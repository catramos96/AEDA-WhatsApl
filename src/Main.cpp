#include <iostream>
#include <windows.h>

/*
#include "System.h"
#include "Utilizador.h"
#include "Grupo.h"
#include "Mensagem.h"
#include "Conversa.h"
*/
#include "Comunidade.h"
#include "Templates.h"
#include "Excecoes.h"

using namespace std;

/*PROBLEMAS:
só um telemovel por utilizador
*/

void esperar() {
	system("pause");
}



/*****************************************************************
*                          MENU UNICIAL                          *
*****************************************************************/

//opccao login
Utilizador * login(Comunidade *c) {
<<<<<<< HEAD
	string login;
	int i;
	cout << "Login de Utilizador" << endl << endl;
	cout << "Login: ";
	cin >> login;
	Utilizador * u = new Utilizador();
	u->setLogin(login);
	i = c->existeUtil(u);
	if (i != -1)
		u = c->utilizadorNaPosicao(i);
	else
		throw UtilizadorInexistente(u->getLogin());
	return u;
=======
  string login;
  int i,op;
  Utilizador * u = new Utilizador();

  imprimirFicheiro("HeaderLogin.txt");
  imprimirFicheiro("MenuLogin.txt");
  opccao<int>(op,1,2);
  
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
>>>>>>> 8e2b1313dc929ae35ef2cba3a1fecebf8bb83186
}

//opccao registar
void registar(Comunidade *c) {
<<<<<<< HEAD
	bool vis;
	string login, nome, email;
	int telemovel;
	int idade, dia, mes, ano;

	cout << "Registar Utilizador" << endl << endl;
	cout << "Login: ";
	cin >> login;
	cout << "Nome: ";
	cin >> nome;
	cout << "Email: ";
	cin >> email;
	cout << "Idade: ";
	cin >> idade;
	cout << "Telemovel: ";
	cin >> telemovel;
	cout << "Data (dia mes ano): ";
	cin >> dia >> mes >> ano;
	Data dA(dia, mes, ano);
	cout << "Perfil publico/privado (1/0): ";
	cin >> vis;

	Utilizador * u = new Utilizador(vis, login, nome, email, dA, telemovel, idade);

	c->adicionarUtil(u);
=======
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
>>>>>>> 8e2b1313dc929ae35ef2cba3a1fecebf8bb83186
}

//opccao comunidade
void comunidade(Comunidade *c) {
<<<<<<< HEAD
	int op;
	cout << "Comunidade" << endl << endl;
	cout << "Ordenar por: " << endl;
	cout << "Login (1)" << endl;
	cout << "Data (2)" << endl << endl;

	cout << "Seleccione uma opccao: ";
	cin >> op;
	if (op < 1 || op > 3) //Resposta errada
		throw OpccaoInvalida<int>(op, 1, 2);
	clrscr();
	cout << "COMUNIDADE" << endl << "(nome/login)" << endl << endl;
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
	}
	c->printComunidade();
	cout << endl;
	esperar();
=======
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
>>>>>>> 8e2b1313dc929ae35ef2cba3a1fecebf8bb83186
}

//Analiza a opccao escolhida do menu
Utilizador * opccaoMenuInicial(int op, Comunidade *c) {
<<<<<<< HEAD

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
		u->setNome("sair");
		break;
	}
	}
	return u;
=======
 
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
>>>>>>> 8e2b1313dc929ae35ef2cba3a1fecebf8bb83186
}

//Header do menu inicial
int headerInicio() {
<<<<<<< HEAD
	int op;
	clrscr();
	cout << "MENU INICIAL" << endl << endl;
	cout << "LOGIN (1)" << endl;
	cout << "REGISTAR (2)" << endl;
	cout << "COMUNIDADE (3)" << endl;
	cout << "SAIR (4)" << endl;
	cout << endl;
	cout << "Seleccione uma opccao: ";
	cin.clear();
	cin >> op;
	if (op < 1 || op > 4) //Resposta errada
		throw OpccaoInvalida<int>(op, 1, 4);
	return op;
}

