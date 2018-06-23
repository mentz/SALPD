#ifndef __ALL_CLASS_HXX__
#define __ALL_CLASS_HXX__

#include <odb/core.hxx>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <iostream>

#pragma db object
class papel {
private:
	#pragma db id auto
	unsigned long id;

	friend class odb::access;

	std::string permissoes; // Somente descritivo. As restrições em si são implementadas
					   // no programa ou na base de dados por meio de triggers.
public:
    papel() {};
    papel(int, std::string);
    void setPermissoes(std::string);
    int getPapel() const;
    std::string getPermissoes() const;
};

#pragma db object
class usuario{
private:
	friend class odb::access;

    #pragma db id auto
	unsigned long id;

	std::string rg;
	std::string cpf;
	std::string nome;
	std::string sobrenome;
	std::string hash_senha;
	std::string data_cadastro;
	std::string ultimo_acesso;
public:
    usuario() {};
	usuario(std::string rg, std::string cpf, std::string nome, std::string sobrenome, std::string hash_senha, std::string data_cadastro, std::string ultimo_acesso){
			this -> rg = rg;
			this -> cpf = cpf;
			this -> nome = nome;
			this -> sobrenome = sobrenome;
			this -> hash_senha = hash_senha;
			this -> data_cadastro = data_cadastro;
			this -> ultimo_acesso = ultimo_acesso;
		}

	void setID(int id);
	void setRG(std::string rg);
	void setCPF(std::string cpf);
	void setNome(std::string nome);
	void setSobrenome(std::string sobrenome);
	void setHashSenha(std::string hash_senha);
	void setDataCadastro(std::string data_cadastro);
	void setUltimoAcesso(std::string ultimo_acesso);

	int getID(){
		return this -> id;
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
	std::string getSobrenome(){
		return this -> sobrenome;
	}
	std::string getHashSenha(){
		return this -> hash_senha;
	}
	std::string getDataCadastro(){
		return this -> data_cadastro;
	}
	std::string getUltimoAcesso();
};

// #pragma db value(Usuario) definition

#pragma db object
class usuariopapel{
private:
    friend class odb::access;

    #pragma db id auto
    unsigned long id;

	unsigned int usuario;
	unsigned int papel;
	bool valido;
public:
    usuariopapel() {};
	usuariopapel(unsigned int usuario, unsigned int papel,
				 bool valido/*, shared_ptr<Auditoria> auditoria*/);

	unsigned int getUsuario();
	unsigned int getPapel();
	// shared_ptr<Auditoria> getAuditoria();
	bool getValido();
	bool setValido();
};

// #pragma db value(UsuarioPapel) definition

#pragma db object
class auditoria{
private:
	// acao: Ação executada pelo usuário
	#pragma db id auto
	unsigned long id;

	friend class odb::access;

	std::string acao;
	// usuario: Usuário que fez ação
	unsigned int usuario;
public:
    auditoria() {};
	auditoria(std::string acao, unsigned int usuario){
		this -> acao = "";
	}

	void setAcao(std::string acao){
		this -> acao = acao;
	}
	void setUsuario(unsigned int usuario){
		this -> usuario = usuario;
	}

	std::string getAcao() {
		return this -> acao;
	}
	unsigned int getUsuario(){
		return this -> usuario;
	}

	// TODO completar classe
};
//
// #pragma db value(Auditoria) definition
//
#pragma db object
class pessoa {
private:
    #pragma db id auto
	unsigned long id;

    friend class odb::access;

	// int estado;	// 0 para perdido, 1 para encontrado
	std::string cpf;
	std::string rg;
	std::string nome;
	std::vector<std::string> apelidos;
	//shared_ptr<Denuncia> ultimo_visto;
	// unsigned int ultima_modificacao;
public:

	pessoa() {};
	pessoa(std::string cpf, std::string rg, std::string nome, std::vector<std::string> apelidos){
		this -> cpf = cpf;
		this -> rg = rg;
		this -> nome = nome;
		this -> apelidos = apelidos;
	}

	void setID(int id);
	void setCPF(std::string cpf);
	void setRG(std::string rg);
	void setNome(std::string nome);
	//void setUltimoVisto(shared_ptr<Denuncia> ultimo_visto);
	// void setUltimaModificacao(unsigned int ultima_modificacao);

	int getID(){
		return this -> id;
	}
	std::string getCPF(){
		return this -> cpf;
	}
	std::string getRG(){
		return this -> rg;
	}
	std::string getNome(){
		return this -> nome;
	}
	//shared_ptr<Denuncia> getUltimoVisto();
	// unsigned int getUltimaModificacao();
};
//
// #pragma db value(Pessoa) definition
//
#pragma db object
class denuncia {
private:
    friend class odb::access;

	unsigned int id;

	bool valido;

	#pragma db id
	unsigned int pessoa;

	std::vector<std::string> localizacoes;
	std::string ultima_localizacao;
	unsigned int usuario_cadastro;
	unsigned int usuario_ultima_atualizacao;
	std::string data_denuncia;
public:
	denuncia(){};
	denuncia(unsigned int pessoa, std::string ultima_localizacao, unsigned int usuario_cadastro, std::string data_denuncia){
		this -> pessoa = pessoa;
		this -> ultima_localizacao = ultima_localizacao;
		this -> localizacoes.push_back(ultima_localizacao);
		this -> usuario_cadastro = usuario_cadastro;
		this -> usuario_ultima_atualizacao = usuario_cadastro;
		this -> data_denuncia = data_denuncia;
		this -> valido = false;
	}

	//SETTERS
	void setUltimaLocalizacao(std::string ultima_localizacao){
		this -> ultima_localizacao = ultima_localizacao;
	}

	void setUsuarioUltimaLocalizacao(unsigned int user){
		this -> usuario_ultima_atualizacao = user;
	}

	//GETTERS
	bool getValido(){
		return this -> valido;
	}
	unsigned int getPessoa(){
		return this -> pessoa;
	}
	std::string getUltimaLocalizacao(){
		return this -> ultima_localizacao;
	}
	unsigned int getUsuarioCadastro(){
		return this -> usuario_cadastro;
	}
	unsigned int getUsuarioUltimaAtualizacao(){
		return this -> usuario_ultima_atualizacao;
	}
	std::string getDataDenuncia(){
		return this -> data_denuncia;
	}

	//GERAL
	void addLocalizacao(std::string localizacao){
		this -> localizacoes.push_back(localizacao);
	}
};

//
// #pragma db value(Denuncia) definition

#endif
