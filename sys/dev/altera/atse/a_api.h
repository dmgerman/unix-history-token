begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Bjoern A. Zeeb  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-11-C-0249)  * ("MRC2"), as part of the DARPA MRC research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Altera, Embedded Peripherals IP, User Guide, v. 11.0, June 2011.  * UG-01085-11.0.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_A_API_H
end_ifndef

begin_define
define|#
directive|define
name|_A_API_H
end_define

begin_comment
comment|/* Table 16-1. Memory Map. */
end_comment

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_METADATA
value|0x04
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_SOP
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_EOP
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_EMPTY_MASK
value|0x000000f7
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_EMPTY_SHIFT
value|2
end_define

begin_comment
comment|/* Reserved				(1<<7)	   */
end_comment

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_CHANNEL_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_CHANNEL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_ERROR_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_ERROR_SHIFT
value|16
end_define

begin_comment
comment|/* Reserved				0xff000000 */
end_comment

begin_comment
comment|/* Table 16-3. FIFO Status Register Memory Map. */
end_comment

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_REG_FILL_LEVEL
value|0x00
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_REG_I_STATUS
value|0x04
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_REG_EVENT
value|0x08
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_REG_INT_ENABLE
value|0x0c
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_REG_ALMOSTFULL
value|0x10
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_REG_ALMOSTEMPTY
value|0x14
end_define

begin_comment
comment|/* Table 16-5. Status Bit Field Descriptions. */
end_comment

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_FULL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_EMPTY
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_ALMOSTFULL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_ALMOSTEMPTY
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_OVERFLOW
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_STATUS_UNDERFLOW
value|(1<<5)
end_define

begin_comment
comment|/* Table 16-6. Event Bit Field Descriptions. */
end_comment

begin_comment
comment|/* XXX Datasheet has incorrect bit fields. Validate. */
end_comment

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_EVENT_FULL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_EVENT_EMPTY
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_EVENT_ALMOSTFULL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_EVENT_ALMOSTEMPTY
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_EVENT_OVERFLOW
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_EVENT_UNDERFLOW
value|(1<<5)
end_define

begin_comment
comment|/* Table 16-7. InterruptEnable Bit Field Descriptions. */
end_comment

begin_comment
comment|/* XXX Datasheet has incorrect bit fields. Validate. */
end_comment

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_INTR_FULL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_INTR_EMPTY
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_INTR_ALMOSTFULL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_INTR_ALMOSTEMPTY
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_INTR_OVERFLOW
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_INTR_UNDERFLOW
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|A_ONCHIP_FIFO_MEM_CORE_INTR_ALL
define|\
value|(A_ONCHIP_FIFO_MEM_CORE_INTR_EMPTY|		\ 	    A_ONCHIP_FIFO_MEM_CORE_INTR_FULL|		\ 	    A_ONCHIP_FIFO_MEM_CORE_INTR_ALMOSTEMPTY|	\ 	    A_ONCHIP_FIFO_MEM_CORE_INTR_ALMOSTFULL|	\ 	    A_ONCHIP_FIFO_MEM_CORE_INTR_OVERFLOW|	\ 	    A_ONCHIP_FIFO_MEM_CORE_INTR_UNDERFLOW)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _A_API_H */
end_comment

begin_comment
comment|/* end */
end_comment

end_unit

