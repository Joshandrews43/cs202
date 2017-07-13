#include <cstdio>

#include "Request.h"
#include "EStore.h"
#include "RequestHandlers.h"

/*
 * ------------------------------------------------------------------
 * add_item_handler --
 *
 *      Handle an AddItemReq.
 *
 *      Delete the request object when done.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void 
add_item_handler(void *args)
{
    // TODO: Your code here.
    AddItemReq *add_item_request = (AddItemReq *)args;
    int item_id = add_item_request->item_id;
    int quantity = add_item_request->quantity;
    double price = add_item_request->price;
    double discount = add_item_request->discount;

    printf("Handling AddItemReq: item_id - %d, quantity - %d, price - %f, discount - %f\n", item_id, quantity, price, discount);

    add_item_request->store->addItem(item_id, quantity, price, discount);

    delete add_item_request;
}

/*
 * ------------------------------------------------------------------
 * remove_item_handler --
 *
 *      Handle a RemoveItemReq.
 *
 *      Delete the request object when done.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void 
remove_item_handler(void *args)
{
    // TODO: Your code here.
    RemoveItemReq *remove_item_request = (RemoveItemReq *)args;
    int item_id = remove_item_request->item_id;

    printf("Handling RemoveItemReq: item_id - %d\n", item_id);

    remove_item_request->store->removeItem(item_id);

    delete remove_item_request;
}

/*
 * ------------------------------------------------------------------
 * add_stock_handler --
 *
 *      Handle an AddStockReq.
 *
 *      Delete the request object when done.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void 
add_stock_handler(void *args)
{
    // TODO: Your code here.
    AddStockReq *add_stock_request = (AddStockReq *)args;
    int item_id = add_stock_request->item_id;
    int additional_stock = add_stock_request->additional_stock;

    printf("Handling AddStockReq: item_id - %d, additional_stock - %d\n", item_id, additional_stock);

    add_stock_request->store->addStock(item_id, additional_stock);

    delete add_stock_request;
}

/*
 * ------------------------------------------------------------------
 * change_item_price_handler --
 *
 *      Handle a ChangeItemPriceReq.
 *
 *      Delete the request object when done.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void 
change_item_price_handler(void *args)
{
    // TODO: Your code here.
    ChangeItemPriceReq *change_item_price_request = (ChangeItemPriceReq *)args;
    int item_id = change_item_price_request->item_id;
    double new_price = change_item_price_request->new_price;

    printf("Handling ChangeItemPriceReq: item_id - %d, new_price - %f\n", item_id, new_price);

    change_item_price_request->store->priceItem(item_id, new_price);

    delete change_item_price_request;
}

/*
 * ------------------------------------------------------------------
 * change_item_discount_handler --
 *
 *      Handle a ChangeItemDiscountReq.
 *
 *      Delete the request object when done.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void 
change_item_discount_handler(void *args)
{
    // TODO: Your code here.
    ChangeItemDiscountReq *change_item_discount_request = (ChangeItemDiscountReq *)args;
    int item_id = change_item_discount_request->item_id;
    double new_discount = change_item_discount_request->new_discount;

    printf("Handling ChangeItemDiscountReq: item_id - %d, new_discount - %f\n", item_id, new_discount);

    change_item_discount_request->store->discountItem(item_id, new_discount);

    delete change_item_discount_request;
}

/*
 * ------------------------------------------------------------------
 * set_shipping_cost_handler --
 *
 *      Handle a SetShippingCostReq.
 *
 *      Delete the request object when done.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void 
set_shipping_cost_handler(void *args)
{
    // TODO: Your code here.
    SetShippingCostReq *set_shipping_cost_request = (SetShippingCostReq *)args;
    double new_cost = set_shipping_cost_request->new_cost;

    printf("Handling SetShippingCostReq: new_cost - %f\n", new_cost);

    set_shipping_cost_request->store->setShippingCost(new_cost);

    delete set_shipping_cost_request;
}

/*
 * ------------------------------------------------------------------
 * set_store_discount_handler --
 *
 *      Handle a SetStoreDiscountReq.
 *
 *      Delete the request object when done.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void
set_store_discount_handler(void *args)
{
    // TODO: Your code here.
    SetStoreDiscountReq *set_store_discount_request = (SetStoreDiscountReq *)args;
    double new_discount = set_store_discount_request->new_discount;

    printf("Handling SetStoreDiscountReq: new_discount - %f\n", new_discount);

    set_store_discount_request->store->setStoreDiscount(new_discount);

    delete set_store_discount_request;
}

/*
 * ------------------------------------------------------------------
 * buy_item_handler --
 *
 *      Handle a BuyItemReq.
 *
 *      Delete the request object when done.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void
buy_item_handler(void *args)
{
    // TODO: Your code here.
    BuyItemReq *buy_item_request = (BuyItemReq *)args;
    int item_id = buy_item_request->item_id;
    double budget = buy_item_request->budget;

    printf("Handling BuyItemReq: item_id - %d, budget - $%f\n", item_id, budget);

    buy_item_request->store->buyItem(item_id, budget);

    delete buy_item_request;
}

/*
 * ------------------------------------------------------------------
 * buy_many_items_handler --
 *
 *      Handle a BuyManyItemsReq.
 *
 *      Delete the request object when done.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void
buy_many_items_handler(void *args)
{
    // TODO: Your code here.
}

/*
 * ------------------------------------------------------------------
 * stop_handler --
 *
 *      The thread should exit.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void 
stop_handler(void* args)
{
    // TODO: Your code here.
    printf("Handling StopHandlerReq: Quitting.\n");

    sthread_exit();
}

