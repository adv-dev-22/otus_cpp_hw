#include "async_interface.h"
#include "async_data_translator.h"
#include <iostream>
#include <sstream>
#include <map>

namespace async {

static auto & data_translators()
{
    static std::map<size_t, DataTranslator>  translators;
    return translators;
}

static auto & data_translator(handle_t handle)
{
    auto & translators = data_translators();
    const size_t id = reinterpret_cast<size_t>(handle);
    return translators.at(id);
}

handle_t connect(std::size_t bulk)
{
    auto & translators = data_translators();

    size_t id = translators.size() + 1;
    translators.emplace(id, std::move(DataTranslator()));

    DataTranslator & translator = translators.at(id);
    translator.setup(bulk, id);

    return reinterpret_cast<void * >(id);
}

void receive(handle_t handle, const char * data, std::size_t size)
{
    DataTranslator & translator = data_translator(handle);

    std::stringstream ss;
    ss << data;

    std::string buffer;
    while (std::getline(ss, buffer))
    {
        translator.translate(buffer);
    }
}

void disconnect(handle_t handle)
{
    DataTranslator & translator = data_translator(handle);
    translator.close();
}

}
