#ifndef SRC_EXCECOES_H_
#define SRC_EXCECOES_H_

#include <string>

using namespace std;

/************************************
*	       EXCECAO UTILIZADOR			    *
************************************/
class UtilizadorInexistente {
private:
  string u;
public:
  UtilizadorInexistente(string u) { this->u = u; };
  string getLogin() const { return u; };
};

class UtilizadorJaExiste {
private:
  string login;
public:
  UtilizadorJaExiste(string l) { l = login; };
  string getLogin() const { return login; };
};

class IdadeInsuficiente {
public:
  IdadeInsuficiente(int idade) { this->idade = idade; };
private:
  int idade;
};

class AmigoJaExiste {
public:
  AmigoJaExiste(string l) { login = l; };
private:
  string login;
};

/************************************
*	    	    EXCECAO MAIN			      *
************************************/
template <class N>
class OpccaoInvalida {
public:
  OpccaoInvalida(N op, N min, N max) { this->op = op; this->min = min; this->max = max; };
  N getMin() const { return min; };
  N getMax() const { return max; };
  N getOp() const { return op; };
private:
  N op;
  N min;
  N max;
};

class VoltarAtras {};

class InputFail {};

/************************************
*	    	    EXCECAO GRUPO 		      *
************************************/
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

/************************************
*	    	    EXCECAO SYSTEM 		      *
************************************/
/**
* @brief Classe DataInvalida.
* E uma classe que indica uma execao da classe Data.
*/
class DataInvalida {
public:
  DataInvalida(int d, int m, int a) { dia = d; mes = m; ano = a; };
  int getDia() const { return dia; };
  int getMes() const { return mes; };
  int getAno() const { return ano; };
private:
  int dia;
  int mes;
  int ano;

};

#endif