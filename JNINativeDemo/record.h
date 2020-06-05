#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include <string>
#include <map>
#include <vector>

//Record is about people and their infomation
class Record{
public:
    void init();
    void showRecord();
    void setValue(int value);
    int getValue();
    std::string queryJob(std::string name);
    bool setAge(std::vector<int> &ages);
private:
    int m_value; //ID of the record
    std::map<std::string, std::string> m_name_job;
    std::vector<int> m_age;
};
#endif