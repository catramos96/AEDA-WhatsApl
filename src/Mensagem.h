/** @ \file Mensagem.h
 * header file que contém a classe Mensagem
 */
#ifndef SRC_MENSAGEM_H_
#define SRC_MENSAGEM_H_

#include <iostream>
#include <vector>
#include "System.h"
#include "Utilizador.h"

using namespace std;

class Mensagem
{

private:
	string tipo; //texto, imagem, video...
	Data data;
	Horas hora;
	string n_emissor;
	vector<string> destinatarios;
public:
	Mensagem(string tipo, Data data, Horas hora, string n_emissor, vector<string> destinatarios);
	virtual void imprimirSms(); //imprime todos os membros private
	string getTipo() const;
	Data getData() const;
	Horas getHora() const;
	string getEmissor() const;
	vector<string> getDestinatarios() const;
	friend ostream & operator<<(ostream &out,const Mensagem &m);
};


class msgTexto : public Mensagem
{
	//friend ostream & operator<<(ostream & out, const msgTexto &mt);
private:
	string conteudo;
public:
	void imprimirSms();

};


/*
 * Não é preciso porque já temos a classe grupo, que atualiza as conversas de
 * cada membro do chat
 */

/*
class MensagemGrupo : public Mensagem {
private:
	Grupo destinatario;
public:
	MensagemGrupo(string tipo, Data data, Horas hora, Utilizador emissor, Utilizador destinatario);
	void imprimirSms();
};
*/

/*
class MensagemUtil : public Mensagem {
private:
	Utilizador destinatario;
public:
	MensagemUtil(string tipo, Data data, Horas hora, Utilizador emissor, Utilizador destinatario);
	void imprimirSms();
};
*/
#endif /* SRC_MENSAGEM_H_ */
