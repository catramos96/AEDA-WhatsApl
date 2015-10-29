#include <iostream>

#include "System.h"
#include "Utilizador.h"
#include "Comunidade.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Mensagem.h"

using namespace std;

int main(){

	try{	
		/*
		Data data;
		int dia, m, a;
		cout << "Dia, mes, ano ";
		cin >> dia >> m >> a;
		data.setData(dia, m, a);
		cout << data << endl;

		Horas hora;
		int h, min;
		cout << "Hora, minutos";
		cin >> h >> min;
		hora.setHoras(h, min);
		cout << hora << endl;
		*/
		//--------------------//
		
		Data d(1, 1, 1);
		Utilizador Ana("123", "Ana", "ana@kdsf.com", d);
		Data d1(4,5,6);
		Utilizador Rui("1234", "Rui", "rui@bgd.com", d1);
		Data d2(2,3,4);
		Utilizador Sofia("12345", "Sofia", "sofia@dsjh.com", d2);
		Data d3(3,4,6);
		Utilizador Carlos("456", "Carlos", "carlos.eedsnh.com", d3);

		Grupo fixes("fixes",d,Ana);
		
		fixes.pedidoAdesao(Rui, d1, Ana, true);
		//fixes.pedidoAdesao(Sofia, d2, Ana, false);
		fixes.pedidoAdesao(Sofia, d2, Ana, true);
		//fixes.pedidoAdesao(Carlos, d3, Rui, true); //nao é moderador
		Data d4(7,8,9);
		fixes.bloquearMembro(Rui, Ana, d4); //ver se está bloqueado
		//fixes.bloquearMembro(Ana, Sofia, d4); // nao é moderador
		//fixes.bloquearMembro(Carlos, Ana, d4); // nao é utilizador
		Data d5(1,2,3);
		//fixes.bloquearMembro(Rui, Ana, d5); //membro ja bloqueado
		fixes.pedidoAdesao(Rui, d5, Ana, true); // desbloquear membro por pedido
		Data d6(5,7,9);
		fixes.retiraMembro(Sofia, Ana, d6);
		//fixes.retiraMembro(Carlos, Ana, d6); //Membro Inexistente
		//fixes.retiraMembro(Ana, Rui, d6); //nao e moderador

		Data d7(1,2,3);
		fixes.bloquearMembro(Rui, Ana, d7);
		Data d8(3,5,7);
		fixes.desbloquearMembro(Rui, Ana, d8);
		fixes.printMembros();
		fixes.printStatus();
		//fixes.desbloquearMembro(Carlos, Ana, d8); //membro inexistente
		//fixes.desbloquearMembro(Ana, Rui, d8); // nao e moderador
	
	}
	catch(Data::DataInvalida &e){
		cout << "Data Invalida!" << endl;
	}
	catch (Horas::HoraInvalida &e){
		cout << "Hora Invalida!" << endl;
	}
	catch(Grupo::NaoModerador &e){
		cout << "Utilizador " << e.getUtilizador() << " nao e moderador!" << endl;
	}
	catch(Grupo::UtilizadorInexistente &e){
		cout << "Utilizador " << e.getUtilizador() << " nao existe!" << endl;
	}
	catch(Grupo::MembroJaBloqueado &e){
		cout << "Utilizador " << e.getUtilizador() << " ja se encontra bloqueado!" << endl;
	}

	return 0;
}
