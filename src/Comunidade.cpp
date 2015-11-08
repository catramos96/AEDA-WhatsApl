#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Comunidade.h"
#include "Templates.h"
#include "Excecoes.h"

/********************************
 *		CLASSE COMUNIDADE		*
 *******************************/
Comunidade::Comunidade() {
	comunidade.clear(); //inicializar o vetor
}

int Comunidade::existeUtil(Utilizador *util) const {
	for (unsigned int i = 0; i < comunidade.size(); i++) {
		if (*comunidade[i] == *util)
			return i;
	}
	return -1;
}

int Comunidade::existeUtilLogin(string login) const{
	for (unsigned int i = 0; i < comunidade.size(); i++) {
		if (comunidade[i]->getLogin() == login)
			return i;   // encontrou
	}
	return -1;     // nao encontrou
}

int Comunidade::existeUtilNome(string nome) const {
	for (unsigned int i = 0; i < comunidade.size(); i++) {
		if (comunidade[i]->getNome() == nome)
			return i;   // encontrou
	}
	return -1;     // nao encontrou
}

Grupo *Comunidade::existeGrupo(string grupo) const {
	for (unsigned int i = 0; i < comunidade.size(); i++) {
		for (size_t x = 0; x < comunidade[i]->getGrupos().size(); x++) {
			if (comunidade[i]->getGrupos()[x]->getTitulo() == grupo)
				return comunidade[i]->getGrupos()[x];   // encontrou
		}
	}
	//throw GrupoInexistente();     // nao encontrou
}

bool Comunidade::existeLogin(string l) const {
	Utilizador *u = new Utilizador;
	u->setLogin(l);
	if (existeUtil(u) == -1)
		return true;
	else
		throw UtilizadorJaExiste(u->getLogin());
}

Utilizador *Comunidade::utilizadorNaPosicao(int pos) const {
	return comunidade.at(pos);
}

void Comunidade::adicionarUtil(Utilizador *util) {
	if (existeUtil(util) == -1)
		comunidade.push_back(util);
	else
		throw UtilizadorJaExiste(util->getLogin());
}

bool comparaData(const Utilizador *u1, const Utilizador *u2) {
	return ((*u1).getDataAdesao() < (*u2).getDataAdesao());
}

void Comunidade::ordenaData() {
	sort(comunidade.begin(), comunidade.end(), comparaData);
}

bool comparaLogin(const Utilizador *u1, const Utilizador *u2) {
	return ((*u1).getLogin() < (*u2).getLogin());
}

void Comunidade::ordenaLogin() {
	sort(comunidade.begin(), comunidade.end(), comparaLogin);
}

void Comunidade::verUtilizador(Utilizador *util) const {
	Utilizador *u = new Utilizador();
	int i = existeUtil(util);
	if (i != -1)
		u = utilizadorNaPosicao(i);
	else
		throw UtilizadorInexistente((*util).getLogin());

	u->imprimirUtilizador();
}

void Comunidade::printComunidade() const {
	for (unsigned int i = 0; i < comunidade.size(); i++)
		cout << *comunidade.at(i) << endl;
}


