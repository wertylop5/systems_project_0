#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

struct node* free_list(struct node *head) {
	struct node *temp;
	while (head) {
		temp = head->next;
		free(head);
		head = temp;
	}
	
	return head;
}

