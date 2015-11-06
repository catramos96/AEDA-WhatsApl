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
Horas::Horas(){
	hora = 0;
	min = 0;
}

Horas::Horas(int h, int m){
	if (h < 0 || h > 24 || m < 0 || m > 60)
		throw HoraInvalida();
	hora = h;
	min = m;
}

void Horas::setHoras(int h, int m){
	if (h < 0 || h > 24 || m < 0 || m > 60)
		throw HoraInvalida();
	else{
		hora = h;
		min = m;
	}
}

int Horas::getHora() const{
	return hora;
}

int Horas::getMinutos() const{
	return min;
}

std::ostream & operator<<(std::ostream & out, const Horas & h){
	out << h.getHora() << " : " << h.getMinutos();
	return out;
}

bool Horas::operator<(const Horas &h) const{
	if (hora == h.hora){
		if (min == h.min)
			return false;
		else
			return (min < h.min);
	}else
		return (hora < h.hora);
}

/********************************
 *	    	CLASSE DATA			*
 *******************************/

Data::Data(){
	dia = 0;
	mes = 0;
	ano = 0;
}

Data::Data(int d, int m, int a){
	dia = d;
	mes = m;
	ano = a;
}

void Data::setData(int d, int m, int a){
  Data dA(d, m, a);
	if (d < 1 || d > 31 || m < 1 || m > 12 || a < 0)
		throw DataInvalida(d,m,a);
  dia = d;
  mes = m;
  ano = a;
}

int Data::getAno() const{
	return ano;
}

int Data::getMes() const{
	return mes;
}

int Data::getDia() const{
	return dia;
}

bool Data::operator<(const Data&d) const{
	if (ano == d.ano){
		if (mes == d.mes){
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

std::ostream & operator<<(std::ostream & out, const Data & d){
	out << d.getDia() << " / " << d.getMes() << " / " << d.getAno();
	return out;
}

bool Data::operator==(const Data&d) const{
	return (ano == d.getAno() && mes == d.getMes() && dia == d.getDia());
}

/************************************
 *	    	CLASSE HORA NOVA		*
 ***********************************/
/*

HoraNova::HoraNova(){
	t = 0;
};

HoraNova::HoraNova(time_t time1){
	t = time1;
}

void HoraNova::setHoraNova(time_t time1){
	t = time(0);
}

time_t HoraNova::getHoraNova() {
  return t;
}

const string HoraNova::getHoraNovaCompleta(){
	time_t now=t;
	struct tm tstruct;
	char buf[80];
	tstruct=*localtime(&now);
	strftime(buf,sizeof(buf), "%Y-%m-%d.%X",&tstruct);
	return buf;
}

const string HoraNova::getHoraNovaHoras(){
	time_t now=t;
	struct tm tstruct;
	char buf[80];
	tstruct=*localtime(&now);
	strftime(buf,sizeof(buf), "%X",&tstruct);
	return buf;
}

const string HoraNova::getHoraNovaData(){
	time_t now=t;
	struct tm tstruct;
	char buf[80];
	tstruct=*localtime(&now);
	strftime(buf,sizeof(buf), "%Y-%m-%d",&tstruct);
	return buf;
}

ostream & operator<<(std::ostream & out, const HoraNova & t){
	out << t;
	return out;
}
*/
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

void menuInicial(){
  header("WHATS APL");
  cout << "LOGIN (1)" << endl;
  cout << "REGISTAR (2)" << endl;
  cout << "COMUNIDADE (3)" << endl;
  cout << "INFORMAÇOES (4)" << endl;
  cout << "SAIR (5)" << endl << endl;
}

void menuLogin() {
  header("LOGIN");
  cout << "Fazer Login (1)" << endl;
  cout << "Voltar Atras (2)" << endl << endl;
}

void menuRegistar() {
  header("REGISTAR");
  cout << "Registar (1)" << endl;
  cout << "Voltar Atras (2)" << endl << endl;
}

void menuComunidade() {
  header("COMUNIDADE");
  cout << "Ordenar por:" << endl;
  cout << "Login (1)" << endl;
  cout << "Data (2)" << endl << endl;
  cout << "Voltar Atras (3)" << endl << endl;
}

void menuUtilizador() {
  header("UTILIZADOR");
  cout << "Perfil (1)" << endl;
  cout << "Amigos (2)" << endl;
  cout << "Conversas (3)" << endl;
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
