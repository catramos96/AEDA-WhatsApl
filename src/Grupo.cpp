#include "Grupo.h"
#include "Templates.h"
#include <algorithm>
#include <sstream>

/* Classe Membro */

Membro::Membro(){

}

Membro::Membro(string login, Data adesaoGrupo){
	this->login = login;
	this->adesaoGrupo = adesaoGrupo;
	bloqueado = false;
}

string Membro::getLogin() const{
	return login;
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
	return (login == m.login);
}

ostream & operator<<(ostream & out, const Membro & m){
	out << m.getLogin() << " , data de adesao : " << m.getData();
	if (m.isBloqueado())
		out << ", estado : bloqueado " << endl;
	else
		out << ", estado : desbloqueado " << endl;
	return out;
}

/* Classe Grupo*/

Grupo::Grupo(string titulo, Data criacao, string moderador){
	stringstream out;
	this->titulo = titulo;
	this->criacao = criacao;
	Membro mod(moderador, criacao);
	this->moderador = mod;
	conversa.adicionaParticipante(moderador);
	membros.push_back(mod);
	out << " HISTORICO: \n" << "Grupo " << titulo << " criado no dia " << criacao << endl << "Moderador : " << moderador << endl;
	status.push_back(out.str());
}

int Grupo::numMembros() const{
	return membros.size();
}

bool Grupo::isModerador(Membro m){
	return (m == moderador);
}

int Grupo::existeMembro(Membro m){
	return sequentialSearch(membros, m);
}

Membro Grupo::membroNaPosicao(int pos){
	return membros.at(pos);
}

void Grupo::printStatus() const{
	for (unsigned int i = 0; i < status.size(); i++)
		cout << status.at(i) << endl;
}

void Grupo::printMembros() const{
	for (int i = 0; i < numMembros(); i++)
		cout << i + 1 << endl << "    " << membros.at(i) << endl;
	cout << endl;
}

bool Grupo::pedidoAdesao(string novo, Membro moderador, Data adesao, bool aceita){

	stringstream out;

	if (isModerador(moderador)){

		if (aceita == true){
			//primeiro passo: criar um membro temporario com a informacao que conhecemos (login)
			Data d;
			Membro m(novo, d);
			int pos = existeMembro(m);
			if (pos != -1){ // já existe o membro
				m = membroNaPosicao(pos);

				if (m.isBloqueado()){ //desbloqueia caso esteja bloqueado
					m.setBloqueio(false); //coloca como bloqueado
					out << "Membro desbloqueado : " << novo << endl << "Data : " << adesao << endl;
					status.push_back(out.str());
					return true;
				}
				else
					return false;
			}
			else{ // novo membro
				Membro m(novo, adesao);
				membros.push_back(m);
				conversa.adicionaParticipante(novo);
				out << "Novo membro : " << novo << endl << "Data : " << adesao << endl;
				status.push_back(out.str());
				return true;
			}
		}
		else
			return false;
	}
	else
		throw;// NaoModerador(moderador);
	return false;
}

bool Grupo::bloquearMembro(string login, Membro moderador, Data diaAtual){

	stringstream out;
	Data d;
	Membro temp(login, d);
	int pos = existeMembro(temp);

	if (isModerador(moderador)){

		if (pos != -1){ //encontra o membro
			temp = membroNaPosicao(pos); //coloca os valores corretos do membro
			if (temp.isBloqueado() == false){
				temp.setBloqueio(true); //coloca como bloqueado
				out << "Membro bloqueado : " << login << endl << "Data : " << diaAtual << endl << endl;
				status.push_back(out.str());
				return true;
			}
			else
				return false;
		}
		else
			throw;// UtilizadorInexistente(nome);
	}
	else
		throw; // NaoModerador(moderador);
}

bool Grupo::retiraMembro(string login, Membro moderador, Data diaAtual){

	stringstream out;
	Data d;
	Membro temp(login, d);
	int pos = existeMembro(temp);

	if (isModerador(moderador)){
		if (existeMembro(temp) != -1){ //encontra o utilizador
			membros.erase(membros.begin() + pos);
			conversa.removeParticipante(login);
			out << "Membro eliminado : " << login << endl << "Data : " << diaAtual << endl << endl;
			status.push_back(out.str());
			return true;
		}
		else
			throw; // UtilizadorInexistente(u);
	}
	else if (!isModerador(moderador))
		throw;// NaoModerador(moderador);
	else
		return false;
}

bool Grupo::desbloquearMembro(string login, Membro moderador, Data diaAtual){

	stringstream out;
	Data d;
	Membro temp(login, d);
	int pos = existeMembro(temp);

	if (isModerador(moderador)){

		if (pos != -1){ //encontra o utilizador
			temp = membroNaPosicao(pos); //coloca os valores corretos do membro
			if (temp.isBloqueado() == true){
				temp.setBloqueio(false); //coloca como desbloqueado
				out << "Membro desbloqueado : " << login << endl << "Data : " << diaAtual << endl << endl;
				status.push_back(out.str());
				return true;
			}
			else
				return false;
		}
		else
			throw; // UtilizadorInexistente(u);
	}
	else
		throw;// NaoModerador(moderador);
}

bool Grupo::enviarMensagem(string emissor, Mensagem sms){
	//corresponder um login a um membro
	Data d;
	Membro temp(emissor, d);
	int pos = existeMembro(temp);

	if (pos != -1) //utilizador existe
	{
		if (temp.isBloqueado())
			throw;// excecao que não deixa o utilizador enviar uma mensagem
		else
			conversa.adicionaSms(sms);
	}
	else
		throw; // acabar isto
}

bool comparaMembro(const Membro &m1, const Membro &m2){
	return (m1.getLogin() < m2.getLogin());
}

bool Grupo::operator==(const Grupo &g)const{ //compara 2 grupos pelos membros

	for (int i = 0; i < numMembros(); i++){
		if (g.membros.at(i) == membros.at(i))
			continue;		// experimentar isto
		else
			return false;
	}
}

/**
 * @brief Classe que representa uma excecao da classe grupo.
 * esta excecao e lancada no caso de o utilizador que esta a pedir permissoes nao ser o utilizador moderador
 */
class NaoModerador{
private:
	string mod;  /**<  membro privado que representa o utilizador que cria a excecao */
public:
	/**
	 * @brief Construtor
	 * inicializa o membro mod com o utilizador recebido
	 * @param mod utilizador recebido
	 */
	NaoModerador(string mod){
		this->mod = mod;
	};
	/**
	 * @brief Funcao que retorna o utilizador
	 * @return mod
	 */
	string getNome() const{
		return mod;
	};
};
