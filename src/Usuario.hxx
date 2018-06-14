/* Usuario (
		UNIQUE char[11] CPF,
		varchar nome,
		varchar sobrenome,
		char[10] hash_senha,
		varchar data_cadastro,
		varchar ultimo_acesso
	)*/
using namespace std;

//#pragma db object table ("usuario")
class usuario{
	string cpf;
	string nome;
	string sobrenome;
	string hash_senha;
	string data_cadastro;
	string ultimo_acesso;
};