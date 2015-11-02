/** @ \file Conversa.h
 * header file que contém a classe Conversa
 */

#ifndef SRC_CONVERSA_H_
#define SRC_CONVERSA_H_

#include <iostream>
#include <string>
#include <vector>

#include "System.h"
#include "Mensagem.h"

using namespace std;


/* Classe Conversa*/

class Conversa
{
private:
	vector<Mensagem> mensagens;
public:
	Conversa(); //conversa vazia
	Conversa(vector<Mensagem> sms);
	void adicionaSms(string tipo, Data data, Horas hora, string emissor, vector<string> destinatarios);
	void removeSms(Data data, Horas hora);
	void imprimirConversa(); // chama o imprimeSms
	int numSms();

};

#endif /* SRC_CONVERSA_H_ */
