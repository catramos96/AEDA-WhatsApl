#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Conversa.h"
#include "Mensagem.h"

using namespace std;

Conversa::Conversa(){
	mensagens.clear();
}

Conversa::Conversa(vector<Mensagem> sms){
	mensagens=sms;
}


void Conversa::adicionaSms(string tipo, Data data, Horas hora, string emissor, vector<string> destinatarios){
	Mensagem msg(tipo, data, hora,emissor,destinatarios);
	mensagens.push_back(msg);
}



void Conversa::removeSms(Data data, Horas hora){

}

void Conversa::imprimirConversa(){
	for(size_t i=0;i<mensagens.size();i++){
		mensagens[i].imprimirMsg();
	}
}

int Conversa::numSms(){
	return mensagens.size();
}
