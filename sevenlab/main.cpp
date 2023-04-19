#include "rccregisters.hpp" // ��� ������ RCC
#include "gpiocregisters.hpp" // ������� ��� ����� �
#include "gpioaregisters.hpp" // ������� ��� ����� a

#include <iostream>

int32_t timer = 1000000; // ��� ������� ������� ������� ����������
int8_t clic = 0; // ���������� ������ ������ (3 ������ ������) 

  uint16_t st = 0x0280;
  uint16_t pt = 0x0140;  


//-----------------������� ��������---------------------------------------------
int Delay(int value)
{
  for(int i = 0;i<value;++i)
  {
    volatile int j = i;
  }
}

//------------------------------��������� ����� ������--------------------------
template<typename TPort, int ...portNums>
class CristmasTree
{
private: // �����������, ������� ��������� ������ � ��������� ������ �� ������ ������ ���������
  static constexpr int portNum[] = {portNums...};
  static int inline currentLed = 0;

public: // �����������, ������� ��������� ������ � ������� �� ������� ������� main()
  static void Blink() // ������� (����� ������, ������� ��������� �������� ��� ���������� ������)
  {
    TPort::Toggle(1 << portNum[currentLed]); // ����������� ���������, � 1 �� 0 � ��������
    currentLed = ++currentLed == (sizeof...(portNums)) ? 0 : currentLed; // ���������� ��� �����, � ����� ������� �� ����������, ������� � ������
  }
  
};
using MyGarland = CristmasTree<GPIOC::ODR, 6,9,8,7>; // �������� � ��������� ����� ���� ������ � ��� ����� ���� ����������� � ����� ������ ����� �����
//------------------------------------------------------------------------------

//------------------������� ������ ������---------------------------------------
void Cristmas()
{
     MyGarland::Blink(); // ����� ������� �� ���������� ������, � ������� �������� ��������� �� using MyGarland
     Delay(timer);  // ����� ������� ��������
}
//------------------------------------------------------------------------------

//---------------------������� ������ �������-----------------------------------
void Migalka()
{
  GPIOC::ODR::Toggle((1 << 6) | (1 << 9) | (1<< 8) | (1<<7));
}

//---------------------������� ������ �������-----------------------------------
void Chess()
{
  GPIOC::ODR::Write(st);
  st=st^pt;
  pt=st^pt;
  st=st^pt;
}
//-----------------------------------------------------------------------------

//------------------------������� ��� ������� ������-----------------------------
void ButtonRegimen(int8_t clicButton)
{
  if (clicButton==0) //���� ����� ������, �� �������
  {
    Migalka();
  } 
  else if (clicButton==1) //���� ����� 2, �� �������
  {
    Chess();
  } 
  else if (clicButton==2) // ���� ����� 3, �� ����
  {
    
    Cristmas();
  }
}




int main()
{ 
  //������ ������������ �� ���� �
  RCC::AHB1ENR::GPIOCEN::Enable::Set();

  //���� c ��������� � ����� ������ (�.6 c.7 c.8 c.9 - ����� �����������)
  GPIOC::MODER::MODER6::Output::Set();
  GPIOC::MODER::MODER7::Output::Set();
  GPIOC::MODER::MODER8::Output::Set();
  GPIOC::MODER::MODER9::Output::Set();
  // ������ ������������ �� ������ (������ - ��� ����)
  GPIOC::MODER::MODER13::Input::Set(); 
  
  for(;;)
  {
    
     
   if(GPIOC::IDR::IDR13::Low::IsSet()) // ���� ������ �� ������
   {
     while (GPIOC::IDR::IDR13::Low::IsSet()) // ���� � ����-�� ������ ������� ������ ��������, �� ����� ������
     {
     } 
     GPIOC::ODR::Write(0x0000); // ����� ����� �� ����������� � 0
    
     if (clic<2)  // ����� 3 ������
     {
       clic++;
     }
     else 
     {
       clic=0;
     }
    
   }
// ���� ������ �� ������, �� ��������� �� �������� � �������
      ButtonRegimen(clic);
      Delay(timer);  
  }
  
}