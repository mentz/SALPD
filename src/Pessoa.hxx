#include "commons.hpp"

/* Pessoa (
		int id PRIMARY KEY,
		char[11] CPF NOT NULL,
		char[8] RG NOT NULL,
		varchar nome NOT NULL,
		varchar sobrenome NOT NULL,
		Denuncia ultimo_visto NOT NULL FOREIGN KEY,
		Auditoria ultima_modificacao NOT NULL FOREIGN KEY,
		?? etc
		)
*/

class Pessoa{

private:
	int id;
	int estado;	// 0 para perdido, 1 para encontrado
	string cpf;
	string rg;
	string nome;
	string sobrenome;
	shared_ptr<Denuncia> ultimo_visto;
	shared_ptr<Auditoria> ultima_modificacao;

public:

	Pessoa();
	Pessoa(int id, string cpf, string rg, string nome, string sobrenome,
		   shared_ptr<Denuncia> ultimo_visto, shared_ptr<Auditoria> ultima_modificacao);

	void setID(int id);
	void setCPF(string cpf);
	void setRG(string rg);
	void setNome(string nome);
	void setSobrenome(string sobrenome);
	void setUltimoVisto(shared_ptr<Denuncia> ultimo_visto);
	void setUltimaModificacao(shared_ptr<Auditoria> ultima_modificacao);

	int getID();
	string getCPF();
	string getRG();
	string getNome();
	string getSobrenome();
	shared_ptr<Denuncia> getUltimoVisto();
	shared_pt<Auditoria> getUltimaModificacao();
};

/* CONSTRUCTORS */
Pessoa::Pessoa(){
	this->id = -1;
	this->cpf = "";
	this->rg = "";
	this->nome = "";
	this->sobrenome = "";
	this->ultimo_visto = NULL;
	this->ultima_modificacao = NULL;
}

Pessoa::Pessoa(int id, string cpf, string rg, string nome, string sobrenome,
	           shared_ptr<Denuncia> ultimo_visto, shared_ptr<Auditoria> ultima_modificacao){
	this->id = id;
	this->cpf = cpf;
	this->rg = rg;
	this->nome = nome;
	this->sobrenome = sobrenome;
	this->ultimo_visto = ultimo_visto;
	this->ultima_modificacao = ultima_modificacao;
}

/* SETTERS */
void Pessoa::setID(int id){
	this->id = id;
}

void Pessoa::setCPF(string cpf){	
	this->cpf = cpf;
}

void Pessoa::setRG(string rg){
	this->rg = rg;
}

void Pessoa::setNome(string nome){
	this->nome = nome;
}

void Pessoa::setSobrenome(string sobrenome){
	this->sobrenome = sobrenome;
}

void Pessoa::setUltimoVisto(shared_ptr<Denuncia> ultimo_visto){
	this->ultimo_visto = ultimo_visto;
}

void Pessoa::setUltimaModificacao(shared_ptr<Auditoria> ultima_modificacao){
	this->ultima_modificacao = ultima_modificacao;
}

/* GETTERS */
int Pessoa::getID(){
	return this->id;
}

string Pessoa::getCPF(){
	return this->cpf;
}

string Pessoa::getRG(){
	return this->rg;
}

string Pessoa::getNome(){
	return this->nome;
}

string Pessoa::getSobrenome(){
	return this->sobrenome;
}

shared_ptr<Denuncia> Pessoa::getUltimoVisto(){
	return this->ultimo_visto;
}

shared_ptr<Auditoria> Pessoa::getUltimaModificacao(){
	return this->ultima_modificacao;
}
