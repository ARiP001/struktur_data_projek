#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <limits>

using namespace std;

//total produk
int total = 0;

// deklarasi struct hash
struct node
{
  int info, harga;
  string nama;
  node *kanan, *kiri;
};
node *hashTable[10], *awal[10], *akhir[10], *NB, *bantu, *hapus;

// void hash
void sisipHash(int IB, string nama, int harga);
void hapusHash(int IH);
void buatHashTable();
void bacaHash();
void hapusNode(string infoHapus);

// deklarasi struct pohon
struct Pohon
{
  int info, harga;
  string nama;
  Pohon *kanan, *kiri;
};
Pohon *akar, *p, *b, *root, *akar_archieve, *root_archieve;

// void pohon
void sisipptb(int IB, string nama, int harga);

void buat_ptb()
{
  Pohon *ptb = NULL;
  akar = ptb;
}

void buat_ptb_archieve()
{
  Pohon *ptb = NULL;
  akar_archieve = ptb;
}

int hash_kosong()
{
  bool found = false;
  for (int i = 0; i < 10; i++)
  {
    if (awal[i] != NULL)
    {
      found = true;
    }
  }
  if (!found)
    return (true);
  else
    return (false);
  ;
}

int ptb_kosong()
{
  if (akar == NULL)
    return (true);
  else
    return (false);
}

int ptb_archieve_kosong()
{
  if (akar_archieve == NULL)
    return (true);
  else
    return (false);
}

void inOrder(Pohon *akar);
void postOrder(Pohon *akar);
void preOrder(Pohon *akar);
void DescendSorting(Pohon *node);
void cariptb();

// void menu
void header_tabel();
void tabel(Pohon *output);
void input();
void keluar();
void tampil();
void cari();
string namahapus;

