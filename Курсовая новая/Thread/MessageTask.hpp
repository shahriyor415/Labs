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

  void Execute() // �����, ���������� �� �������� ��������
  {
    for(;;)
    {
   out = myMainTask.GetMessage(); // ����������, ������� �������� �������� ����������
   sprintf(mes, "Voltage = %1.4f V \n", out); // ����������, ������� ���������� � ��������
   usartDriver.SendMessage(mes, strlen(mes)); // �������� ���������
   Sleep(333ms); // ������� �� 100 ��
    }
  } 
private:
  float out;
  char mes[20]; // ������, ������� ������ � ���� ���������� ��� ��������
};