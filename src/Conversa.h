#ifndef SRC_CONVERSA_H_
#define SRC_CONVERSA_H_

#include <iostream>
#include <string>
#include <vector>

#include "Mensagem.h"

/* Classe Conversa*/

class Conversa
{
private:
	vector<Mensagem *> mensagens;
	vector<string> participantes;
public:
	Conversa();
	Conversa(vector<string> partLogin); //conversa vazia
	void adicionaSms(Mensagem *sms);
	void adicionaParticipante(string partNovo);
	void removeParticipante(string part);
	void removeSms(int id);
	void imprimirConversa();
	int numSms() const;
	int numParticipantes() const;
	vector<string> getParticipantes() const;
	void ordenarData();
	bool operator==(const Conversa&c)const;
  void imprimirParticipantes() const;
};

#endif /* SRC_CONVERSA_H_ */
