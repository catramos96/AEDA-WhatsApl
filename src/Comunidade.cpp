#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Comunidade.h"
#include "Templates.h"
#include "Excecoes.h"
#include <tr1/unordered_set>
using namespace std;
/********************************
*		CLASSE COMUNIDADE		*
*******************************/
Comunidade::Comunidade() {
  comunidade.clear(); //inicializar o vetor
}

void Comunidade::updateUtilizadoresInativos() {
	for (size_t i = 0; i < comunidade.size(); i++) {
		if (comunidade[i]->inativo() > 30) {
			utilizadoresInativos.insert(comunidade[i]);
			//comunidade.erase(comunidade.begin()+i);
		}
	}

	tr1::unordered_set<Utilizador*, hUtilizadoresInativos, hUtilizadoresInativos>::iterator it = utilizadoresInativos.begin();
	while (it != utilizadoresInativos.end()) {
		if((*it)->inativo() < 30 ){
			Utilizador * u = new Utilizador();
			u = (*it);
			utilizadoresInativos.erase((*it));
			//comunidade.push_back(u);
		}
		it++;
	}
}

void Comunidade::printUtilizadoresInativos() const{
	tr1::unordered_set<Utilizador*, hUtilizadoresInativos, hUtilizadoresInativos>::const_iterator it = utilizadoresInativos.begin();
	while(it!=utilizadoresInativos.end()){
		(*it)->imprimirUtilizador();
		it++;
	}
}

int Comunidade::existeUtil(Utilizador *util) const {
	for (unsigned int i = 0; i < comunidade.size(); i++) {
		if (*comunidade[i] == *util)
			return i;
	}
	return -1;
}

int Comunidade::existeUtilLogin(string login) const {
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
  if (existeUtil(util) == -1) {
    comunidade.push_back(util);
  }
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

void Comunidade::leUtilizador(string path) {

	int d, m, a, h, min, num, pos, bloq,d1,m1,a1;
	string titulo, moderador, novo;
	bool flag3 = true;
	vector<string> amigos; //amigos de 1 utilizador
	vector<vector<string> > todosAmigos; // vetor com vetores de amigos. cada posicao corresponde a um utilizador pela ordem da comunidade
	string line;

	/* parte 1 - le utilizadores */

	ifstream util(path.c_str());
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
			d1 = atoi(line.c_str());
			getline(util, line);
			m1 = atoi(line.c_str());
			getline(util, line);
			a1 = atoi(line.c_str());
			u->setDataAcesso(d1,m1,a1);	//ultimo acesso
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
	for (size_t i = 0; i < todosAmigos.size(); i++) {
		for (size_t j = 0; j < todosAmigos.at(i).size(); j++) {
			int pos = existeUtilLogin(todosAmigos.at(i).at(j));
			if (pos != -1)
				comunidade.at(i)->addAmigosAux(comunidade.at(pos));
		}
	}
}

void Comunidade::leConversa(string path) {
	int d, m, a, h, min, num, pos, bloq;
	string titulo, moderador, novo, line;

	/* parte 2 - le conversas */

	ifstream conv(path.c_str());
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

			getline(conv, line);
			while (line != "-") { //adicionar mensagens
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
				if (line == "t") { //mensagem de texto
					getline(conv, line); //conteudo
					Mensagem *sms = new MsgTexto(line, data, hora);
					sms->setNumero(num);
					getline(conv, line); //emissor
					sms->setLoginEmissor(line); //nas conversas só nos interessa o login do emissor
					c->adicionaSms(sms);
				}
				else if (line == "v") { //mensagem de video
					Mensagem *sms = new MsgVideo(data, hora);
					sms->setNumero(num);
					getline(conv, line); //emissor
					sms->setLoginEmissor(line);
					c->adicionaSms(sms);
				}
				else if (line == "i") { //mensagem de imagem
					Mensagem *sms = new MsgImagem(data, hora);
					sms->setNumero(num);
					getline(conv, line); //emissor
					sms->setLoginEmissor(line);
					c->adicionaSms(sms);
				}
				getline(conv, line);
			}
		}
		conv.close();
	}
	else {
		cout << "Unable to open file";
		conv.close();
	}
}

