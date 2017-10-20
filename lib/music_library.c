#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<strings.h>
#include"../include/music_library.h"

static char seed_set = 0;

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
	printf("finding by song name and artist (artist: %s, song: %s)\n", artist, song);
	struct node *result = find_by_artist(lib, artist);
	result = find_song(result, song);
	
	if (result && !strncasecmp(artist, result->artist, strlen(artist)+1)) {
		return result;
	}
	return NULL;
}

struct node* find_by_artist(struct node **lib, char *artist) {
	printf("finding by artist: %s\n", artist);
	int index = get_letter_index(artist);
	return find_first_song_by_artist(lib[index], artist);
}

void print_all_by_letter(struct node **lib, char letter) {
	printf("Artists under %c\n", letter);
	
	int index = get_letter_index(&letter);
	print_list(lib[index]);
}

void print_all_by_artist(struct node **lib, char *artist) {
	struct node *result = find_by_artist(lib, artist);
	if (!result) {
		printf("artist %s not found\n", artist);
	}
	else {
		printf("printing songs for artist %s\n", artist);
		while (result && !strncasecmp(artist, result->artist, strlen(artist)+1)) {
			printf("artist: %s\t\tsong: %s\n", result->artist, result->song);
			result = result->next;
		}
	}
	printf("\n");
}

void print_library(struct node **lib) {
	int x;
	for (x = 0; x < MUSIC_LIB_LEN; x++) {
		printf("Artists under %c\n", x+'a');
		print_list(lib[x]);
	}
	
}

void shuffle(struct node **lib) {
	if (!seed_set) {
		srand(time(NULL));
		seed_set++;
	}
	printf("results of shuffle:\n");
	
	int x, lib_pos;
	struct node *rand_song = NULL;
	for (x = 0; x < 4; x++) {
		do {
			lib_pos = rand() % MUSIC_LIB_LEN;
			rand_song = get_random_song(lib[lib_pos]);
		} while (!rand_song);
		
		if (rand_song) printf("artist: %s\t\tsong: %s\n", rand_song->artist, rand_song->song);
	}
	printf("\n");
}

void delete_song(struct node **lib, char *artist, char *song) {
	printf("deleting song: %s\n", song);
	int index = get_letter_index(artist);
	struct node *result = find_by_song_name_artist(lib, artist, song);
	
	if (result) {
		struct node *temp = lib[index];
		
		if (!strncasecmp(temp->song, result->song, strlen(temp->song)+1)) {
			lib[index] = remove_node(lib[index], 0);
			return;
		}
		
		//we know song exists, so safe to assume this
		while (temp->next != result) temp = temp->next;
		temp->next = remove_node(temp->next, 0);
	}
}

void delete_all_songs(struct node **lib) {
	printf("deleting all songs from library");
	int x;
	for (x = 0; x < MUSIC_LIB_LEN; x++) {
		lib[x] = free_list(lib[x]);
	}
}

