#include "System.h"
#include "Utilizador.h"
#include "COmunidade.h"
#include <iostream>
#include <string>
#include <vector>

Comunidade::Comunidade(){
	comunidade.clear();
}

void Comunidade::adicionarUtil(Utilizador utilizador){
	comunidade.push_back(utilizador);
}


