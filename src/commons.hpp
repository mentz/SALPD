#ifndef _SALPD_COMMONS_
#define _SALPD_COMMONS_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <utility>

//Senha do bando de dados: ccxuE7Ak3GIXiq05gcVT3vgvwJ7naT8-

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include <odb/pgsql/database.hxx>

#include "AllClass.hxx"

#define ADMIN 1
#define GESTOR 2
#define AGENTE 3
#define INFORMANTE 4
#define ANONIMO 5

using namespace odb::core;
using namespace std;

time_t getTime(){
	return time(0);
}

std::string printTime(time_t tempo){
	char buffer[124];

	std::strftime(buffer, 124, "%c", localtime(&tempo));
	return std::string(buffer);
}

usuario getAnonimo(){
	usuario anonimo("", "", "", "", "", getTime(), new papel(ANONIMO, ""));
	anonimo.setID(1);
	return anonimo;
}

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

#endif
