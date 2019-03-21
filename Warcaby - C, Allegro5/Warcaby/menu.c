#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>

#include "defines.h"
#include "menu.h"

int menu(struct ALLEGRO_DISPLAY* display, bool ruch, bool GameOver)
{
	int pos_x, pos_y;
	ALLEGRO_EVENT_QUEUE *menu_event_queue = al_create_event_queue();
	struct ALLEGRO_FONT *font20 = al_load_font("comic.ttf", 20, 0);
	struct ALLEGRO_FONT *font36 = al_load_font("comic.ttf", 36, 0);

	if (GameOver)
		winscreen_render(font20, ruch);
	else
		menu_render(font20, font36);

	al_register_event_source(menu_event_queue, al_get_display_event_source(display));
	al_register_event_source(menu_event_queue, al_get_mouse_event_source());

	while (true)
	{
		ALLEGRO_EVENT menu_ev;
		al_wait_for_event(menu_event_queue, &menu_ev);
		if (menu_ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			al_destroy_event_queue(menu_event_queue);
			al_destroy_font(font20);
			al_destroy_font(font36);
			return -1;
		}
		else
			if (menu_ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (menu_ev.mouse.button & 1)
				{
					pos_x = menu_ev.mouse.x;
					pos_y = menu_ev.mouse.y;
					// BACK TO MENU IN WINSCREEN MODE	//
					if (pos_x > W_BUTTON_NEW_GAME_X1 && pos_x < W_BUTTON_NEW_GAME_X2 && pos_y > W_BUTTON_NEW_GAME_Y1 && pos_y < W_BUTTON_NEW_GAME_Y2 && GameOver)
						return 2;
					// NEW GAME IN 1PLAYER MODE		//
					if (pos_x > MM_BUTTON_X1 && pos_x < MM_BUTTON_X2 && pos_y > MM_1PLAYER_Y1 && pos_y < MM_1PLAYER_Y2 && (!GameOver))
						return 1;
					// NEW GAME IN 2PLAYERS MODE	//
					if (pos_x > MM_BUTTON_X1 && pos_x < MM_BUTTON_X2 && pos_y > MM_2PLAYERS_Y1 && pos_y < MM_2PLAYERS_Y2 && (!GameOver))
						return 0;
					//			EXIT GAME			//
					if (pos_x > MM_BUTTON_X1 && pos_x < MM_BUTTON_X2 && pos_y > MM_EXIT_Y1 && pos_y < MM_EXIT_Y2 && (!GameOver))
					{
						al_destroy_event_queue(menu_event_queue);
						al_destroy_font(font20);
						al_destroy_font(font36);
						return -1;
					}
				}
			}
	}
	return -1;
}

void winscreen_render(struct ALLEGRO_FONT *font20, bool ruch)
{
	al_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, al_map_rgb(100, 100, 100));
	if (!ruch)
		al_draw_text(font20, al_map_rgb(255, 255, 0), 480, 200, ALLEGRO_ALIGN_CENTRE, "Gratulacje, wygraly Biale");
	else
		al_draw_text(font20, al_map_rgb(255, 255, 0), 480, 200, ALLEGRO_ALIGN_CENTRE, "Gratulacje, wygraly Czarne");

	al_draw_text(font20, al_map_rgb(255, 255, 0), 480, 320, ALLEGRO_ALIGN_CENTRE, "Powrot do menu");
	al_draw_rectangle(W_BUTTON_NEW_GAME_X1, W_BUTTON_NEW_GAME_Y1, W_BUTTON_NEW_GAME_X2, W_BUTTON_NEW_GAME_Y2, al_map_rgb(100, 255, 100), 2);
	al_flip_display();
}
void menu_render(struct ALLEGRO_FONT *font20, struct ALLEGRO_FONT *font36)
{

	al_draw_filled_rectangle(0, 0, WIDTH, HEIGHT, al_map_rgb(100, 100, 100));

	al_draw_text(font36, al_map_rgb(255, 255, 0), 480, 140, ALLEGRO_ALIGN_CENTRE, "Warcaby");

	al_draw_text(font20, al_map_rgb(255, 255, 0), 480, 220, ALLEGRO_ALIGN_CENTRE, "1 Gracz");
	al_draw_rectangle(MM_BUTTON_X1, MM_1PLAYER_Y1, MM_BUTTON_X2, MM_1PLAYER_Y2, al_map_rgb(100, 255, 100), 2);

	al_draw_text(font20, al_map_rgb(255, 255, 0), 480, 300, ALLEGRO_ALIGN_CENTRE, "2 Graczy");
	al_draw_rectangle(MM_BUTTON_X1, MM_2PLAYERS_Y1, MM_BUTTON_X2, MM_2PLAYERS_Y2, al_map_rgb(100, 255, 100), 2);

	al_draw_text(font20, al_map_rgb(255, 255, 0), 480, 380, ALLEGRO_ALIGN_CENTRE, "Zakoncz gre");
	al_draw_rectangle(MM_BUTTON_X1, MM_EXIT_Y1, MM_BUTTON_X2, MM_EXIT_Y2, al_map_rgb(100, 255, 100), 2);

	al_flip_display();
}