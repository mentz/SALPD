#ifndef __SALPD_FUNCOES__
#define __SALPD_FUNCOES__

#include "commons.hpp"
#include "AllClass.hxx"
#include "AllClass-odb.hxx"
#include "DAO.hpp"

usuario user;

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
		printf("\t\tMenu do Admin\n\n");
		printf("1 -> Criar Usuarios\n");
		printf("2 -> Sair\n");
		cout << "> ";
		cin >> op;
		getchar();
		switch (op) {
			case 1:
				ret = DAO::getInstance().criaUsuario(db);
				if(ret){
					cout << "Usuario criado com sucesso!\n";
				}
				getchar();
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

void menuAnonimo(shared_ptr<database> db, int & sair){
	int op, ret;
	char ch;
	system(CLEAR);
	// clearConsole();
	// Apresentar opções
	printf("\t\tSALPD\n\n");
	printf("1 -> Login\n");
	printf("2 -> Cadastrar pessoa desaparecida\n");
	printf("3 -> Fazer denuncia\n");
	printf("4 -> Sair\n");
	cout << "> ";
	cin >> op;
	getchar();
	switch (op) {
		case 1:
			user = DAO::getInstance().verificaLogin(db);
			if(user.getFkPapel() -> getPapel() != ANONIMO){
				cout << "Login efetuado com sucesso!" << endl;
			}
			getchar();
			break;
		case 2:
			DAO::getInstance().createPessoa(db);
			if(ret){
				cout << "Cadastro feito com sucesso!" << endl;
			}
			getchar();
			break;
		case 3:
			ret = DAO::getInstance().createDenuncia(db, user);
			if(ret){
				cout << "Denuncia feita com sucesso!" << endl;
			}
			getchar();
			break;
		case 4:
			sair = 1;
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
	user = getAnonimo();
	int sair = 0;
	while (!sair){
		switch(user.getFkPapel() -> getPapel()){
			case ADMIN:
				menuAdmin(db);
				user = getAnonimo();
				break;
			default: //ANONIMO
				menuAnonimo(db, sair);
				break;
		}
	}
}

#endif
