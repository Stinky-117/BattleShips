#include <iostream>
#include <cstdlib>
#include <ctime>

void init_board(char board[5][5])
{
    // Initialize the board with water '~'
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = '~'; // Set each cell to '~'
        }
    }
}

// Function to print the board to the console
void print_board(char board[5][5])
{
    std::cout << "    0   1   2   3   4\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << "   ";
        for (int j = 0; j < 5; j++)
        {
            std::cout << board[i][j] << "   "; // Print the board's current state
        }
        std::cout << "\n"
                  << std::endl;
    }
}

void place_ship(char boats[5][5])
{
    int ux;
    std::cout << "How many ships do you want placed?\n";
    std::cin >> ux;
    for (int i = 0; i < ux; i++)
    {
        int xr = rand() % 5;
        int yr = rand() % 5;
        if (boats[xr][yr] == 'B')
        {
            i--;
        }
        else
        {
            boats[xr][yr] = 'B'; // Place a ship on the boats array
            std::cout << "Ship placed at (" << xr << ", " << yr << ")\n";
        }
    }
}

void fire(char board[5][5], char boats[5][5])
{
    int x, y;
    int hits, misses;
    std::cout << "Enter first coordinate (row):\n";
    std::cin >> x;
    std::cout << "Enter second coordinate (column):\n";
    std::cin >> y;

    if (boats[x][y] == 'B') // Check the boats array to see if there's a ship
    {
        board[x][y] = 'X'; // Mark a hit on the board array
        std::cout << "Hit\n";
        hits++;
    }
    else
    {
        board[x][y] = 'M'; // Mark a miss on the board array
        std::cout << "Miss\n";
        misses++;
    }

    print_board(board); // Print the updated board
}

void reveal_boats(char boats[5][5])
{
    std::cout << "    0   1   2   3   4\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << "   ";
        for (int j = 0; j < 5; j++)
        {
            std::cout << boats[i][j] << "   "; // Print the board's current state
        }
        std::cout << "\n"
                  << std::endl;
    }
}

int main()
{
    system("CLS");
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    char board[5][5];
    char boats[5][5];
    int hits = 0;
    int misses = 0;

    // Initialize both the board and the boats array
    init_board(board);
    init_board(boats);

    // Print the initial state of the board
    print_board(board);

    // Place ships randomly on the boats array
    place_ship(boats);

    // Allow the player to fire at the board
    fire(board, boats);

    reveal_boats(boats);

    return 0;
}
