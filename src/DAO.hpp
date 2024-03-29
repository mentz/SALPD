#ifndef __DAO_HPP__
#define __DAO_HPP__

#include "commons.hpp"
#include "AllClass.hxx"

class DAO {
private:
    DAO();
public:
    static DAO& getInstance();

    int createDenuncia(shared_ptr<database> db, usuario user, bool estado);

    int createPessoa(shared_ptr<database> db, bool estado);

    int criaUsuario(shared_ptr<database> db);
	
	void checkDenuncias(shared_ptr<database> db);
	
	int editPessoa(shared_ptr<database> db, usuario user);

    /* Trecos aleatorios */
    usuario verificaLogin(shared_ptr<database> db);
	void view_pessoa_15_dias(shared_ptr<database> db);
};

#include "DAO.hpp"

DAO::DAO(){}

DAO& DAO::getInstance(){
	static DAO instance;

    return instance;
}

int DAO::createDenuncia(shared_ptr<database> db, usuario user, bool estado = false){
    system(CLEAR);

    printf("\t\tFazer denuncia\n\n");
    pessoa pessoa_desaparecida;

    std::string nome_desaparecido;
    printf("Digite o nome da pessoa desaparecida:\n");
    getline(cin, nome_desaparecido);

    try {
        transaction t(db -> begin());

        typedef odb::query<pessoa> query;
        typedef odb::result<pessoa> result;

        std::string buscaLike = "%%" + nome_desaparecido + "%%";

        result r(db -> query<pessoa>(query::nome.like(buscaLike) and query::estado == false));

        if(r.size() > 0){
            printf("Encontramos algum(ns) resultado(s) com esse nome:\n");
            int idx = 1;
            std::vector<pessoa> pessoas_sistema;
            for(pessoa &p : r){
                printf("%d -> Nome: %s | RG: %8s | CPF: %s\n", idx++, p.getNome().c_str(), p.getRG().c_str(), p.getCPF().c_str());
                pessoas_sistema.push_back(p);
            }
            printf("Digite o numero da pessoa:\n> ");
            int indice;
            scanf("%d", &indice);
            if(indice == -1){
                return 0;
            }
            pessoa_desaparecida = pessoas_sistema[indice - 1];
        } else {
            printf("Nenhuma pessoa cadastrada com esse nome!\n");
            return 0;
        }
        t.commit();
    } catch(odb::exception &e){
        cerr << e.what() << endl;
        return 0;
    }

    printf("Digite a latitude e longitude da ultima localizacao da pessoa desaparecida:\n");
    std::string latitude, longitude;
    printf("\tDigite a latitude: ");
    cin >> latitude;
    printf("\tDigite a longitude: ");
    cin >> longitude;

    printf("Agora descreva alguns detalhes sobre a denuncia:\n");
    getchar();
    std::string detalhes;
    getline(cin, detalhes);

    try {

        transaction t(db -> begin());

        denuncia d = denuncia(&pessoa_desaparecida, latitude, longitude, &user, detalhes, getTime(), "-1", "-1", estado);

        db -> persist(d);

        t.commit();

        return 1;
    } catch(odb::exception &e){
        cerr << e.what() << endl;
        return 0;
	}
}

int DAO::createPessoa(shared_ptr<database> db, bool estado = false){
    system(CLEAR);

    printf("\tCadastro de pessoa desaparecida\n\n");

    printf("Digite o nome da pessoa desaparecida:\n> ");
    std::string nome;
    getline(cin, nome);

    int ret;

    try {
        transaction t(db -> begin());

        typedef odb::query<pessoa> query;
        typedef odb::result<pessoa> result;

        std::string buscaLike = "%%" + nome + "%%";

        result r(db -> query<pessoa>(query::nome.like(buscaLike) and query::estado == false));

        if(r.size()){ //Tem pessoas com o mesmo ou com um nome proximo no banco de dados
            printf("Encontramos algum(ns) resultado(s) com esse nome:\n");
            int idx = 1;
            std::vector<pessoa> pessoas_sistema;
            for(result::iterator it = r.begin(); it != r.end(); it++){
                printf("%d -> Nome: %s | RG %8s | CPF: %s\n", idx++, it -> getNome().c_str(), it -> getRG().c_str(), it -> getCPF().c_str());
                pessoas_sistema.push_back(*it);
            }
            printf("Algum desses eh sua pessoa desaparecida? (S/N)\n");
            printf("> ");
            char c;
            scanf("%c", &c);
            getchar();
            if(c == 'S' or c == 's'){
                printf("Pessoa desaparecida ja cadastrada no sistema!\n");
                ret = 0;
            } else {
                std::string rg, cpf, detalhes;
                int idade;
                printf("Digite o RG da pessoa desaparecida: ");
                getline(cin, rg);
                printf("Digite o CPF da pessoa desaparecida: ");
                getline(cin, cpf);
                printf("Digite a idade da pessoa desaparecida: ");
                cin >> idade;
                getchar();
                printf("Descreva a pessoa desaparecida:\n> ");
                getline(cin, detalhes);

                pessoa nova_pessoa_cadastrada(nome, detalhes, getTime(), rg, cpf, idade, estado);

               	db -> persist(nova_pessoa_cadastrada);
                ret = 1;
            }
        } else { //Nao tem nenhum nome parecido no banco de dados
            std::string rg, cpf, detalhes;
            int idade;
            printf("Digite o RG da pessoa desaparecida: ");
            getline(cin, rg);
            printf("Digite o CPF da pessoa desaparecida: ");
            getline(cin, cpf);
            printf("Digite a idade da pessoa desaparecida: ");
            cin >> idade;
            getchar();
            printf("Descreva a pessoa desaparecida:\n> ");
            getline(cin, detalhes);

            pessoa nova_pessoa_cadastrada(nome, detalhes, getTime(), rg, cpf, idade);

            db -> persist(nova_pessoa_cadastrada);
            ret = 1;
        }
        t.commit();

        return ret;
    } catch(odb::exception &e){
        cerr << e.what() << endl;
        return 0;
    }

}

