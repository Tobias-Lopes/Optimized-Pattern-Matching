#include <stdio.h>
#include <string.h>

void acharpadrao(char texto[], char padrao[]){
    int length = strlen(texto);
    int tamanhofinal = strlen(padrao);
    int achou = 0;

    for (int i = 0; i <= length - tamanhofinal; ++i){
        int j;
        for (j = 0; j < tamanhofinal; ++j){
            printf("%c ", texto[i+j]);
            if (texto[i+j] != padrao[j]){
                printf("não\n");
                break;
            }
        }
        if (j == tamanhofinal){
            printf("sim\n");
            achou = 1;
            printf("Achei o padrão no índice %d\n", i);
            break;
        }
    }
    if (!achou) {
        printf("Não achei o padrão\n");
    }
}

int main(){
    char texto[50];
    char padrao[50];

    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = 0;

    fgets(padrao, sizeof(padrao), stdin);
    padrao[strcspn(padrao, "\n")] = 0;

    acharpadrao(texto, padrao);

    return 0;
}

