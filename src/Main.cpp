#include <iostream>
#include <windows.h>
#include "System.h"
#include "Utilizador.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Templates.h"
#include "Mensagem.h"
#include "Conversa.h"
#include "Excecoes.h"
#include <fstream>

using namespace std;

static Data dataHoje;

/**
 * @brief Funcao que cria uma interrupção no programa para o utilizador poder visualizar o ecra
 */
void esperar() {
	system("pause");
}
/**
 * @brief Funcao que verifica se op esta entre o min e o max
 * caso nao esteja lanca a excepcao OpccaoInvalida
 * @param op opccao escolhida
 * @param min opccao minima
 * @param max opccao maxima
 */
void opccao(int &op, int min, int max) {
	cout << "Seleccione uma opccao: ";
	cin >> op;
	if (op < min || op > max) {
		cin.clear();
		cin.ignore(1000, '\n');
		throw OpccaoInvalida<int>(op, min, max);
	}
}

/*****************************************************************
 *                          MENU UNICIAL                          *
 *****************************************************************/

/**
 * @brief Funcao que faz o login do utilizador.
 * Verifica se o login existe na comunidade e se nao existir lanca a excepcao UtilizadorInexistente.
 * @param c comunidade que contem todos os utilizadores inscritos.
 * @return Utilizador com que se fez o login.
 */
Utilizador * login(Comunidade *c) {
	string login;
	int i, op;
	Utilizador * u = new Utilizador();

	header("LOGIN");

	cout << "Login: ";
	cin >> login;
	u->setLogin(login);
	i = c->existeUtil(u);
	if (i != -1) {
		u = c->utilizadorNaPosicao(i);
		cout << i;
	} else
		throw UtilizadorInexistente(u->getLogin());
	return u;
}

/**
 * @brief Funcao que regista um utilizador na comunidade c.
 * Caso o utilizador com o login inserido exista, e lancada a excepcao UtilizadorJaExiste.
 * Caso o input de algum dos paramentros requeridos para o registo sejam do tipo errado lanca a excepcao InputFail.
 * @param c comunidade que contem todos os utilizadores inscritos.
 */
void registar(Comunidade *c) {
	bool vis;
	string login, nome, email;
	int telemovel;
	int idade, dia, mes, ano;
	Data dA;

	clrscr();

	header("REGISTAR");
	cout << "Login: ";
	input<string>(login);
	cout << "Nome: ";
	cin.ignore(1000, '\n');
	getline(cin, nome);
	cout << "Email: ";
	input<string>(email);
	cout << "Idade: ";
	input<int>(idade);
	cout << "Telemovel: ";
	input<int>(telemovel);
	cout << "Data (dia mes ano): ";
	cin >> dia >> mes >> ano;
	dA.setData(dia, mes, ano);
	cout << "Perfil publico/privado (1/0): ";
	input<bool>(vis);

	Utilizador * u = new Utilizador(vis, login, nome, email, dA, telemovel,
			idade);
	c->adicionarUtil(u);
}

/**
 * @brief Funcao em que visualizamos os utilizadores inscritos e podemos ordena-los por login ou data de adesao.
 * @param c comunidade que contem todos os utilizadores inscritos.
 */
void comunidade(Comunidade *c) {
	menuComunidade();
	int op;
	opccao(op, 1, 3);

	clrscr();

	switch (op) {
	case 1: {
		c->ordenaLogin();
		break;
	}
	case 2: {
		c->ordenaData();
		break;
	}
	case 3:
		throw VoltarAtras();
	}

	menuComunidadeOrdenada();
	c->printComunidade();

}

/**
 * @brief Funcao que analisa a opccao op.
 * @param c comunidade que contem todos os utilizadores inscritos.
 * @return Utilizador caso se tenha feito o login.
 */
Utilizador * opccaoMenuInicial(int op, Comunidade *c) {

	Utilizador *u = new Utilizador();
	clrscr();
	switch (op) {
	case 1: {
		u = login(c);
		break;
	}
	case 2: {
		registar(c);
		break;
	}
	case 3: {
		comunidade(c);
		cout << endl;
		esperar();
		break;
	}
	case 4: {
		menuInformacao();
		esperar();
		throw VoltarAtras();
	}
	case 5: {
		exit(1); //sair
	}
	}
	return u;
}

/**
 * @brief Funcao que mostra no ecra o menu inicial com varias opccoes
 * @return op opccao escolhida apartir do menu inicial
 */
