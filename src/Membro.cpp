#include <sstream>
#include "Membro.h"
#include "Templates.h"
#include "Excecoes.h"

/* Classe Membro */

Membro::Membro() {
	bloqueado = false;
}

Membro::Membro(string login, Data adesaoGrupo) {
	this->login = login;
	this->adesaoGrupo = adesaoGrupo;
	bloqueado = false;
}

string Membro::getLogin() const {
	return login;
}

Data Membro::getDataCriacao() const {
	return adesaoGrupo;
}

Data Membro::getDataBloqueio() const {
	return bloqueio;
}

void Membro::setLogin(string login) {
	this->login = login;
}

void Membro::setDataBloqueio(Data d) {
	bloqueio = d;
}

void Membro::setData(Data d) {
	adesaoGrupo = d;
}

void Membro::setBloqueio(bool bloq) {
	bloqueado = bloq;
}

bool Membro::isBloqueado() const {
	return bloqueado;
}

bool Membro::operator==(const Membro &m) const {
	return (login == m.login);
}

bool Membro::operator<(const Membro &m) const {
	return login < m.login;
}

ostream & operator<<(ostream & out, const Membro & m) {
	out << m.getLogin() << " , data de adesao : " << m.getDataCriacao();
	if (m.isBloqueado())
		out << ", estado : bloqueado " << endl;
	else
		out << ", estado : desbloqueado " << endl;
	return out;
}