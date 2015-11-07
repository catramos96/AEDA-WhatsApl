#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Grupo.h"

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
	* @ brief Construtor Utilizador;
	*/
	Utilizador();
	/**
	* @ brief Destrutor Utilizador;
	*/
	~Utilizador();
	/**
		   * @ brief Construtor que inicializa a visiblidade, login, email, data de adesao, telemovel e idade)
		   */
	Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao, int telemovel, int idade);

	/*****************************************************************
	*                             GETS                               *
	*****************************************************************/

	/**
	* @ brief Funcao que retorna o nome do Utilizador
	* @ return nome
	*/
	string getNome() const;
	/**
	* @ brief Funcao que retorna o email do Utilizador
	* @ return email
	*/
	string getEmail() const;
	/**
	* @ brief Funcao que retorna o login do Utilizador
	* @ return login
	*/
	string getLogin() const;
	/**
	* @ brief Funcao que retorna o telemovel do Utilizador
	* @ return telemovel
	*/
	int getTelemovel()const;
	/**
	* @ brief Funcao que retorna a idade do Utilizador
	* @ return idade
	*/
	int getIdade() const;
	/**
	* @ brief Funcao que retorna a visibilidade do Utilizador
	* @ return visibilidade
	*/
	bool getVisibilidade() const;
	/**
	* @ brief Funcao que retorna a data de adesao do Utilizador
	* @ return dataAdesao
	*/
	Data getDataAdesao() const;
	/**
	* @ brief Funcao que retorna um vector de Utilizadores que sao os amigos do Utilizador
	* @ return amigos
	*/
	vector<Utilizador *> getAmigos() const;
	/**
	* @ brief Funcao que retorna um apontador para um Utilizador dos amigos com um determinado login
	* @ param login login do Utilizador pertencente aos amigo do Utilizador
	* @ return Utilizador*
	*/
	Utilizador * getAmigo(string login) const;
	/**
	* @ brief Funcao que retorna um apontador para um Grupo dos grupos de conversa de indice i
	* @ param i posicao nos grupos do utilizador
	* @ return Grupo*
	*/
	Grupo* getGrupo(int i) const;
	/**
	* @ brief Funcao que retorna os grupos do utilizador
	* @ return grupos
	*/
	vector<Grupo *> getGrupos() const;

	/*****************************************************************
	*                             SETS                               *
	*****************************************************************/

	void setGrupo(Grupo grupo);
	void setLogin(string l);
	void setNome(string n);
	void setEmail(string);
	void setIdade(int i);
	void setVisibilidade(bool v);
	void setAmigos(Utilizador *u);
	void setTelemovel(int i);
	void setData(int d, int m, int a);

	void addAmigo(Utilizador &u);
	void removerAmigoAux(Utilizador *u); //eliminar um amigo
	void removerAmigo(Utilizador &u); //remove u dos meus amigos, e remove-me dos amigos de u

	void imprimirDefinicoes() const;
	void imprimirUtilizador() const;
	void imprimirAmigos() const;
	void imprimirGrupos() const;

	bool operator==(const Utilizador&u)const;
	bool operator<(const Utilizador &u) const;
	friend ostream & operator<<(ostream & out, const Utilizador & u);

	Conversa *criarConversa(Utilizador *u);
	void adicionarConversa(Conversa *c); // se outro utilizador criar a conversa pode adicionar a conversa criada a este utilizador
	void enviarMensagem(Mensagem *sms, Conversa *c);

	void pedirAdesao(Grupo *g);
	Grupo *criarGrupo(string titulo, Data dataAtual);
	bool adicionarGrupo(Grupo *g);
	bool eliminarGrupo(Grupo *g);
	void enviarMensagemGrupo(Mensagem *sms, Grupo *g);
	bool adicionaMembro(Utilizador *u, Grupo *g, Data d);
	bool aceitaMembro(Utilizador *u, Grupo *g, Data d);
	bool rejeitaMembro(Utilizador *u, Grupo *g, Data d);
	bool bloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);
	bool desbloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);
	bool removerMembro(Utilizador *u, Grupo *g, Data diaAtual);

	void imprimirGruposAmigos() const;
	Grupo *escolheGruposAmigos(int i) const;
};

#endif /* SRC_UTILIZADOR_H_ */
