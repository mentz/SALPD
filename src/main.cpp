#include <vector>
#include <cstdio>

#include "Auditoria.hxx"
#include "Denuncia.hxx"
#include "Papel.hxx"
#include "Usuario.hxx"
#include "UsuarioPapel.hxx"
#include "Funcoes.hpp"
#include "DAO.hpp"

int main(int argc, char **argv)
{
	/* Remover este comentário quando formos usar ODB
	if (argc < 6)
	{
		// TODO Mensagens descrevendo uso do programa
		printf("Uso: $ %s <db_address> <db_port> <db_user> <db_pass> <db_database>\n", argv[0]);
		return 1;
	}

	// Definição de parâmetros
	char DB_ADDR[512], DB_USER[128], DB_PASS[128], DB_DATABASE[128];
	int DB_PORT;

	sscanf(argv[1], "%s", DB_ADDR);
	sscanf(argv[2], "%d", DB_PORT);
	sscanf(argv[3], "%s", DB_USER);
	sscanf(argv[4], "%s", DB_PASS);
	sscanf(argv[5], "%s", DB_DATABASE);
	*/

	menu();

	return 0;
}
