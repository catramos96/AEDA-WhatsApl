/** @ \file System.h
 * header file que contém a classe System
 */
#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_
#include <iostream>
#include <string>
#include "Utilizador.h"
#include <vector>

using namespace std;

class Horas
{
	int hora,min;
public:
	Horas(int hora, int min); //construtor
	void setHoras(int hora,int min);
	void setHora(int hora);
	void setMin(int minutos);
	string getHoras() const;
friend ostream & operator<<(ostream & o, const Horas & h);
};

class Data
{
	int dia,mes,ano;
public:
	Data(int dia, int mes, int ano); //construtor
	void setDia(int dia);
	void setMes(int mes);
	void setAno(int ano);
	int getDia() const;
	int getMes() const;
	int getAno() const;

friend ostream & operator<<(ostream & o, const Data & d);

};

class Comunidade
{
private:
	vector<Utilizador *> comunidade;
public:
	Comunidade();
	bool adicionarUtil(Utilizador utilizador);
};


#endif /* SRC_SYSTEM_H_ */
