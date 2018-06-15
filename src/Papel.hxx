#include "commons.hpp"

/*
Papel (
	int papel,
	varchar permissoes
	)
*/

class Papel{
private:
	int papel;
	string permissoes;

public:
	Papel();
	Papel(int papel, string permissoes);

	void setPapel(int papel);
	void setPermissoes(string permissoes);

	int getPapel();
	string getPermissoes();

};

/* CONSTRUCTORS */
Papel::Papel(){
	this->papel = -1;
	this->permissoes = "";
}
Papel::Papel(int papel, string permissoes){
	this->papel = papel;
	this->permissoes = permissoes;
}

/* SETTERS */
void Papel::setPapel(int papel){
	this->papel = papel;
}
void Papel::setPermissoes(string permissoes){
	this->permissoes = permissoes;
}

/* GETTERS */
int Papel::getPapel(){
	return papel;
}
string Papel::getPermissoes(){
	return permissoes;
}