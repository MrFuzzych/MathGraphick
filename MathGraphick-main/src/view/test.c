#include <stdio.h>

int input(char func[]) {
    printf("y = ");
	gets(func);

	//scanf("%s", func);
	//printf("%s", func);
	return 0;
}

int main(){
    char func[5];

    input(func);
    printf("\n%s\n", func);

    input(func);
    printf("\n%s\n", func);

    return 0;
}
