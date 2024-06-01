#include <iostream>
using namespace std;

typedef struct 
{
    int NIM;
    string nama;
    float IPK;

}mahasiswa;


int main()
{
    mahasiswa mhs[3]; //mhs alias mahasiswa
    // string mhsnama[3] = {"jia", "jihan", "hanhan"};

    mhs[0].NIM = 12345;
    mhs[0].nama = "John Doe";
    mhs[0].IPK = 3.85;

    mhs[1].NIM = 12346;
    mhs[1].nama = "Jane";
    mhs[1].IPK = 2.4;

    mhs[2].NIM = 12347;
    mhs[2].nama = "Martin";
    mhs[2].IPK = 3.0;

    for (int i = 0; i <= 2; i++)
    {
        mhs[i].IPK += 0.2;
        if (mhs[i].IPK > 4.0)
        {
            mhs[i].IPK = 4.0;
        }
    }

    for (int i = 0; i <= 2; i++)
    {
        if (mhs[i].IPK < 3.0)
        {
            cout << mhs[i].nama;
        }
    }
    return 0;
}