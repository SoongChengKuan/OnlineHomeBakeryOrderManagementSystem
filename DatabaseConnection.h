#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <mysql/jdbc.h>
using namespace sql;

#include<iostream>
using namespace std;

class DatabaseConnection
{
private: 
	Connection* connection;

public:
	DatabaseConnection();
	~DatabaseConnection();

	PreparedStatement* prepareStatement(string query); 

};
#endif