#ifndef SRC_GRUPO_H_
#define SRC_GRUPO_H_

#include <iostream>
#include <string>
#include <vector>
#include "Conversa.h"


/**
 * @brief Classe Membro.
 * Classe que define os parametros necessarios para um utilizador estar num grupo.
 * Associa o login de um utilizador a data de adesao no grupo e a um boleano que indica se esta bloqueado.
 */
class Membro{
private:
	string login;  /**<  membro privado que representa o login do utilizador */
	Data adesaoGrupo;  /**<  membro privado que representa a data de adesao ao grupo*/
	bool bloqueado;  /**<  membro privado que indica se o utilizador está ou não bloqueado do grupo */
public:
	/**
	 * @brief Construtor default.
	 */
	Membro();
	/**
	 * @brief construtor Membro.
	 * Inicializa o Utilizador util com o utilizador dado, a Data adesaoGrupo com a data dada, e o boleano bloqueado a 'false'.
	 * @param login Login do utilizador.
	 * @param adesaoGrupo data em que aderiu ao grupo.
	 */
	Membro(string login, Data adesaoGrupo);
	/**
	 * @brief Funcao que retorna o login do Utilizador util.
	 * @return util.
	 */
	string getLogin() const;
	/**
	 * @brief Funcao que retorna a Data de adesao do utilizador ao grupo.
	 * @return AdesaoGrupo.
	 */
	Data getData() const;
	/**
	 * @brief Funcao que permite alterar a data inicial.
	 * @param d Nova data.
	 */
	void setData(Data d);
	/**
	 * @brief Funcao que coloca um novo valor ao membro privado 'bloqueado'.
	 * @param bloq Boleano com o valor true ou false.
	 */
	void setBloqueio(bool bloq);
	/**
	 * @brief Funcao que indica o estado atual do membro privado 'bloqueado'.
	 * @return bloqueado.
	 */
	bool isBloqueado() const;
	/**
	 * @brief Operador de igualdade.
	 * Compara 2 membros através do utilizador.
	 * @return true se os utilizadores forem iguais, false se forem diferentes.
	 */
	bool operator==(const Membro &m) const;
	/**
	 * @brief Operador de extracao.
	 * Faz o output dos membros privados da classe.
	 * @return out
	 */
	friend ostream & operator<<(ostream & out, const Membro & m);
};

//============================================================================================================================//

/**
 * @brief Classe Grupo.
 * Classe que forma um grupo. Um grupo pode ter varios membros, mas apenas um moderador.
 * O moderador e o utilizador que gere o grupo: permite aceitar pedidos de adesao ao grupo, retirar, bloquear ou desbloquear elementos,
 * Um grupo tem um titulo e uma data de criacao. O utilizador moderador e o utilizador que cria o grupo, logo contem a mesma data de adesao que a data de criacao do grupo.
 * Um grupo contem uma unica conversa que contem todos os utilizadores. No entanto podem estar bloqueados, pelo que nao podem enviar mensagens.
 */
