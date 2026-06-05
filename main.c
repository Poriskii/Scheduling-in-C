#include <stdio.h>
#include "funções.c"

int main() {
    char escolha;

    printf("Deseja marcar uma consulta ?(s/n)");
    scanf("%s", &escolha);

if(escolha == 's' || escolha == 'S'){    
    Dados();
    }
    return 0;
}
