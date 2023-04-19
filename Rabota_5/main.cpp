#include "rccregisters.hpp"       // ��� ������ ������������ RCC

#include "interrupthandler.hpp"   // ���������� �������� ����������

#include "usart2registers.hpp"    // �������� USART ��� �������� ������
#include "Sender.h"               // ������� �������� ������

#include <sstream>                // ���������� ��� �������������� ����� � ������ 
//----------------------------�����---------------------------------------------
#include "gpiocregisters.hpp" // ������� ��� ����� �
#include "gpioaregisters.hpp" // ������� ��� ����� a

//----------------------------�������-------------------------------------------
//#include "scbregisters.hpp" // ��� scb
#include "stkregisters.hpp" // �������� ��������� ���������� �������
#include "tim5registers.hpp"  // ����������� ������� �IM5
#include "tim2registers.hpp"  // ����������� ������� �IM2
#include "nvicregisters.hpp"
constexpr std::uint32_t SystemClock = 16'000'000U; // ������������ ����������� ����������, 1 ���� = 8 000 000 �� = 1 ���
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

//------------------------��������� ��� ������ ���------------------------------
#include "adc1registers.hpp"         // ���������� ��� ���
#include "adccommonregisters.hpp"    // ����������� ��� TSVREFE - ���������/���������� ������� �����������
#include "ADC.h"                     // ��������� ��� ������� ���
#include "Temperature.h"             // ��������� ��� ������� �����������
#include "CalibratedTemperature.h"   // ��������� ��� ������� ��������������� �����������

