//
// Created by Arnaud WURMEL on 20/02/2018.
//

#ifndef NETWORKSSL_SSLCONFIGURATION_HH
#define NETWORKSSL_SSLCONFIGURATION_HH

# include <string>

namespace zia {
    class SSLConfiguration {
    public:
        static  SSLConfiguration const& get();
        static  void    set(SSLConfiguration const&);

    public:
        SSLConfiguration();
        ~SSLConfiguration();

    public:
        void    setPort(unsigned short port);
        void    setCertificate(std::string const&, std::string const&);

    public:
        unsigned short  getPort() const;
        std::string const&  getKey() const;
        std::string const&  getCert() const;

    private:
        static SSLConfiguration _inst;

    private:
        unsigned short _port;
        std::string _key;
        std::string _cert;
    };
}

#endif //NETWORKSSL_SSLCONFIGURATION_HH
