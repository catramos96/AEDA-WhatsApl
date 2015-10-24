/** @ \file Mensagem.h
 * header file que contém a classe Mensagem
 */
#ifndef SRC_MENSAGEM_H_
#define SRC_MENSAGEM_H_
<<<<<<< HEAD
#include <iostream>
/*
=======

#include <iostream>
#include <vector>
>>>>>>> 15c18cc893a9f1ffbc12130e0811916857f3b415
#include "System.h"

using namespace std;

class Mensagem
{

private:
	string tipo; //texto, imagem, video...
	Data data;
	Horas hora;
	string emissor;
	vector<string> destinatarios;
	string titulo;
public:
	Mensagem(string tipo, Data data, Horas hora, string emissor, vector<string> destinatarios);
	Mensagem(string tipo, Data data, Horas hora, string emissor, vector<string> destinatarios,string titulo);
	virtual ~Mensagem();
	virtual void imprimirMsg(); //imprime todos os membros private
	string getTipo() const;
	Data getData() const;
	Horas getHora() const;
	string getEmissor() const;
	vector<string> getDestinatarios() const;
	string msgHeader() const; //Retorna "header de cada Mensagem"
};


class msgTexto : public Mensagem
{

private:
	string conteudo;
public:
	string getConteudo() const;
	void imprimirMsg();
friend ostream & operator<<(ostream & out, const msgTexto &mt);

};

class msgVideo : public Mensagem{
	friend ostream & operator<<(ostream & out, const msgVideo &mv);
};
<<<<<<< HEAD
*/
=======

class msgImagem : public Mensagem{
	friend ostream & operator<<(ostream & out, const msgImagem &mi);

};
>>>>>>> 15c18cc893a9f1ffbc12130e0811916857f3b415
#endif /* SRC_MENSAGEM_H_ */
