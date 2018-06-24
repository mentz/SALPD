#ifndef __SALPD_FUNCOES__
#define __SALPD_FUNCOES__

#include "commons.hpp"
#include "AllClass.hxx"
#include "AllClass-odb.hxx"
#include "DAO.hpp"

usuario user;

void newAuditoria(shared_ptr<database> db, string acao, usuario user){
	try {
		auditoria aud(acao, &user, getTime());
		transaction t(db -> begin());

		db -> persist(aud);

		t.commit();
	} catch(odb::exception &e){
		cerr << e.what() << endl;
	}
}

void menuInformante(shared_ptr<database> db){
	int op, ret;
	system(CLEAR);

	printf("\t\t Menu do Informante\n\n");
	printf("1 -> Adicionar nova denuncia\n");
	printf("2 -> Sair\n");
	printf("> ");
	cin >> op;
	getchar();
	switch(op){
		case 1:
			ret = DAO::getInstance().createDenuncia(db, user, true);
			if(ret == 1){
				cout << "Denuncia cadastrada com sucesso!" << endl;
			}
			newAuditoria(db, "Cadastrar nova denuncia", user);
			break;
		case 2:
			newAuditoria(db, "Saiu da conta", user);
			user = getAnonimo();
			break;
		default:
			printf("Digite uma opcao valida!\n");
			break;
	}
	
}

void menuAgente(shared_ptr<database> db){
	int op, ret;
	system(CLEAR);

	printf("\t\t Menu do Agente\n\n");
	printf("1 -> Adicionar nova denuncia\n");
	printf("2 -> Validas denuncias\n");
	printf("3 -> Sair\n");
	printf("> ");
	cin >> op;
	getchar();
	switch(op){
		case 1:
			newAuditoria(db, "Cadastrar nova denuncia", user);
			DAO::getInstance().createDenuncia(db, user, true);
			if(ret == 1){
				cout << "Denuncia cadastrada com sucesso!" << endl;
			}
			getchar();
			break;
		case 2:
			newAuditoria(db, "Check na lista de denuncias", user);
			DAO::getInstance().checkDenuncias(db);
			break;
		case 3:
			newAuditoria(db, "Saiu da conta", user);
			user = getAnonimo();
			break;
		default:
			printf("Digite uma opcao valida!\n");
			break;
	}
}

void menuGestor(shared_ptr<database> db){
	int op, ret;
	system(CLEAR);

	printf("\t\t Menu do Gestor\n\n");
	printf("1 -> Criar Usuarios\n");
	printf("2 -> Adicionar pessoa desaparecida\n");
	printf("3 -> Adicionar nova denuncia\n");
	printf("4 -> Validar denuncias\n");
	printf("5 -> Sair\n");
	printf("> ");
	cin >> op;
	getchar();
	switch(op){
		case 1:
			ret = DAO::getInstance().criaUsuario(db);
			if(ret){
				cout << "Usuario criado com sucesso!" << endl;
			}
			newAuditoria(db, "Criar novo usuario", user);
			getchar();
			break;
		case 2:
			ret = DAO::getInstance().createPessoa(db, true);
			if(ret){
				cout << "Pessoa cadastrada com sucesso!" << endl;
			}
			newAuditoria(db, "Cadastrar nova pessoa", user);
			getchar();
			break;
		case 3:
			ret = DAO::getInstance().createDenuncia(db, user, true);
			if(ret){
				cout << "Denuncia cadastrada com sucesso!" << endl;
			}
			newAuditoria(db, "Cadastrar nova denuncia", user);
			getchar();
			break;
		case 4:
			DAO::getInstance().checkDenuncias(db);
			newAuditoria(db, "Check na lista de denuncias", user);
			break;
		case 5:
			newAuditoria(db, "Saiu da conta", user);
			user = getAnonimo();
			break;
		default:
			printf("Digite uma opcao valida!\n");
			break;
	}
}

void menuAdmin(shared_ptr<database> db){
	int op, ret;
	system(CLEAR);
	// Apresentar opções
	printf("\t\tMenu do Admin\n\n");
	printf("1 -> Criar Usuarios\n");
	printf("2 -> Sair\n");
	printf("> ");
	cin >> op;
	getchar();
	switch (op) {
		case 1:
			ret = DAO::getInstance().criaUsuario(db);
			if(ret == 1)
				cout << "Usuario criado com sucesso!\n";
			getchar();
			newAuditoria(db, "Criar novo usuario", user);
			break;
		case 2:
			newAuditoria(db, "Sair da conta", user);
			user = getAnonimo();
			break;
		default:
			printf("Digite uma opcao valida!!\n");
			break;
	}
}

void menuAnonimo(shared_ptr<database> db, int *sair){
	int op, ret;
	char ch;
	system(CLEAR);

	// Apresentar opções
	printf("\t\tSALPD\n\n");

	printf("Logado como: %s\n\n", user.getFkPapel() -> getPapel().c_str());

	printf("1 -> Login\n");
	printf("2 -> Fazer denuncia\n");
	printf("3 -> Sair\n");
	cout << "> ";
	cin >> op;
	getchar();
	switch (op) {
		case 1:
			user = DAO::getInstance().verificaLogin(db);
			if(user.getFkPapel() -> getID() != ANONIMO){
				cout << "Login efetuado com sucesso!" << endl;
			}
			getchar();
			newAuditoria(db, "Logar no sistema", user);
			break;
		case 2:
			newAuditoria(db, "Cadastrar denuncia", user);
			ret = DAO::getInstance().createDenuncia(db, user);
			if(ret){
				cout << "Denuncia feita com sucesso!" << endl;
			}
			getchar();
			break;
		case 3:
			*sair = 1;
			newAuditoria(db, "Sair do sistema", user);
			break;
		default:
			printf("Digite uma opcao valida!!\n");
			getchar();
			break;
	}
}

void menu(shared_ptr<database> db){
	user = getAnonimo();
	int sair = 0;
	while (!sair){
		switch(user.getFkPapel() -> getID()){
			case ADMIN:
				menuAdmin(db);
				break;
			case GESTOR:
				menuGestor(db);
				break;
			case INFORMANTE:
				menuInformante(db);
				break;
			case AGENTE:
				menuAgente(db);
				break;
			default: //ANONIMO
				menuAnonimo(db, &sair);
				break;
		}
	}
}

#endif
