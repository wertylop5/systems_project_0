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
	
	if (!lib[index] || strncasecmp(artist, lib[index]->artist, strlen(artist)+1) < 0) {
		lib[index] = insert_front(lib[index], artist, song);
		return;
	}
	else if (!strncasecmp(artist, lib[index]->artist, strlen(artist)+1)) {
		if (strncasecmp(song, lib[index]->song, strlen(song)+1) <= 0) {
			lib[index] = insert_front(lib[index], artist, song);
		}
		return;
	}
	
	if(!(head[index]->next)) {
		if (strncasecmp(artist, head[index]->artist, strlen(artist)+1 > 0 ||
				strncasecmp(song, head[index]->song, strlen(song)+1 > 0) {
			lib[index] = insert_at(lib[index], 1, artist, song);
		}
		else {
			lib[index] = insert_front(lib[index], artist, song);
		}
		return;
	}
	
	struct node *hi = lib[index]->next;
	struct node *lo = lib[index];
	int cmp_res, counter = 1;
	while(hi) {
		cmp_res = strncasecomp(artist, hi->artist, strlen(artist)+1);
		
		if(cmp_res < 0) {
			lo->next = new_node(artist, song, hi);
			return;
		}
		else if (cmp_res == 0) {
			lo = hi;
			hi = hi->next;
			
			//now check the songs, use the same procedure
			while(hi) {
				
				
				lo = lo->next;
				hi = hi->next;
			}
		}
		
		lo = lo->next;
		hi = hi->next;
	}
	
	lo->next = new_node(artist, song, hi);
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

