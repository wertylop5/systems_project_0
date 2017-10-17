#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"../include/list.h"

struct node* new_node(char *artist, char *song, struct node *next) {
	struct node *new = (struct node *)malloc(sizeof(struct node));
	
	new->artist = (char *)malloc(strlen(artist)+1);
	new->song = (char *)malloc(strlen(song)+1);
	
	strncpy(new->artist, artist, strlen(artist)+1);
	strncpy(new->song, song, strlen(song)+1);
	
	new->next = next;
	
	return new;
} 

size_t list_len(struct node *head) {
	size_t res;
	for (res = 0; head; res++, head=head->next);
	return res;
}

struct node* insert_front(struct node *head, char *artist, char *song) {
	return new_node(artist, song, head);
}

struct node* insert_at(struct node *head, int index, char *artist, char *song) {
	struct node *temp = head;
	
	if (!index) {
		return insert_front(head, artist, song);
	}
	
	index--;
	while(index--) {
		temp = temp->next;
	}
	
	temp->next = new_node(artist, song, temp->next);
	
	return head;
}

void print_list(struct node *head) {
	printf("-----BEGIN LIST-----\n");
	while (head) {
		printf("artist: %s\t\tsong: %s\n", head->artist, head->song);
		head = head->next;
	}
	printf("-----END LIST-----\n\n");
}

struct node* find_song(struct node *head, char *song) {
	while (head) {
		if (!strncmp(head->song, song, strlen(song)+1)) {
			return head;
		}
		head = head->next;
	}
	
	return NULL;
}

struct node* find_first_song_by_artist(struct node *head, char *artist) {
	while (head) {
		if (!strncmp(head->artist, artist, strlen(artist)+1)) {
			return head;
		}
		head = head->next;
	}
	
	return NULL;
}

struct node* get_random_song(struct node *head) {
	srand(time(NULL));
	
	int targ = rand() % list_len(head) - 1;
	
	while (targ--) {
		head = head->next;
	}
	
	return head;
}

struct node* free_list(struct node *head) {
	struct node *temp;
	while (head) {
		temp = head->next;
		free(head);
		head = temp;
	}
	
	return head;
}

