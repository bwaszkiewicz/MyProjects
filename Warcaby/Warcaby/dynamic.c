#include <allegro5\allegro.h>

#include "defines.h"
#include "dynamic.h"
#include "pawns.h"

void CreateTrees(struct MainRoute **root_W, struct MainRoute **root_B)
{
	int orderW[12] = { 5,2,8,1,3,7,0,10,4,6,9,11 };
	int orderB[12] = { 17,14,20,12,15,18,22,13,16,19,21,23 };
	for (int i = 0; i < NUM_PAWNS / 2; ++i)
		AddTree(root_W, orderW[i]);
	for (int i = NUM_PAWNS / 2; i < NUM_PAWNS; ++i)
		AddTree(root_B, orderB[i - NUM_PAWNS / 2]);
}
void AddTree(struct MainRoute **root, int x)
{
	if (!(*root))
	{
		*root = malloc(sizeof(struct MainRoute));
		(*root)->ID = x;
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->head = NULL;
	}
	else
	{
		if ((*root)->ID > x)
			AddTree(&((*root)->left), x);
		else
			AddTree(&((*root)->right), x);
	}
}

void ClearTree(struct MainRoute **root)
{
	if (*root)
	{
		/*struct MainRoute** bufor_left = (&(*root)->left);
		struct MainRoute** bufor_right = (&(*root)->right);
		if (bufor_left)
		{
			ClearTree(bufor_left);
		}
		if (bufor_right)
		{
			ClearTree(bufor_right);
		}*/
		ClearTree(&(*root)->left);
		ClearTree(&(*root)->right);
		free(*root);
		(*root) = NULL;
	}
}

void add_route(int id, int direction, bool ruch, struct MainRoute **root_W, struct MainRoute **root_B, struct Route **head)
{
	struct MainRoute **buforW = root_W;
	struct MainRoute **buforB = root_B;
	if (!ruch)
	{ // biale
		if (!(*head))
		{
			*head = malloc(sizeof(struct Route));
			(*head)->direction = direction;
			(*head)->next = NULL;
		}
		else
		{
			add_route(id, direction, ruch, root_W, root_B, &((*head)->next));
		}
	}
	else
	{ // czarne
		if (!(*head))
		{
			*head = malloc(sizeof(struct Route));
			(*head)->direction = direction;
			(*head)->next = NULL;
		}
		else
		{
			add_route(id, direction, ruch, root_W, root_B, &((*head)->next));
		}
	}
}
void clear_route(int id, struct Pawn pawn[], struct MainRoute **root_W, struct MainRoute **root_B)
{
	struct MainRoute **buforW = root_W;
	struct MainRoute **buforB = root_B;
	struct Route *bufor, *wsk;
	if (id<NUM_PAWNS / 2)
	{ // biale
		while ((*buforW)->ID != id)
		{
			if (id >(*buforW)->ID)
				buforW = (&(*buforW)->right);
			else
				buforW = (&(*buforW)->left);
		}
		if ((*buforW)->head)
		{
			wsk = (*buforW)->head;
			while (wsk)
			{
				bufor = wsk;
				wsk = wsk->next;
				free(bufor);
			}
		}
		(*buforW)->head = NULL;
	}
	else
	{ // czarne
		while ((*buforB)->ID != id)
		{
			if (id > (*buforB)->ID)
				buforB = (&(*buforB)->right);
			else
				buforB = (&(*buforB)->left);
		}
		if ((*buforB)->head)
		{
			wsk = (*buforB)->head;
			while (wsk)
			{
				bufor = wsk;
				wsk = wsk->next;
				free(bufor);
			}
		}
		(*buforB)->head = NULL;
	}
}
struct Route** ReturnRouteHeadAddres(int id, bool ruch, struct MainRoute **root_W, struct MainRoute **root_B)
{
	struct MainRoute **buforW = root_W;
	struct MainRoute **buforB = root_B;
	if (!ruch)
	{
		while ((*buforW)->ID != id)
		{
			if (id > (*buforW)->ID)
				buforW = (&(*buforW)->right);
			else
				buforW = (&(*buforW)->left);
		}
		return &((*buforW)->head);
	}
	else
	{
		while ((*buforB)->ID != id)
		{
			if (id > (*buforB)->ID)
				buforB = (&(*buforB)->right);
			else
				buforB = (&(*buforB)->left);
		}
		return &((*buforB)->head);
	}
}