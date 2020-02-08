#include "book/prf.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "book/hex.h"
#include "gtest/gtest.h"
#include "test_common.h"

/*
[jdavies@localhost ssl]$ ./prf secret label seed 20
b5baf4722b91851a8816d22ebd8c1d8cc2e94d55
*/
TEST(PrfTest, TestBasic) {
  int secret_len;
  int label_len;
  int seed_len;
  unsigned char *secret;
  unsigned char *label;
  unsigned char *seed;

  secret_len =
      hex_decode(reinterpret_cast<const unsigned char *>("secret"), &secret);
  label_len =
      hex_decode(reinterpret_cast<const unsigned char *>("label"), &label);
  seed_len = hex_decode(reinterpret_cast<const unsigned char *>("seed"), &seed);
  int out_len = 20;
  std::vector<unsigned char> output(out_len + 1, 0);

  PRF(secret, secret_len, label, label_len, seed, seed_len, output.data(),
      out_len);
  EXPECT_HEX_EQ(output, "b5baf4722b91851a8816d22ebd8c1d8cc2e94d55");

  free(secret);
  free(label);
  free(seed);
}
