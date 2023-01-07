#include "file.h"
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "log.h"

#define SIZE 1024

//char* getPathByFD(int fd){
//    char path[1024]= {'\0'};
//    char buf[SIZE] = {'\0'};
//    snprintf(buf, sizeof(buf),"/proc/self/fd/%d",fd);
//    if(readlink(buf,path,SIZE)<0){
//        perror("readlink() error\n");
//    }
//    return path;
//}

long getFileLength(const char *path) {
    FILE *file=fopen(path,"r");
    long oldPos = ftell(file);
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, oldPos, SEEK_SET);
    return fileSize;
}

long getFileLength(FILE *file) {
    long oldPos = ftell(file);
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, oldPos, SEEK_SET);
    return fileSize;
}

char *read_file(const char *path, int &size) {
    FILE *fp = fopen(path, "rb+");
    if (!fp) {
        LOGD("[-]fopen %s error:%s", path, strerror(errno));
        return NULL;
    }
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char *base = (char *) calloc(size + 1, sizeof(char));
    if (!base) {
        LOGD("calloc memory failed");
        fclose(fp);
        return NULL;
    }
    fread(base, 1, size, fp);
    fclose(fp);
    return base;
}

char *read_txt_content(const char* textPath) {
    FILE *textFile= fopen(textPath, "r");
    if (!textFile) {
        LOGD("[-]read %s error:%s", textPath, strerror(errno));
    }
    fseek(textFile, 0L, SEEK_END);
    long fileSize = ftell(textFile);
    fseek(textFile, 0L, SEEK_SET);
    char *buffer = new char[fileSize];
    char tmp[1024] = {0};
    long readSize=0;
    long total=0;
    while ((readSize=fread(tmp, sizeof(char), 1024, textFile)) != 0) {
        memcpy(buffer,tmp,readSize);
        total+=readSize;
        fseek(textFile,total,SEEK_SET);
    }
    if (textFile != NULL) {
        fclose(textFile);
    }
    return buffer;
}

int write_file(const char *path, char *data, int size) {
    FILE *fp = fopen(path, "w");
    if (!fp) {
        LOGD("[-]fopen %s error:%s", path, strerror(errno));
        return 0;
    }
    fwrite(data, 1, size, fp);
    if (fp != NULL) {
        fclose(fp);
    }
    return 1;
}

