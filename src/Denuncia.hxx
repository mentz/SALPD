#include "commons.hpp"
#include "Pessoa.hxx"
#include "Usuario.hxx"
/* Denuncia (
	int id PRIMARY KEY,
	double latitude NOT NULL,
	double longitude NOT NULL,
	varchar endereco NOT NULL,
	Pessoa pessoa FOREIGN KEY NOT NULL,
	varchar detalhes NOT NULL,
	Usuario usuario FOREIGN KEY NOT NULL,
	date data_hora_visto NOT NULL
	)
*/

class Denuncia{
private:
	int id;
	double latitude;
	double longitude;
	string endereco;
	shared_ptr<Pessoa> pessoa;		// Pessoa desaparecida
	string detalhes;
	shared_ptr<Usuario> usuario;	// Inserido por
	string data_hora_visto;

public:
	Denuncia();
	Denuncia(int id, double latitude, double longitude, string endereco,
			 shared_ptr<Pessoa> pessoa, string detalhes, shared_ptr<Usuario> usuario,
			 string data_hora_visto);

	void setID(int id);
	void setLatitude(double latitude);
	void setLongitude(double longitude);
	void setEndereco(string endereco);
	void setPessoa(shared_ptr<Pessoa> pessoa);
	void setDetalhes(string detalhes);
	void setUsuario(shared_ptr<Usuario> usuario);
	void setDataHoraVisto(string data_hora_visto);

	int getID();
	double getLatitude();
	double getLongitude();
	string getEndereco();
	shared_ptr<Pessoa> getPessoa();
	string getDetalhes();
	shared_ptr<Usuario> getUsuario();
	string getDataHoraVisto();

};

/* CONSTRUCTORS */
Denuncia::Denuncia(){
	this->id = -1;
	this->latitude = -1.0;
	this->longitude = -1.0;
	this->endereco = "";
	this->pessoa = NULL;
	this->detalhes = "";
	this->usuario = NULL;
	this->data_hora_visto = "";
}
Denuncia::Denuncia(int id, double latitude, double longitude, string endereco,
				   shared_ptr<Pessoa> pessoa, string detalhes, shared_ptr<Usuario> usuario,
				   string data_hora_visto){
	this->id = id;
	this->latitude = latitude;
	this->longitude = longitude;
	this->endereco = endereco;
	this->pessoa = pessoa;
	this->detalhes = detalhes;
	this->usuario = usuario;
	this->data_hora_visto = data_hora_visto;
}

/* SETTERS */
void Denuncia::setID(int id){
	this->id = id;
}

void Denuncia::setLatitude(double latitude){
	this->latitude = latitude;
}

void Denuncia::setLongitude(double longitude){
	this->longitude = longitude;
}

void Denuncia::setEndereco(string endereco){
	this->endereco = endereco;
}

void Denuncia::setPessoa(shared_ptr<Pessoa> pessoa){
	this->pessoa = pessoa;
}

void Denuncia::setDetalhes(string detalhes){
	this->detalhes = detalhes;
}

void Denuncia::setUsuario(shared_ptr<Usuario> usuario){
	this->usuario = usuario;
}

void Denuncia::setDataHoraVisto(string data_hora_visto){
	this->data_hora_visto = data_hora_visto;
}

/* GETTERS */

int Denuncia::getID(){
	return this->id;
}

double Denuncia::getLatitude(){
	return this->latitude;
}

double Denuncia::getLongitude(){
	return this->longitude;
}
string Denuncia::getEndereco(){
	return this->endereco;
}

shared_ptr<Pessoa> Denuncia::getPessoa(){
	return this->pessoa;
}

string Denuncia::getDetalhes(){
	return this->detalhes;
}

shared_ptr<Usuario> Denuncia::getUsuario(){
	return this->usuario;
}

string Denuncia::getDataHoraVisto(){
	return this->data_hora_visto;
}

