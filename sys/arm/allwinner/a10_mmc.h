begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Alexander Fedorov<alexander.fedorov@rtlservice.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_A10_MMC_H_
end_ifndef

begin_define
define|#
directive|define
name|_A10_MMC_H_
end_define

begin_define
define|#
directive|define
name|A10_MMC_GCTRL
value|0x00
end_define

begin_comment
comment|/* Global Control Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CLKCR
value|0x04
end_define

begin_comment
comment|/* Clock Control Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_TIMEOUT
value|0x08
end_define

begin_comment
comment|/* Timeout Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_WIDTH
value|0x0C
end_define

begin_comment
comment|/* Bus Width Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_BLKSZ
value|0x10
end_define

begin_comment
comment|/* Block Size Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_BCNTR
value|0x14
end_define

begin_comment
comment|/* Byte Count Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CMDR
value|0x18
end_define

begin_comment
comment|/* Command Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CARG
value|0x1C
end_define

begin_comment
comment|/* Argument Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_RESP0
value|0x20
end_define

begin_comment
comment|/* Response Register 0 */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_RESP1
value|0x24
end_define

begin_comment
comment|/* Response Register 1 */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_RESP2
value|0x28
end_define

begin_comment
comment|/* Response Register 2 */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_RESP3
value|0x2C
end_define

begin_comment
comment|/* Response Register 3 */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_IMASK
value|0x30
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_MISTA
value|0x34
end_define

begin_comment
comment|/* Masked Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_RINTR
value|0x38
end_define

begin_comment
comment|/* Raw Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_STAS
value|0x3C
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_FTRGL
value|0x40
end_define

begin_comment
comment|/* FIFO Threshold Watermark Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_FUNS
value|0x44
end_define

begin_comment
comment|/* Function Select Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CBCR
value|0x48
end_define

begin_comment
comment|/* CIU Byte Count Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_BBCR
value|0x4C
end_define

begin_comment
comment|/* BIU Byte Count Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_DBGC
value|0x50
end_define

begin_comment
comment|/* Debug Enable Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_DMAC
value|0x80
end_define

begin_comment
comment|/* IDMAC Control Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_DLBA
value|0x84
end_define

begin_comment
comment|/* IDMAC Desc List Base Address Reg */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_IDST
value|0x88
end_define

begin_comment
comment|/* IDMAC Status Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_IDIE
value|0x8C
end_define

begin_comment
comment|/* IDMAC Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CHDA
value|0x90
end_define

begin_define
define|#
directive|define
name|A10_MMC_CBDA
value|0x94
end_define

begin_define
define|#
directive|define
name|A10_MMC_FIFO
value|0x100
end_define

begin_comment
comment|/* FIFO Access Address (A10/A20) */
end_comment

begin_define
define|#
directive|define
name|A31_MMC_FIFO
value|0x200
end_define

begin_comment
comment|/* FIFO Access Address (A31) */
end_comment

begin_comment
comment|/* A10_MMC_GCTRL */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_SOFT_RESET
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|A10_MMC_FIFO_RESET
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DMA_RESET
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_ENABLE
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DMA_ENABLE
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DEBOUNCE_ENABLE
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DDR_MODE
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_ACCESS_BY_AHB
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|A10_MMC_RESET
define|\
value|(A10_MMC_SOFT_RESET | A10_MMC_FIFO_RESET | A10_MMC_DMA_RESET)
end_define

begin_comment
comment|/* A10_MMC_CLKCR */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CARD_CLK_ON
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|A10_MMC_LOW_POWER_ON
value|(1U<< 17)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CLKCR_DIV
value|0xff
end_define

begin_comment
comment|/* A10_MMC_WIDTH */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_WIDTH1
value|0
end_define

begin_define
define|#
directive|define
name|A10_MMC_WIDTH4
value|1
end_define

begin_define
define|#
directive|define
name|A10_MMC_WIDTH8
value|2
end_define

begin_comment
comment|/* A10_MMC_CMDR */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_RESP_EXP
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|A10_MMC_LONG_RESP
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CHECK_RESP_CRC
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DATA_EXP
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_WRITE
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_SEQ_MODE
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|A10_MMC_SEND_AUTOSTOP
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|A10_MMC_WAIT_PREOVER
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_STOP_ABORT_CMD
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|A10_MMC_SEND_INIT_SEQ
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|A10_MMC_UPCLK_ONLY
value|(1U<< 21)
end_define

begin_define
define|#
directive|define
name|A10_MMC_RDCEATADEV
value|(1U<< 22)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CCS_EXP
value|(1U<< 23)
end_define

begin_define
define|#
directive|define
name|A10_MMC_ENB_BOOT
value|(1U<< 24)
end_define

begin_define
define|#
directive|define
name|A10_MMC_ALT_BOOT_OPT
value|(1U<< 25)
end_define

begin_define
define|#
directive|define
name|A10_MMC_BOOT_ACK_EXP
value|(1U<< 26)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DISABLE_BOOT
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|A10_MMC_VOL_SWITCH
value|(1U<< 28)
end_define

