#ifndef SRC_COMUNIDADE_H_
#define SRC_COMUNIDADE_H_
#include "System.h"
#include "Utilizador.h"
#include <vector>


class Comunidade
{
private:
	vector <Utilizador> comunidade;
public:
	Comunidade();
	void adicionarUtil(Utilizador utilizador);
};


#endif /* SRC_COMUNIDADE_H_ */
