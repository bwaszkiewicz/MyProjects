#include <allegro5\allegro.h>

#include "dynamic.h"
#include "defines.h"
#include "pawns.h"
#include "render.h"

void InitPawn(struct Pawn pawn[])
{
	int PAWNS_POS_W[12] = { 1, 3, 5, 7, 0, 2, 4, 6, 1, 3, 5, 7 }; // wspó³rzêdne x bia³ych
	int PAWNS_POS_B[12] = { 0, 2, 4, 6, 1, 3, 5, 7, 0, 2, 4, 6 }; // wspó³rzêdne x czarnych

	for (int i = 0; i < NUM_PAWNS; ++i)
	{
		if (i < NUM_PAWNS / 2)
		{
			pawn[i].ID = i;

			pawn[i].x = PAWNS_POS_W[i];
			if (i < 4)
				pawn[i].y = 0;
			else
				if (i < 8)
					pawn[i].y = 1;
				else
					pawn[i].y = 2;
			pawn[i].live = true;
			pawn[i].type = false;
		}
		else
		{
			pawn[i].ID = i;

			pawn[i].x = PAWNS_POS_B[i - NUM_PAWNS / 2];
			if (i < 16)
				pawn[i].y = 5;
			else
				if (i < 20)
					pawn[i].y = 6;
				else
					pawn[i].y = 7;
			pawn[i].live = true;
			pawn[i].type = false;
		}
	}
}
void AutoAttack(struct Pawn pawn[], int pawn_id, bool ruch, int direction)
{
	int id_broken;
	switch (direction)
	{
	case 0:
		id_broken = CheckPawn_Cords(pawn[pawn_id].x + 1, pawn[pawn_id].y + 1, pawn);
		pawn[id_broken].live = false;
		pawn[id_broken].x = DEATH;
		pawn[id_broken].y = DEATH;
		pawn[pawn_id].x += 2;
		pawn[pawn_id].y += 2;
		break;
	case 1:
		id_broken = CheckPawn_Cords(pawn[pawn_id].x + 1, pawn[pawn_id].y - 1, pawn);
		pawn[id_broken].live = false;
		pawn[id_broken].x = DEATH;
		pawn[id_broken].y = DEATH;
		pawn[pawn_id].x += 2;
		pawn[pawn_id].y -= 2;
		break;
	case 2:
		id_broken = CheckPawn_Cords(pawn[pawn_id].x - 1, pawn[pawn_id].y - 1, pawn);
		pawn[id_broken].live = false;
		pawn[id_broken].x = DEATH;
		pawn[id_broken].y = DEATH;
		pawn[pawn_id].x -= 2;
		pawn[pawn_id].y -= 2;
		break;
	case 3:
		id_broken = CheckPawn_Cords(pawn[pawn_id].x - 1, pawn[pawn_id].y + 1, pawn);
		pawn[id_broken].live = false;
		pawn[id_broken].x = DEATH;
		pawn[id_broken].y = DEATH;
		pawn[pawn_id].x -= 2;
		pawn[pawn_id].y += 2;
		break;
	}
}
void isQueen(struct Pawn pawn[], int id)
{
	if (id < NUM_PAWNS / 2 && id>=0)
	{
		if (pawn[id].y == 7)
			pawn[id].type = true;
	}
	else
		if (pawn[id].y == 0)
			pawn[id].type = true;

}
void TakeMouse(int tab_pos[])
{
	ALLEGRO_EVENT_QUEUE *event_queu = NULL;
	event_queu = al_create_event_queue();
	int x, y;

	al_register_event_source(event_queu, al_get_mouse_event_source());
	while (true)
	{
		ALLEGRO_EVENT eve;
		al_wait_for_event(event_queu, &eve);
		if (eve.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (eve.mouse.button & 1)
			{
				x = eve.mouse.x;
				y = eve.mouse.y;
				break;
			}
		}
	}
	tab_pos[0] = x;
	tab_pos[1] = y;
	al_destroy_event_queue(event_queu);
}

int MovePawn(int mouse_pos_x, int mouse_pos_y, bool ruch, int pawn_id, struct Pawn pawn[])
{
	int piip = CheckPawn_Pos(mouse_pos_x, mouse_pos_y, pawn, ruch); // piip -> pawn_id_in_position
	if (piip == pawn_id)
		return 2;
	int x = ConvertCords_X(mouse_pos_x, mouse_pos_y);
	int y = ConvertCords_Y(mouse_pos_x, mouse_pos_y);
	if (piip == -1)
	{
		if (!pawn[pawn_id].type)
			return MovePawn_Normal(x, y, ruch, pawn_id, pawn);
		else
			return MovePawn_Queen(x, y, ruch, pawn_id, pawn);
	}
	else
		return 0;
}
int MovePawn_Normal(int x, int y, bool ruch, int pawn_id, struct Pawn pawn[])
{
	if (!ruch)
	{ // RUCH BIALYCH
		if (pawn[pawn_id].y + 1 == y && (pawn[pawn_id].x + 1 == x || pawn[pawn_id].x - 1 == x))
		{ // przesuwanie siê o jedno pole po przek¹tnej
			pawn[pawn_id].x = x;
			pawn[pawn_id].y = y;
			return 1;
		}
		else
		{  // bledny ruch
			return 0;
		}
	}
	else
	{ // RUCH CZARNYCH
		if (pawn[pawn_id].y - 1 == y && (pawn[pawn_id].x + 1 == x || pawn[pawn_id].x - 1 == x))
		{ // przesuwanie siê o jedno pole po przek¹tnej
			pawn[pawn_id].x = x;
			pawn[pawn_id].y = y;
			return 1;
		}
		else
		{  // bledny ruch
			return 0;
		}
	}
}
int MovePawn_Queen(int x, int y, bool ruch, int pawn_id, struct Pawn pawn[])
{
	if (ABS_MOVE(x, y, pawn_id, pawn))
	{
		pawn[pawn_id].x = x;
		pawn[pawn_id].y = y;
		return 1;
	}
	else
		return 0;
}

