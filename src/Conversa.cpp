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

void Conversa::adicionaSms(Mensagem *sms){
	mensagens.push_back(sms);
}

/*
void Conversa::removeSms(int id){
	for (int i = 0; i < numSms(); i++){
		if (mensagens.at(i).Mensagem::getID() == id)
			mensagens.erase(mensagens.begin() + i);
	}
}
*/
void Conversa::imprimirConversa(){
	cout << "Chat : ";
	for (int j = 0; j < numParticipantes(); j++){
		if (j == numParticipantes() - 1)
			cout << participantes.at(j) << endl;
		else
			cout << participantes.at(j) << " ,";
	}
	for (int i = 0; i < numSms(); i++){
		mensagens[i]->imprimirMsg();
		cout << endl;
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

bool compara(const string s1,const string s2){
	return (s1<s2);
}

bool Conversa::operator==(const Conversa&c)const{ //compara 2 conversas pelos de participantes
	for (int i = 0; i < numParticipantes(); i++){
		if (participantes.at(i) == participantes.at(i))
			continue;		// experimentar isto
		else
			return false;
	}
	return false;
}
