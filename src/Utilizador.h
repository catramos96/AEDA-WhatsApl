/** @ \file Utilizador.h
 * header file que contém a classe Utilizador
 */
#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include "System.h"
#include "Utilizador.h"
#include "Comunidade.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Mensagem.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Utilizador
{
private:
	string login,nome,email;
	int telemovel;
	Data dataAdesao;
	vector<Conversa> conversas;
public:
	Utilizador();
	Utilizador(string login, string nome, string email, int telemovel, Data dataAdesao);
	//...
};


#endif /* SRC_UTILIZADOR_H_ */
