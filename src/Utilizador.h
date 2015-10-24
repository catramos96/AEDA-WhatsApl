/** @ \file Utilizador.h
 * header file que contém a classe Utilizador
 */
#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include "System.h"
#include "Conversa.h"

#include <iostream>
#include <string>
#include <vector>


class Utilizador
{
private:
	string login,nome,email;
	int telemovel;
	Data dataAdesao;
	//vector<Conversa> conversas;
public:
	Utilizador(string login, string nome, string email, int telemovel, Data dataAdesao);
	//...
};

#endif /* SRC_UTILIZADOR_H_ */
