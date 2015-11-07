#ifndef SRC_EXCECOES_H_
#define SRC_EXCECOES_H_

#include <string>

using namespace std;

/********************************
*		EXCECAO UTILIZADOR		*
********************************/
/**
 * @brief Classe que representa uma excecao da classe utilizador.
 *  Esta excecao e lançada quando um utilizador não existe.
 */
class UtilizadorInexistente {
private:
  string u; /**<  membro privado que representa o login do utilizador que cria a excecao */
public:
  /**
  	* @brief Construtor.
  	* Inicializa o membro u com o login do utilizador recebido.
  	* @param u Login do utilizador recebido
  	*/
  UtilizadorInexistente(string u) { this->u = u; };
  /**
  	* @brief Funcao que retorna o login do utilizador.
  	* @return Login do utilizador que criou a excecao
  	*/
  string getLogin() const { return u; };
};

/**
 * @brief Classe que representa uma excecao da classe utilizador.
 * Esta excecao e lancada quando um utilizador ja existe e nao devia.
 */
class UtilizadorJaExiste {
private:
  string login;	/**<  membro privado que representa o login do utilizador que cria a excecao */
public:
  /**
   	* @brief Construtor.
   	* Inicializa o membro login com o login do utilizador recebido.
   	* @param l Login do utilizador recebido
   	*/
  UtilizadorJaExiste(string l) { l = login; };
  /**
    * @brief Funcao que retorna o login do utilizador.
    * @return Login do utilizador que criou a excecao
    */
  string getLogin() const { return login; };
};

/**
 * @brief Classe que representa uma excecao da classe utilizador.
 * Esta excecao e lancada quando um utilizador nao tem idade suficiente para se registar na aplicação.
 */
class IdadeInsuficiente {
private:
  int idade; /**<  membro privado que representa a idade do utilizador que cria a excecao */
public:
  /**
   * @brief Construtor.
   * Inicializa o membro idade com a idade do utilizador recebido.
   * @param idade Idade do utilizador recebido.
   */
  IdadeInsuficiente(int idade) { this->idade = idade; };
};

/**
 * @brief Classe que representa uma excecao da classe utilizador.
 * Esta excecao e lancada quando o amigo do utilizador ja existe
 */
class AmigoJaExiste {
private:
  string login; /**<  membro privado que representa o login do utilizador que cria a excecao */
public:
  /**
    * @brief Construtor.
    * Inicializa o membro login com o login do amigo do utilizador.
    * @param l Login do amigo do utilizador recebido.
    */
  AmigoJaExiste(string l) { login = l; };
  /**
   * @brief Funcao que retorna o login do utilizador que criou a excecao.
   * @return Login do amigo do utilizador.
   */
  string getLogin() const { return login; };

};

/**
 * @brief Classe que representa uma excecao da classe utilizador.
 * Esta excecao e lancada quando o amigo do utilizador nao existe
 */
class AmigoInexistente {
private:
  string login; /**<  membro privado que representa o login do utilizador que cria a excecao */
public:
  /**
   * @brief Construtor.
   * Inicializa o membro login com o login do amigo do utilizador.
   * @param l Login do amigo do utilizador recebido.
   */
  AmigoInexistente(string l) { login = l; };
  /**
   * @brief Funcao que retorna o login do utilizador que criou a excecao.
   * @return Login do utilizador.
   */
  string getLogin() const { return login; };
};

/**
* @brief Classe que representa uma excecao da classe utilizador.
* Esta excecao e lancada quando se tenta adicionar uma conversa que já faz parte das conversas do utilizador.
*/
class ConversaJaExiste {
public: 
  /**
  * @brief Construtor de ConversaJaExiste
  */
  ConversaJaExiste(vector<string> p) { participantes = p; };
  /**
  * @brief Funcao que imprime os participantes da conversa
  */
  void imprimirParticipantes() const {
    cout << participantes[0] << " , " << participantes[1] << endl;
  };
private:
  vector<string> participantes;/**<  membro privado que representa a conversa que cria a excecao */
};

/********************************
*			EXCECAO MAIN		*
********************************/

/**
 * @brief Classe que representa uma excecao da classe Main.
 * Esta excecao e lancada quando a opcao colocada nao esta entre os limites estabelecidos.
 * E uma classe template pois pode receber mais que um tipo de dados.
 */
template <class N>
class OpccaoInvalida {
private:
  N op;		/**< membro privado que representa a opcao colocada */
  N min;	/**< membro privado que representa a opcao minima */
  N max;	/**< membro privado que representa a opcao maxima */
public:
  /**
	* @brief Construtor.
	* Inicializa os membros op, min e max com, repetivamente, a opcao escolhida, a opcao minima e a opcao maxima.
	* @param op Opcao escolhida.
	* @param min Opcao minima.
	* @param max Opcao maxima.
	*/
  OpccaoInvalida(N op, N min, N max) { this->op = op; this->min = min; this->max = max; };
  /*
   * @brief Funcao que retorna a opcao minima.
   * @return Opcao minima.
   */
  N getMin() const { return min; };
  /*
   * @brief Funcao que retorna a opcao maxima.
   * @return Opcao maxima.
   */
  N getMax() const { return max; };
  /**
   * @brief Funcao que retorna a opcao escolhida.
   * @return Opcao escolhida.
   */
  N getOp() const { return op; };
};

