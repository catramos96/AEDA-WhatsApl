#include "Grupo.h"
#include "Templates.h"

#include <sstream>

/* Classe Membro */
/*
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

bool Membro::operator==(const Membro &m) const{
	return (util == m.util);
}

ostream & operator<<(ostream & out, const Membro & m){
	out << m.getUtilizador() << " , data de adesao : " << m.getData();
	if (m.isBloqueado())
		out << ", estado : bloqueado " << endl;
	else
		out << ", estado : desbloqueado " << endl;
	return out;
}

/* Classe Grupo*/

/*
Grupo::Grupo(string titulo, Data criacao, Utilizador moderador){
	stringstream out;
	this->titulo = titulo;
	this->criacao = criacao;
	this->moderador = moderador;
	Membro *mod = new Membro(moderador, criacao);
	membros.push_back(mod);
	out << " HISTORICO: \n" << "Grupo " << titulo << " criado no dia " << criacao << endl << "Moderador : " << *mod << endl;
	status.push_back(out.str());
}

int Grupo::numMembros() const{
	return membros.size();
}

bool Grupo::isModerador(Utilizador u){
	return (u == moderador);
}

int Grupo::existeMembro(Membro *m){
	return sequentialSearch(membros, m);
}

Membro *Grupo::membroNaPosicao(int pos){
	return membros.at(pos);
}

void Grupo::printStatus() const{
	for (unsigned int i = 0; i < status.size(); i++)
		cout << status.at(i) << endl;
}

void Grupo::printMembros() const{
	for (int i = 0; i < numMembros(); i++)
		cout << i + 1 << endl << "    " << *membros.at(i) << endl;
	cout << endl;
}

bool Grupo::pedidoAdesao(Utilizador u, Utilizador moderador, Data adesao, bool aceita){

	stringstream out;

	if (isModerador(moderador)){

		if (aceita == true){
			Data d;
			Membro *m = new Membro(u, d);
			int pos = existeMembro(m);
			if (pos != -1){ // já existe o membro
				m = membroNaPosicao(pos);

				if (m->isBloqueado()){ //desbloqueia caso esteja bloqueado
					m->setBloqueio(false); //coloca como bloqueado
					out << "Membro desbloqueado : " << u.getNome() << endl << "Data : " << adesao << endl;
					status.push_back(out.str());
					return true;
				}
				else
					return false;
			}
			else{ // novo membro
				Membro *novo = new Membro(u, adesao);
				membros.push_back(novo);
				out << "Novo membro : " << u.getNome() << endl << "Data : " << adesao << endl;
				status.push_back(out.str());
				return true;
			}
		}
		else
			return false;
	}
	else
		throw NaoModerador(moderador);
	return false;
}

bool Grupo::bloquearMembro(Utilizador u, Utilizador moderador, Data diaAtual){

	stringstream out;
	Data d;
	Membro *temp = new Membro(u, d);
	int pos = existeMembro(temp);

	if (isModerador(moderador)){

		if (pos != -1){ //encontra o membro
			temp = membroNaPosicao(pos); //coloca os valores corretos do membro
			if (temp->isBloqueado() == false){
				temp->setBloqueio(true); //coloca como bloqueado
				out << "Membro bloqueado : " << u.getNome() << endl << "Data : " << diaAtual << endl << endl;
				status.push_back(out.str());
				return true;
			}
			else
				return false;
		}
		else
			throw UtilizadorInexistente(u);
	}
	else
		throw NaoModerador(moderador);
}

bool Grupo::retiraMembro(Utilizador u, Utilizador moderador, Data diaAtual){

	stringstream out;
	Data d;
	Membro *temp = new Membro(u, d);
	int pos = existeMembro(temp);

	if (isModerador(moderador)){
		if (existeMembro(temp) != -1){ //encontra o utilizador
			membros.erase(membros.begin() + pos);
			out << "Membro eliminado : " << u.getNome() << endl << "Data : " << diaAtual << endl << endl;
			status.push_back(out.str());
			return true;
		}
		else
			throw UtilizadorInexistente(u);
	}
	else if (!isModerador(moderador))
		throw NaoModerador(moderador);
	else
		return false;
}

bool Grupo::desbloquearMembro(Utilizador u, Utilizador moderador, Data diaAtual){

	stringstream out;
	Data d;
	Membro *temp = new Membro(u, d);
	int pos = existeMembro(temp);

	if (isModerador(moderador)){

		if (pos != -1){ //encontra o utilizador
			temp = membroNaPosicao(pos); //coloca os valores corretos do membro
			if (temp->isBloqueado() == true){
				temp->setBloqueio(false); //coloca como desbloqueado
				out << "Membro desbloqueado : " << u.getNome() << endl << "Data : " << diaAtual << endl << endl;
				status.push_back(out.str());
				return true;
			}
			else
				return false;
		}
		else
			throw UtilizadorInexistente(u);
	}
	else
		throw NaoModerador(moderador);
}
*/