int DAO::criaUsuario(shared_ptr<database> db){
    system(CLEAR);

    std::string rg, cpf, nome, nome_usuario, hash_senha, role;

    cout << "\t\tFormulario de Usuario\n\n";

    cout << "Digite o RG: ";
    cin >> rg;
	getchar();

    cout << "Digite o CPF: ";
    cin >> cpf;
    getchar();

    cout << "Digite o nome: ";
    getline(cin, nome);

    cout << "Digite o nome de usuario: ";
    cin >> nome_usuario;
	getchar();

    cout << "Digite a senha do novo usuario: ";
    cin >> hash_senha;
	getchar();

    cout << "Qual sera o papel do usuario? (ADMIN, GESTOR, AGENTE, INFORMANTE)\n> ";
    cin >> role;
	getchar();

    int p = (role == "ADMIN" ? ADMIN : (role == "GESTOR" ? GESTOR : (role == "AGENTE" ? AGENTE : (role == "INFORMANTE" ? INFORMANTE : -1))));
	
	if(p == 1){
		cout << "Digite um papel valido!" << endl;
		return 0;
	}

    try {
        usuario usu(rg, cpf, nome, nome_usuario, hash_senha, getTime(), new papel(p, ""));

        transaction t(db -> begin());

        db -> persist(usu);

        t.commit();

        return 1;
    } catch(odb::exception &e){
        cerr << e.what() << endl;
        return 0;
    }
}

void DAO::checkDenuncias(shared_ptr<database> db){
	typedef odb::query<denuncia> query;
	typedef odb::query<pessoa> queryP;
	typedef odb::result<denuncia> result;
	typedef odb::result<pessoa> resultP;

	try {
	
		transaction t(db -> begin());

		result r(db -> query<denuncia> (query::estado == false));
		
		if(r.size() > 0){
			int op;
		
			for(denuncia &d : r){
				system(CLEAR);
				cout << "\t\tValidador de denuncias" << endl << endl;
				resultP p(db -> query<pessoa> (queryP::id == d.getFkPessoa()));
				pessoa p_den = *(p.begin());
				cout << "\tDados da pessoa desaparecida\n";
				cout << "Nome: " << p_den.getNome() << endl;
				cout << "RG: " << p_den.getRG() << endl;
				cout << "CPF: " << p_den.getCPF() << endl;
				cout << "Detalhes: " << p_den.getDetalhes() << endl << endl;
				cout << "\tDados da denuncia\n";
				cout << "Latitude: " << d.getLatitude() << " | Longitude: " << d.getLongitude() << endl;
				if(d.getLatitudeD() != "-1"){
					cout << "Latitude denuncia: " << d.getLatitudeD() << " | Longitude denuncia: " << d.getLongitudeD() << endl;
				}
				cout << "Detalhes: " << d.getDetalhes() << endl;
				cout << "Data da denuncia: " << printTime(d.getDataDenuncia()) << endl;

				cout << endl;
				cout << "Deseja validar essa denuncia? (1 -> Sim | 2 -> Nao | 3 -> Sair)\n> ";
				cin >> op;
				getchar();
				if(op == 3) break;
				else if(op == 1){
					d.changeEstado(true);
					db -> update(d);
					cout << "Denuncia validade com sucesso!" << endl;
					getchar();
				} else {
					db -> erase(d);
					cout << "Denuncia deletada com sucesso!" << endl;
					getchar();
				}
			}
			if(op != 3){
				cout << "Nao ha mais denuncias para serem validadas!" << endl;
			}
		} else {
			cout << "Nao ja mais denuncias para serem validadas!" << endl;
		}
		t.commit();

	} catch(odb::exception &e){
		cerr << e.what() << endl;
	}	

}

