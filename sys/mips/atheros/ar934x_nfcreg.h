begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Adrian Chadd<adrian@FreeBSD.org>.  *  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register definitions for the built-in NAND controller  * of the Atheros AR934x and QCA955x SoCs.  *  * This file is based on the AR934x SoC driver from OpenWRT.  *  * Copyright (C) 2011-2013 Gabor Juhos<juhosg@openwrt.org>  *  * Used with permission.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR934X_NFCREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR934X_NFCREG_H__
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_CMD
value|0x00
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_INT_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_INT_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_ECC_CTRL
value|0x14
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_ECC_OFFSET
value|0x18
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_ADDR0_0
value|0x1c
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_ADDR0_1
value|0x24
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_ADDR1_0
value|0x20
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_ADDR1_1
value|0x28
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_SPARE_SIZE
value|0x30
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_PROTECT
value|0x38
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_LOOKUP_EN
value|0x40
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_LOOKUP
parameter_list|(
name|_x
parameter_list|)
value|(0x44 + (_i) * 4)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_DMA_ADDR
value|0x64
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_DMA_COUNT
value|0x68
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_DMA_CTRL
value|0x6c
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_MEM_CTRL
value|0x80
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_DATA_SIZE
value|0x84
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_READ_STATUS
value|0x88
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_TIME_SEQ
value|0x8c
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_TIMINGS_ASYN
value|0x90
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_TIMINGS_SYN
value|0x94
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_FIFO_DATA
value|0x98
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_TIME_MODE
value|0x9c
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_DMA_ADDR_OFFS
value|0xa0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_FIFO_INIT
value|0xb0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_REG_GEN_SEQ_CTRL
value|0xb4
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_CMD_SEQ_S
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_CMD_SEQ_M
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_SEQ_1C
value|0x00
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_SEQ_ERASE
value|0x0e
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_SEQ_12
value|0x0c
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_SEQ_1C1AXR
value|0x21
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_SEQ_S
value|0x24
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_SEQ_1C3AXR
value|0x27
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_SEQ_1C5A1CXR
value|0x2a
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_SEQ_18
value|0x32
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_INPUT_SEL_SIU
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_INPUT_SEL_DMA
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_ADDR_SEL_0
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_ADDR_SEL_1
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_CMD0_S
value|8
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_CMD0_M
value|0xff
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_CMD1_S
value|16
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_CMD1_M
value|0xff
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_CMD2_S
value|24
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CMD_CMD2_M
value|0xff
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_ADDR_CYCLE0_M
value|0x7
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_ADDR_CYCLE0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_SPARE_EN
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_INT_EN
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_ECC_EN
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_BLOCK_SIZE_S
value|6
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_BLOCK_SIZE_M
value|0x3
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_BLOCK_SIZE_32
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_BLOCK_SIZE_64
value|1
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_BLOCK_SIZE_128
value|2
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_BLOCK_SIZE_256
value|3
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PAGE_SIZE_S
value|8
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PAGE_SIZE_M
value|0x7
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PAGE_SIZE_256
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PAGE_SIZE_512
value|1
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PAGE_SIZE_1024
value|2
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PAGE_SIZE_2048
value|3
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PAGE_SIZE_4096
value|4
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PAGE_SIZE_8192
value|5
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PAGE_SIZE_16384
value|6
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_CUSTOM_SIZE_EN
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_IO_WIDTH_8BITS
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_IO_WIDTH_16BITS
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_LOOKUP_EN
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_PROT_EN
value|BIT(14)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_WORK_MODE_ASYNC
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_WORK_MODE_SYNC
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_ADDR0_AUTO_INC
value|BIT(16)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_ADDR1_AUTO_INC
value|BIT(17)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_ADDR_CYCLE1_M
value|0x7
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_ADDR_CYCLE1_S
value|18
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_CTRL_SMALL_PAGE
value|BIT(21)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_START
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_DIR_WRITE
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_DIR_READ
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_MODE_SG
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_BURST_S
value|2
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_BURST_0
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_BURST_1
value|1
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_BURST_2
value|2
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_BURST_3
value|3
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_BURST_4
value|4
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_BURST_5
value|5
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_ERR_FLAG
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_CTRL_DMA_READY
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_INT_DEV_RDY
parameter_list|(
name|_x
parameter_list|)
value|BIT(4 + (_x))
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_INT_CMD_END
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ERR_THRES_S
value|8
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ERR_THRES_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_S
value|5
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_M
value|0x7
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_2
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_4
value|1
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_6
value|2
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_8
value|3
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_10
value|4
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_12
value|5
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_14
value|6
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ECC_CAP_16
value|7
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ERR_OVER
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ERR_UNCORRECT
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_CTRL_ERR_CORRECT
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ECC_OFFS_OFSET_M
value|0xffff
end_define

begin_comment
comment|/* default timing values */
end_comment

begin_define
define|#
directive|define
name|AR934X_NFC_TIME_SEQ_DEFAULT
value|0x7fff
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_TIMINGS_ASYN_DEFAULT
value|0x22
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_TIMINGS_SYN_DEFAULT
value|0xf
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_ID_BUF_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DEV_READY_TIMEOUT
value|25
end_define

begin_comment
comment|/* msecs */
end_comment

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_READY_TIMEOUT
value|25
end_define

begin_comment
comment|/* msecs */
end_comment

begin_define
define|#
directive|define
name|AR934X_NFC_DONE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_DMA_RETRIES
value|20
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_IRQ_MASK
value|AR934X_NFC_INT_DEV_RDY(0)
end_define

begin_define
define|#
directive|define
name|AR934X_NFC_GENSEQ_SMALL_PAGE_READ
value|0x30043
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR934X_NFCREG_H__ */
end_comment

end_unit

