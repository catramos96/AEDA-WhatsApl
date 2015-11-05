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
	Horas hora;
	string emissor;
public:
	Mensagem(string tipo, Data data, Horas hora);
	//virtual ~Mensagem();
	virtual void imprimirMsg(); //imprime todos os membros private
	string getTipo() const;
	Data getData() const;
	void setEmissor(string emissor);
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
