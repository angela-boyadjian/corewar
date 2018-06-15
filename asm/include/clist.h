/*
** EPITECH PROJECT, 2018
** asm
** File description:
** clist
*/

#ifndef CLIST_H_
#define CLIST_H_

#include <stdlib.h>
#include <unistd.h>

enum branch {
	RIGHT = 0,
	LEFT = 1,
	ROOT = 2
};

struct tree {
	struct tree	*right;
	struct tree	*left;
	void		*token;
};

struct stack {
	struct stack	*next;
	void		*token;
};

struct queue {
	struct queue	*next;
	void		*token;
};

struct d_queue {
	struct d_queue	*next;
	struct d_queue	*back;
	void		*token;
};

char *dupstr(char const *, int);
char *stristr(char *, char const *);
int stoi(const char *);
int len(char const *);

struct stack *add_stack(struct stack *, void *);
void *pop_stack(struct stack **);
struct queue *add_queue(struct queue *, void *);
void *pop_queue(struct queue *);
struct tree *add_tree(struct tree *, void *, enum branch);
void *pop_tree(struct tree *, enum branch);
struct d_queue *add_d_queue(struct d_queue *root, void *value);
void *pop_d_queue(struct d_queue *root);

struct queue *create_queue(const char *, const char **, size_t);

#endif