/**
 * @brief Classe que representa uma excecao da classe main.
 * Permite ter a opcao de voltar a tras nos menus.
 */
class VoltarAtras {};

/**
 * @brief Classe que representa uma excecao da classe main.
 * Impede que o programa aborte quando sao introduzidos valores errados no buffer.
 */
class InputFail {};

/********************************
*			EXCECAO GRUPO		*
********************************/
/**
* @brief Classe que representa uma excecao da classe grupo.
* Esta excecao e lancada no caso de não haver um membro com um determinado login
*/
class MembroInexistente {
public:
  MembroInexistente(string login) { this->login = login; };
  string getLogin() const { return login; };
private:
  string login;
};
/**
* @brief Classe que representa uma excecao da classe grupo.
* Esta excecao e lancada no caso de o utilizador que esta a pedir permissoes nao ser o utilizador moderador do grupo.
*/
class NaoModerador{
private:
	string mod;  /**<  membro privado que representa o utilizador que cria a excecao */
public:
	/**
	* @brief Construtor.
	* Inicializa o membro mod com o utilizador recebido.
	* @param mod Utilizador recebido.
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

/**
 * @brief Classe que representa uma excecao da classe grupo.
 * Esta excecao e lancada quando nao existe no vetor de pedidos de adesao de um grupo o login recebido.
 */
class PedidoInexistente{
private:
	string login; /**< membro privado que representa o login do utilizador que criou a excecao */
public:
	/**
	 * @brief Construtor.
	 * Inicializa o membro login com o login do utilizador que criou a excecao
	 * @param l Login recebido.
	 */
	PedidoInexistente(string l){login = l;};
	/**
	 * @brief Funcao que retorna o login do utilizador
	 * @return login
	 */
	string getLogin() const{return login;};
};

/**
 * @brief Classe que representa uma excecao da classe grupo.
 * Esta excecao e lancada quando um utilizador que foi bloqueado de um grupo tenta enviar uma mensagem.
 */
class Bloqueado{
private:
	string login; /**< membro privado que representa o login do utilizador que criou a excecao */
public:
	/**
	 * @brief Construtor.
	 * Inicializa o membro login com o login recebido.
	 * @param l Login recebido.
	 */
	Bloqueado(string l){login = l;};
	/**
	 * @brief Funcao que retorna o login do utilizador que retorna a excecao
	 */
	string getLogin() const{return login;};
};
/**
* @brief Classe excepção que é lançada quando se procura um grupo que nao existe
*/
class GrupoInexistente {
public:
  /**
  * @brief Construtor.
  * @param n posicao de um grupo num vector de grupos.
  */
  GrupoInexistente(int n) { this->n = n; };
  /**
  * @brief retorna a posicao do grupo num vector de grupos
  * @return n posicao
  */
  int getGrupo() const { return n; };
private:
  int n;/**< membro privado que representa a posicao do grupo que criou a excecao */
};

/********************************
*		EXCECAO SYSTEM			*
********************************/
/**
* @brief Classe DataInvalida.
* E uma classe que indica uma execao da classe Data.
*/
class DataInvalida {
private:
  int dia; /**< membro privado que representa o dia invalido */
  int mes; /**< membro privado que representa o dia invalido */
  int ano; /**< membro privado que representa o dia invalido */
public:
  /**
   * @brief Construtor.
   * Inicializa os mebros privados dia mes e ano com os parametros reecebidos correspondentes.
   * @param d Dia invalidos.
   * @param m Mes invalido.
   * @param a Ano invalido.
   */
  DataInvalida(int d, int m, int a) { dia = d; mes = m; ano = a; };
  /**
   * @brief Funcao que retorna o dia invalido.
   * @return Dia invalido.
   */
  int getDia() const { return dia; };
  /**
     * @brief Funcao que retorna o mes invalido.
     * @return Mes invalido.
     */
  int getMes() const { return mes; };
  /**
     * @brief Funcao que retorna o ano invalido.
     * @return Ano invalido.
     */
  int getAno() const { return ano; };
};

/**
* @brief Classe HoraInvalida.
* E uma classe que indica uma execao da classe Horas.
*/
class HoraInvalida {};

/********************************
*		EXCECAO CONVERSA		*
********************************/

/**
 * @brief Classe que representa uma excecao da classe conversa.
 * Esta excecao e lancada quando um utilizador que nao participa na conversa tenta enviar mensagens.
 */
class NaoParticipante{
private:
	string p; /**< membro privado que representa o login do utilizador que criou a excecao */
public:
	/**
	 * @brief Construtor.
	 * Inicializa o membro p com o login do utilizador que nao e participante.
	 * @param p Login do participante.
	 */
	NaoParticipante(string p){this->p = p;};
	/**
	 * @brief Funcao que retorna o login do nao participante
	 * @return p Login do utilizador nao participante
	 */
	string getlogin() const{return p;};
};
/**
* @brief Classe que representa uma excecao da classe conversa.
* Esta excecao e lancada quando um utilizador escolhe a posicao de uma conversa que não existe 
*/
class ConversaInexistente {
public:
  /**
  * @brief Construtor da classe ConversaInexistente
  * @param i posicao da conversa inexistente
  */
  ConversaInexistente(int i) { this->i = i; };
  /**
  * @brief Funcao que retorna a posicao da conversa inexistente
  * @return i
  */
  int getPosicao() const { return i; };
private:
  int i;/**< membro privado que representa a posicao que lancou a excessao */
};

#endif
