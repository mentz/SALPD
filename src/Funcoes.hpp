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

void menuAdmin(shared_ptr<database> db){
	int op, ret;
	system(CLEAR);
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
			newAuditoria(db, "Criar novo usuario", user);
			break;
		case 2:
			user = getAnonimo();
			newAuditoria(db, "Sair da conta", user);
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
	printf("2 -> Cadastrar pessoa desaparecida\n");
	printf("3 -> Fazer denuncia\n");
	printf("4 -> Sair\n");
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
			ret = DAO::getInstance().createPessoa(db);
			if(ret){
				cout << "Pessoa cadastrada com sucesso!" << endl;
			}
			getchar();
			newAuditoria(db, "Cadastrar pessoa desaparecida", user);
			break;
		case 3:
			newAuditoria(db, "Cadastrar denuncia", user);
			ret = DAO::getInstance().createDenuncia(db, user);
			if(ret){
				cout << "Denuncia feita com sucesso!" << endl;
			}
			getchar();
			break;
		case 4:
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
			default: //ANONIMO
				menuAnonimo(db, &sair);
				break;
		}
	}
}

#endif
