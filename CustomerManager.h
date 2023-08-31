#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "customer.h"

class CustomerManager
{
public:
	bool checkcus(string& cusID);
	int AddCustomer(Customer* customer);
	void ViewCustomer();
	int editIName(string& cusID, string& cusName);
	int editContacts(string& cusID, string& cusContacts);
	int editAddress(string& cusID, string& cusAddress);

};


#endif