begin_define
define|#
directive|define
name|A10_MMC_START
value|(1U<< 31)
end_define

begin_comment
comment|/* A10_MMC_IMASK and A10_MMC_RINTR */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_RESP_ERR
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMD_DONE
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DATA_OVER
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|A10_MMC_TX_DATA_REQ
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|A10_MMC_RX_DATA_REQ
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|A10_MMC_RESP_CRC_ERR
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DATA_CRC_ERR
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|A10_MMC_RESP_TIMEOUT
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_ACK_RECV
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DATA_TIMEOUT
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_BOOT_START
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DATA_STARVE
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_VOL_CHG_DONE
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_FIFO_RUN_ERR
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|A10_MMC_HARDW_LOCKED
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|A10_MMC_START_BIT_ERR
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_AUTOCMD_DONE
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|A10_MMC_END_BIT_ERR
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|A10_MMC_SDIO_INT
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CARD_INSERT
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CARD_REMOVE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_ERR_BIT
define|\
value|(A10_MMC_RESP_ERR | A10_MMC_RESP_CRC_ERR |	\ 	 A10_MMC_DATA_CRC_ERR | A10_MMC_RESP_TIMEOUT |	\ 	 A10_MMC_FIFO_RUN_ERR |	A10_MMC_HARDW_LOCKED |	\ 	 A10_MMC_START_BIT_ERR | A10_MMC_END_BIT_ERR)
end_define

begin_comment
comment|/* A10_MMC_STAS */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_RX_WLFLAG
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|A10_MMC_TX_WLFLAG
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_FIFO_EMPTY
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|A10_MMC_FIFO_FULL
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CARD_PRESENT
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CARD_DATA_BUSY
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DATA_FSM_BUSY
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DMA_REQ
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|A10_MMC_FIFO_SIZE
value|16
end_define

begin_comment
comment|/* A10_MMC_FUNS */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CE_ATA_ON
value|(0xceaaU<< 16)
end_define

begin_define
define|#
directive|define
name|A10_MMC_SEND_IRQ_RESP
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|A10_MMC_SDIO_RD_WAIT
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_ABT_RD_DATA
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|A10_MMC_SEND_CC_SD
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_SEND_AUTOSTOP_CC_SD
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CE_ATA_DEV_INT_ENB
value|(1U<< 10)
end_define

begin_comment
comment|/* IDMA CONTROLLER BUS MOD BIT FIELD */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_SOFT_RST
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_FIX_BURST
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_IDMA_ON
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_REFETCH_DES
value|(1U<< 31)
end_define

begin_comment
comment|/* A10_MMC_IDST */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_TRANSMIT_INT
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_RECEIVE_INT
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_FATAL_BUS_ERR
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_DES_INVALID
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_CARD_ERR_SUM
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_NORMAL_INT_SUM
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_ABNORMAL_INT_SUM
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_HOST_ABT_INTX
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_HOST_ABT_INRX
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_IDLE
value|(0U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_SUSPEND
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_DESC_RD
value|(2U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_DESC_CHECK
value|(3U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_RD_REQ_WAIT
value|(4U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_WR_REQ_WAIT
value|(5U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_RD
value|(6U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_WR
value|(7U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_DESC_CLOSE
value|(8U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_ERROR
define|\
value|(A10_MMC_IDMAC_FATAL_BUS_ERR | A10_MMC_IDMAC_CARD_ERR_SUM |	\ 	 A10_MMC_IDMAC_DES_INVALID | A10_MMC_IDMAC_ABNORMAL_INT_SUM)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDMAC_COMPLETE
define|\
value|(A10_MMC_IDMAC_TRANSMIT_INT | A10_MMC_IDMAC_RECEIVE_INT)
end_define

begin_comment
comment|/* The DMA descriptor table. */
end_comment

begin_struct
struct|struct
name|a10_mmc_dma_desc
block|{
name|uint32_t
name|config
decl_stmt|;
define|#
directive|define
name|A10_MMC_DMA_CONFIG_DIC
value|(1U<< 1)
define|#
directive|define
name|A10_MMC_DMA_CONFIG_LD
value|(1U<< 2)
define|#
directive|define
name|A10_MMC_DMA_CONFIG_FD
value|(1U<< 3)
define|#
directive|define
name|A10_MMC_DMA_CONFIG_CH
value|(1U<< 4)
define|#
directive|define
name|A10_MMC_DMA_CONFIG_ER
value|(1U<< 5)
define|#
directive|define
name|A10_MMC_DMA_CONFIG_CES
value|(1U<< 30)
define|#
directive|define
name|A10_MMC_DMA_CONFIG_OWN
value|(1U<< 31)
name|uint32_t
name|buf_size
decl_stmt|;
name|uint32_t
name|buf_addr
decl_stmt|;
name|uint32_t
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _A10_MMC_H_ */
end_comment

end_unit

