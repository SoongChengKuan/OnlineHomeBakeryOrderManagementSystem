#include <string>
#include<iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include <mysql.h>

#include "order.h"
#include "OrderManager.h"
#include "DatabaseConnection.h"

bool OrderManager::checkOrderExist1(string& ID6)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDERS WHERE ORDER_ID = ?");

	ps->setString(1, ID6);

	ResultSet* rs = ps->executeQuery();

	while (rs->next())
	{
		if (ID6 == rs->getString("ORDER_ID"))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

}

bool OrderManager::checkOrderExist(string& ID5)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDERS WHERE ORDER_ID = ? AND ORDER_STATUS='N'");

	ps->setString(1, ID5);

	ResultSet* rs = ps->executeQuery();

	while (rs->next())
	{
		if (ID5 == rs->getString("ORDER_ID") && rs->getString("ORDER_STATUS") == "N")
		{
			return false;
		}
		else
		{
			return true;
		}
	}

}

bool OrderManager::checkcurID(string& ID2)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDER_PRODUCT WHERE ORDER_ID = ? ");

	ps->setString(1, ID2);

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		if (ID2 == rs->getString("ORDER_ID"))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

bool OrderManager::checkcoID(string& ID4)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDERS WHERE ORDER_ID = ? AND ORDER_STATUS='C'");

	ps->setString(1, ID4);

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) 
	{
		if (ID4 == rs->getString("ORDER_ID")&& rs->getString("ORDER_STATUS")=="C")
		{
			return false;
		}
		else
		{
			return true;
		}
	}


}

int OrderManager::AddOrder(Order* order)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO ORDERS VALUES (?,?,?,?,?,?,?)");

	ps->setString(1, order->order_id);
	ps->setString(2, order->customer_id);
	ps->setString(3, order->order_status);
	ps->setInt(4, order->order_rating);
	ps->setDouble(5, order->order_totalprice);
	ps->setString(6, order->order_date);
	ps->setString(7, order->payment_status);


	int status = ps->executeUpdate();

	delete ps;

	return status;
}

void OrderManager::ViewAllOrder()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDERS");

	ResultSet* res = ps->executeQuery();

	cout << endl;
	cout << left;
	cout << setw(35) <<" " <<setw(20)<< "ORDER ID" << setw(20) << "CUSTOMER ID" << setw(20) << "ORDER STATUS" << setw(20) << "ORDER RATING" << setw(20) << "ORDER TOTAL PRICE" << setw(30) << "ORDER DATE(YYYY-MM-DD)" << setw(20) << "PAYMENT STATUS";
	while (res->next())
	{
		cout << left;
		cout << "\n" << setw(35)<<" "<<setw(20)<< res->getString("ORDER_ID") << setw(20) << res->getString("CUSTOMER_ID") << setw(20) << res->getString("ORDER_STATUS") << setw(20) << res->getInt("ORDER_RATING") << setw(20) << fixed << setprecision(2) << res->getDouble("ORDER_TOTALPRICE") << setw(30) << res->getString("ORDER_DATE") << setw(20) << res->getString("PAYMENT_STATUS");
	}
}

void OrderManager::ViewCurrentOrder()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDERS WHERE ORDER_STATUS='N'");

	ResultSet* res = ps->executeQuery();

	cout << endl;
	cout << left;
	cout << setw(35) << " " << setw(20) << "ORDER ID" << setw(20) << "CUSTOMER ID" << setw(20) << "ORDER STATUS" << setw(20) << "ORDER RATING"<<setw(20)<<"ORDER TOTAL PRICE"<<setw(30)<<"ORDER DATE(YYYY-MM-DD)"<<setw(20)<<"PAYMENT STATUS";
	while (res->next())
	{
		cout << left;
		cout << "\n" << setw(35) << " " << setw(20) << res->getString("ORDER_ID") << setw(20) << res->getString("CUSTOMER_ID") << setw(20) << res->getString("ORDER_STATUS") << setw(20) << res->getInt("ORDER_RATING") << setw(20) <<fixed<<setprecision(2)<< res->getDouble("ORDER_TOTALPRICE")<<setw(30)<<res->getString("ORDER_DATE") << setw(20) << res->getString("PAYMENT_STATUS");
	}
}

