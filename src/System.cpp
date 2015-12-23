#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
#include "Excecoes.h"
#include "System.h"

using namespace std;

/********************************
*		CLASSE HORAS			*
*******************************/
Horas::Horas() {
  hora = 0;
  min = 0;
}

Horas::Horas(int h, int m) {
  if (h < 0 || h > 24 || m < 0 || m > 60)
    throw HoraInvalida();
  hora = h;
  min = m;
}

void Horas::setHoras(int h, int m) {
  if (h < 0 || h > 24 || m < 0 || m > 60)
    throw HoraInvalida();
  else {
    hora = h;
    min = m;
  }
}

int Horas::getHora() const {
  return hora;
}

int Horas::getMinutos() const {
  return min;
}

std::ostream & operator<<(std::ostream & out, const Horas & h) {
  out << h.getHora() << " : " << h.getMinutos();
  return out;
}

bool Horas::operator<(const Horas &h) const {
  if (hora == h.hora) {
    if (min == h.min)
      return false;
    else
      return (min < h.min);
  }
  else
    return (hora < h.hora);
}

/********************************
*	    	CLASSE DATA			*
*******************************/

Data::Data() {
  dia = 0;
  mes = 0;
  ano = 0;
}

Data::Data(int d, int m, int a) {
  dia = d;
  mes = m;
  ano = a;
}

void Data::setData(int d, int m, int a) {
  Data dA(d, m, a);
  if (d < 1 || d > 31 || m < 1 || m > 12 || a < 0)
    throw DataInvalida(d, m, a);
  dia = d;
  mes = m;
  ano = a;
}

int Data::getAno() const {
  return ano;
}

int Data::getMes() const {
  return mes;
}

int Data::getDia() const {
  return dia;
}

bool Data::operator<(const Data&d) const {
  if (ano == d.ano) {
    if (mes == d.mes) {
      if (dia == d.dia)
        return false;
      else
        return (dia < d.dia);
    }
    else
      return (mes < d.mes);
  }
  else
    return (ano < d.ano);
}

std::ostream & operator<<(std::ostream & out, const Data & d) {
  out << d.getDia() << " / " << d.getMes() << " / " << d.getAno();
  return out;
}

bool Data::operator==(const Data&d) const {
  return (ano == d.getAno() && mes == d.getMes() && dia == d.getDia());
}

bool datasTresDias(Data d1, Data d2) {
  int ano1 = d1.getAno();
  int ano2 = d2.getAno();
  int mes1 = d1.getMes();
  int mes2 = d2.getMes();
  int dia1 = d1.getDia();
  int dia2 = d2.getDia();

  if (ano1 == ano2 && mes1 == mes2 && abs(dia1 - dia2 <= 2))
    return true;
  else if (ano1 == ano2 && abs(mes1 - mes2) == 1) {
    switch (mes1)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
      if (dia1 >= 30 && dia2 <= 2 && (dia1 + dia2 >= 32))
        return true;
      break;
    }
    case 4: case 6: case 9: case 11: {
      if (dia1 >= 29 && dia2 <= 2 && (dia1 + dia2 >= 31))
        return true;
      break;
    }
    case 2: {
      if (dia1 >= 27 && dia2 <= 2 && (dia1 + dia2 >= 29))
        return true;
      break;
    }
    }
  }
  else if (abs(ano1 - ano2) == 1 && mes1 == 12 && (mes2 == 1 && mes2 == 01) && dia1 >= 30 && dia2 <= 2 && (dia1 + dia2) >= 32)
    return true;
  else
    return false;
}

//Clears the screen

void clrscr(void)
{
  COORD coordScreen = { 0, 0 }; // upper left corner
  DWORD cCharsWritten;
  DWORD dwConSize;
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(hCon, &csbi);
  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
  // fill with spaces
  FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
  GetConsoleScreenBufferInfo(hCon, &csbi);
  FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
  // cursor to upper left corner
  SetConsoleCursorPosition(hCon, coordScreen);
}


