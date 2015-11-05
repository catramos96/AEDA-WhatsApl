#include <iostream>
#include <windows.h>
#include "System.h"
#include "Utilizador.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Templates.h"
#include "Mensagem.h"
#include "Conversa.h"


using namespace std;

/*PROBLEMAS:
s� um telemovel por utilizador
*/

void esperar() {
	system("pause");
}



/*****************************************************************
*                          MENU UNICIAL                          *
*****************************************************************/

//opccao login
Utilizador * login(Comunidade *c) {
	string login;
	int i, op;
	Utilizador * u = new Utilizador();

	imprimirFicheiro("HeaderLogin.txt");
	imprimirFicheiro("MenuLogin.txt");
	opccao<int>(op, 1, 2);

	clrscr(); //clears the screen

	imprimirFicheiro("HeaderLogin.txt");

	if (op == 1)
	{
		cout << "Login: ";
		cin >> login;

		u->setLogin(login);
		i = c->existeUtil(u);
		if (i != -1)
			u = c->utilizadorNaPosicao(i);
		else {
			delete u;
			throw UtilizadorInexistente(*u);
		}
	}
	else if (op == 2)
		throw VoltarAtras();

	return u;
}

//opccao registar
void registar(Comunidade *c) {
	bool vis;
	string login, nome, email;
	int telemovel;
	int idade, dia, mes, ano;
	int op;
	Data dA;

	imprimirFicheiro("HeaderRegistar.txt");
	imprimirFicheiro("MenuRegistar.txt");
	opccao<int>(op, 1, 2);

	clrscr();

	if (op == 1) {
		cout << "Registar Utilizador" << endl << endl;
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

		Utilizador * u = new Utilizador(vis, login, nome, email, dA, telemovel, idade);
		c->adicionarUtil(u);
	}
	else if (op == 2)
		throw VoltarAtras();
}

//opccao comunidade
void comunidade(Comunidade *c) {
	int op;
	imprimirFicheiro("HeaderComunidade.txt");
	imprimirFicheiro("MenuComunidade.txt");
	opccao<int>(op, 1, 3);

	clrscr();

	switch (op)
	{
	case 1:
	{
		c->ordenaLogin();
		break;
	}
	case 2:
	{
		c->ordenaData();
		break;
	}
	case 3:
		throw VoltarAtras();
	}

	imprimirFicheiro("HeaderComunidade.txt");
	imprimirFicheiro("OrdenarComunidade.txt");
	c->printComunidade();
	cout << endl;
	esperar();
}

//Analiza a opccao escolhida do menu
Utilizador * opccaoMenuInicial(int op, Comunidade *c) {

	Utilizador *u = new Utilizador();
	clrscr();
	switch (op)
	{
	case 1:
	{
		u = login(c);
		break;
	}
	case 2:
	{
		registar(c);
		break;
	}
	case 3:
	{
		comunidade(c);
		break;
	}
	case 4:
	{
		imprimirFicheiro("Informacao.txt");
		esperar();
	}
	case 5:
	{
		exit(1);//sair
	}
	}
	return u;
}

//Header do menu inicial
int headerInicio() {
	int op;
	clrscr();
	imprimirFicheiro("HeaderWhatsApl.txt");
	imprimirFicheiro("MenuInicial.txt");
	opccao<int>(op, 1, 5);
	return op;
}

//Try e catch
Utilizador * MenuInicial(Comunidade *c) {
	bool login = false;
	bool sair = false;
	int op;
	Utilizador* u = new Utilizador;
	do
	{
		try {
			op = headerInicio();
			u = opccaoMenuInicial(op, c);
			if (u->getNome() != "")
				login = true;
		}
		catch (OpccaoInvalida<int>(o)) {
			cout << o.getOp() << " nao se encontra entre as opccoes " << o.getMin() << " e " << o.getMax() << endl << endl;
			esperar();
		}
		catch (UtilizadorInexistente(u)) {
			cout << "Nao existe um utilizador com esse login " << endl << endl;
			esperar();
		}
		catch (UtilizadorJaExiste(u)) {
			cout << "Ja existe um utilizador com esse login " << endl << endl;
			esperar();
		}
		catch (VoltarAtras) {
		}
		catch (IdadeInsuficiente(i)) {
			cout << "So e permitido usar a aplicacao com maiores de 18 anos" << endl << endl;
			esperar();
		}
		catch (DataInvalida(d)) {
			cout << d.getData() << " data Invalida!" << endl << endl;
			esperar();
		}
		catch (InputFail) {
			cout << "Input fail!" << endl << endl;
			esperar();
		}

	} while (!login); //At� n�o efectuar login

	return u;
}

/*****************************************************************
*                         MENU UTILIZADOR                        *
*****************************************************************/

