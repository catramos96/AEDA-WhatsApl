/** @ \file System.h
 * header file que contém a classe System
 */
#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include "System.h"
#include "Utilizador.h"
#include "Comunidade.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Mensagem.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Horas
{
private:
	int hora,min;
public:
	class HoraInvalida{};
	Horas();
	void setHoras(int hora,int min);
	int getHora() const;
	int getMinutos() const;
	friend ostream & operator<<(ostream & out, const Horas & h);
};

class Data
{
private:
	int dia,mes,ano;
public:
	class DataInvalida{};
	Data(); //construtor
	void setData(int dia, int mes, int ano);
	int getDia() const;
	int getMes() const;
	int getAno() const;
	friend ostream & operator<<(ostream & out, const Data & d);
};

#endif /* SRC_SYSTEM_H_ */
