#ifndef __ALL_CLASS_HXX__
#define __ALL_CLASS_HXX__

#include <odb/core.hxx>
#include <memory>
#include <iostream>
#include <cstdlib>
#include <cstdio>

#pragma db object
class papel {
private:
	#pragma db id auto
	unsigned long id;

	friend class odb::access;

	// As restrições em si são implementadas no programa com
	//  base nas restrições apresentadas na forma "rw usuario"
	//  deste atributo.
	std::string permissoes;
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
	// std::shared_ptr<Permissao> grupo;
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
	std::string getRG();
	std::string getCPF();
	std::string getNome();
	std::string getSobrenome();
	std::string getHashSenha();
	std::string getDataCadastro();
	std::string getUltimoAcesso();
};

// #pragma db value(Usuario) definition

/*
#pragma db object
class usuariopapel{
private:
    friend class odb::access;

    #pragma db id auto
    unsigned long id;

    // #pragma db type(definition)
	unsigned int usuario;
    // #pragma db type(definition)
	unsigned int papel;
	// shared_ptr<Auditoria> auditoria;
	bool valido;
public:
    usuariopapel() {};
	usuariopapel(unsigned int usuario, unsigned int papel,
				 bool valido);
	//			 bool valido , shared_ptr<Auditoria> auditoria);

	unsigned int getUsuario();
	unsigned int getPapel();
	// shared_ptr<Auditoria> getAuditoria();
	bool getValido();
	bool setValido();
};

// #pragma db value(UsuarioPapel) definition
*/

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

	int estado;	// 0 para perdido, 1 para encontrado
	std::string cpf;
	std::string rg;
	std::string nome;
	std::string sobrenome;
	//shared_ptr<Denuncia> ultimo_visto;
	unsigned int ultima_modificacao;
public:

	pessoa() {};
	pessoa(int id, std::string cpf, std::string rg, std::string nome, std::string sobrenome, unsigned int ultima_modificacao);

	void setID(int id);
	void setCPF(std::string cpf);
	void setRG(std::string rg);
	void setNome(std::string nome);
	void setSobrenome(std::string sobrenome);
	//void setUltimoVisto(shared_ptr<Denuncia> ultimo_visto);
	void setUltimaModificacao(unsigned int ultima_modificacao);

	int getID();
	std::string getCPF();
	std::string getRG();
	std::string getNome();
	std::string getSobrenome();
	//shared_ptr<Denuncia> getUltimoVisto();
	unsigned int getUltimaModificacao();
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

	double latitude;
	double longitude;
	std::string endereco;
	unsigned int pessoa;  // Pessoa desaparecida
	std::string detalhes;
	unsigned int usuario;	// Inserido por
	std::string data_hora_visto;
public:
	denuncia(){};
	denuncia(double latitude, double longitude, std::string endereco,
			 unsigned int pessoa, std::string detalhes, unsigned int usuario,
			 std::string data_hora_visto){
                 this -> latitude = latitude;
                 this -> longitude = longitude;
                 this -> endereco = endereco;
                 this -> pessoa = pessoa;
                 this -> detalhes = detalhes;
                 this -> usuario = usuario;
                 this -> data_hora_visto = data_hora_visto;

             }

	void setID(int id);
	void setLatitude(double latitude);
	void setLongitude(double longitude);
	void setEndereco(std::string endereco);
	void setPessoa(unsigned int pessoa);
	void setDetalhes(std::string detalhes);
	void setUsuario(unsigned int usuario);
	void setDataHoraVisto(std::string data_hora_visto);

	int getID();
	double getLatitude();
	double getLongitude();
	std::string getEndereco();
	unsigned int getPessoa();
	std::string getDetalhes();
	unsigned int getUsuario();
	std::string getDataHoraVisto();

};
//
// #pragma db value(Denuncia) definition

#endif
