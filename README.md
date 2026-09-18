# Pemrograman_MuhammadEzraZahran_Zircon_TLS26
#include <iostream>

using namespace std;

// Fungsi buatan sendiri untuk menghitung panjang array/jumlah elemen
int hitungPanjang(int arr[], int n) {
    return n;
}

// Fungsi untuk menjalankan logika eliminasi astronot
void prosesEliminasi(int n, int k) {
    int astronot[100];
    for (int i = 0; i < n; i++) {
        astronot[i] = i + 1;
    }

    int urutanEliminasi[100];
    int jumlahEliminasi = 0;
    int sisaAstronot = n;
    int posisi = 0;

    while (sisaAstronot > 1) {
        // Hitung posisi astronot yang keluar
        posisi = (posisi + k - 1) % sisaAstronot;
        
        int tereliminasikan = astronot[posisi];
        urutanEliminasi[jumlahEliminasi] = tereliminasikan;
        jumlahEliminasi++;

        // Hapus astronot yang tereliminasi dengan menggeser sisa elemen
        for (int i = posisi; i < sisaAstronot - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        sisaAstronot--;

        // Update nilai K berdasarkan nomor astronot yang keluar
        if (tereliminasikan % 2 == 0) {
            k = k + 2;
        } else {
            k = k - 1;
        }

        // Batas minimal K adalah 2
        if (k < 2) {
            k = 2;
        }
    }

    // Tampilkan urutan eliminasi
    cout << "Urutan eliminasi: ";
    for (int i = 0; i < jumlahEliminasi; i++) {
        cout << urutanEliminasi[i] << " ";
    }
    cout << endl;

    // Tampilkan astronot terakhir yang tersisa
    cout << "Astronot terakhir: " << astronot[0] << endl;
}

int main() {
    int n, k;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> n;
    cout << "Masukkan langkah awal (K): ";
    cin >> k;

    prosesEliminasi(n, k);

    return 0;
}
