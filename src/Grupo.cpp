#include "Grupo.h"
#include "Templates.h"
#include <sstream>

/* Classe Membro */

Membro::Membro(Utilizador util, Data adesaoGrupo){
	this->util = util;
	this->adesaoGrupo = adesaoGrupo;
	bloqueado = false;
}

Utilizador Membro::getUtilizador() const{
	return util;
}

Data Membro::getData() const{
	return adesaoGrupo;
}

void Membro::setData(Data d){
	adesaoGrupo = d;
}

void Membro::setBloqueio(bool bloq){
	bloqueado = bloq;
}

bool Membro::isBloqueado() const{
	return bloqueado;
}

bool Membro::operator<(const Membro &m) const{
	return (util.getNome() < m.util.getNome());
}

/* Classe Grupo*/

Grupo::Grupo(string titulo,Data criacao, Utilizador moderador){
	this->titulo = titulo;
	this->criacao = criacao;
	this->moderador = moderador;
	status.push_back("Historico : \n\n");
}

int Grupo::numMembros() const{
	return membros.size();
}

bool Grupo::isModerador(Utilizador u){
	return (u == moderador);
}

int Grupo::existeMembro(Membro *m){
	return BinarySearch(membros, m);
}

Membro *Grupo::membroNaPosicao(int pos){
	return membros.at(pos);
}

bool Grupo::pedidoAdesao(Utilizador u, Data adesao, Utilizador moderador, bool aceita){

	stringstream out;

	if (isModerador(moderador)){
		if (aceita == true){
			Data d;
			Membro *m = new Membro(u, d);
			int pos = existeMembro(m);
			if (existeMembro(m) != -1){ // já existe o membro
				m = membroNaPosicao(pos);

				if (m->isBloqueado()){ //desbloqueia caso esteja bloqueado
					m->setBloqueio(true); //coloca como bloqueado
					out << "Membro desbloqueado : " << u.getNome() << endl << "Data : " << adesao << endl << endl;
					status.push_back(out.str());
					return true;
				}
			}
			else{ // novo membro
				Membro *novo = new Membro(u, adesao);
				membros.push_back(novo);
				out << "Novo membro : " << u.getNome() << endl << "Data : " << adesao << endl << endl;
				status.push_back(out.str());
				return true;
			}
		}
		else
			return false;
	}
	else
		throw Grupo::NaoModerador(moderador);
}

void Grupo::bloquearMembro(Utilizador u, Utilizador moderador, Data diaAtual){

	vector<Membro *>::iterator it;
	stringstream out;

	if (isModerador(moderador)){

		for (it = membros.begin(); it != membros.end(); it++){
			if (existeMembro(*it)){ //encontra o utilizador

				if ((*it)->isBloqueado() == false){

					(*it)->setBloqueio(true); //coloca como bloqueado

					out << "Membro bloqueado : " << u.getNome() << endl << "Data : " << diaAtual << endl << endl;
					status.push_back(out.str());
				}
				else
					throw Grupo::MembroJaBloqueado(u);
			}
			else
				throw Grupo::UtilizadorInexistente(u);
		}	
	}
	else
		throw Grupo::NaoModerador(moderador);
}

void Grupo::retiraMembro(Utilizador u, Utilizador moderador, Data diaAtual){

	vector<Membro *>::iterator it;
	stringstream out;

	if (isModerador(moderador)){

		for (it = membros.begin(); it != membros.end(); it++){
			if (existeMembro(*it)){ //encontra o utilizador

				membros.erase(it);
				it--;

				out << "Membro eliminado : " << u.getNome() << endl << "Data : " << diaAtual << endl << endl;
				status.push_back(out.str());
				
			}
			else
				throw Grupo::UtilizadorInexistente(u);
		}
	}
	else
		throw Grupo::NaoModerador(moderador);
}

void Grupo::desbloquearMembro(Utilizador u, Utilizador moderador, Data diaAtual){

	vector<Membro *>::iterator it;
	stringstream out;

	if (isModerador(moderador)){

		for (it = membros.begin(); it != membros.end(); it++){
			if (existeMembro(*it)){ //encontra o utilizador

				if ((*it)->isBloqueado()){

					(*it)->setBloqueio(false); //coloca como desbloqueado

					out << "Membro desbloqueado : " << u.getNome() << endl << "Data : " << diaAtual << endl << endl;
					status.push_back(out.str());
				}
			}
			else
				throw Grupo::UtilizadorInexistente(u);
		}
	}
	else
		throw Grupo::NaoModerador(moderador);
}
