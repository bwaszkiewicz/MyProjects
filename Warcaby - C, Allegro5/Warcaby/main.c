#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

#include "defines.h"
#include "menu.h"
#include "gameloop.h"
#include <vld.h> 

int main()
{
	ALLEGRO_DISPLAY *display = NULL;
	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "Allegro nie dziala", NULL, NULL);
		return -1;
	}

	display = al_create_display(WIDTH, HEIGHT);

	if (!display)
	{
		al_show_native_message_box(NULL, NULL, NULL, "Display nie dziala", NULL, NULL);
		return -1;
	}


	int GameMode;

	al_init_native_dialog_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	ALLEGRO_BITMAP *image = NULL;
	image = al_load_bitmap("icon.png");
	al_set_window_title(display, "Warcaby");
	al_set_display_icon(display, image);

	while (true)
	{
		GameMode = menu(display, false, false);
		if (GameMode == -1)
			break;
		else
			if (GameMode == 0)
			{
				if (gameloop2(display) == -1)
					break;
			}
			else
				if (GameMode == 1)
					if (gameloop1(display) == -1)
						break;
	}
	al_destroy_display(display);
	al_uninstall_mouse();
	al_destroy_bitmap(image);
	return 0;
}