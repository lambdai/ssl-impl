

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>

#include "book/asn1.h"
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

TEST(Asn1Test, TestDer) {

  int certificate_file;
  struct stat certificate_file_stat;
  unsigned char *buffer, *bufptr;
  int buffer_size;
  int bytes_read;

  struct asn1struct certificate;
  const char *file_path;
  if ((certificate_file = open(file_path, O_RDONLY)) == -1) {
    FAIL() << ("Unable to open certificate file");
  }

  // Slurp the whole thing into memory
  if (fstat(certificate_file, &certificate_file_stat)) {
    FAIL() << ("Unable to stat certificate file");
  }

  buffer_size = certificate_file_stat.st_size;
  buffer = reinterpret_cast<unsigned char *>(malloc(buffer_size));

  if (!buffer) {
    FAIL() << ("Not enough memory");
  }

  bufptr = buffer;

  while (bytes_read = read(certificate_file, (void *)buffer,
                           certificate_file_stat.st_size)) {
    bufptr += bytes_read;
  }

  // XXX this overallocates a bit, since it sets aside space for markers, etc.
  unsigned char *pem_buffer = buffer;
  buffer = (unsigned char *)malloc(buffer_size);
  buffer_size = pem_decode(pem_buffer, buffer);
  free(pem_buffer);

  asn1parse(buffer, buffer_size, &certificate);

  asn1show(0, &certificate);

  asn1free(&certificate);
}
