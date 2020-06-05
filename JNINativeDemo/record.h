#ifndef RECORD_H
#define RECORD_H
class Record{
public:
    void init();
    void showRecord();
    void setValue(int value);
    int getValue();
private:
    int m_value;
};
#endif