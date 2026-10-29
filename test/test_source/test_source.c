#include <stdio.h>
#include <stdlib.h>

#include "source.h"

int main() {
    SourceFile file = SourceFile_load("test_file.txt");
    if (file.content == NULL) {
        fprintf(stderr, "Failed to load source file\n");
        return 1;
    }

    char c;
    while ((c = SourceFile_ahead(&file)) != EOF) {
        printf("<%c, %zu, %zu> ", c, file.loc.line, file.loc.column);
    }

    SourceFile_free(&file);
    return 0;
}