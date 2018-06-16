#ifndef __USUPAPEL__
#define __USUPAPEL__

#include "commons.hpp"
#include "Usuario.hxx"
#include "Papel.hxx"
#include "Auditoria.hxx"

class UsuarioPapel{
private:
	shared_ptr<Usuario> usuario;
	shared_ptr<Papel> papel;
	shared_ptr<Auditoria> auditoria;
	bool valido;
public:
	UsuarioPapel();
	UsuarioPapel(shared_ptr<Usuario> usuario, shared_ptr<Papel> papel,
				 bool valido, shared_ptr<Auditoria> auditoria);

	shared_ptr<Usuario> getUsuario();
	shared_ptr<Papel> getPapel();
	shared_ptr<Auditoria> getAuditoria();
	bool getValido();
	bool setValido();
};

/* CONSTRUCTORS */

UsuarioPapel::UsuarioPapel(){
	usuario   = NULL;
	papel     = NULL;
	valido    = false;
	auditoria = NULL;
}

UsuarioPapel::UsuarioPapel(shared_ptr<Usuario> usuario, shared_ptr<Papel> papel,
						   bool valido, shared_ptr<Auditoria> auditoria){
	this->usuario   = usuario;
	this->papel     = papel;
	this->valido    = valido;
	this->auditoria = auditoria;
}


/* GETTERS */

shared_ptr<Usuario> UsuarioPapel::getUsuario(){
	return this->usuario;
}

shared_ptr<Papel> UsuarioPapel::getPapel(){
	return this->papel;
}

bool UsuarioPapel::getValido(){
	return this->valido;
}

shared_ptr<Auditoria> UsuarioPapel::getAuditoria(){
	return this->auditoria;
}


/* SETTERS */

// bool UsuarioPapel::setValido(){
// 	// TODO Adicionar esta ação na Auditoria
// 	/*
// 	Auditorias.push_back(GLOBAL_USUARIO, getDateTime(),
// 		"UsuarioPapel;alterado 'valido'");
// 	*/
// 	// ^ é um exemplo, temos que descobrir como fazer depois
// 	return this->auditoria;
// }

#endif
