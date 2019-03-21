#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

#include "gameloop.h"
#include "defines.h"
#include "pawns.h"

void draw_map(const struct ALLEGRO_BITMAP* background, const struct ALLEGRO_DISPLAY* display)
{
	al_set_target_bitmap(background);
	for (int i = 0; i < MAP_SIZE; ++i)
	{
		for (int j = 0; j < MAP_SIZE; ++j)
			if (i % 2 == 0)
				if (j % 2 == 0)
					al_draw_filled_rectangle(j*BOX_SIZE + CORRECTION, i*BOX_SIZE + CORRECTION, j * BOX_SIZE + BOX_SIZE + CORRECTION, i * BOX_SIZE + BOX_SIZE + CORRECTION, al_map_rgb(255, 255, 255));
				else
					al_draw_filled_rectangle(j*BOX_SIZE + CORRECTION, i*BOX_SIZE + CORRECTION, j * BOX_SIZE + BOX_SIZE + CORRECTION, i * BOX_SIZE + BOX_SIZE + CORRECTION, al_map_rgb(100, 100, 100));
			else
				if (j % 2 == 0)
					al_draw_filled_rectangle(j*BOX_SIZE + CORRECTION, i*BOX_SIZE + CORRECTION, j * BOX_SIZE + BOX_SIZE + CORRECTION, i * BOX_SIZE + BOX_SIZE + CORRECTION, al_map_rgb(100, 100, 100));
				else
					al_draw_filled_rectangle(j*BOX_SIZE + CORRECTION, i*BOX_SIZE + CORRECTION, j * BOX_SIZE + BOX_SIZE + CORRECTION, i * BOX_SIZE + BOX_SIZE + CORRECTION, al_map_rgb(255, 255, 255));
	}
	al_set_target_bitmap(al_get_backbuffer(display));


	al_draw_bitmap(background, 0, 0, 0);
	al_flip_display();
}
void draw_pawn(const struct ALLEGRO_BITMAP* image_white, const struct ALLEGRO_BITMAP* image_black, const struct ALLEGRO_BITMAP* image_checked_white,
	const struct ALLEGRO_BITMAP* image_checked_black, const struct ALLEGRO_BITMAP* image_queen_white, const struct ALLEGRO_BITMAP* image_queen_black,
	const struct ALLEGRO_BITMAP* image_checked_queen_white, const struct ALLEGRO_BITMAP* image_checked_queen_black,
	const struct ALLEGRO_DISPLAY* display, struct Pawn pawn[])
{
	// Pionki biale //
	al_set_target_bitmap(image_white);
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2.5, al_map_rgb(255, 255, 255));
	al_set_target_bitmap(al_get_backbuffer(display));
	// Pionki czarne //
	al_set_target_bitmap(image_black);
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2.5, al_map_rgb(0, 0, 0));
	al_set_target_bitmap(al_get_backbuffer(display));
	// Wskazany pionek bialy //
	al_set_target_bitmap(image_checked_white);
	al_draw_rectangle(0, 0, BOX_SIZE, BOX_SIZE, al_map_rgb(255, 0, 255), CORRECTION);
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2.5, al_map_rgb(255, 255, 255));
	al_get_target_bitmap(al_get_backbuffer(display));
	// Wskazany pionek czarny //
	al_set_target_bitmap(image_checked_black);
	al_draw_rectangle(0, 0, BOX_SIZE, BOX_SIZE, al_map_rgb(255, 0, 255), CORRECTION);
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2.5, al_map_rgb(0, 0, 0));
	al_get_target_bitmap(al_get_backbuffer(display));
	// Damka biala // 
	al_set_target_bitmap(image_queen_white);
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2.5, al_map_rgb(255, 255, 255));
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 4, al_map_rgb(204, 204, 204));
	al_get_target_bitmap(al_get_backbuffer(display));
	// Damka czarna //
	al_set_target_bitmap(image_queen_black);
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2.5, al_map_rgb(0, 0, 0));
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 4, al_map_rgb(40, 40, 40));
	al_get_target_bitmap(al_get_backbuffer(display));
	// Wskazana damka biala //
	al_set_target_bitmap(image_checked_queen_white);
	al_draw_rectangle(0, 0, BOX_SIZE, BOX_SIZE, al_map_rgb(255, 0, 255), CORRECTION);
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2.5, al_map_rgb(255, 255, 255));
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 4, al_map_rgb(204, 204, 204));
	al_get_target_bitmap(al_get_backbuffer(display));
	// Wskazana damka czarna //
	al_set_target_bitmap(image_checked_queen_black);
	al_draw_rectangle(0, 0, BOX_SIZE, BOX_SIZE, al_map_rgb(255, 0, 255), CORRECTION);
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2.5, al_map_rgb(0, 0, 0));
	al_draw_filled_circle(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 4, al_map_rgb(40, 40, 40));
	al_get_target_bitmap(al_get_backbuffer(display));

	for (int i = 0; i<NUM_PAWNS; ++i)
		if (i<NUM_PAWNS / 2)
			al_draw_bitmap(image_white, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
		else
			al_draw_bitmap(image_black, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
	al_flip_display();
}
void redraw_pawn(const struct ALLEGRO_BITMAP* image_white, const struct ALLEGRO_BITMAP* image_black, const struct ALLEGRO_BITMAP* image_checked_white,
	const struct ALLEGRO_BITMAP* image_checked_black, const struct ALLEGRO_BITMAP* image_queen_white, const struct ALLEGRO_BITMAP* image_queen_black,
	const struct ALLEGRO_BITMAP* image_checked_queen_white, const struct ALLEGRO_BITMAP* image_checked_queen_black, struct Pawn pawn[], int id)
{
	for (int i = 0; i < NUM_PAWNS; ++i)
		if (pawn[i].live)
		{
			if (i < NUM_PAWNS / 2)
			{
				if (!pawn[i].type)
					if (i != id)
						al_draw_bitmap(image_white, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
					else
						al_draw_bitmap(image_checked_white, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
				else
					if (i != id)
						al_draw_bitmap(image_queen_white, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
					else
						al_draw_bitmap(image_checked_queen_white, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
			}
			else
				if (!pawn[i].type)
					if (i != id)
						al_draw_bitmap(image_black, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
					else
						al_draw_bitmap(image_checked_black, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
				else
					if (i != id)
						al_draw_bitmap(image_queen_black, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
					else
						al_draw_bitmap(image_checked_queen_black, pawn[i].x*BOX_SIZE + CORRECTION, pawn[i].y*BOX_SIZE + CORRECTION, 0);
		}
	al_flip_display();
}
void draw_game_interface(struct ALLEGRO_FONT* font18, bool ruch)
{
	if (!ruch)
		al_draw_text(font18, al_map_rgb(255, 255, 255), WIDTH - 300, 100, 0, "Aktualny ruch Bialych");
	else
		al_draw_text(font18, al_map_rgb(255, 255, 255), WIDTH - 300, 100, 0, "Aktualny ruch Czarnych");

	al_draw_filled_rectangle(WIDTH - 250, 35, WIDTH - 50, 70, al_map_rgb(100, 100, 0));
	al_draw_text(font18, al_map_rgb(255, 255, 255), WIDTH - 200, 40, 0, "Nowa gra");
	al_flip_display();
}
void draw_choose(int id, struct Pawn pawn[], const struct ALLEGRO_BITMAP* image_checked_white, const struct ALLEGRO_BITMAP* image_checked_black,
	const struct ALLEGRO_BITMAP* image_checked_queen_white, const struct ALLEGRO_BITMAP* image_checked_queen_black)
{
	for (int i = 0; i < NUM_PAWNS; ++i)
	{
		if (i == id)
		{
			if (id < 12)
			{		// biale
				if (pawn[id].type != 1)
					al_draw_bitmap(image_checked_white, pawn[id].x*BOX_SIZE + CORRECTION, pawn[id].y*BOX_SIZE + CORRECTION, 0);
				else
					al_draw_bitmap(image_checked_queen_white, pawn[id].x*BOX_SIZE + CORRECTION, pawn[id].y*BOX_SIZE + CORRECTION, 0);
			}
			else
			{		// czarne
				if (pawn[id].type != 1)
					al_draw_bitmap(image_checked_black, pawn[id].x*BOX_SIZE + CORRECTION, pawn[id].y*BOX_SIZE + CORRECTION, 0);
				else
					al_draw_bitmap(image_checked_queen_black, pawn[id].x*BOX_SIZE + CORRECTION, pawn[id].y*BOX_SIZE + CORRECTION, 0);

			}

		}
	}
	al_flip_display();
	//al_draw_rectangle(pawn[id].x*BOX_SIZE+CORRECTION,pawn[id].y*BOX_SIZE+CORRECTION,pawn[id].x*BOX_SIZE+CORRECTION+BOX_SIZE,pawn[id].y*BOX_SIZE+CORRECTION+BOX_SIZE,al_map_rgb(255,0,255),CORRECTION);
}

int ConvertCords_X(int mouse_pos_x, int mouse_pos_y)
{
	if (mouse_pos_x > CORRECTION && mouse_pos_x < SIZE + CORRECTION && mouse_pos_y > CORRECTION && mouse_pos_y < SIZE + CORRECTION)
		return (mouse_pos_x - CORRECTION) / BOX_SIZE;
	else
		return -1;
}
int ConvertCords_Y(int mouse_pos_x, int mouse_pos_y)
{
	if (mouse_pos_x > CORRECTION && mouse_pos_x < SIZE + CORRECTION && mouse_pos_y > CORRECTION && mouse_pos_y < SIZE + CORRECTION)
		return (mouse_pos_y - CORRECTION) / BOX_SIZE;
	else
		return -1;
}