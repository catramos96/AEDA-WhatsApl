#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

/**
 * @brief Classe Horas.
 * Classe que indica as horas (hora e minuto) ao utilizador.
 * E possivel modificar as horas.
 */
class Horas
{
private:
	int hora, /**<  membro privado que representa a hora */
		min; /**<  membro privado que representa os minutos*/
public:
	/**
	 * @brief Classe HoraInvalida.
	 * E uma classe que indica uma execao da classe Horas.
	 */
	class HoraInvalida{};
	/**
	 * @brief Constutor
	 * Construtor default que inicializa as horas e os minutos a zero
	 */
	Horas();
	/**
	 * @brief Construtor
	 * Construtor que inicializa os membros hora e minutos com os valores introduzidos pelo utilizador
	 */
	Horas(int h,int m);
	/**
	 * @ brief Funcao que permite o utilizador alterar as horas e os minutos atuais com verificacoes de input.
	 * @ param h : representa a hora
	 * @ param min : representa os minutos
	 * @ return void
	 */
	void setHoras(int h,int min);
	/**
	 * @brief Funcao que retorna as horas atuais.
	 * @return hora atual
	 */
	int getHora() const;
	/**
	 * @brief Funcao que retorna os minutos atuais
	 * @return minutos
	 */
	int getMinutos() const;
	/**
	 * @brief Funcao friend: funcao que acede aos membros privados da classe.
	 * operator<< permite imprimir no ecra o objeto Horas
	 * @param out output
	 * @param h objeto Horas
	 * @return out
	 */
	friend ostream & operator<<(ostream & out, const Horas & h);
};

/**
 * @brief Classe Data.
 * Classe que indica as data (dia mes e ano) ao utilizador.
 * E possivel modificar a data
 */
class Data
{
private:
	int dia,
		mes,
		ano;
public:

	/**
	 * @brief Classe DataInvalida.
	 * E uma classe que indica uma execao da classe Data.
	 */
	class DataInvalida{};
	/**
	 * @brief Constutor
	 * Construtor default que inicializa o dia mes e ano a zero
	 */
	Data();
	/**
	 * @brief Construtor
	 * inicializa o dia, mes e ano com os dados que o utilizador insere
	 */
	Data(int d,int m,int a);
	/**
	 * @brief Funcao que permite o utilizador alterar o dia mes e ano atuais com verificações de input.
	 * @ param d : representa o dia
	 * @ param m : representa o mes
	 * @ param a : represnta o ano
	 * @return void
	 */
	void setData(int d, int m, int a);
	/**
	 * @brief Funcao que retorna o dia atual.
	 * @return dia atual
	 */
	int getDia() const;
	/**
	 * @brief Funcao que retorna o mes atual
	 * @return mes atual
	 */
	int getMes() const;
	/**
	 * @brief Funcao que retorna o ano atual
	 * @return ano atual
	 */
	int getAno() const;
	/**
	 *
	 */
	bool operator<(const Data&d) const;
	/**
	 * @brief Funcao friend: funcao que acede aos membros privados da classe.
	 * operator<< permite imprimir no ecra o objeto Data
	 * @param out output
	 * @param d objeto Data
	 * @return out
	 */
	friend ostream & operator<<(ostream & out, const Data & d);
};

class HoraNova{
private:
	time_t t;
public:
	HoraNova();
	HoraNova(time_t time1);
	void setHoraNova(time_t time1);
	time_t getHoraNova();
};

#endif /* SRC_SYSTEM_H_ */
