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
  int i,op;
  Utilizador * u = new Utilizador();

  cout << "Login de Utilizador" << endl << endl;
  cout << "Fazer Login (1)" << endl;
  cout << "Voltar Atras (2)" << endl << endl;
  cout << "Seleccione uma opccao: ";
  cin >> op;
  
  clrscr(); //clears the screen

  cout << "Login de Utilizador" << endl << endl;

  if (op == 1)
  {
    cout << "Login: ";
    cin >> login;
    
    u->setLogin(login);
    i = c->existeUtil(u);
    if (i != -1)
      u = c->utilizadorNaPosicao(i);
    else
      throw UtilizadorInexistente(*u);
  }
  else if (op == 2)
  throw VoltarAtras();
  else
    throw OpccaoInvalida<int>(op, 1, 2);
  
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

  cout << "Registar Utilizador" << endl << endl;
  cout << "Registar (1)" << endl;
  cout << "Voltar Atras (2)" << endl << endl;
  cout << "Seleccione uma opccao: ";
  cin >> op;

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
  else
    throw OpccaoInvalida<int>(op, 1, 2);
}

//opccao comunidade
void comunidade(Comunidade *c) {
  int op;
  cout << "Comunidade" << endl << endl;
  cout << "Ordenar por: " << endl;
  cout << "Login (1)" << endl;
  cout << "Data (2)" << endl << endl;
  cout << "Voltar Atras (3)" << endl << endl;

  cout << "Seleccione uma opccao: ";
  cin >> op;   

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
  default:
    throw OpccaoInvalida<int>(op, 1, 3);
  }

  cout << "COMUNIDADE" << endl << "(nome/login)" << endl << endl;
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
    exit(1);//sair
  }
  default:
    throw OpccaoInvalida<int>(op, 1, 4);
  }
  return u;
}

//Header do menu inicial
int headerInicio() {
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
}

/*****************************************************************
*                         MENU UTILIZADOR                        *
*****************************************************************/

//Opcao Amigos
void amigosUtilizador(Utilizador *u, Comunidade *c) {
  int op;

  //Menu Amigos
  cout << "AMIGOS" << endl << endl;
  cout << "Adicionar Novo Amigo (1)" << endl;
  cout << "Remover Amigo (2)" << endl;
  cout << "Ver Amigos (3)" << endl;
  cout << "Voltar Atras (4)" << endl << endl;
  cout << endl;
  cout << "Seleccione uma opccao: ";
  cin >> op;
  if (op < 1 || op > 4) //Resposta errada
    throw OpccaoInvalida<int>(op, 1, 4);

  string login;
  int i;

  clrscr();
  switch (op)
  {
  case 1:
  {
    //adicionar amigo

    cout << "ADICIONAR AMIGO" << endl << endl;
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
}

//Opcao Definicoes
void definicoesUtilizador(Utilizador *u, Comunidade *c) {

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
    if(r > 2 || r < 1)
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
      throw OpccaoInvalida<int>(op, 1, 6);
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
}
*/