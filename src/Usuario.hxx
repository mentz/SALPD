#include "commons.hpp"
/* Usuario (
		int id PRIMARY KEY,
		char[11] cpf UNIQUE,
		char[8] rg UNIQUE,
		varchar nome,
		varchar sobrenome,
		char[10] hash_senha,
		date data_cadastro,
		date ultimo_acesso
	)*/

//#pragma db object table ("usuario")
class Usuario{
private:
	//friend class odb::access;
	int id
	string rg;
	string cpf;
	string nome;
	string sobrenome;
	string hash_senha;
	string data_cadastro;
	string ultimo_acesso;

public:

	Usuario();
	Usuario(int id, string rg, string cpf, string nome, string sobrenome, string hash_senha, string data_cadastro, string ultimo_acesso);

	void setID(int id);
	void setRG(string rg);
	void setCPF(string cpf);
	void setNome(string nome);
	void setSobrenome(string sobrenome);
	void setHashSenha(string hash_senha);
	void setDataCadastro(string data_cadastro);
	void setUltimoAcesso(string ultimo_acesso);

	int getID();
	string getRG();
	string getCPF();
	string getNome();
	string getSobrenome();
	string getHashSenha();
	string getDataCadastro();
	string getUltimoAcesso();
};

/* CONSTRUCTORS */

Usuario::Usuario(){
	this->id = -1;
	this->rg = "";
	this->cpf = "";
	this->nome = "";
	this->sobrenome = "";
	this->hash_senha = "";
	this->data_cadastro = "";
	this->ultimo_acesso = "";
}

Usuario::Usuario(int id, string rg, string cpf, string nome, string sobrenome, string hash_senha, string data_cadastro, string ultimo_acesso){
	this->id = id;
	this->rg = rg;
	this->cpf = cpf;
	this->nome = nome;
	this->sobrenome = sobrenome;
	this->hash_senha = hash_senha;
	this->data_cadastro = data_cadastro;
	this->ultimo_acesso = ultimo_acesso;	
}

/* SETTERS */
void Usuario::setID(int id){
	this -> id = id;
}

void Usuario::setRG(string rg){
	this -> rg = rg;
}

void Usuario::setCPF(string cpf){
	this -> cpf = cpf;
}

void Usuario::setNome(string nome){
	this -> nome = nome;
}

void Usuario::setSobrenome(string sobrenome){
	this -> sobrenome = sobrenome;
}

void Usuario::setHashSenha(string hash_senha){
	this -> hash_senha = hash_senha;
}

void Usuario::setDataCadastro(string data_cadastro){
	this -> data_cadastro = data_cadastro;
}

void Usuario::setUltimoAcesso(string ultimo_acesso){
	this -> ultimo_acesso = ultimo_acesso;
}

/* GETTERS */
int Usuario::getID(){
	return this -> id;
}

string Usuario::getRG(){
	return this -> rg;
}

string Usuario::getCPF(){
	return this -> cpf;
}

string Usuario::getNome(){
	return this -> nome;
}

string Usuario::getSobrenome(){
	return this -> sobrenome;
}

string Usuario::getHashSenha(){
	return this -> hash_senha;
}

string Usuario::getDataCadastro(){
	return this -> data_cadastro;
}

string Usuario::getUltimoAcesso(){
	return this -> ultimo_acesso;
}