void Comunidade::leComunidade() {
	int d, m, a, h, min, num, pos, bloq;
	string titulo, moderador, novo;
	bool flag3 = true;
	vector<string> amigos; //amigos de 1 utilizador
	vector<vector<string> > todosAmigos; // vetor com vetores de amigos. cada posicao corresponde a um utilizador pela ordem da comunidade
	string line;

	/* parte 1 - le utilizadores */

	ifstream util("C:\\utilizadores.txt");
	if (util.is_open()) {
		while (util.good())
		{
			Utilizador *u = new Utilizador;
			getline(util, line);
			u->setNome(line);	//nome
			getline(util, line);
			u->setLogin(line);	//login
			getline(util, line);
			u->setEmail(line);	//email
			getline(util, line);
			u->setTelemovel(atoi(line.c_str()));	//telemovel
			getline(util, line);
			d = atoi(line.c_str());
			getline(util, line);
			m = atoi(line.c_str());
			getline(util, line);
			a = atoi(line.c_str());
			u->setData(d, m, a);	//data
			getline(util, line);
			u->setIdade(atoi(line.c_str()));	//idade
			while (flag3) { //amigos
				getline(util, line);
				if (line == "-") {
					flag3 = false;
					break;
				}
				amigos.push_back(line);
			}
			todosAmigos.push_back(amigos);
			amigos.clear();
			
			getline(util, line);
			u->setVisibilidade(atoi(line.c_str())); //visibilidade

			adicionarUtil(u);

			flag3 = true;
		}
		util.close();
	}
	else {
		cout << "Unable to open file";
		util.close();
	}

	for (size_t i = 0; i < todosAmigos.size(); i++){
		for (size_t j = 0; j < todosAmigos.at(i).size(); j++){
			int pos = existeUtilLogin(todosAmigos.at(i).at(j));
			if (pos != -1)
				comunidade.at(i)->addAmigosAux(comunidade.at(pos));
		}
	}

	/* parte 2 - le conversas */

	ifstream conv("C:\\conversas.txt");
	if (conv.is_open()) {
		while (conv.good())
		{
			Conversa *c = new Conversa;

			getline(conv, line); //adicionar participantes
			c->adicionaParticipante(line);
			pos = existeUtilLogin(line);
			if (pos != -1)
				comunidade.at(pos)->addConversa(c); //adiciona a conversa ao participante

			getline(conv, line);
			c->adicionaParticipante(line);
			pos = existeUtilLogin(line);
			if (pos != -1)
				comunidade.at(pos)->addConversa(c);

			while (line != "-"){ //adicionar mensagens
				getline(conv, line);
				d = atoi(line.c_str());
				getline(conv, line);
				m = atoi(line.c_str());
				getline(conv, line);
				a = atoi(line.c_str());
				Data data(d, m, a);	//data
				getline(conv, line);
				h = atoi(line.c_str());
				getline(conv, line);
				min = atoi(line.c_str());
				Horas hora(h, min);
				getline(conv, line);
				num = atoi(line.c_str()); //numero da mensagem
				getline(conv, line);
				if (line == "t"){ //mensagem de texto
					getline(conv, line); //conteudo
					Mensagem *sms = new MsgTexto(line, data, hora);
					sms->setNumero(num);
					getline(conv, line); //emissor
					sms->setEmissor(line);
					c->adicionaSms(sms);
				}
				else if (line == "v"){ //mensagem de video
					Mensagem *sms = new MsgVideo(data, hora);
					sms->setNumero(num);
					getline(conv, line); //emissor
					sms->setEmissor(line);
					c->adicionaSms(sms);
				}
				else if (line == "i"){ //mensagem de imagem
					Mensagem *sms = new MsgImagem(data, hora);
					sms->setNumero(num);
					getline(conv, line); //emissor
					sms->setEmissor(line);
					c->adicionaSms(sms);
				}
			}
		}
		conv.close();
	}
	else {
		cout << "Unable to open file";
		conv.close();
	}

	/* parte 3 - le grupos */

	ifstream grupo("C:\\grupos.txt");
	if (grupo.is_open()) {
		while (grupo.good())
		{
			getline(grupo, line);
			titulo = line;	//titulo
			getline(grupo, line);
			d = atoi(line.c_str());
			getline(grupo, line);
			m = atoi(line.c_str());
			getline(grupo, line);
			a = atoi(line.c_str());
			Data datag(d, m, a);	//data
			getline(grupo, line); //moderador
			Grupo *g= new Grupo(titulo, datag, line);
			moderador = line;

			pos = existeUtilLogin(line); //adicionar o grupo ao utilizador
			if (pos != -1)
				comunidade.at(pos)->addGrupo(g);

			getline(grupo, line);
			while (line != "-"){ //membros
				d = atoi(line.c_str());
				getline(grupo, line);
				m = atoi(line.c_str());
				getline(grupo, line);
				a = atoi(line.c_str());
				Data dataAd(d, m, a); //data de addesao ao grupo
				getline(grupo, line); //nome
				g->adicionarMembro(line, moderador, dataAd); //juntar o membro ao grupo
				novo = line;
				getline(grupo, line);
				bloq = atoi(line.c_str()); // se o bloqueio for = 0, nao fazemos mais nada
				if (bloq == 1){ // se o bloqueio for 1 temos de ler a date de bloqueio
					getline(grupo, line);
					d = atoi(line.c_str());
					getline(grupo, line);
					m = atoi(line.c_str());
					getline(grupo, line);
					a = atoi(line.c_str());
					Data datab(d, m, a); //data de addesao ao grupo
					g->bloquearMembro(novo, moderador, datab);
				}
				pos = existeUtilLogin(novo); //adicionar o grupo ao utilizador
				if (pos != -1)
					comunidade.at(pos)->addGrupo(g);
				getline(grupo, line);
			}

			getline(grupo, line);
			while (line != "-"){ //pedidos de adesao
				g->adicionarPedido(line);
				getline(grupo, line);
			}

			getline(grupo, line);
			while (line != "-"){ //conversa de grupo
				d = atoi(line.c_str());
				getline(grupo, line);
				m = atoi(line.c_str());
				getline(grupo, line);
				a = atoi(line.c_str());
				Data data(d, m, a);	//data
				getline(grupo, line);
				h = atoi(line.c_str());
				getline(grupo, line);
				min = atoi(line.c_str());
				Horas hora(h, min); //horas
				getline(grupo, line);
				num = atoi(line.c_str()); //numero da mensagem
				getline(grupo, line);
				if (line == "t"){ //mensagem de texto
					getline(grupo, line); //conteudo
					Mensagem *sms = new MsgTexto(line, data, hora);
					sms->setNumero(num);
					getline(grupo, line); //emissor
					sms->setEmissor(line);
					g->enviarMensagem(line, sms);
				}
				else if (line == "v"){ //mensagem de video
					Mensagem *sms = new MsgVideo(data, hora);
					sms->setNumero(num);
					getline(grupo, line); //emissor
					sms->setEmissor(line);
					g->enviarMensagem(line, sms);
				}
				else if (line == "i"){ //mensagem de imagem
					Mensagem *sms = new MsgImagem(data, hora);
					sms->setNumero(num);
					getline(grupo, line); //emissor
					sms->setEmissor(line);
					g->enviarMensagem(line, sms);
				}
				getline(grupo, line);
			}
		}
		grupo.close();
	}
	else {
		cout << "Unable to open file";
		conv.close();
	}
}

int Comunidade::escreveComunidade() {
	ofstream myfile("comnidade2.txt");
	if (myfile.is_open()) {
		for (size_t i = 0; i < comunidade.size(); i++) {
			myfile << comunidade[i]->getNome() << "\n";
			myfile << comunidade[i]->getLogin() << "\n";
			myfile << comunidade[i]->getEmail() << "\n";
			myfile << comunidade[i]->getTelemovel() << "\n";
			myfile << comunidade[i]->getDataAdesao() << "\n";
			myfile << comunidade[i]->getIdade() << "\n";
			for (size_t x = 0; x < comunidade[i]->getAmigos().size(); x++) {
				myfile << comunidade[i]->getAmigos()[x]->getNome() << "\n";
			}
			myfile << "-" << "\n";
			for (size_t x = 0; x < comunidade[i]->getGrupos().size(); x++) {
				myfile << comunidade[i]->getGrupos()[x]->getTitulo() << "\n";
			}
			myfile << "-" << "\n";
			myfile << comunidade[i]->getVisibilidade();
		}

		myfile.close();
	}
	else
		cout << "Unable to open file";
	return 0;
}

