# cpp_zia
Lightweight http server

From scratch web server for 3rd year Epitech project.

This http server is modular; module can be added from the configuration file while it respects the API.

A module is a C++-based shared library that has a symbol named "create" and returns a zia::api::Module instance.

These modules can be combined into a pipeline.

### Built-in modules:
**HttpReceiver**: parse the http request

**HttpSender**: set the http response

**Network**: Wait for connection, and when a client send datas, read it and store as bytes.

**NetworkSSL**: Same as Network but with a SSL support.

**Logger**: Log the request to the terminal with the status and the requested resource.

**ResourceLoader**: Read the requested file and set the content for the HttpSender module.

**php-cgi**: Execute php codes when needed (files ending with .php[1,2,3,...])

### Team:
thibaud.marchand@epitech.eu

erwan.ballet@epitech.eu

@curzolapierre

arnaud.wurmel@epitech.eu

For any questions, feel free to contact us!
