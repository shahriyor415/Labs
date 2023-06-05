//
// Created by Sergey on 21.11.2019.
//

#ifndef REGISTERS_INTERRUPTHANDLER_HPP
#define REGISTERS_INTERRUPTHANDLER_HPP
#include "usart2registers.hpp"    // �������� USART ��� �������� ������
#include "Sender.h"             // ���� �������� ������ �� USART

class InterruptHandler 
{
  public:
    static void DummyHandler() 
    { 
      for(;;) 
      {
        
      } 
    }

    static void USART2Handler() // ����������� ��� USART2, ��������� ����� ������������ ������� USART2::DR
    {
      if (USART2::SR::TXE::DataRegisterEmpty::IsSet() && USART2::CR1::TXEIE::InterruptWhenTXE::IsSet()) // ��������� ��� ������� ������ ���� USART2::SR::TXE � ��� ��������� ��������� �� �������� USART2::CR1::TXEIE
      {
        Sender<USART2>::SendOneSymvol(); // ������� �������� �� 1 ������� (�� 1 �����), ����� ����� �����������, �� ������� ��������� ������
      }
    }
 
};



#endif //REGISTERS_INTERRUPTHANDLER_HPP
