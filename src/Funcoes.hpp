#ifndef __SALPD_FUNCOES__
#define __SALPD_FUNCOES__

#include "commons.hpp"
#include "DAO.hpp"

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

void clearConsole()
{
	/* Na verdade não limpa, apenas imprime um bocadinho de
	 * '\n's para subir a sujeira.
	 */
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		   "\n\n      \n\n    \n\n\n      \n\n    \n\n\n\n\n\n\n\n\n\n"
		   "\n  \n\n\n\n  \n\n  \n  \n\n\n\n  \n\n  \n\n\n\n\n\n\n\n\n"
		   "\n\n    \n\n  \n\n  \n  \n\n\n\n  \n\n  \n\n\n\n\n\n\n\n\n"
		   "\n\n\n\n  \n        \n  \n\n\n\n  \n\n  \n\n\n\n\n\n\n\n\n"
		   "\n      \n\n  \n\n  \n\n      \n\n    \n\n\n\n\n\n\n\n\n\n"
		   "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		   "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		   "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		   "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


void menu(){
	int sair = 0;
	while (!sair){
		int op;
		system(CLEAR);
		// clearConsole();
		// Apresentar opções
		printf("\t\tBando de dados Bucadinho/Clelio\n\n");
		printf("1 -> Login\n");
		printf("2 -> Fazer denuncia\n");
		printf("3 -> Sair\n");
		cout << "> ";
		cin >> op;
		switch (op) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				sair = 1;
				break;
			default:
				printf("Digite uma opcao valida!!\n");
				break;
		}
	}

	// DAO * otherDAO = DAO::getInstance();
	// otherDAO -> add();
	// otherDAO -> printCnt();
}

#endif
