#include <iostream>
#include "record.h"

void Record::init(){
    m_value = 9;
}
void Record::showRecord(){
    std::cout << m_value << std::endl;
}