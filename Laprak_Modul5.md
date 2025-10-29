# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Kafin Fazlur Rahman - 103112430097</p>

## Dasar Teori
Singly Linked List merupakan salah satu struktur data dinamis yang tersusun atas elemen-elemen yang saling terhubung melalui pointer. Setiap elemen dalam list disebut node dan terdiri dari dua bagian, yaitu info yang berisi data dan next yang menunjuk ke node berikutnya. Berbeda dengan array yang memiliki ukuran tetap, singly linked list bersifat fleksibel karena jumlah elemennya dapat bertambah atau berkurang sesuai kebutuhan melalui proses alokasi dan dealokasi memori. Dalam penerapannya, singly linked list menggunakan pointer pertama yang disebut first untuk menandai elemen awal list. Melalui berbagai fungsi dasar seperti createList, alokasi, dealokasi, insertFirst, dan printInfo, struktur ini dapat dibentuk dan dimanipulasi sesuai kebutuhan. Selain itu, fungsi tambahan seperti findElm digunakan untuk mencari data tertentu dalam list, dan totalInfo digunakan untuk menghitung jumlah seluruh nilai yang tersimpan. Dengan konsep pemisahan file menggunakan ADT (Abstract Data Type), yaitu antara header (.h), implementasi (.cpp), dan program utama (main.cpp), program menjadi lebih terstruktur dan modular

## Guided 

### Soal 1

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List; // nama struct disamakan (linkedList)
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil; // semua diinisialisasi Nil
    createList(List);

    // Pembuatan node baru (alokasi data buah)
    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 11450);

    // Proses insert node ke dalam list
    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << nbList(List) << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl; 

    return 0;
}
```
Program ini mengelola data buah dengan Linked List. Pertama dibuat list kosong, lalu beberapa node buah seperti Jeruk, Apel, Pir, Semangka, dan Durian dialokasikan dan dimasukkan ke list menggunakan fungsi 'insertFirst', 'insertLast', dan 'insertAfter'. Setelah itu isi list dan jumlah node ditampilkan. Program kemudian memperbarui data di beberapa posisi dengan 'updateFirst', 'updateLast', dan 'updateAfter', lalu mencari data tertentu berdasarkan nama, alamat, atau rentang harga. Selanjutnya dilakukan penghapusan node di awal, akhir, dan setelah node tertentu menggunakan 'delFirst', 'delLast', dan 'delAfter'. Terakhir, seluruh isi list dihapus dengan 'deleteList', sehingga list menjadi kosong kembali.

## Unguided 

### Soal 1
Buatlah sebuah program menggunakan bahasa C++ untuk mengimplementasikan Singly Linked List dengan spesifikasi sebagai berikut:

- Buat file Singlylist.h yang berisi deklarasi tipe data dan fungsi dasar list (createList, alokasi, dealokasi, insertFirst, printInfo).

- Buat file Singlylist.cpp untuk mengimplementasikan fungsi-fungsi tersebut.

- Uji dengan program utama (main.cpp) yang membuat list berisi data 2, 0, 8, 12, 9.

- Tambahkan fungsi findElm(List L, infotype x) untuk mencari elemen bernilai 8.

- Tambahkan fungsi totalInfo(List L) untuk menghitung jumlah total semua elemen (hasilnya 31).

Tampilkan hasil output program yang sesuai dengan gambar di modul.

```C++
singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif

singlylist.cpp
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    cout << "Isi list: ";
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x)
            return P;
        P = P->next;
    }
    return Nil;
}

int totalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}

main.cpp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    address cari = findElm(L, 8);
    if (cari != Nil)
        cout << "Elemen dengan nilai 8 ditemukan di alamat: " << cari << endl;
    else
        cout << "Elemen 8 tidak ditemukan." << endl;

    cout << "Total seluruh info = " << totalInfo(L) << endl;

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

## Kesimpulan
Singly Linked List adalah struktur data dinamis yang menggunakan pointer untuk menghubungkan setiap elemen secara berurutan. Struktur ini memungkinkan penambahan dan penghapusan data dilakukan lebih fleksibel dibandingkan array karena tidak memerlukan penggeseran elemen lain.

Dengan menerapkan fungsi-fungsi seperti createList, insertFirst, findElm, dan totalInfo, program dapat melakukan pembuatan list, penambahan elemen, pencarian data, hingga perhitungan total nilai dalam list. Pemisahan kode menjadi tiga file — Singlylist.h, Singlylist.cpp, dan main.cpp — juga menunjukkan penerapan konsep modularisasi agar program lebih rapi dan mudah dikelola.

Secara keseluruhan, penerapan singly linked list ini membantu memahami cara kerja struktur data berantai menggunakan pointer di C++ serta memperkuat konsep alokasi memori dan traversal data secara terstruktur.

## Referensi
[1] GeeksforGeeks. Singly Linked List Tutorial. https://www.geeksforgeeks.org/dsa/singly-linked-list-tutorial/
