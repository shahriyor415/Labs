#include "rccregisters.hpp" // ��� ������ RCC

#include "interrupthandler.hpp" // ���������� ����������

//----------------------------�����---------------------------------------------
#include "gpiocregisters.hpp" // ������� ��� ����� �
#include "gpioaregisters.hpp" // ������� ��� ����� a

//----------------------------�������-------------------------------------------
//#include "scbregisters.hpp" // ��� scb
#include "stkregisters.hpp" // �������� ��������� ���������� �������
#include "tim5registers.hpp"  // ����������� ������� �IM5
#include "tim2registers.hpp"  // ����������� ������� �IM2
#include "nvicregisters.hpp" // �������� ��� ������ � ������������ 
constexpr std::uint32_t SystemClock = 8'000'000U; // ������������ ����������� ����������, 1 ���� = 8 000 000 �� = 1 ���
constexpr std::uint32_t OneMillisecondRation = 1000U; // ����������� �������
//constexpr  std::uint32_t Timer2Prescaller = SystemClock / OneMillisecondRation; // 1 �����
constexpr  std::uint32_t Timer5Prescaller = SystemClock / OneMillisecondRation; // 1 �����
//----------------------------����� � �������� ��� ��������---------------------
#include "pinconfig.h" // ���������� ����������� ����� � ������ ��
#include "LED.h"   // ����������� ������������� �����
#include  "Button.h" // ��� ������
#include "AllMode.h" // ����� ����� ���
#include "ChessMode.h" // ����� �������
#include "TreeMode.h" // ����� ������
#include "SlideMode.h" // ����� �������
#include "Garland.h" // ��������

//----------------------------����������� ���������� �++------------------------
#include <iostream> // ����������� ����������� ���������� �++
#include <array> // ����������� ��������� ��� ������ � ���������

//-------------------------������� ��������-------------------------------------
void Delay(std::uint32_t milliseconds)
{
  // ����� ������
 // TIM2::ARR::Write(milliseconds);
  //TIM2::CNT::Write(0);
  //TIM2::SR::UIF::NoInterruptPending::Set(); // ������� ����
  //TIM2::CR1::CEN::Enable::Set(); 
  TIM5::ARR::Write(milliseconds); // �� ������� ������� ������ (������ �������)
  TIM5::CNT::Write(0);            // �������� ������, ����� ������ � ����
  TIM5::SR::UIF::NoInterruptPending::Set(); // ������� ����
  TIM5::CR1::CEN::Enable::Set();  // �������� ������
  
  //const std::uint32_t delayCounts = milliseconds * SystemClock / OneMillisecondRation - 1U; // ������ �������� ���������� �������

  //--------------��������� �������  
  //STK::VAL::Write(0U);           // ����� �������� � "0" ���������� �������
  //TIM5::CNT::Write(0U);            // ����� �������� � "0" ������� TIM5
  //STK::LOAD::Write(delayCounts); // STK - ������ �������, LOAD - �������, � ������� ���������� (Write(�������� �� �������� ������� ��������� ������))
  //TIM5::ARR::Write(milliseconds);  // ����� �� �������� ������� ������ TIM5
  //-------------------------------  

  //STK::CTRL::ENABLE::Enable::Set(); // ��������� ���������� �������
 // STK::CTRL::CLKSOURCE::CpuClock::Set(); 
  //STK::CTRL::TICKINT::EnableInterrupt::Set();
  //TIM5::CR1::CEN::Enable::Set();     // ��������� ������� TIM5
 // while(!STK::CTRL::COUNTFLAG::Overflow::IsSet())     // ��� ���������� �������: "!STK::CTRL::COUNTFLAG::Overflow::IsSet()" "!TIM5::SR::UIF::InterruptPending::IsSet()" - ��� ���� 2
  //{
    // ��� ���������� �������: ����������, ���� � ������� ����������� ������ (COUNTFLAG::Overflow - ������� ������ ����), ��� �� ��������� �� �����
   // ��� TIM5: ����������, ���� � ������� ����������� ������ ( - ������� ������ ������������� ��������)
 // }
 // STK::CTRL::ENABLE::Disable::Set(); // ���������� ���������� �������, ����� ��� ���������� �� �������
  //TIM5::SR::UIF::NoInterruptPending::Set(); // ����� ����� ������������ ������� TIM5
  //TIM5::CNT::Write(0U);            // ����� �������� � "0" ������� TIM5
  //TIM5::CR1::CEN::Disable::Set(); // ���������� ������� TIM5
}
//------------------------------------------------------------------------------

