#include <string>
#include<iostream>
#include <iomanip>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "customer.h"
#include "CustomerManager.h"
#include "DatabaseConnection.h"

bool CustomerManager::checkcus(string& cusID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM CUSTOMER WHERE CUSTOMER_ID = ?");

	ps->setString(1, cusID);

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		if (cusID == rs->getString("CUSTOMER_ID"))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
int CustomerManager::AddCustomer(Customer* customer)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO CUSTOMER VALUES (?,?,?,?)");

	ps->setString(1, customer->customer_id);
	ps->setString(2, customer->customer_name);
	ps->setString(3, customer->customer_contacts);
	ps->setString(4, customer->customer_address);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

void CustomerManager::ViewCustomer()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM CUSTOMER");

	ResultSet* res = ps->executeQuery();

	cout << endl;
	cout << left;
	cout << setw(35) <<" " <<setw(20) << "CUSTOMER ID" << setw(30) << "CUSTOMER NAME" << setw(30) << "CUSTOMER CONTACTS" << setw(80) << "CUSTOMER ADDRESS";
	while (res->next())
	{
		cout << left;
		cout << "\n" << setw(35) <<" "<<setw(20)<< res->getString("CUSTOMER_ID") << setw(30) << res->getString("CUSTOMER_NAME") << setw(30) << res->getString("CUSTOMER_CONTACTS") << setw(80) << res->getString("CUSTOMER_ADDRESS");
	}
}

int CustomerManager::editIName(string& cusID, string& cusName)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE CUSTOMER SET CUSTOMER_NAME=? WHERE CUSTOMER_ID=?");

	ps->setString(1, cusName);
	ps->setString(2, cusID);

	int status1 = ps->executeUpdate();

	delete ps;

	return status1;
}

int CustomerManager::editContacts(string& cusID, string& cusContacts)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE CUSTOMER SET CUSTOMER_CONTACTS=? WHERE CUSTOMER_ID=?");

	ps->setString(1, cusContacts);
	ps->setString(2, cusID);

	int status3 = ps->executeUpdate();

	delete ps;

	return status3;
}

int CustomerManager::editAddress(string& cusID, string& cusAddress)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE CUSTOMER SET CUSTOMER_ADDRESS=? WHERE CUSTOMER_ID=?");

	ps->setString(1, cusAddress);
	ps->setString(2, cusID);

	int status2 = ps->executeUpdate();

	delete ps;

	return status2;
}



