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
	if (existeUtil(util) == -1)
		comunidade.push_back(util);
	else
		throw UtilizadorJaExiste(*util);
}

bool comparaData(const Utilizador *u1, const Utilizador *u2){
	return ((*u1).getDataAdesao() < (*u2).getDataAdesao());
}

void Comunidade::ordenaData(){
	sort(comunidade.begin(), comunidade.end(), comparaData);
}

bool comparaLogin(const Utilizador *u1, const Utilizador *u2){
	return ((*u1).getLogin() < (*u2).getLogin());
}

void Comunidade::ordenaLogin(){
	sort(comunidade.begin(), comunidade.end(), comparaLogin);
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
		cout << *comunidade.at(i) << endl;
}