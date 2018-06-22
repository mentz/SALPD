#ifndef __DAO_HPP__
#define __DAO_HPP__

#include "commons.hpp"
#include "AllClass.hxx"

// #include "UsuarioPapel.hxx"

// EntidadeDenuncia {
//     vector<Denuncia> den;
// }

class DAO {
private:
    DAO();
    //DAO(Denuncia denuncia, Papel papel, Pessoa pessoa, Usuario usuario, UsuarioPapel usuarioPapel, Auditoria auditoria);
public:
    static DAO& getInstance();
    //
    // void add();
    // void printCnt();
    // /* Denuncia */
    // //SETTERS
    // Denuncia getDenuncia();
    // void setDenuncia(Denuncia denuncia);
    // void setDenunciaID(int id);
	// void setDenunciaLatitude(double latitude);
	// void setDenunciaLongitude(double longitude);
	// void setDenunciaEndereco(string endereco);
	// void setDenunciaPessoa(shared_ptr<Pessoa> pessoa);
	// void setDenunciaDetalhes(string detalhes);
	// void setDenunciaUsuario(shared_ptr<Usuario> usuario);
	// void setDenunciaDataHoraVisto(string data_hora_visto);
    // //GETTERS
    // int getDenunciaID();
	// double getDenunciaLatitude();
	// double getDenunciaLongitude();
	// string getDenunciaEndereco();
	// shared_ptr<Pessoa> getDenunciaPessoa();
	// string getDenunciaDetalhes();
	// shared_ptr<Usuario> getDenunciaUsuario();
	// string getDenunciaDataHoraVisto();
    //
    int createDenuncia(shared_ptr<database> db);
    //
    // /* Pessoa */
    // //SETTERS
    // void setPessoaID(int id);
	// void setPessoaCPF(string cpf);
	// void setPessoaRG(string rg);
	// void setPessoaNome(string nome);
	// void setPessoaSobrenome(string sobrenome);
	// //void setPessoaUltimoVisto(shared_ptr<Denuncia> ultimo_visto);
	// void setPessoaUltimaModificacao(shared_ptr<Auditoria> ultima_modificacao);
    // //GETTERS
    // int getPessoaID();
	// string getPessoaCPF();
	// string getPessoaRG();
	// string getPessoaNome();
	// string getPessoaSobrenome();
	// //shared_ptr<Denuncia> getPessoaUltimoVisto();
	// shared_ptr<Auditoria> getPessoaUltimaModificacao();
    //
    // /* Auditoria */
    // //SETTERS
    // void setAuditoriaAcao(string acao);
	// void setAuditoriaUsuario(shared_ptr<UsuarioPapel> usuario);
    // //GETTERS
    // string getAuditoriaAcao();
	// shared_ptr<UsuarioPapel> getAuditoriaUsuario();
    //
    // /* UsuarioPapel */
    // //SETTERS
    // bool setUsuarioPapelValido();
    // //GETTERS
    // shared_ptr<Usuario> getUsuarioPapelUsuario();
	// shared_ptr<Papel> getUsuarioPapelPapel();
	// // shared_ptr<Auditoria> getUsuarioPapelAuditoria();
	// bool getUsuarioPapelValido();
    //
    // /* Usuario */
    // //SETTERS
    // void setUsuarioID(int id);
	// void setUsuarioRG(string rg);
	// void setUsuarioCPF(string cpf);
	// void setUsuarioNome(string nome);
	// void setUsuarioSobrenome(string sobrenome);
	// void setUsuarioHashSenha(string hash_senha);
	// void setUsuarioDataCadastro(string data_cadastro);
	// void setUsuarioUltimoAcesso(string ultimo_acesso);
    // //GETTERS
    // int getUsuarioID();
	// string getUsuarioRG();
	// string getUsuarioCPF();
	// string getUsuarioNome();
	// string getUsuarioSobrenome();
	// string getUsuarioHashSenha();
	// string getUsuarioDataCadastro();
	// string getUsuarioUltimoAcesso();
    int criaUsuario(shared_ptr<database> db);
    // /* Papel */
    // //SETTERS
    // void setPapelPapel(int papel);
    // void setPapelPermissoes(string permissoes);
    // //GETTERS
    // int getPapelPapel();
    // string getPapelPermissoes();

    /* Trecos aleatorios */
    int verificaLogin(shared_ptr<database> db);
};

#include "DAO.hpp"

DAO::DAO(){
    printf("DAO Criado!\n");
    // singleton = NULL;
    // this -> cnt = 0;
}
// DAO::DAO(Denuncia denuncia, Papel papel, Pessoa pessoa, Usuario usuario, UsuarioPapel usuarioPapel, Auditoria auditoria){
//     this -> denuncia = denuncia;
//     this -> papel = papel;
//     this -> pessoa = pessoa;
//     this -> usuario = usuario;
//     this -> usuarioPapel = usuarioPapel;
//     this -> auditoria = auditoria;
// }

