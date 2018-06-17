#ifndef __DAO_HPP__
#define __DAO_HPP__

#include "commons.hpp"

class DAO {
private:
    Denuncia denuncia;
    Papel papel;
    Pessoa pessoa;
    Usuario usuario;
    UsuarioPapel usuarioPapel;
    Auditoria auditoria;
public:
    DAO();
    DAO(Denuncia denuncia, Papel papel, Pessoa pessoa, Usuario usuario, UsuarioPapel usuarioPapel, Auditoria auditoria);

    /* Denuncia */
    //SETTERS
    Denuncia getDenuncia();
    void setDenuncia(Denuncia denuncia);
    void setDenunciaID(int id);
	void setDenunciaLatitude(double latitude);
	void setDenunciaLongitude(double longitude);
	void setDenunciaEndereco(string endereco);
	void setDenunciaPessoa(shared_ptr<Pessoa> pessoa);
	void setDenunciaDetalhes(string detalhes);
	void setDenunciaUsuario(shared_ptr<Usuario> usuario);
	void setDenunciaDataHoraVisto(string data_hora_visto);
    //GETTERS
    int getDenunciaID();
	double getDenunciaLatitude();
	double getDenunciaLongitude();
	string getDenunciaEndereco();
	shared_ptr<Pessoa> getDenunciaPessoa();
	string getDenunciaDetalhes();
	shared_ptr<Usuario> getDenunciaUsuario();
	string getDenunciaDataHoraVisto();

    /* Pessoa */
    //SETTERS
    void setPessoaID(int id);
	void setPessoaCPF(string cpf);
	void setPessoaRG(string rg);
	void setPessoaNome(string nome);
	void setPessoaSobrenome(string sobrenome);
	//void setPessoaUltimoVisto(shared_ptr<Denuncia> ultimo_visto);
	void setPessoaUltimaModificacao(shared_ptr<Auditoria> ultima_modificacao);
    //GETTERS
    int getPessoaID();
	string getPessoaCPF();
	string getPessoaRG();
	string getPessoaNome();
	string getPessoaSobrenome();
	//shared_ptr<Denuncia> getPessoaUltimoVisto();
	shared_ptr<Auditoria> getPessoaUltimaModificacao();

    /* Auditoria */
    //SETTERS
    void setAuditoriaAcao(string acao);
	void setAuditoriaUsuario(shared_ptr<Usuario> usuario);
    //GETTERS
    string getAuditoriaAcao();
	shared_ptr<Usuario> getAuditoriaUsuario();

    /* UsuarioPapel */
    //SETTERS
    bool setUsuarioPapelValido();
    //GETTERS
    shared_ptr<Usuario> getUsuarioPapelUsuario();
	shared_ptr<Papel> getUsuarioPapelPapel();
	shared_ptr<Auditoria> getUsuarioPapelAuditoria();
	bool getUsuarioPapelValido();

    /* Usuario */
    //SETTERS
    void setUsuarioID(int id);
	void setUsuarioRG(string rg);
	void setUsuarioCPF(string cpf);
	void setUsuarioNome(string nome);
	void setUsuarioSobrenome(string sobrenome);
	void setUsuarioHashSenha(string hash_senha);
	void setUsuarioDataCadastro(string data_cadastro);
	void setUsuarioUltimoAcesso(string ultimo_acesso);
    //GETTERS
    int getUsuarioID();
	string getUsuarioRG();
	string getUsuarioCPF();
	string getUsuarioNome();
	string getUsuarioSobrenome();
	string getUsuarioHashSenha();
	string getUsuarioDataCadastro();
	string getUsuarioUltimoAcesso();

    /* Papel */
    //SETTERS
    void setPapelPapel(int papel);
    void setPapelPermissoes(string permissoes);
    //GETTERS
    int getPapelPapel();
    string getPapelPermissoes();
};
DAO::DAO(){
    printf("DAO Criado!\n");
}
DAO::DAO(Denuncia denuncia, Papel papel, Pessoa pessoa, Usuario usuario, UsuarioPapel usuarioPapel, Auditoria auditoria){
    this -> denuncia = denuncia;
    this -> papel = papel;
    this -> pessoa = pessoa;
    this -> usuario = usuario;
    this -> usuarioPapel = usuarioPapel;
    this -> auditoria = auditoria;
}

/********************* DENUNCIA ************************/
// SETTERS
Denuncia DAO::getDenuncia(){
    return this -> denuncia;
}
void DAO::setDenuncia(Denuncia denuncia){
    this -> denuncia = denuncia;
}
void DAO::setDenunciaID(int id){
	this -> denuncia.setID(id);
}
void DAO::setDenunciaLatitude(double latitude){
	this -> denuncia.setLatitude(latitude);
}
void DAO::setDenunciaLongitude(double longitude){
	this -> denuncia.setLongitude(longitude);
}
void DAO::setDenunciaEndereco(string endereco){
	this -> denuncia.setEndereco(endereco);
}
void DAO::setDenunciaPessoa(shared_ptr<Pessoa> pessoa){
	this -> denuncia.setPessoa(pessoa);
}
void DAO::setDenunciaDetalhes(string detalhes){
	this -> denuncia.setDetalhes(detalhes);
}
void DAO::setDenunciaUsuario(shared_ptr<Usuario> usuario){
	this -> denuncia.setUsuario(usuario);
}
void DAO::setDenunciaDataHoraVisto(string data_hora_visto){
	this -> denuncia.setDataHoraVisto(data_hora_visto);
}
//GETTERS
int DAO::getDenunciaID(){
	return this -> denuncia.getID();
}
double DAO::getDenunciaLatitude(){
	return this -> denuncia.getLatitude();
}
double DAO::getDenunciaLongitude(){
	return this -> denuncia.getLongitude();
}
string DAO::getDenunciaEndereco(){
	return this -> denuncia.getEndereco();
}
shared_ptr<Pessoa> DAO::getDenunciaPessoa(){
    return this -> denuncia.getPessoa();
}
string DAO::getDenunciaDetalhes(){
	return this -> denuncia.getDetalhes();
}
shared_ptr<Usuario> DAO::getDenunciaUsuario(){
	return this -> denuncia.getUsuario();
}
string DAO::getDenunciaDataHoraVisto(){
	return this -> denuncia.getDataHoraVisto();
}

