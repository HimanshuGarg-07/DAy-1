#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

string playRound(string playerMove, string computerMove)
{
    if (playerMove == computerMove)
    {
        return "Draw";
    }
    if ((playerMove == "Rock" && computerMove == "Scissors") ||
        (playerMove == "Paper" && computerMove == "Rock") ||
        (playerMove == "Scissors" && computerMove == "Paper"))
    {
        return "Player Wins";
    }

    return "Computer Wins";
}

int main()
{
    srand(time(0));

    string moves[3] = {"Rock", "Paper", "Scissors"};

    string playerMove[5];
    string computerMove[5];
    string result[5];

    int wins = 0;
    int losses = 0;
    int draws = 0;

    cout << "===== ROCK-PAPER-SCISSORS GAME =====" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nRound " << i + 1 << endl;

        cout << "Enter your move (Rock/Paper/Scissors): ";
        cin >> playerMove[i];

        int randomNumber = rand() % 3;

        computerMove[i] = moves[randomNumber];

        result[i] = playRound(
            playerMove[i],
            computerMove[i]
        );

        cout << "Computer Move: "
             << computerMove[i] << endl;

        cout << "Result: "
             << result[i] << endl;

        if (result[i] == "Player Wins")
        {
            wins++;
        }
        else if (result[i] == "Computer Wins")
        {
            losses++;
        }
        else
        {
            draws++;
        }
    }

    cout << "\n\n===== FINAL SUMMARY =====" << endl;

    cout << left
         << setw(10) << "Round"
         << setw(15) << "Player Move"
         << setw(15) << "Computer Move"
         << setw(20) << "Result"
         << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << left
             << setw(10) << i + 1
             << setw(15) << playerMove[i]
             << setw(15) << computerMove[i]
             << setw(20) << result[i]
             << endl;
    }

    double winPercentage = (wins / 5.0) * 100;

    cout << "\nWins   : " << wins << endl;
    cout << "Losses : " << losses << endl;
    cout << "Draws  : " << draws << endl;

    cout << fixed << setprecision(1);
    cout << "Win %  : " << winPercentage << "%" << endl;

    return 0;
}