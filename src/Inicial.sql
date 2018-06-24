/* Esse arquivo inicializa a base de dados
   com dados padrão que serão usados pelo
   aplicativo SALPD.
   */

INSERT INTO papel (id, permissoes) VALUES
	(1, 'rw usuario r pessoa r denuncia r auditoria'),
	(2, 'r pessoa w denuncia'),
	(3, 'rw pessoa rw '),
	(4, 'r pessoa rw denuncia'),
	(5, 'r pessoa w denuncia');

INSERT INTO usuario (id, fk_papel, rg, cpf, nome, nome_usuario, hash_senha, data_cadastro) VALUES
	(0, 1, '5612679', '09700990966', 'Felipe Weiss', 'admin', 'admin', CAST(EXTRACT(EPOCH FROM NOW()) as BIGINT)),
	(1, 5, '', '', '', 'anonimo', '', CAST(EXTRACT(EPOCH FROM NOW()) as BIGINT));
