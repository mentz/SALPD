#ifndef __AUDITORIA_HXX__
#define __AUDITORIA_HXX__

// Auditoria.hxx
// #include "commons.hpp"
#include "UsuarioPapel.hxx"
#include <odb/core.hxx>
#include <string>

#pragma db object
class Auditoria{
private:
	// acao: Ação executada pelo usuário
	#pragma db id auto
	unsigned long id;

	friend class odb::access;

	std::string acao;
	// usuario: Usuário que fez ação
	#pragma db not_null
	shared_ptr<UsuarioPapel> usuario;

	Auditoria() {};
public:
	Auditoria(std::string acao, shared_ptr<UsuarioPapel> usuario){
		this -> acao = "";
	}

	void setAcao(std::string acao){
		this -> acao = acao;
	}
	void setUsuario(shared_ptr<UsuarioPapel> usuario){
		this -> usuario = usuario;
	}

	std::string getAcao() {
		return this -> acao;
	}
	shared_ptr<UsuarioPapel> getUsuario(){
		return this -> usuario;
	}

	// TODO completar classe
};
//
// /* CONSTRUCTORS */
//
// // Rever este, acredito que não precisamos ter construtor vazio
// Auditoria::Auditoria(){
// 	this->acao = "";
// 	this->usuario = NULL;
// }
//
// Auditoria::Auditoria(string acao, shared_ptr<UsuarioPapel> usuario){
// 	this->acao = acao;
// 	this->usuario = usuario;
// }
//
// /* SETTERS */
// void Auditoria::setAcao(string acao){
// 	this->acao = acao;
// }
// void Auditoria::setUsuario(shared_ptr<UsuarioPapel> usuario){
// 	this->usuario = usuario;
// }
//
//
// /* GETTERS */
// string Auditoria::getAcao(){
// 	return this->acao;
// }
// shared_ptr<UsuarioPapel> Auditoria::getUsuario(){
// 	return this->usuario;
// }

#endif
