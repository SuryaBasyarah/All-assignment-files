#include <iostream>
#include <cstring>
using namespace std;

typedef struct song_s
{
    string name;
    string singer;
    string album;
    string duration;
    song_s *nextp;

}song_t;

song_t* AddSong(song_t* last, string tname, string tsinger, string talbum, string tduration)
{
        song_t* Song = new song_t;
        Song->name = tname;
        Song->singer = tsinger;
        Song->album = talbum;
        Song->duration = tduration;
        if (last == nullptr)
        {
            Song->nextp = Song;
            last = Song;
        }
        else
        {
            Song->nextp = last->nextp;
            last->nextp = Song;
            last = Song;
        }
        cout << endl;
    return last;
}

void ShowSong(song_t* last)
{
    char Status;
    if (last == nullptr)
    {
        cout << "No Song Yet." << endl;
    }
    else
    {
        song_t* current = last->nextp;
        do
        {
            cout << "Song Name: " << current->name << endl;
            cout << "Singer Name: " << current->singer << endl;
            cout << "Album Name: " << current->album << endl;
            cout << "Duration: " << current->duration << endl;
            cout << endl;
            cout << "Continue? (y/n): ";
            cin >> Status;
            if (Status != 'y')
            {
                break;
            }
            current = current->nextp;
        } while ((current != last->nextp) || Status == 'y');
    }
    
}

song_t* Delete(song_t* last, const char* TargetDelete)
{
    song_t* current = last->nextp;
    while (current->nextp != last)
    {
        if (current->nextp->name == TargetDelete)
        {
            song_t* DeleteSong = current->nextp;
            current->nextp = DeleteSong->nextp;
            if (DeleteSong == last)
            {
                last = current;
            }
            delete DeleteSong;
            return last;
        }
        current = current->nextp;
    }
}


int main()
{
    song_t* last = nullptr;
    last = AddSong(last, "Under Heroine", "TUYU", "Under Mentality", "02:49");
    last = AddSong(last, "If There Was An Endpoint", "TUYU", "I'll put you in misery", "02:58");
    last = AddSong(last, "Jurus Rahasia Teleport", "JKT48", "Pajama Drive", "03:41");
    last = AddSong(last, "Ponytail dan Shu-Shu", "JKT48", "Ponytail dan Shu-Shu", "04:28");
    cout << endl;
    ShowSong(last);
    cout << endl;
    cout << "Delete Song: If There Was An Endpoint" << endl;
    cout << endl;
    Delete(last, "If There Was An Endpoint");
    ShowSong(last);
    return 0;
}