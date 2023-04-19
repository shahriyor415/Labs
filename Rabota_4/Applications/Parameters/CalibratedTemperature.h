// ��������� ��������������� �����������
#ifndef CALIBRATEDTEMPERATURE_H
#define CALIBRATEDTEMPERATURE_H

#include "IMeasureParameter.h"

class CalibratedTemperature: public IMeasureParameter
{
public: 
   
  CalibratedTemperature();
  
  float Calculate(int32_t code) override;
  
private:
  float coefficientB;
  float coefficientK;
  
  uint16_t t30 = *(uint16_t*)0x1FFF7A2C;  // ��� ������� ����������� ��� 3,3 ������ ��� 30 ��������
  uint16_t t110 = *(uint16_t*)0x1FFF7A2E; // ��� ������� ����������� �� 3,3 ������ ��� 110 ��������
}


;

#endif