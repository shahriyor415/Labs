//������������ ���� ��� ������ "�������"
#ifndef CHESSMODE_H
#define CHESSMODE_H

#include "IMode.h" // ����������� ��������� IMode
#include  "ILED.h" // ����������� ���������� LED


class ChessMode: public IMode // ������������ ������ ������ �� ���������� IMode
{
public: 
   ChessMode(const tArrayLeds& led) ; // �������� ����������� � ����� ������
   void Clear() override ; // ��������������� ������� ���������� �����������
};

#endif