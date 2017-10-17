#ifndef LIST_H
#define LIST_H

#include<stdlib.h>

struct node {
	char *song;
	char *artist;
	
	struct node *next;
};

struct node* new_node(char *artist, char *song, struct node *next);

size_t list_len(struct node *head);

struct node* insert_front(struct node *head, char *artist, char *song);

/*
Inserts the node at the specified index
This means whatever was originally at that index will be pushed forward
*/
struct node* insert_at(struct node *head, int index, char *artist, char *song);

void print_list(struct node *list);

struct node* find_song(struct node *head, char *song);
struct node* find_first_song_by_artist(struct node *head, char *artist);
struct node* get_random_song(struct node *head, int len);

struct node* remove_node(struct node *head, int index);

struct node* free_list(struct node *head);



#endif
