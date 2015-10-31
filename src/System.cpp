#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>

#include "System.h"

using namespace std;

/********************************
 *		CLASSE HORAS			*
 *******************************/
Horas::Horas(){
	hora = 0;
	min = 0;
}

Horas::Horas(int h, int m){
	if (h < 0 || h > 24 || m < 0 || m > 60)
		throw HoraInvalida();
	hora = h;
	min = m;
}

void Horas::setHoras(int h, int m){
	if (h < 0 || h > 24 || m < 0 || m > 60)
		throw HoraInvalida();
	else{
		hora = h;
		min = m;
	}
}

int Horas::getHora() const{
	return hora;
}

int Horas::getMinutos() const{
	return min;
}

std::ostream & operator<<(std::ostream & out, const Horas & h){
	out << h.getHora() << " : " << h.getMinutos();
	return out;
}


/********************************
 *	    	CLASSE DATA			*
 *******************************/

Data::Data(){
	dia = 0;
	mes = 0;
	ano = 0;
}

Data::Data(int d, int m, int a){
	dia = d;
	mes = m;
	ano = a;
}

void Data::setData(int d, int m, int a){
	if (d < 1 || d > 31 || m < 1 || m > 12 || a < 0)
		throw DataInvalida();
	else{
		dia = d;
		mes = m;
		ano = a;
	}
}

int Data::getAno() const{
	return ano;
}

int Data::getMes() const{
	return mes;
}

int Data::getDia() const{
	return dia;
}

std::ostream & operator<<(std::ostream & out, const Data & d){
	out << d.getDia() << " / " << d.getMes() << " / " << d.getAno();
	return out;
}

/************************************
 *	    	CLASSE HORA NOVA		*
 ***********************************/


HoraNova::HoraNova(){
	t = 0;
};

HoraNova::HoraNova(time_t time1){
	t = time1;
}

void HoraNova::setHoraNova(time_t time1){
	t = time(0);
}

time_t HoraNova::getHoraNova(){
	return t;
}

std::ostream & operator<<(std::ostream & out, const HoraNova & t){
	out << t;
	return out;
}

