//������������ ���� ��� ������ "������� �����"
#ifndef ALLMODE_H
#define ALLMODE_H

#include "IMode.h" // ����������� ���������� IMode
#include "iled.h" // ����������� ���������� LED



class AllMode: public IMode // ������������ ������ �������� �� ���������� IMode
{
public: 
   AllMode(const tArrayLeds& leds) ; // �������� ����������� � ����� ��������
};

#endif