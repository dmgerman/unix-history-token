begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2013-2015 John Wehle<john@feith.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_AMLOGIC_AML8726_MMC_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_AMLOGIC_AML8726_MMC_H
end_define

begin_define
define|#
directive|define
name|AML_MMC_ALIGN_DMA
value|4
end_define

begin_define
define|#
directive|define
name|AML_MMC_MAX_DMA
value|4096
end_define

begin_comment
comment|/*  * Timeouts are in milliseconds  *  * Read and write are per section 4.6.2 of the:  *  *   SD Specifications Part 1  *   Physical Layer Simplified Specification  *   Version 4.10  */
end_comment

begin_define
define|#
directive|define
name|AML_MMC_CMD_TIMEOUT
value|50
end_define

begin_define
define|#
directive|define
name|AML_MMC_READ_TIMEOUT
value|100
end_define

begin_define
define|#
directive|define
name|AML_MMC_WRITE_TIMEOUT
value|500
end_define

begin_define
define|#
directive|define
name|AML_MMC_MAX_TIMEOUT
value|5000
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_ARGUMENT_REG
value|0
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_SEND_REG
value|4
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_REP_PKG_CNT_MASK
value|(0xffU<< 24)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_REP_PKG_CNT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_CMD_HAS_DATA
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_CHECK_DAT0_BUSY
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_RESP_CRC7_FROM_8
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_RESP_HAS_DATA
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_RESP_NO_CRC7
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_RESP_BITS_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_RESP_BITS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_START_BIT
value|(0<< 7)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_TRANS_BIT_HOST
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_INDEX_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|AML_MMC_CMD_INDEX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_REG
value|8
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_WR_CRC_STAT_MASK
value|(7U<< 29)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_WR_CRC_STAT_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_WR_DELAY_MASK
value|(0x3f<< 23)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_WR_DELAY_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_DMA_ENDIAN_MASK
value|(3<< 21)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_DMA_ENDIAN_NC
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_DMA_ENDIAN_SB
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_DMA_ENDIAN_SW
value|(2<< 21)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_DMA_ENDIAN_SBW
value|(3<< 21)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_BUS_WIDTH_MASK
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_BUS_WIDTH_1
value|(0<< 20)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_BUS_WIDTH_4
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_DATA_NEG_EDGE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_DONT_DELAY_DATA
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_CMD_ARG_BITS_MASK
value|(0x3f<< 12)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_CMD_ARG_BITS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_CMD_POS_EDGE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_CMD_NO_CRC
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_CMD_CLK_DIV_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|AML_MMC_CONFIG_CMD_CLK_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_REG
value|12
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_TIMER_CNT_MASK
value|(0x1fffU<< 19)
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_TIMER_CNT_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_TIMER_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_TIMEOUT_IRQ
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_CMD_DONE_IRQ
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_WR_CRC16_OK
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_RD_CRC16_OK
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_RESP_CRC7_OK
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_CMD_BUSY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_STATUS_CLEAR_IRQ
value|0x10700
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_CONFIG_REG
value|16
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_CONFIG_SOFT_RESET
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AML_MMC_IRQ_CONFIG_CMD_DONE_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_REG
value|20
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_RESP_INDEX_MASK
value|(0xf<< 12)
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_RESP_INDEX_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_RESP_READOUT_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_STREAM_8_MODE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_STREAM_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_PORT_MASK
value|3
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_PORT_A
value|0
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_PORT_B
value|1
end_define

begin_define
define|#
directive|define
name|AML_MMC_MULT_CONFIG_PORT_C
value|2
end_define

begin_define
define|#
directive|define
name|AML_MMC_DMA_ADDR_REG
value|24
end_define

begin_define
define|#
directive|define
name|AML_MMC_EXTENSION_REG
value|28
end_define

begin_define
define|#
directive|define
name|AML_MMC_EXTENSION_NO_CRC16
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AML_MMC_EXTENSION_PKT_SIZE_MASK
value|(0x3fff<< 16)
end_define

begin_define
define|#
directive|define
name|AML_MMC_EXTENSION_PKT_SIZE_SHIFT
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_AMLOGIC_AML8726_MMC_H */
end_comment

end_unit

