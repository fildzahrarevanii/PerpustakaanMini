#include "perpustakaan.h"

int main(void){
    ensure_data_files_exist();

    printf("=== SISTEM PERPUSTAKAAN MINI ===\n");

    if(!login_pustakawan()){
        printf("Login gagal. Program keluar.\n");
        return 0;
    }

    tampilkan_menu_utama();

    return 0;
}