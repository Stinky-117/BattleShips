#include <iostream>
#include <cstdlib>
#include <ctime>

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
        boats[xr][yr] = 'B';
        std::cout << "Test " << xr << " " << yr << std::endl;
        std::cout << boats[xr][yr] << std::endl;
    }
}

void fire(char board[5][5], char boats[5][5])
{
    int x, y;
    std::cout << "Enter first coordinate\n";
    std::cin >> x;
    std::cout << "Enter second coordinate\n";
    std::cin >> y;
    if (boats[x][y] == 'B')
    {
        board[x][y] = 'X';
        std::cout << "Hit\n";
    }
    else
    {
        board[x][y] = 'M';
        std::cout << "Miss\n";
    }
    print_board(board);
}

int main()
{
    system("CLS");
    srand(static_cast<unsigned int>(time(0)));
    char board[5][5];
    char boats[5][5];
    init_board(board);
    init_board(boats);
    print_board(board);
    place_ship(board);
    fire(board, boats);
    std::cout << boats[0][0];
}