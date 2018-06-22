#ifndef __SALPD_FUNCOES__
#define __SALPD_FUNCOES__

#include "commons.hpp"
#include "AllClass.hxx"
#include "AllClass-odb.hxx"
#include "DAO.hpp"
//
// extern Usuario admin;
//
//
// Usuario verificaLogin(){
// 	system(CLEAR);
// 	Usuario usu;
// 	int id;
// 	string senha;
//
// 	cout << "Digite seu id: ";
// 	cin >> id;
//
// 	cout << "Digite sua senha: ";
// 	cin >> senha;
//
// 	if( id == admin.getID() && senha == admin.getHashSenha()){
// 		cout << "Bem vindo Admin" << endl;
// 		return admin;
// 	}
// }
//
void menuAdmin(auto_ptr<database> db){
	int sair = 0;
	char ch;
	//Usuario* usuario;

	while (!sair){
		int op;
		system(CLEAR);
		// clearConsole();
		// Apresentar opções
		printf("\t\tMenu do Admin\n\n");
		printf("1 -> Criar Usuarios\n");
		printf("2 -> Sair\n");
		cout << "> ";
		cin >> op;
		switch (op) {
			case 1:
				DAO::getInstance().criaUsuario(db);
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
//
//

void menu(auto_ptr<database> db){
	int sair = 0, user, r;
	bool logado = false;
	char ch;
	string line;
	stringstream command;
	while (!sair){
		int op;
		system(CLEAR);
		// Apresentar opções
		if(logado and user == 1){
			menuAdmin(db);
			user = -1;
			logado = false;
		} else {
			printf("\t\tBanco de dados\n\n");
			printf("1 -> Login\n");
			printf("2 -> Fazer denuncia\n");
			printf("3 -> Sair\n");
			cout << "> ";
			getline(cin, line);
			command = stringstream(line);
			command >> op;
			switch (op) {
				case 1:
					r = DAO::getInstance().verificaLogin(db);
					if(r != -1){
						user = r;
						logado = 1;
					}
					break;
				case 2:
					if(!logado){
						cout << "Logue no sistema antes!" << endl;
						getchar();
					}
					else{
						DAO::getInstance().createDenuncia(db);
						// dar push_back nessa denuncia??
						cout << "Denuncia feita com sucesso!" << endl;
						getchar();
					}
					break;
				case 3:
					sair = 1;
					break;
				default:
					printf("Digite uma opcao valida!!\n");
					sair = 1; // Pra não fazer mais o loop feio
					break;
			}
		}
	}

	// DAO * otherDAO = DAO::getInstance();
	// otherDAO -> add();
	// otherDAO -> printCnt();
}

#endif
