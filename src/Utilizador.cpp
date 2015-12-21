#include "Templates.h"
#include "Utilizador.h"
#include "Excecoes.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "System.h"

using namespace std;

static Data dataHoje;

void atualData(Data d){
  dataHoje = d;
}

/*******************************************************
* 				   CLASSE UTILIZADOR	          	   *
******************************************************/

Utilizador::Utilizador() {
  visibilidade = true;
  login = "";
  nome = "";
  email = "";
  idade = 0;
  telemovel = 0;
  Data d;
  dataAdesao = d;
}

Utilizador::Utilizador(bool visibilidade, string login, string nome, string email, Data dataAdesao, int telemovel, int idade) {
  this->visibilidade = visibilidade;
  this->login = login;
  this->nome = nome;
  this->email = email;
  this->dataAdesao = dataAdesao;
  if (idade < 18)
    throw IdadeInsuficiente(idade);
  this->idade = idade;
  this->telemovel = telemovel;
}

Utilizador::~Utilizador() {}

/*****************************************************************
*                             GETS                               *
*****************************************************************/

string Utilizador::getNome() const {
  return nome;
}

string Utilizador::getEmail() const {
  return email;
}

string Utilizador::getLogin() const {
  return login;
}

int Utilizador::getIdade() const {
  return idade;
}

int Utilizador::getTelemovel() const {
  return telemovel;
}

bool Utilizador::getVisibilidade() const {
  return visibilidade;
}

Data Utilizador::getDataAdesao() const {
  return dataAdesao;
}

vector<Utilizador *> Utilizador::getAmigos() const {
  return amigos;
}

Utilizador* Utilizador::getAmigo(string login) const {
  Utilizador *u = new Utilizador;
  u->setLogin(login);
  int i = pointerSequentialSearch(amigos, u);
  if (i == -1)
    throw AmigoInexistente(u->getLogin());
  return amigos[i];
}

Grupo* Utilizador::getGrupo(int i) const {
  if (i < 0 || i >= grupos.size())
    throw GrupoInexistente(i + 1);
  return grupos[i];
}

vector<Grupo *> Utilizador::getGrupos() const {
  return grupos;
}

Conversa* Utilizador::getConversa(int i) const {
  if (i < 0 || i >= conversas.size())
    throw ConversaInexistente(i + 1);
  return conversas[i];
}

vector<Conversa *> Utilizador::getConversas() const {
  return conversas;
}

string Utilizador::getDestinatarioConversa(Conversa *c) const {
  for (unsigned int i = 0; i < c->getParticipantes().size(); i++)
    if (c->getParticipantes()[i] != login)
      return c->getParticipantes()[i];
  return NULL;
}

vector<Grupo *> Utilizador::getGruposAmigos() const {
  vector<Grupo *> temp;
  vector<Grupo *> gruposAmigos;

  for (size_t i = 0; i < amigos.size(); i++) { //percorre os amigos
    temp = amigos.at(i)->getGrupos();
    for (size_t j = 0; j < temp.size(); j++)
      gruposAmigos.push_back(temp.at(j));
  }
  eliminaRepetidos(gruposAmigos);

  for (size_t j = 0; j < grupos.size(); j++) { //elimina os grupos a que o utilizador já pertence
    for (size_t k = 0; k < gruposAmigos.size(); k++)
      if (grupos.at(j) == grupos.at(k)) {
        gruposAmigos.erase(gruposAmigos.begin() + k);
        k--;
      }
  }

  return gruposAmigos;
}

int Utilizador::getNumMsg3dias() const {
  int n = 0;

  //numero de mensagens enviadas em conversas
  vector<Conversa *>::const_iterator it_c = conversas.begin();
  while (it_c != conversas.end()) {
    Conversa *c = *it_c;
    vector<Mensagem *> msgs = c->getMensagens();
    vector<Mensagem *>::const_iterator it_m = msgs.begin();
    while (it_m != msgs.end()) {
      Mensagem *m = *it_m;
      Data data = m->getData();
      if (datasTresDias(data, dataHoje)) {
        if (m->getEmissor().getLogin() == login)
          n++; //incrementa
      }
      it_m++;
    }
    it_c++;
  }

  //numero de conversas enviadas em grupos
  vector<Grupo *>::const_iterator it_g = grupos.begin();
  while (it_g != grupos.end()) {
    Grupo *g = *it_g;
    Conversa c_g = g->getConversa();
    vector<Mensagem *> msgs_g = c_g.getMensagens();
    vector<Mensagem *>::const_iterator it_m_g = msgs_g.begin();
    while (it_m_g != msgs_g.end()) {
      Mensagem *m_g = *it_m_g;
      Data data_g = m_g->getData();
      if (datasTresDias(data_g, dataHoje)) {
        if (m_g->getEmissor().getLogin() == login)
          n++; //incrementa
      }
      it_m_g++;
    }
    it_g++;
  }

  return n;
}

