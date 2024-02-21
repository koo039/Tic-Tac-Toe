#include <stdio.h>
#include <stdlib.h>
#include <conio.h>




int main(){

    char t[] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' } ;

    char c , p1 , p2 , p ;
    int put , i , player ;

    do{
    printf("\n player 1 (X) or (O) : ") ;
    c = getche() ;
    }while( c != 'x' && c != 'X' && c != 'O' && c != 'o' ) ;

    if( c == 'O' || c =='o' ){ p1 = 'O' ; p2 = 'X' ;}
    else{ p1 = 'X' ; p2 = 'O' ; }

    board( t , p1 , p2 );

        for( i = 1 ; i <= 9 ; i++ ){

        if( checkwin(t) == 1 ) break ;
        player = ( i % 2 ) ? 1 : 2 ;
        p = ( i % 2 ) ? p1 : p2 ;

        printf("\n player %d :" , player );
        do{
        printf("\nwrite number : ");
        scanf("%d",&put);
        }while( put < 1 || put > 9 );

        if( put == 1 && t[0] == '1' )
        t[0] = p ;
        else if( put == 2 && t[1] == '2' )
        t[1] = p ;
        else if( put == 3 && t[2] == '3' )
        t[2] = p ;
        else if( put == 4 && t[3] == '4' )
        t[3] = p ;
        else if( put == 5 && t[4] == '5' )
        t[4] = p ;
        else if( put == 6 && t[5] == '6' )
        t[5] = p ;
        else if( put == 7 && t[6] == '7' )
        t[6] = p ;
        else if( put == 8 && t[7] == '8' )
        t[7] = p ;
        else if( put == 9 && t[8] == '9' )
        t[8] = p ;
        else{
        printf("invalid move !\n");
        printf("try again");
        getch();
        i--;
        player = ( i % 2 ) ? 1 : 2 ;
        p = ( i % 2 ) ? p1 : p2 ;

        }
        board( t , p1 , p2 );
    }

    printf("\game over \n");

    if( i == 10 && checkwin(t) == 0 )printf("TIE\n");
    else if(player == 1 )printf("player 1 win\n");
    else printf("player 2 win\n");

return 0;
}


void board(char t[] , char p1 , char p2 ){
    system("cls");
    printf("\n\n player 1 : (%c)  -  player 2 : (%c)" , p1 , p2 );

    printf("\n\n       |       |       \n");
    printf("   %c   |   %c   |   %c   \n" , t[0] , t[1] , t[2] );
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n" , t[3] , t[4] , t[5] );
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n" , t[6] , t[7] , t[8] );
    printf("       |       |       \n");

}

int checkwin( char t[] ){
  int d;
    if( t[0] == t[1] && t[1] == t[2] )d=1;
    else if(t[3] == t[4] && t[4] == t[5] )d=1;
    else if(t[6] == t[7] && t[7] == t[8] )d=1;
    else if(t[0] == t[3] && t[3] == t[6] )d=1;
    else if(t[1] == t[4] && t[4] == t[7] )d=1;
    else if(t[2] == t[5] && t[5] == t[8] )d=1;
    else if(t[0] == t[4] && t[4] == t[8] )d=1;
    else if(t[2] == t[4] && t[4] == t[6] )d=1;
    else d=0;
return d;
}

