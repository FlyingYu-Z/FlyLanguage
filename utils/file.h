

#ifndef CHECKSHELL_FILE_H
#define CHECKSHELL_FILE_H

#include <cstdio>

//char* getPathByFD(int fd);
long getFileLength(const char *path);
long getFileLength(FILE *file);
char *read_file(const char *path, int &size);
char *read_txt_content(const char* textPath);
int write_file(const char *path, char *data, int size);

#endif //CHECKSHELL_FILE_H
