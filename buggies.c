#include <stdio.h>
#include<stdlib.h>

int main() {

    int buggies, count;
    scanf("%d", &buggies);
    int quant_no_bug[buggies];
    int guarda[buggies], count_1 = 0;
    char chr;

    for(count = 0; count <buggies; count++){
        scanf("%d", &quant_no_bug[count]);
    }

    while((scanf("%c", &chr) != EOF)){
        
        int soma = 0, posicao;
        scanf("%d", &posicao);
        if(chr == 'a'){
            quant_no_bug[posicao - 1] = 0;
        }
         
        else if(chr == '?'){
            for(count = 0; count< (posicao - 1); count++){
                soma += quant_no_bug[count];
            }
            guarda[count_1] = soma;
            count_1++;
        }

    }

    for(count = 0; count < count_1; count++){
        printf("%d\n",guarda[count]);
    }

    return 0;
    
}