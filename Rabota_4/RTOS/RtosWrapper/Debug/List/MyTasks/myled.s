///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V9.30.1.335/W64 for ARM        29/Mar/2023  12:58:01
// Copyright 1999-2022 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\MyTasks\myled.cpp
//    Command line =
//        -f
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Debug\Obj\MyTasks\myled.o.rsp
//        (R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\MyTasks\myled.cpp
//        -lC
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Debug\List\MyTasks
//        -lA
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Debug\List\MyTasks
//        -o
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Debug\Obj\MyTasks
//        --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa
//        --no_clustering --no_scheduling --debug --endian=little
//        --cpu=Cortex-M4 -e --fpu=VFPv4_sp --dlib_config
//        R:\Program\IAR\arm\inc\c\DLib_Config_Normal.h -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\ -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\wrapper\ -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\wrapper\FreeRtos\
//        -I R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\FreeRtos\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\FreeRtos\include\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\FreeRtos\portable\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\FreeRtos\portable\Common\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\FreeRtos\portable\IAR\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\FreeRtos\portable\IAR\ARM_CM4F\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Rtos\FreeRtos\portable\MemMang\
//        -I R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\MyTasks\ -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Common\ -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\CMSIS\ -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Application\ -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Application\Diagnostic\
//        -I R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\AHardware\ -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\AHardware\GpioPort\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\AHardware\IrqController\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\..\CortexLib\AbstractHardware\Pin\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\..\CortexLib\AbstractHardware\Registers\STM32F411\FieldValues\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\..\CortexLib\AbstractHardware\Registers\STM32F411\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\..\CortexLib\AbstractHardware\Registers\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\..\CortexLib\AbstractHardware\Port\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\..\CortexLib\AbstractHardware\Atomic\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\..\CortexLib\Common\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\..\CortexLib\Common\Singleton\
//        -I
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\..\CortexLib\Common\RomObject\
//        -Ol --c++ --no_exceptions --no_rtti) --dependencies=n
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Debug\Obj\MyTasks\myled.o.d
//    Locale       =  C
//    List file    =
//        R:\POIP\POIP\POIP2\Rabots\Rabota_4\RTOS\RtosWrapper\Debug\List\MyTasks\myled.s
//
///////////////////////////////////////////////////////////////////////////////

        RTMODEL "__CPP_Exceptions", "Disabled"
        RTMODEL "__CPP_Language", "C++14"
        RTMODEL "__CPP_Library", "DLib"
        RTMODEL "__CPP_Runtime", "1"
        RTMODEL "__SystemLibrary", "DLib"
        AAPCS BASE,INTERWORK,VFP
        PRESERVE8
        REQUIRE8

        #define SHT_PROGBITS 0x1


        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        END
// 
// 
// 0 bytes of memory
//
//Errors: none
//Warnings: none