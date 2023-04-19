/*******************************************************************************
* Filename      : rccregisters.hpp
*
* Details       : Reset and clock control. This header file is auto-generated
*                 for STM32F0x1 device.
*
*
*******************************************************************************/

#if !defined(RCCREGISTERS_HPP)
#define RCCREGISTERS_HPP

#include "rccfieldvalues.hpp"  //for Bits Fields defs 
#include "registerbase.hpp"   //for RegisterBase
#include "register.hpp"       //for Register
#include "accessmode.hpp"     //for ReadMode, WriteMode, ReadWriteMode  

struct RCC
{
  struct RCCCRBase {} ;

  struct CR : public RegisterBase<0x40021000, 32, ReadWriteMode>
  {
    using HSION = RCC_CR_HSION_Values<RCC::CR, 0, 1, ReadWriteMode, RCCCRBase> ;
    using HSIRDY = RCC_CR_HSIRDY_Values<RCC::CR, 1, 1, ReadMode, RCCCRBase> ;
    using HSITRIM = RCC_CR_HSITRIM_Values<RCC::CR, 3, 5, ReadWriteMode, RCCCRBase> ;
    using HSICAL = RCC_CR_HSICAL_Values<RCC::CR, 8, 8, ReadMode, RCCCRBase> ;
    using HSEON = RCC_CR_HSEON_Values<RCC::CR, 16, 1, ReadWriteMode, RCCCRBase> ;
    using HSERDY = RCC_CR_HSERDY_Values<RCC::CR, 17, 1, ReadMode, RCCCRBase> ;
    using HSEBYP = RCC_CR_HSEBYP_Values<RCC::CR, 18, 1, ReadWriteMode, RCCCRBase> ;
    using CSSON = RCC_CR_CSSON_Values<RCC::CR, 19, 1, ReadWriteMode, RCCCRBase> ;
    using PLLON = RCC_CR_PLLON_Values<RCC::CR, 24, 1, ReadWriteMode, RCCCRBase> ;
    using PLLRDY = RCC_CR_PLLRDY_Values<RCC::CR, 25, 1, ReadMode, RCCCRBase> ;
    using FieldValues = RCC_CR_PLLRDY_Values<RCC::CR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using CRPack  = Register<0x40021000, 32, ReadWriteMode, RCCCRBase, T...> ;

  struct RCCCFGRBase {} ;

  struct CFGR : public RegisterBase<0x40021004, 32, ReadWriteMode>
  {
    using SW = RCC_CFGR_SW_Values<RCC::CFGR, 0, 2, ReadWriteMode, RCCCFGRBase> ;
    using SWS = RCC_CFGR_SWS_Values<RCC::CFGR, 2, 2, ReadMode, RCCCFGRBase> ;
    using HPRE = RCC_CFGR_HPRE_Values<RCC::CFGR, 4, 4, ReadWriteMode, RCCCFGRBase> ;
    using PPRE = RCC_CFGR_PPRE_Values<RCC::CFGR, 8, 3, ReadWriteMode, RCCCFGRBase> ;
    using ADCPRE = RCC_CFGR_ADCPRE_Values<RCC::CFGR, 14, 1, ReadWriteMode, RCCCFGRBase> ;
    using PLLSRC = RCC_CFGR_PLLSRC_Values<RCC::CFGR, 15, 2, ReadWriteMode, RCCCFGRBase> ;
    using PLLXTPRE = RCC_CFGR_PLLXTPRE_Values<RCC::CFGR, 17, 1, ReadWriteMode, RCCCFGRBase> ;
    using PLLMUL = RCC_CFGR_PLLMUL_Values<RCC::CFGR, 18, 4, ReadWriteMode, RCCCFGRBase> ;
    using MCO = RCC_CFGR_MCO_Values<RCC::CFGR, 24, 3, ReadWriteMode, RCCCFGRBase> ;
    using MCOPRE = RCC_CFGR_MCOPRE_Values<RCC::CFGR, 28, 3, ReadWriteMode, RCCCFGRBase> ;
    using PLLNODIV = RCC_CFGR_PLLNODIV_Values<RCC::CFGR, 31, 1, ReadWriteMode, RCCCFGRBase> ;
    using FieldValues = RCC_CFGR_PLLNODIV_Values<RCC::CFGR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using CFGRPack  = Register<0x40021004, 32, ReadWriteMode, RCCCFGRBase, T...> ;

