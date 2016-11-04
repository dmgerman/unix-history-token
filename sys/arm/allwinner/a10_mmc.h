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
name|A10_MMC_GCTL
value|0x00
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CKCR
value|0x04
end_define

begin_comment
comment|/* Clock Control Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_TMOR
value|0x08
end_define

begin_comment
comment|/* Timeout Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_BWDR
value|0x0C
end_define

begin_comment
comment|/* Bus Width Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_BKSR
value|0x10
end_define

begin_comment
comment|/* Block Size Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_BYCR
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
name|A10_MMC_CAGR
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
name|A10_MMC_IMKR
value|0x30
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_MISR
value|0x34
end_define

begin_comment
comment|/* Masked Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_RISR
value|0x38
end_define

begin_comment
comment|/* Raw Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_STAR
value|0x3C
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_FWLR
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
name|A10_MMC_HWRST
value|0x78
end_define

begin_comment
comment|/* Hardware reset (not documented) */
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
comment|/* A10_MMC_GCTL */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CTRL_SOFT_RST
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CTRL_FIFO_RST
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CTRL_DMA_RST
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CTRL_INT_ENB
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CTRL_DMA_ENB
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CTRL_CD_DBC_ENB
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CTRL_DDR_MOD_SEL
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CTRL_FIFO_AC_MOD
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|A10_MMC_RESET
define|\
value|(A10_MMC_CTRL_SOFT_RST | A10_MMC_CTRL_FIFO_RST | A10_MMC_CTRL_DMA_RST)
end_define

begin_comment
comment|/* A10_MMC_CKCR */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CKCR_CCLK_ENB
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CKCR_CCLK_CTRL
value|(1U<< 17)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CKCR_CCLK_DIV
value|0xff
end_define

begin_comment
comment|/* A10_MMC_TMOR */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_TMOR_RTO_LMT_SHIFT
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_comment
comment|/* Response timeout limit */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_TMOR_RTO_LMT_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|A10_MMC_TMOR_DTO_LMT_SHIFT
parameter_list|(
name|x
parameter_list|)
value|(x<< 8)
end_define

begin_comment
comment|/* Data timeout limit */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_TMOR_DTO_LMT_MASK
value|0xffffff
end_define

begin_comment
comment|/* A10_MMC_BWDR */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_BWDR1
value|0
end_define

begin_define
define|#
directive|define
name|A10_MMC_BWDR4
value|1
end_define

begin_define
define|#
directive|define
name|A10_MMC_BWDR8
value|2
end_define

begin_comment
comment|/* A10_MMC_CMDR */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_CMDR_RESP_RCV
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_LONG_RESP
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_CHK_RESP_CRC
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_DATA_TRANS
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_DIR_WRITE
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_TRANS_MODE_STREAM
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_STOP_CMD_FLAG
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_WAIT_PRE_OVER
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_STOP_ABT_CMD
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_SEND_INIT_SEQ
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_PRG_CLK
value|(1U<< 21)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_RD_CEDATA_DEV
value|(1U<< 22)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_CCS_EXP
value|(1U<< 23)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_BOOT_MOD_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_BOOT_MOD_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_BOOT_MOD_MANDATORY
value|1
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_BOOT_MOD_ALT
value|2
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_EXP_BOOT_ACK
value|(1U<< 26)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_BOOT_ABT
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_VOL_SW
value|(1U<< 28)
end_define

begin_define
define|#
directive|define
name|A10_MMC_CMDR_LOAD
value|(1U<< 31)
end_define

