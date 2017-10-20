#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<time.h>
#include"../include/list.h"

//so seed only gets set once
static char seed_set = 0;

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
	printf("inserting at front artist: %s, song: %s\n", artist, song);
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

struct node* insert_order(struct node *head, char *artist, char *song) {
	printf("inserting in order artist: %s, song: %s\n", artist, song);
	if (!head || strncasecmp(artist, head->artist, strlen(artist)+1) < 0) {
		head = insert_front(head, artist, song);
		return head;
	}
	else if (!strncasecmp(artist, head->artist, strlen(artist)+1)) {
		if (strncasecmp(song, head->song, strlen(song)+1) <= 0) {
			head = insert_front(head, artist, song);
		}
		return head;
	}
	
	if(!(head->next)) {
		if (strncasecmp(artist, head->artist, strlen(artist)+1 > 0 ||
				strncasecmp(song, head->song, strlen(song)+1 > 0))) {
			head = insert_at(head, 1, artist, song);
		}
		else {
			head = insert_front(head, artist, song);
		}
		return head;
	}
	
	struct node *hi = head->next;
	struct node *lo = head;
	int cmp_res, counter = 1;
	while(hi) {
		cmp_res = strncasecmp(artist, hi->artist, strlen(artist)+1);
		
		if(cmp_res < 0) {
			lo->next = new_node(artist, song, hi);
			return head;
		}
		else if (cmp_res == 0) {
			//now check the songs, use the same procedure
			while(hi) {
				cmp_res = strncasecmp(artist, hi->artist, strlen(artist)+1);
				
				//if no more of the same artist
				if (cmp_res < 0) {
					lo->next = new_node(artist, song, hi);
					return head;
				}
				
				cmp_res = strncasecmp(song, hi->song, strlen(song)+1);
				
				//found the spot
				if (cmp_res <= 0) {
					lo->next = new_node(artist, song, hi);
					return head;
				}
				
				lo = lo->next;
				hi = hi->next;
			}
			
			//reached end of list
			lo->next = new_node(artist, song, lo->next);
			return head;
		}
		
		lo = lo->next;
		hi = hi->next;
	}
	
	//reached end of list
	lo->next = new_node(artist, song, hi);
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
	printf("finding song: %s\n", song);
	while (head) {
		if (!strncasecmp(head->song, song, strlen(song)+1)) {
			return head;
		}
		head = head->next;
	}
	
	return NULL;
}

struct node* find_first_song_by_artist(struct node *head, char *artist) {
	printf("finding first song by artist: %s\n", artist);
	while (head) {
		if (!strncasecmp(head->artist, artist, strlen(artist)+1)) {
			return head;
		}
		head = head->next;
	}
	
	return NULL;
}

struct node* get_random_song(struct node *head) {
	if (!seed_set) {
		srand(time(NULL));
		seed_set++;
	}
	
	if (!head) {
		return NULL;
	}
	
	int targ = rand() % (list_len(head));
	
	while (targ--) {
		head = head->next;
	}
	
	return head;
}

struct node* remove_node(struct node *head, int index) {
	struct node *temp = head;
	
	if (!index) {
		head = temp->next;
		free(temp);
		return head;
	}
	
	index--;
	while(index--) {
		temp = temp->next;
	}
	
	struct node* temp2 = temp->next->next;
	free(temp->next);
	temp->next = temp2;
	
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

