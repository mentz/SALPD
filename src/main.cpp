#include <vector>
#include <cstdio>

// #include "Auditoria.hxx"
// #include "Denuncia.hxx"
// #include "Papel.hxx"
// #include "Usuario.hxx"
// #include "UsuarioPapel.hxx"
#include "Funcoes.hpp"
#include "DAO.hpp"

// Usuario admin;

auto_ptr<database> db;

int main(int argc, char **argv){
	try {
		db = auto_ptr<database>(new odb::pgsql::database(argc, argv));
	} catch(const odb::exception &e){
		cerr << e.what() << endl;
	}

	menu(db);

	return 0;
}
