//
// Created by atlas on 9/14/25.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Order
{
public:
    int orderId;

    bool cancelOrder()
    {
        cout << "Order Cancelled" << endl;
        return true;
    }
};

class GoodTillCancelledOrder : public Order
{
public:
    bool cancelOrder() {
        cout << "Good Till Cancelled" << endl;
        return true;
    }
};

class ImmediateOrCancelOrder : public Order
{
public:
    bool cancelOrder() {
        cout << "Immediate Or Cancel" << endl;
        return true;
    }
};

int main()
{

    GoodTillCancelledOrder gtc;
    ImmediateOrCancelOrder ioc;

    gtc.cancelOrder();
    ioc.cancelOrder();

    Order *order1 = &gtc;
    Order *order2 = &ioc;

    order1->cancelOrder();
    order2->cancelOrder();

    vector<Order *> orders = {order1, order2};

    for (auto order : orders) {
        order->cancelOrder();
    }

    auto* ioc2 = reinterpret_cast<ImmediateOrCancelOrder *>(&gtc);
    ioc2->cancelOrder();

}