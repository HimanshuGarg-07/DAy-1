#include <iostream>
#include <string>

using namespace std;

class HallTicket
{
public:
    string studentName;
    int seatNumber;

    HallTicket(string studentName, int seatNumber)
    {
        this->studentName = studentName;
        this->seatNumber = seatNumber;
    }
};

int main()
{
    HallTicket priya("Priya", 0);

    HallTicket* copy = &priya;

    copy->seatNumber = 45;

    HallTicket separate("Priya", 45);

    cout << "Priya's seatNumber (via first variable): "
         << priya.seatNumber << endl;

    cout << "copy == priya: "
         << boolalpha << (copy == &priya) << endl;

    cout << "separate == priya: "
         << ( &separate == &priya ) << endl;

    return 0;
}