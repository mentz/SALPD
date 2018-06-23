#ifndef __DAO_HPP__
#define __DAO_HPP__

#include "commons.hpp"
#include "AllClass.hxx"

class DAO {
private:
    DAO();
public:
    static DAO& getInstance();

    int createDenuncia(shared_ptr<database> db, usuario user);

    pessoa createPessoa(shared_ptr<database> db);

    int criaUsuario(shared_ptr<database> db);

    /* Trecos aleatorios */
    usuario verificaLogin(shared_ptr<database> db);
};

#include "DAO.hpp"

DAO::DAO(){}

DAO& DAO::getInstance(){
	static DAO instance;

    return instance;
}

int DAO::createDenuncia(shared_ptr<database> db, usuario user){
    system(CLEAR);

    printf("\t\tFazer denuncia\n\n");
    pessoa pessoa_desaparecida = DAO::getInstance().createPessoa(db);

    std::string nome_desaparecido;
    printf("Digite o nome da pessoa desaparecida:\n");
    getline(cin, nome_desaparecido);

    printf("Digite a latitude e longitude da ultima localizacao da pessoa desaparecida:\n");
    std::string latitude, longitude;
    printf("Digite a latitude: ");
    cin >> latitude;
    printf("Digite a longitude: ");
    cin >> longitude;

    printf("Agora descreva alguns detalhes sobre a denuncia:\n");
    getchar();
    std::string detalhes;
    getline(cin, detalhes);

    try {

        transaction t(db -> begin());

        denuncia d = denuncia(&pessoa_desaparecida, latitude, longitude, &user, detalhes, getTime(), "-1", "-1");

        db -> persist(d);

        t.commit();

        return 1;
    } catch(odb::exception &e){
        cerr << e.what() << endl;
        return 0;
	}
}

pessoa DAO::createPessoa(shared_ptr<database> db){
    printf("\tCadastro de pessoa desaparecida\n\n");

    printf("Digite o nome da pessoa desaparecida\n");
    std::string nome;
    getline(cin, nome);

    pessoa ret;

    try {
        transaction t(db -> begin());

        typedef odb::query<pessoa> query;
        typedef odb::result<pessoa> result;

        std::string selectLIKE = "SELECT * FROM pessoa WHERE nome LIKE " + nome;

        result r(db -> query<pessoa>(query::nome.like(nome)));

        if(r.size()){
            printf("Encontramos algum(ns) resultado(s) com esse nome:\n");
            int idx = 1;
            std::vector<pessoa> pessoas_sistema;
            for(result::iterator it = r.begin(); it != r.end(); it++){
                printf("%d -> Nome: %s | RG %s | CPF: %s\n", idx++, it -> getNome(), it -> getRG(), it -> getCPF());
                pessoas_sistema.push_back(*it);
            }
            printf("Algum desses eh sua pessoa desaparecida? (S\N)\n");
            printf("> ");
            char c;
            scanf("%c", &c);
            if(c == 'S' or c == 's'){
                printf("Digite o numero da pessoa: ");
                int indice;
                scanf("%d", &indice);
                pessoa ret = pessoas_sistema[indice - 1];
            } else {
                printf("Ok\n");
            }
        }
        t.commit();

        return ret;
    } catch(odb::exception &e){
        cerr << e.what() << endl;
        return pessoa();
    }

}

int DAO::criaUsuario(shared_ptr<database> db){
    system(CLEAR);

    std::string rg, cpf, nome, nome_usuario, hash_senha, role;

    cout << "\t\tFormulario de Usuario\n\n";

    cout << "Digite o RG: ";
    cin >> rg;

    cout << "Digite o CPF: ";
    cin >> cpf;

    getchar();

    cout << "Digite o nome: ";
    getline(cin, nome);

    cout << "Digite o nome de usuario: ";
    cin >> nome_usuario;

    cout << "Digite a senha do novo usuario: ";
    cin >> hash_senha;

    cout << "Qual sera o papel do usuario? ";
    cin >> role;

    int p = (role == "ADMIN" ? ADMIN : (role == "GESTOR" ? GESTOR : (role == "AGENTE" ? AGENTE : INFORMANTE)));

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

/*********************************** TRECOS ALEATORIOS **********************************/
usuario DAO::verificaLogin(shared_ptr<database> db){
    system(CLEAR);
    std::string nome_usuario, hash_senha;

    cout << "Digite seu usuario: ";
    cin >> nome_usuario;

    cout << "Digite sua senha: ";
    cin >> hash_senha;

    typedef odb::query<usuario> query;
    typedef odb::result<usuario> result;

    try {
        transaction t(db -> begin());
        result r(db -> query<usuario> (query::nome_usuario == nome_usuario and query::hash_senha == hash_senha));

        usuario ret;

        if(r.size() == 0){
            cout << "ID e/ou senha incorretos!" << endl;
            ret = getAnonimo();
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

#endif
