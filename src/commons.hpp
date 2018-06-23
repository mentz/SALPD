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

#define ADMIN 0
#define GESTOR 1
#define AGENTE 2
#define INFORMANTE 3
#define ANONIMO 4

using namespace odb::core;
using namespace std;

std::string dateNow(){
	time_t t = time(0);
	tm* now = localtime(&t);
	std::string ret = static_cast<std::ostringstream*>( &(std::ostringstream() << now -> tm_mday))->str() + "-" +
				      static_cast<std::ostringstream*>( &(std::ostringstream() << (now -> tm_mon + 1)))->str() + "-" +
					  static_cast<std::ostringstream*>( &(std::ostringstream() << (now -> tm_year + 1900)))->str();
	return ret;
}

#ifdef _WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

#endif
