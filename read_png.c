#include "stdio.h"
#include "stdlib.h"
#include "read_png.h"
#include "arpa/inet.h"
#include "string.h" 

void chunk_ler(FILE *png){
    struct  png_chunk_hdr header;
    int contador = 1;
    //le o cabeçalho
    while (fread(&header, sizeof(struct png_chunk_hdr), 1, png)==1){
        int length = ntohl(header.length);
        printf("Lendo chunk %d:\n", contador++);
        printf("    --> Tamanho: %d\n", length);
        printf("    --> Tipo:    %.4s\n", header.type);

        //trata cabecalho de image
        if(strncmp(header.type, "IHDR", 4) == 0){
            struct png_ihdr ihdr;
            fread(&ihdr, sizeof(struct png_ihdr), 1, png);

            printf("\t--> Largura: %d\n", ntohl(ihdr.width));
            printf("\t--> Altura:  %d\n", ntohl(ihdr.height));

            fseek(png, 4, SEEK_CUR); //pula CRC
        }

        //fim do arquivo
        else if(strncmp(header.type, "IEND", 4) == 0){
            break;
        }
        else{
            fseek(png, length + 4, SEEK_CUR);
        }
    }
    
}