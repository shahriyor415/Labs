#ifndef INSENDER_H
#define INSENDER_H

#include "Thread.hpp"
#include "IMeasureParameter.h" 
#include "IDataSource.h"       // ��� ���������� IDataSource ��� ����� ������ 

class InSender: public OsWrapper::Thread<512> 
{

public:
  void Execute() override;
  InSender(IDataSource& volt); 
  
private:
     IDataSource& _volt;  
};

#endif
