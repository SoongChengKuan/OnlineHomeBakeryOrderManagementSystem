#include <string>
#include<iostream>
#include <iomanip>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "OrderProduct.h"
#include "OrderProductManager.h"
#include "DatabaseConnection.h"

bool OrderProductManager::checkOPexist(string& OrderID, string& ItemID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDER_PRODUCT WHERE ORDER_ID = ? AND ITEM_ID=?");

	ps->setString(1, OrderID);
	ps->setString(2, ItemID);

	ResultSet* rs = ps->executeQuery();

	while (rs->next())
	{
		if (OrderID == rs->getString("ORDER_ID") && ItemID==rs->getString("ITEM_ID"))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

int OrderProductManager::AddOrderProduct(OrderProduct* orderproduct)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO ORDER_PRODUCT VALUES (?,?,?,?)");

	ps->setString(1, orderproduct->order_id);
	ps->setString(2, orderproduct->item_id);
	ps->setInt(3, orderproduct->item_quantity);
	ps->setString(4, orderproduct->customer_remark);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

void OrderProductManager::ViewOrderProduct()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDER_PRODUCT");

	ResultSet* res = ps->executeQuery();
	cout << endl;
	cout << left;
	cout << setw(70) <<" "<<setw(20)<< "ORDER ID" << setw(20) << "ITEM ID" << setw(20) << "ITEM QUANTITY" << setw(60) << "CUSTOMER REMARK";
	while (res->next())
	{
		cout << "\n"<<setw(70) << " " << setw(20) << res->getString("ORDER_ID") << setw(20) << res->getString("ITEM_ID")<<setw(20)<< res->getString("ITEM_QUANTITY") << setw(60) << res->getString("CUSTOMER_REMARK");
	}
}

int OrderProductManager::editQuantity(string& orderID, string& itemID,int& newQuantity)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ORDER_PRODUCT SET ITEM_QUANTITY=? WHERE ORDER_ID=? AND ITEM_ID=?");

	ps->setInt(1, newQuantity);
	ps->setString(2, orderID);
	ps->setString(3, itemID);

	int status2 = ps->executeUpdate();

	delete ps;

	return status2;
}

int OrderProductManager::editRemark(string& orderID, string& itemID, string& newRemark)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ORDER_PRODUCT SET CUSTOMER_REMARK=? WHERE ORDER_ID=? AND ITEM_ID=?");

	ps->setString(1, newRemark);
	ps->setString(2, orderID);
	ps->setString(3, itemID);

	int status3 = ps->executeUpdate();

	delete ps;

	return status3;
}

int OrderProductManager::DeleteOrderProduct(string& ID5, string& ID6)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM ORDER_PRODUCT WHERE ITEM_ID=? AND ORDER_ID=?");

	ps->setString(1, ID5);
	ps->setString(2, ID6);

	int status1 = ps->executeUpdate();

	delete ps;

	return status1;
}
