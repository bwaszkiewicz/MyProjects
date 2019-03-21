#pragma once

/**
* \brief Funkcja rysuje plansze gry
* \param background - bitmapa tla planszy
* \param display - okno gry
*/
void draw_map(const struct ALLEGRO_BITMAP* background, const struct ALLEGRO_DISPLAY* display);
/**
* \brief Funkcja tworzy bitmapy pionkow i rysuje je na planszy gry
* \param image_white - bitmapa bialego, normalnego pionka
* \param image_black - bitmapa czarnego, normlnego pionka
* \param image_checked_white - bitmapa wskazanego bialego, normalnego pionka
* \param image_checked_black - bitmapa wskazanego czarnego, normalnego pionka
* \param image_queen_white - bitmapa bialej damki
* \param image_queen_black - bitmapa czarnej damki
* \param image_checked_queen_white - bitmapa wskazanej bialej damki
* \param image_checked_queen_black - bitmapa wskazanej czarnej damki
* \param display - okno gry
* \param pawn - tablica struktur z danymi o pionkach
*/
void draw_pawn(const struct ALLEGRO_BITMAP* image_white, const struct ALLEGRO_BITMAP* image_black, const struct ALLEGRO_BITMAP* image_checked_white,
	const struct ALLEGRO_BITMAP* image_checked_black, const struct ALLEGRO_BITMAP* image_queen_white, const struct ALLEGRO_BITMAP* image_queen_black,
	const struct ALLEGRO_BITMAP* image_checked_queen_white, const struct ALLEGRO_BITMAP* image_checked_queen_black,
	const struct ALLEGRO_DISPLAY* display, struct Pawn pawn[]);
/**
* \brief Funkcja rysuje pionki na planszy zgodnie z aktualna pozycja oraz w przypadku wskazania danego pionka rysuje bitmape z obramowaniem
* \param image_white - bitmapa bialego, normalnego pionka
* \param image_black - bitmapa czarnego, normlnego pionka
* \param image_checked_white - bitmapa wskazanego bialego, normalnego pionka
* \param image_checked_black - bitmapa wskazanego czarnego, normalnego pionka
* \param image_queen_white - bitmapa bialej damki
* \param image_queen_black - bitmapa czarnej damki
* \param image_checked_queen_white - bitmapa wskazanej bialej damki
* \param image_checked_queen_black - bitmapa wskazanej czarnej damki
* \param id - numer id pionka, ktory wykonuje ruch oraz wskazany
*/
void redraw_pawn(const struct ALLEGRO_BITMAP* image_white, const struct ALLEGRO_BITMAP* image_black, const struct ALLEGRO_BITMAP* image_checked_white,
	const struct ALLEGRO_BITMAP* image_checked_black, const struct ALLEGRO_BITMAP* image_queen_white, const struct ALLEGRO_BITMAP* image_queen_black,
	const struct ALLEGRO_BITMAP* image_checked_queen_white, const struct ALLEGRO_BITMAP* image_checked_queen_black,
	struct Pawn pawn[], int id);
/**
* \brief Funkcja rysuje boczny interfejs boczny gry
* \param font18 - czcionka
* \param ruch - aktualny ruch biale/czarne
*/
void draw_game_interface(const struct ALLEGRO_FONT *font18, bool ruch);
/**
* \brief Funkcja rysuje pionki do wyboru, jezeli maja taka sama ilosc bic
* \param id - numer id pionka do obrysowania
* \param pawn - tablica struktur z danymi o pionkach
* \param image_checked_white - bitmapa wskazanego bialego, normalnego pionka
* \param image_checked_black - bitmapa wskazanego czarnego, normalnego pionka
* \param image_checked_queen_white - bitmapa wskazanej bialej damki
* \param image_checked_queen_black - bitmapa wskazanej czarnej damki
*/
void draw_choose(int id, struct Pawn pawn[], const struct ALLEGRO_BITMAP* image_checked_white, const struct ALLEGRO_BITMAP* image_checked_black,
	const struct ALLEGRO_BITMAP* image_checked_queen_white, const struct ALLEGRO_BITMAP* image_checked_queen_black); // Obrysowuje pionki do wybrania

/**
* \brief Funkcja zwraca numer pola w osi X
* \param mouse_pos_x - pozycja wskazana przez mysz w osi X
* \param mouse_pos_y - pozycja wskazana przez mysz w osi Y
* \return numer pola (0-7), -1 -> dla wskazania pozycji poza oknem gry
*/
int ConvertCords_X(int mouse_pos_x, int mouse_pos_y);
/**
* \brief Funkcja zwraca numer pola w osi Y
* \param mouse_pos_x - pozycja wskazana przez mysz w osi X
* \param mouse_pos_y - pozycja wskazana przez mysz w osi Y
* \return numer pola (0-7), -1 -> dla wskazania pozycji poza oknem gry
*/
int ConvertCords_Y(int mouse_pos_x, int mouse_pos_y);