#include "System.h"
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
	if (nome == u.nome && login == u.login && email == u.email)
		return true;
	else
		return false;
}

string Utilizador::getNome() const{
	return nome;
}

//bool addConversa(Conversa &c)