/********************* PESSOA ************************/
//SETTERS
void DAO::setPessoaID(int id){
    this -> pessoa.setID(id);
}
void DAO::setPessoaCPF(string cpf){
    this -> pessoa.setCPF(cpf);
}
void DAO::setPessoaRG(string rg){
    this -> pessoa.setRG(rg);
}
void DAO::setPessoaNome(string nome){
    this -> pessoa.setNome(nome);
}
void DAO::setPessoaSobrenome(string sobrenome){
    this -> pessoa.setSobrenome(sobrenome);
}
// void DAO::setPessoaUltimoVisto(shared_ptr<Denuncia> ultimo_visto){
//     this -> pessoa.setUltimoVisto(ultimo_visto);
// }
void DAO::setPessoaUltimaModificacao(shared_ptr<Auditoria> ultima_modificacao){
    this -> pessoa.setUltimaModificacao(ultima_modificacao);
}

//GETTERS
int DAO::getPessoaID(){
    return this -> pessoa.getID();
}
string DAO::getPessoaCPF(){
    return this -> pessoa.getCPF();
}
string DAO::getPessoaRG(){
    return this -> pessoa.getRG();
}
string DAO::getPessoaNome(){
    return this -> pessoa.getNome();
}
string DAO::getPessoaSobrenome(){
    return this -> pessoa.getSobrenome();
}
//shared_ptr<Denuncia> DAO::getPessoaUltimoVisto(){
//   return this -> pessoa.getUltimoVisto();
// }
shared_ptr<Auditoria> DAO::getPessoaUltimaModificacao(){
    return this -> pessoa.getUltimaModificacao();
}

/********************* AUDITORIA ************************/
//SETTERS
void DAO::setAuditoriaAcao(string acao){
    this -> auditoria.setAcao(acao);
}
void DAO::setAuditoriaUsuario(shared_ptr<Usuario> usuario){
    this -> auditoria.setUsuario(usuario);
}
//GETTERS
string DAO::getAuditoriaAcao(){
    return this -> auditoria.getAcao();
}
shared_ptr<Usuario> DAO::getAuditoriaUsuario(){
    return this -> auditoria.getUsuario();
}

/********************* USUARIOPAPEL ************************/
//SETTERS
// bool DAO::setUsuarioPapelValido(){
//     return this -> usuarioPapel.setValido();
// }
//GETTERS
shared_ptr<Usuario> DAO::getUsuarioPapelUsuario(){
    return this -> usuarioPapel.getUsuario();
}
shared_ptr<Papel> DAO::getUsuarioPapelPapel(){
    return this -> usuarioPapel.getPapel();
}
shared_ptr<Auditoria> DAO::getUsuarioPapelAuditoria(){
    return this -> usuarioPapel.getAuditoria();
}
bool DAO::getUsuarioPapelValido(){
    return this -> usuarioPapel.getValido();
}

/********************* USUARIO ************************/
//SETTERS
void DAO::setUsuarioID(int id){
    this -> usuario.setID(id);
}
void DAO::setUsuarioRG(string rg){
    this -> usuario.setRG(rg);
}
void DAO::setUsuarioCPF(string cpf){
    this -> usuario.setCPF(cpf);
}
void DAO::setUsuarioNome(string nome){
    this -> usuario.setNome(nome);
}
void DAO::setUsuarioSobrenome(string sobrenome){
    this -> usuario.setSobrenome(sobrenome);
}
void DAO::setUsuarioHashSenha(string hash_senha){
    this -> usuario.setHashSenha(hash_senha);
}
void DAO::setUsuarioDataCadastro(string data_cadastro){
    this -> usuario.setDataCadastro(data_cadastro);
}
void DAO::setUsuarioUltimoAcesso(string ultimo_acesso){
    this -> usuario.setUltimoAcesso(ultimo_acesso);
}
//GETTERS
int DAO::getUsuarioID(){
    return this -> usuario.getID();
}
string DAO::getUsuarioRG(){
    return this -> usuario.getRG();
}
string DAO::getUsuarioCPF(){
    return this -> usuario.getCPF();
}
string DAO::getUsuarioNome(){
    return this -> usuario.getNome();
}
string DAO::getUsuarioSobrenome(){
    return this -> usuario.getSobrenome();
}
string DAO::getUsuarioHashSenha(){
    return this -> usuario.getHashSenha();
}
string DAO::getUsuarioDataCadastro(){
    return this -> usuario.getDataCadastro();
}
string DAO::getUsuarioUltimoAcesso(){
    return this -> usuario.getUltimoAcesso();
}

/********************* PAPEL ************************/
//SETTERS
void DAO::setPapelPapel(int papel){
    this -> papel.setPapel(papel);
}
void DAO::setPapelPermissoes(string permissoes){
    this -> papel.setPermissoes(permissoes);
}
//GETTERS
int DAO::getPapelPapel(){
    return this -> papel.getPapel();
}
string DAO::getPapelPermissoes(){
    return this -> papel.getPermissoes();
}
#endif
