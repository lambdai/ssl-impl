#include "src/digest.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "src/hex.h"
#include "src/md5.h"
#include "src/sha.h"

/*
jdavies@localhost$ digest -md5 abc
900150983cd24fb0d6963f7d28e17f72

jdavies@localhost$ digest -sha1 abc
a9993e364706816aba3e25717850c26c9cd0d89d
*/
void EXPECT_HEX_EQ(const std::vector<unsigned int> &lhs,
                   const std::string &rhs) {
  const unsigned char *display_hash =
      reinterpret_cast<const unsigned char *>(lhs.data());
  std::vector<char> display(lhs.size() * 4 * 2 + 32, '0');
  for (int i = 0; i < (lhs.size() * 4); i++) {
    sprintf(display.data() + i * 2, "%.02x", display_hash[i]);
  }
  std::string display_as_string(display.begin(), display.begin() + rhs.size());
  EXPECT_EQ(display_as_string, rhs);
}

TEST(DigestTest, TestMd5) {
  std::vector<unsigned int> hash(MD5_RESULT_SIZE);
  unsigned char *decoded_input;
  int decoded_len;
  unsigned char input[] = "abc";
  decoded_len = hex_decode(input, &decoded_input);
  std::copy(std::begin(md5_initial_hash), std::end(md5_initial_hash),
            hash.begin());

  digest_hash(decoded_input, decoded_len, hash.data(), md5_block_operate,
              md5_finalize);
  EXPECT_HEX_EQ(hash, "900150983cd24fb0d6963f7d28e17f72");
  free(decoded_input);
}

TEST(DigestTest, TestSha1) {
  std::vector<unsigned int> hash(SHA1_RESULT_SIZE);
  unsigned char *decoded_input;
  int decoded_len;
  unsigned char input[] = "abc";

  decoded_len = hex_decode(input, &decoded_input);
  std::copy(std::begin(sha1_initial_hash), std::end(sha1_initial_hash),
            hash.begin());

  digest_hash(decoded_input, decoded_len, hash.data(), sha1_block_operate,
              sha1_finalize);
  EXPECT_HEX_EQ(hash, "a9993e364706816aba3e25717850c26c9cd0d89d");
  free(decoded_input);
}