//Opcao Amigos
void amigosUtilizador(Utilizador *u, Comunidade *c) {
	int op;

	//Menu Amigos
	imprimirFicheiro("HeaderAmigos.txt");
	imprimirFicheiro("MenuAmigos.txt");
	opccao<int>(op, 1, 4);

	string login;
	int i;

	clrscr();

	switch (op)
	{
	case 1:
	{
		//adicionar amigo

		imprimirFicheiro("HeaderAmigos.txt");
		/**************************************************************************
		EM CONSTRUCAO
		**************************************************************************/
		cout << "Login:";
		cin >> login;
		Utilizador * a = new Utilizador();
		a->setLogin(login);

		i = c->existeUtil(a); //Existe na comunidade ?
		if (i == -1)
			throw UtilizadorInexistente(*a);

		u->addAmigo(*c->utilizadorNaPosicao(i)); //J� � meu amigo? se sim adiciona
		cout << endl << login << " adicionado com sucesso" << endl << endl;
		esperar();
		break;
	}

	//Remover Amigo
	case 2:
	{
		cout << "REMOVER AMIGO" << endl << endl;
		cout << "Login:";
		cin >> login;
		Utilizador * a = new Utilizador();
		a->setLogin(login);
		i = c->existeUtil(a); //Existe na comunidade ?
		if (i == -1)
			throw UtilizadorInexistente(*a);

		u->removerAmigo(*c->utilizadorNaPosicao(i)); //� amigo ? se sim remove
		cout << endl << login << " removido com sucesso" << endl << endl;
		esperar();
		break;
	}
	//Ver amigos
	case 3:
	{
		cout << "AMIGOS" << endl << "(nome/login)" << endl << endl;
		u->imprimirAmigos();
		cout << endl;
		esperar();
		break;
	}
	case 4:
		throw VoltarAtras();
	}
}

