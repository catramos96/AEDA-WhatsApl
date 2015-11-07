#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Grupo.h"

/**
* @brief Classe Utilizador.
* Cada Utilizador tem como unico o seu login e tem que ter como obrigatorio maior de 18 anos.
* A Classe Utilizador permite ter conversas e grupos com aqueles que apenas fazem parte do seu grupo de amigos.
* Esta Classe permite a gestao e a criacao de novos objectos Grupo, Conversa e Mensagens.
*/
class Utilizador
{
private:
	bool visibilidade; /**< membro privado que representa a visibilidade, 1 - publico e 0 - privado */
	string login; /**< membro privado que representa login (unico para cada utilizador que existe) */
	string nome; /**< membro privado que representa o nome */
	string email; /**< membro privado que representa o email */
	int telemovel; /**< membro privado que representa o telemovel */
	Data dataAdesao; /**< membro privado que representa a data de adesao (criacao do utilizador) */
	int idade; /**< membro privado que representa a idade */
	vector<Utilizador *> amigos; /**< membro privado que representa os amigos*/
	vector<Conversa *> conversas; /**< membro privado que representa as conversas */
	vector<Grupo *> grupos; /**< membro privado que representa os grupos de conversas */
public:
	/**
	* @brief Construtor Utilizador;
	*/
	Utilizador();
	/**
	* @brief Destrutor Utilizador;
	*/
	~Utilizador();
  /**
  * @brief Construtor classe Utilizador
  * @param visibilidade do utilizador
  * @param login do utilizador
  * @param nome do utilizador
  * @param email do utilizador
  * @para dataAdesao data de adesao do utilizador
  * @param telemovel do utilizador
  * @param idade do utilizador
  */
	Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao, int telemovel, int idade);

	/*****************************************************************
	*                             GETS                               *
	*****************************************************************/

	/**
	*@brief Funcao que retorna o nome do Utilizador
	*@return nome
	*/
	string getNome() const;
	/**
	*@brief Funcao que retorna o email do Utilizador
	*@return email
	*/
	string getEmail() const;
	/**
	*@brief Funcao que retorna o login do Utilizador
	*@return login
	*/
	string getLogin() const;
	/**
	*@brief Funcao que retorna o telemovel do Utilizador
	*@return telemovel
	*/
	int getTelemovel()const;
	/**
	*@brief Funcao que retorna a idade do Utilizador
	*@return idade
	*/
	int getIdade() const;
	/**
	*@brief Funcao que retorna a visibilidade do Utilizador
	*@return visibilidade
	*/
	bool getVisibilidade() const;
	/**
	*@brief Funcao que retorna a data de adesao do Utilizador
	*@return dataAdesao
	*/
	Data getDataAdesao() const;
	/**
	*@brief Funcao que retorna um vector de Utilizadores que sao os amigos do Utilizador
	*@return amigos
	*/
	vector<Utilizador *> getAmigos() const;
	/**
	*@brief Funcao que retorna um apontador para um Utilizador dos amigos com um determinado login
	*@param login login do Utilizador pertencente aos amigo do Utilizador
	*@return Utilizador*
	*/
	Utilizador * getAmigo(string login) const;
	/**
	*@brief Funcao que retorna um apontador para um Grupo dos grupos de conversa de indice i
	*@param i posicao nos grupos do utilizador
	*@return Grupo*
	*/
	Grupo* getGrupo(int i) const;
	/**
	*@brief Funcao que retorna os grupos do utilizador
	*@return grupos
	*/
	vector<Grupo *> getGrupos() const;
  /**
  *@brief Funcao que retorna a conversa na posicao i
  *@param i posicao da conversa
  *@return conversas[i]
  */
  Conversa* getConversa(int i) const;
  /**
  *@brief Funcao que retorna o nome destinatario da Conversa
  *@param c conversa
  *@return string (nome destinatario)
  */
  string getDestinatarioConversa(Conversa *c) const;
  
	/*****************************************************************
	*                             SETS                               *
	*****************************************************************/

  /**
  * @brief Funcao que altera o login de um utilizador
  * @param l novo login do utilizador
  */
	void setLogin(string l);
  /**
  * @brief Funcao que altera o nome de um utilizador
  * @param n novo nome do utilizador
  */
	void setNome(string n);
  /**
  * @brief Funcao que altera o email de um utilizador
  * @param e novo email do utilizador
  */
	void setEmail(string e);
  /**
  * @brief Funcao que altera a idade do Utilizador
  * lanca a excepção IdadeInsuficiente se for < 18
  * @param i nova idade
  */
	void setIdade(int i);
  /**
  * @brief Funcao que altera a visibilidade de um utilizador
  * @param v nova visibilidade do utilizador
  */
	void setVisibilidade(bool v);
  /**
  * @brief Funcao que altera o telemovel de um utilizador
  * @param t novo telemovel do utilizador
  */
	void setTelemovel(int t);
  /**
  * @brief Funcao que altera a data de adesao de um utilizador
  * @param d dia de adesao
  * @param m mes de adesao
  * @param a ano de adesao
  */
	void setData(int d, int m, int a);

  /*****************************************************************
  *                             ADDS                               *
  *****************************************************************/

  /**
  * @brief Funcao que adiciona um utilizador aos amigos do utilizador
  * @param u utilizador a adicionar
  */
  void addAmigosAux(Utilizador *u);
  /**
  * @brief Funcao que adiciona um utilizador como amigos
  * chama a funcao addAmigosAux para adicionar o utilizador u aos meus amigos
  * e para eu ser adicionado aos amigos de u
  * @param u utilizador a adicionar
  */
	void addAmigo(Utilizador &u);
  /**
  * @brief Funcao que adiciona um grupo aos grupos do utilizador
  * se o grupo nao pertencer aos meus grupos
  * @param g grupo a adicionar
  * @return bool true - adicionado , false - já existe (não adicionado)
  */
  bool addGrupo(Grupo *g);
  /**
  * @brief Funcao que adiciona uma conversa as conversas do utilizador
  * se a conversa já não existir
  * @param c conversa a adicionar
  */
  void addConversa(Conversa *c); 
  /**
  * @brief Funcao que adiciona um membro u a um grupo d
  * @param u utilizador a adicionar
  * @param g grupo a adicionar
  * @param d data de adicionado
  * @return bool , true - adicionado , false - nao adicionado
  */
  bool adicionaMembro(Utilizador *u, Grupo *g, Data d);

  /*****************************************************************
  *                            REMOVER                             *
  *****************************************************************/

  /**
  *@brief Funcao que retira o utilizador u dos amigos do utilizador
  *@param u utilizador a remover
  */
	void removerAmigoAux(Utilizador *u); //eliminar um amigo
  /**
  *@brief Funcao que remove u dos meus amigos e eu dos amigos de u
  * usando a fun~cao removerAmigoAux
  *@param u utilizador a remover
  */
	void removerAmigo(Utilizador &u); //remove u dos meus amigos, e remove-me dos amigos de u
  /**
  * @brief Funcao que remove um utilizador u de um grupo g
  * @param u utilizador a remover
  * @param g grupo onde u vai ser removeido
  * @param diaAtual data em que foi removido
  * return bool , true - removido , false - nao removido
  */
  bool removerMembro(Utilizador *u, Grupo *g, Data diaAtual);
  /**
  * @brief Funcao que remove a conversa c das conversas do utilizador
  * @param c conversa a remover
  */
  void removerConversa(Conversa *c);

  /*****************************************************************
  *                           IMPRIMIR                             *
  *****************************************************************/

  /**
  *@brief Funcao que imprime no ecra as definicoes do utilizador
  */
	void imprimirDefinicoes() const;
  /**
  *@brief Funcao que imprime no ecra o perfil do utilizador
  * com as informações do mesmo dependendo da visibilidade.
  */
	void imprimirUtilizador() const;
  /**
  *@brief Funcao que imprime no ecra os amigos do utilizador
  */
	void imprimirAmigos() const;
  /**
  *@brief Funcao que imprime no ecra os grupos do utilizador
  */
	void imprimirGrupos() const;
  /**
  *@brief Funcao que imprime no ecra as conversas do utilizador
  */
  void imprimirConversas() const;
  /**
  *@brief Funcao que imprime no ecra todos os grupos (não repetidos)
  * de todos os amigos do utilizador incluindo os do proprio
  */
  void imprimirGruposAmigos() const;

  /*****************************************************************
  *                         OPERADORES                             *
  *****************************************************************/

  /**
  * @brief overloading do operador == que compara o utilzador e u
  * @param u utilizador com quem se vai comparar
  * @return bool , true - se tiverem o mesmo login
  */
	bool operator==(const Utilizador&u)const;
  /**
  * @brief overloading do operador < que compara o utilzador e u
  * @param u utilizador com quem se vai comparar
  * @return bool , true - o login do utilizador for < que o de u
  */
	bool operator<(const Utilizador &u) const;
  /**
  * @brief overloading do operador << do utilizador
  * @param out ostream de saida
  * @param u utilizador a imprimir
  * @return out
  */
	friend ostream & operator<<(ostream & out, const Utilizador & u);

  /*****************************************************************
  *                             SAIR                               *
  *****************************************************************/

  /**
  * @brief Funcao que me remove a conversa c das minhas conversas
  * e c das conversas do destinatario da mesma
  * @param c conversa a eliminar
  */
  void sairConversa(Conversa * c);
  /**
  * @brief Funcao que remove o grupo g dos meus grupos
  * @param g grupo a remover
  */
  void sairGrupo(Grupo *g);

  /*****************************************************************
  *                           OUTROS                               *
  *****************************************************************/

  /**
  * @brief Funcao que cria uma conversa com o utilizador u e adiciona-a as conversas 
  * de ambos os participantes
  * @param u utilizador que participa na conversa
  * @return retorna a conversa criada
  */
  Conversa *criarConversa(Utilizador *u);
  /**
  * @brief Funcao que adiciona uma mensagem a uma conversa
  * @param sms mensagem a adicionar
  * @param c conversa a que vai ser adicionada a mensagem
  */
  void enviarMensagem(Mensagem *sms, Conversa *c);
  /**
  * @brief Funcao que adiciona um pedido de adesao do utilizador ao grupo g
  * @param g grupo a que o utilizador quer aderir
  */
  void pedirAdesao(Grupo *g);
  /**
  * @brief Funcao que cria um grupo e o adiciona aos grupos do utilizador
  * @param titulo titulo do grupo
  * @param dataAtual data da criacao do grupo
  * @return Grupo * grupo criado
  */
  Grupo *criarGrupo(string titulo, Data dataAtual);
  /**
  * @brief Funcao que envia uma mensagem para um grupo
  * @param sms mensagem que se quer enviar
  * @param g grupo para o qual se quer enviar a mensagem
  */
  void enviarMensagemGrupo(Mensagem *sms, Grupo *g);
  bool aceitaMembro(Utilizador *u, Grupo *g, Data d);
  bool rejeitaMembro(Utilizador *u, Grupo *g, Data d);
  bool bloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);
  bool desbloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);
  Grupo *escolheGruposAmigos(int i) const;
  
};

#endif /* SRC_UTILIZADOR_H_ */
