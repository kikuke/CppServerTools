#include <string.h>
#include <sys/stat.h>

#include "file.h"

int mkdirs(const char *path, unsigned int mode) {
    char path_buf[MAX_PATH_SIZE] = {};
    char *dir_p = path_buf;

    strcpy(path_buf, path);

    while(*dir_p) {
        if (*dir_p == '/') {
            *dir_p = '\0';
            mkdir(path_buf, mode);
            *dir_p = '/';
        }

        dir_p++;
    }
    return mkdir(path, mode);
}