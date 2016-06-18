#ifndef _TREE_H_
#define _TREE_H_

#include "dijkstra.h"
#include "matem.h"

typedef struct _tree Tree;

struct _tree
{
	Tree *left;
	Tree *right;
	Data *data;
};

Tree *tree_create(Data *data);
void tree_add_elem(Tree *tree, Data *data);
void tree_print(Tree *tree, int lvl);
Tree *tree_build(Stack *out);
void tree_BFS_print(Tree *tree);
int find_tree_depht(Tree* tree, int d);
void tree_destroy(Tree** tree);


#endif
