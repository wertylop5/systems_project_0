#include<stdio.h>
#include"include/list.h"

int main() {
	struct node *list = NULL;
	print_list(list);
	
	printf("%lu\n", list_len(list));
	
	printf("~~~~~~~~~~~~~~~~TESTING INSERT_FRONT~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	list = insert_front(list, "Test", "Song");
	printf("%lu\n", list_len(list));
	
	list = insert_front(list, "Hey", "There");
	printf("%lu\n", list_len(list));
	
	list = insert_front(list, "bro", "omg");
	printf("%lu\n", list_len(list));
	
	print_list(list);
	
	list = free_list(list);
	printf("%lu\n", list_len(list));
	print_list(list);
	
	printf("~~~~~~~~~~~~~~~~TESTING INSERT_AT~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	list = insert_at(list, 0, "First", "One");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_at(list, 1, "Second", "Two");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_at(list, 0, "Zeroth", "Zero");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_at(list, 2, "1.5th", "1.5");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_at(list, 1, "0.5th", "0.5");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	printf("~~~~~~~~~~~~~~~~TESTING FIND FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	struct node *temp;
	
	temp = find_song(list, "1.5");
	printf("artist: %s\t\tsong: %s\n", temp->artist, temp->song);
	
	temp = find_song(list, "Zero");
	printf("artist: %s\t\tsong: %s\n", temp->artist, temp->song);
	
	return 0;
}