int headerInicio() {
	clrscr();
	menuInicial();
	int op;
	opccao(op, 1, 5);
	return op;
}

/**
 * @brief Funcao da interface inicial quando se inicializa o programa.
 * Mostra as diferentes opccoes do menu inicial e gere a escolhida.
 * @param c comunidade que contem todos os utilizadores inscritos.
 * @return Utilizador com quem se fez o login
 */
Utilizador * MenuInicial(Comunidade *c) {
	bool login = false;
	//bool sair = false;
	int op;
	Utilizador* u = new Utilizador;
	do {
		try {
			op = headerInicio();
			u = opccaoMenuInicial(op, c);
			if (u->getNome() != "")
				login = true;
		} catch (OpccaoInvalida<int> (x)) {
			cout << x.getOp() << " nao se encontra entre as opccoes "
					<< x.getMin() << " e " << x.getMax() << endl << endl;
			esperar();
		} catch (UtilizadorInexistente (x)) {
			cout << "Nao existe um utilizador com o login " << x.getLogin()
					<< endl << endl;
			esperar();
		} catch (UtilizadorJaExiste (x)) {
			cout << "Ja existe um utilizador com o login " << x.getLogin()
					<< endl << endl;
			esperar();
		} catch (VoltarAtras) {
		} catch (IdadeInsuficiente (x)) {
			cout << "So e permitido usar a aplicacao com maiores de 18 anos"
					<< endl << endl;
			esperar();
		} catch (DataInvalida (x)) {
			cout << x.getDia() << "/" << x.getMes() << "/" << x.getAno()
					<< " e invalida!" << endl << endl;
			esperar();
		} catch (InputFail) {
			cout << "Input fail!" << endl << endl;
			esperar();
		}

	} while (!login); //Até não efectuar login

	return u;
}

/*****************************************************************
 *                         MENU UTILIZADOR                        *
 *****************************************************************/

/**
 * @brief Funcao que analisa e gere a opccao amigos do utilizador.
 * @param u utilizador que se esta a gerir.
 */
void amigosUtilizador(Utilizador *u, Comunidade *c) {
	//Menu Amigos
	menuAmigos();
	int op;
	opccao(op, 1, 4);

	string login;
	int i;

	clrscr();

	switch (op) {
	case 1: {
		//adicionar amigo

		header("AMIGOS");
		cout << "Login:";
		cin >> login;
		Utilizador * a = new Utilizador();
		a->setLogin(login);

		i = c->existeUtil(a); //Existe na comunidade ?
		if (i == -1)
			throw UtilizadorInexistente(a->getLogin());

		u->addAmigo(*c->utilizadorNaPosicao(i)); //Já é meu amigo? se sim adiciona
		cout << endl << login << " adicionado com sucesso" << endl << endl;
		esperar();
		break;
	}

		//Remover Amigo
	case 2: {
		header("REMOVER AMIGOS");
		cout << "Login:";
		cin >> login;
		Utilizador * a = new Utilizador();
		a->setLogin(login);
		i = c->existeUtil(a); //Existe na comunidade ?
		if (i == -1)
			throw UtilizadorInexistente(a->getLogin());

		u->removerAmigo(*c->utilizadorNaPosicao(i)); //É amigo ? se sim remove
		cout << endl << login << " removido com sucesso" << endl << endl;
		esperar();
		break;
	}
		//Ver amigos
	case 3: {
		header("AMIGOS");
		cout << "Nome  /  Login" << endl << endl;
		u->imprimirAmigos();
		cout << endl;
		cout << "Ver Perfil (1)" << endl;
		cout << "Voltar Atras (2)" << endl << endl;
		opccao(op, 1, 2);
		if (op == 1) {
			cout << endl << "Login: ";
			input<string>(login);

			clrscr();

			header(u->getAmigo(login)->getLogin());
			u->getAmigo(login)->imprimirUtilizador();
		} else
			throw VoltarAtras();
		esperar();
		break;
	}
	case 4:
		throw VoltarAtras();
	}
}

/**
 * @brief Funcao que escreve uma mensagem
 */
