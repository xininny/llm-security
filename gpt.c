#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    close(fd); // 정상적인 파일 닫기

    // CWE-1341: 파일 디스크립터를 다시 닫음 (double close)
    close(fd); // 잘못된 동작: fd는 이미 닫혔음

    return 0;
}
