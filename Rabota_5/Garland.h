//��������� ��������
#ifndef GARLAND_H
#define GARLAND_H
#include <iostream>          // ����������� ����������� ����������
#include <array>             // ����������� ���������� ��������
#include "IMode.h"           // ����������� ���������� �������
#include "IButtonObserver.h" // ����������� ���������� ������� ������

using tArrayModes = std::array<IMode*, 4>; // �������� ������� �� ������� (4 ������)
class Garland : public IButtonObserver // ����� ��������, ��������� ��������� ������� ������
{
public: 
  Garland(const tArrayModes& modes): _modes(modes) // ������������� ������ �� ������ �������
  {

  }
  
  void UpdateCurrentMode() const // ���������� ��������� �������� ������
  {
     _modes[modeNumber]->Update();
  };
  
  void SwitchNextMode() // ������������ ������ �� ���������
  {   
    if (modeNumber == (_modes.size()-1)) 
    {
      modeNumber = 0;
    }
    else 
    { 
      modeNumber ++;
    }
    _modes[modeNumber]->Clear(); // ����� ���� �����������
  };
  
  void OnButtonPress () override // �������, ��� ������� �� ������
  {
    SwitchNextMode(); // ������������� �� ��������� �����
  }
  

  
private:
   uint32_t modeNumber = 0;    // ������� �������
   const tArrayModes& _modes;  // ������ �� ������� (4 �����)

};

class Gyru : public IButtonObserver // ����� ������-�� ������� (�����������)
{
    void OnButtonPress () override  // �������, ��� ������� �� ������
  {
    std::cout<<"������ ������"<<std::endl; // ������� � �������� 
  }
};

#endif