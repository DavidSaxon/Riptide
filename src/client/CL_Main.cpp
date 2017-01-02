#include "client/RiptideClient.hpp"

int main(int argc, char* argv[])
{
    return rip_c::RiptideClient::get_instance()->execute();
}
