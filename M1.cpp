#include <iostream>
#include <string>

using namespace std;

class BookInventory
{
public:
    string title;
    string author;
    int copiesAvailable;

    BookInventory(string title, string author, int copiesAvailable)
    {
        this->title = title;
        this->author = author;
        this->copiesAvailable = copiesAvailable;
    }

    void printEntry()
    {
        cout << title << " by " << author
             << " - " << copiesAvailable
             << " copies available" << endl;
    }
};

int main()
{
    BookInventory books[] = {
        BookInventory("Clean Code", "Robert C. Martin", 3),
        BookInventory("Effective Java", "Joshua Bloch", 5),
        BookInventory("Refactoring", "Martin Fowler", 0),
        BookInventory("Design Patterns", "GoF", 2)
    };

    int n = 4;

    for (int i = 0; i < n; i++)
    {
        books[i].printEntry();
    }

    return 0;
}