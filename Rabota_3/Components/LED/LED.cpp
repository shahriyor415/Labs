#include "LED.h" // ����������� ������������� ����� LED


Led::Led(const IPin& pin): _pin(pin) // ������������� ������ �� ������ IPin
{
  
}
// �������� ���������
void Led::SwitchOff() const
{
  _pin.Reset(); // � IPin ���� ����� Reset(), ������� ���������� ��� � 0
}
// ������ ���������
//void Led::SwithOn() const
//{
//  _pin.Set();
//}

// ����������� ���������
void Led::Toggle() const
{
  _pin.Toggle(); // � IPin ���� ����� Toggle(), ������� ����������� ��� �� ������ ��������� � ���������������
}