//-------�������� �������� (����������� ��������) � ��������� � �����-----------
Led led1(pinC7); // ��������� 1
Led led2(pinC8); // ��������� 2
Led led3(pinC9); // ��������� 3 
Led led4(pinC6); // ��������� 4
Button userButton1(pinC13); // ������
//------------------------------------------------------------------------------

//---------------------------------������� �� �����������-----------------------
   tArrayLeds leds =
    { 
      &led1,
      &led2,
      &led3,
      &led4,
    };
//------------------------------------------------------------------------------
    
//-------------�������� �������� (�������) � �������� �� �����������------------  
  AllMode allMode(leds); 
  ChessMode chessMode(leds);
  TreeMode treeMode(leds);
  SlideMode slideMode(leds);
//------------------------------------------------------------------------------  
  
//----------------------------------������ �� �������--------------------------
    using tArrayModes = std::array<IMode*,4>;
    tArrayModes modes =
    { 
      &allMode,
      &chessMode,
      &treeMode,
      &slideMode, 
    };
//------------------------------------------------------------------------------
    
//-------------�������� ������� (��������) � ��������� � �������----------------  
  //Gyru gyru0; 
  //Gyru gyru1;  
  Garland garland(modes); // �.�. ���� �� ��� ������ �������, �� ��� ������ �� ���������
  //Gyru gyru; 
//------------------------------------------------------------------------------     

int main()
{
  //RCC::CR::HSEON::On::Set();                     // �������� ������� ������������ �� 8 ���
  //while (RCC::CR::HSERDY::NotReady::IsSet())  {} // ���������� ������������ �� ������� ���������
  
   RCC::APB1ENR::TIM5EN::Enable::Set();             // ������ ������������ �� ������ TIM5
   TIM5::PSC::Write(Timer5Prescaller);             // �������� �������
   NVIC::ISER1::Write(1U << 18U);                  // ��������� ���������� ����������
   TIM5::DIER::UIE::Value1::Set();                // ���������� ���������� �� ������������
               
   
 //RCC::APB1ENR::TIM2EN::Enable::Set();             // ������ ������������ �� ������ TIM2
 //TIM2::PSC::Write(Timer2Prescaller);
 //NVIC::ISER0::Write(1U << 28U);                  // ��������� ���������� ����������
 //TIM2::DIER::UIE::Enable::Set();                 // ���������� ���������� �� ������������
   
 //TIM5::PSC::Write(8000U);                         // ������������� �������� ������� ��� ������� TIM5
    
  RCC::AHB1ENR::GPIOCEN::Enable::Set();            //������ ������������ �� ���� �

//----���� � ��������� � ����� ������ (�.6 �.7 �.8 �.9 - ����� �����������)-----
  GPIOC::MODER::MODER6::Output::Set();
  GPIOC::MODER::MODER7::Output::Set();
  GPIOC::MODER::MODER8::Output::Set();
  GPIOC::MODER::MODER9::Output::Set();
//------------------------------------------------------------------------------
  
//--------------���������� � ������������ �� ���������� ������------------------
 // userButton1.AddObserver(gyru1);
 // userButton1.AddObserver(gyru0);
  userButton1.AddObserver(garland); 
//  userButton1.AddObserver(gyru);
//------------------------------------------------------------------------------
  
// userButton1.RemoveObserver(garland); // �������� ����������� �� ���������� ������
  
//---------------------------������ ����---------------------------------------- 
  Delay(700);     // �������� � �������������
  for(;;)  
  { 
    userButton1.IsPressed() ;    // ���� ������ ������
    
    if (flag == 1) 
    {
      garland.UpdateCurrentMode(); // ��������� ������� ����� �����������
      flag = 0;
    }

    
  }
//------------------------------------------------------------------------------  
}