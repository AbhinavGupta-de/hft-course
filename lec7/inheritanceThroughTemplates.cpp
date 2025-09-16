//
// Created by atlas on 9/17/25.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename Derived>
class Order
{
public:
    int32_t orderId;
    void cancelOrder()
    {
        // pointer to derived class
        static_cast<Derived*>(this)->cancelOrder();
    }
};

class GoodTillCancelledOrder : public Order<GoodTillCancelledOrder>
{
public:
    void cancelOrder()
    {
        cout << "Good Till Cancelled" << endl;
    }
};


class ImmediateOrCancelOrder : public Order<ImmediateOrCancelOrder>
{
public:
    void cancelOrder()
    {
        cout << "Immediate Or Cancel" << endl;
    }
};


int main()
{
    Order<GoodTillCancelledOrder> *gtc = new GoodTillCancelledOrder();
    Order<ImmediateOrCancelOrder> *ioc = new ImmediateOrCancelOrder();
    gtc->cancelOrder();
    ioc->cancelOrder();
}