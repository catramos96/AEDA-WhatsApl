#ifndef SRC_COMUNIDADE_H_
#define SRC_COMUNIDADE_H_

#include "Utilizador.h"
#include <vector>

using namespace std;

class Comunidade
{
private:
	vector<Utilizador *> comunidade;
public:
	Comunidade();
	void adicionarUtil(Utilizador *utilizador);
};

#endif /* SRC_COMUNIDADE_H_ */
