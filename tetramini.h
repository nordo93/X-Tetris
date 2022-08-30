/** @page 
* pezzi di Tetris: I, J, L, O, S, T, Z
* Logica del gioco
* immagine tetramini posizione 0 : https://upload.wikimedia.org/wikipedia/commons/3/39/Tetrominoes_IJLO_STZ_Worlds.svg
*/

/**@{*//** @brief definisco il numero di righe e colonne
 * @def row è il numero di righe
 * @def column è il numero di colonne
 * @def size indica la grandezza del vettore di ogni tetramino */
#define row 15
#define column 10
#define size 4 /**@}*

/*
 * 0 = nessun blocco presente
 *                  #
 * # 1 = 1 bloccho  # 2 = 2 blocchi sovrapposti
 *
 * #            
 * #                             #
 * # 3 = 3 blocchi sovrapposti   0  4 = un posto vuoto con blocco sopra                         
 *
 * #                                                   #
 * 0                                                   #
 * 0 5 =due posti vuoti sovrapposti con blocco sopra   0 6 = un posto vuoto con due blocchi sopra
 * 
 * #
 * #
 * #
 * # 7 = 4 blocchi sovrapposti
 */

/**@{*//** Differenti versioni del tetramino I
* @param I_free quanti tetramino I sono disponibili
* @param I_ tetramino i in posizione base
* @param I_180 tetramino i in posizione verticale
*/
int I_free = 20; /*Indico quanti pezzi sono disponibili di I*/
int I_[size]={1,1,1,1};
int I_180[size]={7,0,0,0};/**@}*/

/**@{*//** Differenti versioni del tetramino J
* @param J_free quanti tetramino J sono disponibili
* @param J_ tetramino J in posizione base
* @param J_90 tetramino J ruotata di 90 gradi
* @param J_180 tetramino J ruotata di 180 gradi
* @param J_270 tetramino J ruotata di 270 gradi*/
int J_free = 20;
int J_[size]={2,1,1,0};
int J_90[size]={3,5,0,0};
int J_180[size]={4,4,2,0};
int J_270[size]={1,3,0,0};/**@}*/

/**@{*//** Differenti versioni del tetramino L
 * @param L_free quanti tetramino L sono disponibili
 * @param L_ tetramino L in posizione base 
 * @param L_90 tetramino L ruotata di 90 gradi
 * @param L_180 tetramino L ruotata di 180 gradi
 * @param L_270 tetramino L ruotata di 270 gradi */
int L_free = 20;
int L_[size]={1,1,2,0};
int L_90[size]={3,1,0,0};
int L_180[size]={2,4,4,0};
int L_270[size]={5,3,0,0};/**@}*/

/**@{*//** Differenti versioni del tetramino O.
 * @param O_free Tetramini O disponibili 
 * @param O_ tetramino O in posizione base*/
int O_free = 20;
int O_[size]={2,2,0,0};/**@}*/

/**@{*//** Differenti versioni del tetramino S.
 * @param S_free Tetramini S disponibili 
 * @param S_ tetramino S in posizione base
 * @param S_90 tetramino S ruotata di 90 gradi*/
int S_free = 20;
int S_[size]={1,2,4,0};
int S_90[size]={6,2,0,0};/**@}*/

/**@{*//** Differenti versioni del tetramino T
 * @param T_free Tetramini T disponibili
 * @param T_ tetramino T in posizione base
 * @param T_90 tetramino T ruotata di 90 gradi
 * @param T_180 tetramino T ruotata di 180 gradi
 * @param T_270 tetramino T ruotata di 270 gradi */
int T_free = 20;
int T_[size]={1,2,1,0};
int T_90[size]={3,4,0,0};
int T_180[size]={4,2,4,0};
int T_270[size]={4,3,0,0};/**@}*/

/**@{*//** Differenti versioni del tetramino Z.
 * @param Z_free Tetramini Z disponibili 
 * @param Z_ tetramino Z in posizione base
 * @param Z_90 tetramino Z ruotata di 90 gradi*/
int Z_free = 20;
int Z_[size]={4,2,1,0};
int Z_90[size]={2,6,0,0};/**@}*/


