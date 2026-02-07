#include <stdio.h>

int main() {
    char fullName[30];

    printf("Type your full name: \n");
    
    fgets(fullName, sizeof(fullName), stdin);

    printf("Hello %s", fullName);

    return 0;
}


// I used fgets because it says to use keyboard input in the instructions and this is what generally people mean when they say 'keyboard input'
