#include "CalibratedTemperature.h"


CalibratedTemperature::CalibratedTemperature()
  {
    
  }

float CalibratedTemperature::Calculate(int32_t code) 
{
   int i = 0;  
}

float CalibratedTemperature::Calculate(int32_t code, float temperature)
{
   coefficientK = (110.0f-30.0f) / (t110 - t30);                                // ������� ����������� �
   coefficientB =  30.0f - ( t30 * coefficientK );                              // ������� ����������� �
   // calibrateTemperatura = (coefficientK * (temperature * (3.27f / 3.3f)) ) + coefficientB;    // ������� �������������� ���� � �����������
   float calibrateTemperatura = temperature * (3.27f / 3.3f);
   return calibrateTemperatura; 
}