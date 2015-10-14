#ifndef SRC_GRUPO_H_
#define SRC_GRUPO_H_

#include <iostream>
#include "Conversa.h"
#include "Utilizador.h"


struct membro{
	Utilizador util;
	Data adesaoGrupo;
};

class Grupo {
	string titulo;
	vector <membro> membros;
	Data criacao;

public:
	Grupo(string titulo, Data criacao);
};

class Moderador : public Grupo{
	Utilizador moderador;
	Data adesao;
public:
	Moderador(Utilizador moderador, Data adesao, string titulo, Data criacao); //não esquecer: colocar no vetor membros
	bool pedidoAdesao(Utilizador u, Data adesao);
	bool bloquearMembro(Utilizador u);

};

#endif /* SRC_GRUPO_H_ */
