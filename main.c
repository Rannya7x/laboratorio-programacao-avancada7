''' Abrir um arquivo PNG, cujo nome será passado pela linha de comando (argv[1]), e imprimir o tamanho e o tipo detodos os chunks presentes nele, na ordem em que aparecem. Se for um chunk do tipo “IHDR”, imprima a largura e a altura da todos os chunks presentes nele, na ordem em que aparecem. Se for um chunk do tipo IHDR, imprima a largura e a altura da imagem PNG'''

#include "stdio.h"
#include "stdlib.h"
#include "read_png.h"

int main(int argc, char **argv[]) {
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

    //loop para ler os chunks

    fclose(png);
    return 0;

}