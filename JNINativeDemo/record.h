#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <map>
#include <iostream>

//Record is about people and their infomation
class Record{
public:
    void init();
    void showRecord();
    void setValue(int value);
    int getValue();
    std::string queryJob(std::string name);
private:
    int m_value; //TODO
    std::map<std::string, std::string> m_name_job;
};
#endif