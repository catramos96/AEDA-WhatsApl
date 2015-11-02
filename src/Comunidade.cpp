#include "Comunidade.h"
#include "Templates.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

Comunidade::Comunidade(){
	comunidade.clear(); //inicializar o vetor
}

int Comunidade::existeUtil(Utilizador *util) const{
	return sequentialSearch(comunidade, util);
}

Utilizador *Comunidade::utilizadorNaPosicao(int pos) const{
	return comunidade.at(pos);
}

void Comunidade::adicionarUtil(Utilizador *util){
	if (existeUtil(util) != -1)
		comunidade.push_back(util);
	else
		throw UtilizadorInexistente(*util);
}

bool comparaData(const Utilizador&u1, const Utilizador&u2){
	/*
	if (u < d2)
		return true;
	else d1 < d2;*/
}

bool Comunidade::ordenaData(){
	sort(comunidade.begin(), comunidade.end(), comparaData);
}

bool Comunidade::ordenaLogin(){
	insertionSort(comunidade);
}

void Comunidade::verUtilizador(Utilizador *util) const{
	Utilizador *u = new Utilizador();
	int i = existeUtil(util);
	if (i != -1)
		u = utilizadorNaPosicao(i);
	else
		throw UtilizadorInexistente(*util);

	u->imprimirDefinicoes();
}

void Comunidade::printComunidade() const{
	for (unsigned int i = 0; i < comunidade.size(); i++)
		cout << comunidade.at(i);	
}