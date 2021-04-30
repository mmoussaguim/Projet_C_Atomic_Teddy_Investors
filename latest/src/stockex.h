#ifndef __STOCKEX_H
#define __STOCKEX_H
#include "define.h"
#include "good.h"

// The type representing transactions
struct transac;

// The type representing stock exchanges
struct stockex;

// The starting stock exchange
const struct stockex* starting_stockex();

// The name of the stock exchange
const char*           stockex__name(const struct stockex* s);

// Iterator on transactions : the first function returns the number
// `n` of available transactions, and the second accesses them with
// indices ranging between 0 and n-1.
size_t                stockex__num_transactions(const struct stockex* t);
const struct transac* stockex__transaction(const struct stockex* t, size_t num);
// The goods bought by the stock exchange
struct wallet         transac__in_wallet(const struct transac* s);
// The goods sold by the stock exchange
struct wallet         transac__out_wallet(const struct transac* s);

// The stock exchange where the transaction is done
const struct stockex* transac__stockex(const struct transac* s);
// The stock exchange reached after the transaction
const struct stockex* transac__next_stockex(const struct transac* s);

#endif
