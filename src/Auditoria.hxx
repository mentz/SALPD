// Auditoria.hxx
#include "commons.hpp"

class Auditoria{

private:
	// acao: Ação executada pelo usuário
	string acao;

	// usuario: Usuário que fez ação
	shared_ptr<Usuario> usuario;

public:
	Auditoria();
	Auditoria(string acao, shared_ptr<Usuario> usuario);

	void setAcao(string acao);
	void setUsuario(shared_ptr<Usuario> usuario);

	string getAcao();
	int getUsuario();

	// TODO completar classe
};

/* CONSTRUCTORS */

// Rever este, acredito que não precisamos ter construtor vazio
Auditoria::Auditoria(){
	this->acao = "";
	this->usuario = NULL;
}

Auditoria::Auditoria(string acao, shared_ptr<Usuario> usuario){
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
