#include <stdio.h>
#include <stdlib.h>

int graph(float values_arr[]){
    float count = -10.5;
    float x;
    double sc;
    int i = 0;
	int n;
    int errcode;

    for (sc = 10.0; sc >= -10.0; sc -= 0.5) {
        count += 0.5;
        for (i = 0; i <= 40; i++)
        {
            if ( (sc - 0.5 < values_arr[i]) && (values_arr[i] <= sc))
            {
              printf("@ ");
            }
            else {
                if (sc == 0 || i == 20) {
                  printf("# ");
                }
                else {
                  printf("  ");
                }
            }
        }
        printf("\n");
    }
	printf("\n");

	return 0;
}


int show_error(char error_msg[]) {
    printf("%s", error_msg);
	printf("\n");

    return 0;
}

int input(char func[]) {
    printf("y = ");
	gets(func);

	return 0;
}