//Opcao Definicoes
void definicoesUtilizador(Utilizador *u, Comunidade *c) {

	int op;

	//Menu Definicoes
	imprimirFicheiro("HeaderDefinicoes.txt");
	u->imprimirDefinicoes();
	cout << endl;
	imprimirFicheiro("MenuDefinicoes.txt");
	opccao<int>(op, 1, 2);

	clrscr();

	if (op == 1) {
		imprimirFicheiro("MenuAlterarDefinicoes.txt");
		opccao<int>(op, 1, 6);
	}
	else
		throw VoltarAtras();

	clrscr();

	imprimirFicheiro("HeaderDefinicoes.txt");

	switch (op)
	{
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
		}
		else {
			delete p;
			throw UtilizadorJaExiste(*u);
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

//header do menu Utilizador
int menuUtilizador(Utilizador *u) {
	int op;

	clrscr();
	imprimirFicheiro("HeaderUtilizador.txt");
	imprimirFicheiro("MenuUtilizador.txt");
	cout << "Seleccione uma opccao: ";
	opccao<int>(op, 1, 6);
	return op;
}

//Analiza a opcao escolhida do menu utilizador
void opccaoMenuUtilizador(Utilizador *u, Comunidade *c, int op) {
	clrscr();
	switch (op)
	{
	case 1: //Perfil
	{
		imprimirFicheiro("HeaderPerfil.txt");
		u->imprimirUtilizador();
		cout << endl;
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
		//conversasUtilizador(u, c);
		break;
	}
	case 4: //Comunidade
	{
		string login;
		int i;
		comunidade(c);
		cout << endl;
		cout << "Login de utilizador: " << login;
		Utilizador * a = new Utilizador();
		a->setLogin(login);
		i = c->existeUtil(a); //Existe na comunidade ?
		if (i == -1)
			throw UtilizadorInexistente(*a);
		a->imprimirDefinicoes();
		break;
	}
	case 5: //Definicoes
	{
		definicoesUtilizador(u, c);
		break;
	}
	}
}

//try e catch
void MenuUtilizador(Utilizador *u, Comunidade *c) {
	bool terminar = false;
	int op;
	do
	{
		try {
			op = menuUtilizador(u);
			if (op == 6)
				terminar = true;
			opccaoMenuUtilizador(u, c, op);
		}
		catch (OpccaoInvalida<int>(o)) {
			cout << o.getOp() << " nao se encontra entre as opccoes " << o.getMin() << " e " << o.getMax() << endl;
			esperar();
		}
		catch (UtilizadorInexistente(u)) {
			cout << "Nao existe um utilizador com esse login " << endl;
			esperar();
		}
		catch (UtilizadorJaExiste(u)) {
			cout << "Ja existe um utilizador com esse login " << endl;
			esperar();
		}
		catch (IdadeInsuficiente(i)) {
			cout << "So e permitido usar a aplicacao com maiores de 18 anos" << endl;
			esperar();
		}
		catch (DataInvalida(d)) {
			cout << d.getData() << " data Invalida!" << endl;
			esperar();
		}
	} while (terminar == false);
}


/*****************************************************************
*                             MAIN                               *
*****************************************************************/
int main() {
	Comunidade *c = new Comunidade;
	Utilizador *u = new Utilizador;

	while (1) {
		u = MenuInicial(c);
		clrscr();
		MenuUtilizador(u, c);
	}
	return 0;
}

/*
try{
Data data;
int dia, m, a;
cout << "Dia, mes, ano ";
cin >> dia >> m >> a;
data.setData(dia, m, a);
cout << data << endl;

Horas hora;
int h, min;
cout << "Hora, minutos";
cin >> h >> min;
hora.setHoras(h, min);
cout << hora << endl;

//--------------------//

Data d(1, 1, 1);
Utilizador Ana(true, "ana123", "Ana", "ana@kdsf.com", d, 123456);
Data d1(4, 5, 6);
Utilizador Rui(false, "Rui1234", "Rui", "rui@bgd.com", d1, 4455);
Data d2(2, 3, 4);
Utilizador Sofia(true, "Sofia12345", "Sofia", "sofia@dsjh.com", d2, 7878);
Data d3(3, 4, 6);
Utilizador Carlos(false, "456", "Carlos", "carlos.eedsnh.com", d3, 456456);

Grupo fixes("fixes", d, Ana);

fixes.pedidoAdesao(Rui, Ana, d1, true);
//fixes.pedidoAdesao(Sofia, d2, Ana, false);
fixes.pedidoAdesao(Sofia, Ana, d2, true);
//fixes.pedidoAdesao(Carlos, d3, Rui, true); //nao � moderador
Data d4(7, 8, 9);
fixes.bloquearMembro(Rui, Ana, d4); //ver se est� bloqueado
//fixes.bloquearMembro(Ana, Sofia, d4); // nao � moderador
//fixes.bloquearMembro(Carlos, Ana, d4); // nao � utilizador
Data d5(1, 2, 3);
fixes.bloquearMembro(Rui, Ana, d5); //membro ja bloqueado
fixes.pedidoAdesao(Rui, Ana, d5, true); // desbloquear membro por pedido
Data d6(5, 7, 9);
fixes.retiraMembro(Sofia, Ana, d6);
//fixes.retiraMembro(Carlos, Ana, d6); //Membro Inexistente
//fixes.retiraMembro(Ana, Rui, d6); //nao e moderador

Data d7(1, 2, 3);
fixes.bloquearMembro(Rui, Ana, d7);
Data d8(3, 5, 7);
fixes.desbloquearMembro(Rui, Ana, d8);
fixes.printMembros();
fixes.printStatus();
//fixes.desbloquearMembro(Carlos, Ana, d8); //membro inexistente
//fixes.desbloquearMembro(Ana, Rui, d8); // nao e moderador

//--------------------------------------//

Comunidade global;
global.adicionarUtil(&Ana);
global.adicionarUtil(&Rui);
global.adicionarUtil(&Carlos);
global.adicionarUtil(&Sofia);

global.printComunidade();
global.ordenaData();
global.printComunidade();
global.ordenaLogin();
global.verUtilizador(&Ana);
global.verUtilizador(&Rui);
global.verUtilizador(&Carlos);
global.verUtilizador(&Sofia);

}
catch (Data::DataInvalida &e){
cout << "Data Invalida!" << endl;
}
catch (Horas::HoraInvalida &e){
cout << "Hora Invalida!" << endl;
}
catch (NaoModerador &e){
cout << "Utilizador " << e.getUtil() << " nao e moderador!" << endl;
}
/*
catch(UtilizadorInexistente &e){
cout << "Utilizador " << e.getLogin() << " nao existe!" << endl;
}

return 0;
}

Conversa *c1;
c1 = Ana.criarConversa(&Rui);

Mensagem *sms1 = new MsgTexto("ola rui, tudo bem?", d4,h1);
Ana.enviarMensagem(sms1,c1);
Horas h2(12,28);
Mensagem *sms2 = new MsgTexto("ola Ana. tudo, e contigo?",d4, h2);
Rui.enviarMensagem(sms2, c1);
Horas h3(12, 30);
Mensagem *sms3 = new MsgImagem(d4, h3);
Ana.enviarMensagem(sms3, c1);
Horas h4(12, 35);
Mensagem *sms4 = new MsgVideo(d4, h4);
Rui.enviarMensagem(sms4, c1);
c1->imprimirConversa();

Grupo *g1;
Data d5(7, 11, 2015);
Horas h5(13, 42);
g1 = Rui.criarGrupo("Os fixes", d4);
Ana.pedirAdesao(g1);
Sofia.pedirAdesao(g1);
Carlos.pedirAdesao(g1);
g1->printPedidos();
Rui.aceitaMembro(Ana.getLogin(), g1, d4);
Rui.rejeitaMembro(Sofia.getLogin(), g1, d5);
Rui.aceitaMembro(Carlos.getLogin(), g1, d5);
g1->printPedidos();
g1->printMembros();
g1->printStatus();
Mensagem *sms5 = new MsgTexto("Ola fixes.", d5, h5);
Rui.enviarMensagemGrupo(sms5, g1);
Horas h6(13, 45);
Mensagem *sms6 = new MsgTexto("oi", d5, h6);
Carlos.enviarMensagemGrupo(sms6, g1);
g1->printConversa();
return 0;
*/
