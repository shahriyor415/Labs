<<<<<<< HEAD
#include <iostream>

// ���������� ���������� ���������� �� ����������� � ���� ������
long long j = std::numeric_limits<decltype(j)>::max()/2;
 
int main()
{ 
  // ����������� ������� � ������������� ����� ���� long long
   std::cout <<sizeof(j) <<" ���� �������� ���������� j "<< std::endl;
   std::cout <<"MAX �������� ���������� j = "<<std::numeric_limits<decltype(j)>::max() << std::endl;
   std::cout <<"j = "<<j << std::endl; // ����� ���������� j
  // ������������� 8 ���������� ������ �������� ���� int
 auto* ptrU8 = reinterpret_cast<uint8_t*>(&j);
 auto* ptr8 = reinterpret_cast<int8_t*>(&j);
   
 auto* ptrU16 = reinterpret_cast<uint16_t*>(&j);
 auto* ptr16 = reinterpret_cast<int16_t*>(&j);
   
 auto* ptrU32 = reinterpret_cast<uint32_t*>(&j);
 auto* ptr32 = reinterpret_cast<int32_t*>(&j);
   
 auto* ptrU64 = reinterpret_cast<uint64_t*>(&j);  
 auto* ptr64 = reinterpret_cast<int64_t*>(&j); 
 std::cout<<std::endl;
// ����� �������� ���������� j, ���������� � ����������   
 std::cout <<"unsigned int8 = " << static_cast<int>(*ptrU8) << std::endl;
 std::cout <<"int8 = "<< static_cast<int>(*ptr8) << std::endl;
  
 std::cout <<"unsigned int16 = "<< static_cast<int>(*ptrU16) << std::endl;
 std::cout <<"int16 = "<< static_cast<int>(*ptr16) << std::endl;
  
 std::cout <<"unsigned int32 = "<< static_cast<int>(*ptrU32) << std::endl;
 std::cout <<"int32 = "<< static_cast<int>(*ptr32) << std::endl;

 std::cout <<"unsigned int64 = "<< static_cast<int>(*ptrU64) << std::endl;
 std::cout <<"int64 = "<< static_cast<int>(*ptr64) << std::endl; 
 // ����� ������ ���������� ���������� j (�������� ���������)
 std::cout <<"����� ���������� j = " << ptrU64 << std::endl;
 //���������� ������� ��������� �� 1
 ptrU8++;
 ptr8++;
 
 ptrU16++;
 ptr16++;
 
 ptrU32++;
 ptr32++;
 
 ptrU64++;
 ptr64++;
 // ����� �������� ���������� � ���������� ������������ �� 1   
 std::cout<< std::endl;
 std::cout <<"unsigned int8 = " << static_cast<int>(*ptrU8) << std::endl;
 std::cout <<"int8 = "<< static_cast<int>(*ptr8) << std::endl;
  
 std::cout <<"unsigned int16 = "<< static_cast<int>(*ptrU16) << std::endl;
 std::cout <<"int16 = "<< static_cast<int>(*ptr16) << std::endl;
  
 std::cout <<"unsigned int32 = "<< static_cast<int>(*ptrU32) << std::endl;
 std::cout <<"int32 = "<< static_cast<int>(*ptr32) << std::endl;

 std::cout <<"unsigned int64 = "<< static_cast<int>(*ptrU64) << std::endl;
 std::cout <<"int64 = "<< static_cast<int>(*ptr64) << std::endl; 
 
// ����� ���������� ������ ��������� ����� j
 std::cout <<"�������� ����� ����� j, ��� 16-��������� = " << ptrU16 << std::endl;
 std::cout <<"�������� ����� ����� j, ��� 32-��������� = " << ptrU32 << std::endl;
 std::cout <<"�������� ����� ����� j, ��� 64-��������� = " << ptrU64 << std::endl;
 
  
  
=======
#include <iostream>

long long j = 4294967295; // ���������� ����������
 
int main()
{ 
  // ����������� ������� � ������������� ����� ���� long long
   std::cout <<sizeof(long long) <<" ���� �������� ��� long long"<< std::endl;
   std::cout <<"MAX �������� ���� lonf long = "<<LLONG_MAX << std::endl;
   std::cout <<"j = "<<j << std::endl; // ����� ���������� j
  // ������������� 8 ���������� ������ �������� ���� int
 uint8_t* ptrU8 = reinterpret_cast<uint8_t*>(&j);
 int8_t* ptr8 = reinterpret_cast<int8_t*>(&j);
   
 uint16_t* ptrU16 = reinterpret_cast<uint16_t*>(&j);
 int16_t* ptr16 = reinterpret_cast<int16_t*>(&j);
   
 uint32_t* ptrU32 = reinterpret_cast<uint32_t*>(&j);
 int32_t* ptr32 = reinterpret_cast<int32_t*>(&j);
   
 uint64_t* ptrU64 = reinterpret_cast<uint64_t*>(&j);  
 int64_t* ptr64 = reinterpret_cast<int64_t*>(&j); 
 std::cout<<std::endl;
// ����� �������� ���������� j, ���������� � ����������   
 std::cout <<"unsigned int8 = " << static_cast<int>(*ptrU8) << std::endl;
 std::cout <<"int8 = "<< static_cast<int>(*ptr8) << std::endl;
  
 std::cout <<"unsigned int16 = "<< static_cast<int>(*ptrU16) << std::endl;
 std::cout <<"int16 = "<< static_cast<int>(*ptr16) << std::endl;
  
 std::cout <<"unsigned int32 = "<< static_cast<int>(*ptrU32) << std::endl;
 std::cout <<"int32 = "<< static_cast<int>(*ptr32) << std::endl;

 std::cout <<"unsigned int64 = "<< static_cast<int>(*ptrU64) << std::endl;
 std::cout <<"int64 = "<< static_cast<int>(*ptr64) << std::endl; 
 // ����� ������ ���������� ���������� j (�������� ���������)
 std::cout <<"����� ���������� j = " << ptrU16 << std::endl;
 std::cout <<"����� ���������� j = " << ptrU32 << std::endl;
 std::cout <<"����� ���������� j = " << ptrU64 << std::endl;
 //���������� ������� ��������� �� 1
 ptrU8++;
 ptr8++;
 
 ptrU16++;
 ptr16++;
 
 ptrU32++;
 ptr32++;
 
 ptrU64++;
 ptr64++;
 // ����� �������� ���������� � ���������� ������������ �� 1   
 std::cout<< std::endl;
 std::cout <<"unsigned int8 = " << static_cast<int>(*ptrU8) << std::endl;
 std::cout <<"int8 = "<< static_cast<int>(*ptr8) << std::endl;
  
 std::cout <<"unsigned int16 = "<< static_cast<int>(*ptrU16) << std::endl;
 std::cout <<"int16 = "<< static_cast<int>(*ptr16) << std::endl;
  
 std::cout <<"unsigned int32 = "<< static_cast<int>(*ptrU32) << std::endl;
 std::cout <<"int32 = "<< static_cast<int>(*ptr32) << std::endl;

 std::cout <<"unsigned int64 = "<< static_cast<int>(*ptrU64) << std::endl;
 std::cout <<"int64 = "<< static_cast<int>(*ptr64) << std::endl; 
 
// ����� ���������� ������ ��������� ����� j
 std::cout <<"�������� ����� ����� j, ��� 16-��������� ���� = " << ptrU16 << std::endl;
 std::cout <<"�������� ����� ����� j, ��� 32-��������� ���� = " << ptrU32 << std::endl;
 std::cout <<"�������� ����� ����� j, ��� 64-��������� ���� = " << ptrU64 << std::endl;
  
  
  
>>>>>>> dd41c8f31af8845b72ebcb1cc09e39e9ec954adc
}