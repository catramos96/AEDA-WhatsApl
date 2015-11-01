/** @ \file Mensagem.h
 * header file que contém a classe Mensagem
 */
#ifndef SRC_MENSAGEM_H_
#define SRC_MENSAGEM_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "System.h"

using namespace std;

class Mensagem
{
private:
	string tipo; //texto, imagem, video...
	Data data;
	string emissor;
	vector<string> destinatarios;
	//string titulo;
public:
<<<<<<< HEAD
	Mensagem(string tipo, Data data, string emissor, vector<string> destinatarios);
	Mensagem(string tipo, Data data, string emissor, vector<string> destinatarios,string titulo);
	virtual ~Mensagem(){};
=======
	Mensagem(string tipo, Data data, Horas hora, string emissor, vector<string> destinatarios);
	virtual ~Mensagem();
>>>>>>> e2e427b9d7d34bc3626012ea8e7f3af908d8b503
	virtual void imprimirMsg(); //imprime todos os membros private
	string getTipo() const;
	Data getData() const;
	string getEmissor() const;
	//void setTitulo(string t);
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

class msgImagem : public Mensagem{
	friend ostream & operator<<(ostream & out, const msgImagem &mi);
};

#endif /* SRC_MENSAGEM_H_ */
