#pragma once
/**
* \brief Funkcja zawiera menu poczatkowe gry oraz wyswietla informacje o wygranej
* \param display - okno gry
* \param ruch - aktualny ruch biale/czarne
* \param GameOver - podaje czy zakonczyla sie gra i czy wyswietlic informacje o wygranej
* \return -1 -> gra ma sie zakonczyc, 0 -> nowa gra z innym graczem, 1 -> nowa gra z komputerem, 2 -> powrot do menu (w przypadku ekranu z informacja o wygranej) 
*/
int menu(struct ALLEGRO_DISPLAY* display, bool ruch, bool GameOver);

/**
* \brief Funkcja rysuje informacje o wygranej
* \param font20 - czcionka 
* \param ruch - aktualny ruch biale/czarne
*/
void winscreen_render(struct ALLEGRO_FONT *font20, bool ruch);
/**
* \brief Funkcja rysuje menu poczatkowe gry
* \param font20 - czcionka
* \param font36 - czcionka 
*/
void menu_render(struct ALLEGRO_FONT *font20, struct ALLEGRO_FONT *font36);