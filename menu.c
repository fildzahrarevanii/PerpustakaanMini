// menu.c
// menampilkan menu utama dan memanggil fungsi-fungsi fitur

#include "perpustakaan.h"

// menu utama
void tampilkanMenuUtama() {
    int pilihan;
    do {
        clearScreen();
        printf("=== MENU UTAMA ===\n");
        printf("1. Kelola Buku\n");
        printf("2. Kelola Anggota\n");
        printf("3. Peminjaman / Pengembalian\n");
        printf("4. Rangking Buku Populer\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        if (scanf("%d", &pilihan) != 1) {
            while(getchar()!='\n');
            pilihan = 0;

        }
        getchar();

        switch (pilihan) {
            case 1:
                tampilkanSubMenuBuku();
                break;
            case 2:
                clearScreen();
                tampilkanDaftarAnggota();
                pauseScreen();
                break;
            case 3:
                tampilkanSubMenuPeminjaman();
                break;
            case 4:
                clearScreen();
                tampilkanRangkingBuku();
                pauseScreen();
                break;
            case 5:
                printf("Keluar. Terima Kasih.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                pauseScreen();

        }
    } while (pilihan != 5);
}


// submenu buku
void tampilkanSubMenuBuku() {
    int pilih;
    do {
        clearScreen();
        printf("=== MENU BUKU ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Hapus Buku\n");
        printf("3. Edit Buku\n");
        printf("4. Tampilkan Semua Buku\n");
        printf("Cari Buku\n");
        printf("6. Kembali\n");
        printf("Pilih: ");
        if (scanf("%d", &pilih) != 1) {
            while(getchar()!='\n');
            pilih = 0;

        }
        getchar();

        switch (pilih) {
            case 1: tambahBuku(); pauseScreen(); break;
            case 2: hapusBuku(); pauseScreen(); break;
            case 3: editBuku(); pauseScreen(); break;
            case 4: clearScreen(); tampilkanDaftarBuku(); pauseScreen(); break;
            case 5: cariBuku(); pauseScreen(); break;
            case 6: break;
            default: printf("Pilihan tidak valid.\n"); pauseScreen();

        }
    } while (pilih != 6);
}


// submenu peminjaman
void tampilkanSubMenuPeminjaman() {
    int pilih;
    do {
        clearScreen();
        printf("=== MENU PEMINJAMAN ===\n");
        printf("1. Pinjam Buku\n");
        printf("2. Kembalikan Buku\n");
        printf("3. Lihat Riwayat Anggota\n");
        printf("4. Kembali\n");
        printf("Pilih: ");
        if (scanf("%d", &pilih) != 1) {
            while(getchar()!='\n');
            pilih = 0;

        }
        getchar();

        switch (pilih) {
            case 1: pinjamBuku(); pauseScreen(); break;
            case 2: kembalikanBuku(); pauseScreen(); break;
            case 3: {
                int id; printf("Masukkan ID Anggota: "); 
                        scanf("%d", &id); getchar();
                        lihatRiwayatAnggota(id); pauseScreen(); break;

            }
            
            case 4: break;
            default: printf("Pilihan tidak valid.\n");
            pauseScreen();

        } 
    } while (pilih != 4);
}