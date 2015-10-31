/** @ \file Conversa.h
 * header file que contém a classe Conversa
 */

#ifndef SRC_CONVERSA_H_
#define SRC_CONVERSA_H_

#include <iostream>
#include <string>
#include <vector>

#include "System.h"
#include "Utilizador.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Mensagem.h"

using namespace std;

class Conversa
{
private:
	vector<Mensagem> mensagens;
public:
	Conversa(); //conversa vazia
	Conversa(vector<Mensagem> sms);
	void adicionaSms(string tipo, Data data, string emissor, vector<string> destinatarios);
	void removeSms(Data data);
	void imprimirConversa(); // chama o imprimeSms
	int numSms();
};

/*! @ classe Conversa Mensagem.h "inc/Mensagem.h"
 *  @ brief Classe que constrói uma conversa constituida por vária mensagens por ordem cronológica
 *
 *  @ private mensagens
 */


#endif /* SRC_CONVERSA_H_ */