int main()
{
  int pilmenu, hapus;
  char ulang;
  buatHashTable();

  do
  {
     system("cls");
    cout << string(15, ' ') << string(52, '=') << endl;
    cout << string(15, ' ') << "|" << right << setw(48) << setfill(' ') << "SELAMAT DATANG DI TOKO KELONTONG (SERBA ADA) "
         << setw(3) << setfill(' ') << "|" << endl;
    cout << string(15, ' ') << string(52, '-') << endl<<endl;
    cout << "Menu :\n"
         << "----------\n"
         << "1. Input Produk (hash)\n"
         << "2. Tampilkan Produk (hash)\n"
         << "3. Cari Produk\n"
         << "4. Sorting Produk (ptb)\n"
         << "5. Hapus Produk (hash)\n"
         << "6. Lihat History Hapus (ptb) \n\n"
         << "0. Keluar\n";
    cout << string(40, '-') << endl;
    cout << "Pilih menu : ";
    cin >> pilmenu;

    switch (pilmenu)
    {
    case 1:
      input();
      cout << "Kembali ke menu ?[y/n]" << endl
           << ">> ";
      cin >> ulang;
      break;

    case 2:
      tampil();
      cout << "\nKembali ke menu ?[y/n]" << endl
           << ">> ";
      cin >> ulang;
      break;

    case 3:
      int pilih;
      system("cls");
      cout << string(15, ' ') << "-----------------------------\n"
           << string(15, ' ') << "||     MENU PENCARIAN      ||\n"
           << string(15, ' ') << "-----------------------------\n";
      if (hash_kosong())
        cout << "\n[ Data masih kosong ! ]\n";
      else
      {
        cout << "Menu cari:\n"
             << "1. Cari berdasarkan kode (hash)\n"
             << "2. Cari berdasarkan nama (ptb)\n"
             << "Pilih : ";
        cin >> pilih;
        if (pilih == 1)
          cari();
        else if(pilih == 2)
          cariptb();
        else {
          cout<<"\n[ Menu yang anda pilih tidak tersedia! ]"<<endl;
          system("pause");
          }
      }
      cout << "\nKembali ke menu ?[y/n]" << endl
           << ">> ";
      cin >> ulang;
      break;

    case 4:
      system("cls");
      cout << string(15, ' ') << "-----------------------------\n"
           << string(15, ' ') << "||      MENU SORTING       ||\n"
           << string(15, ' ') << "-----------------------------\n";
      if (ptb_kosong())
      {
        cout << "\nData masih kosong" << endl;
      }
      else
      {
        cout << "PostOrder : " << endl;
        header_tabel();
        postOrder(akar);
        cout << string(57, '=') << endl << endl;

        cout << "Descending : " << endl;
        header_tabel();
        DescendSorting(akar);
        cout << string(57, '=') << endl << endl;
      }
      cout << "\nKembali ke menu ?[y/n]" << endl
           << ">> ";
      cin >> ulang;
      break;

    case 5:
      system("cls");
      cout << string(15, ' ') << "-----------------------------\n"
           << string(15, ' ') << "||       MENU HAPUS        ||\n"
           << string(15, ' ') << "-----------------------------\n";
      if (hash_kosong())
      {
        cout << "\n[ Hash masih kosong ! ]" << endl;
      }
      else
      {
      kodesalah: // Label untuk melewati eksekusi bagian selanjutnya dari case 5
        cout << "\nHapus KODE : ";
        cin >> hapus;
        if (cin.fail()) // Penangyanan kesalahan input
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Kesalahan input. Masukkan kode yang benar.\n";
          goto kodesalah; // Label untuk melewati eksekusi bagian selanjutnya dari case 5
        }
        hapusHash(hapus);
        hapusNode(namahapus);
        total--;
      }

      cout << "\nKembali ke menu ?[y/n]" << endl
           << ">> ";
      cin >> ulang;
      break;

    case 6:
      system("cls");
      cout << string(15, ' ') << "----------------------------\n"
           << string(15, ' ') << "||     MENU TAMPILAN      ||\n"
           << string(15, ' ') << "----------------------------\n";
      if (ptb_archieve_kosong())
      {
        cout << "\n[ Archieve masih kosong! ]" << endl;
      }
      else
      {
        cout << "\nData sampah : " << endl
             << endl;
        cout << "DIURUTKAN BERDASARKAN NAMA" << endl;
        cout << "\nInOrder : " << endl;
        header_tabel();
        inOrder(akar_archieve);
        cout << string(57, '=') << endl
             << endl;

        cout << "\nPreOrder : " << endl;
        header_tabel();
        preOrder(akar_archieve);
        cout << string(57, '=') << endl
             << endl;

        cout << "\nPostOrder : " << endl;
        header_tabel();
        postOrder(akar_archieve);
        cout << string(57, '=') << endl
             << endl;
      }
      cout << "\nKembali ke menu ?[y/n]" << endl
           << ">> ";
      cin >> ulang;
      break;

    case 0 :
      ulang = 'n';
      break;

    default:
      cout<<"\n[ Menu yang anda pilih tidak tersedia! ]"<<endl;
      system("pause");
      ulang = 'y';
      break;
    }

  } while (ulang == 'y');
  keluar();
  return 0;
}

void keluar()
{
  system("cls");
  cout << endl
       << string(15, ' ') << "=================================" << endl
       << string(15, ' ') << "|  SAMPAI JUMPA LAGI /(^ _ ^)/  |" << endl
       << string(15, ' ') << "=================================" << endl
       << endl;

  system("pause");
  system("exit");
}

