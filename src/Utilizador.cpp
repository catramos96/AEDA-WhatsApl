/*
 * Utilizador.cpp
 *
 *  Created on: 23/10/2015
 *      Author: Catarina
 */
#include "System.h"
#include "Utilizador.h"
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

bool addConversa(Conversa &c)
{

}