//-------------------------������� ��������-------------------------------------
void Delay(std::uint32_t milliseconds)
{
  // ����� ������
 // TIM2::ARR::Write(milliseconds);
  //TIM2::CNT::Write(0);
  //TIM2::SR::UIF::NoInterruptPending::Set(); // ������� ����
  //TIM2::CR1::CEN::Enable::Set(); 
  TIM5::ARR::Write(milliseconds); // 
  TIM5::CNT::Write(0);
  TIM5::SR::UIF::NoInterruptPending::Set(); // ������� ����
  TIM5::CR1::CEN::Enable::Set(); 
  
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

  //----------------------------�������� �������� ���-----------------------------  
  
  ADC  adc;                                           // �������� ������� ���
  Temperature temperature (3.0f, 4095.0f, 0.76f, 2.5f); // �������� ������ ��� ��������� �����������
  CalibratedTemperature cTemperature;                   // �������� ������� ��� ��������� ������������� �����������
  
//------------------------------------------------------------------------------ 
  
int main()
{
  
//----------------------��������� ������������----------------------------------  
  //RCC::CR::HSEON::On::Set();                     // �������� ������� ������������ �� 8 ���
  //while (RCC::CR::HSERDY::NotReady::IsSet())  {} // ���������� ������������ �� ������� ���������
//------------------------------------------------------------------------------  
  
//-----------------------------�������------------------------------------------  
   RCC::APB1ENR::TIM5EN::Enable::Set();             // ������ ������������ �� ������ TIM5
   TIM5::PSC::Write(Timer5Prescaller);             // �������� �������
   NVIC::ISER1::Write(1U << 18U);                  // ��������� ���������� ����������
   TIM5::DIER::UIE::Value1::Set();                // ���������� ���������� �� ������������
               
   
 //RCC::APB1ENR::TIM2EN::Enable::Set();             // ������ ������������ �� ������ TIM2
 //TIM2::PSC::Write(Timer2Prescaller);
 //NVIC::ISER0::Write(1U << 28U);                  // ��������� ���������� ����������
 //TIM2::DIER::UIE::Enable::Set();                 // ���������� ���������� �� ������������
   
 //TIM5::PSC::Write(8000U);                         // ������������� �������� ������� ��� ������� TIM5
//------------------------------------------------------------------------------
   
//------------------------------------�����-------------------------------------    
   RCC::AHB1ENR::GPIOAEN::Enable::Set();            //������ ������������ �� ���� A
   RCC::AHB1ENR::GPIOCEN::Enable::Set();            //������ ������������ �� ���� �

//----���� � ��������� � ����� ������ (�.6 �.7 �.8 �.9 - ����� �����������)-----
  GPIOC::MODER::MODER6::Output::Set();
  GPIOC::MODER::MODER7::Output::Set();
  GPIOC::MODER::MODER8::Output::Set();
  GPIOC::MODER::MODER9::Output::Set();
//------------------------------------------------------------------------------
  
//--------------------------------�������� ������-------------------------------

  RCC::APB1ENR::USART2EN::Enable::Set();      // ������ ������������ �� USART
  NVIC::ISER1::Write(1U << 6U);              // UART = 38 ������� �� ���������� ������� (38-32 = 6), ��������� ���������� ����������
  
  
  GPIOA::MODER::MODER2::Alternate::Set();  // ��������� ����� �2  �� �������������� ����� ��� �������� ������
  GPIOA::MODER::MODER3::Alternate::Set();  // ��������� ����� �3 �� �������������� ����� ��� ����� ������
  GPIOA::AFRL::AFRL2::Af7::Set();         // �������� ���� �2 � ����� TX ��������
  GPIOA::AFRL::AFRL3::Af7::Set();         // �������� ���� �3 � ����� RX ������
 
  USART2::CR1::M::Data8bits::Set();         // �������� ������ �� 8 ���
  
  USART2::CR1::TXEIE::InterruptWhenTXE::Set();     // ��������� ���������� �� ��������
 // USART2::CR1::TCIE::InterruptWhenTC::Set();     // ��������� ���������� �� ����� ��������
  // USART2::CR1::RXNEIE::InterruptWhenRXNE::Set();   // ��������� ���������� �� �����

  USART2::CR1::TE::Enable::Set();       // ��������� ��������
  USART2::CR1::RE::Enable::Set();       // ��������� ����
  
  USART2::CR2::STOP::Value0::Set();    // 1 �������� ���
  
  uint32_t usartdiv = SystemClock/ (9600);   // ������ ��������
  USART2::BRR::Write(usartdiv);             // ����� ����� ��������

  USART2::CR1::UE::Enable::Set();            // ��������� ������ USART
//------------------------------------------------------------------------------    
  
//----------------------------------------���-----------------------------------  
  RCC::APB2ENR::ADC1EN::Enable::Set(); // ������ ������������ �� ���
  ADC1::CR1::RES::Bits12::Set();       // ����������� ���
  ADC1::SQR1::L::Conversions1::Set();  // ��������� ��������� (��������� ���� ��� ����������)
  
  GPIOA::MODER::MODER0::Analog::Set(); // ������ ������������ �� ���� �0
  
  
  ADC1::CR2::ADON::Enable::Set(); // �������� ���
  
  //ADC1::SQR3::SQ1::Channel0::Set();      // ������������� 0 ����� ��� ������ �������� � ������������� 
  ADC1::SQR3::SQ1::Channel16::Set();     // ������������� 16 ����� ��� ��������� �����������
 // ADC1::SQR3::SQ1::Channel17::Set();     // ������������� 17 ����� ��� ��������� �������� �������� ����������  
  
 // ADC1::SMPR2::SMP0::Cycles480::Set();         // �������� �������������
  ADC1::SMPR2::SMP0::Cycles84::Set();           // �������� �������������
  
  ADC_Common::CCR::TSVREFE::Enable::Set();    // �������� ������ ����������� � ����������
  
//------------------------------------------------------------------------------
  
//---------���������� � �������� ������������ �� ���������� ������--------------
 // userButton1.AddObserver(gyru1);
 // userButton1.AddObserver(gyru0);
  userButton1.AddObserver(garland);
//  userButton1.AddObserver(gyru);
  
// userButton1.RemoveObserver(garland); // �������� ����������� �� ���������� ������
//------------------------------------------------------------------------------  �� �������
//---------------------------������ ����---------------------------------------- 
  Delay(700);     // �������� � �������������
  for(;;)  
  { 
    userButton1.IsPressed() ;    // ���� ������ ������
    
    if (flag == 1) 
    {
      garland.UpdateCurrentMode(); // ��������� ������� ����� �����������
      flag = 0;
      //Sender<USART2>::Send(" Hello World "); 
      //USART::CR1::RE::Enable::Set();
      //TUSART::CR1::RXNEIE::InterruptWhenRXNE::Set();
      //ADC1::CR2::SWSTART::On::Set(); // ��������� ��� �� ���������
     // while( ADC1::SR::EOC::ConversionNotComplete::IsSet() )
     // {
          // ��� ���� ���������� ��������������
     // }
     // std::cout << ADC1::DR::Get() << std::endl;
      //float voltage = ADC1::DR::Get();
      
      // 0x1FFF 7A2C - 0x1FFF 7A2D
      
      //uint16_t codeTemperature = ADC1::DR::Get();  // ������� �������� � ���
      
      //float V25 = 0.76;                                                        // �� �������� (c��. 119) file:///R:/POIP/POIP/stm32f411rc.pdf
      //float Avg_Slope = 2.5;                                                   // ������ �� file:///R:/POIP/POIP/stm32f411rc.pdf
      //float temperatura = ( (codeTemperature*3.0f/4095.0f - V25) / Avg_Slope ) + 25;  // ������� �������������� ���� � �����������

      //std::ostringstream ss;   // �����, ������� ������������ ����� � ������
      //ss << temperatura;      // ����������� ����� � ������
      
      //std::string outputstring (" "+ss.str() + " ");  // ������ � outputstring ������ � ������������
      //Sender<USART2>::Send(outputstring);        // ����� ���������� ����������� � ��������

      //uint16_t T30 = *(uint16_t*)0x1FFF7A2C;  // ��� ������� ����������� ��� 3,3 ������ ��� 30 ��������
      //uint16_t T110 = *(uint16_t*)0x1FFF7A2E; // ��� ������� ����������� �� 3,3 ������ ��� 110 ��������
            
      //cout << codeTemperature << "   " << T30 << "   "<< T110 << endl; // ����� � ������� ���� ����������    
      
      adc.StartConversation(); 
      while ( !adc.IsConversionComplete())
      {
         // ��� ���� �� ���������� ���
      }
      
      uint16_t codeTemperature = adc.GetResult(); // ������� �������� �� �������� ���

      std::ostringstream ss;                             // �����, ������� ������������ ����� � ������
      ss << temperature.Calculate(codeTemperature);      // ����������� ����� � ������
      
      std::string outputstring ("Temperature not calibration: "+ss.str() + ".   ");  // ������ � outputstring ������ � ������������
      Sender<USART2>::Send(outputstring);            // ����� ���������� ����������� � �������� �� UART�
      
     
      std::ostringstream cc;                             // �����, ������� ������������ ����� � ������
      cc << cTemperature.Calculate(codeTemperature);      // ����������� ����� � ������
      
      std::string outputstring1  ("Temperature calibration: "+cc.str() + ".   ");  // ������ � outputstring ������ � ������������
      Sender<USART2>::Send(outputstring1);            // ����� ���������� ����������� � �������� �� UART�
      
        cout << outputstring << "   " << outputstring1 << "   " << endl; // ����� � ������� ���� ����������  
//      cout << codeTemperature << "   " << T30 << "   "<< T110 << endl; // ����� � ������� ���� ����������    
      //------------------------------------------------------------------------
      
      // ��� ���������� ����������
      uint16_t VREFINT_CAL = *(uint16_t*)0x1FFF7A2A;      // ������������� ��� ��� 30 ��������
      uint16_t VREFINT_DATA = codeTemperature;    
      float VDDA = 3.3 * VREFINT_CAL / VREFINT_DATA;
      
    //  cout << codeTemperature << "   " << VREFINT_CAL << "   "<< VDDA << endl; // ����� � ������� ���� ����������  
      //------------------------------------------------------------------------
      
      
      
    }
      }
//------------------------------------------------------------------------------  
}