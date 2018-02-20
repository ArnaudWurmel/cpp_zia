//
// Created by curzol_p on 20/02/18.
//

#include <arpa/inet.h>
#include "openssl/ssl.h"
#include "openssl/err.h"

#include <cstring>
#include <iostream>
#include "OpenSsl.hh"
# define PASSWORD "yolo"

zia::OpenSsl::OpenSsl()
{

}

zia::OpenSsl::OpenSsl(zia::api::ImplSocket *clientSocket)
{
  std::cout << "INIT SSL" << std::endl;
  enableConnection(clientSocket);
}

zia::OpenSsl::~OpenSsl()
{
/*  SSL_shutdown(_ssl);
  BIO_free_all(_bio);
  BIO_free_all(_accept_bio);*/
}

void zia::OpenSsl::initSsl()
{
  SSL_load_error_strings();
  ERR_load_crypto_strings();

  OpenSSL_add_all_algorithms();
  SSL_library_init();
}

bool zia::OpenSsl::getContext()
{
  _ctx = SSL_CTX_new(SSLv23_server_method());

  if (_ctx == nullptr) {
      std::cout << "ERR: Context" << std::endl;
      ERR_print_errors_fp(stderr);
      return false;
    }
  return true;
}

X509 *zia::OpenSsl::generateCertificate(EVP_PKEY *pkey)
{
  X509 *x509 = X509_new();
  X509_set_version(x509, 2);
  ASN1_INTEGER_set(X509_get_serialNumber(x509), 0);
  X509_gmtime_adj(X509_get_notBefore(x509), 0);
  X509_gmtime_adj(X509_get_notAfter(x509), (long)60*60*24*365);
  X509_set_pubkey(x509, pkey);

  X509_NAME *name = X509_get_subject_name(x509);
  X509_NAME_add_entry_by_txt(name, "C", MBSTRING_ASC, (const unsigned char*)"US", -1, -1, 0);
  X509_NAME_add_entry_by_txt(name, "FR", MBSTRING_ASC, (const unsigned char*)"yolo", -1, -1, 0);
  X509_set_issuer_name(x509, name);
  X509_sign(x509, pkey, EVP_md5());
  return x509;
}

EVP_PKEY *zia::OpenSsl::generatePrivateKey()
{
  EVP_PKEY *pkey = NULL;
  EVP_PKEY_CTX *pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
  EVP_PKEY_keygen_init(pctx);
  EVP_PKEY_CTX_set_rsa_keygen_bits(pctx, 2048);
  EVP_PKEY_keygen(pctx, &pkey);
  return pkey;
}

static int passwordCallback(char *buf, int size, int rwflag, void *password)
{
/*  (void)rwflag;

  strncpy(buf, (char *) (password), static_cast<size_t>(size));
  buf[size - 1] = '\0';
  return static_cast<int>(strlen(buf));*/
  if (size < (strlen(PASSWORD) + 1)) {
      return(0);
    }
  strcpy(buf, PASSWORD);
  return strlen(PASSWORD);
}

void zia::OpenSsl::setUpRsa()
{
  RSA *rsa = RSA_generate_key(512, RSA_F4, NULL, NULL);
  SSL_CTX_set_tmp_rsa(_ctx, rsa);
  RSA_free(rsa);
}

void zia::OpenSsl::genBio(int cfd)
{
  _ssl = SSL_new(_ctx);

  _accept_bio = BIO_new_socket(cfd, BIO_CLOSE);
  SSL_set_bio(_ssl, _accept_bio, _accept_bio);
  SSL_accept(_ssl);
  ERR_print_errors_fp(stderr);
  _bio = BIO_pop(_accept_bio);
}

void zia::OpenSsl::LoadCertificates(const char *CertFile, const char *KeyFile)
{
  /* set the local certificate from CertFile */
  if (SSL_CTX_use_certificate_file(this->_ctx, CertFile, SSL_FILETYPE_PEM) <= 0)
    {
      printf("LoadCertificates: use certificate_file\n");
      ERR_print_errors_fp(stderr);
      abort();
    }
  /* set the private key from KeyFile (may be the same as CertFile) */
  if (SSL_CTX_use_PrivateKey_file(this->_ctx, KeyFile, SSL_FILETYPE_PEM) <= 0)
    {
      printf("LoadCertificates: use PrivateKey_file\n");
      ERR_print_errors_fp(stderr);
      abort();
    }
  /* verify private key */
  if (!SSL_CTX_check_private_key(this->_ctx))
    {
      printf("LoadCertificates: check_private_key\n");
      fprintf(stderr, "Private key does not match the public certificate\n");
      abort();
    }
}

bool zia::OpenSsl::enableConnection(zia::api::ImplSocket *clientSocket)
{
  int cfd = clientSocket->getSocket();

  initSsl();
  if (!getContext())
    return false;

  EVP_PKEY *pkey = generatePrivateKey();
  X509 *x509 = generateCertificate(pkey);

  SSL_CTX_use_certificate(_ctx, x509);
  SSL_CTX_set_default_passwd_cb(_ctx, passwordCallback);
  LoadCertificates("root_ca.pem", "root_ca.key");

  setUpRsa();

  SSL_CTX_set_verify(_ctx, SSL_VERIFY_NONE, nullptr);
  genBio(cfd);
}

void zia::OpenSsl::sslWrite()
{
  char *buf;
  int len;
  len = SSL_write(_ssl, buf, 1024);
  buf[len] = '\0';
}

void zia::OpenSsl::sslRead()
{
  char *buf;
  int len;
  len = SSL_read(_ssl, buf, 1024);
  buf[len] = '\0';
  std::cout << "SSL: '" << buf << "'" << std::endl;
}
