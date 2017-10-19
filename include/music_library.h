#ifndef MUSIC_LIBRARY_H
#define MUSIC_LIBRARY_H

#include"list.h"

#define MUSIC_LIB_LEN 26

void add_song(struct node **lib, char *artist, char *song);

struct node* find_by_song_name_artist(struct node **lib,
	char *artist, char *song);
struct node* find_by_artist(struct node **lib, char *artist);

void print_all_by_letter(struct node **lib, char letter);
void print_all_by_artist(struct node **lib, char *artist);
void print_library(struct node **lib);
void shuffle(struct node **lib);

void delete_song(struct node **lib, char *artist, char *song);
void delete_all_songs(struct node **lib);


#endif
