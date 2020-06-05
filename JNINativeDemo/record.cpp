#include <iostream>
#include "record.h"

void Record::init(){
    m_value = 9;
    std::cout << "Init m_value to " << m_value << std::endl;
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