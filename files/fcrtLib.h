#ifndef __FCRTLIB_H
#define __FCRTLIB_H

#define FCRT_VC_MAX         64

#define FCRT_FLAG_PHY_A     0x000000001    // работать только через линию А (основную)
#define FCRT_FLAG_PHY_B     0x000000002    // работать только через линию Б (резервную)

/* align addr on a size boundary - adjust address up/down if needed */
#define _ALIGN_UP(addr, size)  (((addr)+((size)-1))&(~((typeof(addr))(size)-1)))

// структура описания канала передатчика
typedef struct {
    unsigned priority;      // приоритет от 0 до 15
    unsigned period;        // период отправки сообщений в мкс
    unsigned asm_id;        // ASM ID
    unsigned dst_id;        // FC ID
    unsigned max_size;      // максимальный размер сообщения в байтах
    unsigned q_depth;       // размер очереди сообщений
    unsigned flags;         // флаги FCRT_FLAG_
} FCRT_TX_CFG;

// структура описания канала приемника
typedef struct {
    unsigned asm_id;        // ASM ID
    unsigned max_size;      // максимальный размер сообщения в байтах
    unsigned q_depth;       // размер очереди сообщений
    unsigned flags;         // флаги FCRT_FLAG_
} FCRT_RX_CFG;

// структура описания контроллера
typedef struct {
    unsigned fc_id;         // FC ID
    unsigned bbNum;         // число BB кредитов
    unsigned dummyRegs;
} FCRT_CTRL_CFG;

typedef void* (*fcrt_allocator)(u32 size, u32 align, dma_addr_t * da);

// функция инициализации
int fcrtInit(void* regs, FCRT_CTRL_CFG* ctrl, FCRT_TX_CFG* txCfg, FCRT_RX_CFG* rxCfg, unsigned nVC, fcrt_allocator fcrtAlloc);
// функция отправки сообщения по ВК
int fcrtSend(unsigned vc, void* buf, unsigned size);
// функция приема сообщения по ВК
int fcrtRecv(unsigned vc, void* buf, unsigned* size);
// опрос готовности приемных ВК
int fcrtRxReady(void);
// распечатка регистров контроллера
void fcrtShow(unsigned opt, int nch, int ch0);
// выделение непрерывной памяти под DMA буферы
//void* fcrtAlloc(unsigned size, unsigned align, dma_addr_t* da);

#endif //__FCRTLIB_H
