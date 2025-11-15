// peminjaman.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struktur untuk transaksi peminjaman
typedef struct {
    int id_transaksi;
    int id_anggota;
    int id_buku;
    char tanggal_peminjaman[11]; // Format: YYYY-MM-DD
    char tanggal_pengembalian[11]; // Kosong jika belum dikembalikan
    int denda;
} Transaksi;

// Fungsi untuk membaca setting denda dari file
int baca_setting_denda() {
    FILE *file = fopen("data/setting.txt", "r");
    if (!file) {
        printf("Error: Tidak dapat membuka setting.txt\n");
        return 0;
    }
    char line[100];
    int denda = 0;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "denda_per_hari: %d", &denda) == 1) {
            break;
        }
    }
    fclose(file);
    return denda;
}

// Fungsi untuk menghitung denda (dipanggil dari denda.c jika diperlukan)
int hitung_denda(char *tanggal_peminjaman, char *tanggal_pengembalian, int denda_per_hari) {
    // Sederhana: asumsikan tanggal dalam format YYYY-MM-DD
    // Hitung selisih hari (implementasi sederhana, tidak akurat untuk bulan/tahun)
    int tahun1, bulan1, hari1, tahun2, bulan2, hari2;
    sscanf(tanggal_peminjaman, "%d-%d-%d", &tahun1, &bulan1, &hari1);
    sscanf(tanggal_pengembalian, "%d-%d-%d", &tahun2, &bulan2, &hari2);
    
    // Hitung selisih hari (asumsi bulan 30 hari, tahun 365 hari untuk kesederhanaan)
    int hari_peminjaman = hari1 + bulan1 * 30 + tahun1 * 365;
    int hari_pengembalian = hari2 + bulan2 * 30 + tahun2 * 365;
    int selisih = hari_pengembalian - hari_peminjaman;
    
    if (selisih > 7) { // Asumsi batas 7 hari tanpa denda
        return (selisih - 7) * denda_per_hari;
    }
    return 0;
}

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

// Fungsi untuk peminjaman buku
void peminjaman_buku() {
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

// Fungsi untuk pengembalian buku
void pengembalian_buku() {
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
            int denda_per_hari = baca_setting_denda();
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

int main() {
    int pilihan;
    while (1) {
        printf("\nMenu:\n1. Peminjaman Buku\n2. Pengembalian Buku\n3. Keluar\nPilih: ");
        scanf("%d", &pilihan);
        if (pilihan == 1) {
            peminjaman_buku();
        } else if (pilihan == 2) {
            pengembalian_buku();
        } else if (pilihan == 3) {
            break;
        } else {
            printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
} 