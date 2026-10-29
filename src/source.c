#include "source.h"

#include <stdio.h>
#include <stdlib.h>

SourceFile SourceFile_load(char* filename) {
    SourceFile source = {.filename = filename,
                         .length = 0,
                         .loc = {
                             .column = 0,
                             .line = 0,
                             .offset = 0,
                         }};
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Fail to read file %s", filename);
        return source;
    }
    size_t memsize = 64;
    char* content = (char*)malloc(memsize);
    size_t length = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {  // 内存中不应该存在EOF
        content[length++] = c;
        if (length >= memsize) {
            memsize <<= 1;
            content = realloc((void*)content, memsize);
        }
    }
    if (ferror(fp)) {
        perror("Error in fgetc");
        return source;
    }

    source.content = content;
    source.length = length;
    source.loc.line = 1;
    source.loc.column = 1;
    fclose(fp);
    return source;
}

char SourceFile_ahead(SourceFile* file) {
    static char c = EOF;
    if (c == EOF) {
        c = file->content[file->loc.offset];
        return c;
    }
    if (c == '\n') {
        file->loc.line++;
        file->loc.column = 1;
    } else {
        file->loc.column++;
    }
    file->loc.offset++;
    if(file->loc.offset >= file->length) {
        c = EOF;
        return EOF;
    }
    c = file->content[file->loc.offset];
    return c;
}
void SourceFile_free(SourceFile* file) {
    if (file->content != NULL) {
        free((void*)file->content);
        file->content = NULL;
    }
}