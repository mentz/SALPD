#ifndef __PAPEL_HXX__
#define __PAPEL_HXX__

#include <odb/core.hxx>
#include <string>
/*
Papel (
	int papel,
	varchar permissoes
	)
*/

#pragma db object
class Papel {
private:
	#pragma db id auto
	unsigned long id;

	friend class odb::access;

	int papel;
	std::string permissoes; // Somente descritivo. As restrições em si são implementadas
					   // no programa ou na base de dados por meio de triggers.

	Papel() {}
public:
	Papel(int papel, std::string permissoes){
		this -> papel = papel;
		this -> permissoes = permissoes;
	}

	void setPapel(int papel){
		this -> papel = papel;
	}
	void setPermissoes(std::string permissoes){
		this -> permissoes = permissoes;
	}

	int getPapel(){
		return this -> papel;
	}
	std::string getPermissoes(){
		return this -> permissoes;
	}

};

#endif