int DAO::editPessoa(shared_ptr<database> db, usuario user){
	
	system(CLEAR);

	printf("\t\tEditar pessoa\n\n");
	printf("Digite o nome da pessoa: ");
	std::string nome;
	getline(cin, nome);
	
	int ret;

	try {
         transaction t(db -> begin());

         typedef odb::query<pessoa> query;
         typedef odb::result<pessoa> result;

         std::string buscaLike = "%%" + nome + "%%";

         result r(db -> query<pessoa>(query::nome.like(buscaLike) and query::estado == false));

         if(r.size()){ //Tem pessoas com o mesmo ou com um nome proximo no banco de dados
             printf("Encontramos algum(ns) resultado(s) com esse nome:\n");
             int idx = 1;
             std::vector<pessoa> pessoas_sistema;
             for(result::iterator it = r.begin(); it != r.end(); it++){
                 printf("%d -> Nome: %s | RG %8s | CPF: %s\n", idx++, it -> getNome().c_str(), it -> getRG().c_str(), it -> getCPF().c_str());
                 pessoas_sistema.push_back(*it);
             }
			printf("Digite o numero da pessoa: (-1 para sair)\n> ");
			int idx_c;
			cin >> idx_c;
			getchar();
			if(idx_c == -1) ret = 0;
			else {
				pessoa &p = pessoas_sistema[idx_c - 1];
				int op = 0;
				while(op != -1){
					printf("1 -> Nome | 2 -> RG | 3 -> CPF | 4 -> Detalhes | 5 -> Idade | 6 -> Estado | -1 -> Sair\n");
					printf("Digite qual dado deseja atualizar: ");
					cin >> op;
					getchar();

					std::string n_nome, n_rg, n_cpf, n_detalhes;
					int n_estado, n_idade;

					switch(op){
						case 1:
							printf("Digite o nome: ");
							getline(cin, n_nome);
							p.setNome(n_nome);
							break;
						case 2:
							printf("Digite o RG: ");
							getline(cin, n_rg);
							p.setRG(n_rg);
							break;
						case 3:
							printf("Digite o CPF: ");
							getline(cin, n_cpf);
							p.setCPF(n_cpf);
							break;
						case 4:
							printf("Digite os detalhes: ");
							getline(cin, n_detalhes);
							p.setDetalhes(n_detalhes);
							break;
						case 5:
							printf("Digite a idade: ");
							cin >> n_idade;
							getchar();
							p.setIdade(n_idade);
							break;
						case 6:
							printf("Digite o estado: (1 -> Desaparecido | 2 -> Encontrado)\n> ");
							cin >> n_estado;
							n_estado--;
							p.changeEstado(n_estado);
							break;
					}
				}

				p.atualizaUpdate(getTime());

				db -> update(p);
								
				ret = 1;			

			}
		 } else {
			printf("Nao foi encontrado ninguem com este nome!");
			getchar();
			ret = 0;
		 }

		 t.commit();
	} catch(odb::exception &e){
		cerr << e.what() << endl;
		ret = 0;
	}

	return ret;
}

/*********************************** TRECOS ALEATORIOS **********************************/
usuario DAO::verificaLogin(shared_ptr<database> db){
    system(CLEAR);
    std::string nome_usuario, hash_senha;

    cout << "Digite seu usuario: ";
    getline(cin,  nome_usuario);

    cout << "Digite sua senha: ";
    getline(cin, hash_senha);

	if(nome_usuario == "" && hash_senha == ""){
		return getAnonimo();
	}

    typedef odb::query<usuario> query;
    typedef odb::result<usuario> result;

    try {
        transaction t(db -> begin());
        result r(db -> query<usuario> (query::nome_usuario == nome_usuario and query::hash_senha == hash_senha));

        usuario ret;

        if(r.size() != 1){
            cout << "ID e/ou senha incorretos!" << endl;
            ret = getAnonimo();
            getchar();
        } else {
            ret = *(r.begin());
        }
        t.commit();

        return ret;
    } catch(odb::exception &e){
        cerr << e.what() << endl;
        return getAnonimo();
    }
}

void DAO::view_pessoa_15_dias(shared_ptr<database> db){
	system(CLEAR);
	typedef odb::query<view_pessoa_denuncia> query;
	typedef odb::result<view_pessoa_denuncia> result;

	transaction t(db -> begin());

//	result r(db -> query<view_pessoa_denuncia>(query::data_denuncia >= getFixTime(1, 'x')));

	typedef odb::query<pessoa> queryP;
	typedef odb::result<pessoa> resultP;

	resultP rr(db -> query<pessoa>());
	result r(db -> query<view_pessoa_denuncia>(query::denuncia::data_denuncia >= (time(0) - 50)));

	vector<pessoa> vet;
	for(pessoa &p : rr){
		int f = 1;
		if(p.getEstado() == true) continue;
		for(view_pessoa_denuncia &v : r){
			if(v.id == p.getID()){
				f = 0;
				break;
			}
		}
		if(f) vet.push_back(p);
	}

	printf("%-20s | %-10s | %-s\n", "Nome", "RG", "CPF");
	for(pessoa &v : vet){
		printf("%-20s | %-10s | %-s\n", v.getNome().c_str(), v.getRG().c_str(), v.getCPF().c_str());
	}
	
	getchar();

	t.commit();
}

#endif
