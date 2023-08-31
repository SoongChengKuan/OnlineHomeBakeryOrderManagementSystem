#ifndef ORDER_H
#define ORDER_H

#include<string>
#include<iostream>
using namespace std;

class Order
{
public:
	string order_id;
	string customer_id;
	string order_status;
	int order_rating;
	double order_totalprice;
	string order_date;
	string payment_status;

};
#endif
