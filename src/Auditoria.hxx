// Auditoria.hxx
#include "commons.hpp"

class Auditoria{

private:
	// acao: Ação executada pelo usuário
	string acao;

	// usuario: Usuário que fez ação
	int usuario;

public:
	Auditoria();
	Auditoria(string acao, int usuario);

	void setAcao(string acao);
	void setUsuario(int usuario);

	string getAcao();
	int getUsuario();

	// TODO completar classe
};

/* CONSTRUCTORS */

Auditoria::Auditoria(){
	this->acao = "";
	this->usuario = "";
}

Auditoria::Auditoria(string acao, int usuario){
	this->acao = acao;
	this->usuario = usuario;
}

/* SETTERS */
void Auditoria::setAcao(string acao){
	this->acao = acao;
}
void Auditoria::setUsuario(int usuario){
	this->usuario = usuario;
}


/* GETTERS */
string Auditoria::getAcao(){
	return this->acao;
}
int Auditoria::getUsuario(){
	return this->usuario;
}
