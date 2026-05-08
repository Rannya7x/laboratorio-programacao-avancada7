#ifndef READ_PNG_H
#define READ_PNG_H

struct png_chunk_hdr {
    int length;
    char type[4];
}__attribute__((packed));

struct png_ihdr {
    int width;
    int height;
    unsigned char bit_depth;
    unsigned char color_type;
    unsigned char compression;
    unsigned char filter;
    unsigned char interlace;
}__attribute__((packed));

void chunk_ler(FILE *png_file);

#endif