void Comunidade::leGrupo(string path) {
	int d, m, a, h, min, num, pos, bloq;
	string titulo, moderador, novo, line;

	/* parte 3 - le grupos */
	int n = 0;

	ifstream grupo(path.c_str());
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
			Grupo *g = new Grupo(titulo, datag, line);
			moderador = line;
			pos = existeUtilLogin(line); //adicionar o grupo ao utilizador
			if (pos != -1)
				comunidade.at(pos)->addGrupo(g);

			getline(grupo, line);
			while (line != "-") { //membros
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
				if (bloq == 1) { // se o bloqueio for 1 temos de ler a data de bloqueio
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
			while (line != "-") { //pedidos de adesao
				g->adicionarPedido(line);
				getline(grupo, line);
			}

			getline(grupo, line);
			while (line != "-") { //conversa de grupo
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
				if (line == "t") { //mensagem de texto
					getline(grupo, line); //conteudo
					Mensagem *sms = new MsgTexto(line, data, hora);
					sms->setNumero(num);
					getline(grupo, line); //login do emissor
					Membro temp(line, data); // emissor
					int pos = g->existeMembro(temp); //procurar o membro correspondente
					temp = g->membroNaPosicao(pos);
					sms->setMembroEmissor(temp);
					g->colocaMsgConversa(sms);  //coloca a mensagem diretamente na conversa
				}
				else if (line == "v") { //mensagem de video
					Mensagem *sms = new MsgVideo(data, hora);
					sms->setNumero(num);
					getline(grupo, line); //login do emissor
					Membro temp(line, data); // emissor
					int pos = g->existeMembro(temp); //procurar o membro correspondente
					temp = g->membroNaPosicao(pos);
					sms->setMembroEmissor(temp);
					g->colocaMsgConversa(sms);  //coloca a mensagem diretamente na conversa
				}
				else if (line == "i") { //mensagem de imagem
					Mensagem *sms = new MsgImagem(data, hora);
					sms->setNumero(num);
					getline(grupo, line); // login do emissor
					Membro temp(line, data); // emissor
					int pos = g->existeMembro(temp); //procurar o membro correspondente
					temp = g->membroNaPosicao(pos);
					sms->setMembroEmissor(temp);
					g->colocaMsgConversa(sms);  //coloca a mensagem diretamente na conversa
				}
				getline(grupo, line);
			}

			getline(grupo, line);
			while (line != "-") { //mensagens pendentes (igual a escrever uma mensagem só que fazemos push)
				cout << "x";
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
				if (line == "t") { //mensagem de texto
					getline(grupo, line); //conteudo
					Mensagem *sms = new MsgTexto(line, data, hora);
					sms->setNumero(num);
					getline(grupo, line); //login do emissor
					Membro temp(line, data); // emissor
					int pos = g->existeMembro(temp); //procurar o membro correspondente
					temp = g->membroNaPosicao(pos);
					sms->setMembroEmissor(temp);
					g->MsgPendentesPush(sms); // coloca a mensagem na priority_queue
				}
				else if (line == "v") { //mensagem de video
					Mensagem *sms = new MsgVideo(data, hora);
					sms->setNumero(num);
					getline(grupo, line); //login do emissor
					Membro temp(line, data); // emissor
					int pos = g->existeMembro(temp); //procurar o membro correspondente
					temp = g->membroNaPosicao(pos);
					sms->setMembroEmissor(temp);
					g->MsgPendentesPush(sms); // coloca a mensagem na priority_queue
				}
				else if (line == "i") { //mensagem de imagem
					Mensagem *sms = new MsgImagem(data, hora);
					sms->setNumero(num);
					getline(grupo, line); // login do emissor
					Membro temp(line, data); // emissor
					int pos = g->existeMembro(temp); //procurar o membro correspondente
					temp = g->membroNaPosicao(pos);
					sms->setMembroEmissor(temp);
					g->MsgPendentesPush(sms); // coloca a mensagem na priority_queue
				}
				getline(grupo, line);
			}
		}
		grupo.close();
	}
	else {
		cout << "Unable to open file";
		grupo.close();
	}
/*======= 
  int d, m, a, h, min, num, pos, bloq;
  string titulo, moderador, novo;
  bool flag3 = true;
  vector<string> amigos; //amigos de 1 utilizador
  vector<vector<string> > todosAmigos; // vetor com vetores de amigos. cada posicao corresponde a um utilizador pela ordem da comunidade
  string line;

  // parte 1 - le utilizadores

  ifstream util(path.c_str());
  if (util.is_open()) {
    while (util.good())
    {
      cout << "a";
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
  cout << "x";

  for (size_t i = 0; i < todosAmigos.size(); i++) {
    for (size_t j = 0; j < todosAmigos.at(i).size(); j++) {
      int pos = existeUtilLogin(todosAmigos.at(i).at(j));
      if (pos != -1)
        comunidade.at(i)->addAmigosAux(comunidade.at(pos));
    }
  }
}

void Comunidade::leConversa(string path) {
  int d, m, a, h, min, num, pos, bloq;
  string titulo, moderador, novo, line;

  // parte 2 - le conversas

  ifstream conv(path.c_str());
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

      getline(conv, line);	//<<<<<<<<<<<<<<<<<<<
      while (line != "-") { //adicionar mensagens
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
        if (line == "t") { //mensagem de texto
          getline(conv, line); //conteudo
          Mensagem *sms = new MsgTexto(line, data, hora);
          sms->setNumero(num);
          getline(conv, line); //emissor
          sms->setEmissor(line);
          c->adicionaSms(sms);
        }
        else if (line == "v") { //mensagem de video
          Mensagem *sms = new MsgVideo(data, hora);
          sms->setNumero(num);
          getline(conv, line); //emissor
          sms->setEmissor(line);
          c->adicionaSms(sms);
        }
        else if (line == "i") { //mensagem de imagem
          Mensagem *sms = new MsgImagem(data, hora);
          sms->setNumero(num);
          getline(conv, line); //emissor
          sms->setEmissor(line);
          c->adicionaSms(sms);
        }
        getline(conv, line);
      }
    }
    conv.close();
  }
  else {
    cout << "Unable to open file";
    conv.close();
  }
  cout << "x";
}

void Comunidade::leGrupo(string path) {
  int d, m, a, h, min, num, pos, bloq;
  string titulo, moderador, novo, line;

  // parte 3 - le grupos

  ifstream grupo(path.c_str());
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
      Grupo *g = new Grupo(titulo, datag, line);
      moderador = line;
      pos = existeUtilLogin(line); //adicionar o grupo ao utilizador
      if (pos != -1)
        comunidade.at(pos)->addGrupo(g);
      getline(grupo, line);

      while (line != "-") { //membros
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
        if (bloq == 1) { // se o bloqueio for 1 temos de ler a date de bloqueio
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
      while (line != "-") { //pedidos de adesao
        g->adicionarPedido(line);
        getline(grupo, line);
      }

      getline(grupo, line);
      while (line != "-") { //conversa de grupo
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
        if (line == "t") { //mensagem de texto
          getline(grupo, line); //conteudo
          Mensagem *sms = new MsgTexto(line, data, hora);
          sms->setNumero(num);
          getline(grupo, line); //emissor
          sms->setEmissor(line);
          g->enviarMensagem(line, sms);
        }
        else if (line == "v") { //mensagem de video
          Mensagem *sms = new MsgVideo(data, hora);
          sms->setNumero(num);
          getline(grupo, line); //emissor
          sms->setEmissor(line);
          g->enviarMensagem(line, sms);
        }
        else if (line == "i") { //mensagem de imagem
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
    grupo.close();
  }
  cout << "x";
>>>>>>> 8501d842da852d27cbed2d4f289d39b23fa64fb8*/
}

