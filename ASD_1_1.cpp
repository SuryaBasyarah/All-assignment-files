#include <iostream>
using namespace std;

typedef struct
{
    char nama[20];
    int TanggalMulai[3];
    float JamKerja;
}lembur;
lembur pegawai[2];

int TanggalSekarang[3] = {1, 9, 2023}; //misal tanggal segini

void penghitungan()
{
    for (int i = 0; i <= 1; i++)
    {
        pegawai[i].JamKerja = ( ( ( (pegawai[i].TanggalMulai[1] * 30 ) + pegawai[i].TanggalMulai[0] ) * 24 ) - ( ( TanggalSekarang[1] * 30 + TanggalSekarang[0] ) * 24 ) );
        pegawai[i].JamKerja *= -1;
    }
}

int main()
{
    pegawai[0].nama[0] = 'a';
    pegawai[1].nama[0] = 'b';

    pegawai[0].TanggalMulai[0] = 30;
    pegawai[0].TanggalMulai[1] = 8;
    pegawai[0].TanggalMulai[2] = 2023;

    pegawai[1].TanggalMulai[0] = 28;
    pegawai[1].TanggalMulai[1] = 8;
    pegawai[1].TanggalMulai[2] = 2023;

    penghitungan();
    cout << pegawai[0].JamKerja << endl;
    cout << pegawai[1].JamKerja;
    cout << endl;
    for (int i = 0; i <= 1; i++)
    {
        if (pegawai[i].JamKerja >= 40)
        {
            cout << "pegawai " << pegawai[i].nama[0] << " memiliki 40 jam kerja";
            cout << endl;
        }
        else
        {
            cout << "pegawai " << pegawai[i].nama[0] << " belum memiliki 40 jam kerja";
            cout << endl;
        }
    }
    return 0;
}