/** @ \file System.h
 * header file que contém a classe System
 */
#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Classe Horas.
 * Classe que indica as horas (hora e minuto) ao utilizador.
 * É possivel modificar as horas.
 */
class Horas
{
private:
	int hora, /**<  membro privado que representa a hora */
		min; /**<  membro privado que representa os minutos*/
public:
	/**
	 * Classe HoraInvalida.
	 * É uma classe que indica uma exeção da classe Horas.
	 */
	class HoraInvalida{};
	/**
	 * Constutor
	 * Construtor default que inicializa as horas e os minutos a zero
	 */
	Horas();
	/**
	 * Função que permite o utilizador alterar as horas e os minutos atuais com verificações de input.
	 * @ param h : representa a hora
	 * @ param min : representa os minutos
	 * @return void
	 */
	Horas(int h,int m);
	void setHoras(int h,int min);
	/**
	 * Função que retorna as horas atuais.
	 * @return hora atual
	 */
	int getHora() const;
	/**
	 * Função que retorna os minutos atuais
	 * @return minutos
	 */
	int getMinutos() const;
	/**
	 * Função friend: função que acede aos membros privados da classe.
	 * operator<< permite imprimir no ecrã o objeto Horas
	 * @param out output
	 * @param h objeto Horas
	 * @return out
	 */

	friend ostream & operator<<(ostream & out, const Horas & h);

};

/**
 * Classe Data.
 * Classe que indica as data (dia mês e ano) ao utilizador.
 * É possivel modificar a data
 */
class Data
{
private:
	int dia, /**< membro provado que representa o dia */
		mes, /**< membro provado que representa o mes */
		ano; /**< membro provado que representa o ano */
public:
	/**
	 * Classe DataInvalida.
	 * É uma classe que indica uma exeção da classe Data.
	 */
	class DataInvalida{};
	/**
	 * Constutor
	 * Construtor default que inicializa o dia mes e ano a zero
	 */
	Data();
	/**
	 * Função que permite o utilizador alterar o dia mês e ano atuais com verificações de input.
	 * @ param d : representa o dia
	 * @ param m : representa o mes
	 * @ param a : represnta o ano
	 * @return void
	 */

	Data(int d,int m,int a);
	void setData(int d, int m, int a);
	/**
	 * Função que retorna o dia atual.
	 * @return dia atual
	 */
	int getDia() const;
	/**
	 * Função que retorna o mês atual
	 * @return mês atual
	 */
	int getMes() const;
	/**
	 * Função que retorna o ano atual
	 * @return ano atual
	 */
	int getAno() const;
	/**
	 * Função friend: função que acede aos membros privados da classe.
	 * operator<< permite imprimir no ecrã o objeto Data
	 * @param out output
	 * @param d objeto Data
	 * @return out
	 */
	friend ostream & operator<<(ostream & out, const Data & d);
};

#endif /* SRC_SYSTEM_H_ */
