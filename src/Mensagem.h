#ifndef SRC_MENSAGEM_H_
#define SRC_MENSAGEM_H_
#include <iostream>
#include "System.h"
#include "Utilizador.h"
#include "Grupo.h"
#include "Conversa.h"
#include "System.h"

using namespace std;

class Mensagem
{
private:
	string tipo; //texto, imagem, video...
	Data data;
	Horas hora;
	Utilizador emissor;
public:
	Mensagem(string tipo, Data data, Horas hora, Utilizador emissor);
	virtual void imprimirSms() = 0; //imprime todos os membros private
};

class MensagemGrupo {
	Grupo destinatario;
public:
	MensagemGrupo(string tipo, Data data, Horas hora, Utilizador emissor, Utilizador destinatario);
	void imprimirSms();
};

class MensagemUtil {
	Utilizador destinatario;
public:
	MensagemUtil(string tipo, Data data, Horas hora, Utilizador emissor, Utilizador destinatario);
	void imprimirSms();
};

#endif /* SRC_MENSAGEM_H_ */