/*****************************************************************
*                             SETS                               *
*****************************************************************/

void Utilizador::setLogin(string l)
{
  login = l;
}

void Utilizador::setNome(string n) {
  nome = n;
}

void Utilizador::setEmail(string e) {
  email = e;
}

void Utilizador::setIdade(int i) {
  if (i < 18)
    throw IdadeInsuficiente(i);
  idade = i;
}

void Utilizador::setVisibilidade(bool v) {
  visibilidade = v;
}

void Utilizador::setTelemovel(int t) {
  telemovel = t;
}

void Utilizador::setData(int d, int m, int a) {
  dataAdesao.setData(d, m, a);
}

/*****************************************************************
*                             ADDS                               *
*****************************************************************/

void Utilizador::addAmigosAux(Utilizador *u) {
  vector<Utilizador *>::iterator it = find(amigos.begin(), amigos.end(), u);
  if (it != amigos.end())
    throw AmigoJaExiste(u->getLogin());
  else
    amigos.push_back(u);
}

void Utilizador::addAmigo(Utilizador &u) {
  addAmigosAux(&u);
  u.addAmigosAux(this);
}

bool Utilizador::addGrupo(Grupo *g) {
  if (pointerSequentialSearch(grupos, g) != -1) // ja existe aquele grupo, nao precisa de ser adicionado
    return false;
  else
    grupos.push_back(g);
  return true;
}

void Utilizador::addConversa(Conversa *c) {
  if (pointerSequentialSearch(conversas, c) != -1) // ja existe aquele grupo, nao precisa de ser adicionado
    throw ConversaJaExiste(c->getParticipantes());
  else
    conversas.push_back(c);
}

bool Utilizador::adicionaMembro(Utilizador *u, Grupo *g, Data d) {
  u->addGrupo(g);
  return g->adicionarMembro(u->getLogin(), login, d);
}

/*****************************************************************
*                            REMOVER                             *
*****************************************************************/

void Utilizador::removerAmigoAux(Utilizador *u) {
  vector<Utilizador *>::iterator it = find(amigos.begin(), amigos.end(), u);
  if (it == amigos.end())
    throw UtilizadorInexistente((*u).getLogin());
  else
    amigos.erase(it);
}

void Utilizador::removerAmigo(Utilizador &u) {
  removerAmigoAux(&u); //remove dos meus amigos
  u.removerAmigoAux(this); //remove me dos amigos dele
}

bool Utilizador::removerMembro(Utilizador *u, Grupo *g, Data diaAtual) {
  u->sairGrupo(g);
  return g->retiraMembro(u->getLogin(), login, diaAtual);
}

void Utilizador::removerConversa(Conversa *c) {
  for (unsigned int i = 0; i < conversas.size(); i++)
  {
    if (conversas[i] == c)
      conversas.erase(conversas.begin() + i);
  }
}

/*****************************************************************
*                           IMPRIMIR                             *
*****************************************************************/

void Utilizador::imprimirDefinicoes() const {
  cout << "Perfil (1 - publico , 0 - privado): " << visibilidade << endl;
  cout << "Nome: " << nome << endl;
  cout << "Login: " << login << endl;
  cout << "Idade: " << idade << endl;
  cout << "Email: " << email << endl;
  cout << "Telemovel: " << telemovel << endl;
  cout << endl;
}

void Utilizador::imprimirUtilizador() const {
  if (visibilidade) {
    cout << "Perfil: publico" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Login: " << login << endl;
    cout << "Idade: " << idade << endl;
    cout << "Email: " << email << endl;
    cout << "Telemovel: " << telemovel << endl;
    cout << endl;
  }
  else {
    cout << "Perfil: privado" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Login: " << login << endl;
  }
}

void Utilizador::imprimirAmigos() const {
  for (unsigned int i = 0; i < amigos.size(); i++)
  {
    cout << amigos[i]->getNome() << "    " << amigos[i]->getLogin() << endl;
  }
}