//Try e catch
Utilizador * MenuInicial(Comunidade *c) {
	bool login = false;
	bool sair = false;
	int op1;
	Utilizador* u = new Utilizador();
	do
	{
		/*
		try {
			op1 = headerInicio();
			u = opccaoMenuInicial(op1, c);
			if (u->getNome() != "" && u->getNome() != "sair")
				login = true;
			else if (u->getNome() == "sair")
				return 0;
		}
		catch (OpccaoInvalida<int>(o)) {
			cout << o.getOp() << "nao se encontra entre " << o.getMin() << " e " << o.getMax() << endl;
			esperar();
		}
		catch (UtilizadorInexistente((*u)->getLogin())) {
			cout << "Nao existe um utilizador com esse login " << endl;
			esperar();
		}
		catch (UtilizadorJaExiste(u)) {
			cout << "Ja existe um utilizador com esse login " << endl;
			esperar();
		}
		/*
		catch (OpccaoInvalida<int>(o)) {
		cout << o.getOp() << "nao se encontra entre " << o.getMin() << " e " << o.getMax() << endl;
		esperar();
		}

		catch (IdadeInsuficiente(i)) {
			cout << "So e permitido usar a aplicacao com maiores de 18 anos" << endl;
			esperar();
		}

		/*
		catch (DataInvalida()) {
		cout << "Data Invalida!" << endl;
		esperar();
		}
		*/
	} while (!login); //Até não efectuar login

	return u;
=======
  int op;
  clrscr();
  imprimirFicheiro("HeaderWhatsApl.txt");
  imprimirFicheiro("MenuInicial.txt");
  opccao<int>(op,1,5);
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
    
  } while (!login); //Até não efectuar login

  return u;
>>>>>>> 8e2b1313dc929ae35ef2cba3a1fecebf8bb83186
}

/*****************************************************************
*                         MENU UTILIZADOR                        *
*****************************************************************/

//Opcao Amigos
void amigosUtilizador(Utilizador *u, Comunidade *c) {
<<<<<<< HEAD
	int op;

	//Menu Amigos
	cout << "AMIGOS" << endl << endl;
	cout << "Adicionar Novo Amigo (1)" << endl;
	cout << "Remover Amigo (2)" << endl;
	cout << "Ver Amigos (3)" << endl << endl;
	cout << endl;
	cout << "Seleccione uma opccao: ";
	cin >> op;
	if (op < 1 || op > 3) //Resposta errada
		throw OpccaoInvalida<int>(op, 1, 3);

	string login;
	int i;

	clrscr();
	switch (op)
	{
	case 1:
	{
		/*
		//adicionar amigo

		cout << "ADICIONAR AMIGO" << endl << endl;
		cout << "Login:";
		cin >> login;
		Utilizador * a = new Utilizador();
		a->setLogin(login);

		i = c->existeUtil(a); //Existe na comunidade ?
		if (i == -1)
			throw UtilizadorInexistente((*a).getLogin());

		u->addAmigo(*c->utilizadorNaPosicao(i)); //Já é meu amigo? se sim adiciona
		cout << endl << login << " adicionado com sucesso" << endl << endl;
		esperar();
		break;
		*/
	}

	//Remover Amigo
	case 2:
	{
		/*
		cout << "REMOVER AMIGO" << endl << endl;
		cout << "Login:";
		cin >> login;
		Utilizador * a = new Utilizador();
		a->setLogin(login);
		i = c->existeUtil(a); //Existe na comunidade ?
		if (i == -1)
			throw UtilizadorInexistente((*a).getLogin());
		
		u->removerAmigo(*c->utilizadorNaPosicao(i)); //É amigo ? se sim remove
		cout << endl << login << " removido com sucesso" << endl << endl;
		esperar();
		break;
		*/
	}
	//Ver amigos
	case 3:
	{
		/*
		cout << "AMIGOS" << endl << "(nome/login)" << endl << endl;
		u->imprimirAmigos();
		cout << endl;
		esperar();
		break;
		*/
	}
	}
=======
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

    u->addAmigo(*c->utilizadorNaPosicao(i)); //Já é meu amigo? se sim adiciona
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

    u->removerAmigo(*c->utilizadorNaPosicao(i)); //É amigo ? se sim remove
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
>>>>>>> 8e2b1313dc929ae35ef2cba3a1fecebf8bb83186
}

