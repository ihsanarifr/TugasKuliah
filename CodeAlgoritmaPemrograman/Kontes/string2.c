#include <stdio.h>

int main() {
    char tab1='\x9';
    char tab2='\t';
    char line='\n';

    printf("a%cb%c", tab1, line);
    printf("a%cb%c", tab2, line);
    printf("%d - %d\n", tab1, tab2);

    return 0;
}
