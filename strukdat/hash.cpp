#include <iostream>
#include <string>

using namespace std;
struct node{
    int info;
    node *kanan, *kiri;
};

node *hashTable[10],*awal[10], *akhir[10], *NB, *bantu, *hapus;
void sisip (int IB);
void hapusHash(int IH);
void buatlist();
void bacaHash();

int main(){
    cout << "Hash awal";
    sisip(10);
    sisip(11);
    sisip(12);
    sisip(14);
    sisip(13);
    sisip(15);
    // sisip(16);
    // sisip(17);
    sisip(18);
    sisip(19);
    // sisip(18);
    sisip(20);
    sisip(30);
    sisip(40);
    sisip(24);

    bacaHash();

    hapusHash(24);

    cout << "hash 2";
    bacaHash();

    return 0;
}

void buatlist(){
    for (int i = 0; i < 10; i++)
    {
        hashTable[i]=new node;
        hashTable[i]= NULL;
        awal[i]= hashTable[i];
        akhir[i] = hashTable[i];
    }
}
void sisip (int IB){
    int loc;
    loc = IB % 10;
    NB = new node;
    NB -> info = IB;
    NB -> kanan = NULL;
    NB -> kiri = NULL;

    if (awal[loc]==NULL){
        awal[loc]=NB;
        akhir[loc]=NB;
    }
    else{
        akhir[loc]-> kanan = NB;
        NB-> kiri = akhir[loc];
        akhir[loc] = NB;
    }
}


void bacaHash(){
    for (int i = 0; i < 10; i++){
    if(awal[i]!=0){
        bantu = awal[i];
        cout << endl << bantu-> info;
        while (bantu->kanan!= NULL){
            bantu = bantu-> kanan;
            cout << " -> "<< bantu -> info;
        }
            cout << endl;
    }
    }
}

void hapusHash(int IH){
    int i = IH % 10;

        if (awal[i]==NULL) {
            cout << "List masih kosong";
        } else if (awal[i]->info == IH) {
            hapus = awal[i]; // Hapus di awal[i]
            awal[i] = hapus->kanan;
            if (awal[i] != NULL) {
                awal[i]->kiri = NULL;
            }
            free(hapus);
        } else {
            bantu = awal[i];
            while (bantu->kanan != NULL && IH != bantu->kanan->info) {
                bantu = bantu->kanan;
            }
            if (bantu->kanan != NULL && IH == bantu->kanan->info) {
                hapus = bantu->kanan;
                if (hapus == akhir[i]) { // Hapus di akhir[i]
                    akhir[i] = bantu;
                    akhir[i]->kanan = NULL;
                } else { // Hapus di tengah
                    bantu->kanan = hapus->kanan;
                    hapus->kanan->kiri = bantu;
                }
                free(hapus);
            } else {
                cout << "Node tidak ditemukan!\n";
            }
        }
}