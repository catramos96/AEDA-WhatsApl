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

struct membro{
	Utilizador util;
	Data adesaoGrupo;
};

class Grupo {
private:
	string titulo;
	vector <membro *> membros;
	Data criacao;
	Utilizador moderador;
	// algo para registar o bloqueio ou desbloqueio de um membro
public:
	Grupo(string titulo,Data criacao, Utilizador Moderador);
	int numMembros() const;
	bool isModerador(Utilizador u);
	bool pedidoAdesao(Utilizador u, Data adesao, bool aceita);
	bool bloquearMembro(Utilizador u);
};

#endif /* SRC_GRUPO_H_ */
