#include <iostream>

#include "System.h"
#include "Utilizador.h"
#include "Comunidade.h"
#include "Comunidade.h"
#include "Grupo.h"
#include "Mensagem.h"

using namespace std;


/*
void thisIsATest() {
	ASSERTM("start writing tests", false);	
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
*/

int main()
{
	try{
		Data data;
		int d, m, a;
		cout << "Dia, mes, ano ";
		cin >> d >> m >> a;
		data.setData(d, m, a);
		cout << data << endl;

		Horas hora;
		int h, min;
		cout << "Hora, minutos";
		cin >> h >> min;
		hora.setHoras(h, min);
		cout << hora << endl;
	}
	catch(Data::DataInvalida){
		cout << "Data Invalida!" << endl;
	}
	catch (Horas::HoraInvalida){
		cout << "Hora Invalida!" << endl;
	}
	/*
	try{

	}
	catch(){

	}
	*/
	return 0;
}
