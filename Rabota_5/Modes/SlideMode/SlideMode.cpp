#include "SlideMode.h" // ����������� ������������� ������ �������

SlideMode::SlideMode(const tArrayLeds& leds): IMode(leds) // ������������ ���� ������� (�������) �� ���������� IMode
{
  Clear();  // ����� ��� ������ ���� ����������� � 0
 // revers = false;
 // ledNumber = 0;
}

void SlideMode::Update()  // ���������� ��������������� �������
{ 
  _leds[ledNumber]->Toggle(); // ����������� � ������ ��������� �� ������ ��������� � ������
  const auto endIndex = size(_leds) - 1 - ledNumber  ; // ���������� ������� � ����� ������� �����������
  if (ledNumber != endIndex) // ���� ������ ����������� � ����� � ������ �� �����������,
  { 
    _leds[endIndex]->Toggle(); // �� ����������� � ����� ��������� �� ��������������� ���������     
  }
  CalculateNextIndex();
  
}

void SlideMode::CalculateNextIndex()  // ����������� ������� ����������� ��� ������� � ��������� ����
{ 
if (!revers) // ���� ������ ���
  {
     if(ledNumber < ( ((size(_leds) + 1) / 2) -1 ) ) // ���� ������ ���������� �� ����� �� ��������
     {
        ledNumber ++ ; // �� ���������� ������ ����������
     }
     else 
     {
       revers = true; // ��� � �������� �������
     }
  } 
  else  // ���� �������� ���
  { 
     if(ledNumber > 0) // ���� ������ ���������� ����� �� ������ 0
     {
        ledNumber --; //  ��� � �������� �������
     }
     else
     {
       revers = false; // ��� ������ ������ ���������� ���� = 0, ��������� � ������ ���
     }
  }
}
