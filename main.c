#include<stdio.h>
#include"include/list.h"
#include"include/music_library.h"

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
	
	/*
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
	
	list = insert_at(list, 0, "Zeroth", "Anotha Zero");
	printf("%lu\n", list_len(list));
	print_list(list);
	*/
	
	printf("~~~~~~~~~~~~~~~~TESTING INSERT_ORDER~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	list = insert_order(list, "First", "One");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_order(list, "Second", "Two");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_order(list, "Zeroth", "Zero");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_order(list, "1.5th", "1.5");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_order(list, "secoNd", "A Two");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_order(list, "secoNd", "ZTwo");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	list = insert_order(list, "Zeroth", "ZZZero");
	printf("%lu\n", list_len(list));
	print_list(list);
	
	printf("~~~~~~~~~~~~~~~~TESTING FIND FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	struct node *temp;
	
	temp = find_song(list, "1.5");
	printf("artist: %s\t\tsong: %s\n", temp->artist, temp->song);
	
	temp = find_song(list, "Zero");
	printf("artist: %s\t\tsong: %s\n", temp->artist, temp->song);
	
	temp = find_first_song_by_artist(list, "Zeroth");
	printf("artist: %s\t\tsong: %s\n", temp->artist, temp->song);	
	
	temp = find_first_song_by_artist(list, "Second");
	printf("artist: %s\t\tsong: %s\n", temp->artist, temp->song);
	
	temp = find_first_song_by_artist(list, "sEcOnd");
	printf("artist: %s\t\tsong: %s\n", temp->artist, temp->song);
	
	printf("~~~~~~~~~~~~~~~~TESTING GET_RANDOM_SONG~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int x;
	for (x = 0; x < 10; x++) {
		temp = get_random_song(list);
		printf("artist: %s\t\tsong: %s\n", temp->artist, temp->song);
	}
	
	printf("~~~~~~~~~~~~~~~~TESTING REMOVE_NODE~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("original list\n");
	print_list(list);
	
	list = remove_node(list, 0);
	print_list(list);
	
	list = remove_node(list, 4);
	print_list(list);
	
	list = remove_node(list, 3);
	print_list(list);
	
	list = remove_node(list, 1);
	print_list(list);
	
	printf("~~~~~~~~~~~~~~~~TESTING FREE_LIST~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	list = free_list(list);
	print_list(list);
	
	
	
	printf("~~~~~~~~~~~~~~~~LIBRARY FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	struct node *library[MUSIC_LIB_LEN];
	for (x = 0; x < MUSIC_LIB_LEN; x++) {
		library[x] = NULL;
	}
	
	printf("~~~~~~~~~~~~~~~~TESTING ADD_SONG~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	//library[0] = new_node("ahh", "song", library[0]);
	
	add_song(library, "ahh", "oh no");
	add_song(library, "ahh", "song");
	add_song(library, "aah", "pizza");
	add_song(library, "billy", "bob");
	add_song(library, "babby", "waaa");
	add_song(library, "billy", "hello");
	
	
	printf("~~~~~~~~~~~~~~~~TESTING PRINT_LIBRARY~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	print_library(library);
	
	
	printf("~~~~~~~~~~~~~~~~TESTING FIND_BY_ARTIST~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	temp = find_by_artist(library, "ahh");
	print_list(temp);
	
	temp = find_by_artist(library, "BabbY");
	print_list(temp);
	
	temp = find_by_artist(library, "chuck");
	print_list(temp);
	
	
	printf("~~~~~~~~~~~~~~~~TESTING FIND_BY_SONG_NAME_ARTIST~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	temp = find_by_song_name_artist(library, "ahh", "oh no");
	print_list(temp);
	
	temp = find_by_song_name_artist(library, "billy", "bob");
	print_list(temp);
	
	temp = find_by_song_name_artist(library, "chuck", "fun");
	print_list(temp);
	
	temp = find_by_song_name_artist(library, "billy", "fun");
	print_list(temp);
	
	
	printf("~~~~~~~~~~~~~~~~TESTING PRINT_ALL_BY_LETTER~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	print_all_by_letter(library, 'a');
	print_all_by_letter(library, 'B');
	print_all_by_letter(library, 'x');
	
	
	printf("~~~~~~~~~~~~~~~~TESTING PRINT_ALL_BY_ARTIST~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	print_all_by_artist(library, "billy");
	print_all_by_artist(library, "babby");
	print_all_by_artist(library, "DNE");
	
	
	printf("~~~~~~~~~~~~~~~~TESTING SHUFFLE~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	shuffle(library);
	
	
	
	
	
	
	return 0;
}
