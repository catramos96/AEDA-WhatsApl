#include "Utilizador.h"
#include <iostream>
#include <string>
#include <vector>

Utilizador::Utilizador(){
	login = "";
	nome = "";
	email = "";
	Data d;
	dataAdesao = d;
}

Utilizador::Utilizador(string login, string nome, string email, Data dataAdesao)
{
	this->login = login;
	this->nome = nome;
	this->email=email;
	this->dataAdesao = dataAdesao;
	telemoveis.clear();
}

bool Utilizador::operator==(const Utilizador&u)const{
	return (login == u.login);
}

string Utilizador::getNome() const{
	return nome;
}

string Utilizador::getLogin() const{
	return login;
}

ostream & operator<<(ostream & out, const Utilizador & u){
	out << "Nome : " << u.getNome() << " , login : " << u.getLogin();
	return out;
}

//bool addConversa(Conversa &c)


