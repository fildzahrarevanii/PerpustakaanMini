#include "perpustakaan.h"

int main(){
    ensure_data_files_exist();

    clear_screen();
    printf("=== SISTEM PERPUSTAKAAN MINI ===\n\n");

    if(!login_pustakawan()){
        printf("\nLogin gagal. Program selesai.\n");
        
        return 0;
    }

    // jika login berhasil, tampilakn menu utama
    tampilkan_menu_utama();

    return 0;
}