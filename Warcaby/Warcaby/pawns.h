#pragma once

/**
* \brief Struktura pionkow
* \param	ID		- zawiera numer id danego pionka
* \param	x		- aktualna pozycja (numer pola) w osi X
* \param	y		- aktualna pozycja (numer pola) w osi Y
* \param	live	- 1 pionek w grze, 0 pionek zbity
* \param	type	- 0 zwykly pionek, 1 damka
*/
struct Pawn {
	int ID;
	int x;
	int y;
	bool live;
	bool type;
};


/**
* \brief Funkcja inicjalizujaca pionki
* \param	pawn		- tablica struktur z danymi o pionkach
*/
void InitPawn(struct Pawn pawn[]);
/**
* \brief Funkcja odpowiadajaca za wykonanie ataku zgodnie ze wskazanym kierunkiem
* \param	pawn		- tablica struktur z danymi o pionkach
* \param	pawn_id		- numer id danego pionka
* \param	ruch		- aktualny ruch biale/czarne
* \param	direction	- kierunek w ktorym ma zostac wykonane bicie
*/
void AutoAttack(struct Pawn pawn[], int pawn_id, bool ruch, int direction);
/**
* \brief Funkcja sprawdzajaca czy jakis pionek nie zostal damka
* \param	pawn		- tablica struktur z danymi o pionkach
* \param	id			- numer id danego pionka
*/
void isQueen(struct Pawn pawn[], int id);
/**
* \brief Funkcja zwracajaca wspolrzedne myszki po kliknieciu
* \param	tab_pos		- tablica przechowujaca wspolrzedna x i y danej pozycji
*/
void TakeMouse(int tab_pos[]);


/**
* \brief Funkcja sprawdzajaca czy damka moze przejsc do danej pozycji
* \param	x			- numer pola w osi X
* \param	y			- numer pola w osi Y
* \param	pawn_id		- numer id danego pionka
* \param	pawn		- tablica struktur z danymi o pionkach
* \return true -> moze przejsc, false -> nie moze przejsc
*/
bool ABS_MOVE(int x, int y, int pawn_id, struct Pawn pawn[]);
/**
* \brief Funkcja sprawdzajaca czy na danym polu stoi jakis pionek
* \param	x			- numer pola w osi X
* \param	y			- numer pola w osi Y
* \param	pawn		- tablica struktur z danymi o pionkach
* \return true -> pole zajete, false -> pole puste
*/
bool CheckPos(int x, int y, struct Pawn pawn[]);
/**
* \brief Funkcja sprawdzajaca czy koniec gry z wygrana bialych
* \param	pawn		- tablica struktur z danymi o pionkach
* \return true -> koniec, false -> nie koniec
*/
bool isEnd_W(struct Pawn pawn[]);
/**
* \brief Funkcja sprawdzajaca czy koniec gry z wygrana czarnych
* \param	pawn		- tablica struktur z danymi o pionkach
* \return true -> koniec, false -> nie koniec
*/
bool isEnd_B(struct Pawn pawn[]);


