#include <iostream>
#include <vector>

using namespace std;

typedef struct 
{
    string KodeMatkul;
    int kelas;
    int kredit;
}MatKul;

typedef struct
{
    int NIM;
    vector<MatKul> Kuliah;
}mahasiswa;

const int TotalMhs = 3;
mahasiswa mahasiswa_s[TotalMhs];

void DAFTARMHS()
{
    mahasiswa_s[0].NIM = 1111;
    mahasiswa_s[1].NIM = 1234;
    mahasiswa_s[2].NIM = 1357;
}

void COUNTMHS(string Kode_Matkul, int Kelas_s)
{
    int total = 0;
    for (int i = 0; i < TotalMhs; i++)
    {
        for (int j = 0; j < mahasiswa_s[i].Kuliah.size(); j++)
        {
            if ((mahasiswa_s[i].Kuliah[j].KodeMatkul == Kode_Matkul) && (mahasiswa_s[i].Kuliah[j].kelas == Kelas_s))
            total++;
        }
    }
    cout << "Total mahasiswa yang mengambil " << Kode_Matkul << " di kelas " << Kelas_s << " ada " << total << " mahasiswa." << endl;
}

void SEARCH()
{
    for (int i = 0; i < TotalMhs; i++)
    {
        if (mahasiswa_s[i].Kuliah.empty())
        {
            cout << "Mahasiswa " << mahasiswa_s[i].NIM << " tidak aktif." << endl;
        }
    }
}

void COUNTSKS()
{
    for (int i = 0; i < TotalMhs; i++)
    {
        cout << mahasiswa_s[i].NIM << " - ";
        int sks = 0;
        for (int j = 0; j < mahasiswa_s[i].Kuliah.size(); j++)
        {
            sks += mahasiswa_s[i].Kuliah[j].kredit;
        }
        cout << sks << " SKS" << endl;
    }
}

void ADDMATKUL(int NIM_s, string KodeMatkul_s, int kelas_s, int kredit_s)
{
    for (int i = 0; i < TotalMhs; i++)
    {
        if (mahasiswa_s[i].NIM == NIM_s)
        {
            MatKul MatKul_s;
            MatKul_s.KodeMatkul = KodeMatkul_s;
            MatKul_s.kredit = kredit_s;
            MatKul_s.kelas = kelas_s;
            mahasiswa_s[i].Kuliah.push_back(MatKul_s);
            return;
        }
    }
}

void REMOVE(int Mhs_NIM, string KodeMatkul_s)
{
    for (int i = 0; i < TotalMhs; i++)
    {
        for (int j = 0; j < mahasiswa_s[i].Kuliah.size(); j++)
        {
            if ((mahasiswa_s[i].NIM == Mhs_NIM) && (mahasiswa_s[i].Kuliah[j].KodeMatkul == KodeMatkul_s))
            {
                mahasiswa_s[i].Kuliah.erase(mahasiswa_s[i].Kuliah.begin() + j);
            }
        }
    }
}

void SHOWALL()
{
    for (int i = 0; i < TotalMhs; i++)
    {
        cout << "ID Mahasiswa: " << mahasiswa_s[i].NIM << endl;
        for (int j = 0; j < mahasiswa_s[i].Kuliah.size(); j++)
        {
            cout << mahasiswa_s[i].Kuliah[j].KodeMatkul << " - " << mahasiswa_s[i].Kuliah[j].kelas << " - " << mahasiswa_s[i].Kuliah[j].kredit << endl;
        }
        cout << endl;
    }
}

int main()
{
    DAFTARMHS();
    ADDMATKUL(mahasiswa_s[0].NIM, "CIS120", 1, 3);
    ADDMATKUL(mahasiswa_s[0].NIM, "HIS001", 2, 4);

    ADDMATKUL(mahasiswa_s[2].NIM, "CIS120", 2, 3);

    SHOWALL();

    cout << "=================================" << endl;

    REMOVE(mahasiswa_s[0].NIM, "CIS120");

    SHOWALL();

    cout << "=================================" << endl;

    ADDMATKUL(mahasiswa_s[0].NIM, "RPL117", 4, 3);
    ADDMATKUL(mahasiswa_s[0].NIM, "HTS420", 3, 3);
    ADDMATKUL(mahasiswa_s[2].NIM, "HTS420", 3, 3);
    ADDMATKUL(mahasiswa_s[2].NIM, "RPL117", 3, 3);

    SHOWALL();

    COUNTSKS();

    cout << "=================================" << endl;

    SEARCH();

    cout << "=================================" << endl;

    COUNTMHS("HTS420", 3);

    return 0;
}