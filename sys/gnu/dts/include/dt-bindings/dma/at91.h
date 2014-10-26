begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides macros for at91 dma bindings.  *  * Copyright (C) 2013 Ludovic Desroches<ludovic.desroches@atmel.com>  *  * GPLv2 only  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_AT91_DMA_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_AT91_DMA_H__
end_define

begin_comment
comment|/*  * Source and/or destination peripheral ID  */
end_comment

begin_define
define|#
directive|define
name|AT91_DMA_CFG_PER_ID_MASK
value|(0xff)
end_define

begin_define
define|#
directive|define
name|AT91_DMA_CFG_PER_ID
parameter_list|(
name|id
parameter_list|)
value|(id& AT91_DMA_CFG_PER_ID_MASK)
end_define

begin_comment
comment|/*  * FIFO configuration: it defines when a request is serviced.  */
end_comment

begin_define
define|#
directive|define
name|AT91_DMA_CFG_FIFOCFG_OFFSET
value|(8)
end_define

begin_define
define|#
directive|define
name|AT91_DMA_CFG_FIFOCFG_MASK
value|(0xf<< AT91_DMA_CFG_FIFOCFG_OFFSET)
end_define

begin_define
define|#
directive|define
name|AT91_DMA_CFG_FIFOCFG_HALF
value|(0x0<< AT91_DMA_CFG_FIFOCFG_OFFSET)
end_define

begin_comment
comment|/* half FIFO (default behavior) */
end_comment

begin_define
define|#
directive|define
name|AT91_DMA_CFG_FIFOCFG_ALAP
value|(0x1<< AT91_DMA_CFG_FIFOCFG_OFFSET)
end_define

begin_comment
comment|/* largest defined AHB burst */
end_comment

begin_define
define|#
directive|define
name|AT91_DMA_CFG_FIFOCFG_ASAP
value|(0x2<< AT91_DMA_CFG_FIFOCFG_OFFSET)
end_define

begin_comment
comment|/* single AHB access */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_AT91_DMA_H__ */
end_comment

end_unit

