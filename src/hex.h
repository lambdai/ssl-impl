#ifndef HEX_H
#define HEX_H

#ifdef __cplusplus
extern "C" {
#endif

int hex_decode(const unsigned char *input, unsigned char **decoded);
void show_hex(const unsigned char *array, int length);

#ifdef __cplusplus
}
#endif

#endif
