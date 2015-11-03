#ifndef SRC_PRINCIPAL_H_
#define SRC_PRINCIPAL_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Mensagem.h"

//==============================================================================//

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
	//vector<Utilizador *> getPedidosAmizade() const;

	//SETS

	void setLogin(string l);
	void setNome(string n);
	void setEmail(string);
	void setIdade(int i);
	void setVisibilidade(bool v);
	void setAmigos(Utilizador *u);
	//void addConversa(Conversa &c);
	//void addUtilizador(vector<Utilizador *> v, Utilizador u);
	void addAmigo(Utilizador &u);
	void addTelemovel(int t);
	//void aceitarAmizade(Utilizador &u); //de pedidos de amizade
	//bool enviarMsg(Mensagem &m,Utilizador &u,string tipo);

	void deletAmigo(Utilizador *u); //elimina dos amigos
	void removerTelemovel(int t);
	void removerAmigo(Utilizador &u); //remove me dos amigos de u e u dos meus amigos

	//void removerConversa(Conversa &c);


	//IMPRESS STATUS

	void imprimirDefinicoes() const;
	void imprimirUtilizador() const;
	void imprimirAmigos() const;

	//OVERLOADING DE OPERADORES

	bool operator==(const Utilizador&u)const;
	bool operator<(const Utilizador &u) const;
	friend ostream & operator<<(ostream & out, const Utilizador & u);

	void criarConversa(Conversa *c);
	bool enviarMensagemUtilizador(Mensagem sms, Utilizador *u);
	bool enviarMensagemGrupo(Mensagem sms, Grupo *g);

};

//==============================================================================//

/**
 * @brief Classe Membro.
 * Classe que define os parametros necessarios para um utilizador estar num grupo.
 * Associa um utilizador a data de adesao no grupo e a um boleano que indica se o esta bloqueado.
 */
class Membro{
private:
	Utilizador util;  /**<  membro privado que representa o utilizador */
	Data adesaoGrupo;  /**<  membro privado que representa a data de adesao ao grupo*/
	bool bloqueado;  /**<  membro privado que indica se o utilizador está ou não bloqueado do grupo */
public:
	/**
	 * @brief construtor Membro
	 * inicializa o Utilizador util com o utilizador dado, a Data adesaoGrupo com a data dada, e o boleano bloqueado a 'false'
	 * @param util Utilizador
	 * @param adesaoGrupo data em que aderiu ao grupo
	 */
	Membro(Utilizador util, Data adesaoGrupo);
	/**
	 * @brief Funcao que retorna o Utilizador util
	 * @return util
	 */
	Utilizador getUtilizador() const;
	/**
	 * @brief Funcao que retorna a Data de adesao do utilizador ao grupo
	 * @return adesaoGrupo
	 */
	Data getData() const;
	/**
	 * @brief Funcao que permite alterar a data inicial
	 * @param d nova data
	 */
	void setData(Data d);
	/**
	 * @brief Funcao que coloca um novo valor ao membro privado 'bloqueado'
	 * @param bloq boleano com o valor true ou false
	 */
	void setBloqueio(bool bloq);
	/**
	 * @brief Funcao que indica o estado atual do membro privado 'bloqueado'
	 * @return bloqueado
	 */
	bool isBloqueado() const;
	/**
	 * @brief operador de igualdade
	 * compara 2 membros através do utilizador
	 * @return true se os utilizadores forem iguais, false se forem diferentes
	 */
	bool operator==(const Membro &m) const;
	/**
	 * @brief operador de extracao
	 * faz o output dos membros privados da classe
	 * @return out
	 */
	friend ostream & operator<<(ostream & out, const Membro & m);
};

//==============================================================================//

/**
 * @brief Classe Grupo
 * classe que forma um grupo. Um grupo pode ter varios membros, mas apenas um moderador.
 * O moderador e o utilizador que gere o grupo: permite aceitar pedidos de adesao ao grupo, retirar, bloquear ou desbloquear elementos,
 * Um grupo tem um titulo e uma data de criacao. o utilizador moderador e o utilizador que cria o grupo, logo contem a mesma data de adesao que a data de criacao do grupo.
 */
