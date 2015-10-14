#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_
#include <iostream>
#include <string>
#include "Conversa.h"
#include <vector>

using namespace std;

class Utilizador
{
private:
	string login,nome,email;
	int telemovel;
	Data dataAdesao;
	vector<Conversa> conversas;
public:
	Utilizador(string login, string nome, string email, int telemovel, Data dataAdesao);
	//...
};


#endif /* SRC_UTILIZADOR_H_ */
