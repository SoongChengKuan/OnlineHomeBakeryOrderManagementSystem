#ifndef ORDERPRODUCTMANAGER_H
#define ORDERPRODUCTMANAGER_H

#include "OrderProduct.h"

class OrderProductManager
{
public:
	bool checkOPexist(string& OrderID, string& ItemID);
	int AddOrderProduct(OrderProduct* orderproduct);
	void ViewOrderProduct();
	int editQuantity(string& orderID, string& itemID, int& newQuantity);
	int editRemark(string& orderID, string& itemID, string& newRemark);
	int DeleteOrderProduct(string& ID5, string& ID6);

};


#endif

