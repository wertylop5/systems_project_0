#include<stdio.h>
#include<string.h>
#include<strings.h>
#include"../include/music_library.h"

int get_letter_index(char *str) {
	char thing;
	
	if (*str > 'Z') {
		thing = *str;
	}
	else {
		thing = *str + ('a' - 'A');
	}
	
	return (int)(thing-'a');
}

void add_song(struct node **lib, char *artist, char *song) {
	int index = get_letter_index(artist);
	lib[index] = insert_order(lib[index], artist, song);
}


struct node* find_by_song_name_artist(struct node **lib, char *artist, char *song) {
	
}

struct node* find_by_artist(struct node **lib, char *artist) {
	return NULL;
}

void print_all_by_letter(struct node **lib, char letter) {
	printf("Artists under %c\n", letter);
	
	int index = get_letter_index(&letter);
	print_list(lib[index]);
}


void print_library(struct node **lib) {
	int x;
	for (x = 0; x < MUSIC_LIB_LEN; x++) {
		printf("Artists under %c\n", x+'a');
		print_list(lib[x]);
	}
	
}


void delete_all_songs(struct node **lib) {
	int x;
	for (x = 0; x < MUSIC_LIB_LEN; x++) {
		lib[x] = free_list(lib[x]);
	}
}

