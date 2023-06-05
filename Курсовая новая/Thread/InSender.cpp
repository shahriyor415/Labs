#include "InSender.h"
#include "usart2registers.hpp"    // �������� USART ��� �������� ������
#include "Sender.h"

// �����������
InSender::InSender(IDataSource& volt): _volt(volt)
{
  
}

void InSender::Execute() 
{
  for(;;)
  {
   float U =  _volt.GetData();
             
   Sender<USART2>::Send(U); // ����� ������� � ��������
   Sleep(1000ms); 
  }

  
}
