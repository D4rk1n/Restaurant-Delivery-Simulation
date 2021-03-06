#ifndef __ORDER_H_
#define __ORDER_H_

#include "..\Defs.h"
#include <cmath>
class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, Frozen, VIP
	REGION Region;  //Region of this order
	int Distance;	//The distance (in meters) between the order location and the resturant 
	                
	double totalMoney;	//Total order money

	int ArrTime, ServTime, FinishTime, WaitTime;	//arrival, service start, and finish times


public:
	Order(int ID, ORD_TYPE r_Type, REGION r_region,int Dist,int TotalMon,int ArrTim);
	
	virtual ~Order();

	int GetID();

	ORD_TYPE GetType() const;
	REGION GetRegion() const;

	void SetDistance(int d);
	int GetDistance() const;
	void toVIP(int money=0);
	double Priorty() const;
	int getArrTime() const;
	void SetWaitTime(int CurrTime);
	int GetWaitTime();
	int getServeTime();
	void FinishOrder(int Speed);
	int GetFinishTime();
	int getTotalMoney();
	bool operator> (const Order& o);
	bool operator< (const Order& o);
	bool operator== (int id);
};

#endif