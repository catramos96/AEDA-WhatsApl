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
 * @brief Classe Horas.
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
	 * @brief Classe HoraInvalida.
	 * É uma classe que indica uma exeção da classe Horas.
	 */
	class HoraInvalida{};
	/**
	 * @brief Constutor
	 * Construtor default que inicializa as horas e os minutos a zero
	 */
	Horas();
	/**
	 * @ brief Função que permite o utilizador alterar as horas e os minutos atuais com verificações de input.
	 * @ param h : representa a hora
	 * @ param min : representa os minutos
	 * @ return void
	 */
	void setHoras(int h,int min);
	/**
	 * @brief Função que retorna as horas atuais.
	 * @return hora atual
	 */
	int getHora() const;
	/**
	 * @brief Função que retorna os minutos atuais
	 * @return minutos
	 */
	int getMinutos() const;
	/**
	 * @brief Função friend: função que acede aos membros privados da classe.
	 * operator<< permite imprimir no ecrã o objeto Horas
	 * @param out output
	 * @param h objeto Horas
	 * @return out
	 */
	friend ostream & operator<<(ostream & out, const Horas & h);
};

/**
 * @brief Classe Data.
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
	 * @brief Classe DataInvalida.
	 * É uma classe que indica uma exeção da classe Data.
	 */
	class DataInvalida{};
	/**
	 * @brief Constutor
	 * Construtor default que inicializa o dia mes e ano a zero
	 */
	Data();
	/**
	 * @brief Função que permite o utilizador alterar o dia mês e ano atuais com verificações de input.
	 * @ param d : representa o dia
	 * @ param m : representa o mes
	 * @ param a : represnta o ano
	 * @return void
	 */
	void setData(int d, int m, int a);
	/**
	 * @brief Função que retorna o dia atual.
	 * @return dia atual
	 */
	int getDia() const;
	/**
	 * @brief Função que retorna o mês atual
	 * @return mês atual
	 */
	int getMes() const;
	/**
	 * @brief Função que retorna o ano atual
	 * @return ano atual
	 */
	int getAno() const;
	/**
	 * @brief Função friend: função que acede aos membros privados da classe.
	 * operator<< permite imprimir no ecrã o objeto Data
	 * @param out output
	 * @param d objeto Data
	 * @return out
	 */
	friend ostream & operator<<(ostream & out, const Data & d);
};

#endif /* SRC_SYSTEM_H_ */
