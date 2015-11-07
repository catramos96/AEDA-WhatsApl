#include "Templates.h"
#include "Utilizador.h"
#include "Excecoes.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*******************************************************
 * 				   CLASSE UTILIZADOR	          	   *
 ******************************************************/

Utilizador::Utilizador() {
	visibilidade = true;
	login = "";
	nome = "";
	email = "";
	idade = 0;
	telemovel = 0;
	Data d;
	dataAdesao = d;
}

Utilizador::Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao, int telemovel, int idade) {
	this->visibilidade = visibilidade;
	this->login = login;
	this->nome = nome;
	this->email = email;
	this->dataAdesao = dataAdesao;
	if (idade < 18)
		throw IdadeInsuficiente(idade);
	this->idade = idade;
	this->telemovel = telemovel;
}

Utilizador::~Utilizador() {}

string Utilizador::getNome() const {
	return nome;
}

string Utilizador::getEmail() const {
	return email;
}

string Utilizador::getLogin() const {
	return login;
}

int Utilizador::getIdade() const{
	return idade;
}

int Utilizador::getTelemovel() const{
	return telemovel;
}

bool Utilizador::getVisibilidade() const {
	return visibilidade;
}

Data Utilizador::getDataAdesao() const {
	return dataAdesao;
}

vector<Utilizador *> Utilizador::getAmigos() const {
	return amigos;
}

Utilizador* Utilizador::getAmigo(string login) const {
	Utilizador *u = new Utilizador;
	u->setLogin(login);
	int i = pointerSequentialSearch(amigos, u);
	if (i == -1)
		throw AmigoInexistente(u->getLogin());
	return amigos[i];
}

Grupo* Utilizador::getGrupo(int i) const {
	if (i < 0 || i >= grupos.size())
		throw GrupoInexistente(i+1);
	return grupos[i];
}

vector<Grupo *> Utilizador::getGrupos() const {
	return grupos;
}

Conversa* Utilizador::getConversa(int i) const {
  if (i < 0 || i >= conversas.size())
    throw ConversaInexistente(i + 1);
  return conversas[i];
}

string Utilizador::getDestinatarioConversa(Conversa *c) const {
  for (int i = 0; i < c->getParticipantes().size(); i++)
  {
    if (c->getParticipantes()[i] != login)
      return c->getParticipantes()[i];
  }
}

void Utilizador::setLogin(string l)
{
	login = l;
}

void Utilizador::setNome(string n) {
	nome = n;
}

void Utilizador::setEmail(string e) {
	email = e;
}

void Utilizador::setIdade(int i) {
	if (i < 18)
		throw IdadeInsuficiente(i);
	idade = i;
}

void Utilizador::setVisibilidade(bool v) {
	visibilidade = v;
}

void Utilizador::setAmigos(Utilizador *u) {
	vector<Utilizador *>::iterator it = find(amigos.begin(), amigos.end(), u);
	if (it != amigos.end())
		throw AmigoJaExiste(u->getLogin());
	else
		amigos.push_back(u);
}

void Utilizador::setTelemovel(int t) {
	telemovel = t;
}

void Utilizador::setGrupo(Grupo grupo){
	grupos.push_back(&grupo);
}

void Utilizador::addAmigo(Utilizador &u) {
	setAmigos(&u);
	u.setAmigos(this);
}

void Utilizador::removerAmigoAux(Utilizador *u) {
	vector<Utilizador *>::iterator it = find(amigos.begin(), amigos.end(), u);
	if (it == amigos.end())
		throw UtilizadorInexistente((*u).getLogin());
	else
		amigos.erase(it);
}

void Utilizador::removerAmigo(Utilizador &u) {
	removerAmigoAux(&u); //remove dos meus amigos
	u.removerAmigoAux(this); //remove me dos amigos dele
}

void Utilizador::imprimirDefinicoes() const {
	cout << "Perfil (1 - publico , 0 - privado): " << visibilidade << endl;
	cout << "Nome: " << nome << endl;
	cout << "Login: " << login << endl;
	cout << "Idade: " << idade << endl;
	cout << "Email: " << email << endl;
	cout << "Telemovel: " << telemovel << endl;
	cout << endl;
}

void Utilizador::imprimirUtilizador() const {
	if (visibilidade) {
		cout << "Perfil: publico" << endl;
		cout << "Nome: " << nome << endl;
		cout << "Login: " << login << endl;
		cout << "Idade: " << idade << endl;
		cout << "Email: " << email << endl;
		cout << "Telemovel: " << telemovel << endl;
		cout << endl;
	}
	else {
		cout << "Perfil: privado" << endl;
		cout << "Nome: " << nome << endl;
		cout << "Login: " << login << endl;
	}
}

void Utilizador::imprimirAmigos() const {
	for (unsigned int i = 0; i < amigos.size(); i++)
	{
		cout << amigos[i]->getNome() << "    " << amigos[i]->getLogin() << endl;
	}
}

void Utilizador::imprimirGrupos() const {
	for (unsigned int i = 0; i < grupos.size(); i++)
	{
		cout << "Grupo: " << i + 1 << " , ";
		grupos.at(i)->printGrupo();
	}
}

