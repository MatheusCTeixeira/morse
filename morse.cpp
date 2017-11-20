#include "morse.hpp"

namespace mrs
{
morse::morse()
    : m_map{}
{
    this->beep_init_audio();

    this->m_map.insert(std::pair<std::string, std::string>("A", ".-"));
    this->m_map.insert(std::pair<std::string, std::string>("B", "-..."));
    this->m_map.insert(std::pair<std::string, std::string>("C", "-.-."));
    this->m_map.insert(std::pair<std::string, std::string>("D", "-.."));
    this->m_map.insert(std::pair<std::string, std::string>("E", "."));
    this->m_map.insert(std::pair<std::string, std::string>("F", "..-."));
    this->m_map.insert(std::pair<std::string, std::string>("G", "--."));
    this->m_map.insert(std::pair<std::string, std::string>("H", "...."));
    this->m_map.insert(std::pair<std::string, std::string>("I", ".."));
    this->m_map.insert(std::pair<std::string, std::string>("J", ".---"));
    this->m_map.insert(std::pair<std::string, std::string>("K", "-.-"));
    this->m_map.insert(std::pair<std::string, std::string>("L", ".-.."));
    this->m_map.insert(std::pair<std::string, std::string>("M", "--"));
    this->m_map.insert(std::pair<std::string, std::string>("N", "-."));
    this->m_map.insert(std::pair<std::string, std::string>("O", "---"));
    this->m_map.insert(std::pair<std::string, std::string>("P", ".--."));
    this->m_map.insert(std::pair<std::string, std::string>("Q", "--.-"));
    this->m_map.insert(std::pair<std::string, std::string>("R", ".-."));
    this->m_map.insert(std::pair<std::string, std::string>("S", "..."));
    this->m_map.insert(std::pair<std::string, std::string>("T", "-"));
    this->m_map.insert(std::pair<std::string, std::string>("U", "..-"));
    this->m_map.insert(std::pair<std::string, std::string>("V", "...-"));
    this->m_map.insert(std::pair<std::string, std::string>("W", ".--"));
    this->m_map.insert(std::pair<std::string, std::string>("X", "-..-"));
    this->m_map.insert(std::pair<std::string, std::string>("Y", "-.--"));
    this->m_map.insert(std::pair<std::string, std::string>("Z", "--.."));
    this->m_map.insert(std::pair<std::string, std::string>(" ", "    "));

    this->m_map.insert(std::pair<std::string, std::string>("0", "-----"));
    this->m_map.insert(std::pair<std::string, std::string>("1", ".----"));
    this->m_map.insert(std::pair<std::string, std::string>("2", "..---"));
    this->m_map.insert(std::pair<std::string, std::string>("3", "...--"));
    this->m_map.insert(std::pair<std::string, std::string>("4", "....-"));
    this->m_map.insert(std::pair<std::string, std::string>("5", "....."));
    this->m_map.insert(std::pair<std::string, std::string>("6", "-...."));
    this->m_map.insert(std::pair<std::string, std::string>("7", "--..."));
    this->m_map.insert(std::pair<std::string, std::string>("8", "---.."));
    this->m_map.insert(std::pair<std::string, std::string>("9", "----."));
}

std::string morse::message_to_morse(std::string msg)
{
    std::string result{};

    for (auto letter : msg)
    {
        result.append(this->m_map[std::string{letter}]);
        result.append("   ");
    }

    return result;
}

void morse::beep_init_audio()
{
    this->m_short.openFromFile("short.ogg");
    this->m_long.openFromFile("long.ogg");
}

int morse::beep_duration()
{
    return(this->m_short.getDuration().asMilliseconds());
    // long duration = 3*short duration
}

void morse::beep_short_audio()
{
    this->m_short.play();    
}

void morse::beep_long_audio()
{
    this->m_long.play();    
}

void morse::beep_morse(std::string msg)
{
    for (auto letter : msg)
    {
        switch (letter)
        {
        case '.':
            this->beep_short_audio();
            std::this_thread::sleep_for(std::chrono::milliseconds{this->beep_duration()});
            break;

        case '-':
            this->beep_long_audio();            
            std::this_thread::sleep_for(std::chrono::milliseconds{this->beep_duration()});
            break;

        default:
            std::this_thread::sleep_for(std::chrono::milliseconds{this->beep_duration()});
        }
    }
}
}