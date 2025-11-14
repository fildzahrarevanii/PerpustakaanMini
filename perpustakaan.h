// Header utama: deklarasi struct & prototype fungsi untuk Perpustakaan Mini

#ifndef PERPUSTAKAAN_H
#define PERPUSTAKAAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 200

// path file data
#define FILE_BUKU "data/buku.txt"
#define FILE_ANGGOTA "data/anggota.txt"
#define FILE_PINJAMAN "data/peminjaman.txt"
#define FILE_LOGIN "data/login.txt"
#define FILE_SETTING "data/setting.txt"
#define TEMP_FILE "data/temp.txt"

// struktur data
typedef struct {
    int id;              
    char judul[100];
    char penulis[100];
    char kategori[30];      // Fiksi, Non-Fiksi, Komik, Majalah, Referensi
    int tersedia;           // 1 = tersedia, 0 = dipinjam
    int jumlah_dipinjam;     // untuk ranking
} buku;

typedef struct {
    int id;
    char nama[100];
    char alamat[200];
    char no_telp[25];
} anggota;

typedef struct {
    int id_peminjaman;
    int id_buku;
    int id_anggota;
    char tanggal_pinjam[20];   // format YYYY-MM-DD
    char tanggal_kembali[20];  // saat pinjam
    int status;               // 0 = belum kembali, 1 = sudah
    int denda;                // denda saat dikembalikan
} peminjaman;

// prototype fungsi

// menu.c
void tampilkan_menu_utama();
void tampilkan_sub_menu_buku();
void tampilkan_sub_menu_peminjaman();

// login.c
int login_pustakawan();

// buku.c
void tambah_buku();
void hapus_buku();
void edit_buku();
void tampilkan_daftar_buku();
void cari_buku();
void kategorikan_buku();

// anggota.c
void tambah_anggota();
void tampilkan_daftar_anggota();
void lihat_riwayat_anggota(int id_anggota);

// peminjaman.c
void pinjam_buku();
void kembalikan_buku();

// denda.c
int hitung_denda(const char *tanggal_pinjam, const char *tanggal_kembali);

// ranking.c
void tampilkan_ranking_buku();

// filehandler.c
FILE* buka_file(const char *path, const char *mode);
void ensure_data_files_exist();

// util.c
void clear_screen();
void pause_screen();
int baca_batas_pinjam();

#endif
