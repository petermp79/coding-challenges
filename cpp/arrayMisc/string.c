#include <stdio.h>
#include <string.h>

int main() {

    char ipv4[60] = "198.125.0.12";
    char ipv6[60] = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";

    // Note: ipv4 must be an array with extra space for modification.
    //       strtok() will modify ipv4 to return tokens
    //       declare ipv4 as 'char *' will lead to bus error
    //
    const char *dot = ".";
    char *token = strtok(ipv4, dot);

    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, dot);
    }

    const char *colon = ":";
    token = strtok(ipv6, colon);

    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, colon);
    }
}