  struct RCCCIRBase {} ;

  struct CIR : public RegisterBase<0x40021008, 32, ReadWriteMode>
  {
    using LSIRDYF = RCC_CIR_LSIRDYF_Values<RCC::CIR, 0, 1, ReadMode, RCCCIRBase> ;
    using LSERDYF = RCC_CIR_LSERDYF_Values<RCC::CIR, 1, 1, ReadMode, RCCCIRBase> ;
    using HSIRDYF = RCC_CIR_HSIRDYF_Values<RCC::CIR, 2, 1, ReadMode, RCCCIRBase> ;
    using HSERDYF = RCC_CIR_HSERDYF_Values<RCC::CIR, 3, 1, ReadMode, RCCCIRBase> ;
    using PLLRDYF = RCC_CIR_PLLRDYF_Values<RCC::CIR, 4, 1, ReadMode, RCCCIRBase> ;
    using HSI14RDYF = RCC_CIR_HSI14RDYF_Values<RCC::CIR, 5, 1, ReadMode, RCCCIRBase> ;
    using HSI48RDYF = RCC_CIR_HSI48RDYF_Values<RCC::CIR, 6, 1, ReadMode, RCCCIRBase> ;
    using CSSF = RCC_CIR_CSSF_Values<RCC::CIR, 7, 1, ReadMode, RCCCIRBase> ;
    using LSIRDYIE = RCC_CIR_LSIRDYIE_Values<RCC::CIR, 8, 1, ReadWriteMode, RCCCIRBase> ;
    using LSERDYIE = RCC_CIR_LSERDYIE_Values<RCC::CIR, 9, 1, ReadWriteMode, RCCCIRBase> ;
    using HSIRDYIE = RCC_CIR_HSIRDYIE_Values<RCC::CIR, 10, 1, ReadWriteMode, RCCCIRBase> ;
    using HSERDYIE = RCC_CIR_HSERDYIE_Values<RCC::CIR, 11, 1, ReadWriteMode, RCCCIRBase> ;
    using PLLRDYIE = RCC_CIR_PLLRDYIE_Values<RCC::CIR, 12, 1, ReadWriteMode, RCCCIRBase> ;
    using HSI14RDYE = RCC_CIR_HSI14RDYE_Values<RCC::CIR, 13, 1, ReadWriteMode, RCCCIRBase> ;
    using HSI48RDYIE = RCC_CIR_HSI48RDYIE_Values<RCC::CIR, 14, 1, ReadWriteMode, RCCCIRBase> ;
    using LSIRDYC = RCC_CIR_LSIRDYC_Values<RCC::CIR, 16, 1, WriteMode, RCCCIRBase> ;
    using LSERDYC = RCC_CIR_LSERDYC_Values<RCC::CIR, 17, 1, WriteMode, RCCCIRBase> ;
    using HSIRDYC = RCC_CIR_HSIRDYC_Values<RCC::CIR, 18, 1, WriteMode, RCCCIRBase> ;
    using HSERDYC = RCC_CIR_HSERDYC_Values<RCC::CIR, 19, 1, WriteMode, RCCCIRBase> ;
    using PLLRDYC = RCC_CIR_PLLRDYC_Values<RCC::CIR, 20, 1, WriteMode, RCCCIRBase> ;
    using HSI14RDYC = RCC_CIR_HSI14RDYC_Values<RCC::CIR, 21, 1, WriteMode, RCCCIRBase> ;
    using HSI48RDYC = RCC_CIR_HSI48RDYC_Values<RCC::CIR, 22, 1, WriteMode, RCCCIRBase> ;
    using CSSC = RCC_CIR_CSSC_Values<RCC::CIR, 23, 1, WriteMode, RCCCIRBase> ;
    using FieldValues = RCC_CIR_CSSC_Values<RCC::CIR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using CIRPack  = Register<0x40021008, 32, ReadWriteMode, RCCCIRBase, T...> ;

