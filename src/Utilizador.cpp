#include "Templates.h"
#include "Utilizador.h"
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

/*******************************************************
 * 				                GET				               	   *
 ******************************************************/

string Utilizador::getNome() const {
	return nome;
}

string Utilizador::getEmail() const {
	return email;
}

string Utilizador::getLogin() const {
	return login;
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

/*******************************************************
 * 			            	   	 SET				             	   *
 ******************************************************/


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
    throw AmigoJaExiste(*u);
  else
    amigos.push_back(u);
}

void Utilizador::setTelemovel(int t) {
  telemovel = t;
}

/*
void Utilizador::setGrupo(const Grupo grupo){
	grupos.push_back(grupo);
}
*/

/*******************************************************
 * 				   				 ADICIONAR                     	   *
 ******************************************************/

void Utilizador::addAmigo(Utilizador &u) {
    setAmigos(&u);
    u.setAmigos(this);
  }

/*******************************************************
 * 				   			      REMOVER                    	   *
 ******************************************************/

void Utilizador::deletAmigo(Utilizador *u) {
	vector<Utilizador *>::iterator it = find(amigos.begin(), amigos.end(), u);
	if (it == amigos.end())
		throw UtilizadorInexistente(*u);
	else
		amigos.erase(it);
}

void Utilizador::removerAmigo(Utilizador &u) {
	deletAmigo(&u); //remove dos meus amigos
	u.deletAmigo(this); //remove me dos amigos dele
}

/*******************************************************
 * 				   	 IMPRIMIR		     	   *
 ******************************************************/

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
    cout << "Perfil : publico" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Login: " << login << endl;
    cout << "Idade: " << idade << endl;
    cout << "Email: " << email << endl;
    cout << "Telemovel: " << telemovel << endl;
    cout << endl;
  }
  else {
    cout << "Perfil : privado" << endl;
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

/*******************************************************
 * 				   		OVERLOADING			     	   *
 ******************************************************/

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

void Utilizador::criarConversa(Utilizador *u){
	vector<string> destinatarios;
	destinatarios.push_back(u->getLogin());
	destinatarios.push_back(login);
	Conversa c(destinatarios);
}

bool Utilizador::enviarMensagemUtilizador(Mensagem sms, Utilizador *u){
	vector<string> temp;

	for (unsigned int i = 0; i < conversas.size(); i++){ //procurar o utilizador no vetor de conversas
		temp = conversas.at(i)->getParticipantes();
		for (unsigned int j = 0; j < temp.size(); j++)
			if (temp.at(j) == u->getLogin()){ //encontrou o utilizador
				conversas.at(i)->adicionaSms(sms);
				sms.setEmissor(login);
				return true;
			}
	}
	return false;


}

void Utilizador::criarGrupo(string titulo, Data dataAtual){
	Grupo *g = new Grupo(titulo, dataAtual, login);
	grupos.push_back(g);
}

bool Utilizador::enviarMensagemGrupo(Mensagem sms, Grupo *g){
	for (unsigned int i = 0; i < grupos.size(); i++){
		if (g == grupos.at(i)){
			g->enviarMensagem(login, sms);
			sms.setEmissor(login);
			return true;
		}
	}
	return false;
}

bool Utilizador::bloquearMembro(Utilizador *u, Grupo *g, Data diaAtual){
	Data d;
	Membro moderador(login, d);
	return g->bloquearMembro(u->getLogin(),moderador, diaAtual);
}

bool Utilizador::desbloquearMembro(Utilizador *u, Grupo *g, Data diaAtual){
	Data d;
	Membro moderador(login, d);
	return g->desbloquearMembro(u->getLogin(),moderador, diaAtual);
}

bool Utilizador::removerMembro(Utilizador *u, Grupo *g, Data diaAtual){
	Data d;
	Membro moderador(login, d);
	return g->retiraMembro(u->getLogin(),moderador, diaAtual);
}
