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

};

DAO::DAO(Denuncia denuncia, Papel papel, Pessoa pessoa, Usuario usuario, UsuarioPapel usuarioPapel, Auditoria auditoria){
    this -> denuncia = denuncia;
    this -> papel = papel;
    this -> pessoa = pessoa;
    this -> usuario = usuario;
    this -> usuarioPapel = usuarioPapel;
    this -> auditoria = auditoria;
}

/********** DENUNCIA ************************/
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
#endif
