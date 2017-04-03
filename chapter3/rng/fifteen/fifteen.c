/**
 * fifteen.c
 *
 * CS50 AP
 * Austen van der Byl
 * austen.vanderbyl@aupschool.org
 * 
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
// necessary for usleep
#define _XOPEN_SOURCE 500

// libraries to include
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// globally declared board
int board[DIM_MAX][DIM_MAX];

// globally declared board dimension
int d;
int m;
int n;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // Confirms that the correct number of inputs has been entered
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Check that the dimensions are correct and prints correct usage otherwise
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    else
    {
        m = (d - 1);
        n = (d - 1);
    }

    // open log file to record moves
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greets the player
    greet();

    // Initiates the board with tiles d * d - 1
    init();

    // accept moves until game is won
    while (true)
    {
        // Clears screen using ANSI escape sequences.
        clear();

        // Draws out the board depending on what input the user has entered
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Prints to console if the board is in winning configuration
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // Asks user which tile to move and Gets that input
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Prints Illegal move if the user tries to move a tile that doesn't 
        // Border an empty space
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // "Sleeps"/stops the program for 500000 micro seconds
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // Indicates that the program executed correctly
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // Counter for how much should be subtracted from d to print correct value
    int value = 0;
    
    // Itterates over the number of rows, d
    for(int i = 0; i < d; i++)
    {
        // Itterates over the number of colloums, d
        for(int x = 0; x < d; x++)
        {
            // Increments counter and assignes values to board
            value = value + 1;
            board[i][x] = ((d * d) - value);
        }
    }
    
    // Deals with boards with odd number of tiles
    if (d % 2 == 0)
    {
        // Stores a temporary value to switch out numbers when if is met
        int boardSwitch = board[d - 1][d - 2];
        // Preformes the switch
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = boardSwitch;
    }
}

/**
 * int temp = dog
 * dog = cat
 * cat = temp
 * Prints the board in its current state.
 */
void draw(void)
{
    // Itterates over the number of rows, d
    for(int i = 0; i < d; i++)
    {
        // Itterates over the number of rows, d
        for(int x = 0; x < d; x++)
        {
            // Prints the blank space
            if (board[i][x] == 0)
            {
                printf(" |  _");
            }
            else
            {
                // Prints all the numbers
                printf(" | %2d", board[i][x]);
            }
        }
        // Prints a new line
        printf(" |\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
 
 // Needs to search (iterate over everything to look for)then use swaping method
bool move(int tile)
{
    // Goes through rows
    for (int i = 0; i < d; i++) 
    {
        // Gos through columns
        for (int x = 0; x < d; x++) 
        {
            // Checks if tile is equal to the current location on the board
            if (tile == board[i][x]) 
            {
                // Initiaes the blanktile as a varible
                int clearTile = 0;       
 
                // Makes sure that tile is next to clearTile
                if (((m == (i - 1)) && (x == n)) || ((m == (i + 1)) && (x == n))
                || ((i == m) && (n == (x - 1))) || ((i == m) && (n == (x + 1))))
                {
                    // Preformes swap and updates varibles
                    board[m][n] = tile;
                    board[i][x] = clearTile;
                    m = i;
                    n = x;
                    return true;
                }   
            } 
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
 // Either change order you're counting in or change _ tile to d * d
bool won(void)
{
    // Sets the counter in order to check how many tiles are in the right place
    int lastTile = (d * d - 1);
    // Number to compade current tile against
    int currentTile = 1;
    // Loops over rows
    for(int i = 0; i < d; i++)
    {
        // Loops over collums
        for(int x = 0; x < d; x++)
        {
            // Increases the currentTile value if tile is in right place
            if (board[i][x] == currentTile && currentTile <= lastTile)
            {
                currentTile++;
            }
            // Game is in winning formation
            else if(lastTile < currentTile)
            {
                return true;
            }
        }
    }
    return false;
}