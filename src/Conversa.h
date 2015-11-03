#ifndef SRC_CONVERSA_H_
#define SRC_CONVERSA_H_

#include <iostream>
#include <string>
#include <vector>

<<<<<<< HEAD
#include "Utilizador.h"
=======
#include "System.h"
>>>>>>> 7bec163f4faf91f6b251470377c7c010fdf7b2f0
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
