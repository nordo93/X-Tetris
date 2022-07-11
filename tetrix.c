#include <stdio.h>
#include <stdlib.h>
#define row 15
#define column 10

/*Macros*/
/*the definition of constant values*/

typedef struct {
    char **array;
    int width, righe, colonne;
} Shape;
Shape current;

const Shape ShapesArray[7]= {
    {(char *[]){(char []){0,1,1},(char []){1,1,0}, (char []){0,0,0}}, 3},                           //S_shape     
    {(char *[]){(char []){1,1,0},(char []){0,1,1}, (char []){0,0,0}}, 3},                           //Z_shape     
    {(char *[]){(char []){0,1,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                           //T_shape     
    {(char *[]){(char []){0,0,1},(char []){1,1,1}, (char []){0,0,0}}, 3},                           //L_shape     
    {(char *[]){(char []){1,0,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                           //ML_shape    
    {(char *[]){(char []){1,1},(char []){1,1}}, 2},                                                   //SQ_shape
    {(char *[]){(char []){0,0,0,0}, (char []){1,1,1,1}, (char []){0,0,0,0}, (char []){0,0,0,0}}, 4} //R_shape
};
Shape CopyShape(Shape shape){
    Shape new_shape = shape;
    char **copyshape = shape.array;
    new_shape.array = (char**)malloc(new_shape.width*sizeof(char*));
    int i, j;
    for(i = 0; i < new_shape.width; i++){
        new_shape.array[i] = (char*)malloc(new_shape.width*sizeof(char));
        for(j=0; j < new_shape.width; j++) {
            new_shape.array[i][j] = copyshape[i][j];
        }
    }
    return new_shape;
}

void DeleteShape(Shape shape){
    int i;
    for(i = 0; i < shape.width; i++){
        free(shape.array[i]);
    }
    free(shape.array);
}

/*tetramini*/





/* Casella del piano di gioco */
enum casella {VUOTO, PLAYER_1, PLAYER_2};
typedef enum casella casella_t;

typedef struct {
    char height, width;
    char **shape;
} Shape2;

/*https://stackoverflow.com/questions/38357987/initialization-of-multidimensional-pointers-with-different-dimensional-anonym-ar*/
const Shape2 S_shape = {
        2, /* height */
        2, /* width */
        (char *[]) { /* Compound literals, declaring an anonymous array of `char *` with static storage duration */
                (char []) {0, 1}, /* Another compound literal, declaring a static storage duration for a `char []` that will be pointed by `char *[]` */
                (char []) {1, 1} /* Same as above, this one the next (and last) element of `char *[]` */
        }
};


/* Piano di gioco */
/* nota: piano_t è un puntatore */
typedef casella_t *piano_t;
typedef enum bool {FALSE, TRUE} bool_t;

/*Inizializzatore*/
void init(piano_t piano, int ROWS, int COLS) {
    int r, c;
    for (r=0; r<ROWS; r++) {
        for (c=0; c<COLS; c++) {
            piano[r*COLS + c] = VUOTO;
        }
    }
}

void stampa(piano_t piano, int ROWS, int COLS) {
    int r, c;
    for (r=0; r<ROWS; r++) {
        for (c=0; c<COLS; c++) {
            casella_t casella = piano[r*COLS + c];
            if (casella==VUOTO)
                printf(" _ ");
            else if (casella==PLAYER_1)
                printf(" X ");
            else
                printf(" O ");
        }
        printf("  ");
        for (c=0; c<COLS; c++) {
            casella_t casella2 = piano[r*COLS + c];
            if (casella2==VUOTO)
                printf(" _ ");
            else if (casella2==PLAYER_1)
                printf(" X ");
            else
                printf(" O ");
        }
        printf("\n");
    }
    for (c=0; c<COLS; c++)
        printf(" %d ", c);
    printf("  ");
    for (c=COLS; c<(COLS*2); c++)
        printf(" %d", c);
    printf("\n");
}

void load_playground() // INIZIALIZZA L'ARRAY VUOTO CON CICLI FOR INNESTATI
{
	/*char grid[row][column]; // DICHIARAZIONE ARRAY DI CHAR*/
	int i , j;
    for (i = 0; i < row; i++)
    {
    	if(i==0 || i==column)
          printf("*");
    	printf("\n");
        for (j = 0; j < column; j++)
        {
        	if(i==0 && j==0|| i==column && j==column)
          printf("*");
            
            printf(" ");
        }
        if(i==0 && i==column)
          printf("*");
    }
}



int main()
{
	const int ROWS = row;
    const int COLS = column;
    piano_t playground = (piano_t) malloc(ROWS*COLS*sizeof(casella_t));
    /* inizializzare */
    init(playground, ROWS, COLS);

    stampa(playground, ROWS, COLS);

    printf("\n\n");
    return 0;
}