  struct RCCAPB2RSTRBase {} ;

  struct APB2RSTR : public RegisterBase<0x4002100C, 32, ReadWriteMode>
  {
    using SYSCFGRST = RCC_APB2RSTR_SYSCFGRST_Values<RCC::APB2RSTR, 0, 1, ReadWriteMode, RCCAPB2RSTRBase> ;
    using ADCRST = RCC_APB2RSTR_ADCRST_Values<RCC::APB2RSTR, 9, 1, ReadWriteMode, RCCAPB2RSTRBase> ;
    using TIM1RST = RCC_APB2RSTR_TIM1RST_Values<RCC::APB2RSTR, 11, 1, ReadWriteMode, RCCAPB2RSTRBase> ;
    using SPI1RST = RCC_APB2RSTR_SPI1RST_Values<RCC::APB2RSTR, 12, 1, ReadWriteMode, RCCAPB2RSTRBase> ;
    using USART1RST = RCC_APB2RSTR_USART1RST_Values<RCC::APB2RSTR, 14, 1, ReadWriteMode, RCCAPB2RSTRBase> ;
    using TIM15RST = RCC_APB2RSTR_TIM15RST_Values<RCC::APB2RSTR, 16, 1, ReadWriteMode, RCCAPB2RSTRBase> ;
    using TIM16RST = RCC_APB2RSTR_TIM16RST_Values<RCC::APB2RSTR, 17, 1, ReadWriteMode, RCCAPB2RSTRBase> ;
    using TIM17RST = RCC_APB2RSTR_TIM17RST_Values<RCC::APB2RSTR, 18, 1, ReadWriteMode, RCCAPB2RSTRBase> ;
    using DBGMCURST = RCC_APB2RSTR_DBGMCURST_Values<RCC::APB2RSTR, 22, 1, ReadWriteMode, RCCAPB2RSTRBase> ;
    using FieldValues = RCC_APB2RSTR_DBGMCURST_Values<RCC::APB2RSTR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using APB2RSTRPack  = Register<0x4002100C, 32, ReadWriteMode, RCCAPB2RSTRBase, T...> ;

  struct RCCAPB1RSTRBase {} ;

  struct APB1RSTR : public RegisterBase<0x40021010, 32, ReadWriteMode>
  {
    using TIM2RST = RCC_APB1RSTR_TIM2RST_Values<RCC::APB1RSTR, 0, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using TIM3RST = RCC_APB1RSTR_TIM3RST_Values<RCC::APB1RSTR, 1, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using TIM6RST = RCC_APB1RSTR_TIM6RST_Values<RCC::APB1RSTR, 4, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using TIM7RST = RCC_APB1RSTR_TIM7RST_Values<RCC::APB1RSTR, 5, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using TIM14RST = RCC_APB1RSTR_TIM14RST_Values<RCC::APB1RSTR, 8, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using WWDGRST = RCC_APB1RSTR_WWDGRST_Values<RCC::APB1RSTR, 11, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using SPI2RST = RCC_APB1RSTR_SPI2RST_Values<RCC::APB1RSTR, 14, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using USART2RST = RCC_APB1RSTR_USART2RST_Values<RCC::APB1RSTR, 17, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using USART3RST = RCC_APB1RSTR_USART3RST_Values<RCC::APB1RSTR, 18, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using USART4RST = RCC_APB1RSTR_USART4RST_Values<RCC::APB1RSTR, 19, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using USART5RST = RCC_APB1RSTR_USART5RST_Values<RCC::APB1RSTR, 20, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using I2C1RST = RCC_APB1RSTR_I2C1RST_Values<RCC::APB1RSTR, 21, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using I2C2RST = RCC_APB1RSTR_I2C2RST_Values<RCC::APB1RSTR, 22, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using USBRST = RCC_APB1RSTR_USBRST_Values<RCC::APB1RSTR, 23, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using CANRST = RCC_APB1RSTR_CANRST_Values<RCC::APB1RSTR, 25, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using CRSRST = RCC_APB1RSTR_CRSRST_Values<RCC::APB1RSTR, 27, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using PWRRST = RCC_APB1RSTR_PWRRST_Values<RCC::APB1RSTR, 28, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using DACRST = RCC_APB1RSTR_DACRST_Values<RCC::APB1RSTR, 29, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using CECRST = RCC_APB1RSTR_CECRST_Values<RCC::APB1RSTR, 30, 1, ReadWriteMode, RCCAPB1RSTRBase> ;
    using FieldValues = RCC_APB1RSTR_CECRST_Values<RCC::APB1RSTR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using APB1RSTRPack  = Register<0x40021010, 32, ReadWriteMode, RCCAPB1RSTRBase, T...> ;

