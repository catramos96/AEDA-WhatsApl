/*
 * Utilizador.cpp
 *
 *  Created on: 23/10/2015
 *      Author: Catarina
 */
#include "System.h"
#include "Utilizador.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Mensagem.h"

#include <iostream>
#include <string>
#include <vector>

Utilizador::Utilizador(string login, string nome, string email, Data dataAdesao)
{
	this->login = login;
	this->nome = nome;
	this->email=email;
	this->dataAdesao = dataAdesao;
}

bool addTelemovel(int t)
{
	for (int i = 0; i < telemoveis.size(); i++) {
		if(telemoveis[i] == t)
			return false;
	}
	telemoveis.push_back(t);
	return true;
}

bool addConversa(Conversa &c)
{

}



