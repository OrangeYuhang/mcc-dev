#ifndef _SOURCE_H_
#define _SOURCE_H_
#define MAX_SOURCE_NUM 10

#include <stddef.h>
#include <stdio.h>

typedef struct {
    size_t line;    // 行号
    size_t column;  // 列号
    size_t offset;  // 偏移量
} SourceLoc;

typedef struct {
    SourceLoc start;  // 起始位置
    SourceLoc end;    // 结束位置
} SourceSpan;

typedef struct {
    const char* filename;  // 文件名
    const char* content;   // 文件内容
    size_t length;         // 文件长度
    SourceLoc loc;         // 解析位置
} SourceFile;

SourceFile SourceFile_load(char*filename);  // NULL读取stdin
char SourceFile_ahead(SourceFile *file); //读取推进字母
void SourceFile_free(SourceFile *file); //释放内存

#endif  // _SOURCE_H_