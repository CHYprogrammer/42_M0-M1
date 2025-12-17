#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"  // ヘッダに上記関数群のプロトタイプ宣言

int main()
{
    int     fd;
    char    *line;
    
    fd = open("a.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
    
    printf("=== get_next_line テスト ===\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("line: [%s]\n", line);
        free(line);
    }
    close(fd);
    
    // 標準入力からもテスト
    printf("\n=== 標準入力テスト (Ctrl+D で終了) ===\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("stdin: [%s]\n", line);
        free(line);
    }
    
    return (0);
}
