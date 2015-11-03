#ifndef SRC_CONVERSA_H_
#define SRC_CONVERSA_H_

#include <iostream>
#include <string>
#include <vector>

#include "Utilizador.h"
#include "Mensagem.h"


using namespace std;


/* Classe Conversa*/

class Conversa
{
private:
	vector<Mensagem> mensagens;
	vector<Utilizador *> participantes;
public:
	Conversa(vector<Utilizador *> part); //conversa vazia
	void adicionaSms(Mensagem sms);
	void removeSms(Data data, Horas hora);
	void imprimirConversa();
	int numSms() const;
	int numParticipantes() const;
	vector<Utilizador *> getParticipantes() const;
};



#endif /* SRC_CONVERSA_H_ */