Mensagem * escreverMsg() {
	int h, m, tipo;
	cout << "Hora (horas minutos): ";
	cin >> h >> m;
	Horas hora(h, m);
	cout << "\nTipo:" << endl << "Texto (1)" << endl << "Imagem (2)" << endl
			<< "Video (3)" << endl << endl;
	opccao(tipo, 1, 3);
	Mensagem *msg = new Mensagem(dataHoje, hora);

	switch (tipo) {
	case 1: // de texto ... 
	{
		string cont;
		cout << "Conteudo: ";
		cin.ignore(1000, '\n');
		getline(cin, cont);
		msg = new MsgTexto(cont, dataHoje, hora);
		break;
	}
	case 2: // de imagem ...
	{
		msg = new MsgImagem(dataHoje, hora);
		break;
	}
	case 3: // de video ...
	{
		msg = new MsgVideo(dataHoje, hora);
		break;
	}
	}
	return msg;
}

/**
 * @brief Funcao que analisa e gere os grupos do utilizador.
 * @param u utilizador que se esta a gerir.
 */
void gerirGrupos(Utilizador *u, int i) {
	string login;
	int op;

	Grupo *temp = u->getGrupo(i - 1); //grupo com que vamos trabalhar
	Utilizador *amigo; //membro que eventualmente vamos utilizar

	clrscr();

	header("GERIR - " + temp->getTitulo());
	menuGerirGrupos();
	opccao(op, 1, 6);

	clrscr();

	header("GERIR - " + temp->getTitulo());

	switch (op) {
	case 1: //Adicionar -> adiciona um amigo mesmo que este não tenha feito um pedido de adesao
	{
		u->imprimirAmigos();
		cout << endl;
		cout << "Adicionar login: ";
		input<string>(login);
		amigo = u->getAmigo(login);
		u->adicionaMembro(amigo, temp, dataHoje);
		cout << "\nAdicionado com sucesso!" << endl << endl;
		esperar();
		throw VoltarAtras();
		break;
	}
	case 2: //Remover um membro de um grupo
	{
		temp->printMembros();
		cout << endl;
		cout << "Remover login: ";
		input<string>(login);
		amigo = u->getAmigo(login);
		u->removerMembro(amigo, temp, dataHoje);
		cout << "\nRemovido com sucesso!" << endl << endl;
		esperar();
		throw VoltarAtras();
		break;
	}
	case 3: //bloquear um membro do grupo
	{
		temp->printMembros();
		cout << endl;
		cout << "Bloquear login: ";
		input<string>(login);
		amigo = u->getAmigo(login);
		u->bloquearMembro(amigo, temp, dataHoje);
		cout << "\nBloqueado com sucesso!" << endl << endl;
		esperar();
		throw VoltarAtras();
		break;
	}
	case 4: //desbloquear um membro por iniciativa do moderador
	{
		temp->printStatus();
		cout << endl;
		cout << "Desbloquear login: ";
		input<string>(login);
		amigo = u->getAmigo(login);
		u->desbloquearMembro(amigo, temp, dataHoje);
		cout << "\nDesbloqueado com sucesso!" << endl << endl;
		esperar();
		throw VoltarAtras();
		break;
	}
	case 5: //Ver pedidos de adesao ao grupo atual
	{
		//int n;
		cout << "Pedidos de adesao:" << endl;
		temp->printPedidos();
		cout << endl;
		cout << "Aceitar (1)" << endl;
		cout << "Recusar (2)" << endl;
		cout << "Voltar Atras (3)" << endl << endl;
		opccao(op, 1, 3);

		switch (op) {
		case 1: // aceitar pedido de adesao
		{
			cout << endl << "Aceitar login: ";
			input<string>(login);
			amigo = u->getAmigo(login);
			u->aceitaMembro(amigo, temp, dataHoje);
			break;
		}
		case 2: // recusar pedido de adesao
		{
			cout << endl << "Aceitar login: ";
			input<string>(login);
			amigo = u->getAmigo(login);
			u->rejeitaMembro(amigo, temp, dataHoje);
			break;
		}
		case 3: //voltar atras
			throw VoltarAtras();
		}
	}
	case 6:
		throw VoltarAtras();
	}
}

/**
 * @brief Funcao que analisa e gere a opccao mensagens->grupos do utilizador.
 * @param u utilizador que se esta a gerir.
 */
