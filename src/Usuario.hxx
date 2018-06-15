#include "commons.hpp"
/* Usuario (
		UNIQUE char[11] CPF,
		varchar nome,
		varchar sobrenome,
		char[10] hash_senha,
		varchar data_cadastro,
		varchar ultimo_acesso
	)*/

//#pragma db object table ("usuario")
class Usuario
{
private:
	//friend class odb::access;

	std::string rg;
	std::string cpf;
	std::string nome;
	std::string sobrenome;
	std::string hash_senha;
	std::string data_cadastro;
	std::string ultimo_acesso;
};
