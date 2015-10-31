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

		//--------------------//

		Data d(1, 1, 1);
		Utilizador Ana(false, "ana123", "Ana", "ana@kdsf.com", d, 123456);
		Data d1(4, 5, 6);
		Utilizador Rui(false, "Rui1234", "Rui", "rui@bgd.com", d1, 4455);
		Data d2(2, 3, 4);
		Utilizador Sofia(false, "Sofia12345", "Sofia", "sofia@dsjh.com", d2, 7878);
		Data d3(3, 4, 6);
		Utilizador Carlos(false, "456", "Carlos", "carlos.eedsnh.com", d3, 456456);

		Grupo fixes("fixes", d, Ana);

		fixes.pedidoAdesao(Rui, Ana, d1, true);
		//fixes.pedidoAdesao(Sofia, d2, Ana, false);
		fixes.pedidoAdesao(Sofia, Ana, d2, true);
		//fixes.pedidoAdesao(Carlos, d3, Rui, true); //nao é moderador
		Data d4(7, 8, 9);
		fixes.bloquearMembro(Rui, Ana, d4); //ver se está bloqueado
		//fixes.bloquearMembro(Ana, Sofia, d4); // nao é moderador
		//fixes.bloquearMembro(Carlos, Ana, d4); // nao é utilizador
		Data d5(1, 2, 3);
		fixes.bloquearMembro(Rui, Ana, d5); //membro ja bloqueado
		fixes.pedidoAdesao(Rui, Ana, d5, true); // desbloquear membro por pedido
		Data d6(5, 7, 9);
		fixes.retiraMembro(Sofia, Ana, d6);
		//fixes.retiraMembro(Carlos, Ana, d6); //Membro Inexistente
		//fixes.retiraMembro(Ana, Rui, d6); //nao e moderador

		Data d7(1, 2, 3);
		fixes.bloquearMembro(Rui, Ana, d7);
		Data d8(3, 5, 7);
		fixes.desbloquearMembro(Rui, Ana, d8);
		fixes.printMembros();
		fixes.printStatus();
		//fixes.desbloquearMembro(Carlos, Ana, d8); //membro inexistente
		//fixes.desbloquearMembro(Ana, Rui, d8); // nao e moderador

	}
	catch (Data::DataInvalida &e){
		cout << "Data Invalida!" << endl;
	}
	catch (Horas::HoraInvalida &e){
		cout << "Hora Invalida!" << endl;
	}
	catch (NaoModerador &e){
		cout << "Utilizador " << e.getUtil() << " nao e moderador!" << endl;
	}
	/*
	catch(UtilizadorInexistente &e){
	cout << "Utilizador " << e.getLogin() << " nao existe!" << endl;
	}
	*/
	return 0;
}
