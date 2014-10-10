begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CTRL
value|0x0
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CTRL_USE_IDMAC
value|(1<< 25)
end_define

begin_comment
comment|/* Use Internal DMAC */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CTRL_DMA_ENABLE
value|(1<< 5)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CTRL_INT_ENABLE
value|(1<< 4)
end_define

begin_comment
comment|/* Enable interrupts */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CTRL_DMA_RESET
value|(1<< 2)
end_define

begin_comment
comment|/* Reset DMA */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CTRL_FIFO_RESET
value|(1<< 1)
end_define

begin_comment
comment|/* Reset FIFO */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CTRL_RESET
value|(1<< 0)
end_define

begin_comment
comment|/* Reset SD/MMC controller */
end_comment

begin_define
define|#
directive|define
name|SDMMC_PWREN
value|0x4
end_define

begin_comment
comment|/* Power Enable Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_PWREN_PE
value|(1<< 0)
end_define

begin_comment
comment|/* Power On */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CLKDIV
value|0x8
end_define

begin_comment
comment|/* Clock Divider Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CLKSRC
value|0xC
end_define

begin_comment
comment|/* SD Clock Source Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CLKENA
value|0x10
end_define

begin_comment
comment|/* Clock Enable Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CLKENA_LP
value|(1<< 16)
end_define

begin_comment
comment|/* Low-power mode */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CLKENA_CCLK_EN
value|(1<< 0)
end_define

begin_comment
comment|/* SD/MMC Enable */
end_comment

begin_define
define|#
directive|define
name|SDMMC_TMOUT
value|0x14
end_define

begin_comment
comment|/* Timeout Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CTYPE
value|0x18
end_define

begin_comment
comment|/* Card Type Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CTYPE_8BIT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SDMMC_CTYPE_4BIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDMMC_BLKSIZ
value|0x1C
end_define

begin_comment
comment|/* Block Size Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_BYTCNT
value|0x20
end_define

begin_comment
comment|/* Byte Count Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK
value|0x24
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_SDIO
value|(1<< 16)
end_define

begin_comment
comment|/* SDIO Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_EBE
value|(1<< 15)
end_define

begin_comment
comment|/* End-bit error */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_ACD
value|(1<< 14)
end_define

begin_comment
comment|/* Auto command done */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_SBE
value|(1<< 13)
end_define

begin_comment
comment|/* Start-bit error */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_HLE
value|(1<< 12)
end_define

begin_comment
comment|/* Hardware locked write err */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_FRUN
value|(1<< 11)
end_define

begin_comment
comment|/* FIFO underrun/overrun err */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_HTO
value|(1<< 10)
end_define

begin_comment
comment|/* Data starvation by host timeout */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_DRT
value|(1<< 9)
end_define

begin_comment
comment|/* Data read timeout  */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_RTO
value|(1<< 8)
end_define

begin_comment
comment|/* Response timeout */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_DCRC
value|(1<< 7)
end_define

begin_comment
comment|/* Data CRC error */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_RCRC
value|(1<< 6)
end_define

begin_comment
comment|/* Response CRC error */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_RXDR
value|(1<< 5)
end_define

begin_comment
comment|/* Receive FIFO data request */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_TXDR
value|(1<< 4)
end_define

begin_comment
comment|/* Transmit FIFO data request */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_DTO
value|(1<< 3)
end_define

begin_comment
comment|/* Data transfer over */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_CMD_DONE
value|(1<< 2)
end_define

begin_comment
comment|/* Command done */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_RE
value|(1<< 1)
end_define

begin_comment
comment|/* Response error */
end_comment

begin_define
define|#
directive|define
name|SDMMC_INTMASK_CD
value|(1<< 0)
end_define

begin_comment
comment|/* Card Detected */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMDARG
value|0x28
end_define

begin_comment
comment|/* Command Argument Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD
value|0x2C
end_define

begin_comment
comment|/* Command Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_START
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|SDMMC_CMD_USE_HOLD_REG
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SDMMC_CMD_UPD_CLK_ONLY
value|(1<< 21)
end_define

begin_comment
comment|/* Update clk only */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_SEND_INIT
value|(1<< 15)
end_define