DAO& DAO::getInstance(){
	static DAO instance;

    return instance;
}

//
// void DAO::add(){
//     this -> cnt++;
// }
// void DAO::printCnt(){
//     printf("%d\n", this -> cnt);
// }
//
// /********************* DENUNCIA ************************/
// // SETTERS
// Denuncia DAO::getDenuncia(){
//     return this -> denuncia;
// }
// void DAO::setDenuncia(Denuncia denuncia){
//     this -> denuncia = denuncia;
// }
// void DAO::setDenunciaID(int id){
// 	this -> denuncia.setID(id);
// }
//
int DAO::createDenuncia(shared_ptr<database> db){
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

    try {
        transaction t (db -> begin());
        unsigned int id = db -> persist(den);
        t.commit();
        return 1;
    } catch(const odb::exception &e){
		cerr << e.what() << endl;
        return 0;
	}

}

//
// void DAO::setDenunciaLatitude(double latitude){
// 	this -> denuncia.setLatitude(latitude);
// }
// void DAO::setDenunciaLongitude(double longitude){
// 	this -> denuncia.setLongitude(longitude);
// }
// void DAO::setDenunciaEndereco(string endereco){
// 	this -> denuncia.setEndereco(endereco);
// }
// void DAO::setDenunciaPessoa(shared_ptr<Pessoa> pessoa){
// 	this -> denuncia.setPessoa(pessoa);
// }
// void DAO::setDenunciaDetalhes(string detalhes){
// 	this -> denuncia.setDetalhes(detalhes);
// }
// void DAO::setDenunciaUsuario(shared_ptr<Usuario> usuario){
// 	this -> denuncia.setUsuario(usuario);
// }
// void DAO::setDenunciaDataHoraVisto(string data_hora_visto){
// 	this -> denuncia.setDataHoraVisto(data_hora_visto);
// }
// //GETTERS
// int DAO::getDenunciaID(){
// 	return this -> denuncia.getID();
// }
// double DAO::getDenunciaLatitude(){
// 	return this -> denuncia.getLatitude();
// }
// double DAO::getDenunciaLongitude(){
// 	return this -> denuncia.getLongitude();
// }
// string DAO::getDenunciaEndereco(){
// 	return this -> denuncia.getEndereco();
// }
// shared_ptr<Pessoa> DAO::getDenunciaPessoa(){
//     return this -> denuncia.getPessoa();
// }
// string DAO::getDenunciaDetalhes(){
// 	return this -> denuncia.getDetalhes();
// }
// shared_ptr<Usuario> DAO::getDenunciaUsuario(){
// 	return this -> denuncia.getUsuario();
// }
// string DAO::getDenunciaDataHoraVisto(){
// 	return this -> denuncia.getDataHoraVisto();
// }
//
// /********************* PESSOA ************************/
// //SETTERS
// void DAO::setPessoaID(int id){
//     this -> pessoa.setID(id);
// }
// void DAO::setPessoaCPF(string cpf){
//     this -> pessoa.setCPF(cpf);
// }
// void DAO::setPessoaRG(string rg){
//     this -> pessoa.setRG(rg);
// }
// void DAO::setPessoaNome(string nome){
//     this -> pessoa.setNome(nome);
// }
// void DAO::setPessoaSobrenome(string sobrenome){
//     this -> pessoa.setSobrenome(sobrenome);
// }
// // void DAO::setPessoaUltimoVisto(shared_ptr<Denuncia> ultimo_visto){
// //     this -> pessoa.setUltimoVisto(ultimo_visto);
// // }
// void DAO::setPessoaUltimaModificacao(shared_ptr<Auditoria> ultima_modificacao){
//     this -> pessoa.setUltimaModificacao(ultima_modificacao);
// }
//
// //GETTERS
// int DAO::getPessoaID(){
//     return this -> pessoa.getID();
// }
// string DAO::getPessoaCPF(){
//     return this -> pessoa.getCPF();
// }
// string DAO::getPessoaRG(){
//     return this -> pessoa.getRG();
// }
// string DAO::getPessoaNome(){
//     return this -> pessoa.getNome();
// }
// string DAO::getPessoaSobrenome(){
//     return this -> pessoa.getSobrenome();
// }
// //shared_ptr<Denuncia> DAO::getPessoaUltimoVisto(){
// //   return this -> pessoa.getUltimoVisto();
// // }
// shared_ptr<Auditoria> DAO::getPessoaUltimaModificacao(){
//     return this -> pessoa.getUltimaModificacao();
// }
//
// /********************* AUDITORIA ************************/
// //SETTERS
// void DAO::setAuditoriaAcao(string acao){
//     this -> auditoria.setAcao(acao);
// }
// void DAO::setAuditoriaUsuario(shared_ptr<UsuarioPapel> usuario){
//     this -> auditoria.setUsuario(usuario);
// }
// //GETTERS
// string DAO::getAuditoriaAcao(){
//     return this -> auditoria.getAcao();
// }
// shared_ptr<UsuarioPapel> DAO::getAuditoriaUsuario(){
//     return this -> auditoria.getUsuario();
// }
//
// /********************* USUARIOPAPEL ************************/
// //SETTERS
// // bool DAO::setUsuarioPapelValido(){
// //     return this -> usuarioPapel.setValido();
// // }
// //GETTERS
// shared_ptr<Usuario> DAO::getUsuarioPapelUsuario(){
//     return this -> usuarioPapel.getUsuario();
// }
// shared_ptr<Papel> DAO::getUsuarioPapelPapel(){
//     return this -> usuarioPapel.getPapel();
// }
// // shared_ptr<Auditoria> DAO::getUsuarioPapelAuditoria(){
// //     return this -> usuarioPapel.getAuditoria();
// // }
// bool DAO::getUsuarioPapelValido(){
//     return this -> usuarioPapel.getValido();
// }
//
// /********************* USUARIO ************************/
// //SETTERS
// void DAO::setUsuarioID(int id){
//     this -> usuario.setID(id);
// }
// void DAO::setUsuarioRG(string rg){
//     this -> usuario.setRG(rg);
// }
// void DAO::setUsuarioCPF(string cpf){
//     this -> usuario.setCPF(cpf);
// }
// void DAO::setUsuarioNome(string nome){
//     this -> usuario.setNome(nome);
// }
// void DAO::setUsuarioSobrenome(string sobrenome){
//     this -> usuario.setSobrenome(sobrenome);
// }
// void DAO::setUsuarioHashSenha(string hash_senha){
//     this -> usuario.setHashSenha(hash_senha);
// }
// void DAO::setUsuarioDataCadastro(string data_cadastro){
//     this -> usuario.setDataCadastro(data_cadastro);
// }
// void DAO::setUsuarioUltimoAcesso(string ultimo_acesso){
//     this -> usuario.setUltimoAcesso(ultimo_acesso);
// }
// //GETTERS
// int DAO::getUsuarioID(){
//     return this -> usuario.getID();
// }
// string DAO::getUsuarioRG(){
//     return this -> usuario.getRG();
// }
// string DAO::getUsuarioCPF(){
//     return this -> usuario.getCPF();
// }
// string DAO::getUsuarioNome(){
//     return this -> usuario.getNome();
// }
// string DAO::getUsuarioSobrenome(){
//     return this -> usuario.getSobrenome();
// }
// string DAO::getUsuarioHashSenha(){
//     return this -> usuario.getHashSenha();
// }
// string DAO::getUsuarioDataCadastro(){
//     return this -> usuario.getDataCadastro();
// }
// string DAO::getUsuarioUltimoAcesso(){
//     return this -> usuario.getUltimoAcesso();
// }