void gruposUtilizador(Utilizador *u) {
	int op;

	clrscr();

	menuGrupos();
	opccao(op, 1, 5);

	clrscr();

	switch (op) {
	case 1: //CRIAR GRUPO
	{
		header("CRIAR NOVO GRUPO");
		string t;
		cout << "Titulo do grupo: ";
		cin.ignore(1000, '\n');
		getline(cin, t);
		u->criarGrupo(t, dataHoje);
		cout << "\nGrupo criado com sucesso!" << endl << endl;
		break;
	}
	case 2: {
		int i;

		header("ENVIAR MENSAGEM");
		u->imprimirGrupos();
		cout << endl;
		cout << "Enviar mensagem para o grupo numero: ";
		input<int>(i);

		cout << endl;

		//a enviar msg
		u->enviarMensagemGrupo(escreverMsg(), u->getGrupo(i - 1));
		clrscr();

		//imprime as conversas desse grupo
		header("Grupo - " + u->getGrupo(i - 1)->getTitulo());
		u->getGrupo(i - 1)->printConversa();

		esperar();
		throw VoltarAtras();
	}
	case 3: //VER GRUPOS EM QUE PARTICIPO
	{
		header("GRUPOS");
		u->imprimirGrupos();
		cout << endl;
		cout << "Ver Status (1)" << endl;
		cout << "Ver Conversa de Grupo (2)" << endl;
		cout << "Gerir Grupo (3)" << endl;
		cout << "Sair de um Grupo (4)" << endl;
		cout << "Voltar Atras (5)" << endl << endl;
		int op;
		opccao(op, 1, 5);
		if (op != 5) {
			int n;
			cout << "\nGrupo numero: ";
			input<int>(n);
			Grupo *temp = u->getGrupo(n - 1);
			clrscr();

			header("Grupo - " + temp->getTitulo());
			switch (op) {
			case 1: //Ver status
			{
				temp->printStatus();
				break;
			}
			case 2: //Ver conversas
			{
				temp->printConversa();
				break;
			}
			case 3: //Gerir grupo
			{
				gerirGrupos(u, n);
				break;
			}
			case 4: //Sair de um grupo
			{
				string login;
				Grupo *temp = u->getGrupo(n - 1); //grupo com que vamos trabalhar

				if (temp->numMembros() != 1) {
					if (temp->isModerador(u->getLogin())) { //se u for moderador precisa de escolher o proximo moderador
						temp->printMembros();
						cout << "\nLogin do proximo moderador: ";
						input<string>(login);
						Membro m(login, dataHoje);
						if (temp->existeMembro(m) != -1) {
							temp->setModerador(login, dataHoje);
							u->removerMembro(u, temp, dataHoje);
						} else
							throw MembroInexistente(m.getLogin());
					} else
						u->removerMembro(u, temp, dataHoje);
				}else
					u->sairGrupo(temp);
				cout << "Removido com sucesso! \n";
			}
			}
		} else
			throw VoltarAtras();
		break;
	}
	case 4: //enviar um pedido de adesao a um grupo
	{
		int n;
		header("GRUPOS DO CIRCULO DE AMIGOS");
		if (u->getAmigos().size() != 0) {
			u->imprimirGruposAmigos();
			cout << endl << "Enviar pedido ao grupo numero : ";
			input<int>(n);
			u->pedirAdesao(u->escolheGruposAmigos(n));
			cout << "\nPedido efetuado com sucesso!" << endl << endl;
		} else
			cout << "Nao existem grupos para aderir" << endl << endl;
		esperar();
		throw VoltarAtras();
	}
	case 5: //Voltar Atras
	{
		throw VoltarAtras();
	}
	}
	esperar();
}

/**
 * @brief Funcao que analisa e gere a opccao mensagens->conversas do utilizador.
 * @param u utilizador que se esta a gerir.
 */
void conversasUtilizador(Utilizador *u) {
	int op;
	int i;
	clrscr();

	menuConversas();
	opccao(op, 1, 4);

	clrscr();

	switch (op) {
	case 1: //CRIAR
	{
		string login;
		header("CRIAR CONVERSA");
		cout << "Amigos:" << endl << endl;
		u->imprimirAmigos();
		cout << endl;
		cout << "Login do destinatario: ";
		input<string>(login);
		u->criarConversa(u->getAmigo(login));
		break;
	}
	case 2: //ENVIAR
	{
		header("ENVIAR MENSAGEM");
		u->imprimirConversas();
		cout << endl;
		cout << "Enviar para conversa numero: ";
		input<int>(i);

		cout << endl;

		//a enviar msg
		u->enviarMensagem(escreverMsg(), u->getConversa(i - 1));
		clrscr();

		//imprime as conversas desse grupo
		header(
				"Conversa - "
						+ u->getDestinatarioConversa(u->getConversa(i - 1)));
		u->getConversa(i - 1)->imprimirConversa();

		esperar();
		throw VoltarAtras();
	}
	case 3: //ver conversas
	{
		header("CONVERSAS");
		u->imprimirConversas();
		cout << endl;
		cout << "Ver Conversa (1)" << endl;
		cout << "Sair de Conversa (2)" << endl;
		cout << "Voltar Atras (3)" << endl << endl;
		opccao(op, 1, 3);

		if (op != 3) {
			cout << "Conversa numero: ";
			input<int>(i);

			if (op == 1) { //ver conversa x
				clrscr();
				header(
						"Conversa - "
								+ u->getDestinatarioConversa(
										u->getConversa(i - 1)));
				u->getConversa(i - 1)->imprimirConversa();
				cout << endl;
			} else { //apagar conversa x
				u->sairConversa(u->getConversa(i - 1));
				cout << "\nSaida da conversa com sucesso!" << endl << endl;
			}
			esperar();
			throw VoltarAtras();
		} else
			throw VoltarAtras();
	}
		throw VoltarAtras();
	}
}

