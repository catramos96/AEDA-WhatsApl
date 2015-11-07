#ifndef SRC_MENSAGEM_H_
#define SRC_MENSAGEM_H_

#include <iostream>
#include <vector>
#include <time.h>

#include "System.h"

using namespace std;

/**
* @brief Classe Mensagem.
* Cada Mensagem tem um id unico que representa o numero da mensgem.
* Cata Mensagem pode ainda ser de texto, video ou imagem.
*/
class Mensagem
{
private:
	static int id; /**< membro estatico privado id que e incrementado a cada criacao de uma mensagem */
	Data data; /**< membro privado que representa a data de criacao da mensagem */
	Horas hora; /**< membro privado que representa a hora de criacao da mensagem */
	string emissor; /**< membro privado que representa o emissor da mensagem */
	int numero; /**< membro privado que representa o numero da mensagem*/
public:
  /**
  * @brief Construtor da classe Mensagem;
  * @ param data data de criacao
  * @ para hora hora de criacao
  */
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
	string conteudo; /**< membro privado que representa o conteudo da mensagem de texto */
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
