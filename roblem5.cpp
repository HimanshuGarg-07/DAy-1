#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Player
{
private:
    string name;
    int matchesPlayed;
    double battingAverage;
    bool injured;

public:

    Player(string name, int matchesPlayed,
           double battingAverage, bool injured)
    {
        this->name = name;
        this->matchesPlayed = matchesPlayed;
        this->battingAverage = battingAverage;
        this->injured = injured;
    }

    static bool isDraftable(int matchesPlayed)
    {
        return matchesPlayed >= 10;
    }

    static bool isDraftable(int matchesPlayed, bool injured)
    {
        return matchesPlayed >= 5 && injured == false;
    }

    double getFantasyPoints() const
    {
        return battingAverage;
    }

    string getName() const
    {
        return name;
    }

    int getMatchesPlayed() const
    {
        return matchesPlayed;
    }

    bool getInjured() const
    {
        return injured;
    }

    bool operator<(const Player& other) const
    {
        return this->getFantasyPoints() >
               other.getFantasyPoints();
    }
};

string draftAndRank(Player players[], int n)
{
    Player* draftable[500];

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (Player::isDraftable(players[i].getMatchesPlayed()) ||
            Player::isDraftable(players[i].getMatchesPlayed(),
                                players[i].getInjured()))
        {
            draftable[count] = &players[i];
            count++;
        }
    }

    sort(draftable, draftable + count,
         [](Player* a, Player* b)
         {
             return *a < *b;
         });

    string result = "";

    for (int i = 0; i < count; i++)
    {
        result += to_string(i + 1)
                + ". "
                + draftable[i]->getName();

        if (i < count - 1)
        {
            result += " | ";
        }
    }

    return result;
}

int main()
{
    Player players[] = {
        Player("Virat", 15, 48.0, false),
        Player("Rahul", 7, 55.0, false),
        Player("Sameer", 3, 60.0, false),
        Player("Dev", 12, 20.0, true)
    };

    int n = 4;

    cout << draftAndRank(players, n) << endl;

    return 0;
}