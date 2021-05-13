#pragma once
#include <exception>
#include <string>
using namespace std;
class StackException :
    public exception
{
public:
    StackException(string);
    const char* what() const override;

private:
    string m_errorDescription;
};