bool ABS_MOVE(int x, int y, int pawn_id, struct Pawn pawn[])
{ // w for'ach i=1, poniewaz pozycja docelowa jest juz sprawdzona w w MovePawn(...)
	bool Check = false;
	if (x > MAP_SIZE - 1 || y > MAP_SIZE - 1 || x < 0 || y < 0)
		return Check;
	int AttackCheck = 0;
	int ex, ey; // enemy x, enemy y
	int px = pawn[pawn_id].x; // pawn x
	int py = pawn[pawn_id].y; // pawn y
	int enemy_id;
	int distance = abs(px - x);
	if (distance == abs(py - y))
	{
		if (x > px && y > py)
		{
			for (int i = 1; i < distance; ++i)
			{
				Check = CheckPos(px + i, py + i, pawn);
				if (!Check)
				{
					AttackCheck++;
					ex = px + i;
					ey = py + i;
				}
			}
			if (distance == 1)
				Check = CheckPos(x, y, pawn);
		}
		else
			if (x > px && y < py)
			{
				for (int i = 1; i < distance; ++i)
				{
					Check = CheckPos(px + i, py - i, pawn);
					if (!Check)
					{
						AttackCheck++;
						ex = px + i;
						ey = py - i;
					}
				}
				if (distance == 1)
					Check = CheckPos(x, y, pawn);
			}
			else
				if (x < px && y < py)
				{
					for (int i = 1; i < distance; ++i)
					{
						Check = CheckPos(px - i, py - i, pawn);
						if (!Check)
						{
							AttackCheck++;
							ex = px - i;
							ey = py - i;
						}
					}
					if (distance == 1)
						Check = CheckPos(x, y, pawn);
				}
				else
				{
					for (int i = 1; i < distance; ++i)
					{
						Check = CheckPos(px - i, py + i, pawn);
						if (!Check)
						{
							AttackCheck++;
							ex = px - i;
							ey = py + i;
						}
					}
					if (distance == 1)
						Check = CheckPos(x, y, pawn);
				}
	}
	// Je¿eli po drodze ruchu damki znajduje sie jeden pionek, damka go zbija //
	if (AttackCheck == 1)
	{
		enemy_id = CheckPawn_Cords(ex, ey, pawn);
		pawn[enemy_id].live = false;
		pawn[enemy_id].x = DEATH;
		pawn[enemy_id].y = DEATH;
		Check = true;
	}
	return Check;
}
bool CheckPos(int x, int y, struct Pawn pawn[])
{
	for (int i = 0; i < NUM_PAWNS; ++i)
		if (pawn[i].x == x && pawn[i].y == y)
			return false;
	return true;
}

bool isEnd_W(struct Pawn pawn[])
{
	for (int i = 0; i < NUM_PAWNS / 2; ++i)
	{
		if (pawn[i].live == true)
			return false;
		if (i == (NUM_PAWNS / 2) - 1)
			return true;
	}
	return true;
}
bool isEnd_B(struct Pawn pawn[])
{
	for (int i = NUM_PAWNS / 2; i < NUM_PAWNS; ++i)
	{
		if (pawn[i].live == true)
			return false;
		if (i == NUM_PAWNS - 1)
			return true;
	}
	return true;
}

