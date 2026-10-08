#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

//Function prototypes
void add_item(Item *item_list, double newPrice, char *newSku, char *newCategory, char *newName, int index);
void free_items(Item *item_list, int size);
void print_items(Item *item_list, int size);
void print_oneItem(Item *item_list, int number);
double average_price(Item *item_list, int size);

int main(int argc, char **argv) {
	
	char *input = argv[1];

	int listSize = 5;

	//Makes a dynamically allocated array of Items
	Item *theItems;
	theItems = (Item*) malloc(listSize*sizeof(Item));

	//Makes an index counter set to zero
	int indexCounter = 0;

	//Adds a new item using the add_item func and adds 1 to the index counter five times
	add_item(theItems, 4.5, "93121", "baking", "flour", indexCounter);
	indexCounter++;
	add_item(theItems, 6.3, "50830", "baking", "sugar", indexCounter);
	indexCounter++;
	add_item(theItems, 2.1, "26263", "candy", "skittles", indexCounter);
	indexCounter++;
	add_item(theItems, 3.9, "25041", "drinks", "sprite", indexCounter);
	indexCounter++;
	add_item(theItems, 7.2, "31106", "vegetables", "broccoli", indexCounter);

	//Prints all the items
	print_items(theItems, listSize);

	//Prints the average price of the items
	printf("\n\naverage price of items: %.2f\n", average_price(theItems, listSize));

	//Sets the indexCounter back to zero and makes a comparison variable
	indexCounter = 0;
	int theCompare = 1;

	//Loop that runs while the indexCounter is less than the size and theCompare isn't zero
	while (indexCounter < listSize && theCompare != 0) {
		theCompare = strcmp(theItems[indexCounter].sku, input);
		indexCounter++;
	}

	//If the comparison variable is still not zero, prints that item wasn't found
	if (theCompare != 0) {
		printf("item not found.");
	} else {
		//Else, runs the print_oneItem function passing the last indexCounter
		print_oneItem(theItems, indexCounter);
	}

	//Runs the free_items function
	free_items(theItems, listSize);

	//Code done yippee
	return 0;

}

//Sets each indexed item equal to the given parameters
void add_item(Item *item_list, double newPrice, char *newSku, char *newCategory, char *newName, int index) {
	
	item_list[index].price = newPrice;
	
	//For each string variable, memory is allocated
	item_list[index].sku = (char*) malloc(strlen(newSku));
	strcpy(item_list[index].sku, newSku);

	item_list[index].category = (char*) malloc(strlen(newCategory));
	strcpy(item_list[index].category, newCategory);
	
	item_list[index].name = (char*) malloc(strlen(newName));
	strcpy(item_list[index].name, newName);

}

//Frees all allocated memory
void free_items(Item *item_list, int size) {

	for (int i = 0; i < size; i++) {
	
		free(item_list[i].sku);
		free(item_list[i].name);
		free(item_list[i].category);
	
	}

	free(item_list);
		
}

//Prints each item
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

//Prints only one item (easier this way)
void print_oneItem(Item *item_list, int number) {

	printf("\nitem found.");
	printf("\n\nitem %d:\n\n", number);
	number--; //Have to subtract one so that the following are indexed correctly
	printf("sku: %s\n", item_list[number].sku);
	printf("name: %s\n", item_list[number].name);
	printf("category: %s\n", item_list[number].category);
	printf("price: %.2f\n\n", item_list[number].price);
	
}

//Returns the average price of all the items
double average_price(Item *item_list, int size) {
	
	double theTotal = 0;

	for (int i = 0; i < size; i++) {
	
		theTotal += item_list[i].price;
	
	}

	double avg = theTotal/size;

	return avg;

}
