#include "item.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
	//allocate memory
	(item_list + index)->sku = (char *) malloc((strlen(sku))*sizeof(char));
	(item_list + index)->category = (char *) malloc((strlen(category))*sizeof(char));
	(item_list + index)->name = (char *) malloc((strlen(name))*sizeof(char));
	//set values
	(item_list + index)->price = price;
	strcpy((item_list + index)->sku, sku);
	strcpy((item_list + index)->category, category);
	strcpy((item_list + index)->name, name);
}

void free_items(Item *item_list, int size)
{
	for (int i = 0; i < size; ++i)
	{
		//free(item_list[i].sku);
		free((item_list + i)->sku);
		free((item_list + i)->category);
		free((item_list + i)->name);	
	}
	free(item_list);
}

double average_price(Item *item_list, int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += (item_list + i)->price;
	}	
	return sum/size;
}

void print_items(Item *item_list, int size)
{
	printf("Printing items.\n");
	for (int i = 0; i < size; ++i)
	{
		printf("****************\nItem %d\n****************\nName: %s\nSku: %s\nCategory: %s\nPrice: $%f\n", i, (item_list + i)->name, (item_list + i)->sku, (item_list + i)->category, (item_list + i)->price);
	}
}
