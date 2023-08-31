#include <string>
#include<iostream>
#include <iomanip>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "item.h"
#include "itemManager.h"
#include "DatabaseConnection.h"

bool ItemManager::checkID(string& ID1)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ORDER_PRODUCT WHERE ITEM_ID = ?");

	ps->setString(1, ID1);

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		if (ID1 == rs->getString("ITEM_ID"))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

bool ItemManager::IDexist(string& ID2)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ITEM WHERE ITEM_ID = ?");

	ps->setString(1, ID2);

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		if (ID2 == rs->getString("ITEM_ID"))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

int ItemManager::AddItem(Item* item)
{
	DatabaseConnection dbConn; 
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO ITEM VALUES (?,?,?,?,?)");

	ps->setString(1, item->item_id);
	ps->setString(2, item->item_name);
	ps->setDouble(3, item->item_price);
	ps->setString(4, item->item_ingredients);
	ps->setString(5, item->type_name);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

void ItemManager::ViewItem()
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ITEM");

	ResultSet* res = ps->executeQuery();

	cout << endl;
	cout << left;
	cout << setw(20) <<" "<<setw(15)<<"ITEM ID" << setw(40) << "ITEM NAME" << setw(15) << "ITEM PRICE" << setw(95) << "ITEM INGREDIENTS" << setw(20) << "TYPE NAME";
	while (res->next())
	{
		cout << left;
		cout << "\n" << setw(20) << " " << setw(15) << res->getString("ITEM_ID") << setw(40) << res->getString("ITEM_NAME") << fixed << setprecision(2) << setw(15) << res->getDouble("ITEM_PRICE") << setw(95) << res->getString("ITEM_INGREDIENTS") << setw(20) << res->getString("TYPE_NAME");
	}
	cout << endl;
}

int ItemManager::editIName(string& itemID, string& itemName)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ITEM SET ITEM_NAME=? WHERE ITEM_ID=?");

	ps->setString(1, itemName);
	ps->setString(2, itemID);

	int status2 = ps->executeUpdate();

	delete ps;

	return status2;
}

int ItemManager::editIPrice(string& itemID, double& itemPrice)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ITEM SET ITEM_PRICE=? WHERE ITEM_ID=?");

	ps->setDouble(1, itemPrice);
	ps->setString(2, itemID);

	int status3 = ps->executeUpdate();

	delete ps;

	return status3;
}

int ItemManager::editIIngredients(string& itemID, string&itemIngredients)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ITEM SET ITEM_INGREDIENTS=? WHERE ITEM_ID=?");

	ps->setString(1, itemIngredients);
	ps->setString(2, itemID);

	int status4 = ps->executeUpdate();

	delete ps;

	return status4;
}

int ItemManager::editIType(string& itemID, string& itemType)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ITEM SET TYPE_NAME=? WHERE ITEM_ID=?");

	ps->setString(1, itemType);
	ps->setString(2, itemID);

	int status5 = ps->executeUpdate();

	delete ps;

	return status5;
}

int ItemManager::DeleteItem(string& ID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM ITEM WHERE ITEM_ID=?");

	ps->setString(1, ID);

	int status1 = ps->executeUpdate();

	delete ps;

	return status1;
}
