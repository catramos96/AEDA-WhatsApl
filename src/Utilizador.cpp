#include "Utilizador.h"
#include "Templates.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*******************************************************
 * 				      	CLASSE UTILIZADOR			          	   *
 ******************************************************/

Utilizador::Utilizador() {
	visibilidade = true;
	login = "";
	nome = "";
	email = "";
  idade = 100;
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
  if (idade < 18)
  throw IdadeInsuficiente(idade);
	this->idade = idade;
	telemoveis.push_back(telemovel);
}

/*******************************************************
 * 				    GET				     	   *
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

vector<Utilizador *> Utilizador::getPedidosAmizade() const {
	return pedidosAmizade;
}

/*******************************************************
 * 				   	 SET				     	   *
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

void Utilizador::setVisibilidade(bool v) {
	visibilidade = v;
}


/*******************************************************
 * 				   				     	   *
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

/*******************************************************
 * 				   			     	   *
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

/*******************************************************
 * 				   	 IMPRIMIR		     	   *
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


/*******************************************************
 * 				   	OVERLOADING		     	   *
 ******************************************************/

bool Utilizador::operator==(const Utilizador&u) const {
	return (login == u.login);
}

bool Utilizador::operator<(const Utilizador &u) const{
	return (login < u.login);
}

ostream & operator<<(ostream & out, const Utilizador & u) {
	out << "Nome: " << u.getNome() << ", Login : " << u.getLogin() << ", Data : " << u.getDataAdesao;
	return out;
}

//bool addConversa(Conversa &c)
