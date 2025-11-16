// menu.c
// menampilkan menu utama dan memanggil fungsi-fungsi fitur

#include "perpustakaan.h"

// menu utama
void tampilkan_menu_utama() {
    int pilihan;
    do {
        clear_screen(); 
        printf("=== MENU UTAMA ===\n");
        printf("1. Kelola Buku\n");
        // DIHAPUS: 2. Kelola Anggota
        printf("2. Peminjaman / Pengembalian\n");
        // DIHAPUS: 4. Rangking Buku Populer
        printf("3. Keluar\n"); // Dinomori ulang
        printf("Pilih: ");
        if (scanf("%d", &pilihan) != 1) {
            while(getchar()!='\n');
            pilihan = 0;
        }
        getchar();

        switch (pilihan) {
            case 1:
                tampilkan_sub_menu_buku();
                break;
            case 2: // Dinomori ulang
                tampilkan_sub_menu_peminjaman();
                break;
            case 3: // Dinomori ulang
                printf("Keluar. Terima Kasih.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                pause_screen(); 
        }
    } while (pilihan != 3); // Diubah dari 5 menjadi 3
}


// submenu buku
void tampilkan_sub_menu_buku() {
    int pilih;
    do {
        clear_screen(); 
        printf("=== MENU BUKU ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Hapus Buku\n");
        printf("3. Edit Buku\n");
        printf("4. Tampilkan Semua Buku\n");
        printf("5. Cari Buku\n"); 
        printf("6. Kembali\n");
        printf("Pilih: ");
        if (scanf("%d", &pilih) != 1) {
            while(getchar()!='\n');
            pilih = 0;
        }
        getchar();

        switch (pilih) {
            case 1: tambah_buku(); pause_screen(); break; 
            case 2: hapus_buku(); pause_screen(); break; 
            case 3: edit_buku(); pause_screen(); break; 
            case 4: clear_screen(); tampilkan_daftar_buku(); pause_screen(); break; 
            case 5: cari_buku(); pause_screen(); break; 
            case 6: break;
            default: printf("Pilihan tidak valid.\n"); pause_screen(); 
        }
    } while (pilih != 6);
}


// submenu peminjaman
void tampilkan_sub_menu_peminjaman() {
    int pilih;
    do {
        clear_screen(); 
        printf("=== MENU PEMINJAMAN ===\n");
        printf("1. Pinjam Buku\n");
        printf("2. Kembalikan Buku\n");
        // DIHAPUS: 3. Lihat Riwayat Anggota
        printf("3. Kembali\n"); // Dinomori ulang
        printf("Pilih: ");
        if (scanf("%d", &pilih) != 1) {
            while(getchar()!='\n');
            pilih = 0;
        }
        getchar();

        switch (pilih) {
            case 1: pinjam_buku(); pause_screen(); break; 
            case 2: kembalikan_buku(); pause_screen(); break; 
            case 3: // Dinomori ulang
                break;
            default: printf("Pilihan tidak valid.\n");
            pause_screen(); 
        } 
    } while (pilih != 3); // Diubah dari 4 menjadi 3
}
