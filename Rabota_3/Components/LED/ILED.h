//��������� ������ Led
#ifndef ILED_H
#define ILED_H


class ILed
{
public: 
  virtual void SwitchOff() const=0; // ����������� ����� ���������� ����������
  virtual void Toggle() const=0;   // ����������� ����� ������������ ���������� �� 1 � 0 ��� �������
};

#endif