void Utilizador::imprimirConversas() const {
  for (unsigned int i = 0; i < conversas.size(); i++)
  {
    cout << "Conversa: " << i + 1 << " , ";
    conversas.at(i)->imprimirParticipantes();
    cout << endl;
  }
}

bool Utilizador::operator==(const Utilizador&u) const {
	return (login == u.login);
}

bool Utilizador::operator<(const Utilizador &u) const{
	return (login < u.login);
}

ostream & operator<<(ostream & out, const Utilizador & u) {
	out << "Nome: " << u.getNome() << ", Login : " << u.getLogin() << ", Data : " << u.getDataAdesao();
	return out;
}

Conversa *Utilizador::criarConversa(Utilizador *u){
	vector<string> participantes;
	participantes.push_back(u->getLogin()); //destinatario da conversa
	participantes.push_back(login); //emissor
	Conversa *c = new Conversa(participantes);
	conversas.push_back(c); //coloca a conversa no vetor de conversas
	u->adicionarConversa(c);//adiciona a conversa criada ao vetor de conversas do amigo
	return c;
}

void Utilizador::adicionarConversa(Conversa *c){
	conversas.push_back(c);
}

void Utilizador::enviarMensagem(Mensagem *sms, Conversa *c){
	sms->setEmissor(login);
	c->adicionaSms(sms);
}

Grupo *Utilizador::criarGrupo(string titulo, Data dataAtual){
	Grupo *g = new Grupo(titulo, dataAtual, login);
	grupos.push_back(g);
	return g;
}

bool Utilizador::adicionarGrupo(Grupo *g){
	if (pointerSequentialSearch(grupos, g) != -1) // ja existe aquele grupo, nao precisa de ser adicionado
		return false;
	else
		grupos.push_back(g);
	return true;
}

bool Utilizador::eliminarGrupo(Grupo *g){
	int i = pointerSequentialSearch(grupos, g);
	if (i == -1) // ja nao existe aquele grupo, nao precisa de ser eliminado
		return false;
	else
		grupos.erase(grupos.begin() + i);
	return true;
}

void Utilizador::enviarMensagemGrupo(Mensagem *sms, Grupo *g){
	sms->setEmissor(login);
	g->enviarMensagem(login, sms);
}

bool Utilizador::adicionaMembro(Utilizador *u, Grupo *g, Data d){
	u->adicionarGrupo(g);
	return g->adicionarMembro(u->getLogin(), login, d);
}

bool Utilizador::aceitaMembro(Utilizador *u, Grupo *g, Data d){
	u->adicionarGrupo(g);
	return g->pedidoAdesao(u->getLogin(), login, d, true);
}

bool Utilizador::rejeitaMembro(Utilizador *u, Grupo *g, Data d){
	return g->pedidoAdesao(u->getLogin(), login, d, false);
}

bool Utilizador::bloquearMembro(Utilizador *u, Grupo *g, Data diaAtual){
	return g->bloquearMembro(u->getLogin(), login, diaAtual);
}

bool Utilizador::desbloquearMembro(Utilizador *u, Grupo *g, Data diaAtual){
	return g->desbloquearMembro(u->getLogin(), login, diaAtual);
}

bool Utilizador::removerMembro(Utilizador *u, Grupo *g, Data diaAtual){
	u->eliminarGrupo(g);
	return g->retiraMembro(u->getLogin(), login, diaAtual);
}

void Utilizador::pedirAdesao(Grupo *g){
	g->adicionarPedido(login);
}
void Utilizador::setData(int d, int m, int a){
	dataAdesao.setData(d, m, a);
}

void Utilizador::imprimirGruposAmigos() const{
	vector<Grupo *> temp;
	vector<Grupo *> gruposAmigos;

	for (size_t i = 0; i < amigos.size(); i++){ //percorre os amigos
		temp = amigos.at(i)->getGrupos();
		for (size_t j = 0; j < temp.size(); j++)
			gruposAmigos.push_back(temp.at(j));
	}
	eliminaRepetidos(gruposAmigos);

	for (size_t k = 0; k < gruposAmigos.size(); k++){
		cout << "Grupo: " << k + 1 << " , ";
		gruposAmigos.at(k)->printGrupo();
	}

}

Grupo *Utilizador::escolheGruposAmigos(int pos) const{
	vector<Grupo *> temp;
	vector<Grupo *> gruposAmigos;

	for (size_t i = 0; i < amigos.size(); i++){ //percorre os amigos
		temp = amigos.at(i)->getGrupos();
		for (size_t j = 0; j < temp.size(); j++)
			gruposAmigos.push_back(temp.at(j));
	}
	eliminaRepetidos(gruposAmigos);

  if (gruposAmigos.at(pos - 1) == NULL)
    throw GrupoInexistente(pos);
	return gruposAmigos.at(pos - 1);
}

void Utilizador::removerConversa(Conversa *c) {
  for (int i = 0; i < conversas.size(); i++)
  {
    if (conversas[i] == c)
      conversas.erase(conversas.begin() + i);
  }
}

void Utilizador::sairConversa(Conversa *c) {
  getAmigo(getDestinatarioConversa(c))->removerConversa(c);
  removerConversa(c);
}
