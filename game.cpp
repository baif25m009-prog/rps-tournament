#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Forward declarations
void saveResult(string result);
void showResults();

// Get choice from a player
int getChoice(string playerName)
{
    int choice;

    cout << playerName << " enter your choice (1=Rock, 2=Paper, 3=Scissors): ";
    cin >> choice;

    while (choice < 1 || choice > 3)
    {
        cout << "Invalid! Enter 1, 2 or 3: ";
        cin >> choice;
    }

    return choice;
}

// Play one match - if draw, match repeats
string playMatch(string player1, string player2)
{
    cout << "\n" << player1 << " VS " << player2 << endl;

    int choice1 = getChoice(player1);
    int choice2 = getChoice(player2);

    if (choice1 == 1) cout << player1 << " chose Rock" << endl;
    else if (choice1 == 2) cout << player1 << " chose Paper" << endl;
    else cout << player1 << " chose Scissors" << endl;

    if (choice2 == 1) cout << player2 << " chose Rock" << endl;
    else if (choice2 == 2) cout << player2 << " chose Paper" << endl;
    else cout << player2 << " chose Scissors" << endl;

    if (choice1 == choice2)
    {
        cout << "Draw! Match is replaying..." << endl;
        return playMatch(player1, player2);
    }
    else if ((choice1 == 1 && choice2 == 3) ||
             (choice1 == 3 && choice2 == 2) ||
             (choice1 == 2 && choice2 == 1))
    {
        cout << "Winner: " << player1 << endl;
        return player1;
    }
    else
    {
        cout << "Winner: " << player2 << endl;
        return player2;
    }
}

// Print trophy using for loops
void printTrophy(string champion)
{
    // Trophy cup - getting smaller each line
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 10 - (i * 2); j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // Trophy stem
    for (int i = 0; i < 3; i++)
    {
        cout << "    *" << endl;
    }

    // Trophy base
    for (int i = 0; i < 10; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout << "\nChampion: " << champion << endl;
    cout << "Congratulations! You've won 5 Solid Marks in PF sessionals." << endl;
    cout << endl << "Press Enter to exit...";
    cin.ignore();
     cin.get();
}

// Run full tournament
void runTournament(string players[])
{
    string qfWinners[4];
    string sfWinners[2];
    string champion;

    // Randomly shuffle players
    for (int i = 7; i > 0; i--)
    {
        int j = rand() % (i + 1);
        string temp = players[i];
        players[i] = players[j];
        players[j] = temp;
    }

    // Quarter Finals
    cout << "\n--- QUARTER FINALS ---" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "\nQuarter Final Match " << i + 1 << endl;
        qfWinners[i] = playMatch(players[i * 2], players[i * 2 + 1]);
        saveResult("QF Match " + to_string(i + 1) + ": " + players[i * 2] + " vs " + players[i * 2 + 1] + " --> Winner: " + qfWinners[i]);
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    // Shuffle QF winners for semi finals
    for (int i = 3; i > 0; i--)
    {
        int j = rand() % (i + 1);
        string temp = qfWinners[i];
        qfWinners[i] = qfWinners[j];
        qfWinners[j] = temp;
    }

    // Semi Finals
    cout << "\n--- SEMI FINALS ---" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "\nSemi Final Match " << i + 1 << endl;
        sfWinners[i] = playMatch(qfWinners[i * 2], qfWinners[i * 2 + 1]);
        saveResult("SF Match " + to_string(i + 1) + ": " + qfWinners[i * 2] + " vs " + qfWinners[i * 2 + 1] + " --> Winner: " + sfWinners[i]);
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    // Grand Final
    cout << "\n--- GRAND FINAL ---" << endl;
    champion = playMatch(sfWinners[0], sfWinners[1]);
    saveResult("Final: " + sfWinners[0] + " vs " + sfWinners[1] + " --> Winner: " + champion);

    // Show all results
    showResults();

    // Print trophy
    printTrophy(champion);
}