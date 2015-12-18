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
	Data d(0, 0, 0);
	Membro novo("", d);
	this->emissor = novo;
	this->data = data;
	this->hora = hora;
}

void Mensagem::imprimirMsg() {
	cout << "Mensagem : "<< numero << endl;
	cout << "Data: " << data << " Hora: " << hora << endl;
	cout << "Emissor: " << emissor << endl;
}

string Mensagem::getEmissor() const{
	return emissor.getLogin();
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

Data Mensagem::getDataEmissor() const {
	return emissor.getDataCriacao();
}

void Mensagem::setEmissor(string emissor){
	this->emissor.setLogin(emissor);
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

bool Mensagem::operator<(const Mensagem &m) const {
	if (data < m.getData())  
		return false;
	else if (m.getData() < data) //datas mais antigas têm prioridade
		return true;
	else if (emissor.getDataCriacao() == m.getDataEmissor() && m.getData() == data) //os utilizadores tÊm a mesma data de criacao e data de mensagem
		return (emissor.getLogin < m.getEmissor()); //ordem alfabetica do login
	else if (m.getData() == data) // os utilizadores apenas têm datas iguais
		return emissor.getDataCriacao() == m.getDataEmissor(); //prioridade aos mais recentes
	else
		return false;
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