/*
 * Mensagem.cpp
 *
 *  Created on: 23/10/2015
 *      Author: Catarina
 */

#include <iostream>
#include <vector>
#include "System.h"
#include "Utilizador.h"

using namespace std;

Mensagem::Mensagem(string tipo, Data data, Horas hora, string n_emissor,vector<string> destinatarios)
{
	this->tipo = tipo;
	this->data = data;
	this->hora = hora;
	this->n_emissor = n_emissor;
	this->destinatarios = destinatarios;
}

void Mensagem::imprimirSms()
{
	cout << "Tipo: " << tipo << endl;
	cout << "Data: " << data << endl;
	cout << "Hora: " << hora << endl;
	cout << "Emissor: " << n_emissor << endl;
	cout << "Destinatarios: " << endl;
	for (unsigned int i = 0; i < destinatarios.size(); i++) {
		cout << "    " << destinatarios[i] << endl;
	}
}

string Mensagem::getTipo() const {
	return tipo;
}

Data Mensagem::getData() const{
	return data;
}

Horas Mensagem::getHora() const{
	return hora;
}

string Mensagem::getEmissor() const
{
	return n_emissor;
}

vector<string> Mensagem::getDestinatarios() const{
	return destinatarios;
}

ostream & operator<<(ostream &out,const Mensagem &m){
	out << "De: " << m.getEmissor() << endl;
	out << "Para: ";
	for (int i = 0; i < m.getDestinatarios().size(); i++) {
		out << m.getDestinatarios()[i];
		if(i+1 < m.getDestinatarios().size())
			out << ", ";
	}
	out << endl;
	return out;
}

void msgTexto::imprimirSms()
{
	Mensagem::imprimirSms();
	cout << "Conteudo: \n   " << conteudo << endl;
}

