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
#include "Comunidade.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Mensagem.h"


struct membro{
	Utilizador *util;
	Data adesaoGrupo;
};

class Grupo {
private:
	string titulo;
	vector <membro *> membros;
	Data criacao;
public:
	Grupo(string titulo, Data criacao);
};

class Moderador : public Grupo{
private:
	Utilizador *moderador;
	Data adesao;
public:
	Moderador(Utilizador moderador, Data adesao, string titulo, Data criacao); //não esquecer: colocar no vetor membros
	bool pedidoAdesao(Utilizador u, Data adesao);
	bool bloquearMembro(Utilizador u);

};

#endif /* SRC_GRUPO_H_ */
