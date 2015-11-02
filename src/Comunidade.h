#ifndef SRC_COMUNIDADE_H_
#define SRC_COMUNIDADE_H_

#include "Utilizador.h"
#include <vector>

using namespace std;

class Comunidade
{
private:
	vector<Utilizador*> comunidade;
public:
	Comunidade();
	int existeUtil(Utilizador *util) const;
  bool existeLogin(string l) const;
	Utilizador *utilizadorNaPosicao(int pos) const;
	void adicionarUtil(Utilizador *util);
	void ordenaData();
	void ordenaLogin();
	void verUtilizador(Utilizador *util) const;
	void printComunidade() const;
};

#endif /* SRC_COMUNIDADE_H_ */
