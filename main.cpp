#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Forward declaration
void runTournament(string players[]);

int main()
{
    // Set random seed
    srand(time(0));

    string players[8];

    cout << "Welcome to Rock Paper Scissors Tournament" << endl;
    cout << "Please enter the names of 8 players" << endl;

    // Take 8 player names from user
    for (int i = 0; i < 8; i++)
    {
        cout << "Player " << i + 1 << " name: ";
        cin >> players[i];
    }

    // Show registered players
    cout << endl <<"Registered Players:" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". " << players[i] << endl;
    }

    cout << endl << "Press Enter to start the tournament...";
    cin.ignore();
    cin.get();

    // Start tournament
    runTournament(players);

    return 0;
}