//Opcao Definicoes
void definicoesUtilizador(Utilizador *u, Comunidade *c) {

<<<<<<< HEAD
	int op;

	//Menu Definicoes
	cout << "DEFINICOES" << endl << endl;
	u->imprimirDefinicoes();
	cout << endl;

	cout << "Alterar: " << endl;
	cout << "Visibilidade (1)" << endl;
	cout << "Nome (2)" << endl;
	cout << "Login (3)" << endl;
	cout << "Idade (4)" << endl;
	cout << "Email (5)" << endl;
	cout << "Telemovel (6)" << endl;
	cout << endl;

	cout << "Opcao: ";
	cin >> op;
	if (op > 6 || op < 1)
		throw OpccaoInvalida<int>(op, 1, 6);

	clrscr();
	cout << "DEFINICOES" << endl << endl;
	switch (op)
	{
	case 1: //Alterar Visibilidade
	{
		int v;
		cout << "Publica (1) , Privada (0) :";
		cin >> v;
		if (v > 1 && v < 0)
			cout << "Visibilidade Invalida" << endl;
		else
			u->setVisibilidade(v);
		break;
	}
	case 2: //Alterar Nome
	{
		string n;
		cout << "Nome novo: " << endl;
		cin >> n;
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
		else
			throw UtilizadorJaExiste(*u);
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
		int r;
		int t;
		cout << "Adicionar telemovel (1)" << endl;
		cout << "Remover telemovel (2)" << endl;
		cout << endl;
		cout << "Opcao: ";
		cin >> r;
		clrscr();
		if (r > 2 || r < 1)
			throw OpccaoInvalida<int>(op, 1, 2);
		if (r == 1) {
			cout << "ADICIONAR TELEMOVEL" << endl << endl;
			cout << "Telemovel: ";
			cin >> t;
			u->addTelemovel(t);
		}
		else if (r == 2) {
			cout << "REMOVER TELEMOVEL" << endl << endl;
			cout << "Telemovel: ";
			cin >> t;
			u->removerTelemovel(t);
		}
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
	cin.clear();
	cout << "MENU UTILIZADOR - " << u->getNome() << endl << endl;
	//OPCCOES
	cout << "Perfil (1)" << endl;
	cout << "Amigos (2)" << endl;
	cout << "Conversas (3)" << endl;
	cout << "Comunidade (4)" << endl;
	cout << "Definicoes (5)" << endl;
	cout << "Terminar Seccao (6)" << endl;
	cout << endl;
	cout << "Seleccione uma opccao: ";

	cin >> op;
	if (op < 1 || op > 6) //Resposta errada
		throw OpccaoInvalida<int>(op, 1, 5);
	return op;
}

//Analiza a opcao escolhida do menu utilizador
void opccaoMenuUtilizador(Utilizador *u, Comunidade *c, int op) {
	clrscr();
	switch (op)
	{
	case 1: //Perfil
	{
		cout << "DEFINICOES" << endl << endl;
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
			throw UtilizadorInexistente((*a).getLogin());
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
		/*
		try {
			op = menuUtilizador(u);
			if (op == 6)
				terminar = true;
			opccaoMenuUtilizador(u, c, op);
		}
		catch (OpccaoInvalida<int>(o)) {
			cout << o.getOp() << "nao se encontra entre " << o.getMin() << " e " << o.getMax() << endl;
			esperar();
		}
		catch (UtilizadorInexistente(u.getLogin())) {
			cout << "Nao existe um utilizador com esse login " << endl;
			esperar();
		}
		catch (UtilizadorJaExiste(u)) {
			cout << "Ja existe um utilizador com esse login " << endl;
			esperar();
		}
		/*
		catch (OpccaoInvalida<int>(o)) {
		cout << o.getOp() << "nao se encontra entre " << o.getMin() << " e " << o.getMax() << endl;
		esperar();
		}

		catch (IdadeInsuficiente(i)) {
			cout << "So e permitido usar a aplicacao com maiores de 18 anos" << endl;
			esperar();
		}
		*/
	} while (terminar == false);
}
=======
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
>>>>>>> 8e2b1313dc929ae35ef2cba3a1fecebf8bb83186

  
/*****************************************************************
*                             MAIN                               *
*****************************************************************/
<<<<<<< HEAD
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
//fixes.pedidoAdesao(Carlos, d3, Rui, true); //nao é moderador
Data d4(7, 8, 9);
fixes.bloquearMembro(Rui, Ana, d4); //ver se está bloqueado
//fixes.bloquearMembro(Ana, Sofia, d4); // nao é moderador
//fixes.bloquearMembro(Carlos, Ana, d4); // nao é utilizador
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
=======
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
    //fixes.pedidoAdesao(Carlos, d3, Rui, true); //nao é moderador
    Data d4(7, 8, 9);
    fixes.bloquearMembro(Rui, Ana, d4); //ver se está bloqueado
    //fixes.bloquearMembro(Ana, Sofia, d4); // nao é moderador
    //fixes.bloquearMembro(Carlos, Ana, d4); // nao é utilizador
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
>>>>>>> 8e2b1313dc929ae35ef2cba3a1fecebf8bb83186
}

catch(UtilizadorInexistente &e){
cout << "Utilizador " << e.getLogin() << " nao existe!" << endl;
}

return 0;
}

Data d(1, 1, 2011);
Utilizador Ana(true, "ana123", "Ana", "ana@kdsf.com", d, 123456, 18);
Data d1(4, 5, 2006);
Utilizador Rui(false, "Rui1234", "Rui", "rui@bgd.com", d1, 4455, 30);
Data d2(2, 3, 2014);
Utilizador Sofia(true, "Sofia12345", "Sofia", "sofia@dsjh.com", d2, 7878, 40);
Data d3(3, 4, 2010);
Utilizador Carlos(false, "456", "Carlos", "carlos.eedsnh.com", d3, 456456, 70);

Data d4(5,11,2015);
/*
Horas h1(12,27);
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