int CheckPawn_Pos(int mouse_pos_x, int mouse_pos_y, struct Pawn pawn[], bool ruch)
{
	if (mouse_pos_x > CORRECTION && mouse_pos_x < SIZE + CORRECTION && mouse_pos_y > CORRECTION && mouse_pos_y < SIZE + CORRECTION)
	{
		if (!ruch)
		{ // ruch bia³ych
			for (int i = 0; i < NUM_PAWNS / 2; ++i)
			{
				if (mouse_pos_x > pawn[i].x*BOX_SIZE + CORRECTION && mouse_pos_x < pawn[i].x*BOX_SIZE + BOX_SIZE + CORRECTION &&
					mouse_pos_y > pawn[i].y*BOX_SIZE + CORRECTION && mouse_pos_y < pawn[i].y*BOX_SIZE + BOX_SIZE + CORRECTION)
					return i;
			}
		}
		else
		{ // ruch czarnych
			for (int i = NUM_PAWNS / 2; i < NUM_PAWNS; ++i)
			{
				if (mouse_pos_x > pawn[i].x*BOX_SIZE + CORRECTION && mouse_pos_x < pawn[i].x*BOX_SIZE + BOX_SIZE + CORRECTION &&
					mouse_pos_y > pawn[i].y*BOX_SIZE + CORRECTION && mouse_pos_y < pawn[i].y*BOX_SIZE + BOX_SIZE + CORRECTION)
					return i;
			}
		}
		return -1;
	}
	else
		return -2;
}
int CheckPawn_Cords(int x, int y, struct Pawn pawn[])
{
	for (int i = 0; i < NUM_PAWNS; ++i)
		if (pawn[i].x == x && pawn[i].y == y)
			return pawn[i].ID;
	if (x > 7 || y > 7 || x < 0 || y < 0)
	{
		return -2;
	}
	return -1;
}
int Choose(bool ruch, struct Pawn pawn[], int choosepawn[])
{
	bool isGood = false;
	int tab_xy[2];
	int x, y;
	int take_id; // id wybrane myszka
	while (!isGood)
	{
		TakeMouse(tab_xy);
		x = tab_xy[0];
		y = tab_xy[1];
		take_id = CheckPawn_Pos(x, y, pawn, ruch);
		for (int i = 0; i < NUM_PAWNS / 2; ++i)
			if (choosepawn[i] == take_id)
				isGood = true;
		if (take_id == -1)
			isGood = false;
	}
	return take_id;
}

