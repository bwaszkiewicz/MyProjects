#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

#include "defines.h"
#include "render.h"
#include "pawns.h"
#include "dynamic.h"
#include "menu.h"

int gameloop1(struct ALLEGRO_DISPLAY* display)
{
	// Zmienne Allegro
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_FONT *font18 = al_load_font("comic.ttf", 18, 0);

	// Bitmapy 
	ALLEGRO_BITMAP *background = al_create_bitmap(SIZE, SIZE);
	ALLEGRO_BITMAP *image_white = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_black = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_checked_white = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_checked_black = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_queen_white = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_queen_black = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_checked_queen_white = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_checked_queen_black = al_create_bitmap(BOX_SIZE, BOX_SIZE);

	// Zmienne
	bool isReady = false;
	bool ruch = false; // false - ruch bia³ych | true - ruch czarnych
	bool render = false; // sterowanie renderem
	bool priorityrender = true;
	int pos_x; // wspolrzedne kursora (x)
	int pos_y; // wspolrzedne kursora (y)
	int correct_pawn; // ID aktualnego pionka do ruchu
	int correct_pawn_attack; // ID akualnego pionka, ktory bije
	int direction; // kierunek kolejnego bicia
	int count; // licznik ruchów w serii bic
	int maxcount; // docelowa liczba bic
	int ster = 0; // dzieli klikniecia myszka na odznaczenie pionka i zaznaczenie
	int choosepawn[12] = { -1 }; //id pionkow, ktore maja bicie w tym samym momecie

	struct Pawn pawn[NUM_PAWNS];
	struct MainRoute* root_W = NULL;
	struct MainRoute* root_B = NULL;
	// Inicjalizacja // 
	srand(time(NULL));
	if (rand() % 100 > 50)
	{
		ruch = true;
	}
	const bool EnemyColor = !ruch;

	CreateTrees(&root_W, &root_B);
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	InitPawn(pawn);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	draw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
		image_checked_queen_white, image_checked_queen_black, display, pawn);

	// GAMELOOP // 
	while (true)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{ //  Czyszczenie przed wylaczeniem programu //
			al_destroy_event_queue(event_queue);
			al_destroy_bitmap(background);
			al_destroy_bitmap(image_white);
			al_destroy_bitmap(image_black);
			al_destroy_bitmap(image_checked_white);
			al_destroy_bitmap(image_checked_black);
			al_destroy_bitmap(image_queen_white);
			al_destroy_bitmap(image_queen_black);
			al_destroy_bitmap(image_checked_queen_white);
			al_destroy_bitmap(image_checked_queen_black);
			al_destroy_font(font18);
			for (int i = 0; i<NUM_PAWNS; ++i)
				clear_route(i, pawn, &root_W, &root_B);
			ClearTree(&root_W);
			ClearTree(&root_B);
			return -1;
		}
		else
			if ((correct_pawn_attack = CheckBattle(ruch, pawn, &root_W, &root_B, choosepawn)) != -1 && ster == 0)
			{
				if (choosepawn[1] != -1 && ruch != EnemyColor)
				{
					draw_map(background, display);
					redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
						image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn);
					for (int i = 0; i < NUM_PAWNS / 2; ++i)
					{
						if (i != -1)
							draw_choose(choosepawn[i], pawn, image_checked_white, image_checked_black, image_checked_queen_white, image_checked_queen_black);
					}
					draw_game_interface(font18, ruch);
					correct_pawn_attack = Choose(ruch, pawn, choosepawn);
				}
				maxcount = DirectionsNumbers(correct_pawn_attack, ruch, &root_W, &root_B);
				while (!isReady)
				{
					// PETLA BICIA //
					for (count = 0; count < maxcount; ++count)
					{
						direction = NextDirection(count, ruch, correct_pawn_attack, &root_W, &root_B);
						if (direction > -1)
						{
							AutoAttack(pawn, correct_pawn_attack, ruch, direction);
							al_rest(2.0);
							// RENDER PO BICIU //

							draw_map(background, display);
							redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
								image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn_attack);
							draw_game_interface(font18, ruch);
							al_flip_display();
							al_clear_to_color(al_map_rgb(0, 0, 0));
							if (isEnd_W(pawn) || isEnd_B(pawn))
							{
								al_rest(2.0);
								switch (menu(display, ruch, true))
								{
								case 2: // powrot do menu
									al_destroy_event_queue(event_queue);
									al_destroy_bitmap(background);
									al_destroy_bitmap(image_white);
									al_destroy_bitmap(image_black);
									al_destroy_bitmap(image_checked_white);
									al_destroy_bitmap(image_checked_black);
									al_destroy_bitmap(image_queen_white);
									al_destroy_bitmap(image_queen_black);
									al_destroy_bitmap(image_checked_queen_white);
									al_destroy_bitmap(image_checked_queen_black);
									al_destroy_font(font18);
									for (int i = 0; i<NUM_PAWNS; ++i)
										clear_route(i, pawn, &root_W, &root_B);
									ClearTree(&root_W);
									ClearTree(&root_B);
									return 0;
									break;
								case -1: // koniec gry
									al_destroy_event_queue(event_queue);
									al_destroy_bitmap(background);
									al_destroy_bitmap(image_white);
									al_destroy_bitmap(image_black);
									al_destroy_bitmap(image_checked_white);
									al_destroy_bitmap(image_checked_black);
									al_destroy_bitmap(image_queen_white);
									al_destroy_bitmap(image_queen_black);
									al_destroy_bitmap(image_checked_queen_white);
									al_destroy_bitmap(image_checked_queen_black);
									al_destroy_font(font18);
									for (int i = 0; i<NUM_PAWNS; ++i)
										clear_route(i, pawn, &root_W, &root_B);
									ClearTree(&root_W);
									ClearTree(&root_B);
									return -1;
									break;
								}
							}
							// CZYSZCZENIE KOLEJEK BICIA //
							if (count == maxcount - 1)
								for (int i = 0; i<NUM_PAWNS; ++i)
									clear_route(i, pawn, &root_W, &root_B);
						}
						else
						{		// SPRAWDZENIE CZY JAKIS PIONEK NIE STAL SIE DAMKA //
							isQueen(pawn, correct_pawn_attack);
							ruch = !ruch;
							isReady = true;
							maxcount = 0;
							priorityrender = true;
						}
					}
				}
				isReady = false;
			}
			else
			{
				if (ruch == EnemyColor)
				{															// RUCH KOMPUTERA //
					correct_pawn = SI_Choose_Pawn(ruch, pawn);
					SI_Move_Pawn(ruch, correct_pawn, pawn);
					isQueen(pawn, correct_pawn);
					priorityrender = true;
					ruch = !ruch;
				}
				else
				{															// RUCH GRACZA // 
					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
					{		// RUCH BEZ BICIA //
						if (ev.mouse.button & 1)
						{
							pos_x = ev.mouse.x;
							pos_y = ev.mouse.y;
							if (pos_x > G_BUTTON_NEW_GAME_X1 && pos_x < G_BUTTON_NEW_GAME_X2 && pos_y > G_BUTTON_NEW_GAME_Y1 && pos_y < G_BUTTON_NEW_GAME_Y2)
							{
								al_destroy_event_queue(event_queue);
								al_destroy_bitmap(background);
								al_destroy_bitmap(image_white);
								al_destroy_bitmap(image_black);
								al_destroy_bitmap(image_checked_white);
								al_destroy_bitmap(image_checked_black);
								al_destroy_bitmap(image_queen_white);
								al_destroy_bitmap(image_queen_black);
								al_destroy_bitmap(image_checked_queen_white);
								al_destroy_bitmap(image_checked_queen_black);
								al_destroy_font(font18);
								ClearTree(&root_W);
								ClearTree(&root_B);
								return 0;
							}
							if (ster == 0)
							{
								correct_pawn = CheckPawn_Pos(pos_x, pos_y, pawn, ruch);
								draw_map(background, display);
								redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
									image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn);
								draw_game_interface(font18, ruch);
								al_flip_display();
								al_clear_to_color(al_map_rgb(0, 0, 0));
								if (correct_pawn > -1)
								{
									ster = 1;
								}
							}
							else
							{
								switch (MovePawn(pos_x, pos_y, ruch, correct_pawn, pawn))
								{
								case 0: // niepoprawny ruch
									isReady = false;
									break;
								case 1: // poprawny ruch
									isReady = true;
									isQueen(pawn, correct_pawn);
									break;
								case 2: // odznaczenie pionka
									ster = 0;
									correct_pawn = -1;
									draw_map(background, display);
									redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
										image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn);
									draw_game_interface(font18, ruch);
									al_flip_display();
									al_clear_to_color(al_map_rgb(0, 0, 0));
									break;
								}
								if (isReady)
								{
									ruch = !ruch;
									ster = 0;
									isReady = false;
									render = true;
								}
								correct_pawn = -1;
							}
						}
					}
				}
			}
		if (isEnd_W(pawn) || isEnd_B(pawn))
		{
			switch (menu(display, ruch, true))
			{
			case 2: // powrot do menu
				return 0;
				break;
			case -1: // koniec gry
				al_destroy_event_queue(event_queue);
				al_destroy_bitmap(background);
				al_destroy_bitmap(image_white);
				al_destroy_bitmap(image_black);
				al_destroy_bitmap(image_checked_white);
				al_destroy_bitmap(image_checked_black);
				al_destroy_bitmap(image_queen_white);
				al_destroy_bitmap(image_queen_black);
				al_destroy_bitmap(image_checked_queen_white);
				al_destroy_bitmap(image_checked_queen_black);
				al_destroy_font(font18);
				ClearTree(&root_W);
				ClearTree(&root_B);
				return -1;
				break;
			}
		}
		// RENDER //
		if ((render && al_is_event_queue_empty(event_queue)) || priorityrender)
		{
			render = false;
			priorityrender = false;
			draw_map(background, display);
			redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
				image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn);
			draw_game_interface(font18, ruch);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_rest(1.0);
		}
	}

	return 0;
}

