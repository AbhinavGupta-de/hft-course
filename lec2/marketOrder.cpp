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

Response match(MarketOrder buyer, MarketOrder seller) {
    // we have to check if the buyer and seller can match based on their price and type of the bid, and then return the quantity of how much
    if (buyer.isBid && !seller.isBid && buyer.price >= seller.price) {
        int quantityFilled = min(buyer.quantity, seller.quantity);
        return {quantityFilled};
    }
    return {0};
}


int main() {
    // let's have some buysers and sellers here
    MarketOrder buyer1 = {1, true, 100, 10}; // buyer willing to pay up to 100 for 10 units
    MarketOrder seller1 = {2, false, 90, 5}; // seller willing to sell at 90 for 5 units
    MarketOrder seller2 = {3, false, 110, 10}; // seller willing to sell at 110 for 10 units
    MarketOrder buyer2 = {4, true, 80, 10}; // buyer willing to pay up to 80 for 10 units
    MarketOrder seller3 = {5, false, 100, 15}; // seller willing to sell at 100 for 15 units
    MarketOrder buyer3 = {6, true, 100, 20}; // buyer willing to pay up to 100 for 20 units
    MarketOrder seller4 = {7, false, 95, 10}; // seller willing to sell at 95 for 10 units
    MarketOrder buyer4 = {8, true, 105, 5}; // buyer willing to pay up to 105 for 5 units

    // let's match them, and print the results: we are going to loop through all buyers and sellers
    MarketOrder buyers[] = {buyer1, buyer2, buyer3, buyer4};
    MarketOrder sellers[] = {seller1, seller2, seller3, seller4};
    for (auto buyer: buyers) {
        for (auto seller: sellers) {
            Response response = match(buyer, seller);
            if (response.quantityFilled > 0) {
                cout << "Matched Buyer " << buyer.orderId << " with Seller " << seller.orderId
                        << " for quantity " << response.quantityFilled << endl;
            }
        }
    }
    return 0;
}
