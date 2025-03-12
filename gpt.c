#include <stdio.h>
#include <string.h>

void vulnerable_function(char *user_input) {
    char buffer[16]; // 크기가 16바이트인 버퍼 선언
    printf("Copying input into buffer...\n");

    // 🚨 취약점: strcpy()를 사용하여 입력을 제한 없이 복사
    strcpy(buffer, user_input);

    printf("Input copied successfully!\n");
}

int main() {
    char user_input[128]; // 사용자가 입력할 수 있는 공간 (버퍼보다 훨씬 큼)
    
    printf("Enter some text: ");
    fgets(user_input, sizeof(user_input), stdin); // 사용자 입력 받기

    // 개행 문자 제거
    user_input[strcspn(user_input, "\n")] = '\0';

    // 취약한 함수 호출
    vulnerable_function(user_input);

    return 0;
}
