/** @ \file Utilizador.h
 * header file que contém a classe Utilizador
 */
#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include "System.h"
#include "Conversa.h"
#include "Grupo.h"

#include <iostream>
#include <string>
#include <vector>


class Utilizador
{
private:
	bool visibilidade; //publica = true , privado = false
	string login, nome, email;
	vector<int> telemoveis;
	Data dataAdesao;
	int idade;
	vector<Utilizador *> amigos;
	vector<Conversa *> conversas;
	vector<Grupo *> grupos;

	//vector<Utilizador *> pedidosAmizade;
public:
	Utilizador();
	Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao, int telemovel, int idade);

	//GETS

	string getNome() const;
	string getEmail() const;
	string getLogin() const;
	bool getVisibilidade() const;
	Data getDataAdesao() const;
	vector<Utilizador *> getAmigos() const;
	vector<Utilizador *> getPedidosAmizade() const;

	//SETS

	void setLogin(string l);
	void setNome(string n);
	void setEmail(string);
	void setVisibilidade(bool v);
	//void setAmigos(Utilizador &u);

	//void addConversa(Conversa &c);
	void addUtilizador(vector<Utilizador *> v, Utilizador &u);
	void addTelemovel(int t);
	//void aceitarAmizade(Utilizador &u); //de pedidos de amizade
	//bool enviarMsg(Mensagem &m,Utilizador &u,string tipo);

	void removerUtilizador(vector<Utilizador *> v, Utilizador &u);
	void removerTelemovel(int t);
	void removerAmigo(Utilizador &u);
	//void removerConversa(Conversa &c);


	//IMPRESS STATUS

	void imprimirDefinicoes() const;

	//OVERLOADING DE OPERADORES

	bool operator==(const Utilizador&u)const;
	bool operator<(const Utilizador &u) const;
	friend ostream & operator<<(ostream & out, const Utilizador & u);

	void criarConversa(Conversa *c);
	bool enviarMensagemUtilizador(Mensagem sms, Utilizador *u);
	bool enviarMensagemGrupo(Mensagem sms, Grupo *g);

};

/*******************************************************
 * 				   	CLASSES EXCECÇÃO		     	   *
 *****************************************************/

class UtilizadorJaExiste {
private:
	Utilizador u;
	string login;
public:
	UtilizadorJaExiste(Utilizador u){ this->u = u; };
	UtilizadorJaExiste(string login){ this->login = login; };
	string getLogin() const { return u.getNome(); };
};

class UtilizadorInexistente {
private:
	Utilizador u;
public:
	UtilizadorInexistente(Utilizador u){ this->u = u; };
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

#endif /* SRC_UTILIZADOR_H_ */
