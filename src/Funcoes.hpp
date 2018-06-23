#ifndef __SALPD_FUNCOES__
#define __SALPD_FUNCOES__

#include "commons.hpp"
#include "AllClass.hxx"
#include "AllClass-odb.hxx"
#include "DAO.hpp"

void menuAdmin(shared_ptr<database> db){
	int sair = 0;
	char ch;
	//Usuario* usuario;

	while (!sair){
		int op, ret;
		char ch;
		system(CLEAR);
		// clearConsole();
		// Apresentar opções
		printf("        Menu do Admin\n\n");
		printf("1 -> Criar Usuarios\n");
		printf("2 -> Sair\n");
		cout << "> ";
		cin >> op;
		switch (op) {
			case 1:
				ret = DAO::getInstance().criaUsuario(db);
				if(ret){
					cout << "Usuario criado com sucesso!\n";
				}
				cin >> ch;
				break;
			case 2:
				sair = 1;
				break;
			default:
				printf("Digite uma opcao valida!!\n");
				break;
		}
	}
}

int menuAnonimo(shared_ptr<database> db){
	int op, r = -1, ret;
	char ch;
	system(CLEAR);
	// clearConsole();
	// Apresentar opções
	printf("        SALPD\n\n");
	printf("1 -> Login\n");
	printf("2 -> Fazer denuncia anônima\n");
	printf("3 -> Sair\n");
	cout << "> ";
	cin >> op;
	switch (op) {
		case 1:
			r = DAO::getInstance().verificaLogin(db);
			if(r > 0){
				cout << "Login efetuado com sucesso!" << endl;
			}
			getchar();
			break;
		case 2:
			ret = DAO::getInstance().createDenuncia(db);
			/*
			if(ret){
				cout << "Denuncia feita com sucesso!" << endl;
			}
			*/
			getchar();
			break;
		case 3:
			r = -2;
			break;
		default:
			printf("Digite uma opcao valida!!\n");
			getchar();
			break;
	}
	return r;
}
//
//

void menu(shared_ptr<database> db){

	int sair = 0, user = -1, r;
	bool logado = false;
	char ch;
	while (!sair and user >= -1){
		switch(user){
			case ADMIN:
				menuAdmin(db);
				user = -1;
				break;
			case GESTOR:
				user = -1;
				break;
			case AGENTE:
				user = -1;
				break;
			case INFORMANTE:
				user = -1;
				break;
			default: //ANONIMO
				user = menuAnonimo(db);
				break;
		}
	}
}

#endif
