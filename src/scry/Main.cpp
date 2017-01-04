#include "scry/Client.hpp"

int main(int argc, char* argv[])
{
    return scry::Client::get_instance()->execute();
}
