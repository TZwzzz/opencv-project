#ifndef PUTURLPIC_H_
#define PUTURLPIC_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *md5;
} json_data_t;
int putUrlPic(const char *picName);

#endif