  struct RCCAHBENRBase {} ;

  struct AHBENR : public RegisterBase<0x40021014, 32, ReadWriteMode>
  {
    using DMA1EN = RCC_AHBENR_DMA1EN_Values<RCC::AHBENR, 0, 1, ReadWriteMode, RCCAHBENRBase> ;
    using DMA2EN = RCC_AHBENR_DMA2EN_Values<RCC::AHBENR, 1, 1, ReadWriteMode, RCCAHBENRBase> ;
    using SRAMEN = RCC_AHBENR_SRAMEN_Values<RCC::AHBENR, 2, 1, ReadWriteMode, RCCAHBENRBase> ;
    using FLITFEN = RCC_AHBENR_FLITFEN_Values<RCC::AHBENR, 4, 1, ReadWriteMode, RCCAHBENRBase> ;
    using CRCEN = RCC_AHBENR_CRCEN_Values<RCC::AHBENR, 6, 1, ReadWriteMode, RCCAHBENRBase> ;
    using IOPAEN = RCC_AHBENR_IOPAEN_Values<RCC::AHBENR, 17, 1, ReadWriteMode, RCCAHBENRBase> ;
    using IOPBEN = RCC_AHBENR_IOPBEN_Values<RCC::AHBENR, 18, 1, ReadWriteMode, RCCAHBENRBase> ;
    using IOPCEN = RCC_AHBENR_IOPCEN_Values<RCC::AHBENR, 19, 1, ReadWriteMode, RCCAHBENRBase> ;
    using IOPDEN = RCC_AHBENR_IOPDEN_Values<RCC::AHBENR, 20, 1, ReadWriteMode, RCCAHBENRBase> ;
    using IOPFEN = RCC_AHBENR_IOPFEN_Values<RCC::AHBENR, 22, 1, ReadWriteMode, RCCAHBENRBase> ;
    using TSCEN = RCC_AHBENR_TSCEN_Values<RCC::AHBENR, 24, 1, ReadWriteMode, RCCAHBENRBase> ;
    using FieldValues = RCC_AHBENR_TSCEN_Values<RCC::AHBENR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using AHBENRPack  = Register<0x40021014, 32, ReadWriteMode, RCCAHBENRBase, T...> ;

  struct RCCAPB2ENRBase {} ;

