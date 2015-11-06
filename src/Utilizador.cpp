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
  if (i < 0 || i > grupos.size()-1){
    throw GrupoInexistente(i);
}
  return grupos[i];
}

vector<Grupo *> Utilizador::getGrupos() const {
  return grupos;
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

void Utilizador::imprimirGrupos(vector<Grupo*> g) const {
  for (unsigned int i = 0; i < g.size(); i++)
  {
    cout << "Grupo: " << i + 1 << " , ";
    g[i]->printGrupo();
  }
}

bool Utilizador::operator==(const Utilizador&u) const {
	return (login == u.login);
}

bool Utilizador::operator<(const Utilizador &u) const{
	return (login < u.login);
}

ostream & operator<<(ostream & out, const Utilizador & u) {
	out << "Nome: " << u.getNome() << ", Login : " << u.getLogin() << ", Data : "<< u.getDataAdesao();
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

void Utilizador::enviarMensagemGrupo(Mensagem *sms, Grupo *g){
	sms->setEmissor(login);
	g->enviarMensagem(login, sms);
}

bool Utilizador::aceitaMembro(string u, Grupo *g, Data d){
	return g->pedidoAdesao(u,login,d,true);
}

bool Utilizador::rejeitaMembro(string u, Grupo *g, Data d){
	return g->pedidoAdesao(u,login,d,false);
}

bool Utilizador::bloquearMembro(Utilizador *u, Grupo *g, Data diaAtual){
	return g->bloquearMembro(u->getLogin(),login, diaAtual);
}

bool Utilizador::desbloquearMembro(Utilizador *u, Grupo *g, Data diaAtual){
	return g->desbloquearMembro(u->getLogin(),login, diaAtual);
}

bool Utilizador::removerMembro(Utilizador *u, Grupo *g, Data diaAtual){
	return g->retiraMembro(u->getLogin(),login, diaAtual);
}

void Utilizador::pedirAdesao(Grupo *g){
	g->adicionarPedido(login);
}
void Utilizador::setData(int d, int m, int a){
	dataAdesao.setData(d,m,a);
}


vector<Grupo *> Utilizador::meusGrupos() const {
  vector<Grupo *> g;
  for (int i = 0; i < grupos.size(); i++)
  {
    if (grupos[i]->isModerador(login))
      g.push_back(grupos[i]);
  }
  return g;
}

