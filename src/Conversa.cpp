#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Conversa.h"

using namespace std;

Conversa::Conversa(vector<Utilizador *> part){
	participantes = part;
	mensagens.clear();
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
	for(size_t i=0;i<mensagens.size();i++){
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