  struct APB2ENR : public RegisterBase<0x40021018, 32, ReadWriteMode>
  {
    using SYSCFGEN = RCC_APB2ENR_SYSCFGEN_Values<RCC::APB2ENR, 0, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using ADCEN = RCC_APB2ENR_ADCEN_Values<RCC::APB2ENR, 9, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using TIM1EN = RCC_APB2ENR_TIM1EN_Values<RCC::APB2ENR, 11, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using SPI1EN = RCC_APB2ENR_SPI1EN_Values<RCC::APB2ENR, 12, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using USART1EN = RCC_APB2ENR_USART1EN_Values<RCC::APB2ENR, 14, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using TIM15EN = RCC_APB2ENR_TIM15EN_Values<RCC::APB2ENR, 16, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using TIM16EN = RCC_APB2ENR_TIM16EN_Values<RCC::APB2ENR, 17, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using TIM17EN = RCC_APB2ENR_TIM17EN_Values<RCC::APB2ENR, 18, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using DBGMCUEN = RCC_APB2ENR_DBGMCUEN_Values<RCC::APB2ENR, 22, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using USART8EN = RCC_APB2ENR_USART8EN_Values<RCC::APB2ENR, 7, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using USART7EN = RCC_APB2ENR_USART7EN_Values<RCC::APB2ENR, 6, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using USART6EN = RCC_APB2ENR_USART6EN_Values<RCC::APB2ENR, 5, 1, ReadWriteMode, RCCAPB2ENRBase> ;
    using FieldValues = RCC_APB2ENR_USART6EN_Values<RCC::APB2ENR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using APB2ENRPack  = Register<0x40021018, 32, ReadWriteMode, RCCAPB2ENRBase, T...> ;

  struct RCCAPB1ENRBase {} ;

  struct APB1ENR : public RegisterBase<0x4002101C, 32, ReadWriteMode>
  {
    using TIM2EN = RCC_APB1ENR_TIM2EN_Values<RCC::APB1ENR, 0, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using TIM3EN = RCC_APB1ENR_TIM3EN_Values<RCC::APB1ENR, 1, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using TIM6EN = RCC_APB1ENR_TIM6EN_Values<RCC::APB1ENR, 4, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using TIM7EN = RCC_APB1ENR_TIM7EN_Values<RCC::APB1ENR, 5, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using TIM14EN = RCC_APB1ENR_TIM14EN_Values<RCC::APB1ENR, 8, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using WWDGEN = RCC_APB1ENR_WWDGEN_Values<RCC::APB1ENR, 11, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using SPI2EN = RCC_APB1ENR_SPI2EN_Values<RCC::APB1ENR, 14, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using USART2EN = RCC_APB1ENR_USART2EN_Values<RCC::APB1ENR, 17, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using USART3EN = RCC_APB1ENR_USART3EN_Values<RCC::APB1ENR, 18, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using USART4EN = RCC_APB1ENR_USART4EN_Values<RCC::APB1ENR, 19, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using USART5EN = RCC_APB1ENR_USART5EN_Values<RCC::APB1ENR, 20, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using I2C1EN = RCC_APB1ENR_I2C1EN_Values<RCC::APB1ENR, 21, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using I2C2EN = RCC_APB1ENR_I2C2EN_Values<RCC::APB1ENR, 22, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using USBRST = RCC_APB1ENR_USBRST_Values<RCC::APB1ENR, 23, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using CANEN = RCC_APB1ENR_CANEN_Values<RCC::APB1ENR, 25, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using CRSEN = RCC_APB1ENR_CRSEN_Values<RCC::APB1ENR, 27, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using PWREN = RCC_APB1ENR_PWREN_Values<RCC::APB1ENR, 28, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using DACEN = RCC_APB1ENR_DACEN_Values<RCC::APB1ENR, 29, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using CECEN = RCC_APB1ENR_CECEN_Values<RCC::APB1ENR, 30, 1, ReadWriteMode, RCCAPB1ENRBase> ;
    using FieldValues = RCC_APB1ENR_CECEN_Values<RCC::APB1ENR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using APB1ENRPack  = Register<0x4002101C, 32, ReadWriteMode, RCCAPB1ENRBase, T...> ;

  struct RCCBDCRBase {} ;

