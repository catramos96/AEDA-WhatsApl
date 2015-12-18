#ifndef SRC_MEMBRO_H_
#define SRC_MEMBRO_H_

#include <iostream>
#include <string>
#include <vector>

#include "System.h"

/**
* @brief Classe Membro.
* Classe que define os parametros necessarios para um utilizador estar num grupo.
* Associa o login de um utilizador a data de adesao no grupo e a um boleano que indica se esta bloqueado.
*/
class Membro {
private:
	string login;  /**<  membro privado que representa o login do utilizador */
	Data adesaoGrupo;  /**<  membro privado que representa a data de adesao ao grupo*/
	bool bloqueado;  /**<  membro privado que indica se o utilizador esta ou nao bloqueado do grupo */
	Data bloqueio; /**< membro privado que indica a data do ultimo bloqueio de um membro */
public:
	/**
	* @brief Construtor default.
	*/
	Membro();
	/**
	* @brief construtor Membro.
	* Inicializa o Utilizador util com o utilizador dado, a Data adesaoGrupo com a data dada, e o boleano bloqueado a 'false'.
	* @param login Login do utilizador.
	* @param adesaoGrupo data em que aderiu ao grupo.
	*/
	Membro(string login, Data adesaoGrupo);
	/**
	* @brief Funcao que retorna o login do Utilizador util.
	* @return util.
	*/
	string getLogin() const;
	/**
	* @brief Funcao que retorna a Data de adesao do utilizador ao grupo.
	* @return AdesaoGrupo.
	*/
	Data getDataCriacao() const;
	/**
	* @brief Funcao que retorna a Data de bloqueio do utilizador ao grupo.
	* @return bloqueio.
	*/
	Data getDataBloqueio() const;
	/**
	* @brief Funcao que permite alterar o login do membro.
	* @param login Novo login.
	*/
	void setLogin(string login);
	/**
	* @brief Funcao que permite alterar a data inicial.
	* @param d Nova data.
	*/
	void setData(Data d);
	/**
	* @brief Funcao que coloca uma nova data de bloqueio de um membro.
	* @param d Data de bloqueio.
	*/
	void setDataBloqueio(Data d);
	/**
	* @brief Funcao que coloca um novo valor ao membro privado 'bloqueado'.
	* @param bloq Boleano com o valor true ou false.
	*/
	void setBloqueio(bool bloq);
	/**
	* @brief Funcao que indica o estado atual do membro privado 'bloqueado'.
	* @return bloqueado.
	*/
	bool isBloqueado() const;
	/**
	* @brief Operador de igualdade.
	* Compara 2 membros através do utilizador.
	* @return true se os utilizadores forem iguais, false se forem diferentes.
	*/
	bool operator==(const Membro &m) const;
	/**
	* @brief Operador de extracao.
	* Faz o output dos membros privados da classe.
	* @return out
	*/
	friend ostream & operator<<(ostream & out, const Membro & m);

	/**
	* @brief Overloading do operador menor.
	* E usado o login dos memsbros como termo de comparacao.
	* @param m Membro com que vamos comparar o membro atual.
	* @return True se e menor, ou false em caso contrario.
	*/
	bool operator<(const Membro &m) const;
};

#endif