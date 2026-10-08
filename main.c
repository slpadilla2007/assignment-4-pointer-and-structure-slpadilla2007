#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

//Function prototypes
void add_item(Item *item_list, double newPrice, char *newSku, char *newCategory, char *newName, int index);
void free_items(Item *item_list, int size);
void print_items(Item *item_list, int size);
double average_price(Item *item_list, int size);

int main(int argc, char **argv) {
	
	char *input = argv[1];

	int listSize = 5;
	
	Item *theItems;
	theItems = (Item*) malloc(listSize*sizeof(Item));

	int indexCounter = 0;

	add_item(theItems, 4.5, "93121", "baking", "flour", indexCounter);
	indexCounter++;
	add_item(theItems, 6.3, "50830", "baking", "sugar", indexCounter);
	indexCounter++;
	add_item(theItems, 2.1, "26263", "candy", "skittles", indexCounter);
	indexCounter++;
	add_item(theItems, 3.9, "25041", "drinks", "sprite", indexCounter);
	indexCounter++;
	add_item(theItems, 7.2, "31106", "vegetables", "broccoli", indexCounter);

	print_items(theItems, listSize);

	printf("\n\naverage price of items: %.2f\n", average_price(theItems, listSize));
	
	indexCounter = 0;

	while (indexCounter < listSize && ) {
	
	}

	free_items(theItems, listSize);
	free(theItems);

	return 0;

}

void add_item(Item *item_list, double newPrice, char *newSku, char *newCategory, char *newName, int index) {
	
	item_list[index].price = newPrice;

	item_list[index].sku = (char*) malloc(strlen(newSku));
	strcpy(item_list[index].sku, newSku);

	item_list[index].category = (char*) malloc(strlen(newCategory));
	strcpy(item_list[index].category, newCategory);
	
	item_list[index].name = (char*) malloc(strlen(newName));
	strcpy(item_list[index].name, newName);

}

void free_items(Item *item_list, int size) {

	for (int i = 0; i < size; i++) {
	
		free(item_list[i].sku);
		free(item_list[i].name);
		free(item_list[i].category);
	
	}

}

void print_items(Item *item_list, int size) {

	for (int i = 0; i < size; i++) {
	
		printf("~~~~~~~~~~~~~~~~~~~~");
		printf("\n\nitem %d:\n\n", i + 1);
		printf("sku: %s\n", item_list[i].sku);
		printf("name: %s\n", item_list[i].name);
		printf("category: %s\n", item_list[i].category);
		printf("price: %.2f\n\n", item_list[i].price);
		
		if (i == size - 1) {
			printf("~~~~~~~~~~~~~~~~~~~~");
		}
	
	}

}

double average_price(Item *item_list, int size) {
	
	double theTotal = 0;

	for (int i = 0; i < size; i++) {
	
		theTotal += item_list[i].price;
	
	}

	double avg = theTotal/size;

	return avg;

}
