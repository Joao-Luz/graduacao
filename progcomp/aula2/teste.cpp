#include <cstdio>

int main(){
    char s[100];

    scanf(" %*c");
    scanf(" %[^\n]", s);
    printf("%s", s);
}