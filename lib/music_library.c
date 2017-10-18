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
	struct node *ptr;
	
	
	if (!lib[index] || strncasecmp(artist, lib[index]->artist, strlen(artist)+1) < 0) {
		lib[index] = insert_front(lib[index], artist, song);
	}
	else if (!strncasecmp(artist, lib[index]->artist, strlen(artist)+1)) {
		if (strncasecmp(song, lib[index]->song, strlen(song)+1) <= 0) {
			lib[index] = insert_front(lib[index], artist, song);
		}
		else {
			lib[index] = insert_at(lib[index], 1, artist, song);
		}
	}
	else {
		ptr = lib[index];
		int counter = 0;
		while(ptr->next) {
			break;
			//if (str
		}
	}
}



void print_library(struct node **lib) {
	int x;
	for (x = 0; x < MUSIC_LIB_LEN; x++) {
		printf("Artists under %c\n", x+'a');
		print_list(lib[x]);
	}
	
}



