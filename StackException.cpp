#include "StackException.h"

StackException::StackException(string)
{
}

const char* StackException::what() const
{
    return m_errorDescription.c_str(); //string to char*

}