void input()
{
  int kode, harga, jum;
  string nama;
  system("cls");
  cout << string(15, ' ') << "----------------------------\n"
       << string(15, ' ') << "||       MENU INPUT       ||\n"
       << string(15, ' ') << "----------------------------\n";
  cout << "\nMasukkan jumlah produk : ";
  cin >> jum;
  int jumlah = jum + total;
  if (cin.fail() || jum <= 0) // Penanganan kesalahan input
  {
    cin.clear();                                         // Membersihkan status kesalahan cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang salah
    cout << "Kesalahan input. Masukkan jumlah produk yang benar.\n";
    return;
  }

  for (int i = total; i < jumlah; i++)
  {
    cout << "\n<Produk ke-" << i + 1 <<">";
    cout << "\nKode produk (1-3 digit)\t: ";
    cin >> kode;
    if (cin.fail() || kode < 1 || kode > 999) // Penanganan kesalahan input
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Kesalahan input. Masukkan kode produk antara 1 dan 999.\n";
      i--; // Mengulangi langkah untuk produk ini
      continue;
    }
    cout << "Nama produk\t\t: ";
    getline(cin >> ws, nama);
    cout << "Harga produk\t\t: ";
    cin >> harga;
    if (cin.fail() || harga <= 0) // Penanganan kesalahan input
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Kesalahan input. Masukkan harga produk yang benar.\n";
      i--; // Mengulangi langkah untuk produk ini
      continue;
    }
    total++;
    sisipHash(kode, nama, harga);
    sisipptb(kode, nama, harga);
  }
  cout << endl;
  cout << string(15, ' ') << "--------------------------\n"
       << string(15, ' ') << "|  PRODUK TELAH DIINPUT  |\n"
       << string(15, ' ') << "--------------------------\n";
}

void tampil()
{
  int num = 1;
  system("cls");
  cout << string(15, ' ') << "----------------------------\n"
       << string(15, ' ') << "||     MENU TAMPILAN      ||\n"
       << string(15, ' ') << "----------------------------\n";
  if (hash_kosong())
    cout << "\n[ Hash masih kosong ! ]\n";
  else
  {
    cout << "\nTampilan Hash Table : \n";
    bacaHash();
    cout << "\nTampilan Produk : \n";
    cout << string(64, '=') << endl;
    cout << "| ";
    cout << setw(3) << right << setfill(' ') << "No";
    cout << setw(1) << right << setfill(' ') << "";
    cout << " | ";
    cout << setw(6) << right << setfill(' ') << "Kode";
    cout << setw(4) << right << setfill(' ') << "";
    cout << " | ";
    cout << setw(14) << right << setfill(' ') << "Nama";
    cout << setw(10) << right << setfill(' ') << "";
    cout << " | ";
    cout << setw(9) << right << setfill(' ') << "Harga";
    cout << setw(4) << right << setfill(' ') << "";
    cout << " |" << endl;
    cout << string(64, '=') << endl;
    for (int i = 0; i < 10; i++)
    {
      if (awal[i] != 0)
      {
        bantu = awal[i];
        cout << "| ";
        cout << setw(4) << left << setfill(' ') << num++;
        cout << " | ";
        cout << setw(10) << left << setfill(' ') << bantu->info;
        cout << " | ";
        cout << setw(24) << left << setfill(' ') << bantu->nama;
        cout << " | ";
        cout << "Rp. " << setw(9) << left << setfill(' ') << bantu->harga;
        cout << " |" << endl;
        while (bantu->kanan != NULL)
        {
          bantu = bantu->kanan;
          cout << "| ";
          cout << setw(4) << left << setfill(' ') << num++;
          cout << " | ";
          cout << setw(10) << left << setfill(' ') << bantu->info;
          cout << " | ";
          cout << setw(24) << left << setfill(' ') << bantu->nama;
          cout << " | ";
          cout << "Rp. " << setw(9) << left << setfill(' ') << bantu->harga;
          cout << " |" << endl;
        }
      }
    }
    cout << string(64, '=') << endl;
  }
}