class Grupo {
private:
	Conversa conversa;
	string titulo;  /**<  membro privado que indica o titulo do grupo */
	vector <Membro *> membros;  /**<  membro privado que guarda os membros que pertencem ao grupo */
	Data criacao;  /**<  membro privado que representa a data de criacao do grupo */
	Utilizador moderador;  /**<  membro privado que representa o utilizador moderador do grupo */
	vector<string> status;  /**<  membro privado que guarda todas as notificacoes acerca do grupo.
									 Regista a entrada, saida, bloqueio ou desbloqueio de um membro com a respetiva data da ocorrencia*/
public:
	/**
	 * @brief Construtor do grupo
	 * Inicializa o titulo com o titulo recebido e a data com a data de criacao.
	 * Cria o membro moderador com o parametro moderador, a data de criacao do grupo e coloca-o no vetor de membros.
	 * Inicializa o membro status com as informacoes iniciais sobre o grupo
	 * @param titulo Titulo do grupo
	 * @param criacao Data de criacao do grupo
	 * @param moderador Utilizador moderador do grupo
	 */
	Grupo(string titulo, Data criacao, Utilizador moderador);
	/**
	 * @brief Funcao que retorna o numero de elementos do grupo
	 * @return Numero de elementos membro
	 */
	int numMembros() const;
	/**
	 * @brief Funcao que indica se um utilizador e ou nao o mderador do grupo
	 * @return True se o utilizador e moderador ou false se nao e.
	 */
	bool isModerador(Utilizador u);
	/**
	 * @brief Funcao que procura um membro no vetor 'membros' através do metodo de pesquisa sequential search definido na header Templates.h
	 * @param *m Membro que queremos encontrar
	 * @return posicao no vetor do membro. -1 se nao encontra.
	 */
	int existeMembro(Membro *m);
	/**
	 * @brief Funcao que devolve o membro indicado na posicao 'pos'
	 * @param pos Posicao do elemento no vetor 'membros'
	 * @return Membro na posicao pos
	 */
	Membro *membroNaPosicao(int pos);
	/**
	 * @brief Funcao que imprime o membro privado Status
	 */
	void printStatus() const;
	/**
	 * @brief Funcao que imprime os membros existentes no vetor 'membros'
	 */
	void printMembros() const;
	/**
	 * @brief Funcao que aceita um novo membro no grupo.
	 * Um utilizador que pede permissao pode ser novo ou pode apenas estar bloqueado.
	 * O surgimento de um novo membro e registado no membro-dado 'status'
	 * Gera excecoes quando o utilizador moderador nao e o moderador do grupo ou quando o utilizador nao existe.
	 * @param u Utilizador que pede permissao
	 * @param moderador Utilizador moderador (apenas ele pode aceitar ou rejeitar pedidos de adesao)
	 * @param adesao Data em que o utilizador pede permissao para entrar no grupo
	 * @param aceita Boleano com a indicacao se o moderador aceitou ou nao o pedido de adesao
	 * @return True se aceita o pedido, false se rejeita
	 */
	bool pedidoAdesao(Utilizador u, Utilizador moderador, Data adesao, bool aceita);
	/**
	 * @brief Funcao que elimina um membro do gupo.
	 * A eliminacao e registada no membro-dado 'status'
	 * Gera excecoes quando o utilizador moderador nao e o moderador do grupo ou quando o utilizador nao existe.
	 * @param u Utilizador que vai ser eliminado
	 * @param moderador Utilizador moderador (apenas ele pode eliminar membros)
	 * @param diaAtual Data em que o utilizador e eliminado do grupo
	 * @return True se e eliminado com sucesso
	 */
	bool retiraMembro(Utilizador u, Utilizador moderador, Data diaAtual);
	/**
	 * @brief Funcao que bloqueia um membro.
	 * Um membro bloqueado nao pode enviar mensagens dentro do grupo, no entanto continua a pertencer ao grupo e a ver mensagens enviadas entre outros utilizadores.
	 * O bloqueio e registado no membro-dado 'status'
	 * Gera excecoes quando o utilizador moderador nao e o moderador do grupo ou quando o utilizador nao existe.
	 * @param u Utilizador que vai ser bloqueado
	 * @param moderador Utilizador moderador (apenas ele pode bloquear membros)
	 * @param diaAtual Data em que o utilizador e bloqueado
	 * @return True se o membro e bloqueado com sucesso e false se o membro ja se encontra bloqueado
	 */
	bool bloquearMembro(Utilizador u, Utilizador moderador, Data diaAtual);
	/**
	 * @brief Funcao que desbloqueia um membro.
	 * Esta funcao, ao contrario da funcao pedidoAdesao, nao implica que o utilizador peca para ser desbloqueado
	 * O desbloqueio e registado no membro-dado 'status'
	 * Gera excecoes quando o utilizador moderador nao e o moderador do grupo ou quando o utilizador nao existe.
	 * @param u Utilizador que vai ser desbloqueado
	 * @param moderador Utilizador moderador (apenas ele pode desbloquear membros)
	 * @param diaAtual Data em que o utilizador e desbloqueado
	 * @return True se o membro e desbloqueado com sucesso e false se o membro ja se encontra desbloqueado
	 */
	bool desbloquearMembro(Utilizador u, Utilizador moderador, Data diaAtual);

	bool enviarMensagem(string emissor, Mensagem sms);
};

/**
 * @brief Classe que representa uma excecao da classe grupo.
 * esta excecao e lancada no caso de o utilizador que esta a pedir permissoes nao ser o utilizador moderador
 */
class NaoModerador{
private:
	Utilizador mod;  /**<  membro privado que representa o utilizador que cria a excecao */
public:
	/**
	 * @brief Construtor
	 * inicializa o membro mod com o utilizador recebido
	 * @param mod utilizador recebido
	 */
	NaoModerador(Utilizador mod){
		this->mod = mod;
	};
	/**
	 * @brief Funcao que retorna o utilizador
	 * @return mod
	 */
	Utilizador getUtil() const{
		return mod;
	};
};

//==============================================================================//

/* Classe Conversa*/

class Conversa
{
private:
	vector<Mensagem> mensagens;
	vector<Utilizador *> participantes;
public:
	Conversa();
	Conversa(vector<Utilizador *> part); //conversa vazia
	void adicionaSms(Mensagem sms);
	void adicionaParticipante(Utilizador *novo);
	void removeParticipante(Utilizador *p);
	void removeSms(Data data, Horas hora);
	void imprimirConversa();
	int numSms() const;
	int numParticipantes() const;
	vector<Utilizador *> getParticipantes() const;
	bool operator==(const Conversa&c)const;
};

//==============================================================================//

class UtilizadorJaExiste {
private:
	Utilizador u;
	string login;
public:
	UtilizadorJaExiste(Utilizador u){ this->u = u; login = u.getLogin(); };
	UtilizadorJaExiste(string login){ this->login = login; };
	string getLogin() const { return login; };
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

class AmigoJaExiste {
public:
	AmigoJaExiste(Utilizador u) { util = u; };
private:
	Utilizador util;
};


#endif /* SRC_PRINCIPAL_H_ */
