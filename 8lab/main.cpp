#include "rccregisters.hpp" // ��� ������ RCC
#include "gpiocregisters.hpp" // ������� ��� ����� �
#include "gpioaregisters.hpp" // ������� ��� ����� a

#include "pinconfig.h" // ���������� ����������� ����� � ������ ��
#include "LED.h"   // ����������� ������������� �����
#include  "Button.h" // ��� ������
#include "AllMode.h" // ����� ����� ���
#include "ChessMode.h" // ����� �������
#include "TreeMode.h" // ����� ������
#include "SlideMode.h" // ����� �������
#include "Garland.h" // ��������


#include <iostream> // ����������� ����������� ���������� �++
#include <array> // ����������� ��������� ��� ������ � ���������
// -------------------------������� �������� �  �������������-----------------------------------
void Delay(uint64_t value)
{
    for(uint64_t i = 0;i<value;++i)
  {
    volatile uint64_t j = i; 
  }
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
  Gyru gyru0; 
  Gyru gyru1;  
  Garland garland(modes); // �.�. ���� �� ��� ������ �������, �� ��� ������ �� ���������
  Gyru gyru; 

//------------------------------------------------------------------------------     

int main()
{
  //������ ������������ �� ���� �
  RCC::AHB1ENR::GPIOCEN::Enable::Set();

  //���� � ��������� � ����� ������ (�.6 �.7 �.8 �.9 - ����� �����������)
  GPIOC::MODER::MODER6::Output::Set();
  GPIOC::MODER::MODER7::Output::Set();
  GPIOC::MODER::MODER8::Output::Set();
  GPIOC::MODER::MODER9::Output::Set();
  
  // ���������� ������������ �� ���������� ������
 // userButton1.AddObserver(gyru1);
 // userButton1.AddObserver(gyru0);
  userButton1.AddObserver(garland); 
//  userButton1.AddObserver(gyru);
  
 // �������� �����������
// userButton1.RemoveObserver(garland); // �������� ����������� �� ���������� ������
  
  
  for(;;)  // ������ ����
  { 
    userButton1.IsPressed() ;// ���� ������ ������

    Delay(1000000);  // � ������������
    garland.UpdateCurrentMode(); // ��������� ������� ����� �����������
  }
  
}