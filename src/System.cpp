#include "System.h"

/* classe Horas */

/* construtor */
Horas::Horas(){
	hora = 0;
	min = 0;
}

void Horas::setHoras(int h, int m){
	if(h < 0 || h > 24 || m < 0 || m > 60)
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

ostream & operator<<(ostream & out, const Horas & h){
	out << h.getHora()  << " : " << h.getMinutos();
	return out;
}

/* classe Data */

/* construtor */
Data::Data(){
	dia=0;
	mes=0;
	ano=0;
}

void Data::setData(int d, int m, int a){
	if(d < 1 || d > 31 || m < 1 || m > 12 || a < 0)
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

ostream & operator<<(ostream & out, const Data & d){
	out << d.getDia() << " / " << d.getMes() << " / " << d.getAno();
	return out;
}
