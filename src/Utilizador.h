/** @ \file Utilizador.h
 * header file que contém a classe Utilizador
 */
#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include "System.h"
#include "Utilizador.h"

#include <iostream>
#include <string>
#include <vector>


class Utilizador
{
private:
	string login,nome,email;
	vector<int> telemoveis;
	Data dataAdesao;
	vector<Utilizador *> amigos; // só pode enviar mensagens se estiver dentro do grupo de amigos
								// pode adicionar ou eliminar amigos
	//vector<Conversa *> conversas;
public:
	Utilizador();
	Utilizador(string login, string nome, string email, Data dataAdesao);
	bool addTelemovel(int t);
	bool operator==(const Utilizador&u)const;
	string getNome() const;
	//bool addConversa(Conversa &c);
	//bool enviarSms(Mensagem &m);
	friend ostream & operator<<(ostream & out, const Utilizador & u);

};

#endif /* SRC_UTILIZADOR_H_ */
