#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;
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

struct Pohon
{
  int info, harga;
  string nama;
  Pohon *kanan, *kiri;
};
Pohon *akar, *p, *b, *root;

// void pohon
void sisipptb(int IB, string nama, int harga);
void buat_ptb()
{
  Pohon *ptb = NULL;
  akar = ptb;
}
int ptb_kosong()
{
  if (akar == NULL)
    return (true);
  else
    return (false);
}
void postorder(Pohon *akar);

void cariptb();

// void menu
void input();
void keluar();
void tampil();
void cari();

int main()
{
  int pilmenu;
  char ulang;
  buatHashTable();

  do
  {
    system("cls");
    cout << string(52, '=') << endl;
    cout << "|" << right << setw(48) << setfill(' ') << "SELAMAT DATANG DI TOKO KELONTONG (SERBA ADA) "
         << setw(3) << setfill(' ') << "|" << endl;
    cout << string(52, '-') << endl;
    cout << "Menu :\n"
         << "1. Input Produk (hash)\n"
         << "2. Tampilkan Produk (hash)\n"
         << "3. Cari Produk (ptb)\n"
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
      cout << "Kembali ke menu ?[y/n]";
      cin >> ulang;
      break;
    case 2:
      tampil();
      cout << "Kembali ke menu ?[y/n]";
      cin >> ulang;
      break;
    case 3:
      cariptb();
      cout << "Kembali ke menu ?[y/n]";
      cin >> ulang;
      break;
    case 4:
      postorder(akar);
      cout << "Kembali ke menu ?[y/n]";
      cin >> ulang;
      break;
    // case 4 : hapus();
    // cout << "Kembali ke menu ?[y/n]";cin >>ulang;
    //     break;
    default:
      ulang = 'n';
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
       << "=================================" << endl
       << "|  SAMPAI JUMPA LAGI /(^ _ ^)/  |" << endl
       << "=================================" << endl
       << endl;

  system("pause");
  system("exit");
}

void input()
{
  int id, harga, jum;
  string nama;
  system("cls");
  cout << "----------------------------"
       << "\n||       MENU INPUT       ||"
       << "\n----------------------------\n";
  cout << "Masukkan jumlah produk : ";
  cin >> jum;
  for (int i = 0; i < jum; i++)
  {
    cout << "\nProduk ke-" << i + 1;
    cout << "\nID produk\t: ";
    cin >> id;
    cout << "Nama produk\t: ";
    getline(cin >> ws, nama);
    cout << "harga produk\t: ";
    cin >> harga;

    sisipHash(id, nama, harga);
    sisipptb(id, nama, harga);
  }

  cout << "\n--------------------------"
       << "\n|  PRODUK TELAH DIINPUT  |"
       << "\n--------------------------\n";
}

void tampil()
{
  int num = 1;
  system("cls");
  cout << "----------------------------"
       << "\n||     MENU TAMPILAN      ||"
       << "\n----------------------------\n";
  cout << "\nTampilan Hash\n";
  bacaHash();
  cout << "\nTampilan Produk\n";
  for (int i = 0; i < 10; i++)
  {
    if (awal[i] != 0)
    {
      bantu = awal[i];
      cout << "\n\nProduk ke-" << num++
           << "\nID\t: " << bantu->info
           << "\nNama\t: " << bantu->nama
           << "\nHarga\t: Rp" << bantu->harga;
      while (bantu->kanan != NULL)
      {
        bantu = bantu->kanan;
        cout << "\n\nProduk ke-" << num++
             << "\nID\t: " << bantu->info
             << "\nNama\t: " << bantu->nama
             << "\nHarga\t: Rp" << bantu->harga;
      }
    }
  }
  cout << endl;
}

void cari()
{
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
      cout << endl
           << bantu->info;
      while (bantu->kanan != NULL)
      {
        bantu = bantu->kanan;
        cout << " -> " << bantu->info;
      }
      cout << endl;
    }
  }
}

void hapusHash(int IH)
{
  int i = IH % 10;

  if (awal[i] == NULL)
  {
    cout << "List masih kosong";
  }
  else if (awal[i]->info == IH)
  {
    hapus = awal[i]; // Hapus di awal[i]
    awal[i] = hapus->kanan;
    if (awal[i] != NULL)
    {
      awal[i]->kiri = NULL;
    }
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
        akhir[i] = bantu;
        akhir[i]->kanan = NULL;
      }
      else
      { // Hapus di tengah
        bantu->kanan = hapus->kanan;
        hapus->kanan->kiri = bantu;
      }
      free(hapus);
    }
    else
    {
      cout << "Node tidak ditemukan!\n";
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

// void sisipptb(int IB, string nama, int harga)
// {
//   Pohon *NB;
//   NB = new Pohon();
//   NB->info = IB;
//   NB->nama = nama;
//   NB->harga = harga;
//   NB->kiri = NULL;
//   NB->kanan = NULL;

//   if (ptb_kosong())
//   {
//     akar = NB;
//   }
//   else
//   {
//     b = akar;
//     p = akar;

//     // mencari tempat untuk sisip
//     while (p != NULL && strcmp(nama.c_str(), p->nama.c_str()) != 0)
//     {
//       b = p;
//       if (strcmp(nama.c_str(), p->nama.c_str()) < 0)
//         p = b->kiri;
//       else
//         p = b->kanan;
//     }

//     if (strcmp(nama.c_str(), b->nama.c_str()) == 0)
//     {
//       cout << "\n\nNode " << nama << " sudah ada !\n\n";
//     }
//     else
//     {
//       // masukin NB
//       if (strcmp(nama.c_str(), b->nama.c_str()) < 0)
//       {
//         b->kiri = NB;
//       }
//       else
//       {
//         b->kanan = NB;
//       }
//     }
//   }
// }

void postorder(Pohon *akar)
{
  if (akar != NULL)
  {
    postorder(akar->kanan);
    cout << "Kode  : " << akar->info << endl;
    cout << "Nama  : " << akar->nama << endl;
    cout << "Harga : " << akar->harga << endl;
    cout << endl;
    postorder(akar->kiri);
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
  cout << "-----------------------------"
       << "\n||     MENU PENCARIAN      ||"
       << "\n-----------------------------\n";
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
    cout << "\nProduk dengan nama " << targetNama << " tidak ditemukan.\n";
  }
}
