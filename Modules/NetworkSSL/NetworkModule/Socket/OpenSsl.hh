//
// Created by curzol_p on 20/02/18.
//

#ifndef NETWORK_OPENSSL_HH
#define NETWORK_OPENSSL_HH

#include <arpa/inet.h>
#include "openssl/ssl.h"
#include "openssl/err.h"

#include "ISocketAcceptor.h"
#include "../NetworkModule.hh"

namespace zia
{
  class OpenSsl
  {
   public:
    OpenSsl();
    OpenSsl(zia::api::ImplSocket *clientSocket);
    ~OpenSsl();

   private:
    SSL_CTX *_ctx;
    BIO *_bio;
    BIO *_accept_bio;
    SSL *_ssl;

    bool enableConnection(zia::api::ImplSocket*);
    void initSsl();
    bool getContext();
    X509 *generateCertificate(EVP_PKEY *pkey);
    EVP_PKEY *generatePrivateKey();
    void setUpRsa();
    void genBio(int cfd);
    void sslWrite();
    void sslRead();
    void LoadCertificates(const char *CertFile,
			  const char *KeyFile);
  };
}

#endif //NETWORK_OPENSSL_HH
