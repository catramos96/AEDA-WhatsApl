#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Conversa.h"
#include "Templates.h"

using namespace std;

Conversa::Conversa(){
	mensagens.clear();
}

Conversa::Conversa(vector<Utilizador *> part){
	participantes = part;
	mensagens.clear();
}

void Conversa::adicionaParticipante(Utilizador *novo){
	participantes.push_back(novo);
}

void Conversa::removeParticipante(Utilizador *p){
	for (int i = 0; i < numParticipantes(); i++)
		if (p == participantes.at(i)) //encontra o utilizador
			participantes.erase(participantes.begin() + i);
}

void Conversa::adicionaSms(Mensagem sms){
	/*
	Mensagem msg(tipo, data, hora,emissor,destinatarios);
	mensagens.push_back(msg);
	*/
}

void Conversa::removeSms(Data data, Horas hora){

}

void Conversa::imprimirConversa(){
	for (size_t i = 0; i < mensagens.size(); i++){
		mensagens[i].imprimirMsg();
	}
}

int Conversa::numSms() const{
	return mensagens.size();
}

int Conversa::numParticipantes() const{
	return participantes.size();
}

vector<Utilizador *> Conversa::getParticipantes() const{
	return participantes;
}

bool comparaLogin(const Utilizador *u1, const Utilizador *u2){
	return ((*u1).getLogin() < (*u2).getLogin());
}

bool Conversa::operator==(const Conversa&c)const{ //compara 2 conversas pelos de participantes
	sort(c.participantes.begin(), c.participantes.end(), comparaLogin);
	sort(participantes.begin(), participantes.end(), comparaLogin);

	for (int i = 0; i < numParticipantes(); i++){
		if (participantes.at(i) == participantes.at(i))
			continue;		// experimentar isto
		else
			return false;
	}
}