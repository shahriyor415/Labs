<<<<<<< HEAD
#include "rccregisters.hpp" // ��� ������ RCC
#include "gpiocregisters.hpp" // ������� ��� ����� �


//--------------------------------������� ��������-------------
void Delay(int zaderjka)
{
  for (int i=0; i<zaderjka;++i)
  {
    //��� ���-�� ��������
    volatile int j = i; // ��� �����������, ��������� ��� ������ ��� ��� �� ����, ��� ���� ����� �������� ��������
    // ���� �������� ����������� �� ������ � ����������� volatile, �� ���������� ��� �����
    // � volatile ������� �� 
  }
  
}
//-----------------��������� ����� ������ ����---------------------------------
template<typename TPort, int ...portNums>
class CristmasTree
{
private: // �����������, ������� ��������� ������ � ��������� ������ �� ������ ������ ���������
  static constexpr int portNum[] = {portNums...}; // constexpr - ������������, ������� ��������� �������� �� ����� ����������, �.�. � ������ �������
  static int inline currentLed = 0;

public: // �����������, ������� ��������� ������ � ������� �� ������� ������� main()
  static void Blink() // ������� (����� ������, ������� ��������� �������� ��� ���������� ������)   
  {
    TPort::Toggle(1 << portNum[currentLed]); // ����������� ��������, � 1 �� 0 � ��������
    currentLed = ++currentLed == (sizeof...(portNums)) ? 0 : currentLed; // ���������� ��� �����, � ����� ������� �� ����������, ������� � ������  
  }
};
using MyGarland = CristmasTree<GPIOC::ODR, 7,8,9>; // �������� � ��������� ����� ���� ������ � ��� ����� ���� ����������� � ����� ������ ����� �����
//������� �������
int main()
{
  //������ ������������ �� ���� �
  RCC::AHB1ENR::GPIOCEN::Enable::Set();
  
  //���� � ����� ������ ��������� c.7 c.8 c.9
  GPIOC::MODER::MODER7::Output::Set(); 
  GPIOC::MODER::MODER8::Output::Set(); 
  GPIOC::MODER::MODER9::Output::Set(); 
  // ������ ����������

  while(true)// ���� ��� ������������ �������� �����������
  {
     MyGarland::Blink(); // ����� ������� �� ���������� ������, � ������� �������� ��������� �� using MyGarland
     Delay(2000000);  // ����� ������� ��������
  }
=======
#include "rccregisters.hpp" // ��� ������ RCC
#include "gpiocregisters.hpp" // ������� ��� ����� �
//������� ��������
void Delay(int zaderjka)
{
  for (int i=0; i<zaderjka;++i)
  {
    //��� ���-�� ��������
    volatile int j = i; // ��� �����������, ��������� ��� ������ ��� ��� �� ����, ��� ���� ����� �������� ��������
    // ���� �������� ����������� �� ������ � ����������� volatile, �� ���������� ��� �����
    // � volatile ������� �� 
  }
  
}
//������� �������
int main()
{
  //������ ������������ �� ���� �
  RCC::AHB1ENR::GPIOCEN::Enable::Set();
  
  //���� � ����� ������ ��������� c.5 c.8 c.9
  GPIOC::MODER::MODER7::Output::Set(); 
  GPIOC::MODER::MODER8::Output::Set(); 
  GPIOC::MODER::MODER9::Output::Set(); 
  // ������ ����������
  uint8_t i = 0; 
  while(true)// ���� ��� ������������ �������� �����������
  {
    i++;
    
    
    if (i%2==0)  // ������� �� ���������/������� ����������
    {
      GPIOC::ODR::ODR7::High::Set(); // ���������� ���������
      Delay(2000000);  // ����� ������� ��������
      GPIOC::ODR::ODR8::High::Set(); // ���������� ���������
      Delay(2000000);  // ����� ������� ��������
      GPIOC::ODR::ODR9::High::Set();  // ��������� ������ 
      Delay(2000000);  // ����� ������� ��������
    }
    else 
    {
      GPIOC::ODR::ODR7::Low::Set();  // ��������� ������ 
      Delay(2000000);  // ����� ������� ��������
      GPIOC::ODR::ODR8::Low::Set();  // ��������� ������ 
      Delay(2000000);  // ����� ������� ��������
      GPIOC::ODR::ODR9::Low::Set();  // ��������� ������ 
      Delay(2000000);  // ����� ������� ��������
    } 
  }
 
 
>>>>>>> dd41c8f31af8845b72ebcb1cc09e39e9ec954adc
}