/**
 * @brief Funcao que gere a opccao mensagens do utilizador.
 * @param c comunidade que contem todos os utilizadores inscritos.
 * @param u utilizador que se esta a gerir.
 */
void mensagensUtilizador(Utilizador *u, Comunidade *c) {
	menuMensagens();
	int op;
	opccao(op, 1, 3);

	switch (op) {
	case 1: {
		gruposUtilizador(u);
		break;
	}
	case 2: {
		conversasUtilizador(u);
		break;
	}
	case 3:
		throw VoltarAtras();
	}
}

/**
 * @brief Funcao que gere a opccao definicoes do utilizador.
 * @param c comunidade que contem todos os utilizadores inscritos.
 * @param u utilizador que se esta a gerir.
 */
void definicoesUtilizador(Utilizador *u, Comunidade *c) {
	//Menu Definicoes
	header("DEFINICOES");
	u->imprimirDefinicoes();
	menuDefinicoes();
	int op;
	opccao(op, 1, 2);

	clrscr();

	if (op == 1) {
		menuAlterarDefinicoes();
		opccao(op, 1, 6);
	} else
		throw VoltarAtras();

	clrscr();

	header("DEFINICOES");

	switch (op) {
	case 1: //Alterar Visibilidade
	{
		int v;
		cout << "Publica (1) , Privada (0) :";
		cin >> v;
		if (v > 1 && v < 0)
			cout << "Visibilidade Invalida" << endl;
		else if (v == 1)
			u->setVisibilidade(true);
		else
			u->setVisibilidade(false);
		break;
	}
	case 2: //Alterar Nome
	{
		string n;
		cout << "Nome novo: " << endl;
		cin.ignore(1000, '\n');
		getline(cin, n);
		u->setNome(n);
		break;
	}
	case 3: //Alterar Login
	{
		string l;
		cout << "Login novo: " << endl;
		cin >> l;
		Utilizador *p = new Utilizador;
		p->setLogin(l);
		if (c->existeUtil(p) == -1) {
			u->setLogin(l);
			delete p;
		} else {
			delete p;
			throw UtilizadorJaExiste(u->getLogin());
		}
		break;
	}
	case 4: //Alterar Idade
	{
		int idade;
		cout << "Idade nova: ";
		cin >> idade;
		u->setIdade(idade);
		break;
	}
	case 5: //Alterar Email
	{
		string e;
		cout << "Email novo: ";
		cin >> e;
		u->setEmail(e);
		break;
	}
	case 6: //Telemovel
	{
		int t;
		cout << "Novo telemovel: ";
		cin >> t;
		u->setTelemovel(t);
		break;
	}
	}
	cout << endl << "Mudanca bem succedida!" << endl << endl;
	esperar();
}

/**
 * @brief Funcao que mostra o menu do utilizador.
 * @param u utilizador que se esta a gerir.
 * @return op opccao escolhida do menu.
 */
int menuUtilizador(Utilizador *u) {
	clrscr();
	header("Utilizador - " + u->getLogin());
	menuUtilizador();
	int op;
	opccao(op, 1, 6);
	return op;
}

/**
 * @brief Funcao que analisa e gere a opccao op do menu do utilizador.
 * @param c comunidade que contem todos os utilizadores inscritos.
 * @param u utilizador que se esta a gerir.
 */
