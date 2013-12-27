begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * sDMA device driver interface for the TI SoC  *  * See the ti_sdma.c file for implementation details.  *  * Reference:  *  OMAP35x Applications Processor  *   Technical Reference Manual  *  (omap35xx_techref.pdf)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_DMA_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_DMA_H_
end_define

begin_define
define|#
directive|define
name|TI_SDMA_ENDIAN_BIG
value|0x1
end_define

begin_define
define|#
directive|define
name|TI_SDMA_ENDIAN_LITTLE
value|0x0
end_define

begin_define
define|#
directive|define
name|TI_SDMA_BURST_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|TI_SDMA_BURST_16
value|0x1
end_define

begin_define
define|#
directive|define
name|TI_SDMA_BURST_32
value|0x2
end_define

begin_define
define|#
directive|define
name|TI_SDMA_BURST_64
value|0x3
end_define

begin_define
define|#
directive|define
name|TI_SDMA_DATA_8BITS_SCALAR
value|0x0
end_define

begin_define
define|#
directive|define
name|TI_SDMA_DATA_16BITS_SCALAR
value|0x1
end_define

begin_define
define|#
directive|define
name|TI_SDMA_DATA_32BITS_SCALAR
value|0x2
end_define

begin_define
define|#
directive|define
name|TI_SDMA_ADDR_CONSTANT
value|0x0
end_define

begin_define
define|#
directive|define
name|TI_SDMA_ADDR_POST_INCREMENT
value|0x1
end_define

begin_define
define|#
directive|define
name|TI_SDMA_ADDR_SINGLE_INDEX
value|0x2
end_define

begin_define
define|#
directive|define
name|TI_SDMA_ADDR_DOUBLE_INDEX
value|0x3
end_define

begin_comment
comment|/**  * Status flags for the DMA callback  *  */
end_comment

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_DROP
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_HALF
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_FRAME
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_LAST
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_BLOCK
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_SYNC
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_PKT
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_TRANS_ERR
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_SECURE_ERR
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_SUPERVISOR_ERR
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_MISALIGNED_ADRS_ERR
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_STATUS_DRAIN_END
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_SYNC_FRAME
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_SYNC_BLOCK
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_SYNC_PACKET
value|(TI_SDMA_SYNC_FRAME | TI_SDMA_SYNC_BLOCK)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_SYNC_TRIG_ON_SRC
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_SYNC_TRIG_ON_DST
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_IRQ_FLAG_DROP
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_IRQ_FLAG_HALF_FRAME_COMPL
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_IRQ_FLAG_FRAME_COMPL
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_IRQ_FLAG_START_LAST_FRAME
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_IRQ_FLAG_BLOCK_COMPL
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_IRQ_FLAG_ENDOF_PKT
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|TI_SDMA_IRQ_FLAG_DRAIN
value|(1UL<< 12)
end_define

begin_function_decl
name|int
name|ti_sdma_activate_channel
parameter_list|(
name|unsigned
name|int
modifier|*
name|ch
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|uint32_t
name|status
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_deactivate_channel
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_start_xfer
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|unsigned
name|int
name|src_paddr
parameter_list|,
name|unsigned
name|long
name|dst_paddr
parameter_list|,
name|unsigned
name|int
name|frmcnt
parameter_list|,
name|unsigned
name|int
name|elmcnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_start_xfer_packet
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|unsigned
name|int
name|src_paddr
parameter_list|,
name|unsigned
name|long
name|dst_paddr
parameter_list|,
name|unsigned
name|int
name|frmcnt
parameter_list|,
name|unsigned
name|int
name|elmcnt
parameter_list|,
name|unsigned
name|int
name|pktsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_stop_xfer
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_enable_channel_irq
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_disable_channel_irq
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_get_channel_status
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|uint32_t
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_set_xfer_endianess
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|unsigned
name|int
name|src
parameter_list|,
name|unsigned
name|int
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_set_xfer_burst
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|unsigned
name|int
name|src
parameter_list|,
name|unsigned
name|int
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_set_xfer_data_type
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|unsigned
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_set_callback
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|uint32_t
name|status
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_sync_params
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|unsigned
name|int
name|trigger
parameter_list|,
name|unsigned
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ti_sdma_set_addr_mode
parameter_list|(
name|unsigned
name|int
name|ch
parameter_list|,
name|unsigned
name|int
name|src_mode
parameter_list|,
name|unsigned
name|int
name|dst_mode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_SDMA_H_ */
end_comment

end_unit

