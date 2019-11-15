//Uva 272 TEXquotes (ACEPTADO)
#include <cstdio>
using namespace std;

int main(void){
    int count = 2;
    char caracter;
    while(scanf("%c",&caracter)==1){
        if(caracter == '"'){
            if(count%2 == 0){
                printf("``");
            }
            else if(count%2 != 0){
                printf("''");
            }
            count++;
        }
        else{
            printf("%c",caracter);
        }
    }
    return 0;
}

