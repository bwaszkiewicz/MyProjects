#pragma once

#define WIDTH 960+CORRECTION // 960+CORRECTION
#define HEIGHT 640+CORRECTION*2 // 640+CORRECTION
#define SIZE 640+CORRECTION // rozmiar planszy
#define BOX_SIZE 80 // rozmiar jednego pola
#define MAP_SIZE 8 // iloœæ pól w poziomie/pionie
#define NUM_PAWNS 24
#define CORRECTION 5
#define DIRECTIONS 3
#define DEATH 13

// MENU BUTTONS

// Winscreen buttons
#define W_BUTTON_NEW_GAME_X1 400
#define W_BUTTON_NEW_GAME_Y1 320
#define W_BUTTON_NEW_GAME_X2 560
#define W_BUTTON_NEW_GAME_Y2 350

// Main menu buttons

#define MM_BUTTON_X1 360 //
#define MM_BUTTON_X2 600 //		ramki przyciskow w menu lewa i prawa strona
#define MM_1PLAYER_Y1 215
#define MM_1PLAYER_Y2 255
#define MM_2PLAYERS_Y1 295
#define MM_2PLAYERS_Y2 335
#define MM_EXIT_Y1 375
#define MM_EXIT_Y2 415

// GAME BUTTONS

#define G_BUTTON_NEW_GAME_X1 WIDTH - 250
#define G_BUTTON_NEW_GAME_Y1 35
#define G_BUTTON_NEW_GAME_X2 WIDTH - 50
#define G_BUTTON_NEW_GAME_Y2 70