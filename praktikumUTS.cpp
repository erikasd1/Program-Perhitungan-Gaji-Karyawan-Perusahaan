#include <iostream>
using namespace std;

struct dataKaryawan {  //STRUKTUR UNTUK MENYIMPAN DATA KARYAWAN//
    string nama;
    char golongan;
    int gajiPokok;
    int jumlahAnak;
    int tunjanganAnak;
    int totalGaji;
    dataKaryawan *next, *prev;  //UNTUK PENGHUBUNG ANTAR LINKED LIST//
};

//POINTER GLOBAL UNTUK AWAL, AKHIR, BANTU, DAN BARU//
dataKaryawan *awal = NULL, *akhir = NULL, *bantu, *baru;

int gajiPokok(char golongan);
int tunjanganAnak(int jumlahAnak);

//FUNGSI UNTUK MEMASUKKAN DATA DI AWAL LINKED LIST//
void inputDataDepan(dataKaryawan* orng, int karyawan) {
    for (int i = 0; i < karyawan; i++) {
        cout << "Karyawan ke-" << i+1 << endl;
        cout << "Nama Karyawan: "; 
        cin.ignore();
        getline(cin, orng[i].nama);
        cout << "Golongan: "; cin >> orng[i].golongan;
        cout << "Jumlah Anak: "; cin >> orng[i].jumlahAnak;
        orng[i].gajiPokok = gajiPokok(orng[i].golongan);  //MENGHHITUNG GAJI POKOK DAN TOTAL GAJI//
        orng[i].tunjanganAnak = tunjanganAnak(orng[i].jumlahAnak);
        orng[i].totalGaji = orng[i].gajiPokok + orng[i].tunjanganAnak;
        cout << endl;

        baru = new dataKaryawan();  //MEMBUAT NODE BARU//
        baru->nama = orng[i].nama;
        baru->golongan = orng[i].golongan;
        baru->jumlahAnak = orng[i].jumlahAnak;
        baru->gajiPokok = orng[i].gajiPokok;
        baru->tunjanganAnak = orng[i].tunjanganAnak;
        baru->totalGaji = orng[i].totalGaji;

        if (awal == NULL) {   //SISIPKAN DI AWAL//
            awal = akhir = baru;
        } else {
            baru->next = awal;
            awal->prev = baru;
            awal = baru;
        }
    }
    system("cls");  //MEMBERSIHKAN LAYAR //
}

//FUNGSI UNTUK MEMASUKKAN DATA DI AKHIR LINKEDE LIST//
void inputDataBelakang(dataKaryawan* orng, int karyawan) {
    for (int i = 0; i < karyawan; i++) {
        cout << "Karyawan ke-"  << i+1 << endl;
        cout << "Nama Karyawan: "; 
        cin.ignore();
        getline(cin, orng[i].nama);
        cout << "Golongan: "; cin >> orng[i].golongan;
        cout << "Jumlah Anak: "; cin >> orng[i].jumlahAnak;
        orng[i].gajiPokok = gajiPokok(orng[i].golongan);  //HITUNG GAJI POKOK DAN TOTAL GAJI//
        orng[i].tunjanganAnak = tunjanganAnak(orng[i].jumlahAnak);
        orng[i].totalGaji = orng[i].gajiPokok + orng[i].tunjanganAnak;
        cout << endl;

        baru = new dataKaryawan();  //MEMBUAT NODE BARU//
        baru->nama = orng[i].nama;
        baru->golongan = orng[i].golongan;
        baru->jumlahAnak = orng[i].jumlahAnak;
        baru->gajiPokok = orng[i].gajiPokok;
        baru->tunjanganAnak = orng[i].tunjanganAnak;
        baru->totalGaji = orng[i].totalGaji;
        

        if (awal == NULL) {  //SISIPKAN DI AKHIR//
            awal = akhir = baru;
        } else {
            akhir->next = baru;
            baru->prev = akhir;
            akhir = baru;
        }
    }
    system("cls");  //MEMBERSIHKAN LAYAR//
}

//FUNGSI UNTUK OUTPUT DATA//
void outputData() {
    bantu = awal;
    while (bantu != NULL) {
        cout << "Nama Karyawan\t\t\t: " << bantu->nama << endl;
        cout << "Golongan Karyawan\t\t: " << bantu->golongan << endl;
        cout << "Gaji Pokok  Karyawan\t\t: " <<  bantu->gajiPokok << endl;
        cout << "Jumlah Anak Karyawan\t\t: " << bantu->jumlahAnak << endl;
        cout << "Tunjangan Anak\t\t\t: " << bantu->tunjanganAnak << endl;
        cout << "Total Gaji Karyawan\t\t: " << bantu->totalGaji << endl;
        bantu = bantu->next;
        cout << endl;
    }
    cout << endl;
}

//FUNGSI UTAMA//
int main() {
    int karyawan;
    char menu;

    cout << "Masukkan Jumlah Karyawan: "; cin >> karyawan;  //MEMASUKKAN JUMLAH KARYAWAN YANG INGIN DI INPUT//
    dataKaryawan *orng = new dataKaryawan[karyawan];

    do {
        cout << "========= DATA KARYAWAN PERUSAHAAN ESD =========" << endl;  //MENAMPILKAN PILIHAN MENU UNTUK INPUT DATA//
        cout << "Pilihan Menu:" << endl;
        cout << "a. Input Data Di Depan"  << endl;
        cout << "b. Input Data Di Belakang" << endl;
        cout << "c. Output Data" << endl;
        cout << "d. EXIT" << endl;
        cout << "Pilihan: "; cin >> menu;

        switch (menu) {
            case 'a':   //INPUT DATA DARI DEPAN 'a'//
                inputDataDepan(orng, karyawan);
                break;

            case 'b':  //INPUT DATA DARI BELAKANG 'b'//
                inputDataBelakang(orng, karyawan);
                break;

            case 'c':
                if (awal == NULL) {
                    cout << "DATA MASIH KOSONG!" << endl;  //JIKA DATA MASIH KONG//
                } else {
                    outputData();  //JIKA DATA TERISI DAN AKAN MENAMPILKAN DATA YANG DI INPUT//
                }
                break;

            default:
                cout << "====== EXIT ======";  //MENAMPILKAN 'EXIT'//
                break;
        }
    
    } while (menu <= 'c');

    delete[] orng;
    return 0;
}

int gajiPokok(char golongan) {  //MENGHITUNG GAJI POKOK BERDASARKAN GOLONGAN//
    if (golongan == 'A') {
        return 800000;
    } else if (golongan == 'B') {
        return 600000;
    } else if (golongan == 'C') {
        return 400000;
    } else {
        return 0;
    }
}

int tunjanganAnak(int jumlahAnak) {  //MENGHITUNG TUNJANGAN ANAK BERDASARKAN JUMLAH ANAK//
    if (jumlahAnak == 1 || jumlahAnak == 2) {
        return jumlahAnak * 200000;
    } else if (jumlahAnak > 2) {
        return 500000;
    } else {
        return 0;
    }
}
