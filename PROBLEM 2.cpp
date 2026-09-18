#include <iostream>

using namespace std;

// Fungsi buatan sendiri untuk menghitung panjang string manual (tanpa <string>)
int hitungPanjang(char teks[]) {
    int panjang = 0;
    while (teks[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

// Fungsi buatan sendiri untuk mendapatkan posisi alfabet (A=1, B=2, ..., Z=26)
int posisiAlfabet(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    return 0;
}

// Fungsi buatan sendiri untuk mengembalikan angka posisi menjadi huruf kapital
char hurufAlfabet(int nilai) {
    return (char)('A' + nilai - 1);
}

// Fungsi utama proses enkripsi Sandi Alien
void prosesSandiAlien(char pesanAsli[]) {
    char pesanSandi[100];
    int panjang = hitungPanjang(pesanAsli);

    if (panjang == 0) return;

    // Sesuai flowchart: PESAN_SANDI = PESAN_ASLI[0] (huruf pertama tidak berubah)
    pesanSandi[0] = pesanAsli[0];

    // Sesuai flowchart: I = 2 (dalam array C++, indeks dimulai dari 1 untuk huruf kedua)
    for (int i = 1; i < panjang; i++) {
        int nilaiSebelumnya = posisiAlfabet(pesanAsli[i - 1]);
        int nilaiSekarang = posisiAlfabet(pesanAsli[i]);

        int nilaiBaru = nilaiSekarang + nilaiSebelumnya;

        // Pengecekan kondisi: APAKAH NILAI_BARU > 26?
        if (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }

        pesanSandi[i] = hurufAlfabet(nilaiBaru);
    }

    // Menandai akhir dari string
    pesanSandi[panjang] = '\0';

    // TAMPILKAN PESAN_SANDI
    cout << "PESAN_SANDI: " << pesanSandi << endl;
}

int main() {
    char pesanAsli[100];

    // MASUKKAN PESAN_ASLI
    cout << "MASUKKAN PESAN_ASLI: ";
    cin >> pesanAsli;

    prosesSandiAlien(pesanAsli);

    return 0;
}