void OrderManager::ViewCompletedOrder()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDERS WHERE ORDER_STATUS='C'");

	ResultSet* res = ps->executeQuery();

	cout << endl;
	cout << left;
	cout << setw(35) <<" "<<setw(20)<< "ORDER ID" << setw(20) << "CUSTOMER ID" << setw(20) << "ORDER STATUS" << setw(20) << "ORDER RATING" << setw(20) << "ORDER TOTAL PRICE" << setw(30) << "ORDER DATE(YYYY-MM-DD)" << setw(20) << "PAYMENT STATUS";
	while (res->next())
	{
		cout << "\n" << setw(35) << " " << setw(20) << res->getString("ORDER_ID") << setw(20) << res->getString("CUSTOMER_ID") << setw(20) << res->getString("ORDER_STATUS") << setw(20) << res->getInt("ORDER_RATING") << setw(20) << fixed << setprecision(2) << res->getDouble("ORDER_TOTALPRICE") << setw(30) << res->getString("ORDER_DATE") << setw(20) << res->getString("PAYMENT_STATUS");
	}
}

int OrderManager::editcusID(string& orderID, string& cusID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ORDERS SET CUSTOMER_ID=? WHERE ORDER_ID=?");

	ps->setString(1, cusID);
	ps->setString(2, orderID);

	int status1 = ps->executeUpdate();

	delete ps;

	return status1;
}
int OrderManager::editOrderStatus(string& orderID, string& OStatus)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ORDERS SET ORDER_STATUS=? WHERE ORDER_ID=?");

	ps->setString(1, OStatus);
	ps->setString(2, orderID);

	int status2 = ps->executeUpdate();

	delete ps;

	return status2;
}
int OrderManager::editOrderRating(string& orderID, int& ORating)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ORDERS SET ORDER_RATING=? WHERE ORDER_ID=?");

	ps->setInt(1, ORating);
	ps->setString(2, orderID);

	int status3 = ps->executeUpdate();

	delete ps;

	return status3;
}
int OrderManager::editTotalPrice(string& orderID, double& Tprice)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ORDERS SET ORDER_TOTALPRICE=? WHERE ORDER_ID=?");

	ps->setDouble(1, Tprice);
	ps->setString(2, orderID);

	int status4 = ps->executeUpdate();

	delete ps;

	return status4;
}
int OrderManager::editOrderDate(string& orderID, string& ODate)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ORDERS SET ORDER_DATE=? WHERE ORDER_ID=?");

	ps->setString(1, ODate);
	ps->setString(2, orderID);

	int status5 = ps->executeUpdate();

	delete ps;

	return status5;
}
int OrderManager::editPaymentStatus(string& orderID, string& PStatus)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ORDERS SET PAYMENT_STATUS=? WHERE ORDER_ID=?");

	ps->setString(1, PStatus);
	ps->setString(2, orderID);

	int status6 = ps->executeUpdate();

	delete ps;

	return status6;
}

int OrderManager::DeleteOrder(string& ID3)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM ORDERS WHERE ORDER_ID=?");

	ps->setString(1, ID3);

	int status1 = ps->executeUpdate();

	delete ps;

	return status1;
}