int CheckBattle(bool ruch, struct Pawn pawn[], struct MainRoute **root_W, struct MainRoute **root_B, int choosepawn[])
{
	int pawn_points[NUM_PAWNS / 2] = { 0 }; // przechowuje liczbê biæ dla ka¿dego pionka
	int max = 0;
	int counter = 0;
	int SE = 0, NE = 0, NW = 0, SW = 0; // zliczone bicia w danym "glownym" kierunku
	int id_max = -1;
	int licznik = 0; // licznik do choosenpawn[]

	for (int h = 0; h < NUM_PAWNS / 2; h++)
		choosepawn[h] = -1;
	if (!ruch)
	{
		for (int i = 0; i < NUM_PAWNS / 2; ++i)
		{ // sprawdzenie dla bia³ych
			if (pawn[i].live)
			{
				for (int j = NUM_PAWNS / 2; j < NUM_PAWNS; ++j)
				{
					if (pawn[j].live)
					{
						if ((pawn[i].x + 1 == pawn[j].x && pawn[i].y + 1 == pawn[j].y) && CheckPawn_Cords(pawn[i].x + 2, pawn[i].y + 2, pawn) == -1)
						{ // x++ y++
							SE = ExtendedCheckBattle(ruch, pawn, i, 0, pawn[i].x, pawn[i].y, root_W, root_B, &counter) + 1;
							if (pawn_points[i] < SE)
								pawn_points[i] = SE;
						}
						if ((pawn[i].x + 1 == pawn[j].x && pawn[i].y - 1 == pawn[j].y) && CheckPawn_Cords(pawn[i].x + 2, pawn[i].y - 2, pawn) == -1)
						{ // x++ y--
							NE = ExtendedCheckBattle(ruch, pawn, i, 1, pawn[i].x, pawn[i].y, root_W, root_B, &counter) + 1;
							if (pawn_points[i] < NE)
								pawn_points[i] = NE;
						}
						if ((pawn[i].x - 1 == pawn[j].x && pawn[i].y - 1 == pawn[j].y) && CheckPawn_Cords(pawn[i].x - 2, pawn[i].y - 2, pawn) == -1)
						{ // x-- y--
							NW = ExtendedCheckBattle(ruch, pawn, i, 2, pawn[i].x, pawn[i].y, root_W, root_B, &counter) + 1;
							if (pawn_points[i] < NW)
								pawn_points[i] = NW;
						}
						if ((pawn[i].x - 1 == pawn[j].x && pawn[i].y + 1 == pawn[j].y) && CheckPawn_Cords(pawn[i].x - 2, pawn[i].y + 2, pawn) == -1)
						{ // x-- y++
							SW = ExtendedCheckBattle(ruch, pawn, i, 3, pawn[i].x, pawn[i].y, root_W, root_B, &counter) + 1;
							if (pawn_points[i] < SW)
								pawn_points[i] = SW;
						}
					}
				}
			}
		}
		for (int k = 0; k < NUM_PAWNS / 2; ++k)
			if (pawn_points[k] > max)
			{
				max = pawn_points[k];
				id_max = k;
			}
		// Do wyboru pionka, jezeli 2 lub wiecej pionkow ma tyle samo bic //
		for (int u = 0; u < NUM_PAWNS / 2; ++u)
		{
			if (pawn_points[u] == max)
			{
				choosepawn[licznik] = u;
				licznik++;
			}
		}
		return id_max;
	}
	else
	{
		for (int i = NUM_PAWNS / 2; i < NUM_PAWNS; ++i)
		{ // sprawdzenie dla czarnych
			if (pawn[i].live)
			{
				for (int j = 0; j < NUM_PAWNS / 2; ++j)
				{
					if (pawn[j].live)
					{
						if ((pawn[i].x + 1 == pawn[j].x && pawn[i].y + 1 == pawn[j].y) && CheckPawn_Cords(pawn[i].x + 2, pawn[i].y + 2, pawn) == -1)
						{
							SE = ExtendedCheckBattle(ruch, pawn, i, 0, pawn[i].x, pawn[i].y, root_W, root_B, &counter) + 1;
							if (pawn_points[i - NUM_PAWNS / 2] < SE)
								pawn_points[i - NUM_PAWNS / 2] = SE;
						}
						if ((pawn[i].x + 1 == pawn[j].x && pawn[i].y - 1 == pawn[j].y) && CheckPawn_Cords(pawn[i].x + 2, pawn[i].y - 2, pawn) == -1)
						{
							NE = ExtendedCheckBattle(ruch, pawn, i, 1, pawn[i].x, pawn[i].y, root_W, root_B, &counter) + 1;
							if (pawn_points[i - NUM_PAWNS / 2] < NE)
								pawn_points[i - NUM_PAWNS / 2] = NE;
						}
						if ((pawn[i].x - 1 == pawn[j].x && pawn[i].y - 1 == pawn[j].y) && CheckPawn_Cords(pawn[i].x - 2, pawn[i].y - 2, pawn) == -1)
						{
							NW = ExtendedCheckBattle(ruch, pawn, i, 2, pawn[i].x, pawn[i].y, root_W, root_B, &counter) + 1;
							if (pawn_points[i - NUM_PAWNS / 2] < NW)
								pawn_points[i - NUM_PAWNS / 2] = NW;
						}
						if ((pawn[i].x - 1 == pawn[j].x && pawn[i].y + 1 == pawn[j].y) && CheckPawn_Cords(pawn[i].x - 2, pawn[i].y + 2, pawn) == -1)
						{
							SW = ExtendedCheckBattle(ruch, pawn, i, 3, pawn[i].x, pawn[i].y, root_W, root_B, &counter) + 1;
							if (pawn_points[i - NUM_PAWNS / 2] < SW)
								pawn_points[i - NUM_PAWNS / 2] = SW;
						}
					}
				}
			}
		}
		for (int k = 0; k < NUM_PAWNS / 2; ++k)
			if (pawn_points[k] > max)
			{
				max = pawn_points[k];
				id_max = k + NUM_PAWNS / 2;
			}
		// Do wyboru pionka, jezeli 2 lub wiecej pionkow ma tyle samo bic //
		for (int u = 0; u < NUM_PAWNS / 2; ++u)
		{
			if (pawn_points[u] == max)
			{
				choosepawn[licznik] = u + NUM_PAWNS / 2;
				licznik++;
			}
		}
		return id_max;
	}
}
int ExtendedCheckBattle(bool ruch, struct Pawn pawn[], int current_id, int direction, int pawn_x, int pawn_y,
	struct MainRoute **head_W, struct MainRoute **head_B, int *counter)
{
	int bufor = 0;
	int count[DIRECTIONS] = { 0 };
	int current_x;
	int current_y;
	struct Route **head = ReturnRouteHeadAddres(current_id, ruch, head_W, head_B);
	add_route(current_id, direction, ruch, head_W, head_B, head);
	switch (direction)
	{
	case 0:
		current_x = pawn_x + 2;
		current_y = pawn_y + 2;
		if (ruch)
		{ // ruch czarnych
			if (((CheckPawn_Cords(current_x + 1, current_y + 1, pawn) > -1) && (CheckPawn_Cords(current_x + 1, current_y + 1, pawn) < 12)) && (CheckPawn_Cords(current_x + 2, current_y + 2, pawn) == -1))
			{ // direction 0
				bufor = CheckMax(current_id, current_x, current_y, 0, ruch, pawn);
				count[0] = bufor;
			}
			if (((CheckPawn_Cords(current_x + 1, current_y - 1, pawn) > -1) && (CheckPawn_Cords(current_x + 1, current_y - 1, pawn) < 12)) && (CheckPawn_Cords(current_x + 2, current_y - 2, pawn) == -1))
			{ // direction 1
				bufor = CheckMax(current_id, current_x, current_y, 1, ruch, pawn);
				count[1] = bufor;
			}
			if (((CheckPawn_Cords(current_x - 1, current_y + 1, pawn) > -1) && (CheckPawn_Cords(current_x - 1, current_y + 1, pawn) < 12)) && (CheckPawn_Cords(current_x - 2, current_y + 2, pawn) == -1))
			{ // direction 3
				bufor = CheckMax(current_id, current_x, current_y, 3, ruch, pawn);
				count[2] = bufor;
			}
			switch (TableIndexMax(count, DIRECTIONS))
			{
			case 0:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 0, current_x, current_y, head_W, head_B, counter);
				break;
			case 1:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 1, current_x, current_y, head_W, head_B, counter);
				break;
			case 2:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 3, current_x, current_y, head_W, head_B, counter);
				break;
			case -1:
				break;
			}
		}
		else
		{ // ruch bialych
			if ((CheckPawn_Cords(current_x + 1, current_y + 1, pawn) > 11) && (CheckPawn_Cords(current_x + 2, current_y + 2, pawn) == -1))
			{ // direction 0
				bufor = CheckMax(current_id, current_x, current_y, 0, ruch, pawn);
				count[0] = bufor;
			}
			if ((CheckPawn_Cords(current_x + 1, current_y - 1, pawn) > 11) && (CheckPawn_Cords(current_x + 2, current_y - 2, pawn) == -1))
			{ // direction 1
				bufor = CheckMax(current_id, current_x, current_y, 1, ruch, pawn);
				count[1] = bufor;
			}
			if ((CheckPawn_Cords(current_x - 1, current_y + 1, pawn) > 11) && (CheckPawn_Cords(current_x - 2, current_y + 2, pawn) == -1))
			{ // direction 3
				bufor = CheckMax(current_id, current_x, current_y, 3, ruch, pawn);
				count[2] = bufor;
			}
			switch (TableIndexMax(count, DIRECTIONS))
			{
			case 0:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 0, current_x, current_y, head_W, head_B, counter);
				break;
			case 1:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 1, current_x, current_y, head_W, head_B, counter);
				break;
			case 2:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 3, current_x, current_y, head_W, head_B, counter);
				break;
			case -1:
				break;
			}
		}
		break;
	case 1:
		current_x = pawn_x + 2;
		current_y = pawn_y - 2;
		if (ruch)
		{ // ruch czarnych
			if (((CheckPawn_Cords(current_x + 1, current_y + 1, pawn) > -1) && (CheckPawn_Cords(current_x + 1, current_y + 1, pawn) < 12)) && (CheckPawn_Cords(current_x + 2, current_y + 2, pawn) == -1))
			{ // direction 0
				bufor = CheckMax(current_id, current_x, current_y, 0, ruch, pawn);
				count[0] = bufor;
			}
			if (((CheckPawn_Cords(current_x + 1, current_y - 1, pawn) > -1) && (CheckPawn_Cords(current_x + 1, current_y - 1, pawn) < 12)) && (CheckPawn_Cords(current_x + 2, current_y - 2, pawn) == -1))
			{ // direction 1
				bufor = CheckMax(current_id, current_x, current_y, 1, ruch, pawn);
				count[1] = bufor;
			}
			if (((CheckPawn_Cords(current_x - 1, current_y - 1, pawn) > -1) && (CheckPawn_Cords(current_x - 1, current_y - 1, pawn) < 12)) && (CheckPawn_Cords(current_x - 2, current_y - 2, pawn) == -1))
			{ // direction 2
				bufor = CheckMax(current_id, current_x, current_y, 2, ruch, pawn);
				count[2] = bufor;
			}
			switch (TableIndexMax(count, DIRECTIONS))
			{
			case 0:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 0, current_x, current_y, head_W, head_B, counter);
				break;
			case 1:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 1, current_x, current_y, head_W, head_B, counter);
				break;
			case 2:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 2, current_x, current_y, head_W, head_B, counter);
				break;
			case -1:
				break;
			}
		}
		else
		{ // ruch bialych
			if ((CheckPawn_Cords(current_x + 1, current_y + 1, pawn) > 11) && (CheckPawn_Cords(current_x + 2, current_y + 2, pawn) == -1))
			{ // direction 0
				bufor = CheckMax(current_id, current_x, current_y, 0, ruch, pawn);
				count[0] = bufor;
			}
			if ((CheckPawn_Cords(current_x + 1, current_y - 1, pawn) > 11) && (CheckPawn_Cords(current_x + 2, current_y - 2, pawn) == -1))
			{ // direction 1
				bufor = CheckMax(current_id, current_x, current_y, 1, ruch, pawn);
				count[1] = bufor;
			}
			if ((CheckPawn_Cords(current_x - 1, current_y - 1, pawn) > 11) && (CheckPawn_Cords(current_x - 2, current_y - 2, pawn) == -1))
			{ // direction 2
				bufor = CheckMax(current_id, current_x, current_y, 2, ruch, pawn);
				count[2] = bufor;
			}
			switch (TableIndexMax(count, DIRECTIONS))
			{
			case 0:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 0, current_x, current_y, head_W, head_B, counter);
				break;
			case 1:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 1, current_x, current_y, head_W, head_B, counter);
				break;
			case 2:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 2, current_x, current_y, head_W, head_B, counter);
				break;
			case -1:
				break;
			}
		}
		break;
	case 2:
		current_x = pawn_x - 2;
		current_y = pawn_y - 2;
		if (ruch)
		{
			if (((CheckPawn_Cords(current_x + 1, current_y - 1, pawn) > -1) && (CheckPawn_Cords(current_x + 1, current_y - 1, pawn) < 12)) && (CheckPawn_Cords(current_x + 2, current_y - 2, pawn) == -1))
			{ // direction 1
				bufor = CheckMax(current_id, current_x, current_y, 1, ruch, pawn);
				count[0] = bufor;
			}
			if (((CheckPawn_Cords(current_x - 1, current_y - 1, pawn) > -1) && (CheckPawn_Cords(current_x - 1, current_y - 1, pawn) < 12)) && (CheckPawn_Cords(current_x - 2, current_y - 2, pawn) == -1))
			{ // direction 2
				bufor = CheckMax(current_id, current_x, current_y, 2, ruch, pawn);
				count[1] = bufor;
			}
			if (((CheckPawn_Cords(current_x - 1, current_y + 1, pawn) > -1) && (CheckPawn_Cords(current_x - 1, current_y + 1, pawn) < 12)) && (CheckPawn_Cords(current_x - 2, current_y + 2, pawn) == -1))
			{ // direction 3
				bufor = CheckMax(current_id, current_x, current_y, 3, ruch, pawn);
				count[2] = bufor;
			}
			switch (TableIndexMax(count, DIRECTIONS))
			{
			case 0:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 1, current_x, current_y, head_W, head_B, counter);
				break;
			case 1:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 2, current_x, current_y, head_W, head_B, counter);
				break;
			case 2:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 3, current_x, current_y, head_W, head_B, counter);
				break;
			case -1:
				break;
			}
		}
		else
		{
			if ((CheckPawn_Cords(current_x + 1, current_y - 1, pawn) > 11) && (CheckPawn_Cords(current_x + 2, current_y - 2, pawn) == -1))
			{ // direction 1
				bufor = CheckMax(current_id, current_x, current_y, 1, ruch, pawn);
				count[0] = bufor;
			}
			if ((CheckPawn_Cords(current_x - 1, current_y - 1, pawn) > 11) && (CheckPawn_Cords(current_x - 2, current_y - 2, pawn) == -1))
			{ // direction 2
				bufor = CheckMax(current_id, current_x, current_y, 2, ruch, pawn);
				count[1] = bufor;
			}
			if ((CheckPawn_Cords(current_x - 1, current_y + 1, pawn) > 11) && (CheckPawn_Cords(current_x - 2, current_y + 2, pawn) == -1))
			{ // direction 3
				bufor = CheckMax(current_id, current_x, current_y, 3, ruch, pawn);
				count[2] = bufor;
			}
			switch (TableIndexMax(count, DIRECTIONS))
			{
			case 0:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 1, current_x, current_y, head_W, head_B, counter);
				break;
			case 1:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 2, current_x, current_y, head_W, head_B, counter);
				break;
			case 2:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 3, current_x, current_y, head_W, head_B, counter);
				break;
			case -1:
				break;
			}
		}
		break;
	case 3:
		current_x = pawn_x - 2;
		current_y = pawn_y + 2;
		if (ruch)
		{
			if (((CheckPawn_Cords(current_x + 1, current_y + 1, pawn) > -1) && (CheckPawn_Cords(current_x + 1, current_y + 1, pawn) < 12)) && (CheckPawn_Cords(current_x + 2, current_y + 2, pawn) == -1))
			{ // direction 0
				bufor = CheckMax(current_id, current_x, current_y, 0, ruch, pawn);
				count[0] = bufor;
			}
			if (((CheckPawn_Cords(current_x - 1, current_y - 1, pawn) > -1) && (CheckPawn_Cords(current_x - 1, current_y - 1, pawn) < 12)) && (CheckPawn_Cords(current_x - 2, current_y - 2, pawn) == -1))
			{ // direction 2
				bufor = CheckMax(current_id, current_x, current_y, 2, ruch, pawn);
				count[1] = bufor;
			}
			if (((CheckPawn_Cords(current_x - 1, current_y + 1, pawn) > -1) && (CheckPawn_Cords(current_x - 1, current_y + 1, pawn) < 12)) && (CheckPawn_Cords(current_x - 2, current_y + 2, pawn) == -1))
			{ // direction 3
				bufor = CheckMax(current_id, current_x, current_y, 3, ruch, pawn);
				count[2] = bufor;
			}
			switch (TableIndexMax(count, DIRECTIONS))
			{
			case 0:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 0, current_x, current_y, head_W, head_B, counter);
				break;
			case 1:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 2, current_x, current_y, head_W, head_B, counter);
				break;
			case 2:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 3, current_x, current_y, head_W, head_B, counter);
				break;
			case -1:
				break;
			}
		}
		else
		{
			if ((CheckPawn_Cords(current_x + 1, current_y + 1, pawn) > 11) && (CheckPawn_Cords(current_x + 2, current_y + 2, pawn) == -1))
			{ // direction 0
				bufor = CheckMax(current_id, current_x, current_y, 1, ruch, pawn);
				count[0] = bufor;
			}
			if ((CheckPawn_Cords(current_x - 1, current_y - 1, pawn) > 11) && (CheckPawn_Cords(current_x - 2, current_y - 2, pawn) == -1))
			{ // direction 2
				bufor = CheckMax(current_id, current_x, current_y, 2, ruch, pawn);
				count[1] = bufor;
			}
			if ((CheckPawn_Cords(current_x - 1, current_y + 1, pawn) > 11) && (CheckPawn_Cords(current_x - 2, current_y + 2, pawn) == -1))
			{ // direction 3
				bufor = CheckMax(current_id, current_x, current_y, 3, ruch, pawn);
				count[2] = bufor;
			}
			switch (TableIndexMax(count, DIRECTIONS))
			{
			case 0:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 0, current_x, current_y, head_W, head_B, counter);
				break;
			case 1:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 2, current_x, current_y, head_W, head_B, counter);
				break;
			case 2:
				(*counter)++;
				ExtendedCheckBattle(ruch, pawn, current_id, 3, current_x, current_y, head_W, head_B, counter);
				break;
			case -1:
				break;
			}
		}
		break;
	}
	return (*counter);
}
int CheckMax(int current_id, int x, int y, int last_direction, bool ruch, struct Pawn pawn[])
{
	int num_move = 0;
	int bufor;
	if (!ruch)
	{ // sprawdzenie bialych
		if (x + 2 < MAP_SIZE && y + 2 < MAP_SIZE && CheckPawn_Cords(x + 1, y + 1, pawn) > 11 && CheckPawn_Cords(x + 2, y + 2, pawn) == -1 && last_direction != 2)
		{ // direction 0
			bufor = CheckMax(current_id, x + 2, y + 2, 0, ruch, pawn) + 1;
			if (bufor > num_move)
				num_move = bufor;
		}
		if (x + 2 < MAP_SIZE && y - 2 >= 0 && CheckPawn_Cords(x + 1, y - 1, pawn) > 11 && CheckPawn_Cords(x + 2, y - 2, pawn) == -1 && last_direction != 3)
		{ // direction 1
			bufor = CheckMax(current_id, x + 2, y - 2, 1, ruch, pawn) + 1;
			if (bufor > num_move)
				num_move = bufor;
		}
		if (x - 2 >= 0 && y - 2 >= 0 && CheckPawn_Cords(x - 1, y - 1, pawn) > 11 && CheckPawn_Cords(x - 2, y - 2, pawn) == -1 && last_direction != 0)
		{ // direction 2
			bufor = CheckMax(current_id, x - 2, y - 2, 2, ruch, pawn) + 1;
			if (bufor > num_move)
				num_move = bufor;
		}
		if (x - 2 >= 0 && y + 2 < MAP_SIZE && CheckPawn_Cords(x - 1, y + 1, pawn) > 11 && CheckPawn_Cords(x - 2, y + 2, pawn) == -1 && last_direction != 1)
		{ // direction 3
			bufor = CheckMax(current_id, x - 2, y + 2, 3, ruch, pawn) + 1;
			if (bufor > num_move)
				num_move = bufor;
		}
		return num_move;
	}
	else
	{ // sprawdzanie czarnych
		if (x + 2 < MAP_SIZE && y + 2 < MAP_SIZE && CheckPawn_Cords(x + 1, y + 1, pawn) > -1 && CheckPawn_Cords(x + 1, y + 1, pawn) < 12 && CheckPawn_Cords(x + 2, y + 2, pawn) == -1 && last_direction != 2)
		{
			bufor = CheckMax(current_id, x + 2, y + 2, 0, ruch, pawn) + 1;
			if (bufor > num_move)
				num_move = bufor;
		}
		if (x + 2 < MAP_SIZE && y - 2 >= 0 && CheckPawn_Cords(x + 1, y - 1, pawn) > -1 && CheckPawn_Cords(x + 1, y - 1, pawn) < 12 && CheckPawn_Cords(x + 2, y - 2, pawn) == -1 && last_direction != 3)
		{
			bufor = CheckMax(current_id, x + 2, y - 2, 1, ruch, pawn) + 1;
			if (bufor > num_move)
				num_move = bufor;
		}
		if (x - 2 >= 0 && y - 2 >= 0 && CheckPawn_Cords(x - 1, y - 1, pawn) > -1 && CheckPawn_Cords(x - 1, y - 1, pawn) < 12 && CheckPawn_Cords(x - 2, y - 2, pawn) == -1 && last_direction != 0)
		{
			bufor = CheckMax(current_id, x - 2, y - 2, 2, ruch, pawn) + 1;
			if (bufor > num_move)
				num_move = bufor;
		}
		if (x - 2 >= 0 && y + 2 < MAP_SIZE && CheckPawn_Cords(x - 1, y + 1, pawn) > -1 && CheckPawn_Cords(x - 1, y + 1, pawn) < 12 && CheckPawn_Cords(x - 2, y + 2, pawn) == -1 && last_direction != 1)
		{
			bufor = CheckMax(current_id, x - 2, y + 2, 3, ruch, pawn) + 1;
			if (bufor > num_move)
				num_move = bufor;
		}
		return num_move;
	}

}
int TableIndexMax(int tab[], int end)
{
	int max = tab[0];
	int index = 0;
	if (end == 3)
		if ((tab[0] == 0) && (tab[1] == 0) && (tab[2] == 0))
			return -1;
	for (int i = 0; i < end - 1; ++i)
	{
		if (max < tab[i + 1])
		{
			max = tab[i + 1];
			index = i + 1;
		}
	}
	return index;
}
int NextDirection(int count, bool ruch, int pawn_id, struct MainRoute **root_W, struct MainRoute **root_B)
{
	struct Route *bufor = *(ReturnRouteHeadAddres(pawn_id, ruch, root_W, root_B));
	int count_internal = 0;
	while ((bufor) && count_internal != count)
	{
		bufor = bufor->next;
		count_internal++;
	}
	if (bufor)
		return bufor->direction;
	else
		return -1;
}
int DirectionsNumbers(int id, bool ruch, struct MainRoute **root_W, struct MainRoute **root_B)
{
	int counter = 0;
	struct Route **bufor = ReturnRouteHeadAddres(id, ruch, root_W, root_B);
	while ((*bufor))
	{
		counter++;
		bufor = &((*bufor)->next);
	}
	return counter;
}


