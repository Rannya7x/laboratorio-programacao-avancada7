#ifndef READ_PNG_H
#define READ_PNG_H

struct png_chunk_hdr {
    int length;
    char type[4];
}__attribute__((packed));

struct png_chunk_idr {
    int width;
    int height;
    unsigned bit_depth;
    unsigned color_type;
    unsigned compression;
    unsigned filter;
    unsigned interlace;
}__attribute__((packed));

#endif