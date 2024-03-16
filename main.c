#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void initializePlayground(char playground[MAX][MAX]);
void printPlayground(char playground[MAX][MAX]);
void moveEast(char playground[MAX][MAX], char * position, int * xCoordinate, int * yCoordinate);
void moveSouth(char playground[MAX][MAX], char * position, int * xCoordinate, int * yCoordinate);
void moveNorth(char playground[MAX][MAX], char * position, int * xCoordinate, int * yCoordinate);
void moveWest(char playground[MAX][MAX], char * position, int * xCoordinate, int * yCoordinate);


int main()
{
    char playground[MAX][MAX];
    char input;
    int xCoordinate = 0;
    int yCoordinate = 0;
    char position = 'A';

    initializePlayground(playground);
    playground[xCoordinate][yCoordinate] = position;
    printPlayground(playground);

    do{



        printf("walk to: \n");
        scanf(" %c", &input);

            if(input == 'e'){
                if(yCoordinate == 9){
                printf("not possible\n");
                }else if(playground[xCoordinate][yCoordinate+1] == '.'){
                moveEast(playground, &position, &xCoordinate, &yCoordinate);
                printPlayground(playground);
                }else{
                printf("not possible\n");
                }
            }

            if(input == 's'){
                if(xCoordinate == 9){
                printf("not possible\n");
                }else if(playground[xCoordinate+1][yCoordinate] == '.'){
                moveSouth(playground, &position, &xCoordinate, &yCoordinate);
                printPlayground(playground);
                }else{
                printf("not possible\n");
                }
            }

            if(input == 'n'){
                if(xCoordinate == 0){
                printf("not possible\n");
                }else if(playground[xCoordinate-1][yCoordinate] == '.'){
                moveNorth(playground, &position, &xCoordinate, &yCoordinate);
                printPlayground(playground);
                }else{
                printf("not possible\n");
                }
            }

            if(input == 'w'){
                if(yCoordinate == 0){
                printf("not possible\n");
                }else if(playground[xCoordinate][yCoordinate-1] == '.'){
                moveWest(playground, &position, &xCoordinate, &yCoordinate);
                printPlayground(playground);
                }else{
                printf("not possible\n");
                }
            }

    }while (input != 'x');
}

//----------------------------------------------------------------------------------------------------------
void initializePlayground(char playground[MAX][MAX]){

        for(int i = 0; i < MAX; i++){
            for(int k = 0; k < MAX; k++){
                playground[i][k] = '.';
            }
        }
}
//----------------------------------------------------------------------------------------------------------
void printPlayground(char playground[MAX][MAX]){

    for(int i = 0; i < MAX; i++){
        for(int k = 0; k < MAX; k++){
            printf("%c", playground[i][k]);
        }
        printf("\n");
    }
}
//----------------------------------------------------------------------------------------------------------
void moveEast(char playground[MAX][MAX], char * position, int * xCoordinate, int * yCoordinate){

        playground[*xCoordinate][*yCoordinate+1] = *position+1;

        *position = *position +1;
        if(*position == 90){
            *position = 64;
        }
        *yCoordinate = *yCoordinate +1;

}
//----------------------------------------------------------------------------------------------------------
void moveSouth(char playground[MAX][MAX], char * position, int * xCoordinate, int * yCoordinate){

        playground[*xCoordinate+1][*yCoordinate] = *position+1;

        *position = *position +1;
        if(*position == 90){
            *position = 64;
        }
        *xCoordinate = *xCoordinate +1;

}
//----------------------------------------------------------------------------------------------------------
void moveNorth(char playground[MAX][MAX], char * position, int * xCoordinate, int * yCoordinate){

        playground[*xCoordinate-1][*yCoordinate] = *position+1;

        *position = *position +1;
        if(*position == 90){
            *position = 64;
        }
        *xCoordinate = *xCoordinate -1;

}
//----------------------------------------------------------------------------------------------------------
void moveWest(char playground[MAX][MAX], char * position, int * xCoordinate, int * yCoordinate){

        playground[*xCoordinate][*yCoordinate-1] = *position+1;

        *position = *position +1;
        if(*position == 90){
            *position = 64;
        }
        *yCoordinate = *yCoordinate -1;

}