/**
* \brief Funkcja odpowiadajaca za ruch pionkiem przy wskazaniu myszy
* \param	mouse_pos_x		- pozycja wskazana przez mysz w osi X
* \param	mouse_pos_y		- pozycja wskazana przez mysz w osi Y
* \param	ruch			- aktualny ruch biale/czarne
* \param	pawn_id			- numer id danego pionka
* \param	pawn			- tablica struktur z danymi o pionkach
* \return 0 -> bledny ruch, 1 -> zakonczenie popranego ruchu, 2 -> odznaczenie pionka
*/
int MovePawn(int mouse_pos_x, int mouse_pos_y, bool ruch, int pawn_id, struct Pawn pawn[]);
/**
* \brief Funkcja zmieniajaca wspolrzedne pionkow przy ruchu
* \param	x			- numer pola w osi X
* \param	y			- numer pola w osi Y
* \param	ruch		- aktualny ruch biale/czarne
* \param	pawn_id		- numer id danego pionka
* \param	pawn		- tablica struktur z danymi o pionkach
* \return 0 -> niepoprawny ruch, 1 -> poprawny ruch
*/
int MovePawn_Normal(int x, int y, bool ruch, int pawn_id, struct Pawn pawn[]); 
/**
* \brief Funkcja zmieniajaca wspolrzedne damek przy ruchu
* \param	x			- numer pola w osi X
* \param	y			- numer pola w osi Y
* \param	ruch		- aktualny ruch biale/czarne
* \param	pawn_id		- numer id danego pionka
* \param	pawn		- tablica struktur z danymi o pionkach
* \return 0 -> niepoprawny ruch, 1 -> poprawny ruch
*/
int MovePawn_Queen(int x, int y, bool ruch, int pawn_id, struct Pawn pawn[]);
/**
* \brief Funkcja sprawdzajaca po wspolrzednych myszki, czy na danej pozycji stoi pionek
* \param	mouse_pos_x		- pozycja wskazana przez mysz w osi X
* \param	mouse_pos_y		- pozycja wskazana przez mysz w osi Y
* \param	pawn			- tablica struktur z danymi o pionkach
* \param	ruch			- aktualny ruch biale/czarne
* \return 0-23 -> ID pionka, -1 -> puste pole, -2 -> obszar poza polem gry
*/
int CheckPawn_Pos(int mouse_pos_x, int mouse_pos_y, struct Pawn pawn[], bool ruch);
/**
* \brief Funkcja sprawdzaj¹ca po numerach pola, czy na danej pozycji stoi pionek
* \param	x			- numer pola w osi X
* \param	y			- numer pola w osi Y
* \param	pawn		- tablica struktur z danymi o pionkach
* \return 0-23 -> ID pionka, -1 -> puste pole, -2 -> obszar poza polem gry
*/
int CheckPawn_Cords(int x, int y, struct Pawn pawn[]);
/**
* \brief Funkcja zwracajaca id pionka ktory zostal wybrany
* \param ruch - aktualny ruch biale/czarne
* \param pawn - tablica struktur z danymi o pionkach
* \param choosepawn - tablica z numerami id pionkow ktore moga zostac wybrane
* \return 0-23 -> ID pionka ktory zostal wybrany
*/
int Choose(bool ruch, struct Pawn pawn[], int choosepawn[]); // zwraca id pionka, ktory zostal wybrany
/**
* \brief Funkcja sprawdzajaca ktory pionek posiada najwiecej zbic
* \param ruch - aktualny ruch biale/czarne
* \param pawn - tablica struktur z danymi o pionkach
* \param root_W - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow bialych
* \param root_B - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow czarnych
* \param choosepawn - tablica z numerami id pionkow ktore moga zostac wybrane
* \return 0-23 -> ID pionka z najwieksza liczba bic, -1 -> brak bicia dla jakiegokolwiek pionka
*/
int CheckBattle(bool ruch, struct Pawn pawn[], struct MainRoute **root_W, struct MainRoute **root_B, int choosepawn[]);
/**
* \brief Funkcja zwracajaca ilosc bic dla danego pionka oraz tworzaca liste kierunkow bicia dla danego pionka
* \param ruch - aktualny ruch biale/czarne
* \param pawn - tablica struktur z danymi o pionkach
* \param currnt_id - numer ID wybranego pionka
* \param direction - numer kierunku w ktorym jest tworzona lista
* \param pawn_x - nowy numer pola pionka w osi X
* \param pawn_y - nowy numer pola pionka w osi Y
* \param head_W - glowa listy bicia danego pionka (bialego)
* \param head_B - glowa listy bicia danego pionka (czarnego)
* \param counter - licznik dlugosci listy
* \return ilosc bic dla danego pionka
*/
int ExtendedCheckBattle(bool ruch, struct Pawn pawn[], int current_id, int direction, int pawn_x, int pawn_y,
	struct MainRoute **head_W, struct MainRoute **head_B, int *counter);
