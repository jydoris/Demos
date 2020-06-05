#include "record.h"

void Record::init(){
    m_value = 9;
    std::cout << "Init m_value to " << m_value << std::endl;

    m_name_job.emplace("Mary", "Programmer");
    m_name_job.emplace("Mike", "Banker");
    m_name_job.emplace("Elain", "Teacher");
}

void Record::showRecord(){
    std::cout << m_value << std::endl;
}

void Record::setValue(int value){
    m_value = value;
    std::cout<<"setValue to "<< value << std::endl;
}

int Record::getValue(){
    return m_value;
}

std::string Record::queryJob(std::string name){
    std::string result = "not found";
    for (auto it = m_name_job.begin(); it != m_name_job.end(); it++){
       if (name == it->first)
       {
           result = it->second;
           break;
       }
    }
    return result;
}