#ifndef __SALPD_FUNCOES__
#define __SALPD_FUNCOES__

#include "commons.hpp"
#include "AllClass.hxx"
#include "AllClass-odb.hxx"
#include "DAO.hpp"
//
// extern Usuario admin;
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
//
// Usuario criaUsuario(){
// 	system(CLEAR);
// 	Usuario usu;
// 	int id;
// 	string rg;
// 	string cpf;
// 	string nome;
// 	string sobrenome;
// 	string hash_senha = "123456";
// 	string data_cadastro = "agora";
// 	string ultimo_acesso = "";
//
// 	id = 1;
// 	cout << "\t\tFormulario de Usuario\n\n";
//
// 	cout << "Digite o RG: ";
// 	cin >> rg;
//
// 	cout << "Digite o CPF: ";
// 	cin >> cpf;
//
// 	cout << "Digite o nome: ";
// 	cin >> nome;
//
// 	cout << "Digite o sobrenome: ";
// 	cin >> sobrenome;
//
// 	usu = Usuario(id, rg, cpf, nome, sobrenome, hash_senha, data_cadastro, ultimo_acesso);
// 	cout << "Usuario criado com sucesso!\n";
// 	return usu;
// }
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
// void menuAdmin(){
// 	int sair = 0;
// 	char ch;
// 	//Usuario* usuario;
//
// 	while (!sair){
// 		int op;
// 		system(CLEAR);
// 		// clearConsole();
// 		// Apresentar opções
// 		printf("\t\tMenu do Admin\n\n");
// 		printf("1 -> Criar Usuarios\n");
// 		printf("2 -> Sair\n");
// 		cout << "> ";
// 		cin >> op;
// 		switch (op) {
// 			case 1:
// 				criaUsuario();
// 				cin >> ch;
// 				break;
// 			case 2:
// 				sair = 1;
// 				break;
// 			default:
// 				printf("Digite uma opcao valida!!\n");
// 				break;
// 		}
// 	}
//
// }
//
void createDenuncia(auto_ptr<database> db){
    system(CLEAR);

	double latitude;
	double longitude;
	string endereco;
	string pessoa;
	unsigned int pes;
	string detalhes;
	string usuario;
	unsigned int usu;
	string data_hora_visto;

	latitude = 30;
	longitude= 30;

	getchar();
	cout << "\t\tFormulario de Denuncias: \n\n";
	cout << "Nome do desaparecido(a): ";
	getline(cin, pessoa);
	// lista = dao.getPessoaPeloNome(pessoa);

	cout << "Endereco: ";
	getline(cin, endereco);

	cout << "Quando ele(a) foi visto(a): ";
	getline(cin, data_hora_visto);

	cout << "Seu nome: ";
	getline(cin, usuario);

	cout << "Detalhes: ";
	getline(cin, detalhes);

	pes = 1;
	usu = 3;

	denuncia den = denuncia(latitude,
				   longitude,
			   	   endereco,
				   pes,
				   detalhes,
				   usu,
				   data_hora_visto);

	transaction t (db -> begin());
	unsigned int id = db -> persist(den);
	t.commit();
}
//

void menu(auto_ptr<database> db){
	int sair = 0;
	bool logado = true;
	char ch;
	usuario usu;
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
				// usu = verificaLogin();
				// logado = true;
				// cin >> ch;
				// if(usuario.getID() == 0)
				// 	menuAdmin();
				break;
			case 2:
				if(!logado){
					cout << "Logue no sistema antes!" << endl;
					cin >> ch;
				}
				else{
					createDenuncia(db);
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
