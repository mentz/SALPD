#include <vector>
#include <cstdio>

#include "Funcoes.hpp"
#include "DAO.hpp"

int main(int argc, char **argv){
	shared_ptr<database> db;
	try {
		db = shared_ptr<database>(new odb::pgsql::database(argc, argv));
	} catch(const odb::exception &e){
		cerr << e.what() << endl;
	}

	menu(db);

	return 0;
}
