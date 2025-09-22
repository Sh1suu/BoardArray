#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board
{
    Entry *array;
    int index;

public:
    BoardArray()
    {
        array = new Entry[SIZE];
        index = 0;
    }

    void add(Entry* entry) {

    int pos = index; 
    for (int i = 0; i < index; ++i) {
        if (entry->compare(&array[i])) {
            pos = i;
            break;
        }
    }

    if (index == SIZE && !entry->compare(&array[SIZE - 1])) { //full and not higher than last
        cout << entry->name << "'s score is too low to be added!" << endl;
        return;
    }

    int limit = (index < SIZE) ? index : SIZE - 1;

    for (int j = limit; j > pos; --j) { //shift right
        array[j] = array[j - 1];
    }

    array[pos] = *entry;

    if (index < SIZE) {
        ++index;
    }
}
        
    

    void print()
    {
        for (int i = 0; i < index; i++)
        {
            cout << i + 1 << ". ";
            array[i].print();
        }
    }
};