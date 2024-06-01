#include <iostream>

using namespace std;

typedef struct mahasiswa_s
{
    string NIM;
    string nama;
    string jurusan;
    float IPK;
    mahasiswa_s* nextp;
    mahasiswa_s* prevp;

}mahasiswa_t;

mahasiswa_t* AddFront(mahasiswa_t* head, string tNIM, string tnama, string tjurusan, float tIPK)
{
    mahasiswa_t* MHSbaru = new mahasiswa_t;
    MHSbaru->NIM = tNIM;
    MHSbaru->nama = tnama;
    MHSbaru->jurusan = tjurusan;
    MHSbaru->IPK = tIPK;
    if (head == nullptr)
    {
        head = MHSbaru;
    }
    else
    {
        MHSbaru->nextp = head;
        head->prevp = MHSbaru;
        head = MHSbaru;
    }
    return head;
}

mahasiswa_t* AddLast(mahasiswa_t* head, string tNIM, string tnama, string tjurusan, float tIPK)
{
    mahasiswa_t* MHSbaru = new mahasiswa_t;
    MHSbaru->NIM = tNIM;
    MHSbaru->nama = tnama;
    MHSbaru->jurusan = tjurusan;
    MHSbaru->IPK = tIPK;
    if (head == nullptr)
    {
        head = MHSbaru;
    }
    else
    {
        mahasiswa_t* current = head;
        while (current->nextp != nullptr)
        {
            current = current->nextp;
        }
        current->nextp = MHSbaru;
        MHSbaru->prevp = current;
    }
    return head;
}

mahasiswa_t* AddAfter(mahasiswa_t* head, mahasiswa_t* target, string tNIM)
{
    if (target == nullptr)
    {
        return head;
    }

    mahasiswa_t* MHSbaru = new mahasiswa_t;
    MHSbaru->prevp = target;
    MHSbaru->nextp = target->nextp;

    if (target->nextp != nullptr)
    {
        target->nextp->prevp = MHSbaru;
    }

    target->nextp = MHSbaru;

    return head;
}

mahasiswa_t* Delete(mahasiswa_t* head, string tNIM)
{
    mahasiswa_t* current = head;
    while (current != nullptr && current->NIM != tNIM)
    {
        current = current->nextp;
    }

    if (current->prevp != nullptr)
    {
        current->prevp->nextp = current->nextp;
    }
    if (current->nextp != nullptr)
    {
        current->nextp->prevp = current->prevp;
    }

    if (current == head)
    {
        head = current->nextp;
    }

    delete current;
    return head;
}

void DeleteAll(mahasiswa_t* head)
{
    
    while (head != nullptr)
    {
        mahasiswa_t* current = head;
        head = head->nextp;
        delete current;
    }
}

mahasiswa_t* ShowASC(mahasiswa_t* head)
{
    mahasiswa_t* current = head;
    while (current != nullptr)
    {
        cout << current->NIM << endl;
        cout << current->nama << endl;
        cout << current->jurusan << endl;
        cout << current->IPK << endl;
        cout << endl;

        current = current->nextp;
    }
    current = head;
    return current;
}

mahasiswa_t* ShowDSC(mahasiswa_t* head)
{
    mahasiswa_t* current = head;
    while (current != nullptr)
    {
        cout << current->NIM << endl;
        cout << current->nama << endl;
        cout << current->jurusan << endl;
        cout << current->IPK << endl;
        cout << endl;

        current = current->prevp;
    }
    current = head;
    return current;
}

int main()
{
    system("cls");
    mahasiswa_t* head = nullptr;
    //#1 test
    head = AddFront(head, "105224001", "Nell", "CS", 4.0);
    head = AddFront(head, "105124010", "James", "CH", 3.8);
    head = AddFront(head, "101124100", "John", "GP", 3.8);
    head = ShowASC(head);
    cout << "========================================" << endl;
    
    //#2 test
    DeleteAll(head);
    head = AddFront(head, "105222016", "Putra", "CS", 4.0);
    head = AddFront(head, "105222027", "Naima", "CS", 3.0);
    head = AddFront(head, "105224001", "Nell", "CS", 4.0);
    head = AddFront(head, "105124010", "James", "CH", 3.8);
    head = AddFront(head, "101124100", "John", "GP", 3.8);   
    head = ShowASC(head);

    //#3 test
    cout << "========================================" << endl;
    DeleteAll(head);
    head = AddFront(head, "105222016", "Putra", "CS", 4.0);
    head = AddFront(head, "105222027", "Naima", "CS", 3.0); 
    head = AddFront(head, "105222022", "Han-Han", "CS", 1.0);
    head = ShowASC(head);

    return 0;
}