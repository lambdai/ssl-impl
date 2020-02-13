#include "test_common.h"

#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"

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

void EXPECT_HEX_EQ(const std::vector<unsigned char> &lhs,
                   const std::string &rhs) {
  std::vector<char> display(lhs.size() * 2 + 32, '0');
  for (int i = 0; i < lhs.size(); i++) {
    sprintf(display.data() + i * 2, "%.02x", lhs[i]);
  }
  std::string display_as_string(display.begin(), display.begin() + rhs.size());
  EXPECT_EQ(display_as_string, rhs);
}