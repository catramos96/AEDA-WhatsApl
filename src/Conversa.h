#ifndef SRC_CONVERSA_H_
#define SRC_CONVERSA_H_

#include <iostream>
#include <string>
#include <vector>

#include "Mensagem.h"

/**
 * @brief Classe Comunidade.
 * Class que gere as conversas
 * E possivel ordenar as conversas por data
 */
class Conversa
{
private:
	vector<Mensagem *> mensagens; /**<  membro privado que contem todos as mensagens */
	vector<string> participantes; /**<  membro privado que contem todos os participantes */
public:
	/**
	* @brief Construtor
	* Construtor default que inicializa uma conversa vazia
	*/
	Conversa();
	/**
	* @brief Construtor
	* Construtor default que inicializa uma conversa vazia
	*/
	Conversa(vector<string> partLogin); //conversa vazia

	/**
		 * @ brief Funcao que adiciona uma mensagem
		 * @ param sms: contem a mensagem
		 * @ return void
		 */
	void adicionaSms(Mensagem *sms);
	/**
		 * @ brief Funcao que adiciona um participante
		 * @ param partNovo : indica o novo participante
		 * @ return void
		 */
	void adicionaParticipante(string partNovo);
	/**
	* @ brief Funcao que remove um participante
	* @ param partNovo : indica o novo participante
	* @ return void
	*/
	void removeParticipante(string part);
	/**
	* @ brief Funcao que remove uma mensagem
	* @ param id : indica id da mensagem
	* @ return void
	*/
	void removeSms(int id);
	/**
	* @ brief Funcao que imprime no ecra toda a conversa
	* @ return void
	*/
	void imprimirConversa();
	/**
	* @ brief Funcao que retorna o numero de sms
	* @ return numero de mensagens
	*/
	int numSms() const;
	/**
	* @ brief Funcao que retorna o numero de participantes de uma conversa
	* @ return numero de participantes
	*/
	int numParticipantes() const;
	/**
	* @ brief Funcao permite obter todos os participantes
	* @ return vector com os participantes
	*/
	vector<string> getParticipantes() const;
	/**
	* @ brief Funcao retorna todas as mensagens de uma conversa
	* @ return vetor de mensagens
	*/
	vector<Mensagem *> getMensagens() const;
	/**
	* @ brief Funcao que ordena as mensagens de uma conversa por ordem cronologica
	* @ return void
	*/
	void ordenarData();
	/**
		 * @brief Funcao que permite fazer o overloading do operador == de modo a conseguir igualar 2 objetos do tipo Conversa.
		 * O criterio de igualdade sao os participantes.
		 * @param c Conversa que vamos comparar.
		 * @return True se forem iguais, false se diferentes.
		 */
	bool operator==(Conversa&c)const;
	/**
		* @ brief Funcao que imprime os participantes de uma conversa
		* @ return void
		*/
  void imprimirParticipantes() const;
};

#endif /* SRC_CONVERSA_H_ */