void SI_Move_Pawn(bool ruch, int id, struct Pawn pawn[])
{
	if (pawn[id].type == 0)
		SI_Move_Normal_Pawn(ruch, id, pawn);
	else
		SI_Move_Queen_Pawn(ruch, id, pawn);
}
void SI_Move_Normal_Pawn(bool ruch, int id, struct Pawn pawn[])
{
	srand(time(NULL));
	int dir = rand() % 100;
	if (!ruch)
	{ // biale
		if (dir > 50)
		{
			if (CheckPawn_Cords(pawn[id].x - 1, pawn[id].y + 1, pawn) == -1)
			{
				pawn[id].x -= 1;
				pawn[id].y += 1;
			}
			else
				if (CheckPawn_Cords(pawn[id].x + 1, pawn[id].y + 1, pawn) == -1)
				{
					pawn[id].x += 1;
					pawn[id].y += 1;
				}
		}
		else
		{
			if (CheckPawn_Cords(pawn[id].x + 1, pawn[id].y + 1, pawn) == -1)
			{
				pawn[id].x += 1;
				pawn[id].y += 1;
			}
			else
				if (CheckPawn_Cords(pawn[id].x - 1, pawn[id].y + 1, pawn) == -1)
				{
					pawn[id].x -= 1;
					pawn[id].y += 1;
				}
		}
	}
	else
	{ // czarne
		if (dir > 50)
		{
			if (CheckPawn_Cords(pawn[id].x - 1, pawn[id].y - 1, pawn) == -1)
			{
				pawn[id].x -= 1;
				pawn[id].y -= 1;
			}
			else
				if (CheckPawn_Cords(pawn[id].x + 1, pawn[id].y - 1, pawn) == -1)
				{
					pawn[id].x += 1;
					pawn[id].y -= 1;
				}
		}
		else
		{
			if (CheckPawn_Cords(pawn[id].x + 1, pawn[id].y - 1, pawn) == -1)
			{
				pawn[id].x += 1;
				pawn[id].y -= 1;
			}
			else
				if (CheckPawn_Cords(pawn[id].x - 1, pawn[id].y - 1, pawn) == -1)
				{
					pawn[id].x -= 1;
					pawn[id].y -= 1;
				}
		}
	}
}
void SI_Move_Queen_Pawn(bool ruch, int id, struct Pawn pawn[])
{
	bool isDone = false;
	srand(time(NULL));
	int dir;
	int distance;
	while (!isDone)
	{
		dir = rand() % 4;
		distance = rand() % 6;
		switch (dir)
		{
		case 0:
			if (MovePawn_Queen(pawn[id].x + distance, pawn[id].y + distance, ruch, id, pawn) == 1 && CheckPawn_Cords(pawn[id].x + distance, pawn[id].y + distance, pawn) == -1)
			{
				//pawn[id].x += distance;
				//pawn[id].y += distance;
				isDone = true;
			}
			break;
		case 1:
			if (MovePawn_Queen(pawn[id].x + distance, pawn[id].y - distance, ruch, id, pawn) == 1 && CheckPawn_Cords(pawn[id].x + distance, pawn[id].y - distance, pawn) == -1)
			{
				//pawn[id].x += distance;
				//pawn[id].y -= distance;
				isDone = true;
			}
			break;
		case 2:
			if (MovePawn_Queen(pawn[id].x - distance, pawn[id].y - distance, ruch, id, pawn) == 1 && CheckPawn_Cords(pawn[id].x - distance, pawn[id].y - distance, pawn) == -1)
			{
				//pawn[id].x -= distance;
				//pawn[id].y -= distance;
				isDone = true;
			}
			break;
		case 3:
			if (MovePawn_Queen(pawn[id].x - distance, pawn[id].y + distance, ruch, id, pawn) == 1 && CheckPawn_Cords(pawn[id].x - distance, pawn[id].y + distance, pawn) == -1)
			{
				//pawn[id].x -= distance;
				//pawn[id].y += distance;
				isDone = true;
			}
			break;
		}
	}
}

