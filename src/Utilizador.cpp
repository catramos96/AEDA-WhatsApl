#include "Utilizador.h"
#include "Templates.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*******************************************************
 * 					CLASSE UTILIZADOR				   *
 ******************************************************/

Utilizador::Utilizador() {
	visibilidade = true;
	login = "";
	nome = "";
	email = "";
	Data d;
	idade = 0;
	dataAdesao = d;
}

Utilizador::Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao, int telemovel, int idade) {
	this->visibilidade = visibilidade;
	this->login = login;
	this->nome = nome;
	this->email = email;
	this->dataAdesao = dataAdesao;
	this->idade = idade;
	telemoveis.push_back(telemovel);
}

/*******************************************************
 * 				   	FUN합ES GET				     	   *
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

vector<int> Utilizador::getTelemoveis() const {
	return telemoveis;
}

Data Utilizador::getDataAdesao() const {
	return dataAdesao;
}

vector<Utilizador *> Utilizador::getAmigos() const {
	return amigos;
}

vector<Utilizador *> Utilizador::getBloqueados() const {
	return bloqueados;
}

vector<Utilizador *> Utilizador::getBloquearamMe() const {
	return bloquearamMe;
}

vector<Utilizador *> Utilizador::getPedidosAmizade() const {
	return pedidosAmizade;
}

/*
 vector<Conversa *> Utilizador::getConversa(Conversa &c){
 return conversas;
 }
 */

vector<string> Utilizador::getNotificacoes() const {
	return notificacoes;
}

/*******************************************************
 * 				   	FUN합ES SET				     	   *
 ******************************************************/

/*
bool Utilizador::setLogin(string login, vector<Utilizador*> comunidade) {
	Data d;
	Utilizador u(false, login, "", "", d, 0);
	if (sequentialSearch(comunidade, &u) == -1) {
		this->login = login;
		return true;
	}
	else
		throw UtilizadorJaExiste(login);
}
*/
void Utilizador::setNome(string n) {
	nome = n;
}

void Utilizador::setEmail(string e) {
	email = e;
}

void Utilizador::setVisibilidade(bool v) {
	visibilidade = v;
}


/*******************************************************
 * 				   	FUN합ES ADD				     	   *
 ******************************************************/

void Utilizador::addUtilizador(vector<Utilizador *> v, Utilizador &u) {
	vector<Utilizador *>::iterator it = find(v.begin(), v.end(), &u);
	if (it != v.end())
		throw UtilizadorJaExiste(u);
	else
		v.push_back(&u);
}

void Utilizador::addTelemovel(int t) {
	vector<int>::iterator it = find(telemoveis.begin(), telemoveis.end(), t);
	if (it != telemoveis.end())
		telemoveis.push_back(t);
	else
		throw TelemovelJaExiste(t);
}

/*
void Utilizador::aceitarAmizade(Utilizador &u) {
vector<Utilizador *>::iterator it = find(pedidosAmizade.begin(), pedidosAmizade.end(), &u);
if (it == pedidosAmizade.end())
throw UtilizadorInexistente(u);
else {
amigos.push_back(&u);
u.setAmigos(*this);
}
}

void Utilizador::bloquearUtilizador(Utilizador &u) {
vector<Utilizador *>::iterator it = find(comunidade.begin(), comunidade.end(), &u);
if (it == comunidade.end())
throw UtilizadorInexistente(u);
else {
bloqueados.push_back(&u);
u.setBloquearamMe(*this);
}
}
*/
/*******************************************************
 * 				   	FUN합ES REMOVER			     	   *
 ******************************************************/

void Utilizador::removerUtilizador(vector<Utilizador *> v, Utilizador &u) {
	vector<Utilizador *>::iterator it = find(v.begin(), v.end(), &u);
	if (it == v.end())
		throw UtilizadorInexistente(u);
	else
		v.erase(it);
}

void Utilizador::removerTelemovel(int t) {
	vector<int>::iterator it = find(telemoveis.begin(), telemoveis.end(), t);
	if (it != telemoveis.end())
		telemoveis.erase(it);
	else
		throw TelemovelInexistente(t);
}

void Utilizador::removerAmigo(Utilizador &u) {
	removerUtilizador(amigos, u);
	u.removerUtilizador(u.getAmigos(), *this);
}

/*
void Utilizador::desbloquearUtilizador(Utilizador &u) {
removerUtilizador(bloqueados, u);
u.removerUtilizador(u.getBloqueados(), *this);
}
*/
/*******************************************************
 * 				   	FUN합ES IMPRIMIR		     	   *
 ******************************************************/

void Utilizador::imprimirDefinicoes() const {
	if (visibilidade){
		cout << "Perfil : publico" << endl;
		cout << "Nome: " << nome << endl;
		cout << "Login: " << login << endl;
		cout << "Idade: " << idade << endl;
		cout << "Email: " << email << endl;
		cout << "Telemoveis: ";
		for (unsigned int i = 0; i < telemoveis.size(); ++i) {
			cout << telemoveis[i];
			if (i == telemoveis.size() - 1)
				cout << " , ";
		}
	}
	else{
		cout << "Perfil : privado" << endl;
		cout << "Nome: " << nome << endl;
		cout << "Login: " << login << endl;
	}
}

void Utilizador::imprimirNotificacoes() const
{
	for (unsigned int i = 0; i < notificacoes.size(); ++i) {
		cout << notificacoes[i] << endl;
	}
}

void Utilizador::imprimirGrupo(vector<Utilizador *> v) const {
	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
}

/*******************************************************
 * 				   	FUN합ES OVERLOADING		     	   *
 ******************************************************/

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

//bool addConversa(Conversa &c)

