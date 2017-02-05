#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <string>
using boost::asio::ip::tcp;

static const int MAX_LENGTH = 1024;

typedef boost::shared_ptr<tcp::socket> socket_ptr;

void session(socket_ptr sock)
{
    try
    {
        char data[MAX_LENGTH];
        boost::system::error_code error;
        size_t length = sock->read_some(boost::asio::buffer(data), error);
        if (error) {
            throw boost::system::system_error(error);
        }
        std::cerr << length << " :: " << data << std::endl;
        boost::asio::write(*sock, boost::asio::buffer(data, length));
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void server(boost::asio::io_service& io_service, unsigned short port)
{
    tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), port));
    for (;;)
    {
        socket_ptr sock(new tcp::socket(io_service));
        a.accept(*sock);
        boost::thread t(boost::bind(session, sock));
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << " $ tcp_echo_server <port>" << std::endl;
        return 1;
    }
    try
    {
        boost::asio::io_service io_service;
        server(io_service, std::atoi(argv[1]));
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
