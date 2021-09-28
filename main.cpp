#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

int main()
{
    // create a handle to the computer screen
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    // declare vars
    std::string playerOneName, playerTwoName, playerOneRollType, playerTwoRollType, winner = "";
    int playerOneRoll, playerTwoRoll, playerOneColor, playerTwoColor;
    // seed number generator
    srand(time(0));
    // roll for players
    playerOneRoll = rand() % 20 + 1;
    playerTwoRoll = rand() % 20 + 1;
    // get user input names
    std::cout << "Please Input Player Ones Name: ";
    std::cin >> playerOneName;
    std::cout << "\nPlease Input Player Twos Name: ";
    std::cin >> playerTwoName;
    // set roll types
    if (playerOneRoll == 1)
        playerOneRollType = "Critical Failure";
    if (playerTwoRoll == 1)
        playerTwoRollType = "Critical Failure";
    if (playerOneRoll == 20)
        playerOneRollType = "Critical Success";
    if (playerTwoRoll == 20)
        playerTwoRollType = "Critical Success";
    // set player roll colors
    playerOneColor = (playerOneRollType == "Critical Failure") ? 4 : (playerOneRollType == "Critical Success") ? 2 : 7;
    playerTwoColor = (playerTwoRollType == "Critical Failure") ? 4 : (playerTwoRollType == "Critical Success") ? 2 : 7;
    // check for winner
    winner = (playerOneRoll == playerTwoRoll)
                 ? "Evenly Matched"
             : (playerOneRoll > playerTwoRoll)
                 ? playerOneName
                 : playerTwoName;
    // output details of rolls
    std::cout << "\n<===============================>\n";
    std::cout << "| Player One: " << playerOneName << ", rolled a " << playerOneRoll << " ";
    // handle output color for player one
    SetConsoleTextAttribute (screen, playerOneColor);
    std::cout << playerOneRollType << std::endl;
    // reset color
    SetConsoleTextAttribute (screen, 7);
    std::cout << "| Player Two: " << playerTwoName << ", rolled a " << playerTwoRoll << " ";
    // handle output color for player two
    SetConsoleTextAttribute (screen, playerTwoColor);
    std::cout << playerTwoRollType << std::endl;
    // reset color
    SetConsoleTextAttribute (screen, 7);
    std::cout << "<================================>\n";
    std::cout << "|\n";
    std::cout << "| The Winner Is: " << winner << "\n";
    std::cout << "|\n";
    std::cout << "<================================>\n";
}