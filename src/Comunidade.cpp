#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "Comunidade.h"
#include "Templates.h"
#include "Excecoes.h"

/********************************
 *		CLASSE COMUNIDADE		*
 *******************************/
Comunidade::Comunidade(){
	comunidade.clear(); //inicializar o vetor
}

int Comunidade::existeUtil(Utilizador *util) const{
	return sequentialSearch(comunidade, util);
}

bool Comunidade::existeLogin(string l) const {
	Utilizador *u = new Utilizador;
	u->setLogin(l);
	if (existeUtil(u) == -1)
		return true;
	else
		throw UtilizadorJaExiste(u->getLogin());
}
	
Utilizador *Comunidade::utilizadorNaPosicao(int pos) const{
	return comunidade.at(pos);
}

void Comunidade::adicionarUtil(Utilizador *util){
	if (existeUtil(util) == -1)
		comunidade.push_back(util);
	else
		throw UtilizadorJaExiste(util->getLogin());
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
		throw UtilizadorInexistente((*util).getLogin());

	u->imprimirUtilizador();
}

void Comunidade::printComunidade() const{
	for (unsigned int i = 0; i < comunidade.size(); i++)
		cout << *comunidade.at(i) << endl;
}

/*
int Comunidade::leComunidade(){
	string line;
	////
	bool visibilidade;
	string login, nome, email;
	vector<int> telemoveis;
	int idade;
	Data dataAdesao;
	bool flag=true;
	bool flag2=true;
	bool flag3=true;
	bool flag4=true;
	////
	ifstream myfile ("comunidade.txt");

	if (myfile.is_open())
	{

		while(flag){
			Utilizador u;
			getline (myfile,line);
			u.setNome(line);
			getline (myfile,line);
			u.setLogin(line);
			getline (myfile,line);
			u.setEmail(line);

			while(flag2){
				getline (myfile,line);
				if(line=="-"){
					flag2=false;
					break;
				}
				u.addTelemovel(atoi(line.c_str()));
			}
			getline (myfile,line);
			//data;
			getline (myfile,line);
			u.setIdade(atoi(line.c_str()));
			while(flag3){
				getline (myfile,line);
				if(line=="-"){
					flag3=false;
					break;
				}
				u.setAmigos(comunidade[existeUtilNome(line)]);
			}
			while(flag4){
				getline (myfile,line);
				if(line=="-"){
					flag4=false;
					break;
				}
				u.
			}




		}

	    myfile.close();
	}

	else cout << "Unable to open file";

	return 0;
}

int Comunidade::escreveComunidade(){
	ofstream myfile ("example.txt");
	  if (myfile.is_open())
	  {
	    myfile << "This is a line.\n";
	    myfile << "This is another line.\n";
	    myfile.close();
	  }
	  else cout << "Unable to open file";
	  return 0;
}
*/
