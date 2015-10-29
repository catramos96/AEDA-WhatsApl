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
	return ((nome == u.nome) && (login == u.login) && (email == u.email));
}

string Utilizador::getNome() const{
	return nome;
}

ostream & operator<<(ostream & out, const Utilizador & u){
	out << u.getNome();
	return out;
}

//bool addConversa(Conversa &c)


