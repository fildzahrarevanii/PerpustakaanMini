// fungsi untuk membuka file dan memastikan folder data & file default ada

#include "perpustakaan.h"

#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

// buka file dengan mode, jika gagal kembalikan NULL
FILE* buka_file(const char *path, const char *mode){
    FILE *f = fopen(path, mode);
    return f;
}

void ensure_data_files_exist(){

#ifdef _WIN32
    struct stat st = {0};
    if(stat("data", &st) == -1) mkdir("data", 0755);
#else
    _mkdir
}