class Grupo {
private:
	Conversa conversa;	/**< membro privado que contem a conversa do grupo */
	string titulo;  /**<  membro privado que indica o titulo do grupo */
	vector <Membro> membros;  /**<  membro privado que guarda os membros que pertencem ao grupo */
	Data criacao;  /**<  membro privado que representa a data de criacao do grupo */
	Membro moderador;  /**<  membro privado que representa o utilizador moderador do grupo */
	vector<string> status;  /**<  membro privado que guarda todas as notificacoes acerca do grupo.
									 Regista a entrada, saida, bloqueio ou desbloqueio de um membro com a respetiva data da ocorrencia*/
	vector<string> pedidos; /**< membro privado que indica os pedidos de adesao ao grupo */
public:
	/**
	 * @brief Construtor do grupo.
	 * Inicializa o titulo com o titulo recebido e a data com a data de criacao.
	 * Cria o membro moderador com o parametro moderador, a data de criacao do grupo e coloca-o no vetor de membros.
	 * Inicializa o membro status com as informacoes iniciais sobre o grupo.
	 * @param titulo Titulo do grupo.
	 * @param criacao Data de criacao do grupo.
	 * @param moderador Utilizador moderador do grupo.
	 */
	Grupo(string titulo, Data criacao, string moderador);
	/**
	 * @brief Funcao que retorna o numero de elementos do grupo.
	 * @return Numero de elementos membro.
	 */
	int numMembros() const;
	/**
	 * @brief Funcao que indica se um utilizador e ou nao o mderador do grupo.
	 * @return True se o utilizador e moderador ou false se nao.
	 */
	bool isModerador(string m);
	/**
	 * @brief Funcao que procura um membro no vetor 'membros' através do metodo de pesquisa sequential search definido na header Templates.h.
	 * @param m Membro que queremos encontrar.
	 * @return posicao no vetor do membro. -1 se nao encontra.
	 */
	int existeMembro(Membro m);
	/**
	 * @brief Funcao que devolve o membro indicado na posicao 'pos'.
	 * @param pos Posicao do elemento no vetor 'membros'.
	 * @return Membro na posicao pos.
	 */
	Membro membroNaPosicao(int pos);
	/**
	 * @brief Funcao que imprime o membro privado Status.
	 */
	void printStatus() const;
	/**
	 * @brief Funcao que imprime os membros existentes no vetor 'membros'.
	 */
	void printMembros() const;
	/**
	 * @brief Funcao que aceita um novo membro no grupo.
	 * Um utilizador que pede permissao pode ser novo ou pode apenas estar bloqueado.
	 * O surgimento de um novo membro e registado no membro-dado 'status'.
	 * Gera excecoes quando o utilizador moderador nao e o moderador do grupo ou quando o utilizador nao existe.
	 * @param novo Login do Utilizador que pede permissao.
	 * @param moderador Login do Utilizador moderador (apenas ele pode aceitar ou rejeitar pedidos de adesao).
	 * @param adesao Data em que o utilizador pede permissao para entrar no grupo.
	 * @param aceita Boleano com a indicacao se o moderador aceitou ou nao o pedido de adesao.
	 * @return True se aceita o pedido, false se rejeita.
	 */
	bool pedidoAdesao(string novo, string moderador, Data adesao, bool aceita);
	/**
	 * @brief Funcao que elimina um membro do gupo.
	 * A eliminacao e registada no membro-dado 'status'.
	 * Gera excecoes quando o utilizador moderador nao e o moderador do grupo ou quando o utilizador nao existe.
	 * @param login Login do Utilizador que vai ser eliminado.
	 * @param moderador Login do Utilizador moderador (apenas ele pode eliminar membros).
	 * @param diaAtual Data em que o utilizador e eliminado do grupo.
	 * @return True se e eliminado com sucesso.
	 */
	bool retiraMembro(string login, string moderador, Data diaAtual);
	/**
	 * @brief Funcao que bloqueia um membro.
	 * Um membro bloqueado nao pode enviar mensagens dentro do grupo, no entanto continua a pertencer ao grupo e a ver mensagens enviadas entre outros utilizadores.
	 * O bloqueio e registado no membro-dado 'status'.
	 * Gera excecoes quando o utilizador moderador nao e o moderador do grupo ou quando o utilizador nao existe.
	 * @param login Login do Utilizador que vai ser bloqueado.
	 * @param moderador Utilizador moderador (apenas ele pode bloquear membros).
	 * @param diaAtual Data em que o utilizador e bloqueado.
	 * @return True se o membro e bloqueado com sucesso e false se o membro ja se encontra bloqueado.
	 */
	bool bloquearMembro(string login, string moderador, Data diaAtual);
	/**
	 * @brief Funcao que desbloqueia um membro.
	 * Esta funcao, ao contrario da funcao pedidoAdesao, nao implica que o utilizador peca para ser desbloqueado.
	 * O desbloqueio e registado no membro-dado 'status'.
	 * Gera excecoes quando o utilizador moderador nao e o moderador do grupo ou quando o utilizador nao existe.
	 * @param login Login do Utilizador que vai ser desbloqueado.
	 * @param moderador Utilizador moderador (apenas ele pode desbloquear membros).
	 * @param diaAtual Data em que o utilizador e desbloqueado.
	 * @return True se o membro e desbloqueado com sucesso e false se o membro ja se encontra desbloqueado.
	 */
	bool desbloquearMembro(string login, string moderador, Data diaAtual);
	/**
	 * @brief Funcao que envia uma mensagem para a conversa de grupo.
	 * Gera excecoes se o utilizador que quer enviar a mensagem esta bloqueado ou se nao existe.
	 * @param emissor Login do utilizador que envia a mensagem.
	 * @param *sms Mensagem que vai ser enviada,
	 * @return True em caso de sucesso ou false se insucesso.
	 */
	bool enviarMensagem(string emissor, Mensagem *sms);
	/**
	 * @brief Funcao que permite fazer o overloading do operador == de modo a conseguir igualar 2 objetos do tipo Grupo.
	 * O criterio de igualdade sao os participantes.
	 * @param g Grupo que vamos comparar.
	 * @return True se forem iguais, false se diferentes.
	 */
	bool operator==(const Grupo&g)const;
	/**
	 * @brief Funcao que imprime o membro privado pedidos.
	 */
	void printPedidos() const;
	/**
	 * @brief Funcao que retorna o numero de pedidos de adesao ao grupo
	 * @return numero de pedidos
	 */
	int numPedidos() const;
	/**
	 * @brief Funcao que adiciona o pedido de adesao de um utilizador ao membro privado 'pedidos'.
	 * @param login Login do utilizador que quer pertencer ao grupo.
	 */
	void adicionarPedido(string login);
	/**
	 * @brief Funcao que imprime a conversa que pertence ao grupo.
	 */
	void printConversa();
  /**
  * @brief Funcao que imprime o titulo do grupo, o gerente e a data de criação
  */
  void printGrupo() const;
  /**
  * @brief Funcao que retorna o titulo do grupo
  */
  string getTitulo() const { return titulo; };
};

#endif /* SRC_GRUPO_H_ */
