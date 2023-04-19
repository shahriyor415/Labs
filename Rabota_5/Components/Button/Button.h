#ifndef  BUTTON_H
#define  BUTTON_H
#include <array>             // ����������� ����������� ���������� ��������

#include "IButton.h"         // ����������� ���������� Button
#include "iPinReadable.h"    // ����������� ���������� ���������� ����
#include "IButtonObserver.h" // ����������� ���������� ������� ������
#include "IObservable.h"     // ����������� ����������, ������� �������� � ������������

 
class Button : public IButton, public IObservable // ������������ Button �� ����������� IButton � IObservable
{
public: 
   Button(const IPinReadable& pin) ; // ����������� � ������� ��������� ������ �� ����� ���� IPin
   bool IsPressed() const override; // ������������������ ������, ������� ���������� ������ �� ������
   
   void AddObserver(IButtonObserver& observer) override;     // ���������� ����������� � ������ �����������
   void RemoveObserver (IButtonObserver& observer) override; // �������� �� ������� �����������
  
private: // ��������� �������, ������� ������ ������ �� ��������� (��� ������������� ��������� � Button.cpp)
   const IPinReadable& _pin;                    
   std::array<IButtonObserver*, 4> _observers;  // ������ �� 4 �����������
   int32_t _currentObserver = -1;               // ��������� �������� ������� �����������
      
};

#endif