#include "Order.h"

Order::Order(int id, ORD_TYPE r_Type, REGION r_region,int Dist,int TotalMon,int ArrTim)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	Region = r_region;	
	Distance = Dist;
	totalMoney = TotalMon;
	ArrTime = ArrTim;
	FinishTime = -1;
	ServTime = -1;
	WaitTime = -1;
}


Order::~Order()
{
}

int Order::GetID()
{
	return ID;
}

int Order:: getTotalMoney()
{
	return totalMoney;
}

ORD_TYPE Order::GetType() const
{
	return type;
}

int Order::getArrTime() const
{
	return ArrTime;
}
void Order::SetWaitTime(int CurrTime)
{
	WaitTime = CurrTime - ArrTime;
}
int Order::GetWaitTime()
{
	return WaitTime;
}
int Order::getServeTime()
{
	return ServTime;
}
void Order::toVIP(int money)
{
	type = TYPE_VIP;
	totalMoney += money;
}

REGION Order::GetRegion() const
{
	return Region;
}

void Order::SetDistance(int d)
{
	Distance = d>0?d:0; // d pos or zero
}

int Order::GetDistance() const
{
	return Distance;
}
double Order::Priorty() const
{
	return (double(Distance) / ArrTime) + (double(totalMoney) / Distance);
}
bool Order::operator< (const Order& o)
{
	if(FinishTime == -1)
		return Priorty() < o.Priorty();

	else if(FinishTime != o.FinishTime)
		{
			if(FinishTime > o.FinishTime)
				return true;

			return false;
		}

	else if (ServTime > o.ServTime)
		return true;

	return false;
}

bool Order::operator> (const Order& o)
{
	if(FinishTime == -1)
	return Priorty() > o.Priorty();

	else if(FinishTime != o.FinishTime)
		{
			if(FinishTime < o.FinishTime)
				return true;

			return false;
		}

	else if (ServTime < o.ServTime)
		return true;

	return false;
}
bool Order::operator== (int id)
{
	return GetID() == id;
}

void Order::FinishOrder(int Speed)
{
	FinishTime = ArrTime + WaitTime + ceil(Distance * 1.0 / Speed);
	ServTime=FinishTime-ArrTime-WaitTime;   //which equals the last term above 
}
int Order::GetFinishTime()
{
	return FinishTime;
}
