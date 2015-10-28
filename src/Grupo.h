/** @ \file Grupo.h
 * header file que contém a classe Grupo
 */

//testing git
#ifndef SRC_GRUPO_H_
#define SRC_GRUPO_H_

#include <iostream>
#include <string>

#include "System.h"
#include "Utilizador.h"

class Membro{
private:
	Utilizador util;
	Data adesaoGrupo;
	bool bloqueado;
public:
	Membro(Utilizador util, Data adesaoGrupo);
	Utilizador getUtilizador() const;
	Data getData() const;
	void setData(Data d);
	void setBloqueio(bool bloq);
	bool isBloqueado() const;
	bool operator<(const Membro &m) const;
};

class Grupo {
private:
	string titulo;
	vector <Membro *> membros;
	Data criacao;
	Utilizador moderador;
	vector<string> status; //registar a entrada, retirada , bloqueio ou desbloqueio de um membro
public:
	class NaoModerador{
	private:
		Utilizador mod;
	public:
		NaoModerador(Utilizador mod){
			this->mod = mod;
		};
		Utilizador getUtilizador() const{
			return mod;
		};
	};
	class UtilizadorInexistente{
	private:
		Utilizador util;
	public:
		UtilizadorInexistente(Utilizador u){
			util = u;
		};
		Utilizador getUtilizador() const{
			return util;
		};
	};
	class MembroJaBloqueado{
	private:
		Utilizador u;
	public:
		MembroJaBloqueado(Utilizador u){
			this->u = u;
		};
		Utilizador getUtilizador() const{
			return u;
		};
	};
	Grupo(string titulo,Data criacao, Utilizador Moderador);
	int numMembros() const;
	bool isModerador(Utilizador u);
	int existeMembro(Membro *m);
	Membro *membroNaPosicao(int pos);
	bool pedidoAdesao(Utilizador u, Data adesao, Utilizador moderador, bool aceita); //um utilizador que pede permissao pode ser novo ou bloqueado
	void retiraMembro(Utilizador u, Utilizador moderador, Data diaAtual);
	void bloquearMembro(Utilizador u, Utilizador moderador, Data diaAtual);
	void desbloquearMembro(Utilizador u, Utilizador moderador, Data diaAtual);
};

#endif /* SRC_GRUPO_H_ */
