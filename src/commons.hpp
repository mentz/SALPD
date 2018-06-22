#ifndef _SALPD_COMMONS_
#define _SALPD_COMMONS_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <memory>

//Senha do bando de dados: ccxuE7Ak3GIXiq05gcVT3vgvwJ7naT8-

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include <odb/pgsql/database.hxx>

#define ADMIN 1
#define GESTOR 2
#define AGENTE 3
#define INFORMANTE 4
#define ANONIMO 5

using namespace odb::core;
using namespace std;

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

#endif
