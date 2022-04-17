#include <iostream>
#include "list.h"
using namespace std;
#include "test.h"


/************************* Don't Edit this code *********************************/

int main (){
    //use infolist, createElmList, firstElm, LastElm to help you debug code
    // infolist : print all elm in list
    // createElmList : return address of new elm you create
    // firstElm : return int, first Elm in list
    // LastElm : return int, last Elm in list

    //there are 2 bonus case, insertFirst, deleteFirst
    // your task is complete 4 procedure
    // insertAfter, insertLast, DelAfter, DelLast
    testCase();
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/

void InsertFirst (List * L, address P){
    if(L->First == NULL) L->First = P;
    else {
        P->next = L->First;
        L->First = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List * L, address P, address Prec){
    // Write your code in Here
    // Prec: 1 -> 2
    // P: 5
    // Precc: 1 -> 5
    // L: 1 5 2 3 4
    // arahkan next P ke address P
    // kemudian P: 5 -> 2
    address temp = L->First;
    while (temp != Prec)
    {
        temp->next;
    }
    P -> next = temp -> next;
    temp -> next = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List * L, address P){
    // Write your code in Here
    address Last = L->First;
    while (Last->next !=NULL)
    {
        Last = Last -> next;
    }
    Last -> next = P;
}
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List * L, address * P){
    if(L->First){
        address old = *P;
        L->First = L->First->next;
        delete old;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (List * L, address * P){
//     write your code in Here
    address tmp = L->First;
    while(tmp->next->next !=NULL){
        tmp = tmp->next;
    }
    address old = *P;
    tmp->next = NULL;
    delete old;
}
/* I.S. List tidak kosong */
/* F.S. Pe adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen liest berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List * L, address * Pdel, address Prec){
    // Write your code in Here
    ElmtList *temp = L->First;
    while(temp != Prec){
        temp = temp->next;
    }
    address old = *Pdel;

    temp->next = temp->next->next;
    delete old;
}
/* I.S. Liset tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
