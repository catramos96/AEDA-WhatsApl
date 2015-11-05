#ifndef SRC_EXCECOES_H_
#define SRC_EXCECOES_H_

#include <string>

using namespace std;

class UtilizadorInexistente {
private:
	string u;
public:
	UtilizadorInexistente(string u){ this->u = u; };
	string getLogin() const { return u; };
};


/**
* @brief Classe que representa uma excecao da classe grupo.
* esta excecao e lancada no caso de o utilizador que esta a pedir permissoes nao ser o utilizador moderador
*/
class NaoModerador{
private:
	string mod;  /**<  membro privado que representa o utilizador que cria a excecao */
public:
	/**
	* @brief Construtor
	* inicializa o membro mod com o utilizador recebido
	* @param mod utilizador recebido
	*/
	NaoModerador(string mod){
		this->mod = mod;
	};
	/**
	* @brief Funcao que retorna o utilizador
	* @return mod
	*/
	string getNome() const{
		return mod;
	};
};

#endif