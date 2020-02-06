

#include "book/x509.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>

#include "book/asn1.h"
#include "gtest/gtest.h"

TEST(X509Test, TestDer) {
  int certificate_file;
  struct stat certificate_file_stat;
  char *buffer, *bufptr;
  int buffer_size;
  int bytes_read;
  int error_code;

  signed_x509_certificate certificate;
  std::string file_path =
      "/home/lambdai/workspace/tlsimpl/src/data/book/cert1.der";

  if ((certificate_file = open(file_path.data(), O_RDONLY)) == -1) {
    FAIL() << ("Unable to open certificate file");
  }

  // Slurp the whole thing into memory
  if (fstat(certificate_file, &certificate_file_stat)) {
    FAIL() << ("Unable to stat certificate file");
  }

  buffer_size = certificate_file_stat.st_size;
  buffer = (char *)malloc(buffer_size);
  if (!buffer) {
    FAIL() << ("Not enough memory");
  }

  bufptr = buffer;

  while ((bytes_read = read(certificate_file, (void *)buffer, buffer_size))) {
    bufptr += bytes_read;
  }

  // // XXX this overallocates a bit, since it sets aside space for markers,
  // etc.
  // unsigned char *pem_buffer = reinterpret_cast<unsigned char *>(buffer);
  // buffer = reinterpret_cast<char *>(malloc(buffer_size));
  // buffer_size =
  //     pem_decode(pem_buffer, reinterpret_cast<unsigned char *>(buffer));
  // free(pem_buffer);

  // now parse it
  init_x509_certificate(&certificate);
  if (!(error_code =
            parse_x509_certificate(reinterpret_cast<unsigned char *>(buffer),
                                   buffer_size, &certificate))) {
    printf("X509 Certificate:\n");
    display_x509_certificate(&certificate);

    // Assume it's a self-signed certificate and try to validate it that
    switch (certificate.algorithm) {
      case md5WithRSAEncryption:
      case shaWithRSAEncryption:
        if (validate_certificate_rsa(
                &certificate, &certificate.tbsCertificate.subjectPublicKeyInfo
                                   .rsa_public_key)) {
          printf("Certificate is a valid self-signed certificate.\n");
        } else {
          printf("Certificate is corrupt or not self-signed.\n");
        }
        break;
      case shaWithDSA:
        if (validate_certificate_dsa(&certificate)) {
          printf("Certificate is a valid self-signed certificate.\n");
        } else {
          printf("Certificate is corrupt or not self-signed.\n");
        }
    }
  } else {
    printf("error parsing certificate: %d\n", error_code);
  }

  free_x509_certificate(&certificate);
  free(buffer);
}
