#include <iostream>
#include <cstdio>

int fire()
{
    int co1, co2;
    int hits = 0;
    int misses = 0;
    std::string hit = ") was a hit!";
    std::string miss = ") was a miss!";
    std::cout << "Enter First Coordinate:\n";
    std::cin >> co1;
    std::cout << "Enter second Coordinate:\n";
    std::cin >> co2;

    switch (co1)
    {
    case 0:
        switch (co2)
        {
        case 0:
            std::cout << "Coordinate (" << co1 << "," << co2 << miss << std::endl;
            ++misses;
            break;
        case 1:
            std::cout << "Coordinate (" << co1 << "," << co2 << miss << std::endl;
            ++misses;
            break;
        case 2:
            std::cout << "Coordinate (" << co1 << "," << co2 << miss << std::endl;
            ++misses;
            break;
        default:
            std::cout << "Please enter valid coordinate" << std::endl;
        }
        break;
    case 1:
        switch (co2)
        {
        case 0:
            std::cout << "Coordinate (" << co1 << "," << co2 << miss << std::endl;
            ++misses;
            break;
        case 1:
            std::cout << "Coordinate (" << co1 << "," << co2 << hit << std::endl;
            ++hits;
            break;
        case 2:
            std::cout << "Coordinate (" << co1 << "," << co2 << hit << std::endl;
            ++hits;
            break;
        default:
            std::cout << "Please enter valid coordinate" << std::endl;
        }
        break;
    case 2:
        switch (co2)
        {
        case 0:
            std::cout << "Coordinate (" << co1 << "," << co2 << miss << std::endl;
            ++misses;
            break;
        case 1:
            std::cout << "Coordinate (" << co1 << "," << co2 << miss << std::endl;
            ++hits;
            break;
        case 2:
            std::cout << "Coordinate (" << co1 << "," << co2 << hit << std::endl;
            ++hits;
            break;
            break;
        default:
            std::cout << "Please enter valid coordinate" << std::endl;
        }
    default:
        std::cout << "Please enter valid coordinate" << std::endl;
    }
    int turns = hits + misses;
    std::cout << "You took " << turns << " turns!\n"
              << "You got " << hits << " hits!\n"
              << "You got " << misses << " misses!" << std::endl;
    return 0;
}

void board()
{
    std::string board = "   0     1     2\n      |     |     \n0  -  |  -  |  -  \n _____|_____|_____\n      |     |     \n1  -  |  B  |  B  \n _____|_____|_____\n      |     |     \n2  -  |  -  |  B  \n      |     |     ";
    std::cout << board << std::endl;
}

int main()
{
    system("CLS");
    board();
    fire();
    std::getchar();

    return 0;
}