void Utilizador::imprimirGrupos() const {
  for (unsigned int i = 0; i < grupos.size(); i++)
  {
    cout << "Grupo: " << i + 1 << " , ";
    grupos.at(i)->printGrupo();
  }
}

void Utilizador::imprimirConversas() const {
  for (unsigned int i = 0; i < conversas.size(); i++)
  {
    cout << "Conversa: " << i + 1 << " , ";
    conversas.at(i)->imprimirParticipantes();
    cout << endl;
  }
}

void Utilizador::imprimirGruposAmigos() const {
  for (size_t k = 0; k < getGruposAmigos().size(); k++) {
    cout << "Grupo: " << k + 1 << " , ";
    getGruposAmigos().at(k)->printGrupo();
  }
}

/*****************************************************************
*                         OPERADORES                             *
*****************************************************************/

bool Utilizador::operator==(const Utilizador&u) const {
  return (login == u.login);
}

bool Utilizador::operator<(const Utilizador &u) const {
  if (getNumMsg3dias() > u.getNumMsg3dias())
    return true;
  else if (getNumMsg3dias() == u.getNumMsg3dias() && grupos.size() > u.getGrupos().size())
    return true;
  else
    return false;
}

ostream & operator<<(ostream & out, const Utilizador & u) {
  out << "Nome: " << u.getNome() << ", Login : " << u.getLogin() << ", Data : " << u.getDataAdesao();
  return out;
}

/*****************************************************************
*                             SAIR                               *
*****************************************************************/

void Utilizador::sairConversa(Conversa *c) {
  getAmigo(getDestinatarioConversa(c))->removerConversa(c);
  removerConversa(c);
  delete c;
}

void Utilizador::sairGrupo(Grupo* g) {
  for (size_t i = 0; i < grupos.size(); i++)
  {
    if (grupos[i] == g) {
      grupos.erase(grupos.begin() + i);
    }
  }
}

/*****************************************************************
*                           OUTROS                               *
*****************************************************************/

Conversa *Utilizador::criarConversa(Utilizador *u) {
  vector<string> participantes;
  participantes.push_back(u->getLogin()); //destinatario da conversa
  participantes.push_back(login); //emissor
  Conversa *c = new Conversa(participantes);
  bool encontrou = false;
  for (size_t i = 0; i < conversas.size(); i++) {
    if (conversas.at(i) == c) { // já existe essa conversa
      encontrou = true;
      throw ConversaJaExiste(participantes);
    }
  }
  if (!encontrou) {
    addConversa(c); //coloca a conversa no vetor de conversas
    u->addConversa(c);//adiciona a conversa criada ao vetor de conversas do amigo
  }
  return c;
}

void Utilizador::enviarMensagem(Mensagem *sms, Conversa *c) {
	sms->setLoginEmissor(login);
	c->adicionaSms(sms);
}

void Utilizador::pedirAdesao(Grupo *g) {
  g->adicionarPedido(login);
}

Grupo *Utilizador::criarGrupo(string titulo, Data dataAtual) {
  Grupo *g = new Grupo(titulo, dataAtual, login);
  grupos.push_back(g);
  return g;
}

void Utilizador::enviarMensagemGrupo(Mensagem *sms, Grupo *g) {
	sms->setLoginEmissor(login);
	g->enviarMensagem(login, sms);
}

bool Utilizador::aceitaMembro(Utilizador *u, Grupo *g, Data d) {
  u->addGrupo(g);
  return g->pedidoAdesao(u->getLogin(), login, d, true);
}

bool Utilizador::rejeitaMembro(Utilizador *u, Grupo *g, Data d) {
  return g->pedidoAdesao(u->getLogin(), login, d, false);
}

bool Utilizador::bloquearMembro(Utilizador *u, Grupo *g, Data diaAtual) {
  return g->bloquearMembro(u->getLogin(), login, diaAtual);
}

bool Utilizador::desbloquearMembro(Utilizador *u, Grupo *g, Data diaAtual) {
  return g->desbloquearMembro(u->getLogin(), login, diaAtual);
}

Grupo *Utilizador::escolheGruposAmigos(int pos) const {
  vector<Grupo *> temp = getGruposAmigos();

  if (temp.size() < (pos - 1))
    throw GrupoInexistente(pos);
  return temp.at(pos - 1);
}