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
