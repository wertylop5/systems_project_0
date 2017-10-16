#ifndef LIST_H
#define LIST_H


struct node {
	char *song;
	char *artist;
	
	struct node *next;
};

void print_list(struct node *);

struct node* insert_front(struct node *, char *, char *);


struct node* free_list(struct node *);



#endif
