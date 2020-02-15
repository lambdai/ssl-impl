#include "openssl/err.h"
#include "openssl/ssl.h"

/**
 * This example demonstrates how to set up a simple SSL BIO filter on an
 * existing connect BIO. This is useful in sutiations where cleartext
 * communication is upgraded to ciphertext communication.
 *
 * Compile with:
 *    gcc ssl_bio.c -lcrypto -lssl -o ssl_bio
 */

void handle_error(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  ERR_print_errors_fp(stderr);
  exit(1);
}

int main(void) {
  SSL_load_error_strings();
  SSL_library_init();

  SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_client_method());
  if (!ssl_ctx) handle_error("Failed creating SSL context");

  SSL *ssl = SSL_new(ssl_ctx);
  if (!ssl) handle_error("Failed allocating SSL structure");

  SSL_set_connect_state(ssl);

  /* Create SSL filter BIO. Data that passes through this filter will be
   * encrypted. Also handles handshake when needed.
   */
  BIO *ssl_bio = BIO_new(BIO_f_ssl());
  if (!ssl_bio) handle_error("Failed creating SSL BIO");

  BIO_set_ssl(ssl_bio, ssl, BIO_CLOSE);

  /* Creates a BIO of method BIO_s_connect and sets hostname and port. */
  BIO *bio = BIO_new_connect("example.com:https");
  if (!bio) handle_error("Failed creating connect BIO");

  /* Create a BIO of method BIO_s_file, for writing to stdout. */
  BIO *out = BIO_new_fp(stdout, BIO_NOCLOSE);
  if (!out) handle_error("Failed creating file BIO");

  if (BIO_do_connect(bio) <= 0) handle_error("Error connecting to server");

  BIO_push(ssl_bio, bio);

  if (BIO_puts(ssl_bio, "GET https://www.example.com/ HTTP/1.1\n\n") <= 0)
    handle_error("Failed writing request");

  char buf[1024];
  for (;;) {
    int len = BIO_read(ssl_bio, buf, sizeof(buf));

    if (len == 0) break;

    if (len < 0) handle_error("Failed reading response data");

    BIO_write(out, buf, len);
  }

  BIO_free(bio);
  BIO_free(ssl_bio);
  BIO_free(out);

  SSL_CTX_free(ssl_ctx);
  ERR_free_strings();

  return 0;
}