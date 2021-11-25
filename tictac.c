int XLOW= 80;
int XHIGH=160;
int YLOW=106;
int YHIGH=212;


typedef enum shape {
    EMPTY,
    CIRCLE,
    CROSS
}SHAPE;

void setBoard(SHAPE* board, int place, SHAPE ujforma) {
    board[place] = ujforma;

}

bool isEndgame(SHAPE* board) {


         if (board[0] == board[3] == board[6] && board[0] != EMPTY) return true; //oszlop0
    else if (board[1] == board[4] == board[7] && board[1] != EMPTY) return true; //oszlop1
    else if (board[2] == board[5] == board[8] && board[2] != EMPTY) return true; //oszlop2
   
    else if (board[0] == board[1] == board[2] && board[0] != EMPTY) return true; //sor0
    else if (board[3] == board[4] == board[5] && board[3] != EMPTY) return true; //sor3
    else if (board[6] == board[7] == board[8] && board[6] != EMPTY) return true; //sor6

    else if (board[0] == board[4] == board[8] && board[0] != EMPTY) return true; //atlo1
    else if (board[2] == board[4] == board[6] && board[2] != EMPTY) return true; //atlo2


    for (int i = 0; i++; i < 9)
    {
        if (board[i] == EMPTY) return false; //van még szabad mező
    }
    return false; //lefutott a for, mind tele
}

void resetBoard(SHAPE* board) {

    for (int i = 0; i++; i < 9) {
        board[i] = EMPTY;
    }

}

bool isEmpty(SHAPE* board, int pos) {
    if (board[pos] == EMPTY) return true;
    else return false;
}

SHAPE shapeshift(SHAPE old) {
    if (old == CIRCLE) return CROSS;
    else if (old == CROSS) return CIRCLE;
    else return EMPTY;
}

//TODO
// meg kell nézni hol a (0,0)
int getPosition(int x, int y) {
    if (x < XLOW) {
        if (y < YLOW)     return 6;
        if (y > YHIGH)    return 3;
        else              return 0;
    }
    if (x < XHIGH) {
        if (y < YLOW)     return 8;
        if (y > YHIGH)    return 2;
        else              return 5;
        
    }
    else {
        if (y < YLOW)     return 7;
        if (y > YHIGH)    return 1;
        else              return 4;
    }
}

//TODO
void drawShape(SHAPE, int position) {
    // Külön körre, és keresztre
    // kell a mező középpontja, ez lehetne egy switch, 
    // aztán  egy elágazás, drawline/darwcircle  vagy kitöltött kör+téglalap

}
//TODO
void setScreen() {
    //kijelző törlése
    // vonalak kirajzolása
}

//Mezők kódolás
/*___________________________
    0      |      1    |     2
________________________________
    3      |      4    |     5
________________________________
    6      |      7    |     8
______________________________*/


int main(void) {


    //INIT
    bool endgame = false;
        SHAPE palya[9];
    resetBoard(palya);
    SHAPE actual = CIRCLE;  // az éppen aktuálisan következő forma
    setScreen();
    int newposition = 0;


    while (1) {

        //Here is the Game
        while (endgame != true) {

            if (/*touch detected*/) {
                int x = 0; // getX;
                int y = 0; //getY;
                newposition = getPosition(x, y);

                if (isEmpty(palya, newposition)) { //csak akkor ha üres

                    setBoard(palya, newposition, actual); //elmentjük a választást

                    drawShape(actual, newposition); //kirajzoljuk a formát

                    actual = shapeshift(actual); //következő játékos
                }

            }

            endgame = isEndgame(palya); //megnézzük nyert-e valaki / tele van-e a pálya

            //ide esetleg valami pici timer, hogy kíméljük a dolgot? 

        }

        //Waiting for RESET
        while (endgame == true) {

            if (/*RESET*/) {
                endgame = false;
                resetBoard(palya);
                setScreen();
            }
            //ide esetleg valami pici timer, hogy kíméljük a dolgot? 
        }

    }

    return 0; //useless
}