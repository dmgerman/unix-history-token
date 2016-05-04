begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2015 John Wehle<john@feith.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_AMLOGIC_AML8726_SDXC_M8_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_AMLOGIC_AML8726_SDXC_M8_H
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ALIGN_DMA
value|4
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MAX_DMA
value|4096
end_define

begin_comment
comment|/*  * Timeouts are in milliseconds  *  * Read and write are per section 4.6.2 of the:  *  *   SD Specifications Part 1  *   Physical Layer Simplified Specification  *   Version 4.10  */
end_comment

begin_define
define|#
directive|define
name|AML_SDXC_CMD_TIMEOUT
value|50
end_define

begin_define
define|#
directive|define
name|AML_SDXC_READ_TIMEOUT
value|100
end_define

begin_define
define|#
directive|define
name|AML_SDXC_WRITE_TIMEOUT
value|500
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MAX_TIMEOUT
value|5000
end_define

begin_define
define|#
directive|define
name|AML_SDXC_BUSY_POLL_INTVL
value|1
end_define

begin_define
define|#
directive|define
name|AML_SDXC_BUSY_TIMEOUT
value|1000
end_define

begin_comment
comment|/*  * There's some disagreements between the S805 documentation  * and the Amlogic Linux platform code regarding the exact  * layout of various registers ... when in doubt we follow  * the platform code.  */
end_comment

