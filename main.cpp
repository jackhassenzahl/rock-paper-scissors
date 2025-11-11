#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <cctype>

using namespace std;

//  function to compare lower case strings
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return static_cast<char>(std::tolower(c)); });
    return s;
}
int main()
{
    int wins = 0;
    int losses = 0;
    int ties = 0;
    int games = 0;
    string input;
    system("cls");

    cout << "Welcome to Rock, Paper, Scissors\n";
    cout << "Can you win?\n\n";

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);

    // user can enter a string, and it checks if the choice is contained
    // if the user enters "rock scissorspaper ExIT", the code would exit because that is checked first
    while (true)
    {
        games = wins + losses + ties;
        cout << wins << '/' << losses << '/' << ties << "\n\n";

        cout << "Rock, paper, or scissors?\n";
        int computerChoice = dist(gen);

        if (!getline(cin, input))
        {
            cout << "Input closed. Exiting.\n";
            break;
        }

        string low = toLower(input);

        //  if user types exit, end the program
        if (string::npos != low.find("exit"))
        {
            system("cls");
            cout << "Exiting, have a nice day!";
            break;
        }

        // 0 = rock
        // 1 = paper
        // 2 = scissors

        // if user enters rock
        else if (string::npos != low.find("rock"))
        {
            if (computerChoice == 1)
            {
                cout << "The computer chose paper. You lose!\n";
                losses++;
            }

            else if (computerChoice == 2)
            {
                cout << "The computer chose scissors. You win!\n";
                wins++;
            }

            else if (computerChoice == 0)
            {
                cout << "The computer chose rock. It's a tie!\n";
                ties++;
            }
        }

        // if user enters paper
        else if (string::npos != low.find("paper"))
        {
            if (computerChoice == 1)
            {
                cout << "The computer chose paper. It's a tie!\n";
                ties++;
            }

            else if (computerChoice == 2)
            {
                cout << "The computer chose scissors. You lose!\n";
                losses++;
            }

            else if (computerChoice == 0)
            {
                cout << "The computer chose rock. You win!\n";
                wins++;
            }
        }

        // if user enters scissors
        else if (string::npos != low.find("scissors"))
        {
            if (computerChoice == 1)
            {
                cout << "The computer chose paper. You win!\n";
                wins++;
            }

            else if (computerChoice == 2)
            {
                cout << "The computer chose scissors. It's a tie!\n";
                ties++;
            }

            else if (computerChoice == 0)
            {
                cout << "The computer chose rock. You lose!\n";
                losses++;
            }
        }

        else if (string::npos != low.find("clear"))
        {
            system("cls");
        }

        else
        {
            cout << "Unrecognized input. Type rock, paper, scissors or exit.\n";
            continue;
        }
    }
}