int gameloop2(struct ALLEGRO_DISPLAY* display)
{
	// Zmienne Allegro
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_FONT *font18 = al_load_font("comic.ttf", 18, 0);

	// Bitmapy 
	ALLEGRO_BITMAP *background = al_create_bitmap(SIZE, SIZE);
	ALLEGRO_BITMAP *image_white = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_black = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_checked_white = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_checked_black = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_queen_white = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_queen_black = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_checked_queen_white = al_create_bitmap(BOX_SIZE, BOX_SIZE);
	ALLEGRO_BITMAP *image_checked_queen_black = al_create_bitmap(BOX_SIZE, BOX_SIZE);

	// Zmienne
	bool isReady = false;
	bool ruch = false; // false - ruch bia³ych | true - ruch czarnych
	bool render = false; // sterowanie renderem
	bool priorityrender = true;
	int pos_x; // wspolrzedne kursora (x)
	int pos_y; // wspolrzedne kursora (y)
	int correct_pawn; // ID aktualnego pionka do ruchu
	int correct_pawn_attack; // ID akualnego pionka, ktory bije
	int direction; // kierunek kolejnego bicia
	int count; // licznik ruchów w serii bic
	int maxcount; // docelowa liczba bic
	int r_movepawn; // zwrot MovePawn
	int ster = 0; // dzieli klikniecia myszka na odznaczenie pionka i zaznaczenie
	int choosepawn[12] = { -1 }; //id pionkow, ktore maja bicie w tym samym momecie

	struct Pawn pawn[NUM_PAWNS];
	struct MainRoute* root_W = NULL;
	struct MainRoute* root_B = NULL;

	// Inicjalizacja // 
	srand(time(NULL));
	if (rand() % 100 > 50)
	{
		ruch = true;
	}
	CreateTrees(&root_W, &root_B);
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	InitPawn(pawn);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	draw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
		image_checked_queen_white, image_checked_queen_black, display, pawn);

	// GAMELOOP // 
	while (true)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{ //  Czyszczenie przed wylaczeniem programu //
			al_destroy_event_queue(event_queue);
			al_destroy_bitmap(background);
			al_destroy_bitmap(image_white);
			al_destroy_bitmap(image_black);
			al_destroy_bitmap(image_checked_white);
			al_destroy_bitmap(image_checked_black);
			al_destroy_bitmap(image_queen_white);
			al_destroy_bitmap(image_queen_black);
			al_destroy_bitmap(image_checked_queen_white);
			al_destroy_bitmap(image_checked_queen_black);
			al_destroy_font(font18);
			for (int i = 0; i<NUM_PAWNS; ++i)
				clear_route(i, pawn, &root_W, &root_B);
			ClearTree(&root_W);
			ClearTree(&root_B);
			return -1;
		}
		else
			if ((correct_pawn_attack = CheckBattle(ruch, pawn, &root_W, &root_B, choosepawn)) != -1 && ster == 0)
			{
				if (choosepawn[1] != -1)
				{
					draw_map(background, display);
					redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
						image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn);
					for (int i = 0; i < NUM_PAWNS / 2; ++i)
					{
						if (i != -1)
							draw_choose(choosepawn[i], pawn, image_checked_white, image_checked_black, image_checked_queen_white, image_checked_queen_black);
					}
					draw_game_interface(font18, ruch);
					correct_pawn_attack = Choose(ruch, pawn, choosepawn);
				}
				maxcount = DirectionsNumbers(correct_pawn_attack, ruch, &root_W, &root_B);
				while (!isReady)
				{
					// PETLA BICIA //
					for (count = 0; count < maxcount; ++count)
					{
						direction = NextDirection(count, ruch, correct_pawn_attack, &root_W, &root_B);
						if (direction > -1)
						{
							AutoAttack(pawn, correct_pawn_attack, ruch, direction);
							al_rest(2.0);
							// RENDER PO BICIU //

							draw_map(background, display);
							redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
								image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn_attack);
							draw_game_interface(font18, ruch);
							al_flip_display();
							al_clear_to_color(al_map_rgb(0, 0, 0));

							if (isEnd_W(pawn) || isEnd_B(pawn))
							{
								al_rest(2.0);
								switch (menu(display, ruch, true))
								{
								case 2: // powrot do menu
									al_destroy_event_queue(event_queue);
									al_destroy_bitmap(background);
									al_destroy_bitmap(image_white);
									al_destroy_bitmap(image_black);
									al_destroy_bitmap(image_checked_white);
									al_destroy_bitmap(image_checked_black);
									al_destroy_bitmap(image_queen_white);
									al_destroy_bitmap(image_queen_black);
									al_destroy_bitmap(image_checked_queen_white);
									al_destroy_bitmap(image_checked_queen_black);
									al_destroy_font(font18);
									for (int i = 0; i<NUM_PAWNS; ++i)
										clear_route(i, pawn, &root_W, &root_B);
									ClearTree(&root_W);
									ClearTree(&root_B);
									return 0;
									break;
								case -1: // koniec gry
									al_destroy_event_queue(event_queue);
									al_destroy_bitmap(background);
									al_destroy_bitmap(image_white);
									al_destroy_bitmap(image_black);
									al_destroy_bitmap(image_checked_white);
									al_destroy_bitmap(image_checked_black);
									al_destroy_bitmap(image_queen_white);
									al_destroy_bitmap(image_queen_black);
									al_destroy_bitmap(image_checked_queen_white);
									al_destroy_bitmap(image_checked_queen_black);
									al_destroy_font(font18);
									for (int i = 0; i<NUM_PAWNS; ++i)
										clear_route(i, pawn, &root_W, &root_B);
									ClearTree(&root_W);
									ClearTree(&root_B);
									return -1;
									break;
								}
							}
							// CZYSZCZENIE KOLEJEK BICIA //
							if (count == maxcount - 1)
								for (int i = 0; i<NUM_PAWNS; ++i)
									clear_route(i, pawn, &root_W, &root_B);
						}
						else
						{		// SPRAWDZENIE CZY JAKIS PIONEK NIE STAL SIE DAMKA //
							isQueen(pawn, correct_pawn_attack);
							ruch = !ruch;
							isReady = true;
							maxcount = 0;
							priorityrender = true;
						}
					}
				}
				isReady = false;
			}
			else
			{
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
				{		// RUCH BEZ BICIA //
					if (ev.mouse.button & 1)
					{
						pos_x = ev.mouse.x;
						pos_y = ev.mouse.y;
						if (pos_x > G_BUTTON_NEW_GAME_X1 && pos_x < G_BUTTON_NEW_GAME_X2 && pos_y > G_BUTTON_NEW_GAME_Y1 && pos_y < G_BUTTON_NEW_GAME_Y2)
						{
							al_destroy_event_queue(event_queue);
							al_destroy_bitmap(background);
							al_destroy_bitmap(image_white);
							al_destroy_bitmap(image_black);
							al_destroy_bitmap(image_checked_white);
							al_destroy_bitmap(image_checked_black);
							al_destroy_bitmap(image_queen_white);
							al_destroy_bitmap(image_queen_black);
							al_destroy_bitmap(image_checked_queen_white);
							al_destroy_bitmap(image_checked_queen_black);
							al_destroy_font(font18);
							ClearTree(&root_W);
							ClearTree(&root_B);
							return 0;
						}
						if (ster == 0)
						{
							correct_pawn = CheckPawn_Pos(pos_x, pos_y, pawn, ruch);
							draw_map(background, display);
							redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
								image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn);
							draw_game_interface(font18, ruch);
							al_flip_display();
							al_clear_to_color(al_map_rgb(0, 0, 0));
							if (correct_pawn > -1)
							{
								ster = 1;
							}
						}
						else
						{

							r_movepawn = MovePawn(pos_x, pos_y, ruch, correct_pawn, pawn);
							switch (r_movepawn)
							{
							case 0: // niepoprawny ruch
								isReady = false;
								break;
							case 1: // poprawny ruch
								isReady = true;
								isQueen(pawn, correct_pawn);
								break;
							case 2: // odznaczenie pionka
								ster = 0;
								correct_pawn = -1;
								draw_map(background, display);
								redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
									image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn);
								draw_game_interface(font18, ruch);
								al_flip_display();
								al_clear_to_color(al_map_rgb(0, 0, 0));
								break;
							}
							if (isReady)
							{
								ruch = !ruch;
								ster = 0;
								isReady = false;
								render = true;
							}
							correct_pawn = -1;
						}
					}
				}
			}
		if (isEnd_W(pawn) || isEnd_B(pawn))
		{
			switch (menu(display, ruch, true))
			{
			case 2: // powrot do menu
				return 0;
				break;
			case -1: // koniec gry
				al_destroy_event_queue(event_queue);
				al_destroy_bitmap(background);
				al_destroy_bitmap(image_white);
				al_destroy_bitmap(image_black);
				al_destroy_bitmap(image_checked_white);
				al_destroy_bitmap(image_checked_black);
				al_destroy_bitmap(image_queen_white);
				al_destroy_bitmap(image_queen_black);
				al_destroy_bitmap(image_checked_queen_white);
				al_destroy_bitmap(image_checked_queen_black);
				al_destroy_font(font18);
				ClearTree(&root_W);
				ClearTree(&root_B);
				return -1;
				break;
			}
		}
		// RENDER //
		if ((render && al_is_event_queue_empty(event_queue)) || priorityrender)
		{
			render = false;
			priorityrender = false;
			draw_map(background, display);
			redraw_pawn(image_white, image_black, image_checked_white, image_checked_black, image_queen_white, image_queen_black,
				image_checked_queen_white, image_checked_queen_black, pawn, correct_pawn);
			draw_game_interface(font18, ruch);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}
	return 0;
}
