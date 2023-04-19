#include "ADC.h"
#include "adc1registers.hpp"      // ���������� ��� ���


void ADC::StartConversation() 
{
   ADC1::CR2::SWSTART::On::Set();    // ��������� ��� �� ���������
   
}

int32_t ADC::GetResult() 
{
   return static_cast<int32_t>(ADC1::DR::Get());  // ������� �������� � ���
}

bool ADC::IsConversionComplete()
{
  return ADC1::SR::EOC::ConversionComplete::IsSet(); 
}