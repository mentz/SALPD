/* Esse arquivo inicializa a base de dados
   com dados padrão que serão usados pelo
   aplicativo SALPD.
   */

INSERT INTO "papel"("id", "permissoes") VALUES
	(0, "rw usuario r pessoa r denuncia r auditoria"),
	(1, "r pessoa w denuncia"),
	(2, "rw pessoa rw "),
	(3, "r pessoa rw denuncia"),
	(4, "r pessoa w denuncia")

#define ADMIN 0
#define GESTOR 1
#define AGENTE 2
#define INFORMANTE 3
#define ANONIMO 4

INSERT INTO "usuario"(
