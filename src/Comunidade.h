#ifndef SRC_COMUNIDADE_H_
#define SRC_COMUNIDADE_H_

#include "Utilizador.h"
#include "BST.h"
#include <vector>
#include <tr1/unordered_set>
using namespace std;

/**
* @brief Struct with the hash function for users who haven't logged in a month
*
*/

struct hUtilizadoresInativos
{
	int operator()(const Utilizador* u) const
	{
		return u->inativo();
	}

	bool operator()(const Utilizador* u1, const Utilizador* u2) const
	{
		return (u1->getLogin() == u2->getLogin());
	}
};

typedef tr1::unordered_set<Utilizador*, hUtilizadoresInativos, hUtilizadoresInativos> hashInativos;



/**
* @brief Classe Comunidade.
* Class que contem e gere todos os utilizadores
* E possivel ordenar os utilizadores por data de adesão, login
*/
class Comunidade {
private:
  vector<Utilizador*> comunidade; /**<  membro privado que contem todos os utilizadores */
  hashInativos utilizadoresInativos; /**<  membro privado que contem todos os utilizadores inativos por 1 mes */
public:
  /**
  * @brief Construtor
  * Construtor default que inicializa o vector de utilizadores a zero
  */
  Comunidade();

  /**
   * @ brief Funcao que carrega para uma tabela de dispersao os utilizadores inativos
   * @
   * @ return void
   */
  void updateUtilizadoresInativos();
  /**
   * @ brief Funcao que imprime todos os utilizadores inativos à mais de 30 dias
   * @
   * @ return void
   */
  void printUtilizadoresInativos() const;
  /**
   * @ brief Funcao que verifica a existencia de um certo utilizador
   * @ param util : indica o utilizador
   * @ return posicao
   */
  int existeUtil(Utilizador *util) const;

  /**
   * @ brief Funcao que verifica a existencia de um certo utilizador na tabela de dispersao
   * @ param util : indica o utilizador
   * @ return posicao
   */
  int existeUtilInativo(Utilizador *util) const;

  /**
  * @brief Funcao que procura um utilizador na comunidade pelo login
  * @param login Login do utilizador
  * @return posicao
  */
  int existeUtilLogin(string login) const;

  /**
  * @ brief Funcao que verifica a existencia de um certo utilizador
  * @ param util : indica o nome do utilizador
  * @ return posicao
  */
  int existeUtilNome(string nome) const;

  /**
  * @ brief Funcao que verifica a existencia de um certo grupo
  * @ param util : indica o nome do grupo
  * @ return Grupo
  */
  Grupo* existeGrupo(string grupo) const;
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
  /**
  * @brief Funcao que verifica se existe um login.
  * @param l Login que vamos procurar
  * @return true se já existe, false se nao
  */
  bool existeLogin(string l) const;
  /**
  * @brief Funcao que le um ficheiro de texto com os utilizadores e coloca a informacao no local certo.
  * @param path Caminho onde se encontra o ficheiro utilizadores.txt
  */
  void leUtilizador(string path);
  /**
  * @brief Funcao que le um ficheiro de texto com as conversas e coloca a informacao no local certo.
  * @param path Caminho onde se encontra o ficheiro conversas.txt
  */
  void leConversa(string path);
  /**
  * @brief Funcao que le um ficheiro de texto com os grupos e coloca a informacao no local certo.
  * @param path Caminho onde se encontra o ficheiro grupos.txt
  */
  void leGrupo(string path);
  /**
  * @brief Funcao que converte a informacao do programa sobre utilizadores num ficheiro .txt
  * @param path Caminho onde se encontra o ficheiro utilizadores.txt
  * @return 0 se sucesso ou 1 se insucesso
  */
  int escreveUtilizador(string path);
  /**
  * @brief Funcao que converte a informacao do programa sobre conversas num ficheiro .txt
  * @param path Caminho onde se encontra o ficheiro conversas.txt
  * @return 0 se sucesso ou 1 se insucesso
  */
  int escreveConversa(string path);
  /**
  * @brief Funcao que converte a informacao do programa sobre grupos num ficheiro .txt
  * @param path Caminho onde se encontra o ficheiro grupos.txt
  * @return 0 se sucesso ou 1 se insucesso
  */
  int escreveGrupo(string path);

  /**
  * @brief Funcao que analiza os utilizadores mais ativos nos ultimos 3 dias da aplicação
  * @return árvore binária de pesquisa com a informação dos utilizadores mais ativos
  */
  BST<Utilizador> topUtilizadores() const;

  /**
  * @brief Funcao que mostra no ecra os utilizadores mais ativos
  */
  void displayTopUtilizadores() const;
};

#endif /* SRC_COMUNIDADE_H_ */
