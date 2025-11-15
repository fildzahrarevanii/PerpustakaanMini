// denda.h - Header untuk fungsi denda
#ifndef DENDA_H
#define DENDA_H

// Fungsi untuk membaca setting denda dari file
int baca_setting_denda();

// Fungsi untuk menghitung selisih hari antara dua tanggal
int hitung_selisih_hari(char *tanggal1, char *tanggal2);

// Fungsi untuk menghitung denda
int hitung_denda(char *tanggal_peminjaman, char *tanggal_pengembalian, int denda_per_hari);

#endif
