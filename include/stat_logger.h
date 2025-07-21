
#ifndef ISOSURFACING_STAT_LOGGER_H
#define ISOSURFACING_STAT_LOGGER_H

#include <string>
#include <vector>
#include <fstream>
#include <assert.h>

template <typename DataType>
class StatLogger{
private:
    std::ofstream _stream;
public:
    StatLogger(const std::string& filepath);
    void AddValue(DataType value);
    void Flush();
};

template<typename DataType>
StatLogger<DataType>::StatLogger(const std::string &filepath) : _stream(filepath) {
    assert(_stream);
}

template<typename DataType>
void StatLogger<DataType>::AddValue(DataType value) {
    _stream << value;
}

template<typename DataType>
void StatLogger<DataType>::Flush(){
    _stream.close();
}

#endif  // ISOSURFACING_STAT_LOGGER_H
