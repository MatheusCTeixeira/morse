#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>

#include <SFML/Audio.hpp>

#ifndef __MORSE__
#define __MORSE__

namespace mrs
{
    class morse
    {
    public:
        morse();

        void beep_init_audio();
        int beep_duration();
        void beep_short_audio();
        void beep_long_audio();
        std::string message_to_morse(std::string msg);
        void beep_morse(std::string msg);

    private:
        std::unordered_map<std::string, std::string> m_map;
        sf::Music m_short;
        sf::Music m_long;
    };
    

    
}

#endif