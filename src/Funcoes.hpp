#ifndef __SALPD_FUNCOES__
#define __SALPD_FUNCOES__

#include "commons.hpp"
#include "DAO.hpp"

extern Usuario admin;

void clearConsole(){
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

Usuario criaUsuario(){
	system(CLEAR);
	Usuario usu;
	int id;
	string rg;
	string cpf;
	string nome;
	string sobrenome;
	string hash_senha = "123456";
	string data_cadastro = "agora";
	string ultimo_acesso = "";

	id = 1;
	cout << "\t\tFormulario de Usuario\n\n";

	cout << "Digite o RG: ";
	cin >> rg;

	cout << "Digite o CPF: ";
	cin >> cpf;

	cout << "Digite o nome: ";
	cin >> nome;

	cout << "Digite o sobrenome: ";
	cin >> sobrenome;

	usu = Usuario(id, rg, cpf, nome, sobrenome, hash_senha, data_cadastro, ultimo_acesso);
	cout << "Usuario criado com sucesso!\n";
	return usu;
}

Usuario verificaLogin(){
	system(CLEAR);
	Usuario usu;
	int id;
	string senha;

	cout << "Digite seu id: ";
	cin >> id;

	cout << "Digite sua senha: ";
	cin >> senha;

	if( id == admin.getID() && senha == admin.getHashSenha()){
		cout << "Bem vindo Admin" << endl;
		return admin;
	}
}

void menuAdmin(){
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
				criaUsuario();
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

Denuncia criaDenuncia(){

}


void menu(){
	int sair = 0;
	bool logado = false;
	char ch;
	Denuncia denuncia;
	Usuario usuario;

	while (!sair){
		int op;
		system(CLEAR);
		// clearConsole();
		// Apresentar opções
		printf("\t\tBando de dados\n\n");
		printf("1 -> Login\n");
		printf("2 -> Fazer denuncia\n");
		printf("3 -> Sair\n");
		cout << "> ";
		cin >> op;
		switch (op) {
			case 1:
				usuario = verificaLogin();
				logado = true;
				cin >> ch;
				if(usuario.getID() == 0)
					menuAdmin();
				break;
			case 2:
				if(!logado){
					cout << "Logue no sistema antes!" << endl;
					cin >> ch;
				}
				else{
					denuncia = criaDenuncia();
					// dar push_back nessa denuncia??
					cout << "Denuncia feita com sucesso!" << endl;
					cin >> ch;
				}
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
