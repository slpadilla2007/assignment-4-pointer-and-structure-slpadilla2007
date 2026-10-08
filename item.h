#ifndef ITEM_H
#define ITEM_H

struct _item {

	double price;
	char *sku;
	char *name;
	char *category;

};

typedef struct _item Item;

#endif
