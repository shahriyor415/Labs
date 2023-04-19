#include "CalibratedTemperature.h"


CalibratedTemperature::CalibratedTemperature()
  {
    
  }

float CalibratedTemperature::Calculate(int32_t code) 
{
   coefficientK = (110.0f-30.0f) / (t110 - t30);                   // ������� ����������� �
   coefficientB =  30.0f - ( t30 * coefficientK );                 // ������� ����������� �
   float temperatura = ( coefficientK * code ) + coefficientB;     // ������� �������������� ���� � �����������
   return temperatura;  
}