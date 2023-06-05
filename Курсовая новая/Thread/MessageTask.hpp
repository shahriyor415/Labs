#pragma once
#include "thread.hpp"//for thread
#include "usartconfig.hpp"
#include "Voltage.h"
#include <stdio.h> //for sprintf
using namespace OsWrapper;

template<auto& myMainTask>
class Message: public Thread<512>
{
public:

  void Execute() // Метод, отвечающий за передачу значений
  {
    for(;;)
    {
   out = myMainTask.GetMessage(); // Переменная, которая содержит значение напряжения
   sprintf(mes, "Voltage = %1.4f V \n", out); // Информация, которая передается в терминал
   usartDriver.SendMessage(mes, strlen(mes)); // Отправка сообщения
   Sleep(333ms); // Заснуть на 100 мс
    }
  } 
private:
  float out;
  char mes[20]; // Массив, который хранит в себе информацию для отправки
};