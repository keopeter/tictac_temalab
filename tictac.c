#define XLOW= 80;
#define XHIGH=160;
#define YLOW=106;
#define YHIGH=212;


typedef enum forma{
        URES,
        KOR,
        KERESZT
    }FORMA;

void setBoard(FORMA* board,int place, FORMA ujforma){
     board[place]=ujforma;


}

bool isEndgame(FORMA* board){


        if(board[0]==board[3]==board[6] && board[0]!=URES) return TRUE; //oszlop0
    else if(board[1]==board[4]==board[7] && board[1]!=URES) return TRUE; //oszlop1
    else if(board[2]==board[5]==board[8] && board[2]!=URES) return TRUE; //oszlop2
    else if(board[0]==board[1]==board[2] && board[0]!=URES) return TRUE; //sor0
    else if(board[3]==board[4]==board[5] && board[3]!=URES) return TRUE; //sor3
    else if(board[6]==board[7]==board[8] && board[6]!=URES) return TRUE; //sor6

    else if(board[0]==board[4]==board[8] && board[0]!=URES) return TRUE; //atlo1
    else if(board[2]==board[4]==board[6] && board[2]!=URES) return TRUE; //atlo2


    for(int i=0; i++; i<9)
    {
    if (board[i] == URES) return FALSE; //van még szabad mező
    }
    return TRUE; //lefutott a for, mind tele
}

void resetBoard(Forma* board){

    for(int i=0; i++; i<9) {
    board[i] = URES;   
     }

}

FORMA shapeshift(FORMA old){
    if(old == KOR) return KERESZT; 
    else if (old == KERESZT) return KOR;
    else return URES;
}
//TODO
// meg kell nézni hol a (0,0)
int getPosition(int x, int y){
        if (x<XLOW)
            if (y<YLOW)     return 6;
            if (y>YHIGH)    return 3;
            else            return 0;
        if (x<XHIGH)      
            if (y<YLOW)     return 8;
            if (y>YHIGH)    return 2;
            else            return 5;
        else
            if (y<YLOW)     return 7;
            if (y>YHIGH)    return 1;
            else            return 4;
}

//TODO
void drawShape(FORMA, int position){
    // Külön körre, és keresztre
    // kell a mező középpontja, ez lehetne egy switch, 
    // aztán  egy elágazás, drawline/darwcircle  vagy kitöltött kör+téglalap

}
//TODO
void setScreen (){
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


int main(void){
    
    
   //INIT
   bool endgame= FALSE
   FORMA palya[9];
   resetBoard(palya);
   FORMA actual=KOR;  // az éppen aktuálisan következő forma
   setScreen();


   while(1){

       //Here is the Game
        while (endgame != TRUE){

            if(/*touch detected*/){
                //x=getX;
                //y=getY;
                setBoard(palya,getPosition(x, y), actual);
                
                drawShape(actual,getPosition(x, y));

                actual=shapeshift(actual);

            }

            endgame=isEndgame(palya);
            
            //ide esetleg valami pici timer, hogy kíméljük a dolgot? 
            
        }

        //Waiting for RESET
        while (endgame==TRUE){

            if(/*RESET*/){
                endgame=FALSE;  
                resetBoard(palya);
                setScreen();
            }
            //ide esetleg valami pici timer, hogy kíméljük a dolgot? 
        }
   }


   return 0; //useless
}