#include "ChessMode.h" // ����������� �������������


ChessMode::ChessMode(const tArrayLeds& leds): IMode(leds) // ������������ ���� ������� (�������) �� ���������� IMode
{
  Clear(); // ��������������� �������
  
}

void ChessMode::Clear()  // ���������� ��������������� �������
{
    for (std::uint32_t i = 0; i < std::size(_leds); ++i)
    {
      if ((i % 2) == 0)
      {
         _leds[i]->Toggle();
      }
    }
}
