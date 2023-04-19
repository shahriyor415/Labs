//
// Created by Sergey on 21.11.2019.
//

#ifndef REGISTERS_INTERRUPTHANDLER_HPP
#define REGISTERS_INTERRUPTHANDLER_HPP

#include <iostream>

//#include "pin.hpp" //for Pin

#include "tim2registers.hpp"  //for TIM2
#include "tim5registers.hpp"  //for TIM5
#include "gpiocregisters.hpp"  // ��� ����� �
#include "gpiodregisters.hpp"  // ��� ����� d
#include "usart2registers.hpp"   // �������� USART ��� �������� ������
#include "Sender.h"

inline int flag = 0;

class InterruptHandler 
{
  public:
    static void DummyHandler() 
    { 
      for(;;) 
      {
        
      } 
    }

    
    static void TimerHandler() // ����������� ��� ���������� �������
    {
      //flag = 1;
      //static int i = 0; 
      //std::cout << i++ << std::endl;
    } 
      
      
      
    static void Timer2Handler() // ����������� ��� ������� TIM2
    {
     
      //if (TIM2::SR::UIF::InterruptPending::IsSet())
    // {
    //    TIM2::SR::UIF::NoInterruptPending::Set(); // ��������� ����
        //Pin<Port<GPIOC>, 8U, PinWriteable>::Toggle() ;
   //   flag = 1;
    // static int i = 0; 
    // std::cout << i++ << std::endl;
    // }
    }
    
    static void USART2Handler() // ����������� ��� USART2, ��������� ����� ������������ ������� USART2::DR
    {
      if (USART2::SR::TXE::DataRegisterEmpty::IsSet() && USART2::CR1::TXEIE::InterruptWhenTXE::IsSet()) // ��������� ��� ������� ������ ���� USART2::SR::TXE � ��� ��������� ��������� �� �������� USART2::CR1::TXEIE
      { 
        Sender<USART2>::SendOneSymvol(); // ������� �������� �� 1 ������� (�� 1 �����), ����� ����� �����������, �� ������� ��������� ������
      }
   /*   if (USART2::SR::RXNE::DataRecieved::IsSet() && USART2::CR1::RXNEIE::InterruptWhenRXNE::IsSet())
      {
          Sender<USART2>::ReciveOneSymvol(); // ARR[i] = TUSART::DR::Get(); ��
      } */
     }

    static void Timer5Handler() // ����������� ��� ������� TIM5
    {
     
      if (TIM5::SR::UIF::InterruptPending::IsSet())
      {
        TIM5::SR::UIF::NoInterruptPending::Set(); // ��������� ���� �������
        flag = 1; // ���� ����, ��� ������ ������������
 
      }
    }
};



#endif //REGISTERS_INTERRUPTHANDLER_HPP
