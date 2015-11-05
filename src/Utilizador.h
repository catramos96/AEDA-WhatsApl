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
	vector<Utilizador *> amigos;
	vector<Conversa *> conversas; //quer com apenas 1 utilizador quer com grupos
	vector<Grupo *> grupos;
public:
	Utilizador();
  ~Utilizador();
	Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao, int telemovel, int idade);

	string getNome() const;
	string getEmail() const;
	string getLogin() const;
	bool getVisibilidade() const;
	Data getDataAdesao() const;
	vector<Utilizador *> getAmigos() const;
	vector<Utilizador *> getPedidosAmizade() const;

	void setGrupo(Grupo grupo);
	void setLogin(string l);
	void setNome(string n);
	void setEmail(string);
	void setIdade(int i);
	void setVisibilidade(bool v);
	void setAmigos(Utilizador *u);
	void setTelemovel(int i);

	void addAmigo(Utilizador &u);
	void deletAmigo(Utilizador *u); //elimina dos amigos
	void removerAmigo(Utilizador &u); //remove me dos amigos de u e u dos meus amigos

	void imprimirDefinicoes() const;
	void imprimirUtilizador() const;
	void imprimirAmigos() const;

	bool operator==(const Utilizador&u)const;
	bool operator<(const Utilizador &u) const;
	friend ostream & operator<<(ostream & out, const Utilizador & u);

	Conversa *criarConversa(Utilizador *u);
	void adicionarConversa(Conversa *c);
	void enviarMensagem(Mensagem *sms, Conversa *c);

	void pedirAdesao(Grupo *g);
	Grupo *criarGrupo(string titulo, Data dataAtual);
	void enviarMensagemGrupo(Mensagem *sms, Grupo *g);
	bool aceitaMembro(string u, Grupo *g, Data d);
	bool rejeitaMembro(string u, Grupo *g, Data d);
	bool bloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);
	bool desbloquearMembro(Utilizador *u, Grupo *g, Data diaAtual);
	bool removerMembro(Utilizador *u, Grupo *g, Data diaAtual);
};

#endif /* SRC_UTILIZADOR_H_ */