void cari()
{
  int cari;
  bool found = false;
  system("cls");
  cout << string(15, ' ') << "-------------------------------\n"
       << string(15, ' ') << "||   MENU PENCARIAN PRODUK   ||\n"
       << string(15, ' ') << "-------------------------------\n";
  cout << "Masukkan kode yang ingin dicari : ";
  cin >> cari;
  if (cin.fail()) // Penanganan kesalahan input
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n[ Kesalahan input. Masukkan kode yang benar! ]\n";
    return;
  }
  int index = cari % 10;
  bantu = awal[index];
  while (bantu != NULL)
  {
    if (bantu->info == cari)
    {
      cout << "\nProduk ditemukan:\n";
      cout << "Kode  : " << bantu->info << endl;
      cout << "Nama  : " << bantu->nama << endl;
      cout << "Harga : " << bantu->harga << endl;
      found = true;
      break;
    }
    bantu = bantu->kanan;
  };
  if (!found)
    cout << "\n[ Produk dengan kode '" << cari << "' tidak ditemukan ! ]\n";
}

void buatHashTable()
{
  for (int i = 0; i < 10; i++)
  {
    hashTable[i] = new node;
    hashTable[i] = NULL;
    awal[i] = hashTable[i];
    akhir[i] = hashTable[i];
  }
}

void sisipHash(int IB, string nama, int harga)
{
  int loc;
  loc = IB % 10;
  NB = new node;
  NB->info = IB;
  NB->nama = nama;
  NB->harga = harga;
  NB->kanan = NULL;
  NB->kiri = NULL;

  if (awal[loc] == NULL)
  {
    awal[loc] = NB;
    akhir[loc] = NB;
  }
  else
  {
    akhir[loc]->kanan = NB;
    NB->kiri = akhir[loc];
    akhir[loc] = NB;
  }
}

void bacaHash()
{
  for (int i = 0; i < 10; i++)
  {
    if (awal[i] != 0)
    {
      bantu = awal[i];
      cout << "[ index ke-" << i << " ] : " << bantu->info;
      while (bantu->kanan != NULL)
      {
        bantu = bantu->kanan;
        cout << " -> " << bantu->info;
      }
    }
    else
      cout << "[ index ke-" << i << " ] : [/] ";
    cout << endl;
  }
}

void hapusHash(int IH)
{
  int i = IH % 10;

  if (awal[i] == NULL)
  {
    cout << "\n[ List masih kosong! ]";
  }
  else if (awal[i]->info == IH)
  {
    hapus = awal[i]; // Hapus di awal[i]
    awal[i] = hapus->kanan;
    if (awal[i] != NULL)
    {
      awal[i]->kiri = NULL;
    }
    namahapus = hapus->nama;
    free(hapus);
  }
  else
  {
    bantu = awal[i];
    while (bantu->kanan != NULL && IH != bantu->kanan->info)
    {
      bantu = bantu->kanan;
    }
    if (bantu->kanan != NULL && IH == bantu->kanan->info)
    {
      hapus = bantu->kanan;
      if (hapus == akhir[i])
      { // Hapus di akhir[i]
        namahapus = hapus->nama;
        akhir[i] = bantu;
        akhir[i]->kanan = NULL;
      }
      else
      { // Hapus di tengah
        bantu->kanan = hapus->kanan;
        hapus->kanan->kiri = bantu;
      }
      namahapus = hapus->nama;
      free(hapus);
    }
    else
    {
      cout << "\n[ Node tidak ditemukan! ]";
    }
  }
}

void sisipptb(int IB, string nama, int harga)
{
  Pohon *NB;
  // NB = (Pohon *)malloc(sizeof(Pohon));
  NB = new Pohon();
  NB->info = IB;
  NB->nama = nama;
  NB->harga = harga;
  NB->kiri = NULL;
  NB->kanan = NULL;
  if (ptb_kosong())
    akar = NB;
  else
  {
    b = akar;
    p = akar;
    // mencari tempat untuk sisip
    while (p != NULL && nama != p->nama)
    {
      b = p;
      if (nama < p->nama)
        p = b->kiri;
      else
        p = b->kanan;
    }
    if (nama == b->nama)
      cout << "\n\nNode " << nama << " sudah ada !\n\n";
    // masukin nb
    else
    {
      if (nama < b->nama)
        b->kiri = NB;
      else
        b->kanan = NB;
    }
  }
}

