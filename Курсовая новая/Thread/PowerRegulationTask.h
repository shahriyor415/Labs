#ifndef POWERREGULATIONTASK_H
#define POWERREGULATIONTASK_H

#include "Thread.hpp"
#include "IMeasureParameter.h" 
// ������, ������� ����� �� ����� ������� � ����������� ������������� ����������
class PowerRegulationTask: public OsWrapper::Thread<512> 
{
public:
  PowerRegulationTask(IMeasureParameter& parameter); 
  void Execute() override; 
  
private: // ��������� �������, ������� ������ ������ �� ��������� (��� ������������� ��������� � PowerRegulationTask.cpp)
   IMeasureParameter& _parameter;   
};

#endif
