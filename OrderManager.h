#ifndef ORDERMANAGER_H
#define ORDERANAGER_H

#include "order.h"

class OrderManager
{
public:
	bool checkOrderExist1(string& ID6); //check both completed and current order//
	bool checkOrderExist(string& ID5); //check current order//
	bool checkcurID(string& ID2); //check order_product//
	bool checkcoID(string& ID4); //check completed order//
	int AddOrder(Order* order);
	void ViewAllOrder();
	void ViewCurrentOrder();
	void ViewCompletedOrder();
	int editcusID(string& orderID, string& cusID);
	int editOrderStatus(string& orderID, string& OStatus);
	int editOrderRating(string& orderID, int& ORating);
	int editTotalPrice(string& orderID, double& Tprice);
	int editOrderDate(string& orderID, string& ODate);
	int editPaymentStatus(string& orderID, string& PStatus);
	int DeleteOrder(string& ID3);
	void ViewRating(string& begin, string& end);
	void viewAverageRating(string& begin, string& end);
	void ViewSales(string& begin, string& end);
	void ViewTotalSales(string& begin, string& end);
};


#endif