void sisip_archieve_ptb(Pohon *from_delete)
{
  Pohon *NB;
  NB = new Pohon();
  NB->info = from_delete->info;
  NB->nama = from_delete->nama;
  NB->harga = from_delete->harga;
  NB->kiri = NULL;
  NB->kanan = NULL;
  if (ptb_archieve_kosong())
    akar_archieve = NB;
  else
  {
    b = akar_archieve;
    p = akar_archieve;
    // mencari tempat untuk sisip
    while (p != NULL && from_delete->nama != p->nama)
    {
      b = p;
      if (from_delete->nama <= p->nama)
        p = b->kiri;
      else
        p = b->kanan;
    }
    if (from_delete->nama <= b->nama)
      b->kiri = NB;
    else
      b->kanan = NB;
  }
}

void header_tabel()
{
  cout << string(57, '=') << endl;
  cout << "| ";
  cout << setw(6) << right << setfill(' ') << "Kode";
  cout << setw(4) << right << setfill(' ') << "";
  cout << " | ";
  cout << setw(14) << right << setfill(' ') << "Nama";
  cout << setw(10) << right << setfill(' ') << "";
  cout << " | ";
  cout << setw(9) << right << setfill(' ') << "Harga";
  cout << setw(4) << right << setfill(' ') << "";
  cout << " |" << endl;
  cout << string(57, '=') << endl;
}

void tabel(Pohon *node)
{
  cout << "| ";
  cout << setw(10) << left << setfill(' ') << node->info;
  cout << " | ";
  cout << setw(24) << left << setfill(' ') << node->nama;
  cout << " | ";
  cout << "Rp. " << setw(9) << left << setfill(' ') << node->harga;
  cout << " |" << endl;
}

void inOrder(Pohon *node)
{
  if (node != NULL)
  {
    inOrder(node->kiri);
    tabel(node);
    inOrder(node->kanan);
  }
}

void preOrder(Pohon *node)
{
  if (node != NULL)
  {
    tabel(node);
    inOrder(node->kiri);
    inOrder(node->kanan);
  }
}

void postOrder(Pohon *node)
{
  if (node != NULL)
  {
    inOrder(node->kiri);
    inOrder(node->kanan);
    tabel(node);
  }
}

void DescendSorting(Pohon *node)
{
  if (node != NULL)
  {
    DescendSorting(node->kanan);
    tabel(node);
    DescendSorting(node->kiri);
  } 
}

Pohon *carinama(Pohon *akar, string nama)
{
  if (akar == NULL || akar->nama == nama)
  {
    return akar;
  }

  if (nama < akar->nama)
  {
    return carinama(akar->kiri, nama);
  }

  return carinama(akar->kanan, nama);
}

void cariptb()
{
  system("cls");
  cout << string(15, ' ') << "---------------------------------\n"
       << string(15, ' ') << "||    MENU PENCARIAN PRODUK    ||\n"
       << string(15, ' ') << "---------------------------------\n";
  string targetNama;
  cout << "Masukkan nama produk yang dicari: ";
  getline(cin >> ws, targetNama);

  Pohon *hasilPencarian = carinama(akar, targetNama);

  if (hasilPencarian != NULL)
  {
    cout << "\nProduk ditemukan:\n";
    cout << "Kode  : " << hasilPencarian->info << endl;
    cout << "Nama  : " << hasilPencarian->nama << endl;
    cout << "Harga : " << hasilPencarian->harga << endl;
  }
  else
  {
    cout << "\n[ Produk dengan nama " << targetNama << " tidak ditemukan1! ]\n";
  }
}