begin_comment
comment|/* Send initialization */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_STOP_ABORT
value|(1<< 14)
end_define

begin_comment
comment|/* stop current data transfer */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_WAIT_PRVDATA
value|(1<< 13)
end_define

begin_comment
comment|/* Wait for prev data transfer completion */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_SEND_ASTOP
value|(1<< 12)
end_define

begin_comment
comment|/* Send stop command at end of data tx/rx */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_MODE_STREAM
value|(1<< 11)
end_define

begin_comment
comment|/* Stream data transfer */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_DATA_WRITE
value|(1<< 10)
end_define

begin_comment
comment|/* Write to card */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_DATA_EXP
value|(1<< 9)
end_define

begin_comment
comment|/* Data transfer expected */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_RESP_CRC
value|(1<< 8)
end_define

begin_comment
comment|/* Check Response CRC */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_RESP_LONG
value|(1<< 7)
end_define

begin_comment
comment|/* Long response expected */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CMD_RESP_EXP
value|(1<< 6)
end_define

begin_comment
comment|/* Response expected */
end_comment

begin_define
define|#
directive|define
name|SDMMC_RESP0
value|0x30
end_define

begin_comment
comment|/* Response Register 0 */
end_comment

begin_define
define|#
directive|define
name|SDMMC_RESP1
value|0x34
end_define

begin_comment
comment|/* Response Register 1 */
end_comment

begin_define
define|#
directive|define
name|SDMMC_RESP2
value|0x38
end_define

begin_comment
comment|/* Response Register 2 */
end_comment

begin_define
define|#
directive|define
name|SDMMC_RESP3
value|0x3C
end_define

begin_comment
comment|/* Response Register 3 */
end_comment

begin_define
define|#
directive|define
name|SDMMC_MINTSTS
value|0x40
end_define

begin_comment
comment|/* Masked Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_RINTSTS
value|0x44
end_define

begin_comment
comment|/* Raw Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_STATUS
value|0x48
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_STATUS_DATA_BUSY
value|(1<< 9)
end_define

begin_comment
comment|/* card_data[0] */
end_comment

begin_define
define|#
directive|define
name|SDMMC_FIFOTH
value|0x4C
end_define

begin_comment
comment|/* FIFO Threshold Watermark Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_FIFOTH_MSIZE_S
value|28
end_define

begin_comment
comment|/* Burst size of multiple transaction */
end_comment

begin_define
define|#
directive|define
name|SDMMC_FIFOTH_RXWMARK_S
value|16
end_define

begin_comment
comment|/* FIFO threshold watermark level */
end_comment

begin_define
define|#
directive|define
name|SDMMC_FIFOTH_TXWMARK_S
value|0
end_define

begin_comment
comment|/* FIFO threshold watermark level */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CDETECT
value|0x50
end_define

begin_comment
comment|/* Card Detect Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_WRTPRT
value|0x54
end_define

begin_comment
comment|/* Write Protect Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_TCBCNT
value|0x5C
end_define

begin_comment
comment|/* Transferred CIU Card Byte Count */
end_comment

begin_define
define|#
directive|define
name|SDMMC_TBBCNT
value|0x60
end_define

begin_comment
comment|/* Transferred Host to BIU-FIFO Byte Count */
end_comment

begin_define
define|#
directive|define
name|SDMMC_DEBNCE
value|0x64
end_define

begin_comment
comment|/* Debounce Count Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_USRID
value|0x68
end_define

begin_comment
comment|/* User ID Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_VERID
value|0x6C
end_define

begin_comment
comment|/* Version ID Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_HCON
value|0x70
end_define

begin_comment
comment|/* Hardware Configuration Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_UHS_REG
value|0x74
end_define

begin_comment
comment|/* UHS-1 Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_UHS_REG_DDR
value|(1<< 16)
end_define

begin_comment
comment|/* DDR mode */
end_comment

begin_define
define|#
directive|define
name|SDMMC_RST_N
value|0x78
end_define

