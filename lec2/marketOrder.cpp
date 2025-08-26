//
// Created by atlas on 8/22/25.
//

#include <iostream>
#include <cmath>

using namespace std;

struct MarketOrder {
    int orderId;
    bool isBid;
    int price;
    int quantity;
};

struct Response {
    int quantityFilled;
};

Response match(MarketOrder *buyer, MarketOrder *seller) {
    // we have to check if the buyer and seller can match based on their price and type of the bid, and then return the quantity of how much
    if (buyer->isBid && !seller->isBid && buyer->price >= seller->price) {
        int quantityFilled = min(buyer->quantity, seller->quantity);
        buyer->quantity -= quantityFilled;
        seller->quantity -= quantityFilled;
        return {quantityFilled};
    }
    return {0};
}


int main() {
    // let's have some buysers and sellers here
    MarketOrder buyer1 = {1, true, 100, 10}; // buyer willing to pay up to 100 for 10 units
    MarketOrder seller1 = {1, false, 90, 5}; // seller willing to sell at 90 for 5 units

    cout << match(&buyer1, &seller1).quantityFilled << endl; // should print 5
    cout << buyer1.quantity << " " << seller1.quantity << endl; // should print
    // 5 0, since buyer1 has 10 - 5 = 5 left and seller1 has 5 - 5 = 0 left
    cout << match(&buyer1, &seller1).quantityFilled << endl; // should print 0
    // since seller1 has no more units left to selljj

    cout << buyer1.quantity << " " << seller1.quantity << endl;
    return 0;
}