void hapusNode(string infoHapus)
{
  Pohon *bantu1, *bantu2, *temp;
  bantu1 = new Pohon;
  bantu2 = new Pohon;
  temp = new Pohon;

  if (ptb_kosong())
  {
    cout << "[ Data masih kosong! ]" << endl;
    system("pause");
  }
  else
  {
    bantu1 = akar;
    bantu2 = akar;
    while (bantu1 != NULL && infoHapus != bantu1->nama)
    {
      bantu2 = bantu1;
      if (infoHapus < bantu1->nama)
      {
        bantu1 = bantu2->kiri;
      }
      else
      {
        bantu1 = bantu2->kanan;
      }
    }
    if (bantu1 == NULL)
    {
      cout << "\n[ Produk tidak ditemukan! ]" << endl;
      system("pause");
      return;
    }
    else
    {

      if (bantu1->kiri == NULL && bantu1->kanan == NULL)
      {
        if (bantu1 == akar && bantu2 == akar)
        {
          akar = NULL;
        }
        else
        {
          if (bantu1 == bantu2->kiri)
          {
            bantu2->kiri = NULL;
          }
          else
          {
            bantu2->kanan = NULL;
          }
        }
        cout << "\nProduk dengan keterangan : "<< endl;
        cout << "Kode\t: " << bantu1->info << endl;
        cout << "Nama\t: " << bantu1->nama << endl;
        cout << "Harga\t: " << bantu1->harga << endl;
        cout << "\n[ Berhasil di hapus! ]"<<endl;
        sisip_archieve_ptb(bantu1);
      }
      else if (bantu1->kiri != NULL && bantu1->kanan != NULL)
      {
        temp = bantu1->kiri;
        cout << "\nProduk dengan keterangan : "<< endl;
        cout << "Kode\t: " << bantu1->info << endl;
        cout << "Nama\t: " << bantu1->nama << endl;
        cout << "Harga\t: " << bantu1->harga << endl;
        cout << "\n[ Berhasil di hapus! ]"<<endl;
        sisip_archieve_ptb(bantu1);
        bantu2 = bantu1;
        while (temp->kanan != NULL)
        {
          bantu2 = temp;
          temp = temp->kanan;
        }
        bantu1->info = temp->info;
        bantu1->harga = temp->harga;
        bantu1->nama = temp->nama;
        if (bantu2 == bantu1)
        {
          bantu2->kiri = temp->kiri;
        }
        else
        {
          bantu2->kanan = temp->kiri;
        }
        // sisip_archieve_ptb(bantu1);
        
      }
      else if (bantu1->kiri == NULL && bantu1->kanan != NULL)
      {
        if (bantu1 == bantu2)
        {
          akar = bantu1->kanan;
        }
        else
        {
          if (bantu1 == bantu2->kanan)
          {
            bantu2->kanan = bantu1->kanan;
          }
          else
          {
            bantu2->kiri = bantu1->kanan;
          }
        }
        cout << "\nProduk dengan keterangan : "<< endl;
        cout << "Kode\t: " << bantu1->info << endl;
        cout << "Nama\t: " << bantu1->nama << endl;
        cout << "Harga\t: " << bantu1->harga << endl;
        cout << "\n[ Berhasil di hapus! ]"<<endl;
        sisip_archieve_ptb(bantu1);
      }
      else if (bantu1->kiri != NULL && bantu1->kanan == NULL)
      {
        if (bantu1 == bantu2)
        {
          akar = bantu1->kiri;
        }
        else
        {
          if (bantu1 == bantu2->kiri)
          {
            bantu2->kiri = bantu1->kiri;
          }
          else
          {
            bantu2->kanan = bantu1->kiri;
          }
        }
        cout << "\nProduk dengan keterangan : "<< endl;
        cout << "Kode\t: " << bantu1->info << endl;
        cout << "Nama\t: " << bantu1->nama << endl;
        cout << "Harga\t: " << bantu1->harga << endl;
        cout << "\n[ Berhasil di hapus! ]"<<endl;
        sisip_archieve_ptb(bantu1);
      }
    }
  }
}
