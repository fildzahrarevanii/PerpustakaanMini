#include "perpustakaan.h"

void tampilkan_menu_utama(){
    int pilih;
    do{
        clear_screen();
        garis();
        printf("=== SISTEM PERPUSTAKAAN MINI\n");
        garis();
        printf("1. Kelola Buku\n");
        printf("2. Kelola Anggota");
        printf("3. Peminjaman Buku\n");
        printf("4. Pengembalian Buku");
        printf("5. Cari Buku\n");
        printf("6. Lihat Riwayat Peminjaman\n");
        printf("7. Lihat Ranking Buku\n");
        printf("8. Ubah Batas Peminjaman\n");
        printf("9. Keluar\n");
        garis();
        printf("Pilih menu: ");
        scanf("%d", &pilih);

        switch(pilih){
            case 1: tambah_buku();
            break;

            case 2: tambah_anggota();
            break;

            case 3: pinjam_buku();
            break;

            case 4: kembalikan_buku();
            break;

            case 5: cari_buku();
            break;

            case 6: liat_riwayat_anggota();
            break;

            case 7: tampilkan_ranking_buku();
            break;

            case 8: ubah_batas_pinjam();
            break;

            case 9: printf("Keluar dari sistem.\n");
            break;

            default: printf("Pilihan tidak valid!\n");
            break;
        }

        pause_program();
    } 
    
    while (pilih != 9);
}

int main(){
    ensure_data_files_exist(FILE_BUKU);
    ensure_data_files_exist(FILE_ANGGOTA);
    ensure_data_files_exist(FILE_PINJAMAN);
    ensure_data_files_exist(FILE_LOGIN);
    ensure_data_files_exist(FILE_SETTING);

    if(login_pustakawan()){
        tampilkan_menu_utama();
    }

    else{
        printf("Login gagal!\n");
    }

    return 0;
}