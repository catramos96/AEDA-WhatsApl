#ifndef SRC_MENSAGEM_H_
#define SRC_MENSAGEM_H_

#include <iostream>
#include <vector>
#include <time.h>

#include "Membro.h"

using namespace std;

/**
* @brief Classe Mensagem.
* Cada Mensagem tem um id unico que representa o numero da mensgem, um membro que pode ser de um grupo ou individual
* (neste caso o membro apenas tem login), e uma data e hora de envio.
* Cada Mensagem pode ainda ser de texto, video ou imagem.
*/
class Mensagem
{
private:
	static int id; /**< membro estatico privado id que e incrementado a cada criacao de uma mensagem */
	Data data; /**< membro privado que representa a data de criacao da mensagem */
	Horas hora; /**< membro privado que representa a hora de criacao da mensagem */
	Membro emissor; /**< membro privado que representa o membro emissor da mensagem */
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
	* @brief Funcao que retorna a data de criacao deste membro num grupo. 
	* Caso este membro não seja de um grupo mas apenas de uma conversa, devolve 0 0 0.
	* @return Data Data em que o emissor desta mensagem se juntou a um dado grupo.
	*/
	Data getDataEmissor() const;
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
	/**
	* @brief Funcao abstrata que retorna uma string com o tipo dependendo da classe derivada
	* @return string com  i, v ou t
	*/
	virtual string tipo() const ;
	/**
	* @brief Funcao abstrata que retorna o conteudo da classe derivada
	* @return string com  o conteudo
	*/
	virtual string getConteudo() const ;
	/**
	* @brief o operador menor nas mensagens serve para orderar a fila de prioridade da classe 'Grupo'.
	* Estas mensagens são ordenadas, primeiramente, por ordem cronológica das mensagens (data da mensagem : primeiro as mais antigas)
	* e de seguida por data de adesão ao grupo (membros mais recentes têm prioridade). 
	* @param m Mensagem que queremos comparar
	* @return bool True or False caso se verifique se é menor ou não.
	*/
	bool operator<(const Mensagem &m) const;
};

// =================================================================================================================//

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

	/**
	* @brief Funcao que retorna o tipo de mensagem
	* @return string com  t
	*/
	string tipo() const;
};

// =================================================================================================================//

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

	/**
	* @brief Funcao que retorna o tipo de mensagem
	* @return string com  v
	*/
	string tipo() const;

	/**
	* @brief Funcao que retorna um 'video'
	* @return string com  o conteudo
	*/
	string getConteudo() const;
};

// =================================================================================================================//

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

	/**
	* @brief Funcao que retorna o tipo de mensagem
	* @return string com  i
	*/
	string tipo() const;

	/**
	* @brief Funcao que retorna uma 'imagem'
	* @return string com  o conteudo
	*/
	string getConteudo() const;
};

#endif /* SRC_MENSAGEM_H_ */