begin_comment
comment|/* A10_MMC_IMKR and A10_MMC_RISR */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_INT_RESP_ERR
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_CMD_DONE
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_DATA_OVER
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_TX_DATA_REQ
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_RX_DATA_REQ
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_RESP_CRC_ERR
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_DATA_CRC_ERR
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_RESP_TIMEOUT
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_BOOT_ACK_RECV
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_DATA_TIMEOUT
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_BOOT_START
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_DATA_STARVE
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_VOL_CHG_DONE
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_FIFO_RUN_ERR
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_CMD_BUSY
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_DATA_START_ERR
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_AUTO_STOP_DONE
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_DATA_END_BIT_ERR
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_SDIO
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_CARD_INSERT
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_CARD_REMOVE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|A10_MMC_INT_ERR_BIT
define|\
value|(A10_MMC_INT_RESP_ERR | A10_MMC_INT_RESP_CRC_ERR |	\ 	 A10_MMC_INT_DATA_CRC_ERR | A10_MMC_INT_RESP_TIMEOUT |	\ 	 A10_MMC_INT_FIFO_RUN_ERR |	A10_MMC_INT_CMD_BUSY |	\ 	 A10_MMC_INT_DATA_START_ERR | A10_MMC_INT_DATA_END_BIT_ERR)
end_define

begin_comment
comment|/* A10_MMC_STAR */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_STAR_FIFO_RX_LEVEL
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|A10_MMC_STAR_FIFO_TX_LEVEL
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_STAR_FIFO_EMPTY
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|A10_MMC_STAR_FIFO_FULL
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|A10_MMC_STAR_CARD_PRESENT
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_STAR_CARD_BUSY
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_STAR_FSM_BUSY
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_STAR_DMA_REQ
value|(1U<< 31)
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
name|A10_MMC_DMAC_IDMAC_SOFT_RST
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DMAC_IDMAC_FIX_BURST
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DMAC_IDMAC_IDMA_ON
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|A10_MMC_DMAC_IDMAC_REFETCH_DES
value|(1U<< 31)
end_define

begin_comment
comment|/* A10_MMC_IDST */
end_comment

begin_define
define|#
directive|define
name|A10_MMC_IDST_TX_INT
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_RX_INT
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_FATAL_BERR_INT
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_DES_UNAVL_INT
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_ERR_FLAG_SUM
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_NOR_INT_SUM
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_ABN_INT_SUM
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_HOST_ABT_INTX
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_HOST_ABT_INRX
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_IDLE
value|(0U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_SUSPEND
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_DESC_RD
value|(2U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_DESC_CHECK
value|(3U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_RD_REQ_WAIT
value|(4U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_WR_REQ_WAIT
value|(5U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_RD
value|(6U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_WR
value|(7U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_DESC_CLOSE
value|(8U<< 13)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_ERROR
define|\
value|(A10_MMC_IDST_FATAL_BERR_INT | A10_MMC_IDST_ERR_FLAG_SUM |	\ 	 A10_MMC_IDST_DES_UNAVL_INT | A10_MMC_IDST_ABN_INT_SUM)
end_define

begin_define
define|#
directive|define
name|A10_MMC_IDST_COMPLETE
define|\
value|(A10_MMC_IDST_TX_INT | A10_MMC_IDST_RX_INT)
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
comment|/* Disable Interrupt Completion */
define|#
directive|define
name|A10_MMC_DMA_CONFIG_LD
value|(1U<< 2)
comment|/* Last DES */
define|#
directive|define
name|A10_MMC_DMA_CONFIG_FD
value|(1U<< 3)
comment|/* First DES */
define|#
directive|define
name|A10_MMC_DMA_CONFIG_CH
value|(1U<< 4)
comment|/* CHAIN MOD */
define|#
directive|define
name|A10_MMC_DMA_CONFIG_ER
value|(1U<< 5)
comment|/* End of Ring (undocumented register) */
define|#
directive|define
name|A10_MMC_DMA_CONFIG_CES
value|(1U<< 30)
comment|/* Card Error Summary */
define|#
directive|define
name|A10_MMC_DMA_CONFIG_OWN
value|(1U<< 31)
comment|/* DES Own Flag */
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

begin_define
define|#
directive|define
name|A10_MMC_DMA_ALIGN
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _A10_MMC_H_ */
end_comment

end_unit

