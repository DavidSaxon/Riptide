#include "riptide/client/RiptideClient.hpp"

int main(int argc, char* argv[])
{
    // create the instance of the client
    rip::client::RiptideClient client;

    return client.execute();
}