int Comunidade::escreveUtilizador(string path) {

	/* parte 1 - escreve utilizadores */

	fstream myfile(path.c_str());
	if (myfile.is_open()) {

		for (size_t i = 0; i < comunidade.size(); i++) {
			myfile << comunidade.at(i)->getNome() << endl;
			myfile << comunidade.at(i)->getLogin() << endl;
			myfile << comunidade.at(i)->getEmail() << endl;
			myfile << comunidade.at(i)->getTelemovel() << endl;
			myfile << comunidade.at(i)->getDataAdesao().getDia() << endl;
			myfile << comunidade.at(i)->getDataAdesao().getMes() << endl;
			myfile << comunidade.at(i)->getDataAdesao().getAno() << endl;
			myfile << comunidade.at(i)->getUltimoAcesso().getDia() << endl;
			myfile << comunidade.at(i)->getUltimoAcesso().getMes() << endl;
			myfile << comunidade.at(i)->getUltimoAcesso().getAno() << endl;
			myfile << comunidade.at(i)->getIdade() << endl;

			for (size_t j = 0; j < comunidade.at(i)->getAmigos().size(); j++)
				myfile << comunidade.at(i)->getAmigos().at(j)->getLogin() << endl;
			myfile << "-" << endl;

			if (comunidade.at(i)->getVisibilidade())
				myfile << "1";
			else
				myfile << "0";

			if (i != comunidade.size() - 1)
				myfile << endl;
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file";
		return 1;
	}
	return 0;
}

int Comunidade::escreveConversa(string path) {
	/* parte 2 - conversas */

	//vetor com todas as conversas - sem repetidas
	vector< Conversa *> todas;

	for (size_t k = 0; k < comunidade.size(); k++) {
		for (size_t l = 0; l < comunidade.at(k)->getConversas().size(); l++) {
			todas.push_back(comunidade.at(k)->getConversas().at(l));
		}
	}
	eliminaRepetidos(todas);

	fstream myfile(path.c_str());
	if (myfile.is_open()) {
		for (size_t m = 0; m < todas.size(); m++) { // percorre todas as conversas
			myfile << todas.at(m)->getParticipantes().at(0) << endl;
			myfile << todas.at(m)->getParticipantes().at(1) << endl;

			for (size_t n = 0; n < todas.at(m)->getMensagens().size(); n++) { //percorre as mensagens
				myfile << todas.at(m)->getMensagens().at(n)->getData().getDia() << endl;
				myfile << todas.at(m)->getMensagens().at(n)->getData().getMes() << endl;
				myfile << todas.at(m)->getMensagens().at(n)->getData().getAno() << endl;
				myfile << todas.at(m)->getMensagens().at(n)->getHora().getHora() << endl;
				myfile << todas.at(m)->getMensagens().at(n)->getHora().getMinutos() << endl;
				myfile << todas.at(m)->getMensagens().at(n)->getNumero() << endl;
				myfile << todas.at(m)->getMensagens().at(n)->tipo() << endl;
				if (todas.at(m)->getMensagens().at(n)->tipo() == "t")
					myfile << todas.at(m)->getMensagens().at(n)->getConteudo() << endl;
				myfile << todas.at(m)->getMensagens().at(n)->getEmissor().getLogin() << endl;
			}
			if (m != todas.size() - 1)
				myfile << "-" << endl;
			else
				myfile << "-";
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file";
		return 1;
	}
	return 0;
/*=======
  // parte 1 - escreve utilizadores 

  fstream myfile(path.c_str());
  if (myfile.is_open()) {

    for (size_t i = 0; i < comunidade.size(); i++) {
      myfile << comunidade.at(i)->getNome() << endl;
      myfile << comunidade.at(i)->getLogin() << endl;
      myfile << comunidade.at(i)->getEmail() << endl;
      myfile << comunidade.at(i)->getTelemovel() << endl;
      myfile << comunidade.at(i)->getDataAdesao().getDia() << endl;
      myfile << comunidade.at(i)->getDataAdesao().getMes() << endl;
      myfile << comunidade.at(i)->getDataAdesao().getAno() << endl;
      myfile << comunidade.at(i)->getIdade() << endl;

      for (size_t j = 0; j < comunidade.at(i)->getAmigos().size(); j++)
        myfile << comunidade.at(i)->getAmigos().at(j)->getLogin() << endl;
      myfile << "-" << endl;

      if (comunidade.at(i)->getVisibilidade())
        myfile << "1";
      else
        myfile << "0";

      if (i != comunidade.size() - 1)
        myfile << endl;
    }
    myfile.close();
  }
  else {
    cout << "Unable to open file";
    return 1;
  }
  return 0;
}

int Comunidade::escreveConversa(string path) {
  // parte 2 - conversas 

  //vetor com todas as conversas - sem repetidas
  vector< Conversa *> todas;

  for (size_t k = 0; k < comunidade.size(); k++) {
    for (size_t l = 0; l < comunidade.at(k)->getConversas().size(); l++) {
      todas.push_back(comunidade.at(k)->getConversas().at(l));
    }
  }
  eliminaRepetidos(todas);

  fstream myfile(path.c_str());
  if (myfile.is_open()) {
    for (size_t m = 0; m < todas.size(); m++) { // percorre todas as conversas
      myfile << todas.at(m)->getParticipantes().at(0) << endl;
      myfile << todas.at(m)->getParticipantes().at(1) << endl;

      for (size_t n = 0; n < todas.at(m)->getMensagens().size(); n++) { //percorre as mensagens
        myfile << todas.at(m)->getMensagens().at(n)->getData().getDia() << endl;
        myfile << todas.at(m)->getMensagens().at(n)->getData().getMes() << endl;
        myfile << todas.at(m)->getMensagens().at(n)->getData().getAno() << endl;
        myfile << todas.at(m)->getMensagens().at(n)->getHora().getHora() << endl;
        myfile << todas.at(m)->getMensagens().at(n)->getHora().getMinutos() << endl;
        myfile << todas.at(m)->getMensagens().at(n)->getNumero() << endl;
        myfile << todas.at(m)->getMensagens().at(n)->tipo() << endl;
        if (todas.at(m)->getMensagens().at(n)->tipo() == "t")
          myfile << todas.at(m)->getMensagens().at(n)->getConteudo() << endl;
        myfile << todas.at(m)->getMensagens().at(n)->getEmissor() << endl;
      }
      if (m != todas.size() - 1)
        myfile << "-" << endl;
      else
        myfile << "-";
    }
    myfile.close();
  }
  else {
    cout << "Unable to open file";
    return 1;
  }
  return 0;
>>>>>>> 8501d842da852d27cbed2d4f289d39b23fa64fb8*/
}

int Comunidade::escreveGrupo(string path) {

	/* parte 3 - grupos */

	vector< Grupo *> todosGrupos;

	for (size_t p = 0; p < comunidade.size(); p++) {
		for (size_t r = 0; r < comunidade.at(p)->getGrupos().size(); r++) {
			todosGrupos.push_back(comunidade.at(p)->getGrupos().at(r));
		}
	}
	eliminaRepetidos(todosGrupos);

	fstream myfile(path.c_str());
	if (myfile.is_open()) {
		for (size_t s = 0; s < todosGrupos.size(); s++) {
			cout << "grupo " << s << endl;

			myfile << todosGrupos.at(s)->getTitulo() << endl;
			myfile << todosGrupos.at(s)->getDataCriacao().getDia() << endl;
			myfile << todosGrupos.at(s)->getDataCriacao().getMes() << endl;
			myfile << todosGrupos.at(s)->getDataCriacao().getAno() << endl;
			myfile << todosGrupos.at(s)->getModerador() << endl;

			for (unsigned int t = 0; t < todosGrupos.at(s)->numMembros(); t++) { //percorre os membros
				if (todosGrupos.at(s)->getMembros().at(t).getLogin() == todosGrupos.at(s)->getModerador()) { //passa à frente o moderador
					t++;
					if (t == todosGrupos.at(s)->numMembros()) { // se o moderador era o ultimo elemento acaba o ciclo
						break;
					}
				}

				myfile << todosGrupos.at(s)->getMembros().at(t).getDataCriacao().getDia() << endl;
				myfile << todosGrupos.at(s)->getMembros().at(t).getDataCriacao().getMes() << endl;
				myfile << todosGrupos.at(s)->getMembros().at(t).getDataCriacao().getAno() << endl;
				myfile << todosGrupos.at(s)->getMembros().at(t).getLogin() << endl;
				if (todosGrupos.at(s)->getMembros().at(t).isBloqueado()) {
					myfile << "1" << endl;
					myfile << todosGrupos.at(s)->getMembros().at(t).getDataBloqueio().getDia() << endl;
					myfile << todosGrupos.at(s)->getMembros().at(t).getDataBloqueio().getMes() << endl;
					myfile << todosGrupos.at(s)->getMembros().at(t).getDataBloqueio().getAno() << endl;
				}
				else
					myfile << "0" << endl;
			}
			cout << "nao há mais membros" << endl;
			myfile << "-" << endl;

			for (unsigned int u = 0; u < todosGrupos.at(s)->numPedidos(); u++) { //pedidos de adesao
				myfile << todosGrupos.at(s)->getPedidos().at(u) << endl;
			}
			cout << "nao ha mais pedidos de adesao" << endl;
			myfile << "-" << endl;

			for (size_t v = 0; v < todosGrupos.at(s)->getConversa().getMensagens().size(); v++) { //percorre as mensagens
				myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getData().getDia() << endl;
				myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getData().getMes() << endl;
				myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getData().getAno() << endl;
				myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getHora().getHora() << endl;
				myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getHora().getMinutos() << endl;
				myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getNumero() << endl;
				myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->tipo() << endl;
				if (todosGrupos.at(s)->getConversa().getMensagens().at(v)->tipo() == "t")
					myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getConteudo() << endl;
				myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getEmissor().getLogin() << endl;
			}
			cout << "nao ha mais mensagens" << endl;
			myfile << "-" << endl;

			cout << todosGrupos.at(s)->getMsgPendentesSize() << endl;

			for (size_t x = 0; x < todosGrupos.at(s)->getMsgPendentesSize(); x++) { //mensagens pendentes
				Mensagem *sms = todosGrupos.at(s)->getTopo();
				myfile << sms->getData().getDia() << endl;
				myfile << sms->getData().getMes() << endl;
				myfile << sms->getData().getAno() << endl;
				myfile << sms->getHora().getHora() << endl;
				myfile << sms->getHora().getMinutos() << endl;
				myfile << sms->getNumero() << endl;
				myfile << sms->tipo() << endl;
				if (sms->tipo() == "t")
					myfile << sms->getConteudo() << endl;
				myfile << sms->getEmissor().getLogin() << endl;
				todosGrupos.at(s)->MsgPendentesPop();
			}
			cout << "nao ha mais mensagens pendentes" << endl;
			myfile << "-";

			if (s != todosGrupos.size() - 1)
				myfile << endl;
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file";
		return 1;
	}
	return 0;
/*=======
  // parte 3 - grupos

  vector< Grupo *> todosGrupos;

  for (size_t p = 0; p < comunidade.size(); p++) {
    for (size_t r = 0; r < comunidade.at(p)->getGrupos().size(); r++) {
      todosGrupos.push_back(comunidade.at(p)->getGrupos().at(r));
    }
  }
  eliminaRepetidos(todosGrupos);

  fstream myfile(path.c_str());
  if (myfile.is_open()) {
    for (size_t s = 0; s < todosGrupos.size(); s++) {
      myfile << todosGrupos.at(s)->getTitulo() << endl;
      myfile << todosGrupos.at(s)->getDataCriacao().getDia() << endl;
      myfile << todosGrupos.at(s)->getDataCriacao().getMes() << endl;
      myfile << todosGrupos.at(s)->getDataCriacao().getAno() << endl;
      myfile << todosGrupos.at(s)->getModerador() << endl;

      for (unsigned int t = 0; t < todosGrupos.at(s)->numMembros(); t++) { //percorre os membros
        if (todosGrupos.at(s)->getMembros().at(t).getLogin() == todosGrupos.at(s)->getModerador()) { //passa à frente o moderador
          t++;
          if (t == todosGrupos.at(s)->numMembros()) { // se o moderador era o ultimo elemento acaba o ciclo
            break;
          }
        }

        myfile << todosGrupos.at(s)->getMembros().at(t).getDataCriacao().getDia() << endl;
        myfile << todosGrupos.at(s)->getMembros().at(t).getDataCriacao().getMes() << endl;
        myfile << todosGrupos.at(s)->getMembros().at(t).getDataCriacao().getAno() << endl;
        myfile << todosGrupos.at(s)->getMembros().at(t).getLogin() << endl;
        if (todosGrupos.at(s)->getMembros().at(t).isBloqueado()) {
          myfile << "1" << endl;
          myfile << todosGrupos.at(s)->getMembros().at(t).getDataBloqueio().getDia() << endl;
          myfile << todosGrupos.at(s)->getMembros().at(t).getDataBloqueio().getMes() << endl;
          myfile << todosGrupos.at(s)->getMembros().at(t).getDataBloqueio().getAno() << endl;
        }
        else
          myfile << "0" << endl;
      }
      myfile << "-" << endl;

      for (unsigned int u = 0; u < todosGrupos.at(s)->numPedidos(); u++) { //pedidos de adesao
        myfile << todosGrupos.at(s)->getPedidos().at(u) << endl;
      }
      myfile << "-" << endl;

      for (size_t v = 0; v < todosGrupos.at(s)->getConversa().getMensagens().size(); v++) { //percorre as mensagens
        myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getData().getDia() << endl;
        myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getData().getMes() << endl;
        myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getData().getAno() << endl;
        myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getHora().getHora() << endl;
        myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getHora().getMinutos() << endl;
        myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getNumero() << endl;
        myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->tipo() << endl;
        if (todosGrupos.at(s)->getConversa().getMensagens().at(v)->tipo() == "t")
          myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getConteudo() << endl;
        myfile << todosGrupos.at(s)->getConversa().getMensagens().at(v)->getEmissor() << endl;
      }
      myfile << "-";
      if (s != todosGrupos.size() - 1)
        myfile << endl;
    }
    myfile.close();
  }
  else {
    cout << "Unable to open file";
    return 1;
  }
  return 0;
>>>>>>> 8501d842da852d27cbed2d4f289d39b23fa64fb8*/
}

BST<Utilizador> Comunidade::topUtilizadores() const{
  Data d(1, 1, 1);
  Utilizador u(1, "", "", "", d,d, 0, 18);
  BST<Utilizador> arvore(u);
  vector<Utilizador *>::const_iterator it = comunidade.begin();

  while (it != comunidade.end()) {
    arvore.insert(**it);
    it++;
  }

  return arvore;
}

void Comunidade::displayTopUtilizadores() const {
  BST<Utilizador> bst = topUtilizadores();
  bst.printTree();  
  cout << endl;
}
