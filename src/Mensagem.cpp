#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>

#include "Mensagem.h"

using namespace std;

/********************************
 *		CLASSE MENSAGEM			*
 *******************************/

int Mensagem::id = 0;

Mensagem::Mensagem(Data data, Horas hora) : numero(++id){
	this->data = data;
	this->hora = hora;
}

void Mensagem::imprimirMsg() {
	cout << "Mensagem : "<< numero << endl;
	cout << "Data: " << data << " Hora: " << hora << endl;
	cout << "Emissor: " << emissor << endl;
}

string Mensagem::getEmissor() const{
	return emissor;
}

Data Mensagem::getData() const {
	return data;
}

Horas Mensagem::getHora() const {
	return hora;
}

int Mensagem::getNumero() const{
	return numero;
}

void Mensagem::setEmissor(string emissor){
	this->emissor = emissor;
}

void Mensagem::setNumero(int num){
	this->numero = num;
}

string Mensagem::tipo() const{
	return "sem tipo";
}

string Mensagem::getConteudo() const{
	return "sem conteudo";
}

/********************************
 *		CLASSE MSG TEXTO		*
 *******************************/

MsgTexto::MsgTexto(string conteudo, Data d, Horas h) : Mensagem(d,h)
{
	this->conteudo = conteudo;
}

void MsgTexto::imprimirMsg() {
	Mensagem::imprimirMsg();
	cout << "Tipo: texto " << endl;
	cout << "Conteudo: \n   " << conteudo << endl;
}

string MsgTexto::getConteudo() const {
	return conteudo;
}

string MsgTexto::tipo() const{
	return "t";
}

/********************************
 *		CLASSE MSG VIDEO		*
 *******************************/

MsgVideo::MsgVideo(Data d, Horas h) : Mensagem(d,h)
{}

void MsgVideo::imprimirMsg(){
	Mensagem::imprimirMsg();
	cout << "Tipo: video " << endl;
}

string MsgVideo::getConteudo() const {
	return "video";
}

string MsgVideo::tipo() const{
	return "v";
}

/********************************
 *		CLASSE MSG IMAGEM		*
 *******************************/
MsgImagem::MsgImagem(Data d, Horas h) : Mensagem(d,h)
{}

void MsgImagem::imprimirMsg(){
	Mensagem::imprimirMsg();
	cout << "Tipo: imagem " << endl;
}

string MsgImagem::getConteudo() const {
	return "imagem";
}

string MsgImagem::tipo() const{
	return "i";
}