//COUTS
void header(string msg) {
  cout << "//////////////////////////////////////////////////" << endl;
  cout << msg << endl;
  cout << "//////////////////////////////////////////////////" << endl << endl;
}

void menuInicial() {
  header("WHATS APL");
  cout << "LOGIN (1)" << endl;
  cout << "REGISTAR (2)" << endl;
  cout << "COMUNIDADE (3)" << endl;
  cout << "INFORMAÇOES (4)" << endl;
  cout << "SAIR (5)" << endl << endl;
}

void menuComunidade() {
  header("COMUNIDADE");
  cout << "Ordenar por:" << endl;
  cout << "Login (1)" << endl;
  cout << "Data (2)" << endl;
  cout << "Top Utilizadores (3)" << endl;
  cout << "Utilizadores Inativos (4)" << endl << endl;
  cout << "Voltar Atras (5)" << endl << endl;
}

void menuUtilizador() {
  cout << "Perfil (1)" << endl;
  cout << "Amigos (2)" << endl;
  cout << "Mensagens (3)" << endl;
  cout << "Comunidade (4)" << endl;
  cout << "Definicoes (5)" << endl;
  cout << "Terminar Seccao (6)" << endl << endl;
}

void menuAmigos() {
  header("AMIGOS");
  cout << "Adicionar Amigo (1)" << endl;
  cout << "Remover Amigo (2)" << endl;
  cout << "Ver Amigos (3)" << endl;
  cout << "Voltar Atras (4)" << endl << endl;
}

void menuMensagens() {
  header("MENSAGENS");
  cout << "Grupos (1)" << endl;
  cout << "Conversas (2)" << endl;
  cout << "Voltar Atras (3)" << endl << endl;
}

void menuGrupos() {
  header("GRUPOS");
  cout << "Criar novo grupo (1)" << endl;
  cout << "Enviar mensagem (2)" << endl;
  cout << "Ver grupos (3)" << endl;
  cout << "Enviar pedido de Adesao a um grupo (4)" << endl;
  cout << "Voltar Atras (5)" << endl << endl;
}

void menuGerirGrupos() {
  cout << "Adicionar utilizador (1)" << endl;
  cout << "Remover utilizador (2)" << endl;
  cout << "Bloquear utilizador (3)" << endl;
  cout << "Desbloquear utilizador (4)" << endl;
  cout << "Pedidos de adesao (5)" << endl;
  cout << "Mensagens Pendentes (6)" << endl;
  cout << "Voltar Atras (7)" << endl << endl;
}

void menuConversas() {
  header("CONVERSA");
  cout << "Criar nova conversa (1)" << endl;
  cout << "Enviar mensagem (2)" << endl;
  cout << "Ver conversas (3)" << endl;
  cout << "Voltar Atras (4)" << endl << endl;
}

void menuDefinicoes() {
  cout << "Alterar (1)" << endl;
  cout << "Voltar Atras (2)" << endl << endl;
}

void menuAlterarDefinicoes() {
  header("DEFINICOES");
  cout << "Alterar:" << endl;
  cout << "Visibilidade (1)" << endl;
  cout << "Nome (2)" << endl;
  cout << "Login (3)" << endl;
  cout << "Idade (4)" << endl;
  cout << "Email (5)" << endl;
  cout << "Telemovel (6)" << endl << endl;
}

void menuComunidadeOrdenada() {
  header("COMUNIDADE");
  cout << "Nome  /  Login  /  Data" << endl << endl;
}

void menuInformacao() {
  header("INFORMACAO");
  cout << "Desenvlovido por Catarina Ramos, Ines Gomes e Pedro Duarte em algoritmos e estruturas de dados (AEDA),cadeira do 2 ano do curso de Mestrado Integrado de Engenharia Informatica e Computacao (MIEIC) na Faculdade de Engenharia da Universidade do Porto (FEUP)." << endl << endl;
}


