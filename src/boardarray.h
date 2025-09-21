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

    void add(Entry *entry)
    {
        // TODO: IMPLEMENT THIS FUNCTION
        // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT

        int pos = index;

        if(index == SIZE){
            if(!entry->compare(array[SIZE - 1])){ 
                cout << entry->name << "'s score is too low to be added!" << endl;
                return;
            }
        }

        for (int i = 0; i < index; i++)
        {
            if (entry->compare(array[i]))
            {
                pos = i;
                break;
            }
        }

        for (int i = index; i > pos; i--) { // shift right
            array[i] = array[i - 1];
        }
        array[pos] = *entry;
        index++;

        
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