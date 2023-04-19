#ifndef  SENDER_H  //������ �� �������� ����������� ������������� �����
#define  SENDER_H  //������ �� �������� ����������� ������������� �����

#include <string>    // ���������� ���� ������ ������ 
#include <iostream> 
#include <array>


  template <typename TUSART> // ��������� �����, ���� ��������� ����� �� USART��
class Sender 
{
  public:
   static void Send (std::string str) // ������� �������� ������
    {
     // TUSART::CR1::RE::Enable::Set();
      //TUSART::CR1::RXNEIE::InterruptWhenRXNE::Set();
      i = 0;                                         //��������� �������� ���������� �������� 
      localStroka = str;                             // ���������� ������������� ��������
      SendOneSymvol();                               // ����� �������
      TUSART::CR1::TE::Enable::Set();                // 
      TUSART::CR1::TXEIE::InterruptWhenTXE::Set();   //
    }

   static void SendOneSymvol ()    //������� �������� �������� ������
   {
      //TUSART::CR1::RE::Enable::Set();
      //TUSART::CR1::RXNEIE::InterruptWhenRXNE::Set();
     if (i > localStroka.size())   // ���� �������� ����� ������
     {
       i = 0;                                         // �������� �������
       TUSART::CR1::TE::Disable::Set();               // ��������� ��������
       TUSART::CR1::TXEIE::InterruptInhibited::Set(); // ��������� ���������� 
     }
     else  // ���� �� �������� ����� ������, ��
     {
       TUSART::DR::Write(localStroka[i]);  // ���������� � ������� ������ (1 ����)
       i++;                                // ��������� � ���������� �������
     }
   }

   
 /* static void ReciveOneSymvol()
   {
     StrokaRx[f] = TUSART::DR::Get();
          if (f == byteRx)
          {
            f = 0;
            USART2::CR1::RE::Disable::Set();
            USART2::CR1::RXNEIE::InterruptInhibited::Set();
            std::cout << StrokaRx;
          }
          else
          {
            f++;
            
          }
       }*/
   
   private:
  // static inline int8_t f = 0U;                            // ������� ��� ������
  // static inline int8_t byteRx =2 ;                         // ���������� ����������� ����
   //static inline std::array<int, byteRx> StrokaRx[];         // ������ ������
 
   
   static inline std::string localStroka;    // ������ ��������   
   static inline int32_t i = 0U;            // ������� ����������� �������� ��� �������� ������
}; 





#endif  //����� ������������� �����