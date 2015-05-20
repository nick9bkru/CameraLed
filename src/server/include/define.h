#ifndef DEFINE_H
#define DEFINE_H
#include <string>

#define UNUSED(x) (void)x; // макрос для неиспользованный переменных, что бы не ругался компилятор

const std::string OK = "OK";
const std::string FAILED = "FAILED";
const std::string fifo_name = "./FIFO";
#endif 