void OrderManager::ViewSales(string& begin, string& end)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT ORDER_ID,CUSTOMER_ID,CUSTOMER_NAME, CUSTOMER_CONTACTS,ORDER_STATUS, ORDER_TOTALPRICE, CUSTOMER_NAME, ORDER_DATE, PAYMENT_STATUS FROM ORDERS JOIN CUSTOMER USING (CUSTOMER_ID) WHERE ORDER_DATE BETWEEN ? AND ? AND ORDER_STATUS='C'" );

	ps->setString(1, begin);
	ps->setString(2, end);

	ResultSet* res = ps->executeQuery();

	cout << endl;
	cout << left;
	cout << setw(23) << " "<<setw(20)<<"ORDER ID" << setw(20) << "CUSTOMER ID" << setw(35) << "CUSTOMER NAME" << setw(20) << "CUSTOMER CONTACTS" << setw(20) << "ORDER STATUS" << setw(20) << "ORDER TOTAL PRICE" << setw(20) << "ORDER DATE" << setw(20) << "PAYMENT STATUS";
	while (res->next())
	{
		cout << "\n" << setw(23) << " " << setw(20) << res->getString("ORDER_ID") << setw(20) << res->getString("CUSTOMER_ID") << setw(35) << res->getString("CUSTOMER_NAME") << setw(20) << res->getString("CUSTOMER_CONTACTS") << setw(20) << res->getString("ORDER_STATUS") << setw(20) << res->getDouble("ORDER_TOTALPRICE") << setw(20) << res->getString("ORDER_DATE") << setw(20) << res->getString("PAYMENT_STATUS");
	}
}

void OrderManager::ViewTotalSales(string& begin, string& end)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT SUM(ORDER_TOTALPRICE) 'TOTAL_SALES' FROM ORDERS JOIN CUSTOMER USING (CUSTOMER_ID) WHERE ORDER_DATE BETWEEN ? AND ? AND ORDER_STATUS='C'");

	ps->setString(1, begin);
	ps->setString(2, end);

	ResultSet* res = ps->executeQuery();
	while (res->next())
	{
		cout << endl;
		cout << endl;
		cout << "\n" << setw(80) <<" " << "Total sales between: " << begin << " and " << end << " :" << res->getDouble("TOTAL_SALES") << endl;
	}
}

void OrderManager::ViewRating(string& begin, string& end)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT ORDER_ID,ITEM_ID,ITEM_NAME, ITEM_QUANTITY, CUSTOMER_ID, CUSTOMER_NAME, ORDER_STATUS, ORDER_RATING FROM ITEM JOIN ORDER_PRODUCT USING (ITEM_ID) JOIN ORDERS USING (ORDER_ID) JOIN CUSTOMER USING (CUSTOMER_ID) WHERE ORDER_STATUS='C' AND ORDER_DATE BETWEEN ? AND ?");
	
	ps->setString(1, begin);
	ps->setString(2, end);

	ResultSet* res = ps->executeQuery();

	cout << endl;
	cout << left;
	cout << setw(15) <<" "<< setw(20)<<"ORDER ID" << setw(20) << "ITEM ID" << setw(35) << "ITEM NAME" << setw(20) << "ITEM QUANTITY" << setw(20) << "CUSTOMER ID" << setw(35) << "CUSTOMER NAME" << setw(20) << "ORDER STATUS" << setw(20) << "ORDER RATING";
	while (res->next())
	{
		cout << "\n" << setw(15) << " " << setw(20) << res->getString("ORDER_ID") << setw(20) << res->getString("ITEM_ID") << setw(35) << res->getString("ITEM_NAME") << setw(20) << res->getInt("ITEM_QUANTITY") << setw(20) << res->getString("CUSTOMER_ID") << setw(35) << res->getString("CUSTOMER_NAME") << setw(20) << res->getString("ORDER_STATUS") << setw(20) << res->getInt("ORDER_RATING");
	}
}

void OrderManager::viewAverageRating(string& begin, string& end)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps1 = dbConn.prepareStatement("SELECT AVG(ORDER_RATING) 'AVERAGE_RATING' FROM ORDERS WHERE ORDER_STATUS='C' AND ORDER_DATE BETWEEN ? AND ?");
	
	ps1->setString(1, begin);
	ps1->setString(2, end);

	ResultSet* res1 = ps1->executeQuery();
	while (res1->next())
	{
		cout << endl;
		cout << "\n" << setw(90)<<" " << "Average rating: " << res1->getDouble("AVERAGE_RATING")<<" out of 5" << endl;
	}
	
}

