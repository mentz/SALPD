/* Esse arquivo inicializa a base de dados
   com dados padrão que serão usados pelo
   aplicativo SALPD.
   */

INSERT INTO papel (id, permissoes) VALUES
	(1, 'rw usuario r pessoa r denuncia r auditoria'),
	(2, 'r pessoa w denuncia'),
	(3, 'rw pessoa rw '),
	(4, 'r pessoa rw denuncia'),
	(5, 'r pessoa w denuncia')
