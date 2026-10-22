#include <stdio.h>

int main(){

    int table[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int key[] = {5, 29, 20, 0, 27, 18};
    int n = 6, size = 9;
    int x = 0;

    int chain[9][6];          // used only for separate chaining
    
    int chainLen[9] = {0};

    printf("bir islemin numarasi secin\n");
    printf("1-Seperate Chaining\n");
    printf("2-Linear Probing\n");
    printf("3-Quadratic Probing\n");
    printf("4-Double Hashing\n");
    scanf("%d", &x);

    for (int i = 0; i < n; i++){
        int h = key[i] % size;    
        int index = h;
        int j = 0;                
        int prime = 7;
        int h2 = prime - (key[i] % prime);

        if (x == 1){
            //ayrik zincirleme secildigi durumda//
            chain[h][chainLen[h]++] = key[i];
        }
        else {
            //linear, quadratic veya double hashing//
            while (table[index] != -1 && j < size){
                j++;
                if (x == 2)
                    index = (h + j) % size;
                else if (x == 3)
                    index = (h + j * j) % size;
                else
                    index = (h + j * h2) % size;
            }
            table[index] = key[i];
        }
    }

    // print once, after all keys are inserted
    if (x == 1){
        for (int i = 0; i < size; i++){
            printf("%d:", i);
            for (int j = 0; j < chainLen[i]; j++)
                printf(" %d", chain[i][j]);
            printf("\n");
        }
    }
    else {
        for (int i = 0; i < size; i++)
            printf("%d ", table[i]);
        printf("\n");
    }

    return 0;
}