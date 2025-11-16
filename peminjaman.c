// peminjaman.c
#include "perpustakaan.h" // Ditambahkan agar tahu fungsi dari file lain
#include "denda.h"        // Ditambahkan agar tahu fungsi hitung_denda
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struktur untuk transaksi peminjaman
// CATATAN: Ini adalah struct lokal, berbeda dari 'peminjaman' di perpustakaan.h
typedef struct {
    int id_transaksi;
    int id_anggota;
    int id_buku;
    char tanggal_peminjaman[11]; // Format: YYYY-MM-DD
    char tanggal_pengembalian[11]; // Kosong jika belum dikembalikan
    int denda;
} Transaksi;

// FUNGSI 'baca_setting_denda' DIHAPUS (sudah ada di denda.c)
// FUNGSI 'hitung_denda' DIHAPUS (sudah ada di denda.c)

// Fungsi untuk menyimpan transaksi ke file
void simpan_transaksi(Transaksi t) {
    FILE *file = fopen("data/peminjaman.txt", "a");
    if (!file) {
        printf("Error: Tidak dapat membuka peminjaman.txt\n");
        return;
    }
    fprintf(file, "%d %d %d %s %s %d\n", t.id_transaksi, t.id_anggota, t.id_buku, t.tanggal_peminjaman, t.tanggal_pengembalian, t.denda);
    fclose(file);
}

// Diubah: void peminjaman_buku() -> void pinjam_buku()
void pinjam_buku() {
    Transaksi t;
    printf("Masukkan ID Transaksi: ");
    scanf("%d", &t.id_transaksi);
    printf("Masukkan ID Anggota: ");
    scanf("%d", &t.id_anggota);
    printf("Masukkan ID Buku: ");
    scanf("%d", &t.id_buku);
    printf("Masukkan Tanggal Peminjaman (YYYY-MM-DD): ");
    scanf("%s", t.tanggal_peminjaman);
    strcpy(t.tanggal_pengembalian, ""); // Belum dikembalikan
    t.denda = 0;
    
    // Update status (asumsi: cetak pesan, dalam implementasi nyata update database)
    printf("Status buku %d: Dipinjam oleh anggota %d\n", t.id_buku, t.id_anggota);
    printf("Status anggota %d: Meminjam buku %d\n", t.id_anggota, t.id_buku);
    
    simpan_transaksi(t);
    printf("Peminjaman berhasil disimpan.\n");
}

// Diubah: void pengembalian_buku() -> void kembalikan_buku()
void kembalikan_buku() {
    int id_transaksi;
    char tanggal_pengembalian[11];
    printf("Masukkan ID Transaksi: ");
    scanf("%d", &id_transaksi);
    printf("Masukkan Tanggal Pengembalian (YYYY-MM-DD): ");
    scanf("%s", tanggal_pengembalian);
    
    // Baca transaksi dari file (sederhana: asumsikan file kecil)
    FILE *file = fopen("data/peminjaman.txt", "r");
    if (!file) {
        printf("Error: Tidak dapat membuka peminjaman.txt\n");
        return;
    }
    
    Transaksi t;
    int found = 0;
    FILE *temp = fopen("data/temp.txt", "w");
    while (fscanf(file, "%d %d %d %s %s %d", &t.id_transaksi, &t.id_anggota, &t.id_buku, t.tanggal_peminjaman, t.tanggal_pengembalian, &t.denda) != EOF) {
        if (t.id_transaksi == id_transaksi && strlen(t.tanggal_pengembalian) == 0) {
            strcpy(t.tanggal_pengembalian, tanggal_pengembalian);
            
            // Diubah: Memanggil fungsi yang benar dari util.c
            int denda_per_hari = get_denda_per_hari(); 
            // Memanggil fungsi dari denda.c
            t.denda = hitung_denda(t.tanggal_peminjaman, t.tanggal_pengembalian, denda_per_hari); 
            
            found = 1;
            printf("Denda: %d\n", t.denda);
            // Update status
            printf("Status buku %d: Tersedia\n", t.id_buku);
            printf("Status anggota %d: Tidak meminjam\n", t.id_anggota);
        }
        fprintf(temp, "%d %d %d %s %s %d\n", t.id_transaksi, t.id_anggota, t.id_buku, t.tanggal_peminjaman, t.tanggal_pengembalian, t.denda);
    }
    fclose(file);
    fclose(temp);
    remove("data/peminjaman.txt");
    rename("data/temp.txt", "data/peminjaman.txt");
    
    if (!found) {
        printf("Transaksi tidak ditemukan atau sudah dikembalikan.\n");
    } else {
        printf("Pengembalian berhasil.\n");
    }
}

// FUNGSI 'main' DIHAPUS (untuk menghindari error 'multiple definition')
