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
	static int id; // incrementa a cada mensagem
	Data data;
	Horas hora;
	string emissor;
	int numero; // numero da mensagem atual
public:
	Mensagem(Data data, Horas hora);
	//virtual ~Mensagem();
	virtual void imprimirMsg(); //imprime todos os membros private
	string getEmissor() const;
	Data getData() const;
	Horas getHora() const;
	static int getID(){return id;};
	int getNumero() const;
	void setEmissor(string emissor);
};

class MsgTexto : public Mensagem{
private:
	string conteudo;
public:
	MsgTexto(string conteudo, Data d, Horas h);
	string getConteudo() const;
	void imprimirMsg();
};

class MsgVideo : public Mensagem{
public:
	MsgVideo(Data d, Horas h);
	void imprimirMsg();
};

class MsgImagem : public Mensagem{
public:
	MsgImagem(Data d, Horas h);
	void imprimirMsg();
};

#endif /* SRC_MENSAGEM_H_ */
