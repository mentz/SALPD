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
Denuncia fazDenuncia(){
	system(CLEAR);

	int id;
	double latitude;
	double longitude;
	string endereco;
	string pessoa;
	shared_ptr<Pessoa> pes;
	string detalhes;
	string usuario;
	shared_ptr<Usuario> usu;
	string data_hora_visto;

	Denuncia den;

	id = 0;
	latitude = 30;
	longitude= 30;

	getchar();
	cout << "\t\tFormulario de Denuncias: \n\n";
	cout << "Nome do desaparecido(a): ";
	getline(cin, pessoa);

	cout << "Endereco: ";
	getline(cin, endereco);

	cout << "Quando ele(a) foi visto(a): ";
	getline(cin, data_hora_visto);

	cout << "Seu nome: ";
	getline(cin, usuario);

	cout << "Detalhes: ";
	getline(cin, detalhes);

	pes = shared_ptr<Pessoa> (new Pessoa());
	usu = shared_ptr<Usuario>(new Usuario());

	den = Denuncia(	id,
		 		   	latitude,
				   	longitude,
			   	   	endereco,
					pes,
					detalhes,
					usu,
					data_hora_visto);

	return den;
}


void menu(){
	int sair = 0;
	bool logado = false;
	char ch;
	Denuncia denuncia;
	//Usuario* usuario;

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
				logado = true;
				cout << "Seja bem-vindo!" << endl;
				cin >> ch;
				break;
			case 2:
				if(!logado){
					cout << "Logue no sistema antes!" << endl;
					cin >> ch;
				}
				else{
					denuncia = fazDenuncia();
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
