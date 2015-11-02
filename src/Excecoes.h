#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_



class UtilizadorJaExiste {
private:
  Utilizador u;
  string login;
public:
  UtilizadorJaExiste(Utilizador u) { this->u = u; };
  UtilizadorJaExiste(string login) { this->login = login; };
  string getLogin() const { return u.getNome(); };
};

class UtilizadorInexistente {
private:
  Utilizador u;
public:
  UtilizadorInexistente(Utilizador u) { this->u = u; };
  string getLogin() const { return u.getNome(); };
};

class TelemovelJaExiste {
private:
  int t;
public:
  TelemovelJaExiste(int t) { this->t = t; };
  int getTelemovel() const { return t; };
};

class TelemovelInexistente {
private:
  int t;
public:
  TelemovelInexistente(int t) { this->t = t; };
  int getTelemovel() const { return t; };
};
class IdadeInsuficiente {
public:
  IdadeInsuficiente(int idade) { this->idade = idade; };
private:
  int idade;
};

/*******************************************************
* 			      	   	      DATA		                	   *
*****************************************************/
/**
* @brief Classe HoraInvalida.
* E uma classe que indica uma execao da classe Horas.
*/
class HoraInvalida {};

/*******************************************************
* 			      	   	      GRUPO		                	   *
*****************************************************/

/**
* @brief Classe que representa uma excecao da classe grupo.
* esta excecao e lancada no caso de o utilizador que esta a pedir permissoes nao ser o utilizador moderador
*/
class NaoModerador {
private:
  Utilizador mod;  /**<  membro privado que representa o utilizador que cria a excecao */
public:
  /**
  * @brief Construtor
  * inicializa o membro mod com o utilizador recebido
  * @param mod utilizador recebido
  */
  NaoModerador(Utilizador mod) {
    this->mod = mod;
  };
  /**
  * @brief Funcao que retorna o utilizador
  * @return mod
  */
  Utilizador getUtil() const {
    return mod;
  };
};

#endif