/**
* \brief Funkcja sprawdzajaca po ruchu w ktorym kierunku pionek zdobedzie najwiecej zbic
* \param current_id - numer ID wybranego pionka
* \param x - numer pola na ktorym stoi pionek w osi X
* \param y - numer pola na ktorym stoi pionek w osi Y
* \param last_direction - kierunek w ktorym pionek ostatnio sie poruszyl
* \param ruch - aktualny ruch biale/czarne
* \param pawn - tablica struktur z danymi o pionkach
* \return liczba bic dla danego kierunku
*/
int CheckMax(int current_id, int x, int y, int last_direction, bool ruch, struct Pawn pawn[]);
/**
* \brief Funkcja zwracajaca indeks ktorego wartosc jest najwieksza
* \param tab - tablica kierunkow 
* \param end - dlugosc tablicy
* \return -1 -> wartosc kazdego indeksu jest rowny "0", indeks ktorego wartosc jest najwieksza
*/
int TableIndexMax(int tab[], int end);
/**
* \brief Funkcja zwracajaca kirunek kolejnego bicia
* \param count - licznik ile kierunkow juz odczytano
* \param ruch - aktualny ruch biale/czarne
* \param pawn_id - numer ID danego pionka
* \param root_W - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow bialych
* \param root_B - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow czarnych
* \return -1 -> koniec kolejki kierunkow bicia, 0-3 -> kierunek bicia
*/
int NextDirection(int count, bool ruch, int pawn_id, struct MainRoute **root_W, struct MainRoute **root_B);
/**
* \brief Funkcja zwracajaca ilosc ruchow na podstawie dlugosci listy kierunkow
* \param id - numer ID danego pionka
* \param ruch - aktualny ruch biale/czarne
* \param root_W - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow bialych
* \param root_B - korzen drzewa przechowujacego listy z kierunkami ruchu pionkow czarnych
return liczba ruchow
*/
int DirectionsNumbers(int id, bool ruch, struct MainRoute **root_W, struct MainRoute **root_B);


																								// SI //

/**
* \brief Funkcja odpowiadajaca za ruch SI
* \param ruch - aktualny ruch biale/czarne
* \param id - numer ID danego pionka
* \param pawn - tablica struktur z danymi o pionkach
*/
void SI_Move_Pawn(bool ruch, int id, struct Pawn pawn[]);
/**
* \brief Funkcja odpowiadaja za ruch zwyklych pionkow (SI)
* \param ruch - aktualny ruch biale/czarne
* \param id - numer ID danego pionka
* \param pawn - tablica struktur z danymi o pionkach
*/
void SI_Move_Normal_Pawn(bool ruch, int id, struct Pawn pawn[]);
/**
* \brief Funkcja odpowiadaja za ruch damek (SI)
* \param ruch - aktualny ruch biale/czarne
* \param id - numer ID danego pionka
* \param pawn - tablica struktur z danymi o pionkach
*/
void SI_Move_Queen_Pawn(bool ruch, int id, struct Pawn pawn[]);


/**
* \brief Funkcja sprawdzajaca czy dany pionek nie jest zablokowany (mozliwy jest ruch)
* \param id - numer ID danego pionka
* \param pawn - tablica struktur z danymi o pionkach
* \return true -> ruch mozliwy, false -> ruch niemozliwy
*/
bool SI_Possible_Move(int id, struct Pawn pawn[]);


/**
* \brief Funkcja wybierajaca pionek do ruchu
* \param ruch - aktualny ruch biale/czarne
* \param pawn - tablica struktur z danymi o pionkach
* \return numer ID pionka, ktory wykona ruch
*/
int SI_Choose_Pawn(bool ruch, struct Pawn pawn[]);