#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype> // for tolower()

// Initialize the board with water '~'
void init_board(char board[5][5])
{
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
        std::cout << "\n";
    }
}

// Function to place ships on the boats array
void place_ship(char boats[5][5], int ship_count)
{
    for (int i = 0; i < ship_count; i++)
    {
        int x, y;
        do
        {
            x = rand() % 5; // Random row
            y = rand() % 5; // Random column
        } while (boats[x][y] == 'B'); // Ensure no ship is already placed here

        boats[x][y] = 'B'; // Place a ship
    }
}

// Function to handle a fire action
void fire(char board[5][5], char boats[5][5], int &hits, int &misses)
{
    int x, y;
    std::cout << "Enter first coordinate (row):\n";
    std::cin >> x;
    std::cout << "Enter second coordinate (column):\n";
    std::cin >> y;

    // Ensure coordinates are within bounds
    if (x < 0 || x >= 5 || y < 0 || y >= 5)
    {
        std::cout << "Invalid coordinates! Please enter values between 0 and 4.\n";
        return; // Let the user try again
    }
    system("CLS");
    if (boats[x][y] == 'B')
    {                      // Check if there's a ship
        board[x][y] = 'X'; // Mark a hit
        std::cout << "Hit!\n";
        hits++;
    }
    else
    {
        board[x][y] = 'M'; // Mark a miss
        std::cout << "Miss!\n";
        misses++;
    }

    print_board(board); // Print the updated board
}

// Function to check if the game is over (i.e., all ships are hit)
bool game_over(int total_ships, int hits)
{
    return hits == total_ships;
}

int main()
{
    system("CLS");
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    char board[5][5];
    char boats[5][5];
    int hits = 0, misses = 0;

    // Splash screen
    std::string splash_screen = " _____       _    _    _         _____  _    _           \n| __  | ___ | |_ | |_ | | ___   |   __|| |_ |_| ___  ___ \n| __ -|| .'||  _||  _|| || -_|  |__   ||   || || . ||_ -|\n|_____||__,||_|  |_|  |_||___|  |_____||_|_||_||  _||___|\n                                               |_|";
    std::cout << splash_screen << "\n";

    // Ask how many ships to place
    int ship_count;
    std::cout << "How many ships do you want placed?\n";
    std::cin >> ship_count;

    // Initialize both the board and the boats array
    init_board(board);
    init_board(boats);

    // Print the initial state of the board
    print_board(board);

    place_ship(boats, ship_count);

    // Play the game until all ships are hit
    while (!game_over(ship_count, hits))
    {
        fire(board, boats, hits, misses);
    }

    // End of the game
    std::cout << "Game over! You sank all the ships!\n";
    std::cout << "Turns: " << hits + misses << "\nHits: " << hits << "\nMisses: " << misses << std::endl;

    return 0;
}
