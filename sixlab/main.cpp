#include "rccregisters.hpp" // ��� ������ RCC
#include "gpiocregisters.hpp" // ������� ��� ����� �
#include "gpioaregisters.hpp" // ������� ��� ����� a

#include <iostream>

// ���������� ���������� ���������� �� ����������� � ���� ������
long long j = std::numeric_limits<decltype(j)>::max()/2;
    int StudentUdacha = 10;

int Delay(int value)
{
  for(int i = 0;i<value;++i)
  {
    volatile int j = i;
  }
}

int main()
{ 
  
  
  // ����������� ������� � ������������� ����� ���� long long
    std::cout <<sizeof(StudentUdacha) <<" ���� �������� ���������� j "<< std::endl;
    std::cout <<"MAX �������� ���������� j = "<<std::numeric_limits<decltype(j)>::max() << std::endl;
    std::cout <<"j = "<<j << std::endl; // ����� ���������� j
    
    int StudentUdacha = 10;
    int PrepodUdachca = 0 ;
    StudentUdacha = StudentUdacha ^ PrepodUdachca ;
    PrepodUdachca = StudentUdacha ^ PrepodUdachca ;
    StudentUdacha ^= PrepodUdachca ;
  
   RCC::CR::HSEON::On::Set(); // �������� ������� ���������, 
   while (RCC::CR::HSERDY::NotReady::IsSet())  {} // ���������� ������������ �� ������� ���������

    RCC::CFGR::SW::Hse::Set(); // ������������� ��� ������������ ����� ������������ (������� (Hse), ���������� (Hsi) � PLL)
    while (!RCC::CFGR::SWS::Hse::IsSet())  {} // ��� �� ����� ������������� �� ������� ���������
  // ������ ������� �� ������ ����
    
    RCC::AHB1ENR::GPIOCEN::Enable::Set(); // ������ ������� �� ���� �
    RCC::AHB1ENR::GPIOAEN::Enable::Set(); // ������ ������� �� ���� �
    
    // ��������� ����� ���� �������� �� �����
    //GPIOC::MODER::MODER7::Output::Set(); // ��������� ���� � 9 �� �����
    
  //  GPIOC::MODER::MODER8::Output::Set();
   // GPIOC::MODER::MODER9::Output::Set();
   // GPIOC::MODER::MODER13::Input::Set(); // ��������� ���� �� ���� (������
    
    auto pPortCModer = reinterpret_cast<std::uint32_t*>( 0x40020800);
    constexpr std::uint32_t PortC9Output = 1U<<18U;
    constexpr std::uint32_t  PortC9Mask = 3U<<18U;
    
    *pPortCModer &=  ~PortC9Mask;
    *pPortCModer |=  PortC9Output;
      
    GPIOA::MODER::MODER5::Output::Set();

    for(;;)
    {
      while(GPIOC::IDR::IDR13::High::IsSet()) // ���� �� ����� 13 (������) ����� 1, �� ������ �����������
      {
      }
      while(GPIOC::IDR::IDR13::Low::IsSet())
      {
      }
     // GPIOC::ODR::Toggle(1U<<9U);
      
     auto pPortCODR = reinterpret_cast<std::uint32_t*>( 0x40020814);
     *pPortCODR ^=(1U<<9U);
     
     
     }
    
}