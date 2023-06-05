#include "PowerRegulationTask.h"
#include <iostream> // ����������� ����������� ���������� �++
#include <cstdint>                    // ��� int32_t
#include "tim3registers.hpp"         // ���������� ��� TIM3

// �����������
PowerRegulationTask::PowerRegulationTask(IMeasureParameter& parameter): _parameter(parameter)
{
  
}
// ������, ������� ���������� � ������ �������� CCR
void PowerRegulationTask::Execute() 
{
  for(;;)
  {
   volatile auto  CCR = _parameter.Calculate();
   TIM3::CCR3::Write(static_cast<int32_t>(CCR));

   Sleep(100ms); 
  }
}