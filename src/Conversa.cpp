#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Utilizador.h"
#include "Templates.h"

using namespace std;

Conversa::Conversa(){
	mensagens.clear();
}

Conversa::Conversa(vector<string> participantes){
	this->participantes = participantes;
	mensagens.clear();
}

void Conversa::adicionaParticipante(string partNovo){
	participantes.push_back(partNovo);
}

void Conversa::removeParticipante(string part){
	for (int i = 0; i < numParticipantes(); i++)
		if (part == participantes.at(i)) //encontra o utilizador
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

vector<string> Conversa::getParticipantes() const{
	return participantes;
}

bool Conversa::operator==(const Conversa&c)const{ //compara 2 conversas pelos de participantes
	//insertionSort(&participantes); //*???
	//insertionSort(c.participantes);
	//sort(c.participantes.begin(), c.participantes.end(), compara);
	//sort(participantes.begin(), participantes.end(), compara);

	for (int i = 0; i < numParticipantes(); i++){
		if (participantes.at(i) == participantes.at(i))
			continue;		// experimentar isto
		else
			return false;
	}
	return false;
}
