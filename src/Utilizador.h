/** @ \file Utilizador.h
 * header file que contém a classe Utilizador
 */
#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_

#include "System.h"
#include "Utilizador.h"
#include "Conversa.h"
#include <iostream>
#include <string>
#include <vector>
#include "Templates.h"


class Utilizador
{
private:
	bool visibilidade; //publica = true , privado = false
	string login,nome,email;
	vector<int> telemoveis;
	Data dataAdesao;
	vector<Utilizador *> amigos;
	vector<Utilizador *> bloqueados;
	vector<Utilizador *> bloquearamMe;
	vector<Utilizador *> pedidosAmizade;
	vector<Utilizador *> comunidade;
	//vector<Conversa *> conversas;
	vector<string> notificacoes;
public:
	Utilizador();
	Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao, int telemovel);
	string getNome() const;
<<<<<<< HEAD
	string getLogin() const;
	//bool addConversa(Conversa &c);
	//bool enviarSms(Mensagem &m);
=======

	//GETS

	string getEmail() const;
	string getLogin() const;
	bool getVisibilidade() const;
	vector<int> getTelemoveis() const;
	Data getDataAdesao() const;
	vector<Utilizador *> getAmigos() const;
	vector<Utilizador *> getBloqueados() const;
	vector<Utilizador *> getBloquearamMe() const;
	vector<Utilizador *> getPedidosAmizade() const;
	//vector<Conversa *> getConversas() const;
	vector<string> getNotificacoes() const;

	//SETS

	bool setLogin (string l,vector<Utilizador*> comunidade); //vector com os nomes da comunidade
	void setNome (string n);
	void setEmail(string );
	void setVisibilidade(bool v);
	void setAmigos(Utilizador &u);
	void setBloquearamMe(Utilizador &u);

	void addUtilizador(vector<Utilizador *> v,Utilizador &u);
	void addTelemovel(int t);
	void aceitarAmizade(Utilizador &u); //de pedidos de amizade
	void bloquearUtilizador(Utilizador &u);

	void removerUtilizador(vector<Utilizador *> v,Utilizador &u);
	void removerTelemovel(int t);
	void removerAmigo(Utilizador &u);
	void desbloquearUtilizador(Utilizador &u);
	//void addConversa(Conversa &c);
	//void removerConversa(Conversa &c);
	//bool enviarMsg(Mensagem &m,Utilizador &u,string tipo);

	//IMPRESS STATUS

	void imprimirDefinicoes() const;
	void imprimirNotificacoes() const;
	void imprimirGrupo(vector<Utilizador *> v) const;
	void imprimirAmigos() const {imprimirGrupo(amigos);};
	void imprimirBloqueados() const {imprimirGrupo(bloqueados);};
	void imprimirBloquearamMe() const {imprimirGrupo(bloquearamMe);};
	void imprimirPedidosAmizade() const {imprimirGrupo(pedidosAmizade);};
	void imprimirComunidade() const {imprimirGrupo(comunidade);};

	//OVERLOADING DE OPERADORES

	bool operator==(const Utilizador&u)const;
>>>>>>> e2bf3dd4c4580ddda629b9d2243c44e21fa4b5ba
	friend ostream & operator<<(ostream & out, const Utilizador & u);

};

/*******************************************************
 * 				   	CLASSES EXCECÇÃO		     	   *
 ******************************************************/

class UtilizadorJaExiste {
private:
	Utilizador u;
	string login;
public:
	UtilizadorJaExiste(Utilizador u){this->u = u;};
	UtilizadorJaExiste(string login){this->login = login;};
	string getLogin() const {return u.getNome();};
};

class UtilizadorInexistente {
private:
	Utilizador u;
public:
	UtilizadorInexistente(Utilizador u){this->u = u;};
	string getLogin() const {return u.getNome();};
};

class TelemovelJaExiste {
private:
	int t;
public:
	TelemovelJaExiste(int t) {this->t = t;};
	int getTelemovel() const {return t;};
};

class TelemovelInexistente {
private:
	int t;
public:
	TelemovelInexistente(int t) {this->t = t;};
	int getTelemovel() const {return t;};
};

#endif /* SRC_UTILIZADOR_H_ */
