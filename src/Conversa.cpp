#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Utilizador.h"
#include "Templates.h"
#include "Excecoes.h"

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
	string temp = sms->getEmissor().getLogin();
	if (sequentialSearch<string>(participantes, temp) == -1)
		throw NaoParticipante(temp);
	mensagens.push_back(sms);
}

void Conversa::removeSms(int id){
	for (int i = 0; i < numSms(); i++){
		if (mensagens.at(i)->getNumero() == id)
			mensagens.erase(mensagens.begin() + i);
	}
}

void Conversa::imprimirConversa(){
	ordenarData();
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

vector<Mensagem *> Conversa::getMensagens() const{
	return mensagens;
}

bool compara(const string s1,const string s2){
	return (s1<s2);
}

bool Conversa::operator==(Conversa&c)const{ //compara 2 conversas pelos de participantes
	vector<string> p = participantes;
	insertionSort(c.participantes); //ordenar primeiro os 2 vetores para ter a certeza que não comparamos membros diferentes que na verdade existem mas estão só por ordem diferente
	insertionSort(p);

	for (int i = 0; i < numParticipantes(); i++){
		if (participantes.at(i) == participantes.at(i))
			continue;		// experimentar isto
		else
			return false;
	}
	return false;
}

bool comp(const Mensagem *m1, const Mensagem *m2){
	if((*m1).getData() ==(*m2).getData()){
		return ((*m1).getHora() < (*m2).getHora());
	}else
		return ((*m1).getData() < (*m2).getData());
}

void Conversa::ordenarData(){
	sort(mensagens.begin(), mensagens.end(), comp);
}

void Conversa::imprimirParticipantes() const {
  for (unsigned int i = 0; i < participantes.size(); i++)
  {
    cout << participantes[i] << "  ";
  }
}