int DAO::criaUsuario(shared_ptr<database> db){
    system(CLEAR);
    string rg;
    string cpf;
    string nome;
    string sobrenome;
    string hash_senha = "123456";
    string data_cadastro = "20180622";
    string ultimo_acesso = "20180622";

    cout << "\t\tFormulario de Usuario\n\n";

    cout << "Digite o RG: ";
    cin >> rg;

    cout << "Digite o CPF: ";
    cin >> cpf;

    cout << "Digite o nome: ";
    cin >> nome;

    cout << "Digite o sobrenome: ";
    cin >> sobrenome;

    usuario usu = usuario(rg, cpf, nome, sobrenome, hash_senha, data_cadastro, ultimo_acesso);

    /* Ponto de falha do carai */

    try {
        transaction t(db -> begin());

        unsigned int id = db -> persist(usu);

        t.commit();

        return 1;
    } catch(odb::exception &e){
        cerr << e.what() << endl;
        return 0;
    }
}

// /********************* PAPEL ************************/
// //SETTERS
// void DAO::setPapelPapel(int papel){
//     this -> papel.setPapel(papel);
// }
// void DAO::setPapelPermissoes(string permissoes){
//     this -> papel.setPermissoes(permissoes);
// }
// //GETTERS
// int DAO::getPapelPapel(){
//     return this -> papel.getPapel();
// }
// string DAO::getPapelPermissoes(){
//     return this -> papel.getPermissoes();
// }

/*********************************** TRECOS ALEATORIOS **********************************/
int DAO::verificaLogin(shared_ptr<database> db){
    system(CLEAR);
    int id;
    string senha;

    cout << "Digite seu id: ";
    cin >> id;

    cout << "Digite sua senha: ";
    cin >> senha;

    typedef odb::query<usuario> query;
    typedef odb::result<usuario> result;

    try {
        transaction t(db -> begin());
        result r(db -> query<usuario> (query::id == id and query::hash_senha == senha));

        int ret;

        if(r.size() == 0){
            cout << "ID e/ou senha incorretos!" << endl;
            ret = -1;
        } else {
            result::iterator it = r.begin();
            ret = it -> getID();
        }
        t.commit();

        return ret;
    } catch(odb::exception &e){
        cerr << e.what() << endl;
        return 0;
    }
}

#endif
