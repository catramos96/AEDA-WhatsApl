/** @ \file Utilizador.h
 * header file que contém a classe Utilizador
 */
#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include "System.h"
<<<<<<< HEAD
#include "Conversa.h"
=======
#include "Utilizador.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Mensagem.h"
>>>>>>> 15c18cc893a9f1ffbc12130e0811916857f3b415

#include <iostream>
#include <string>
#include <vector>


class Utilizador
{
private:
	string login,nome,email;
	vector<int> telemoveis;
	Data dataAdesao;
<<<<<<< HEAD
	//vector<Conversa> conversas;
public:
	Utilizador(string login, string nome, string email, int telemovel, Data dataAdesao);
=======
	vector<Conversa *> conversas;
public:
	Utilizador(string login, string nome, string email, Data dataAdesao);
	bool addTelemovel(int t);
	bool addConversa(Conversa &c);
	bool enviarSms(Mensagem &m);
>>>>>>> 15c18cc893a9f1ffbc12130e0811916857f3b415
	//...

};

#endif /* SRC_UTILIZADOR_H_ */
