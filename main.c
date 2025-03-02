#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char * sku = argv[1];
	int size = 5;
	Item *items = (Item*)malloc(size*sizeof(Item));
		
	add_item(items, 30.85, "10013", "Input Devices", "Keyboard", 0);
	add_item(items, 64.72, "14512", "Displays", "Monitor", 1);
	add_item(items, 26.93, "98205", "Input Devices", "Mouse", 2);
	add_item(items, 52.87, "42370", "Storage", "SSD", 3);
	add_item(items, 193.44, "68687", "PCI Cards", "GPU", 4);
	
	print_items(items, size);
	average_price(items, size);
	
	if(sku != NULL)
	{
		printf("\nSearching for %s\n", sku);
		int count = 0;
		while(count < size && strcmp((items + count)->sku,sku) != 0)
		{	
			++count;
		}
		if(count == size)
		{
			printf("Item could not be found. Please be sure to type the sku correctly.");
		}
		else
		{
			printf("****************\nYour Item:\n****************\nName: %s\nSku: %s\nCategory: %s\nPrice: $%f\n", (items + count)->name, (items + count)->sku, (items + count)->category, (items + count)->price);
		}	

		free_items(items, 5);
	}
	else
	{
		printf("\nEnter a sku when running the program to search for an item.\n");
	}
}
