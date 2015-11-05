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
	bool visibilidade; //publica = true , privado = false
	string login, nome, email;
  int telemovel;
	Data dataAdesao;
	int idade;
	//vector<Utilizador *> amigos;
	vector<Conversa *> conversas; //quer com apenas 1 utilizador quer com grupos
	vector<Grupo *> grupos;
public:
	Utilizador();
  ~Utilizador();
	Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao, int telemovel, int idade);

	//GETS

	string getNome() const;
	string getEmail() const;
	string getLogin() const;
	bool getVisibilidade() const;
	Data getDataAdesao() const;
	//vector<Utilizador *> getAmigos() const;
	//vector<Utilizador *> getPedidosAmizade() const;

	//SETS
	void setGrupo(const Grupo grupo);
	void setLogin(string l);
	void setNome(string n);
	void setEmail(string);
	void setIdade(int i);
	void setVisibilidade(bool v);
<<<<<<< HEAD
	//void setAmigos(Utilizador *u);
	//void addAmigo(Utilizador &u);
	void addTelemovel(int t);

	//void deletAmigo(Utilizador *u); //elimina dos amigos
	void removerTelemovel(int t);
	//void removerAmigo(Utilizador &u); //remove me dos amigos de u e u dos meus amigos
=======
	void setAmigos(Utilizador *u);
  void setTelemovel(int i);


	//void addConversa(Conversa &c);
	//void addUtilizador(vector<Utilizador *> v, Utilizador u);
	void addAmigo(Utilizador &u);
	//void aceitarAmizade(Utilizador &u); //de pedidos de amizade
	//bool enviarMsg(Mensagem &m,Utilizador &u,string tipo);

	void deletAmigo(Utilizador *u); //elimina dos amigos
	void removerAmigo(Utilizador &u); //remove me dos amigos de u e u dos meus amigos
>>>>>>> 8e2b1313dc929ae35ef2cba3a1fecebf8bb83186
	//void removerConversa(Conversa &c);

	//IMPRESS STATUS

	void imprimirDefinicoes() const;
	void imprimirUtilizador() const;
	//void imprimirAmigos() const;

	//OVERLOADING DE OPERADORES

	bool operator==(const Utilizador&u)const;
	bool operator<(const Utilizador &u) const;
	friend ostream & operator<<(ostream & out, const Utilizador & u);

	Conversa *criarConversa(Utilizador *u);
	void adicionarConversa(Conversa *c);
	void enviarMensagem(Mensagem *sms, Conversa *c);
	Grupo *criarGrupo(string titulo, Data dataAtual);
	void enviarMensagemGrupo(Mensagem *sms, Grupo *g);
	bool aceitaMembro(string u, Grupo *g, Data d);
	bool rejeitaMembro(string u, Grupo *g, Data d);
	bool bloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);
	bool desbloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);
	bool removerMembro(Utilizador *u, Grupo *g, Data diaAtual);
	void pedirAdesao(Grupo *g);
};

//================================================================================================//

class UtilizadorJaExiste {
private:
	Utilizador u;
	string login;
public:
	UtilizadorJaExiste(Utilizador u){ this->u = u; login = u.getLogin(); };
	UtilizadorJaExiste(string login){ this->login = login; };
	string getLogin() const { return login; };
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

class AmigoJaExiste {
public:
	AmigoJaExiste(Utilizador u) { util = u; };
private:
	Utilizador util;
};

#endif /* SRC_UTILIZADOR_H_ */
