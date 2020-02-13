#ifndef PRF_H
#define PRF_H

#ifdef __cplusplus
extern "C" {
#endif

void PRF(const unsigned char *secret, int secret_len,
         const unsigned char *label, int label_len, const unsigned char *seed,
         int seed_len, unsigned char *output, int out_len);

#ifdef __cplusplus
}
#endif

#endif
