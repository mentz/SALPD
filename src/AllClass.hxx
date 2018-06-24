#ifndef __ALL_CLASS_HXX__
#define __ALL_CLASS_HXX__

#include <odb/core.hxx>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>

#pragma db object
class papel {
private:
	friend class odb::access;

	#pragma db id auto
	unsigned long id;

	// As restrições em si são implementadas no programa com
	//  base nas restrições apresentadas na forma "rw usuario"
	//  deste atributo.
	std::string permissoes;
public:
    papel() {}
    papel(int id, std::string permissoes){
		this -> id = id;
		this -> permissoes = permissoes;
	}
    void setPermissoes(std::string);
	int getID(){
		return this -> id;
	}
    std::string getPapel() const {
		return (this -> id == 1 ? "ADMIN" : (this -> id == 2 ? "GESTOR" : (this -> id == 3 ? "AGENTE" : (this -> id == 4 ? "INFORMANTE" : "ANONIMO"))));
	}
    std::string getPermissoes() const;
};

#pragma db object
class usuario {
private:
	friend class odb::access;

    #pragma db id auto
	unsigned long id;

	#pragma db not_null
	papel * fk_papel;

	#pragma db not_null
	std::string rg;
	#pragma db not_null
	std::string cpf;
	#pragma db not_null
	std::string nome;
	#pragma db not_null
	std::string nome_usuario;
	#pragma db not_null
	std::string hash_senha;
	#pragma db not_null
	time_t data_cadastro;
public:
    usuario() {}
	usuario(std::string rg, std::string cpf, std::string nome, std::string nome_usuario, std::string hash_senha, time_t data_cadastro, papel * fk_papel){
		this -> rg = rg;
		this -> cpf = cpf;
		this -> nome = nome;
		this -> nome_usuario = nome_usuario;
		this -> hash_senha = hash_senha;
		this -> data_cadastro = data_cadastro;
		this -> fk_papel = fk_papel;
	}

	int getID(){
		return this -> id;
	}
	papel * getFkPapel(){
		return this -> fk_papel;
	}
	std::string getRG(){
		return this -> rg;
	}
	std::string getCPF(){
		return this -> cpf;
	}
	std::string getNome(){
		return this -> nome;
	}
	std::string getNomeUsuario(){
		return this -> nome_usuario;
	}
	std::string getHashSenha(){
		return this -> hash_senha;
	}
	time_t getDataCadastro(){
		return this -> data_cadastro;
	}

	void setID(int id){
		this -> id = id;
	}
};


#pragma db object
class auditoria {
private:
	friend class odb::access;

	#pragma db id auto
	unsigned long id;

	#pragma db not_null
	std::string acao; // acao: Ação executada pelo usuário
	#pragma db not_null
	usuario * usuario_acao; // usuario: Usuário que fez ação
	#pragma db not_null
	time_t data_hora;
public:
    auditoria() {}
	auditoria(std::string acao, usuario * usuario_acao, time_t data_hora){
		this -> acao = acao;
		this -> usuario_acao = usuario_acao;
		this -> data_hora = data_hora;
	}

	std::string getAcao() {
		return this -> acao;
	}
	usuario * getUsuario(){
		return this -> usuario_acao;
	}

	// TODO completar classe
};

#pragma db object
class pessoa {
private:
	friend class odb::access;

    #pragma db id auto
	unsigned long id;

	#pragma db not_null
	bool estado;

	std::string rg;
	std::string cpf;

	#pragma db not_null
	std::string nome;
	int idade;
	#pragma db not_null
	std::string detalhes;
	#pragma db not_null
	time_t data_cadastro;
	#pragma db not_null
	time_t ultimo_update;
public:

	pessoa() {}
	pessoa(std::string nome, std::string detalhes, time_t data_cadastro, std::string rg = "", std::string cpf = "", int idade = -1, bool estado = false){
		this -> rg = rg;
		this -> cpf = cpf;
		this -> nome = nome;
		this -> detalhes = detalhes;
		this -> data_cadastro = data_cadastro;
		this -> ultimo_update = data_cadastro;
		this -> estado = estado;
		this -> idade = idade;
	}

	void changeEstado(bool estado){
		this -> estado = estado;
	}
	void atualizaUpdate(time_t ultimo_update){
		this -> ultimo_update = ultimo_update;
	}
	
	unsigned int getID(){
		return this -> id;
	}

	std::string getNome(){
		return this -> nome;
	}
	std::string getCPF(){
		return this -> cpf;
	}
	std::string getRG(){
		return this -> rg;
	}

	std::string getDetalhes(){
		return this -> detalhes;
	}

};
//
// #pragma db value(Pessoa) definition
//
#pragma db object
class denuncia {
private:
    friend class odb::access;

	#pragma db id auto
	unsigned int id;

	#pragma db not_null
	bool estado; //valido

	#pragma db not_null
	pessoa * pessoa_denuncia;

	#pragma db not_null
	std::string latitude;
	#pragma db not_null
	std::string longitude;

	#pragma db not_null
	usuario * usuario_denuncia;

	std::string latitude_denuncia;
	std::string longitude_denuncia;

	#pragma db not_null
	std::string detalhes;

	#pragma db not_null
	time_t data_denuncia;
public:
	denuncia(){};
	denuncia(pessoa * pessoa_denuncia, std::string latitude, std::string longitude, usuario * usuario_denuncia, std::string detalhes, time_t data_denuncia, std::string latitude_denuncia = "", std::string longitude_denuncia = "", bool estado = false){
		this -> pessoa_denuncia = pessoa_denuncia;
		this -> latitude = latitude;
		this -> longitude = longitude;
		this -> usuario_denuncia = usuario_denuncia;
		this -> detalhes = detalhes;
		this -> data_denuncia = data_denuncia;
		this -> latitude_denuncia = latitude_denuncia;
		this -> longitude_denuncia = longitude_denuncia;
		this -> estado = estado;
	}
	
	unsigned int getID(){
		return this -> id;
	}
	
	unsigned int getFkPessoa(){
		return (this -> pessoa_denuncia -> getID());
	}

	void changeEstado(bool estado){
		this -> estado = estado;
	}

	std::string getLatitude(){
		return this -> latitude;
	}
	std::string getLongitude(){
		return this -> longitude;
	}
	std::string getLatitudeD(){
		return this -> latitude_denuncia;
	}
	std::string getLongitudeD(){
		return this -> longitude_denuncia;
	}
	std::string getDetalhes(){
		return this -> detalhes;
	}
	time_t getDataDenuncia(){
		return this -> data_denuncia;
	}

};


#endif
