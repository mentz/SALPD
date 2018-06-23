#ifndef __SALPD_FUNCOES__
#define __SALPD_FUNCOES__

#include "commons.hpp"
#include "AllClass.hxx"
#include "AllClass-odb.hxx"
#include "DAO.hpp"

int user = -1;

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

void menuAnonimo(shared_ptr<database> db){
	int op, ret;
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
			user = DAO::getInstance().verificaLogin(db);
			if(user > 0){
				cout << "Login efetuado com sucesso!" << endl;
			}
			getchar();
			break;
		case 2:
			ret = DAO::getInstance().createDenuncia(db, user);
			/*
			if(ret){
				cout << "Denuncia feita com sucesso!" << endl;
			}
			*/
			getchar();
			break;
		case 3:
			user = -2;
			break;
		default:
			printf("Digite uma opcao valida!!\n");
			getchar();
			break;
	}
}
//
//

void menu(shared_ptr<database> db){

	int sair = 0, r;
	bool logado = false;
	char ch;
	while (!sair and user >= -1){
		switch(user){
			case ADMIN:
				menuAdmin(db);
				user = -1;
				break;
			default: //ANONIMO
				menuAnonimo(db);
				break;
		}
	}
}

#endif
