
#include "stdio.h"
#include "stdlib.h"
#include "read_png.h"
#include "string.h" 

int main(int argc, char **argv) {
    if (argc < 2){
        printf("Uso: %s <arquivo.png>\n", argv[0]);
        return 1;
    }

    FILE *png = fopen(argv[1], "rb");
    if (png == NULL) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    //pula 8 bytes (assinatura do PNG)
    fseek(png, 8, SEEK_SET);

    //ler os chunks
    chunk_ler(png);

    fclose(png);
    return 0;

}