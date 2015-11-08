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
  * @param data Data de criacao
  * @param hora Hora de criacao
  */
	Mensagem(Data data, Horas hora);
  /**
  * @brief Funcao que imprime todos os membros privados da mensagem
  */
	virtual void imprimirMsg(); 
  /**
  * @brief Funcao que retorna o emissor
  * @return emissor
  */
	string getEmissor() const;
  /**
  * @brief Funcao que retorna a data
  * @return data
  */
	Data getData() const;
  /**
  * @brief Funcao que retorna a hora
  * @return hora
  */
	Horas getHora() const;
  /**
  * @brief Funcao que retorna o id
  * @return id
  */
	static int getID(){return id;};
  /**
  * @brief Funcao que retorna o numero
  * @return numero
  */
	int getNumero() const;
  /**
  * @brief Funcao que altera o emissor
  * @param emissor
  */
	void setEmissor(string emissor);
	/**
	 * @brief Funcao que altera o numero da mensagem
	 * @param num Numero novo
	 */
	void setNumero(int num);
};

/**
* @brief Classe MsgTexto.
* E uma classe derivada da classe Mensagem que representa o tipo de mensagem.
*/
class MsgTexto : public Mensagem{
private:
	string conteudo; /**< membro privado que representa o conteudo da mensagem de texto */
public:
  /**
  * @brief Construtor de MsgTexto
  * @param conteudo
  * @param d data
  * @param h hora
  */
	MsgTexto(string conteudo, Data d, Horas h);
  /**
  * @brief Funcao que retorna o conteudo
  * @return conteudo
  */
	string getConteudo() const;
  /**
  * @brief Funcao que imprime no ecra a mensagem
  */
	void imprimirMsg();
};

/**
* @brief Classe MsgVideo.
* E uma classe derivada da classe Mensagem que representa o tipo de mensagem.
*/
class MsgVideo : public Mensagem{
public:
  /**
  * @brief Construtor de MsgVideo
  * @param d data
  * @param h hora
  */
	MsgVideo(Data d, Horas h);
  /**
  * @brief Funcao que imprime no ecra a mensagem
  */
	void imprimirMsg();
};

/**
* @brief Classe MsgImagem.
* E uma classe derivada da classe Mensagem que representa o tipo de mensagem.
*/
class MsgImagem : public Mensagem{
public:
  /**
  * @brief Construtor de MsgImagem
  * @param d data
  * @param h hora
  */
	MsgImagem(Data d, Horas h);
  /**
  * @brief Funcao que imprime no ecra a mensagem
  */
	void imprimirMsg();
};

#endif /* SRC_MENSAGEM_H_ */
