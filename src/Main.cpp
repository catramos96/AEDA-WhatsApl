#include <iostream>

#include "System.h"
#include "Utilizador.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Templates.h"
#include "Mensagem.h"

using namespace std;

int menu() {
  int op;
  cout << "LOGIN (1)" << endl;
  cout << "REGISTAR (2)" << endl;
  cout << "COMUNIDADE (3)" << endl;
  cout << "SAIR (4)" << endl;
  cout << endl;
  cout << "Seleccione uma opccao: ";
  cin >> op;
  if (op < 1 || op > 4) //Resposta errada
    throw OpccaoInvalida<int>(op, 1, 4);
  return op;
}

Utilizador * analisarOpccao(int op, Comunidade &c) {
  Utilizador *u;
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
}

Utilizador * login(Comunidade &c) {
  string login;
  int i;
  cout << "Login de Utilizador" << endl << endl;
  cout << "Login: ";
  cin >> login;
  Utilizador * u = new Utilizador();
  u->setLogin(login);
  i = c.existeUtil(u);
  if (i != -1)
    u = c.utilizadorNaPosicao(i);
  else
    throw UtilizadorInexistente(*u);
  return u;
}

void registar(Comunidade &c) {
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

  c.adicionarUtil(u);
}

void comunidade(Comunidade &c) {
  int op;
  cout << "Comunidade" << endl;
  cout << "Ordenar por: " << endl;
  cout << "Login (1)" << endl;
  cout << "Data (2)" << endl << endl;
  cout << "Sair (3)" << endl << endl;

  cout << "Seleccione uma opccao: ";
  cin >> op;
  if (op < 1 || op > 3) //Resposta errada
    throw OpccaoInvalida<int>(op, 1, 3);

  /*
  switch (op)
  {
  case 1:
  {

  }
  default:
    break;
  }
  */
}

int main() {
  Comunidade c;
  bool login = false;
  int op;
  Utilizador* u;
  //Menu Inicio
  do
  {
    try {
      op = menu();
      u = analisarOpccao(op, c);
      if (u->getNome() != "" && u->getNome() != "sair")
        login = true;
      else if (u->getNome() != "sair")
        return 0;
    }
    catch (OpccaoInvalida<int>(o)) {
      cout << o.getOp() << "nao se encontra entre" << o.getMin() << " e " << o.getMax() << endl;
    }
    catch (UtilizadorInexistente(u)) {
      cout << "Nao existe um utilizador com o login " << u.getLogin() << endl;
    }
    catch (UtilizadorJaExiste(u)) {
      cout << "Ja existe um utilizador com o login " << u.getLogin() << endl;
    }
    catch (IdadeInsuficiente(i)) {
      cout << "So e permitido o registo a maiores de 18 anos" << endl;
    }
  } while (!login);


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
  */
  return 0;
}
