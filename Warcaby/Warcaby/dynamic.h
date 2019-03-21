#pragma once

/**
* \brief Struktura drzewa zawierajacego listy kierunkow bicia danych pionkow
* \param ID - numer ID danego pionka
* \param left - wskaznik na lewego potomka
* \param right - wskaznik na prawego potomka
* \param head - wskaznik na poczatek listy kierunkow bicia
*/
struct MainRoute {
	int ID; // id pionka do ktorego odnosi sie dana droga
	struct MainRoute* left;
	struct MainRoute* right;
	struct Route* head;
};
/**
* \brief Struktura listy kierunkow bicia
* \param direction - kierunek bicia ( 0 -> SE ( x++ y++), 1 -> NE (x++ y--), 2 -> NW (x-- y--), 3 -> SW (x-- y++) )
* \param next - wskaznik na kolejny element listy
*/
struct Route {
	int direction;
	struct Route* next;
};


/**
* \brief Funkcja tworzaca drzewa pionkow
* \param root_W - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow bialych
* \param root_B - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow czarnych
*/
void CreateTrees(struct MainRoute **root_W, struct MainRoute **root_B);
/**
* \brief Funkcja tworzaca drzewo
* \param root - korzen drzewa
* \param x - wartosc przechowywana w wezle (ID pionka)
*/
void AddTree(struct MainRoute **root, int x);
/**
* \brief Funkcja usuwajaca drzewo
* \param root - korzen drzewa
*/
void ClearTree(struct MainRoute **root);
/**
* \brief Funkcja tworzaca oraz dodajaca kolejny element listy trasy danego pionka
* \param id - numer ID danego pionka
* \param direction - numer kierunku bicia
* \param ruch - aktualny ruch biale/czarne
* \param root_W - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow bialych
* \param root_B - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow czarnych
* \param head - wskaznik na poczatek listy kierunkow bicia
*/
void add_route(int id, int direction, bool ruch, struct MainRoute **root_W, struct MainRoute **root_B, struct Route **head);
/**
* \brief Funkcja usuwajaca kolejke tras dla danego id
* \param id - numer ID danego pionka
* \param pawn - tablica struktur z danymi o pionkach
* \param root_W - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow bialych
* \param root_B - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow czarnych
*/
void clear_route(int id, struct Pawn pawn[], struct MainRoute **root_W, struct MainRoute **root_B);


/**
* \brief Funkcja zwracajaca adres glowy sciezki bicia dla konkretnego pionka
* \param id - numer ID danego pionka
* \param ruch - aktualny ruch biale/czarne
* \param root_W - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow bialych
* \param root_B - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow czarnych
* \return adres glowy sciezki bicia dla konkretnego pionka
*/
struct Route** ReturnRouteHeadAddres(int id, bool ruch, struct MainRoute **root_W, struct MainRoute **root_B);