  struct BDCR : public RegisterBase<0x40021020, 32, ReadWriteMode>
  {
    using LSEON = RCC_BDCR_LSEON_Values<RCC::BDCR, 0, 1, ReadWriteMode, RCCBDCRBase> ;
    using LSERDY = RCC_BDCR_LSERDY_Values<RCC::BDCR, 1, 1, ReadMode, RCCBDCRBase> ;
    using LSEBYP = RCC_BDCR_LSEBYP_Values<RCC::BDCR, 2, 1, ReadWriteMode, RCCBDCRBase> ;
    using LSEDRV = RCC_BDCR_LSEDRV_Values<RCC::BDCR, 3, 2, ReadWriteMode, RCCBDCRBase> ;
    using RTCSEL = RCC_BDCR_RTCSEL_Values<RCC::BDCR, 8, 2, ReadWriteMode, RCCBDCRBase> ;
    using RTCEN = RCC_BDCR_RTCEN_Values<RCC::BDCR, 15, 1, ReadWriteMode, RCCBDCRBase> ;
    using BDRST = RCC_BDCR_BDRST_Values<RCC::BDCR, 16, 1, ReadWriteMode, RCCBDCRBase> ;
    using FieldValues = RCC_BDCR_BDRST_Values<RCC::BDCR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using BDCRPack  = Register<0x40021020, 32, ReadWriteMode, RCCBDCRBase, T...> ;

  struct RCCCSRBase {} ;

  struct CSR : public RegisterBase<0x40021024, 32, ReadWriteMode>
  {
    using LSION = RCC_CSR_LSION_Values<RCC::CSR, 0, 1, ReadWriteMode, RCCCSRBase> ;
    using LSIRDY = RCC_CSR_LSIRDY_Values<RCC::CSR, 1, 1, ReadMode, RCCCSRBase> ;
    using RMVF = RCC_CSR_RMVF_Values<RCC::CSR, 24, 1, ReadWriteMode, RCCCSRBase> ;
    using OBLRSTF = RCC_CSR_OBLRSTF_Values<RCC::CSR, 25, 1, ReadWriteMode, RCCCSRBase> ;
    using PINRSTF = RCC_CSR_PINRSTF_Values<RCC::CSR, 26, 1, ReadWriteMode, RCCCSRBase> ;
    using PORRSTF = RCC_CSR_PORRSTF_Values<RCC::CSR, 27, 1, ReadWriteMode, RCCCSRBase> ;
    using SFTRSTF = RCC_CSR_SFTRSTF_Values<RCC::CSR, 28, 1, ReadWriteMode, RCCCSRBase> ;
    using IWDGRSTF = RCC_CSR_IWDGRSTF_Values<RCC::CSR, 29, 1, ReadWriteMode, RCCCSRBase> ;
    using WWDGRSTF = RCC_CSR_WWDGRSTF_Values<RCC::CSR, 30, 1, ReadWriteMode, RCCCSRBase> ;
    using LPWRRSTF = RCC_CSR_LPWRRSTF_Values<RCC::CSR, 31, 1, ReadWriteMode, RCCCSRBase> ;
    using FieldValues = RCC_CSR_LPWRRSTF_Values<RCC::CSR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using CSRPack  = Register<0x40021024, 32, ReadWriteMode, RCCCSRBase, T...> ;

  struct RCCAHBRSTRBase {} ;

  struct AHBRSTR : public RegisterBase<0x40021028, 32, ReadWriteMode>
  {
    using IOPARST = RCC_AHBRSTR_IOPARST_Values<RCC::AHBRSTR, 17, 1, ReadWriteMode, RCCAHBRSTRBase> ;
    using IOPBRST = RCC_AHBRSTR_IOPBRST_Values<RCC::AHBRSTR, 18, 1, ReadWriteMode, RCCAHBRSTRBase> ;
    using IOPCRST = RCC_AHBRSTR_IOPCRST_Values<RCC::AHBRSTR, 19, 1, ReadWriteMode, RCCAHBRSTRBase> ;
    using IOPDRST = RCC_AHBRSTR_IOPDRST_Values<RCC::AHBRSTR, 20, 1, ReadWriteMode, RCCAHBRSTRBase> ;
    using IOPFRST = RCC_AHBRSTR_IOPFRST_Values<RCC::AHBRSTR, 22, 1, ReadWriteMode, RCCAHBRSTRBase> ;
    using TSCRST = RCC_AHBRSTR_TSCRST_Values<RCC::AHBRSTR, 24, 1, ReadWriteMode, RCCAHBRSTRBase> ;
    using FieldValues = RCC_AHBRSTR_TSCRST_Values<RCC::AHBRSTR, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using AHBRSTRPack  = Register<0x40021028, 32, ReadWriteMode, RCCAHBRSTRBase, T...> ;