void opccaoMenuUtilizador(Utilizador *u, Comunidade *c, int op) {
	clrscr();
	switch (op) {
	case 1: //Perfil
	{
		header("PERFIL");
		u->imprimirUtilizador();
		esperar();
		break;
	}
	case 2: //Amigos
	{
		amigosUtilizador(u, c);
		break;
	}
	case 3: //Conversas
	{
		mensagensUtilizador(u, c);
		break;
	}
	case 4: //Comunidade
	{
		string login;
		//int i;
		comunidade(c);
		cout << endl;

		cout << "Ver Perfil (1)" << endl;
		cout << "Voltar Atras (2)" << endl << endl;

		opccao(op, 1, 2);
		if (op == 1) {
			cout << endl << "Login: ";
			input<string>(login);

			clrscr();

			header(u->getAmigo(login)->getLogin());
			u->getAmigo(login)->imprimirUtilizador();
		} else
			throw VoltarAtras();
		esperar();
		break;
	}
	case 5: //Definicoes
	{
		definicoesUtilizador(u, c);
		break;
	}
	}
}

/**
 * @brief Funcao da interface do utilizador.
 * Mostra as diferentes opccoes do menu utilizador e gere a escolhida.
 * @param c comunidade que contem todos os utilizadores inscritos.
 * @param u utilizador que estamos a gerir.
 */
void MenuUtilizador(Utilizador *u, Comunidade *c) {
	bool terminar = false;
	int op;
	do {
		try {
			op = menuUtilizador(u);
			if (op == 6)
				terminar = true;
			opccaoMenuUtilizador(u, c, op);
		} catch (OpccaoInvalida<int> (x)) {
			cout << x.getOp() << " nao se encontra entre as opccoes "
					<< x.getMin() << " e " << x.getMax() << endl << endl;
			esperar();
		} catch (UtilizadorInexistente (x)) {
			cout << "Nao existe um utilizador com o login " << x.getLogin()
					<< endl << endl;
			esperar();
		} catch (UtilizadorJaExiste (x)) {
			cout << "Ja existe um utilizador com o login " << x.getLogin()
					<< endl << endl;
			esperar();
		} catch (IdadeInsuficiente (x)) {
			cout << "So e permitido usar a aplicacao com maiores de 18 anos!"
					<< endl << endl;
			esperar();
		} catch (DataInvalida (x)) {
			cout << x.getDia() << "/" << x.getMes() << "/" << x.getAno()
					<< " e invalida!" << endl << endl;
			esperar();
		} catch (AmigoJaExiste (x)) {
			cout << x.getLogin() << " ja e seu amigo!" << endl << endl;
			esperar();
		} catch (AmigoInexistente (x)) {
			cout << x.getLogin() << " nao e seu amigo!" << endl << endl;
			esperar();
		} catch (VoltarAtras) {
		} catch (InputFail) {
			cout << endl;
			esperar();
		} catch (HoraInvalida) {
			cout << "Hora Invalida!" << endl << endl;
			esperar();
		} catch (GrupoInexistente (x)) {
			cout << "Grupo numero " << x.getGrupo() << " inexistente!" << endl
					<< endl;
			esperar();
		} catch (MembroInexistente (x)) {
			cout << "Nao existe nenhum membro do grupo com o login "
					<< x.getLogin() << endl << endl;
			esperar();
		} catch (NaoModerador (x)) {
			cout << "O membro " << x.getNome() << " nao e moderador" << endl
					<< endl;
			esperar();
		} catch (PedidoInexistente (x)) {
			cout << "Nao existe nenhum pedido de adesao com o login "
					<< x.getLogin() << endl << endl;
		} catch (ConversaInexistente (x)) {
			cout << "Conversa numero " << x.getPosicao() << " inexistente!"
					<< endl << endl;
			esperar();
		}
	} while (terminar == false);
}

/*****************************************************************
 *                             MAIN                               *
 *****************************************************************/

/**
 * @brief Main do programa.
 * Gere a interacao entre os diferentes utilizadores de uma comunidade.
 */
int main() {
	Comunidade *c = new Comunidade;
	Utilizador *u = new Utilizador;

	c->leComunidade();
	c->printComunidade();
	c->escreveComunidade();
	/*
	int d, m, a;
	while (1) {
		u = MenuInicial(c);
		clrscr();
		header("Loading ...");
		cout << "Data (dia mes ano): ";
		cin >> d >> m >> a;
		dataHoje.setData(d, m, a);
		MenuUtilizador(u, c);
	}
	*/
	return 0;
}
