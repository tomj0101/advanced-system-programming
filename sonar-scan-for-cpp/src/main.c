/*
This program first checks if the in_data string is empty. 
If it's empty, it prints the "string is empty" message. 
If the string is not empty and has at least two characters, 
it prints the last two characters. If the string has less than two characters, it prints a message accordingly.
*/
#include <stdio.h>
#include <string.h>

int main() {
    char in_data[] = "this is the new way to code";

    if (strlen(in_data) == 0) {
        printf("String is empty\n");
    } else if (strlen(in_data) >= 2) {
        printf("Last two characters: %c%c\n", in_data[strlen(in_data) - 2], in_data[strlen(in_data) - 1]);
    } else {
        printf("String has less than two characters\n");
    }

    return 0;
}