begin_define
define|#
directive|define
name|AML_SDXC_CMD_ARGUMENT_REG
value|0
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_REG
value|4
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_REP_PKG_CNT_MASK
value|(0xffffU<< 16)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_REP_PKG_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_DATA_STOP
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_DATA_WRITE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_RESP_NO_CRC7_CHECK
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_RESP_136
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_CMD_HAS_DATA
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_CMD_HAS_RESP
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_INDEX_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SEND_INDEX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_REG
value|8
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_TX_ENDIAN_MASK
value|(7<< 29)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_TX_ENDIAN_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_RX_ENDIAN_MASK
value|(7<< 24)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_RX_ENDIAN_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_RX_PERIOD_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_RX_TIMEOUT_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_PKG_LEN_MASK
value|(0x1ff<< 4)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_PKG_LEN_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_BUS_WIDTH_MASK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_BUS_WIDTH_1
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_BUS_WIDTH_4
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CNTRL_BUS_WIDTH_8
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_REG
value|12
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_TX_CNT_MASK
value|(0x7f<< 13)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_TX_CNT_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_RX_CNT_MASK
value|(0x7f<< 6)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_RX_CNT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_CMD
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_DAT3
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_DAT2
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_DAT1
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_DAT0
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_STATUS_BUSY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_REG
value|16
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_MEM_PWR_MASK
value|(3<< 25)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_MEM_PWR_OFF
value|(3<< 25)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_MEM_PWR_ON
value|(0<< 25)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_CLK_SEL_MASK
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_CLK_SEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_CLK_MODULE_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_SD_CLK_EN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_RX_CLK_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_TX_CLK_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_CLK_DIV_MASK
value|0x0fff
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK_CNTRL_CLK_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_SDXC_DMA_ADDR_REG
value|20
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_REG
value|24
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_TX_FILL
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_RX_FLUSH_NOW
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_RX_FLUSH_MODE_SW
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_TX_THOLD_MASK
value|(0x3f<< 22)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_TX_THOLD_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_RX_THOLD_MASK
value|(0x3f<< 15)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_RX_THOLD_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_RD_BURST_MASK
value|(0x1f<< 10)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_RD_BURST_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_WR_BURST_MASK
value|(0x1f<< 5)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_WR_BURST_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_DMA_URGENT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_RESP_INDEX_MASK
value|(7<< 1)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_RESP_INDEX_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|AML_SDXC_PDMA_DMA_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MISC_REG
value|28
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MISC_TXSTART_THOLD_MASK
value|(7U<< 29)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MISC_TXSTART_THOLD_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MISC_MANUAL_STOP_MODE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MISC_WCRC_OK_PAT_MASK
value|(7<< 7)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MISC_WCRC_OK_PAT_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MISC_WCRC_ERR_PAT_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_MISC_WCRC_ERR_PAT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|AML_SDXC_DATA_REG
value|32
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_REG
value|36
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_TX_FIFO_EMPTY
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_RX_FIFO_FULL
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_DMA_DONE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_TRANSFER_DONE_OK
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_A_PKG_CRC_ERR
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_A_PKG_TIMEOUT_ERR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_A_PKG_DONE_OK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_RESP_CRC_ERR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_RESP_TIMEOUT_ERR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_RESP_OK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_ENABLE_STANDARD
define|\
value|(AML_SDXC_IRQ_ENABLE_TX_FIFO_EMPTY |		\     AML_SDXC_IRQ_ENABLE_RX_FIFO_FULL |			\     AML_SDXC_IRQ_ENABLE_A_PKG_CRC_ERR |			\     AML_SDXC_IRQ_ENABLE_A_PKG_TIMEOUT_ERR |		\     AML_SDXC_IRQ_ENABLE_RESP_CRC_ERR |			\     AML_SDXC_IRQ_ENABLE_RESP_TIMEOUT_ERR |		\     AML_SDXC_IRQ_ENABLE_RESP_OK)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_REG
value|40
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_TX_FIFO_EMPTY
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_RX_FIFO_FULL
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_DMA_DONE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_TRANSFER_DONE_OK
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_A_PKG_CRC_ERR
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_A_PKG_TIMEOUT_ERR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_A_PKG_DONE_OK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_RESP_CRC_ERR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_RESP_TIMEOUT_ERR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_RESP_OK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_IRQ_STATUS_CLEAR
define|\
value|(AML_SDXC_IRQ_STATUS_TX_FIFO_EMPTY |		\     AML_SDXC_IRQ_STATUS_RX_FIFO_FULL |			\     AML_SDXC_IRQ_STATUS_DMA_DONE |			\     AML_SDXC_IRQ_STATUS_TRANSFER_DONE_OK |		\     AML_SDXC_IRQ_STATUS_A_PKG_CRC_ERR |			\     AML_SDXC_IRQ_STATUS_A_PKG_TIMEOUT_ERR |		\     AML_SDXC_IRQ_STATUS_RESP_CRC_ERR |			\     AML_SDXC_IRQ_STATUS_RESP_TIMEOUT_ERR |		\     AML_SDXC_IRQ_STATUS_RESP_OK)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SOFT_RESET_REG
value|44
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SOFT_RESET_DMA
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SOFT_RESET_TX_PHY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SOFT_RESET_RX_PHY
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SOFT_RESET_TX_FIFO
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SOFT_RESET_RX_FIFO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SOFT_RESET_MAIN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_SOFT_RESET
define|\
value|(AML_SDXC_SOFT_RESET_DMA |				\     AML_SDXC_SOFT_RESET_TX_FIFO |			\     AML_SDXC_SOFT_RESET_RX_FIFO |			\     AML_SDXC_SOFT_RESET_MAIN)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_REG
value|52
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_TX_EMPTY_THOLD_MASK
value|(0x7f<< 25)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_TX_EMPTY_THOLD_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_RX_FULL_THOLD_MASK
value|(0x7f<< 18)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_RX_FULL_THOLD_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_SDIO_IRQ_PERIOD_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_SDIO_IRQ_PERIOD_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_DMA_NO_WR_RESP_CHECK_M8
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_DMA_NO_RD_RESP_CHECK_M8
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_RX_TIMEOUT_MASK_M8
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_RX_TIMEOUT_SHIFT_M8
value|0
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_NO_DMA_CHECK_M8M2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_NO_WR_RESP_CHECK_M8M2
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_ENH_CNTRL_WR_RESP_MODE_SKIP_M8M2
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK2_REG
value|56
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK2_SD_PHASE_MASK
value|(0x3ff<< 12)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK2_SD_PHASE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK2_RX_PHASE_MASK
value|(0x3ff<< 0)
end_define

begin_define
define|#
directive|define
name|AML_SDXC_CLK2_RX_PHASE_SHIFT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_AMLOGIC_AML8726_SDXC_M8_H */
end_comment

end_unit

