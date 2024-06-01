#include <iostream>
#include <cstring>
using namespace std;

typedef struct passenger_s
{
    string name;
    char seat_number[3];
    char flight_number[6];
    string departure_date;
    char departure_time[9];
    struct passenger_s *linkp;
}passenger_t;

passenger_t *Passenger, *prevp, *newp;

void showall(passenger_t *headp)
{
    while (headp != nullptr)
    {
        headp = (*headp).linkp;
        if (headp != nullptr)
        {
            cout << (*headp).name << endl;
            cout << (*headp).seat_number << endl;
            cout << (*headp).flight_number << endl;
            cout << (*headp).departure_date << endl;
            cout << (*headp).departure_time << endl;
            cout << endl;
        }
    }
}

void adding()
{
    newp = new passenger_t;
    (*newp).name = "John Kennedy";
    strcpy((*newp).seat_number, "5D");
    strcpy((*newp).flight_number, "AB123");
    (*newp).departure_date = "12/08/23";
    strcpy((*newp).departure_time, "14:30:30");
    (*prevp).linkp = newp;
    prevp = newp;

    newp = new passenger_t;
    (*newp).name = "Jacky Kennedy";
    strcpy((*newp).seat_number, "5F");
    strcpy((*newp).flight_number, "AB123");
    (*newp).departure_date = "12/08/23";
    strcpy((*newp).departure_time, "14:30:30");
    (*prevp).linkp = newp;
    prevp = newp;
    (*prevp).linkp = nullptr;
}

void search(passenger_t *headp)
{
    string input;
    cout << "Input search: ";
    cin >> input;
    passenger_t *current = headp;
    
    while(current != nullptr)
    {
        if ((*current).seat_number == input)
        {
            cout << (*current).name << endl;
            break;
        }
        current = current->linkp;
    }
    
    if (current == nullptr)
    {
        cout << "Passenger not found." << endl;
    }
}

void Remove(passenger_t *headp)
{
    passenger_t *current = headp;
    passenger_t *prev = nullptr;
    string NameRemove;
    NameRemove = "Jacky Doe";

    while (current != nullptr && (*current).name != NameRemove)
    {
        prev = current;
        current = (*current).linkp;
    }

    if (current == nullptr)
    {
        cout << "Passenger " << NameRemove << " not found." << endl;
        return;
    }

    if (prev == nullptr)
    {
        headp = (*current).linkp;
    }
    else
    {
        prev->linkp = (*current).linkp;
    }

    cout << "Passenger " << NameRemove << " has been removed." << endl;
}

int main()
{
    system("cls");
    Passenger = new passenger_t;
    prevp = Passenger;
    newp = new passenger_t;
    (*newp).name = "John Doe";
    strcpy((*newp).seat_number, "1A");
    strcpy((*newp).flight_number, "AB123");
    (*newp).departure_date = "12/08/23";
    strcpy((*newp).departure_time, "14:30:30");
    (*prevp).linkp = newp;
    prevp = newp;

    newp = new passenger_t;
    (*newp).name = "Jane Doe";
    strcpy((*newp).seat_number, "1B");
    strcpy((*newp).flight_number, "AB123");
    (*newp).departure_date = "12/08/23";
    strcpy((*newp).departure_time, "14:30:30");
    (*prevp).linkp = newp;
    prevp = newp;

    newp = new passenger_t;
    (*newp).name = "Jacky Doe";
    strcpy((*newp).seat_number, "1C");
    strcpy((*newp).flight_number, "AB123");
    (*newp).departure_date = "12/08/23";
    strcpy((*newp).departure_time, "14:30:30");
    (*prevp).linkp = newp;
    prevp = newp;


    adding();

    showall(Passenger);

    search(Passenger);
    cout << endl;

    Remove(Passenger);

    showall(Passenger);
    



    return 0;
}