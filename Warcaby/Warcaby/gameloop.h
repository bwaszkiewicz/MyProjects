#pragma once
/**
* \brief Funkcja glownej petli gry dla 1 gracza
* \param display - okno gry
* \return -1 -> koniec gry, 0 -> powrot do menu
*/
int gameloop1(struct ALLEGRO_DISPLAY* display);
/**
* \brief Funkcja glownej petli gry dla 2 graczy
* \param display - okno gry
* \return -1 -> koniec gry, 0 -> powrot do menu
*/
int gameloop2(struct ALLEGRO_DISPLAY* display);