bool SI_Possible_Move(int id, struct Pawn pawn[])
{
	if (id < NUM_PAWNS / 2)
	{
		if (pawn[id].type == 0)
			if (CheckPawn_Cords(pawn[id].x - 1, pawn[id].y + 1, pawn) == -1 || CheckPawn_Cords(pawn[id].x + 1, pawn[id].y + 1, pawn) == -1)
				return true;
			else
				return false;
		else
			return true;
	}
	else
	{
		if (pawn[id].type == 0)
			if (CheckPawn_Cords(pawn[id].x - 1, pawn[id].y - 1, pawn) == -1 || CheckPawn_Cords(pawn[id].x + 1, pawn[id].y - 1, pawn) == -1)
				return true;
			else
				return false;
		else
			return true;
	}
}

int SI_Choose_Pawn(bool ruch, struct Pawn pawn[])
{
	int id;
	srand(time(NULL));
	while (true)
	{
		id = rand() % (NUM_PAWNS / 2);
		if (!ruch)
		{ // ruch komputera bialymi
			if (pawn[id].live && SI_Possible_Move(id, pawn))
				return id;
		}
		else
		{ // ruch komputera czarnymi
			id = id + NUM_PAWNS / 2;
			if (pawn[id].live && SI_Possible_Move(id, pawn))
				return id;
		}
	}
}