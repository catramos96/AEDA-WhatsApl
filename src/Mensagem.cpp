#include <iostream>
#include <vector>
#include "System.h"
#include <string>
#include <sstream>
#include "Mensagem.h"

using namespace std;

/********************************
 *		CLASSE MENSAGEM			*
 *******************************/

Mensagem::Mensagem(string tipo, Data data, Horas hora, string emissor, vector<string> destinatarios) {
	this->tipo = tipo;
	this->data = data;
	this->hora = hora;
	this->emissor = emissor;
	this->destinatarios = destinatarios;
}

void Mensagem::imprimirMsg() {
	cout << "Tipo: " << tipo << endl;
	cout << "Data: " << data << endl;
	cout << "Hora: " << hora << endl;
	cout << "Emissor: " << emissor << endl;
	cout << "Destinatarios: " << endl;
	for (unsigned int i = 0; i < destinatarios.size(); i++) {
		cout << "    " << destinatarios[i] << endl;
	}
}

string Mensagem::getTipo() const {
	return tipo;
}

Data Mensagem::getData() const {
	return data;
}

Horas Mensagem::getHora() const {
	return hora;
}

string Mensagem::getEmissor() const {
	return emissor;
}

vector<string> Mensagem::getDestinatarios() const {
	return destinatarios;
}

string Mensagem::msgHeader() const {
	stringstream s;
	s << "De: " << emissor << endl;
	s << "Para: ";
	for (unsigned int i = 0; i < destinatarios.size(); i++) {
		s << destinatarios[i];
		if (i + 1 < destinatarios.size())
			s << ", ";
	}
	s << endl;
	s << "Titulo: " << titulo << endl;
	return s.str();
}

/********************************
 *		CLASSE MSG TEXTO		*
 *******************************/

string msgTexto::getConteudo() const {
	return conteudo;
}

void msgTexto::imprimirMsg() {
	Mensagem::imprimirMsg();
	cout << "Conteudo: \n   " << conteudo << endl;
}

ostream & operator<<(ostream & out, const msgTexto &mt) {
	out << mt.msgHeader();
	out << mt.getConteudo();
	return out;
}

/********************************
 *		CLASSE MSG VIDEO		*
 *******************************/

ostream & operator<<(ostream & out, const msgVideo &mv) {
	out << mv.msgHeader();
	out << "VIDEO";
	return out;
}

/********************************
 *		CLASSE MSG IMAGEM		*
 *******************************/

ostream & operator<<(ostream & out, const msgImagem &mi) {
	out << mi.msgHeader();
	out << "IMAGEM";

	return out;
}

