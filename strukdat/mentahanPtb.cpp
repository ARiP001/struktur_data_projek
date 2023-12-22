#include <bits/stdc++.h>
#define true 1
#define false 0

using namespace std;

struct node{
  int info;
  node *kanan, *kiri;
};
node *akar, *p, *b;
int NH;
void buat_ptb();
int ptb_kosong();
void sisipnode (int IB);
void cetak();
void preorder (node *akar);
void inorder (node *akar);
void postorder (node *akar);
void hapusnode (int IH);
void hapus ();


int main(){
    buat_ptb();
    sisipnode(1);
    sisipnode(2);
    sisipnode(3);
    sisipnode(2);
    sisipnode(2);
    sisipnode(0);
    sisipnode(1);
    sisipnode(3);
    sisipnode(6);
    cetak();
    return 0;
}
void buat_ptb (){
    node *ptb;
    ptb=NULL;
    akar=ptb;
}
int ptb_kosong(){
    if (akar==NULL)
    return (true);
    else return (false);
}
void sisipnode (int IB){
    node *NB;
    NB = new node;
    NB-> info = IB;
    NB-> kiri = NULL;
    NB-> kanan = NULL;
    if (ptb_kosong())
    akar =NB;
    else {
        b= akar;
        p= akar;

        while (p!=NULL && IB !=b->info){
            b=p;
            if (IB<p-> info)
                p=b-> kiri;
            else 
                p = b-> kanan;
        }
        if (IB==b->info)
        cout <<"\n\nNode "<<IB<< " sudah ada !";
        else {
            if (IB<b-> info)
                b->kiri =NB;
            else
                b->kanan=NB;
        }
    }
}

void cetak (){
    cout << "\nPre-order : ";
    preorder(akar);
    cout <<"\nIn-order : ";
    inorder(akar);
    cout << "\nPost-order : ";
    postorder(akar);
    return;
}

void preorder(node *akar){
    if (akar!= NULL){
        cout <<" "<<akar-> info ;
        preorder (akar->kiri);
        preorder (akar->kanan);
    }
}

void inorder(node *akar){
    if (akar != NULL){
        inorder (akar-> kiri);
        cout <<" "<<akar-> info;
        inorder (akar-> kanan);
    }
}

void postorder (node *akar){
    if (akar != NULL){
        postorder (akar -> kiri);
        postorder (akar-> kanan);
        cout <<" "<<akar-> info;
    }
}

void hapusnode(int IH){
    if (ptb_kosong())
        cout << "PTB Kosong !\n\n";
    else {
        b=akar;
        p=akar;

        while (p!=NULL && IH != p-> info){
            b=p;
            if (IH<p-> info)
                p=b-> kiri;
            else 
                p=b-> kanan;
        }
    }
    hapus();
}

void hapus(){
    node *temp;
    if (p-> kiri == NULL && p-> kanan == NULL){
        if (b==akar && p==akar)
        akar=NULL;
        else {
            if (p==b-> kiri)
                b-> kiri =NULL;
            else 
                b->kanan = NULL;
        }
        free (p);
    }
    else if (p-> kiri != NULL && p-> kanan !=NULL ){
        temp=p-> kiri;
        b=p;
        while (temp-> kanan != NULL){
            b=temp ;
            temp = temp -> kanan;
        }
        p-> info = temp -> info;
        if (b==p)
            b->kiri = temp -> kiri;
        else 
            b-> kanan = temp -> kiri;
        
        free(temp);
    }
    else if (p-> kiri != NULL && p-> kanan == NULL){
        if (b==p)
            akar = p-> kiri;
        else {
            if (p==b-> kiri)
                b-> kiri = p-> kiri;
            else 
                b-> kanan = p-> kiri;
        }
        free (p);
    }
    else if (p-> kiri ==NULL && p->kanan != NULL){
        if (b==p)
            akar = p-> kanan;
        else {
            if (p==b-> kanan)
                b-> kanan = p-> kanan;
            else 
                b-> kiri = p-> kanan;
        }
        free (p);
    }
}