  struct RCCCFGR2Base {} ;

  struct CFGR2 : public RegisterBase<0x4002102C, 32, ReadWriteMode>
  {
    using PREDIV = RCC_CFGR2_PREDIV_Values<RCC::CFGR2, 0, 4, ReadWriteMode, RCCCFGR2Base> ;
    using FieldValues = RCC_CFGR2_PREDIV_Values<RCC::CFGR2, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using CFGR2Pack  = Register<0x4002102C, 32, ReadWriteMode, RCCCFGR2Base, T...> ;

  struct RCCCFGR3Base {} ;

  struct CFGR3 : public RegisterBase<0x40021030, 32, ReadWriteMode>
  {
    using USART1SW = RCC_CFGR3_USART1SW_Values<RCC::CFGR3, 0, 2, ReadWriteMode, RCCCFGR3Base> ;
    using I2C1SW = RCC_CFGR3_I2C1SW_Values<RCC::CFGR3, 4, 1, ReadWriteMode, RCCCFGR3Base> ;
    using CECSW = RCC_CFGR3_CECSW_Values<RCC::CFGR3, 6, 1, ReadWriteMode, RCCCFGR3Base> ;
    using USBSW = RCC_CFGR3_USBSW_Values<RCC::CFGR3, 7, 1, ReadWriteMode, RCCCFGR3Base> ;
    using ADCSW = RCC_CFGR3_ADCSW_Values<RCC::CFGR3, 8, 1, ReadWriteMode, RCCCFGR3Base> ;
    using USART2SW = RCC_CFGR3_USART2SW_Values<RCC::CFGR3, 16, 2, ReadWriteMode, RCCCFGR3Base> ;
    using FieldValues = RCC_CFGR3_USART2SW_Values<RCC::CFGR3, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using CFGR3Pack  = Register<0x40021030, 32, ReadWriteMode, RCCCFGR3Base, T...> ;

  struct RCCCR2Base {} ;

  struct CR2 : public RegisterBase<0x40021034, 32, ReadWriteMode>
  {
    using HSI14ON = RCC_CR2_HSI14ON_Values<RCC::CR2, 0, 1, ReadWriteMode, RCCCR2Base> ;
    using HSI14RDY = RCC_CR2_HSI14RDY_Values<RCC::CR2, 1, 1, ReadMode, RCCCR2Base> ;
    using HSI14DIS = RCC_CR2_HSI14DIS_Values<RCC::CR2, 2, 1, ReadWriteMode, RCCCR2Base> ;
    using HSI14TRIM = RCC_CR2_HSI14TRIM_Values<RCC::CR2, 3, 5, ReadWriteMode, RCCCR2Base> ;
    using HSI14CAL = RCC_CR2_HSI14CAL_Values<RCC::CR2, 8, 8, ReadMode, RCCCR2Base> ;
    using HSI48ON = RCC_CR2_HSI48ON_Values<RCC::CR2, 16, 1, ReadWriteMode, RCCCR2Base> ;
    using HSI48RDY = RCC_CR2_HSI48RDY_Values<RCC::CR2, 17, 1, ReadMode, RCCCR2Base> ;
    using HSI48CAL = RCC_CR2_HSI48CAL_Values<RCC::CR2, 24, 1, ReadMode, RCCCR2Base> ;
    using FieldValues = RCC_CR2_HSI48CAL_Values<RCC::CR2, 0, 0, NoAccess, NoAccess> ;
  } ;

  template<typename... T> 
  using CR2Pack  = Register<0x40021034, 32, ReadWriteMode, RCCCR2Base, T...> ;

} ;

#endif //#if !defined(RCCREGISTERS_HPP)
