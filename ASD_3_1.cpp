#include <iostream>
#include <cstring>
using namespace std;

typedef struct
{
    string name;
    char seat_number[3];
    char flight_number[6];
    string departure_date;
    char departure_time[9];
}passenger_t;

passenger_t Passenger;
int hours, minutes, sec;

void late()
{
    minutes += 45;
    hours += minutes / 60;
    minutes %= 60;
    hours %= 24;

    sprintf(Passenger.departure_time, "%d:%d:%d", hours, minutes, sec);
}

void show()
{
    cout << Passenger.name << endl;
    cout << Passenger.seat_number << endl;
    cout << Passenger.flight_number << endl;
    cout << Passenger.departure_date << endl;
    cout << Passenger.departure_time << endl;
}

int main()
{
    Passenger.name = "John Doe";
    strcpy(Passenger.seat_number, "1A");
    strcpy(Passenger.flight_number, "AB123");
    Passenger.departure_date = "12/08/23";
    sscanf("14:30:00", "%d:%d:%d", &hours, &minutes, &sec);

    late();
    show();


    return 0;
}