#include "morse.hpp"

using namespace mrs;

int main(){
    morse moorse;

    while (true)
    {
        std::cout << "> " ;
        std::string message;
        std::cin >> message;
        moorse.beep_morse(moorse.message_to_morse(message));
        std::cout << std::endl;
    }
    return 0;
}