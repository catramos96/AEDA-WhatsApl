\/** @ \file Utilizador.h
 * header file que contém a classe Utilizador
 */
#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include "System.h"

#include <iostream>
#include <string>
#include <vector>


class Utilizador
{
private:
	string login,nome,email;
	vector<int> telemoveis;
	Data dataAdesao;
	//vector<Conversa *> conversas;
public:
	Utilizador();
	Utilizador(string login, string nome, string email, Data dataAdesao);
	bool addTelemovel(int t);
	bool operator==(const Utilizador&u)const;
	string getNome() const;
	//bool addConversa(Conversa &c);
	//bool enviarSms(Mensagem &m);

};

	//...

#endif /* SRC_UTILIZADOR_H_ */
