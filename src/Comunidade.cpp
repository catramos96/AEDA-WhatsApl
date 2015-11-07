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
  for (unsigned int i = 0; i < comunidade.size(); i++)
  {
    if (*comunidade[i] == *util)
      return i;
  }
  return -1;
}

int Comunidade::existeUtilNome(string nome) const{
	for (unsigned int i = 0; i < comunidade.size(); i++){
			if (comunidade[i]->getNome() == nome)
				return i;   // encontrou
		}
		return -1;     // nao encontrou
}


Grupo *Comunidade::existeGrupo(string grupo) const{
	for (unsigned int i = 0; i < comunidade.size(); i++){
		for(size_t x=0;x<comunidade[i]->getGrupos().size();x++)
		{
			if (comunidade[i]->getGrupos()[x]->getTitulo() == grupo)
				return comunidade[i]->getGrupos()[x];   // encontrou
		}
	}
  //throw GrupoInexistente();     // nao encontrou
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

void Comunidade::leComunidade(){
	int d,m,a;
	bool flag3=true;
	bool flag4=true;
	vector<string>amigos;
	vector<string>grupos;
	string line;
	ifstream myfile ("C:\\Users\\pedro\\Documents\\aeda2\\src\\comunidade.txt");
	if (myfile.is_open())
	{
		while(myfile.good()){
			Utilizador u;
			getline (myfile,line);
			u.setNome(line);
			getline (myfile,line);
			u.setLogin(line);
			getline (myfile,line);
			u.setEmail(line);
			getline (myfile,line);
			u.setTelemovel(atoi(line.c_str()));
			getline (myfile,line);
			d=atoi(line.c_str());
			getline (myfile,line);
			m=atoi(line.c_str());
			getline (myfile,line);
			a=atoi(line.c_str());
			u.setData(d,m,a);
			getline (myfile,line);
			u.setIdade(atoi(line.c_str()));
			while(flag3){
				getline (myfile,line);
				if(line=="-"){
					flag3=false;
					break;
				}
				amigos.push_back(line);
				//u.setAmigos(comunidade[existeUtilNome(line)]);
			}
			while(flag4){
				getline (myfile,line);
				if(line=="-"){
					flag4=false;
					break;
				}

				//u.setGrupo(*existeGrupo(line));
			}
			getline (myfile,line);
			u.setVisibilidade(atoi(line.c_str()));

			adicionarUtil(&u);

		}
	    myfile.close();
	}

	else{
		cout << "Unable to open file";
		myfile.close();
	}


	for(size_t i=0;i<comunidade.size();i++){
		for(size_t x=0;x<amigos.size();x++){
			comunidade[i]->addAmigosAux(comunidade[existeUtilNome(amigos[x])]);
		}
	}
	for(size_t i=0;i<comunidade.size();i++){
			for(size_t x=0;x<grupos.size();x++){
				comunidade[i]->addGrupo(existeGrupo(grupos[x]));
			}
		}
}


int Comunidade::escreveComunidade(){
	ofstream myfile ("example.txt");
	  if (myfile.is_open())
	  {
		  for(size_t i=0;i<comunidade.size();i++){
			  myfile << comunidade[i]->getNome() << "\n";
			  myfile << comunidade[i]->getLogin() << "\n";
			  myfile << comunidade[i]->getEmail() << "\n";
			  myfile << comunidade[i]->getTelemovel() << "\n";
			  myfile << comunidade[i]->getDataAdesao() << "\n";
			  myfile << comunidade[i]->getIdade() << "\n";
			  for(size_t x=0;x<comunidade[i]->getAmigos().size();x++){
				  myfile << comunidade[i]->getAmigos()[x]->getNome() << "\n";
			  }
			  myfile << "-" << "\n";
			  for(size_t x=0;x<comunidade[i]->getGrupos().size();x++){
			  	 myfile << comunidade[i]->getGrupos()[x]->getTitulo() << "\n";
			  }
			  myfile << "-" << "\n";
			  myfile << comunidade[i]->getVisibilidade();
		  }


	    myfile.close();
	  }
	  else cout << "Unable to open file";
	  return 0;
}

