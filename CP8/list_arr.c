#include "list_arr.h"

List *list_create()
{
	List *l = (List*) malloc(sizeof(List));

	if (!l)
		return NULL;

	for (int i = 0; i < POOL_SIZE; ++i) 
		l->data[i].next = &(l->data[i+1]);

	l->data[POOL_SIZE - 1].next = NULL;
	l->head->next = l->head;
	l->top = &(l->data[0]);
	l->size = 0;

	return l;
}

Iterator list_add_element(List *l, Iterator *i, char letter)
{
	Iterator res = { l->top };

	if(!res.node)
		return last(l);

	l->top = l->top->next;

	res.node->letter = letter;

	res.node->next = i->node->next;
	i->node->next = res.node;

	++l->size;

	return res;
}

Iterator list_delete_element(List *l, Iterator* i)
{
	Iterator res = last(l);
	if (equal(i, &res))
		return res;

	res.node = i->node->next;
	i->node->next = l->top;

	l->top = i->node;
	i->node = NULL;

	--l->size;

	return res;
}

Iterator first(List *list)
{
	Iterator i = { list->head->next };
	return i;
}

Iterator last(List *list)
{
	Iterator i = { list->head };
	return i;
}

Iterator next(Iterator *i)
{
	i->node = i->node->next;
	return *i;
}


void list_print(List *list)
{

}

int list_lenght(List *list)
{
	Iterator i, _last = last(list);
	int dlinna = 0;
	for (i = first(list); not_equal(&i, &_last); next(&i))
	{
		++dlinna;
	}

	return dlinna;
}

bool not_equal(Iterator *i, Iterator *j)
{
	return !equal(i, j);
}

bulochka equal(Iterator *i, Iterator *j)
{
	return !not_equal(i, j);
}