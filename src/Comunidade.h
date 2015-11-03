#ifndef SRC_COMUNIDADE_H_
#define SRC_COMUNIDADE_H_

#include "Utilizador.h"
#include <vector>

using namespace std;

/**
 * @brief Classe Comunidade.
 * Class que contem e gere todos os utilizadores
 * E possivel ordenar os utilizadores por data de adesão, login
 */
class Comunidade
{
private:
	vector<Utilizador*> comunidade; /**<  membro privado que contem todos os utilizadores */
public:
	/**
	* @brief Construtor
	* Construtor default que inicializa o vector de utilizadores a zero
	*/
	Comunidade();
	/**
	 * @ brief Funcao que verifica a existencia de um certo utilizador
	 * @ param util : indica o utilizador
	 * @ return posicao
	 */
	int existeUtil(Utilizador *util) const;
	/**
	* @ brief Funcao retorna o utilizador que se encontra na posicao "pos" do vetor comunidade
	* @ param pos: posicao do utilizador
	* @ return utilzador
	*/
	Utilizador *utilizadorNaPosicao(int pos) const;
	/**
	* @ brief Funcao que adiciona um utilizador à comunidade
	* @ param util: utilizador
	* @ return void
	*/
	void adicionarUtil(Utilizador *util);
	/**
	* @ brief Funcao ordena a comunidade por data de adesao
	* @ return void
	*/
	void ordenaData();
	/**
	* @ brief Funcao ordena a comunidade por login
	* @ return void
	*/
	void ordenaLogin();
	/**
	* @ brief Funcao que imprime informações acerca do utilizador
	* @ return void
	*/
	void verUtilizador(Utilizador *util) const;
	/**
	* @ brief Funcao imprime todos os utilizadores da comunidade
	* @ return void
	*/
	void printComunidade() const;

	bool existeLogin(string l) const;
};

#endif /* SRC_COMUNIDADE_H_ */
