#ifndef KIKUKE_FILE_H
#define KIKUKE_FILE_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_PATH_SIZE 4096

#define DEFAULT_DIR_AUTH 0777

/**
 * path를 입력하면 해당 경로까지의 디렉토리를 생성합니다.
 * 리턴 값, 오류 값은 mkdir과 같습니다.
*/
int mkdirs(const char *path, unsigned int mode);

#ifdef __cplusplus
}
#endif

#endif