#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    /* KAMUS */
    /* ALGORITMA */
    return ((Head(Q)==Nil) && (Tail(Q)==Nil));
}
boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmt(Q) == MaxEl(Q));
}
int NBElmt (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    /* KAMUS */
    int count;
    /* ALGORITMA */
    if (IsEmpty(Q)){
        count = 0;
    }
    else{
        count = Tail(Q) - Head(Q) + 1;
    }
    return count;
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    /* KAMUS */
    /* ALGORITMA */
    (*Q).T = (infotype *) malloc (Max * sizeof(infotype));
    if ((*Q).T != NULL){
        MaxEl(*Q) = Max+1;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }else{
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    /* KAMUS */
    /* ALGORITMA */
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
    /* KAMUS */
    int pos;
    /* ALGORITMA */
    if (IsFull(*Q) == true){
        printf("Antrian Penuh");
    }else{
        pos = Tail(*Q);
        Tail(*Q) = Tail(*Q) + 1;
        while ((pos >= 0) && (Prio(Elmt(*Q, pos)) >= Prio(X))){
            Elmt(*Q, pos+1) = Elmt(*Q, pos);
            pos = pos - 1;
        }
        Elmt(*Q, pos+1) = X;
        if (Head(*Q) == Nil){
            Head(*Q) = Head(*Q) + 1;
        }
    }
}
void Dequeue (PrioQueueChar * Q, infotype * X)
{
     // KAMUS
    address P;
    // ALGORITMA
    if (IsEmpty(*Q) == false){
        *X = InfoHead(*Q);
        P = Head(*Q);
        Head(*Q) = Head(*Q) + 1;
        if (Head(*Q) == Nil){
            Tail(*Q) = Nil;
        }
    }
}

void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    /* KAMUS */
    int i;
    /* ALGORITMA */
    if (IsEmpty(Q)){
        printf("#\n");
    }
    else{
        i = Head(Q);
        while (i <= Tail(Q)){
            printf("<%d> <%c>\n", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
            i = i + 1;
        }
        printf("#\n");
    }
}