/**
 * @file fcrt_define.h
 * @author Нелюбин Виктор. ЗАО НТЦ Модуль (v.nelyubin@module.ru)
 * @brief определения для контроллера ВСРВ(ГРЭК)
 * @version 0.1
 * @date 2022-06-01
 * 
 * 
 */
#ifndef FCRT_DEF_H
#define FCRT_DEF_H
///разрядность указателей 64 бита
#define SYSTEM_X64
///разрядность указателей 32 бита
// #define SYSTEM_X32

#ifdef SYSTEM_X32
///разрядность указателя
typedef uint32_t platform_addr_type;
#elif defined(SYSTEM_X64)
///разрядность указателя
typedef uint64_t platform_addr_type;
#else
#error Select platform address type
#endif

/**
 * @brief освобождает блок памяти, полученный fcrt_allocator
 * 
 */
typedef void (*fcrt_release)(void*);
///выбор вариант сигнатуры fcrtInit
#define FCRT_INIT_LONG_PARAM
#define TX_Q_LEN	    8
#define RX_Q_LEN	    16
#define MSG_MAX_LEN (32 * 1024)
///размер области ОЗУ для внутреннего исп-я контроллера
/// @todo расчитывать по параметрам загрузочной таблицы
#define FCRT_INTERNAL_RAM_SZ_B 0x100000u
///маска адресов дма для контроллера
#define FCRT_DMA_MASK			0xFFFFFFFFull


#endif