begin_comment
comment|/* Hardware Reset Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_BMOD
value|0x80
end_define

begin_comment
comment|/* Bus Mode Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_BMOD_DE
value|(1<< 7)
end_define

begin_comment
comment|/* IDMAC Enable */
end_comment

begin_define
define|#
directive|define
name|SDMMC_BMOD_FB
value|(1<< 1)
end_define

begin_comment
comment|/* AHB Master Fixed Burst */
end_comment

begin_define
define|#
directive|define
name|SDMMC_BMOD_SWR
value|(1<< 0)
end_define

begin_comment
comment|/* Reset DMA */
end_comment

begin_define
define|#
directive|define
name|SDMMC_PLDMND
value|0x84
end_define

begin_comment
comment|/* Poll Demand Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_DBADDR
value|0x88
end_define

begin_comment
comment|/* Descriptor List Base Address */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDSTS
value|0x8C
end_define

begin_comment
comment|/* Internal DMAC Status Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDINTEN
value|0x90
end_define

begin_comment
comment|/* Internal DMAC Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDINTEN_AI
value|(1<< 9)
end_define

begin_comment
comment|/* Abnormal Interrupt Summary */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDINTEN_NI
value|(1<< 8)
end_define

begin_comment
comment|/* Normal Interrupt Summary */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDINTEN_CES
value|(1<< 5)
end_define

begin_comment
comment|/* Card Error Summary */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDINTEN_DU
value|(1<< 4)
end_define

begin_comment
comment|/* Descriptor Unavailable */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDINTEN_FBE
value|(1<< 2)
end_define

begin_comment
comment|/* Fatal Bus Error */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDINTEN_RI
value|(1<< 1)
end_define

begin_comment
comment|/* Receive Interrupt */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDINTEN_TI
value|(1<< 0)
end_define

begin_comment
comment|/* Transmit Interrupt */
end_comment

begin_define
define|#
directive|define
name|SDMMC_IDINTEN_MASK
value|(SDMMC_IDINTEN_AI | SDMMC_IDINTEN_NI | SDMMC_IDINTEN_CES | \ 				 SDMMC_IDINTEN_DU | SDMMC_IDINTEN_FBE | SDMMC_IDINTEN_RI | \ 				 SDMMC_IDINTEN_TI)
end_define

begin_define
define|#
directive|define
name|SDMMC_DSCADDR
value|0x94
end_define

begin_comment
comment|/* Current Host Descriptor Address */
end_comment

begin_define
define|#
directive|define
name|SDMMC_BUFADDR
value|0x98
end_define

begin_comment
comment|/* Current Buffer Descriptor Address */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CARDTHRCTL
value|0x100
end_define

begin_comment
comment|/* Card Threshold Control Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_BACK_END_POWER_R
value|0x104
end_define

begin_comment
comment|/* Back End Power Register */
end_comment

begin_define
define|#
directive|define
name|SDMMC_DATA
value|0x200
end_define

begin_comment
comment|/* Data FIFO Access */
end_comment

begin_comment
comment|/* eMMC */
end_comment

begin_define
define|#
directive|define
name|EMMCP_MPSBEGIN0
value|0x1200
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|EMMCP_SEND0
value|0x1204
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|EMMCP_CTRL0
value|0x120C
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|MPSCTRL_SECURE_READ_BIT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MPSCTRL_SECURE_WRITE_BIT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MPSCTRL_NON_SECURE_READ_BIT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MPSCTRL_NON_SECURE_WRITE_BIT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MPSCTRL_USE_FUSE_KEY
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MPSCTRL_ECB_MODE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MPSCTRL_ENCRYPTION
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MPSCTRL_VALID
value|(1<< 0)
end_define

begin_comment
comment|/* Platform-specific defines */
end_comment

begin_define
define|#
directive|define
name|SDMMC_CLKSEL
value|0x9C
end_define

begin_define
define|#
directive|define
name|SDMMC_CLKSEL_SAMPLE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMMC_CLKSEL_DRIVE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SDMMC_CLKSEL_DIVIDER_SHIFT
value|24
end_define

end_unit

