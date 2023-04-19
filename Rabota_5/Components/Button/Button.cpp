#include "Button.h"          // ����������� ������������� ����� Button
#include "IButtonObserver.h" // ����������� ���������� ������� ������
#include "IObservable.h"     // ����������� ����������, ������� �������� � ������������

Button::Button(const IPinReadable& pin): _pin(pin) // ������������� ������ �� ������ IPin
{
  
}
// ������ ������
bool Button::IsPressed() const 
{   
  if( !_pin.IsHigh() )  // ���� ������ �� ������ 
  {
      while (!_pin.IsHigh()) // ���� � ����-�� ������ ������� ������ ��������, �� ����� ������
      {
         volatile int a = 1; // ������ �� �������� �������, ����� ��� �������� ���� ������ ������� �� ����������
      } 
      for (int i = 0; i <= _currentObserver; i ++) // ������ �� ������� �����������
      {
        _observers[i]->OnButtonPress(); // ��������� ������� ���������� � ���, ��� ������ ������
      }
      return true;
  }
  return false;
} 

  
void Button::AddObserver(IButtonObserver& observer) // ���������� ����������� (�� 4 ����)
{
  _currentObserver++; // ���������� ���������� �� ������ ���������� � �������                  
  _observers[_currentObserver] = &observer; // �������� � ������ ������, �������� ����� ���������
}

void Button::RemoveObserver(IButtonObserver& observer) // �������� �� ������� �����������
{
  for (int i = 0; i <= (_currentObserver); i ++) // ������ �� ������� �����������
  {
   
    if ( _observers[i] == &observer) // ���� ����� �� ��� ����� ��������,
    {
       for (int j = i; j <= (_currentObserver - 1); j ++) // �� ����� �������� �� ������� ����������� �
       {
           _observers[j] = _observers[j + 1]; // �������������� 
       }
       _currentObserver--;
    }
  }

  
}


