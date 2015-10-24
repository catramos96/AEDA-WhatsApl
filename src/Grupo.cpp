#include "Grupo.h"

/* Classe Grupo*/

Grupo::Grupo(string titulo, Data criacao, Utilizador moderador){
	this->titulo = titulo;
	this->criacao = criacao;
	this->moderador = moderador;
	membros.clear();
}

int Grupo::numMembros() const{
	return membros.size();
}
/*
bool Moderador::pedidoAdesao(Utilizador u, int dia_ad, int mes_ad,int ano_ad, bool aceita){

	if(aceita == true){
		Data ad;
		ad.setData(dia_ad,mes_ad,ano_ad);
		membro novo;
		novo.util = u;
		novo.adesaoGrupo = ad;
		//experimentar usar o new
		//membros.push_back(mod);
		return true;
	}
	else
		return false;
}
*/
