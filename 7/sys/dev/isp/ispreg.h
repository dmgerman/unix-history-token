begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  *  Copyright (c) 1997-2007 by Matthew Jacob  *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *   *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *   *  THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *  SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Machine Independent (well, as best as possible) register  * definitions for Qlogic ISP SCSI adapters.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISPREG_H
end_ifndef

begin_define
define|#
directive|define
name|_ISPREG_H
end_define

begin_comment
comment|/*  * Hardware definitions for the Qlogic ISP  registers.  */
end_comment

begin_comment
comment|/*  * This defines types of access to various registers.  *  *  	R:		Read Only  *	W:		Write Only  *	RW:		Read/Write  *  *	R*, W*, RW*:	Read Only, Write Only, Read/Write, but only  *			if RISC processor in ISP is paused.  */
end_comment

begin_comment
comment|/*  * Offsets for various register blocks.  *  * Sad but true, different architectures have different offsets.  *  * Don't be alarmed if none of this makes sense. The original register  * layout set some defines in a certain pattern. Everything else has been  * grafted on since. For example, the ISP1080 manual will state that DMA  * registers start at 0x80 from the base of the register address space.  * That's true, but for our purposes, we define DMA_REGS_OFF for the 1080  * to start at offset 0x60 because the DMA registers are all defined to  * be DMA_BLOCK+0x20 and so on. Clear?  */
end_comment

begin_define
define|#
directive|define
name|BIU_REGS_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_MBOX_REGS_OFF
value|0x70
end_define

begin_define
define|#
directive|define
name|PCI_MBOX_REGS2100_OFF
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_MBOX_REGS2300_OFF
value|0x40
end_define

begin_define
define|#
directive|define
name|PCI_MBOX_REGS2400_OFF
value|0x80
end_define

begin_define
define|#
directive|define
name|SBUS_MBOX_REGS_OFF
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_SXP_REGS_OFF
value|0x80
end_define

begin_define
define|#
directive|define
name|SBUS_SXP_REGS_OFF
value|0x200
end_define

begin_define
define|#
directive|define
name|PCI_RISC_REGS_OFF
value|0x80
end_define

begin_define
define|#
directive|define
name|SBUS_RISC_REGS_OFF
value|0x400
end_define

begin_comment
comment|/* Bless me! Chip designers have putzed it again! */
end_comment

begin_define
define|#
directive|define
name|ISP1080_DMA_REGS_OFF
value|0x60
end_define

begin_define
define|#
directive|define
name|DMA_REGS_OFF
value|0x00
end_define

begin_comment
comment|/* same as BIU block */
end_comment

begin_define
define|#
directive|define
name|SBUS_REGSIZE
value|0x450
end_define

begin_define
define|#
directive|define
name|PCI_REGSIZE
value|0x100
end_define

begin_comment
comment|/*  * NB:	The *_BLOCK definitions have no specific hardware meaning.  *	They serve simply to note to the MD layer which block of  *	registers offsets are being accessed.  */
end_comment

begin_define
define|#
directive|define
name|_NREG_BLKS
value|5
end_define

begin_define
define|#
directive|define
name|_BLK_REG_SHFT
value|13
end_define

begin_define
define|#
directive|define
name|_BLK_REG_MASK
value|(7<< _BLK_REG_SHFT)
end_define

begin_define
define|#
directive|define
name|BIU_BLOCK
value|(0<< _BLK_REG_SHFT)
end_define

begin_define
define|#
directive|define
name|MBOX_BLOCK
value|(1<< _BLK_REG_SHFT)
end_define

begin_define
define|#
directive|define
name|SXP_BLOCK
value|(2<< _BLK_REG_SHFT)
end_define

begin_define
define|#
directive|define
name|RISC_BLOCK
value|(3<< _BLK_REG_SHFT)
end_define

begin_define
define|#
directive|define
name|DMA_BLOCK
value|(4<< _BLK_REG_SHFT)
end_define

begin_comment
comment|/*  * Bus Interface Block Register Offsets  */
end_comment

begin_define
define|#
directive|define
name|BIU_ID_LO
value|(BIU_BLOCK+0x0)
end_define

begin_comment
comment|/* R  : Bus ID, Low */
end_comment

begin_define
define|#
directive|define
name|BIU2100_FLASH_ADDR
value|(BIU_BLOCK+0x0)
end_define

begin_define
define|#
directive|define
name|BIU_ID_HI
value|(BIU_BLOCK+0x2)
end_define

begin_comment
comment|/* R  : Bus ID, High */
end_comment

begin_define
define|#
directive|define
name|BIU2100_FLASH_DATA
value|(BIU_BLOCK+0x2)
end_define

begin_define
define|#
directive|define
name|BIU_CONF0
value|(BIU_BLOCK+0x4)
end_define

begin_comment
comment|/* R  : Bus Configuration #0 */
end_comment

begin_define
define|#
directive|define
name|BIU_CONF1
value|(BIU_BLOCK+0x6)
end_define

begin_comment
comment|/* R  : Bus Configuration #1 */
end_comment

begin_define
define|#
directive|define
name|BIU2100_CSR
value|(BIU_BLOCK+0x6)
end_define

begin_define
define|#
directive|define
name|BIU_ICR
value|(BIU_BLOCK+0x8)
end_define

begin_comment
comment|/* RW : Bus Interface Ctrl */
end_comment

begin_define
define|#
directive|define
name|BIU_ISR
value|(BIU_BLOCK+0xA)
end_define

begin_comment
comment|/* R  : Bus Interface Status */
end_comment

begin_define
define|#
directive|define
name|BIU_SEMA
value|(BIU_BLOCK+0xC)
end_define

begin_comment
comment|/* RW : Bus Semaphore */
end_comment

begin_define
define|#
directive|define
name|BIU_NVRAM
value|(BIU_BLOCK+0xE)
end_define

begin_comment
comment|/* RW : Bus NVRAM */
end_comment

begin_comment
comment|/*  * These are specific to the 2300.  */
end_comment

begin_define
define|#
directive|define
name|BIU_REQINP
value|(BIU_BLOCK+0x10)
end_define

begin_comment
comment|/* Request Queue In */
end_comment

begin_define
define|#
directive|define
name|BIU_REQOUTP
value|(BIU_BLOCK+0x12)
end_define

begin_comment
comment|/* Request Queue Out */
end_comment

begin_define
define|#
directive|define
name|BIU_RSPINP
value|(BIU_BLOCK+0x14)
end_define

begin_comment
comment|/* Response Queue In */
end_comment

begin_define
define|#
directive|define
name|BIU_RSPOUTP
value|(BIU_BLOCK+0x16)
end_define

begin_comment
comment|/* Response Queue Out */
end_comment

begin_define
define|#
directive|define
name|BIU_R2HSTSLO
value|(BIU_BLOCK+0x18)
end_define

begin_define
define|#
directive|define
name|BIU_R2HSTSHI
value|(BIU_BLOCK+0x1A)
end_define

begin_define
define|#
directive|define
name|BIU_R2HST_INTR
value|(1<< 15)
end_define

begin_comment
comment|/* RISC to Host Interrupt */
end_comment

begin_define
define|#
directive|define
name|BIU_R2HST_PAUSED
value|(1<<  8)
end_define

begin_comment
comment|/* RISC paused */
end_comment

begin_define
define|#
directive|define
name|BIU_R2HST_ISTAT_MASK
value|0x3f
end_define

begin_comment
comment|/* intr information&& status */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_ROM_MBX_OK
value|0x1
end_define

begin_comment
comment|/* ROM mailbox cmd done ok */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_ROM_MBX_FAIL
value|0x2
end_define

begin_comment
comment|/* ROM mailbox cmd done fail */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_MBX_OK
value|0x10
end_define

begin_comment
comment|/* mailbox cmd done ok */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_MBX_FAIL
value|0x11
end_define

begin_comment
comment|/* mailbox cmd done fail */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_ASYNC_EVENT
value|0x12
end_define

begin_comment
comment|/* Async Event */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_RSPQ_UPDATE
value|0x13
end_define

begin_comment
comment|/* Response Queue Update */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_RQST_UPDATE
value|0x14
end_define

begin_comment
comment|/* Resquest Queue Update */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_RIO_16
value|0x15
end_define

begin_comment
comment|/* RIO 1-16 */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_FPOST
value|0x16
end_define

begin_comment
comment|/* Low 16 bits fast post */
end_comment

begin_define
define|#
directive|define
name|ISPR2HST_FPOST_CTIO
value|0x17
end_define

begin_comment
comment|/* Low 16 bits fast post ctio */
end_comment

begin_comment
comment|/* fifo command stuff- mostly for SPI */
end_comment

begin_define
define|#
directive|define
name|DFIFO_COMMAND
value|(BIU_BLOCK+0x60)
end_define

begin_comment
comment|/* RW : Command FIFO Port */
end_comment

begin_define
define|#
directive|define
name|RDMA2100_CONTROL
value|DFIFO_COMMAND
end_define

begin_define
define|#
directive|define
name|DFIFO_DATA
value|(BIU_BLOCK+0x62)
end_define

begin_comment
comment|/* RW : Data FIFO Port */
end_comment

begin_comment
comment|/*  * Putzed DMA register layouts.  */
end_comment

begin_define
define|#
directive|define
name|CDMA_CONF
value|(DMA_BLOCK+0x20)
end_define

begin_comment
comment|/* RW*: DMA Configuration */
end_comment

begin_define
define|#
directive|define
name|CDMA2100_CONTROL
value|CDMA_CONF
end_define

begin_define
define|#
directive|define
name|CDMA_CONTROL
value|(DMA_BLOCK+0x22)
end_define

begin_comment
comment|/* RW*: DMA Control */
end_comment

begin_define
define|#
directive|define
name|CDMA_STATUS
value|(DMA_BLOCK+0x24)
end_define

begin_comment
comment|/* R  : DMA Status */
end_comment

begin_define
define|#
directive|define
name|CDMA_FIFO_STS
value|(DMA_BLOCK+0x26)
end_define

begin_comment
comment|/* R  : DMA FIFO Status */
end_comment

begin_define
define|#
directive|define
name|CDMA_COUNT
value|(DMA_BLOCK+0x28)
end_define

begin_comment
comment|/* RW*: DMA Transfer Count */
end_comment

begin_define
define|#
directive|define
name|CDMA_ADDR0
value|(DMA_BLOCK+0x2C)
end_define

begin_comment
comment|/* RW*: DMA Address, Word 0 */
end_comment

begin_define
define|#
directive|define
name|CDMA_ADDR1
value|(DMA_BLOCK+0x2E)
end_define

begin_comment
comment|/* RW*: DMA Address, Word 1 */
end_comment

begin_define
define|#
directive|define
name|CDMA_ADDR2
value|(DMA_BLOCK+0x30)
end_define

begin_comment
comment|/* RW*: DMA Address, Word 2 */
end_comment

begin_define
define|#
directive|define
name|CDMA_ADDR3
value|(DMA_BLOCK+0x32)
end_define

begin_comment
comment|/* RW*: DMA Address, Word 3 */
end_comment

begin_define
define|#
directive|define
name|DDMA_CONF
value|(DMA_BLOCK+0x40)
end_define

begin_comment
comment|/* RW*: DMA Configuration */
end_comment

begin_define
define|#
directive|define
name|TDMA2100_CONTROL
value|DDMA_CONF
end_define

begin_define
define|#
directive|define
name|DDMA_CONTROL
value|(DMA_BLOCK+0x42)
end_define

begin_comment
comment|/* RW*: DMA Control */
end_comment

begin_define
define|#
directive|define
name|DDMA_STATUS
value|(DMA_BLOCK+0x44)
end_define

begin_comment
comment|/* R  : DMA Status */
end_comment

begin_define
define|#
directive|define
name|DDMA_FIFO_STS
value|(DMA_BLOCK+0x46)
end_define

begin_comment
comment|/* R  : DMA FIFO Status */
end_comment

begin_define
define|#
directive|define
name|DDMA_COUNT_LO
value|(DMA_BLOCK+0x48)
end_define

begin_comment
comment|/* RW*: DMA Xfer Count, Low */
end_comment

begin_define
define|#
directive|define
name|DDMA_COUNT_HI
value|(DMA_BLOCK+0x4A)
end_define

begin_comment
comment|/* RW*: DMA Xfer Count, High */
end_comment

begin_define
define|#
directive|define
name|DDMA_ADDR0
value|(DMA_BLOCK+0x4C)
end_define

begin_comment
comment|/* RW*: DMA Address, Word 0 */
end_comment

begin_define
define|#
directive|define
name|DDMA_ADDR1
value|(DMA_BLOCK+0x4E)
end_define

begin_comment
comment|/* RW*: DMA Address, Word 1 */
end_comment

begin_comment
comment|/* these are for the 1040A cards */
end_comment

begin_define
define|#
directive|define
name|DDMA_ADDR2
value|(DMA_BLOCK+0x50)
end_define

begin_comment
comment|/* RW*: DMA Address, Word 2 */
end_comment

begin_define
define|#
directive|define
name|DDMA_ADDR3
value|(DMA_BLOCK+0x52)
end_define

begin_comment
comment|/* RW*: DMA Address, Word 3 */
end_comment

begin_comment
comment|/*  * Bus Interface Block Register Definitions  */
end_comment

begin_comment
comment|/* BUS CONFIGURATION REGISTER #0 */
end_comment

begin_define
define|#
directive|define
name|BIU_CONF0_HW_MASK
value|0x000F
end_define

begin_comment
comment|/* Hardware revision mask */
end_comment

begin_comment
comment|/* BUS CONFIGURATION REGISTER #1 */
end_comment

begin_define
define|#
directive|define
name|BIU_SBUS_CONF1_PARITY
value|0x0100
end_define

begin_comment
comment|/* Enable parity checking */
end_comment

begin_define
define|#
directive|define
name|BIU_SBUS_CONF1_FCODE_MASK
value|0x00F0
end_define

begin_comment
comment|/* Fcode cycle mask */
end_comment

begin_define
define|#
directive|define
name|BIU_PCI_CONF1_FIFO_128
value|0x0040
end_define

begin_comment
comment|/* 128 bytes FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|BIU_PCI_CONF1_FIFO_64
value|0x0030
end_define

begin_comment
comment|/* 64 bytes FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|BIU_PCI_CONF1_FIFO_32
value|0x0020
end_define

begin_comment
comment|/* 32 bytes FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|BIU_PCI_CONF1_FIFO_16
value|0x0010
end_define

begin_comment
comment|/* 16 bytes FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|BIU_BURST_ENABLE
value|0x0004
end_define

begin_comment
comment|/* Global enable Bus bursts */
end_comment

begin_define
define|#
directive|define
name|BIU_SBUS_CONF1_FIFO_64
value|0x0003
end_define

begin_comment
comment|/* 64 bytes FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|BIU_SBUS_CONF1_FIFO_32
value|0x0002
end_define

begin_comment
comment|/* 32 bytes FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|BIU_SBUS_CONF1_FIFO_16
value|0x0001
end_define

begin_comment
comment|/* 16 bytes FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|BIU_SBUS_CONF1_FIFO_8
value|0x0000
end_define

begin_comment
comment|/* 8 bytes FIFO threshold */
end_comment

begin_define
define|#
directive|define
name|BIU_SBUS_CONF1_BURST8
value|0x0008
end_define

begin_comment
comment|/* Enable 8-byte  bursts */
end_comment

begin_define
define|#
directive|define
name|BIU_PCI_CONF1_SXP
value|0x0008
end_define

begin_comment
comment|/* SXP register select */
end_comment

begin_define
define|#
directive|define
name|BIU_PCI1080_CONF1_SXP0
value|0x0100
end_define

begin_comment
comment|/* SXP bank #1 select */
end_comment

begin_define
define|#
directive|define
name|BIU_PCI1080_CONF1_SXP1
value|0x0200
end_define

begin_comment
comment|/* SXP bank #2 select */
end_comment

begin_define
define|#
directive|define
name|BIU_PCI1080_CONF1_DMA
value|0x0300
end_define

begin_comment
comment|/* DMA bank select */
end_comment

begin_comment
comment|/* ISP2100 Bus Control/Status Register */
end_comment

begin_define
define|#
directive|define
name|BIU2100_ICSR_REGBSEL
value|0x30
end_define

begin_comment
comment|/* RW: register bank select */
end_comment

begin_define
define|#
directive|define
name|BIU2100_RISC_REGS
value|(0<< 4)
end_define

begin_comment
comment|/* RISC Regs */
end_comment

begin_define
define|#
directive|define
name|BIU2100_FB_REGS
value|(1<< 4)
end_define

begin_comment
comment|/* FrameBuffer Regs */
end_comment

begin_define
define|#
directive|define
name|BIU2100_FPM0_REGS
value|(2<< 4)
end_define

begin_comment
comment|/* FPM 0 Regs */
end_comment

begin_define
define|#
directive|define
name|BIU2100_FPM1_REGS
value|(3<< 4)
end_define

begin_comment
comment|/* FPM 1 Regs */
end_comment

begin_define
define|#
directive|define
name|BIU2100_NVRAM_OFFSET
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|BIU2100_FLASH_UPPER_64K
value|0x04
end_define

begin_comment
comment|/* RW: Upper 64K Bank Select */
end_comment

begin_define
define|#
directive|define
name|BIU2100_FLASH_ENABLE
value|0x02
end_define

begin_comment
comment|/* RW: Enable Flash RAM */
end_comment

begin_define
define|#
directive|define
name|BIU2100_SOFT_RESET
value|0x01
end_define

begin_comment
comment|/* SOFT RESET FOR ISP2100 is same bit, but in this register, not ICR */
end_comment

begin_comment
comment|/* BUS CONTROL REGISTER */
end_comment

begin_define
define|#
directive|define
name|BIU_ICR_ENABLE_DMA_INT
value|0x0020
end_define

begin_comment
comment|/* Enable DMA interrupts */
end_comment

begin_define
define|#
directive|define
name|BIU_ICR_ENABLE_CDMA_INT
value|0x0010
end_define

begin_comment
comment|/* Enable CDMA interrupts */
end_comment

begin_define
define|#
directive|define
name|BIU_ICR_ENABLE_SXP_INT
value|0x0008
end_define

begin_comment
comment|/* Enable SXP interrupts */
end_comment

begin_define
define|#
directive|define
name|BIU_ICR_ENABLE_RISC_INT
value|0x0004
end_define

begin_comment
comment|/* Enable Risc interrupts */
end_comment

begin_define
define|#
directive|define
name|BIU_ICR_ENABLE_ALL_INTS
value|0x0002
end_define

begin_comment
comment|/* Global enable all inter */
end_comment

begin_define
define|#
directive|define
name|BIU_ICR_SOFT_RESET
value|0x0001
end_define

begin_comment
comment|/* Soft Reset of ISP */
end_comment

begin_define
define|#
directive|define
name|BIU_IMASK
value|(BIU_ICR_ENABLE_RISC_INT|BIU_ICR_ENABLE_ALL_INTS)
end_define

begin_define
define|#
directive|define
name|BIU2100_ICR_ENABLE_ALL_INTS
value|0x8000
end_define

begin_define
define|#
directive|define
name|BIU2100_ICR_ENA_FPM_INT
value|0x0020
end_define

begin_define
define|#
directive|define
name|BIU2100_ICR_ENA_FB_INT
value|0x0010
end_define

begin_define
define|#
directive|define
name|BIU2100_ICR_ENA_RISC_INT
value|0x0008
end_define

begin_define
define|#
directive|define
name|BIU2100_ICR_ENA_CDMA_INT
value|0x0004
end_define

begin_define
define|#
directive|define
name|BIU2100_ICR_ENABLE_RXDMA_INT
value|0x0002
end_define

begin_define
define|#
directive|define
name|BIU2100_ICR_ENABLE_TXDMA_INT
value|0x0001
end_define

begin_define
define|#
directive|define
name|BIU2100_ICR_DISABLE_ALL_INTS
value|0x0000
end_define

begin_define
define|#
directive|define
name|BIU2100_IMASK
value|(BIU2100_ICR_ENA_RISC_INT|BIU2100_ICR_ENABLE_ALL_INTS)
end_define

begin_comment
comment|/* BUS STATUS REGISTER */
end_comment

begin_define
define|#
directive|define
name|BIU_ISR_DMA_INT
value|0x0020
end_define

begin_comment
comment|/* DMA interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU_ISR_CDMA_INT
value|0x0010
end_define

begin_comment
comment|/* CDMA interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU_ISR_SXP_INT
value|0x0008
end_define

begin_comment
comment|/* SXP interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU_ISR_RISC_INT
value|0x0004
end_define

begin_comment
comment|/* Risc interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU_ISR_IPEND
value|0x0002
end_define

begin_comment
comment|/* Global interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU2100_ISR_INT_PENDING
value|0x8000
end_define

begin_comment
comment|/* Global interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU2100_ISR_FPM_INT
value|0x0020
end_define

begin_comment
comment|/* FPM interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU2100_ISR_FB_INT
value|0x0010
end_define

begin_comment
comment|/* FB interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU2100_ISR_RISC_INT
value|0x0008
end_define

begin_comment
comment|/* Risc interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU2100_ISR_CDMA_INT
value|0x0004
end_define

begin_comment
comment|/* CDMA interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU2100_ISR_RXDMA_INT_PENDING
value|0x0002
end_define

begin_comment
comment|/* Global interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BIU2100_ISR_TXDMA_INT_PENDING
value|0x0001
end_define

begin_comment
comment|/* Global interrupt pending */
end_comment

begin_define
define|#
directive|define
name|INT_PENDING
parameter_list|(
name|isp
parameter_list|,
name|isr
parameter_list|)
define|\
value|IS_FC(isp)?								\   (IS_24XX(isp)? (isr& BIU2400_ISR_RISC_INT) : (isr& BIU2100_ISR_RISC_INT)) :\   (isr& BIU_ISR_RISC_INT)
end_define

begin_define
define|#
directive|define
name|INT_PENDING_MASK
parameter_list|(
name|isp
parameter_list|)
define|\
value|(IS_FC(isp)? (IS_24XX(isp)? BIU2400_ISR_RISC_INT : BIU2100_ISR_RISC_INT) : \  (BIU_ISR_RISC_INT))
end_define

begin_comment
comment|/* BUS SEMAPHORE REGISTER */
end_comment

begin_define
define|#
directive|define
name|BIU_SEMA_STATUS
value|0x0002
end_define

begin_comment
comment|/* Semaphore Status Bit */
end_comment

begin_define
define|#
directive|define
name|BIU_SEMA_LOCK
value|0x0001
end_define

begin_comment
comment|/* Semaphore Lock Bit */
end_comment

begin_comment
comment|/* NVRAM SEMAPHORE REGISTER */
end_comment

begin_define
define|#
directive|define
name|BIU_NVRAM_CLOCK
value|0x0001
end_define

begin_define
define|#
directive|define
name|BIU_NVRAM_SELECT
value|0x0002
end_define

begin_define
define|#
directive|define
name|BIU_NVRAM_DATAOUT
value|0x0004
end_define

begin_define
define|#
directive|define
name|BIU_NVRAM_DATAIN
value|0x0008
end_define

begin_define
define|#
directive|define
name|BIU_NVRAM_BUSY
value|0x0080
end_define

begin_comment
comment|/* 2322/24xx only */
end_comment

begin_define
define|#
directive|define
name|ISP_NVRAM_READ
value|6
end_define

begin_comment
comment|/* COMNMAND&& DATA DMA CONFIGURATION REGISTER */
end_comment

begin_define
define|#
directive|define
name|DMA_ENABLE_SXP_DMA
value|0x0008
end_define

begin_comment
comment|/* Enable SXP to DMA Data */
end_comment

begin_define
define|#
directive|define
name|DMA_ENABLE_INTS
value|0x0004
end_define

begin_comment
comment|/* Enable interrupts to RISC */
end_comment

begin_define
define|#
directive|define
name|DMA_ENABLE_BURST
value|0x0002
end_define

begin_comment
comment|/* Enable Bus burst trans */
end_comment

begin_define
define|#
directive|define
name|DMA_DMA_DIRECTION
value|0x0001
end_define

begin_comment
comment|/* 						 * Set DMA direction: 						 *	0 - DMA FIFO to host 						 *	1 - Host to DMA FIFO 						 */
end_comment

begin_comment
comment|/* COMMAND&& DATA DMA CONTROL REGISTER */
end_comment

begin_define
define|#
directive|define
name|DMA_CNTRL_SUSPEND_CHAN
value|0x0010
end_define

begin_comment
comment|/* Suspend DMA transfer */
end_comment

begin_define
define|#
directive|define
name|DMA_CNTRL_CLEAR_CHAN
value|0x0008
end_define

begin_comment
comment|/* 						 * Clear FIFO and DMA Channel, 						 * reset DMA registers 						 */
end_comment

begin_define
define|#
directive|define
name|DMA_CNTRL_CLEAR_FIFO
value|0x0004
end_define

begin_comment
comment|/* Clear DMA FIFO */
end_comment

begin_define
define|#
directive|define
name|DMA_CNTRL_RESET_INT
value|0x0002
end_define

begin_comment
comment|/* Clear DMA interrupt */
end_comment

begin_define
define|#
directive|define
name|DMA_CNTRL_STROBE
value|0x0001
end_define

begin_comment
comment|/* Start DMA transfer */
end_comment

begin_comment
comment|/*  * Variants of same for 2100  */
end_comment

begin_define
define|#
directive|define
name|DMA_CNTRL2100_CLEAR_CHAN
value|0x0004
end_define

begin_define
define|#
directive|define
name|DMA_CNTRL2100_RESET_INT
value|0x0002
end_define

begin_comment
comment|/* DMA STATUS REGISTER */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_STATUS_PIPE_MASK
value|0x00C0
end_define

begin_comment
comment|/* DMA Pipeline status mask */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_STATUS_CHAN_MASK
value|0x0030
end_define

begin_comment
comment|/* Channel status mask */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_STATUS_BUS_PARITY
value|0x0008
end_define

begin_comment
comment|/* Parity Error on bus */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_STATUS_BUS_ERR
value|0x0004
end_define

begin_comment
comment|/* Error Detected on bus */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_STATUS_TERM_COUNT
value|0x0002
end_define

begin_comment
comment|/* DMA Transfer Completed */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_STATUS_INTERRUPT
value|0x0001
end_define

begin_comment
comment|/* Enable DMA channel inter */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_INTERRUPT
value|0x8000
end_define

begin_comment
comment|/* Enable DMA channel inter */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_RETRY_STAT
value|0x4000
end_define

begin_comment
comment|/* Retry status */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_CHAN_MASK
value|0x3000
end_define

begin_comment
comment|/* Channel status mask */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_FIFO_OVR
value|0x0100
end_define

begin_comment
comment|/* DMA FIFO overrun cond */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_FIFO_UDR
value|0x0080
end_define

begin_comment
comment|/* DMA FIFO underrun cond */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_BUS_ERR
value|0x0040
end_define

begin_comment
comment|/* Error Detected on bus */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_BUS_PARITY
value|0x0020
end_define

begin_comment
comment|/* Parity Error on bus */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_CLR_PEND
value|0x0010
end_define

begin_comment
comment|/* DMA clear pending */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_TERM_COUNT
value|0x0008
end_define

begin_comment
comment|/* DMA Transfer Completed */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_DMA_SUSP
value|0x0004
end_define

begin_comment
comment|/* DMA suspended */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_STATUS_PIPE_MASK
value|0x0003
end_define

begin_comment
comment|/* DMA Pipeline status mask */
end_comment

begin_comment
comment|/* DMA Status Register, pipeline status bits */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_PIPE_FULL
value|0x00C0
end_define

begin_comment
comment|/* Both pipeline stages full */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_PIPE_OVERRUN
value|0x0080
end_define

begin_comment
comment|/* Pipeline overrun */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_PIPE_STAGE1
value|0x0040
end_define

begin_comment
comment|/* 						 * Pipeline stage 1 Loaded, 						 * stage 2 empty 						 */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_PIPE_FULL
value|0x0003
end_define

begin_comment
comment|/* Both pipeline stages full */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_PIPE_OVERRUN
value|0x0002
end_define

begin_comment
comment|/* Pipeline overrun */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_PIPE_STAGE1
value|0x0001
end_define

begin_comment
comment|/* 						 * Pipeline stage 1 Loaded, 						 * stage 2 empty 						 */
end_comment

begin_define
define|#
directive|define
name|DMA_PIPE_EMPTY
value|0x0000
end_define

begin_comment
comment|/* All pipeline stages empty */
end_comment

begin_comment
comment|/* DMA Status Register, channel status bits */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_CHAN_SUSPEND
value|0x0030
end_define

begin_comment
comment|/* Channel error or suspended */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_CHAN_TRANSFER
value|0x0020
end_define

begin_comment
comment|/* Chan transfer in progress */
end_comment

begin_define
define|#
directive|define
name|DMA_SBUS_CHAN_ACTIVE
value|0x0010
end_define

begin_comment
comment|/* Chan trans to host active */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_CHAN_TRANSFER
value|0x3000
end_define

begin_comment
comment|/* Chan transfer in progress */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_CHAN_SUSPEND
value|0x2000
end_define

begin_comment
comment|/* Channel error or suspended */
end_comment

begin_define
define|#
directive|define
name|DMA_PCI_CHAN_ACTIVE
value|0x1000
end_define

begin_comment
comment|/* Chan trans to host active */
end_comment

begin_define
define|#
directive|define
name|ISP_DMA_CHAN_IDLE
value|0x0000
end_define

begin_comment
comment|/* Chan idle (normal comp) */
end_comment

begin_comment
comment|/* DMA FIFO STATUS REGISTER */
end_comment

begin_define
define|#
directive|define
name|DMA_FIFO_STATUS_OVERRUN
value|0x0200
end_define

begin_comment
comment|/* FIFO Overrun Condition */
end_comment

begin_define
define|#
directive|define
name|DMA_FIFO_STATUS_UNDERRUN
value|0x0100
end_define

begin_comment
comment|/* FIFO Underrun Condition */
end_comment

begin_define
define|#
directive|define
name|DMA_FIFO_SBUS_COUNT_MASK
value|0x007F
end_define

begin_comment
comment|/* FIFO Byte count mask */
end_comment

begin_define
define|#
directive|define
name|DMA_FIFO_PCI_COUNT_MASK
value|0x00FF
end_define

begin_comment
comment|/* FIFO Byte count mask */
end_comment

begin_comment
comment|/*  * 2400 Interface Offsets and Register Definitions  *   * The 2400 looks quite different in terms of registers from other QLogic cards.  * It is getting to be a genuine pain and challenge to keep the same model  * for all.  */
end_comment

begin_define
define|#
directive|define
name|BIU2400_FLASH_ADDR
value|(BIU_BLOCK+0x00)
end_define

begin_define
define|#
directive|define
name|BIU2400_FLASH_DATA
value|(BIU_BLOCK+0x04)
end_define

begin_define
define|#
directive|define
name|BIU2400_CSR
value|(BIU_BLOCK+0x08)
end_define

begin_define
define|#
directive|define
name|BIU2400_ICR
value|(BIU_BLOCK+0x0C)
end_define

begin_define
define|#
directive|define
name|BIU2400_ISR
value|(BIU_BLOCK+0x10)
end_define

begin_define
define|#
directive|define
name|BIU2400_REQINP
value|(BIU_BLOCK+0x1C)
end_define

begin_comment
comment|/* Request Queue In */
end_comment

begin_define
define|#
directive|define
name|BIU2400_REQOUTP
value|(BIU_BLOCK+0x20)
end_define

begin_comment
comment|/* Request Queue Out */
end_comment

begin_define
define|#
directive|define
name|BIU2400_RSPINP
value|(BIU_BLOCK+0x24)
end_define

begin_comment
comment|/* Response Queue In */
end_comment

begin_define
define|#
directive|define
name|BIU2400_RSPOUTP
value|(BIU_BLOCK+0x28)
end_define

begin_comment
comment|/* Response Queue Out */
end_comment

begin_define
define|#
directive|define
name|BIU2400_PRI_RQINP
value|(BIU_BLOCK+0x2C)
end_define

begin_comment
comment|/* Priority Request Q In */
end_comment

begin_define
define|#
directive|define
name|BIU2400_PRI_RSPINP
value|(BIU_BLOCK+0x30)
end_define

begin_comment
comment|/* Priority Request Q Out */
end_comment

begin_define
define|#
directive|define
name|BIU2400_ATIO_RSPINP
value|(BIU_BLOCK+0x3C)
end_define

begin_comment
comment|/* ATIO Queue In */
end_comment

begin_define
define|#
directive|define
name|BIU2400_ATIO_REQINP
value|(BIU_BLOCK+0x40)
end_define

begin_comment
comment|/* ATIO Queue Out */
end_comment

begin_define
define|#
directive|define
name|BIU2400_R2HSTSLO
value|(BIU_BLOCK+0x44)
end_define

begin_define
define|#
directive|define
name|BIU2400_R2HSTSHI
value|(BIU_BLOCK+0x46)
end_define

begin_define
define|#
directive|define
name|BIU2400_HCCR
value|(BIU_BLOCK+0x48)
end_define

begin_define
define|#
directive|define
name|BIU2400_GPIOD
value|(BIU_BLOCK+0x4C)
end_define

begin_define
define|#
directive|define
name|BIU2400_GPIOE
value|(BIU_BLOCK+0x50)
end_define

begin_define
define|#
directive|define
name|BIU2400_HSEMA
value|(BIU_BLOCK+0x58)
end_define

begin_comment
comment|/* BIU2400_FLASH_ADDR definitions */
end_comment

begin_define
define|#
directive|define
name|BIU2400_FLASH_DFLAG
value|(1<< 30)
end_define

begin_comment
comment|/* BIU2400_CSR definitions */
end_comment

begin_define
define|#
directive|define
name|BIU2400_NVERR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|BIU2400_DMA_ACTIVE
value|(1<< 17)
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|BIU2400_DMA_STOP
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|BIU2400_FUNCTION
value|(1<< 15)
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|BIU2400_PCIX_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xf)
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|BIU2400_CSR_64BIT
value|(1<< 2)
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|BIU2400_FLASH_ENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|BIU2400_SOFT_RESET
value|(1<< 0)
end_define

begin_comment
comment|/* BIU2400_ICR definitions */
end_comment

begin_define
define|#
directive|define
name|BIU2400_ICR_ENA_RISC_INT
value|0x8
end_define

begin_define
define|#
directive|define
name|BIU2400_IMASK
value|(BIU2400_ICR_ENA_RISC_INT)
end_define

begin_comment
comment|/* BIU2400_ISR definitions */
end_comment

begin_define
define|#
directive|define
name|BIU2400_ISR_RISC_INT
value|0x8
end_define

begin_define
define|#
directive|define
name|BIU2400_R2HST_INTR
value|BIU_R2HST_INTR
end_define

begin_define
define|#
directive|define
name|BIU2400_R2HST_PAUSED
value|BIU_R2HST_PAUSED
end_define

begin_define
define|#
directive|define
name|BIU2400_R2HST_ISTAT_MASK
value|0x1f
end_define

begin_comment
comment|/* interrupt status meanings */
end_comment

begin_define
define|#
directive|define
name|ISP2400R2HST_ROM_MBX_OK
value|0x1
end_define

begin_comment
comment|/* ROM mailbox cmd done ok */
end_comment

begin_define
define|#
directive|define
name|ISP2400R2HST_ROM_MBX_FAIL
value|0x2
end_define

begin_comment
comment|/* ROM mailbox cmd done fail */
end_comment

begin_define
define|#
directive|define
name|ISP2400R2HST_MBX_OK
value|0x10
end_define

begin_comment
comment|/* mailbox cmd done ok */
end_comment

begin_define
define|#
directive|define
name|ISP2400R2HST_MBX_FAIL
value|0x11
end_define

begin_comment
comment|/* mailbox cmd done fail */
end_comment

begin_define
define|#
directive|define
name|ISP2400R2HST_ASYNC_EVENT
value|0x12
end_define

begin_comment
comment|/* Async Event */
end_comment

begin_define
define|#
directive|define
name|ISP2400R2HST_RSPQ_UPDATE
value|0x13
end_define

begin_comment
comment|/* Response Queue Update */
end_comment

begin_define
define|#
directive|define
name|ISP2400R2HST_ATIO_RSPQ_UPDATE
value|0x1C
end_define

begin_comment
comment|/* ATIO Response Queue Update */
end_comment

begin_define
define|#
directive|define
name|ISP2400R2HST_ATIO_RQST_UPDATE
value|0x1D
end_define

begin_comment
comment|/* ATIO Request Queue Update */
end_comment

begin_comment
comment|/* BIU2400_HCCR definitions */
end_comment

begin_define
define|#
directive|define
name|HCCR_2400_CMD_NOP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HCCR_2400_CMD_RESET
value|0x10000000
end_define

begin_define
define|#
directive|define
name|HCCR_2400_CMD_CLEAR_RESET
value|0x20000000
end_define

begin_define
define|#
directive|define
name|HCCR_2400_CMD_PAUSE
value|0x30000000
end_define

begin_define
define|#
directive|define
name|HCCR_2400_CMD_RELEASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|HCCR_2400_CMD_SET_HOST_INT
value|0x50000000
end_define

begin_define
define|#
directive|define
name|HCCR_2400_CMD_CLEAR_HOST_INT
value|0x60000000
end_define

begin_define
define|#
directive|define
name|HCCR_2400_CMD_CLEAR_RISC_INT
value|0xA0000000
end_define

begin_define
define|#
directive|define
name|HCCR_2400_RISC_ERR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x7)
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|HCCR_2400_RISC2HOST_INT
value|(1<< 6)
end_define

begin_comment
comment|/* RO */
end_comment

begin_define
define|#
directive|define
name|HCCR_2400_RISC_RESET
value|(1<< 5)
end_define

begin_comment
comment|/* RO */
end_comment

begin_comment
comment|/*  * Mailbox Block Register Offsets  */
end_comment

begin_define
define|#
directive|define
name|INMAILBOX0
value|(MBOX_BLOCK+0x0)
end_define

begin_define
define|#
directive|define
name|INMAILBOX1
value|(MBOX_BLOCK+0x2)
end_define

begin_define
define|#
directive|define
name|INMAILBOX2
value|(MBOX_BLOCK+0x4)
end_define

begin_define
define|#
directive|define
name|INMAILBOX3
value|(MBOX_BLOCK+0x6)
end_define

begin_define
define|#
directive|define
name|INMAILBOX4
value|(MBOX_BLOCK+0x8)
end_define

begin_define
define|#
directive|define
name|INMAILBOX5
value|(MBOX_BLOCK+0xA)
end_define

begin_define
define|#
directive|define
name|INMAILBOX6
value|(MBOX_BLOCK+0xC)
end_define

begin_define
define|#
directive|define
name|INMAILBOX7
value|(MBOX_BLOCK+0xE)
end_define

begin_define
define|#
directive|define
name|OUTMAILBOX0
value|(MBOX_BLOCK+0x0)
end_define

begin_define
define|#
directive|define
name|OUTMAILBOX1
value|(MBOX_BLOCK+0x2)
end_define

begin_define
define|#
directive|define
name|OUTMAILBOX2
value|(MBOX_BLOCK+0x4)
end_define

begin_define
define|#
directive|define
name|OUTMAILBOX3
value|(MBOX_BLOCK+0x6)
end_define

begin_define
define|#
directive|define
name|OUTMAILBOX4
value|(MBOX_BLOCK+0x8)
end_define

begin_define
define|#
directive|define
name|OUTMAILBOX5
value|(MBOX_BLOCK+0xA)
end_define

begin_define
define|#
directive|define
name|OUTMAILBOX6
value|(MBOX_BLOCK+0xC)
end_define

begin_define
define|#
directive|define
name|OUTMAILBOX7
value|(MBOX_BLOCK+0xE)
end_define

begin_comment
comment|/*  * Strictly speaking, it's   *  SCSI&& 2100 : 8 MBOX registers  *  2200: 24 MBOX registers  *  2300/2400: 32 MBOX registers  */
end_comment

begin_define
define|#
directive|define
name|MBOX_OFF
parameter_list|(
name|n
parameter_list|)
value|(MBOX_BLOCK + ((n)<< 1))
end_define

begin_define
define|#
directive|define
name|NMBOX
parameter_list|(
name|isp
parameter_list|)
define|\
value|(((((isp)->isp_type& ISP_HA_SCSI)>= ISP_HA_SCSI_1040A) || \ 	 ((isp)->isp_type& ISP_HA_FC))? 12 : 6)
end_define

begin_define
define|#
directive|define
name|NMBOX_BMASK
parameter_list|(
name|isp
parameter_list|)
define|\
value|(((((isp)->isp_type& ISP_HA_SCSI)>= ISP_HA_SCSI_1040A) || \ 	 ((isp)->isp_type& ISP_HA_FC))? 0xfff : 0x3f)
end_define

begin_define
define|#
directive|define
name|MAX_MAILBOX
parameter_list|(
name|isp
parameter_list|)
value|((IS_FC(isp))? 12 : 8)
end_define

begin_define
define|#
directive|define
name|MAILBOX_STORAGE
value|12
end_define

begin_comment
comment|/* if timeout == 0, then default timeout is picked */
end_comment

begin_define
define|#
directive|define
name|MBCMD_DEFAULT_TIMEOUT
value|100000
end_define

begin_comment
comment|/* 100 ms */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|param
index|[
name|MAILBOX_STORAGE
index|]
decl_stmt|;
name|uint16_t
name|ibits
decl_stmt|;
name|uint16_t
name|obits
decl_stmt|;
name|uint32_t
label|:
literal|28
operator|,
name|logval
operator|:
literal|4
expr_stmt|;
name|uint32_t
name|timeout
decl_stmt|;
block|}
name|mbreg_t
typedef|;
end_typedef

begin_comment
comment|/*  * Fibre Protocol Module and Frame Buffer Register Offsets/Definitions (2X00).  * NB: The RISC processor must be paused and the appropriate register  * bank selected via BIU2100_CSR bits.  */
end_comment

begin_define
define|#
directive|define
name|FPM_DIAG_CONFIG
value|(BIU_BLOCK + 0x96)
end_define

begin_define
define|#
directive|define
name|FPM_SOFT_RESET
value|0x0100
end_define

begin_define
define|#
directive|define
name|FBM_CMD
value|(BIU_BLOCK + 0xB8)
end_define

begin_define
define|#
directive|define
name|FBMCMD_FIFO_RESET_ALL
value|0xA000
end_define

begin_comment
comment|/*  * SXP Block Register Offsets  */
end_comment

begin_define
define|#
directive|define
name|SXP_PART_ID
value|(SXP_BLOCK+0x0)
end_define

begin_comment
comment|/* R  : Part ID Code */
end_comment

begin_define
define|#
directive|define
name|SXP_CONFIG1
value|(SXP_BLOCK+0x2)
end_define

begin_comment
comment|/* RW*: Configuration Reg #1 */
end_comment

begin_define
define|#
directive|define
name|SXP_CONFIG2
value|(SXP_BLOCK+0x4)
end_define

begin_comment
comment|/* RW*: Configuration Reg #2 */
end_comment

begin_define
define|#
directive|define
name|SXP_CONFIG3
value|(SXP_BLOCK+0x6)
end_define

begin_comment
comment|/* RW*: Configuration Reg #2 */
end_comment

begin_define
define|#
directive|define
name|SXP_INSTRUCTION
value|(SXP_BLOCK+0xC)
end_define

begin_comment
comment|/* RW*: Instruction Pointer */
end_comment

begin_define
define|#
directive|define
name|SXP_RETURN_ADDR
value|(SXP_BLOCK+0x10)
end_define

begin_comment
comment|/* RW*: Return Address */
end_comment

begin_define
define|#
directive|define
name|SXP_COMMAND
value|(SXP_BLOCK+0x14)
end_define

begin_comment
comment|/* RW*: Command */
end_comment

begin_define
define|#
directive|define
name|SXP_INTERRUPT
value|(SXP_BLOCK+0x18)
end_define

begin_comment
comment|/* R  : Interrupt */
end_comment

begin_define
define|#
directive|define
name|SXP_SEQUENCE
value|(SXP_BLOCK+0x1C)
end_define

begin_comment
comment|/* RW*: Sequence */
end_comment

begin_define
define|#
directive|define
name|SXP_GROSS_ERR
value|(SXP_BLOCK+0x1E)
end_define

begin_comment
comment|/* R  : Gross Error */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPTION
value|(SXP_BLOCK+0x20)
end_define

begin_comment
comment|/* RW*: Exception Enable */
end_comment

begin_define
define|#
directive|define
name|SXP_OVERRIDE
value|(SXP_BLOCK+0x24)
end_define

begin_comment
comment|/* RW*: Override */
end_comment

begin_define
define|#
directive|define
name|SXP_LIT_BASE
value|(SXP_BLOCK+0x28)
end_define

begin_comment
comment|/* RW*: Literal Base */
end_comment

begin_define
define|#
directive|define
name|SXP_USER_FLAGS
value|(SXP_BLOCK+0x2C)
end_define

begin_comment
comment|/* RW*: User Flags */
end_comment

begin_define
define|#
directive|define
name|SXP_USER_EXCEPT
value|(SXP_BLOCK+0x30)
end_define

begin_comment
comment|/* RW*: User Exception */
end_comment

begin_define
define|#
directive|define
name|SXP_BREAKPOINT
value|(SXP_BLOCK+0x34)
end_define

begin_comment
comment|/* RW*: Breakpoint */
end_comment

begin_define
define|#
directive|define
name|SXP_SCSI_ID
value|(SXP_BLOCK+0x40)
end_define

begin_comment
comment|/* RW*: SCSI ID */
end_comment

begin_define
define|#
directive|define
name|SXP_DEV_CONFIG1
value|(SXP_BLOCK+0x42)
end_define

begin_comment
comment|/* RW*: Device Config Reg #1 */
end_comment

begin_define
define|#
directive|define
name|SXP_DEV_CONFIG2
value|(SXP_BLOCK+0x44)
end_define

begin_comment
comment|/* RW*: Device Config Reg #2 */
end_comment

begin_define
define|#
directive|define
name|SXP_PHASE_PTR
value|(SXP_BLOCK+0x48)
end_define

begin_comment
comment|/* RW*: SCSI Phase Pointer */
end_comment

begin_define
define|#
directive|define
name|SXP_BUF_PTR
value|(SXP_BLOCK+0x4C)
end_define

begin_comment
comment|/* RW*: SCSI Buffer Pointer */
end_comment

begin_define
define|#
directive|define
name|SXP_BUF_CTR
value|(SXP_BLOCK+0x50)
end_define

begin_comment
comment|/* RW*: SCSI Buffer Counter */
end_comment

begin_define
define|#
directive|define
name|SXP_BUFFER
value|(SXP_BLOCK+0x52)
end_define

begin_comment
comment|/* RW*: SCSI Buffer */
end_comment

begin_define
define|#
directive|define
name|SXP_BUF_BYTE
value|(SXP_BLOCK+0x54)
end_define

begin_comment
comment|/* RW*: SCSI Buffer Byte */
end_comment

begin_define
define|#
directive|define
name|SXP_BUF_WD
value|(SXP_BLOCK+0x56)
end_define

begin_comment
comment|/* RW*: SCSI Buffer Word */
end_comment

begin_define
define|#
directive|define
name|SXP_BUF_WD_TRAN
value|(SXP_BLOCK+0x58)
end_define

begin_comment
comment|/* RW*: SCSI Buffer Wd xlate */
end_comment

begin_define
define|#
directive|define
name|SXP_FIFO
value|(SXP_BLOCK+0x5A)
end_define

begin_comment
comment|/* RW*: SCSI FIFO */
end_comment

begin_define
define|#
directive|define
name|SXP_FIFO_STATUS
value|(SXP_BLOCK+0x5C)
end_define

begin_comment
comment|/* RW*: SCSI FIFO Status */
end_comment

begin_define
define|#
directive|define
name|SXP_FIFO_TOP
value|(SXP_BLOCK+0x5E)
end_define

begin_comment
comment|/* RW*: SCSI FIFO Top Resid */
end_comment

begin_define
define|#
directive|define
name|SXP_FIFO_BOTTOM
value|(SXP_BLOCK+0x60)
end_define

begin_comment
comment|/* RW*: SCSI FIFO Bot Resid */
end_comment

begin_define
define|#
directive|define
name|SXP_TRAN_REG
value|(SXP_BLOCK+0x64)
end_define

begin_comment
comment|/* RW*: SCSI Transferr Reg */
end_comment

begin_define
define|#
directive|define
name|SXP_TRAN_CNT_LO
value|(SXP_BLOCK+0x68)
end_define

begin_comment
comment|/* RW*: SCSI Trans Count */
end_comment

begin_define
define|#
directive|define
name|SXP_TRAN_CNT_HI
value|(SXP_BLOCK+0x6A)
end_define

begin_comment
comment|/* RW*: SCSI Trans Count */
end_comment

begin_define
define|#
directive|define
name|SXP_TRAN_CTR_LO
value|(SXP_BLOCK+0x6C)
end_define

begin_comment
comment|/* RW*: SCSI Trans Counter */
end_comment

begin_define
define|#
directive|define
name|SXP_TRAN_CTR_HI
value|(SXP_BLOCK+0x6E)
end_define

begin_comment
comment|/* RW*: SCSI Trans Counter */
end_comment

begin_define
define|#
directive|define
name|SXP_ARB_DATA
value|(SXP_BLOCK+0x70)
end_define

begin_comment
comment|/* R  : SCSI Arb Data */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CTRL
value|(SXP_BLOCK+0x72)
end_define

begin_comment
comment|/* RW*: SCSI Control Pins */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_DATA
value|(SXP_BLOCK+0x74)
end_define

begin_comment
comment|/* RW*: SCSI Data Pins */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_DIFF
value|(SXP_BLOCK+0x76)
end_define

begin_comment
comment|/* RW*: SCSI Diff Pins */
end_comment

begin_comment
comment|/* for 1080/1280/1240 only */
end_comment

begin_define
define|#
directive|define
name|SXP_BANK1_SELECT
value|0x100
end_define

begin_comment
comment|/* SXP CONF1 REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF1_ASYNCH_SETUP
value|0xF000
end_define

begin_comment
comment|/* Asynchronous setup time */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF1_SELECTION_UNIT
value|0x0000
end_define

begin_comment
comment|/* Selection time unit */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF1_SELECTION_TIMEOUT
value|0x0600
end_define

begin_comment
comment|/* Selection timeout */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF1_CLOCK_FACTOR
value|0x00E0
end_define

begin_comment
comment|/* Clock factor */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF1_SCSI_ID
value|0x000F
end_define

begin_comment
comment|/* SCSI id */
end_comment

begin_comment
comment|/* SXP CONF2 REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF2_DISABLE_FILTER
value|0x0040
end_define

begin_comment
comment|/* Disable SCSI rec filters */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF2_REQ_ACK_PULLUPS
value|0x0020
end_define

begin_comment
comment|/* Enable req/ack pullups */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF2_DATA_PULLUPS
value|0x0010
end_define

begin_comment
comment|/* Enable data pullups */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF2_CONFIG_AUTOLOAD
value|0x0008
end_define

begin_comment
comment|/* Enable dev conf auto-load */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF2_RESELECT
value|0x0002
end_define

begin_comment
comment|/* Enable reselection */
end_comment

begin_define
define|#
directive|define
name|SXP_CONF2_SELECT
value|0x0001
end_define

begin_comment
comment|/* Enable selection */
end_comment

begin_comment
comment|/* SXP INTERRUPT REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_PARITY_ERR
value|0x8000
end_define

begin_comment
comment|/* Parity error detected */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_GROSS_ERR
value|0x4000
end_define

begin_comment
comment|/* Gross error detected */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_FUNCTION_ABORT
value|0x2000
end_define

begin_comment
comment|/* Last cmd aborted */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_CONDITION_FAILED
value|0x1000
end_define

begin_comment
comment|/* Last cond failed test */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_FIFO_EMPTY
value|0x0800
end_define

begin_comment
comment|/* SCSI FIFO is empty */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_BUF_COUNTER_ZERO
value|0x0400
end_define

begin_comment
comment|/* SCSI buf count == zero */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_XFER_ZERO
value|0x0200
end_define

begin_comment
comment|/* SCSI trans count == zero */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_INT_PENDING
value|0x0080
end_define

begin_comment
comment|/* SXP interrupt pending */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_CMD_RUNNING
value|0x0040
end_define

begin_comment
comment|/* SXP is running a command */
end_comment

begin_define
define|#
directive|define
name|SXP_INT_INT_RETURN_CODE
value|0x000F
end_define

begin_comment
comment|/* Interrupt return code */
end_comment

begin_comment
comment|/* SXP GROSS ERROR REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_GROSS_OFFSET_RESID
value|0x0040
end_define

begin_comment
comment|/* Req/Ack offset not zero */
end_comment

begin_define
define|#
directive|define
name|SXP_GROSS_OFFSET_UNDERFLOW
value|0x0020
end_define

begin_comment
comment|/* Req/Ack offset underflow */
end_comment

begin_define
define|#
directive|define
name|SXP_GROSS_OFFSET_OVERFLOW
value|0x0010
end_define

begin_comment
comment|/* Req/Ack offset overflow */
end_comment

begin_define
define|#
directive|define
name|SXP_GROSS_FIFO_UNDERFLOW
value|0x0008
end_define

begin_comment
comment|/* SCSI FIFO underflow */
end_comment

begin_define
define|#
directive|define
name|SXP_GROSS_FIFO_OVERFLOW
value|0x0004
end_define

begin_comment
comment|/* SCSI FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|SXP_GROSS_WRITE_ERR
value|0x0002
end_define

begin_comment
comment|/* SXP and RISC wrote to reg */
end_comment

begin_define
define|#
directive|define
name|SXP_GROSS_ILLEGAL_INST
value|0x0001
end_define

begin_comment
comment|/* Bad inst loaded into SXP */
end_comment

begin_comment
comment|/* SXP EXCEPTION REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPT_USER_0
value|0x8000
end_define

begin_comment
comment|/* Enable user exception #0 */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPT_USER_1
value|0x4000
end_define

begin_comment
comment|/* Enable user exception #1 */
end_comment

begin_define
define|#
directive|define
name|PCI_SXP_EXCEPT_SCAM
value|0x0400
end_define

begin_comment
comment|/* SCAM Selection enable */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPT_BUS_FREE
value|0x0200
end_define

begin_comment
comment|/* Enable Bus Free det */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPT_TARGET_ATN
value|0x0100
end_define

begin_comment
comment|/* Enable TGT mode atten det */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPT_RESELECTED
value|0x0080
end_define

begin_comment
comment|/* Enable ReSEL exc handling */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPT_SELECTED
value|0x0040
end_define

begin_comment
comment|/* Enable SEL exc handling */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPT_ARBITRATION
value|0x0020
end_define

begin_comment
comment|/* Enable ARB exc handling */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPT_GROSS_ERR
value|0x0010
end_define

begin_comment
comment|/* Enable gross error except */
end_comment

begin_define
define|#
directive|define
name|SXP_EXCEPT_BUS_RESET
value|0x0008
end_define

begin_comment
comment|/* Enable Bus Reset except */
end_comment

begin_comment
comment|/* SXP OVERRIDE REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_EXT_TRIGGER
value|0x8000
end_define

begin_comment
comment|/* Enable external trigger */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_STEP
value|0x4000
end_define

begin_comment
comment|/* Enable single step mode */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_BREAKPOINT
value|0x2000
end_define

begin_comment
comment|/* Enable breakpoint reg */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_PIN_WRITE
value|0x1000
end_define

begin_comment
comment|/* Enable write to SCSI pins */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_FORCE_OUTPUTS
value|0x0800
end_define

begin_comment
comment|/* Force SCSI outputs on */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_LOOPBACK
value|0x0400
end_define

begin_comment
comment|/* Enable SCSI loopback mode */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_PARITY_TEST
value|0x0200
end_define

begin_comment
comment|/* Enable parity test mode */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_TRISTATE_ENA_PINS
value|0x0100
end_define

begin_comment
comment|/* Tristate SCSI enable pins */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_TRISTATE_PINS
value|0x0080
end_define

begin_comment
comment|/* Tristate SCSI pins */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_FIFO_RESET
value|0x0008
end_define

begin_comment
comment|/* Reset SCSI FIFO */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_CMD_TERMINATE
value|0x0004
end_define

begin_comment
comment|/* Terminate cur SXP com */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_RESET_REG
value|0x0002
end_define

begin_comment
comment|/* Reset SXP registers */
end_comment

begin_define
define|#
directive|define
name|SXP_ORIDE_RESET_MODULE
value|0x0001
end_define

begin_comment
comment|/* Reset SXP module */
end_comment

begin_comment
comment|/* SXP COMMANDS */
end_comment

begin_define
define|#
directive|define
name|SXP_RESET_BUS_CMD
value|0x300b
end_define

begin_comment
comment|/* SXP SCSI ID REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_SELECTING_ID
value|0x0F00
end_define

begin_comment
comment|/* (Re)Selecting id */
end_comment

begin_define
define|#
directive|define
name|SXP_SELECT_ID
value|0x000F
end_define

begin_comment
comment|/* Select id */
end_comment

begin_comment
comment|/* SXP DEV CONFIG1 REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_DCONF1_SYNC_HOLD
value|0x7000
end_define

begin_comment
comment|/* Synchronous data hold */
end_comment

begin_define
define|#
directive|define
name|SXP_DCONF1_SYNC_SETUP
value|0x0F00
end_define

begin_comment
comment|/* Synchronous data setup */
end_comment

begin_define
define|#
directive|define
name|SXP_DCONF1_SYNC_OFFSET
value|0x000F
end_define

begin_comment
comment|/* Synchronous data offset */
end_comment

begin_comment
comment|/* SXP DEV CONFIG2 REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_DCONF2_FLAGS_MASK
value|0xF000
end_define

begin_comment
comment|/* Device flags */
end_comment

begin_define
define|#
directive|define
name|SXP_DCONF2_WIDE
value|0x0400
end_define

begin_comment
comment|/* Enable wide SCSI */
end_comment

begin_define
define|#
directive|define
name|SXP_DCONF2_PARITY
value|0x0200
end_define

begin_comment
comment|/* Enable parity checking */
end_comment

begin_define
define|#
directive|define
name|SXP_DCONF2_BLOCK_MODE
value|0x0100
end_define

begin_comment
comment|/* Enable blk mode xfr count */
end_comment

begin_define
define|#
directive|define
name|SXP_DCONF2_ASSERTION_MASK
value|0x0007
end_define

begin_comment
comment|/* Assersion period mask */
end_comment

begin_comment
comment|/* SXP PHASE POINTER REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_PHASE_STATUS_PTR
value|0x1000
end_define

begin_comment
comment|/* Status buffer offset */
end_comment

begin_define
define|#
directive|define
name|SXP_PHASE_MSG_IN_PTR
value|0x0700
end_define

begin_comment
comment|/* Msg in buffer offset */
end_comment

begin_define
define|#
directive|define
name|SXP_PHASE_COM_PTR
value|0x00F0
end_define

begin_comment
comment|/* Command buffer offset */
end_comment

begin_define
define|#
directive|define
name|SXP_PHASE_MSG_OUT_PTR
value|0x0007
end_define

begin_comment
comment|/* Msg out buffer offset */
end_comment

begin_comment
comment|/* SXP FIFO STATUS REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_FIFO_TOP_RESID
value|0x8000
end_define

begin_comment
comment|/* Top residue reg full */
end_comment

begin_define
define|#
directive|define
name|SXP_FIFO_ACK_RESID
value|0x4000
end_define

begin_comment
comment|/* Wide transfers odd resid */
end_comment

begin_define
define|#
directive|define
name|SXP_FIFO_COUNT_MASK
value|0x001C
end_define

begin_comment
comment|/* Words in SXP FIFO */
end_comment

begin_define
define|#
directive|define
name|SXP_FIFO_BOTTOM_RESID
value|0x0001
end_define

begin_comment
comment|/* Bottom residue reg full */
end_comment

begin_comment
comment|/* SXP CONTROL PINS REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_PHASE
value|0x8000
end_define

begin_comment
comment|/* Scsi phase valid */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_PARITY_HI
value|0x0400
end_define

begin_comment
comment|/* Parity pin */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_PARITY_LO
value|0x0200
end_define

begin_comment
comment|/* Parity pin */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_REQ
value|0x0100
end_define

begin_comment
comment|/* SCSI bus REQUEST */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_ACK
value|0x0080
end_define

begin_comment
comment|/* SCSI bus ACKNOWLEDGE */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_RST
value|0x0040
end_define

begin_comment
comment|/* SCSI bus RESET */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_BSY
value|0x0020
end_define

begin_comment
comment|/* SCSI bus BUSY */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_SEL
value|0x0010
end_define

begin_comment
comment|/* SCSI bus SELECT */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_ATN
value|0x0008
end_define

begin_comment
comment|/* SCSI bus ATTENTION */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_MSG
value|0x0004
end_define

begin_comment
comment|/* SCSI bus MESSAGE */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_CD
value|0x0002
end_define

begin_comment
comment|/* SCSI bus COMMAND */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_CON_IO
value|0x0001
end_define

begin_comment
comment|/* SCSI bus INPUT */
end_comment

begin_comment
comment|/*  * Set the hold time for the SCSI Bus Reset to be 250 ms  */
end_comment

begin_define
define|#
directive|define
name|SXP_SCSI_BUS_RESET_HOLD_TIME
value|250
end_define

begin_comment
comment|/* SXP DIFF PINS REGISTER */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_DIFF_SENSE
value|0x0200
end_define

begin_comment
comment|/* DIFFSENS sig on SCSI bus */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_DIFF_MODE
value|0x0100
end_define

begin_comment
comment|/* DIFFM signal */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_DIFF_ENABLE_OUTPUT
value|0x0080
end_define

begin_comment
comment|/* Enable SXP SCSI data drv */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_DIFF_PINS_MASK
value|0x007C
end_define

begin_comment
comment|/* Differential control pins */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_DIFF_TARGET
value|0x0002
end_define

begin_comment
comment|/* Enable SXP target mode */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_DIFF_INITIATOR
value|0x0001
end_define

begin_comment
comment|/* Enable SXP initiator mode */
end_comment

begin_comment
comment|/* Ultra2 only */
end_comment

begin_define
define|#
directive|define
name|SXP_PINS_LVD_MODE
value|0x1000
end_define

begin_define
define|#
directive|define
name|SXP_PINS_HVD_MODE
value|0x0800
end_define

begin_define
define|#
directive|define
name|SXP_PINS_SE_MODE
value|0x0400
end_define

begin_comment
comment|/* The above have to be put together with the DIFFM pin to make sense */
end_comment

begin_define
define|#
directive|define
name|ISP1080_LVD_MODE
value|(SXP_PINS_LVD_MODE)
end_define

begin_define
define|#
directive|define
name|ISP1080_HVD_MODE
value|(SXP_PINS_HVD_MODE|SXP_PINS_DIFF_MODE)
end_define

begin_define
define|#
directive|define
name|ISP1080_SE_MODE
value|(SXP_PINS_SE_MODE)
end_define

begin_define
define|#
directive|define
name|ISP1080_MODE_MASK
define|\
value|(SXP_PINS_LVD_MODE|SXP_PINS_HVD_MODE|SXP_PINS_SE_MODE|SXP_PINS_DIFF_MODE)
end_define

begin_comment
comment|/*  * RISC and Host Command and Control Block Register Offsets  */
end_comment

begin_define
define|#
directive|define
name|RISC_ACC
value|RISC_BLOCK+0x0
end_define

begin_comment
comment|/* RW*: Accumulator */
end_comment

begin_define
define|#
directive|define
name|RISC_R1
value|RISC_BLOCK+0x2
end_define

begin_comment
comment|/* RW*: GP Reg R1  */
end_comment

begin_define
define|#
directive|define
name|RISC_R2
value|RISC_BLOCK+0x4
end_define

begin_comment
comment|/* RW*: GP Reg R2  */
end_comment

begin_define
define|#
directive|define
name|RISC_R3
value|RISC_BLOCK+0x6
end_define

begin_comment
comment|/* RW*: GP Reg R3  */
end_comment

begin_define
define|#
directive|define
name|RISC_R4
value|RISC_BLOCK+0x8
end_define

begin_comment
comment|/* RW*: GP Reg R4  */
end_comment

begin_define
define|#
directive|define
name|RISC_R5
value|RISC_BLOCK+0xA
end_define

begin_comment
comment|/* RW*: GP Reg R5  */
end_comment

begin_define
define|#
directive|define
name|RISC_R6
value|RISC_BLOCK+0xC
end_define

begin_comment
comment|/* RW*: GP Reg R6  */
end_comment

begin_define
define|#
directive|define
name|RISC_R7
value|RISC_BLOCK+0xE
end_define

begin_comment
comment|/* RW*: GP Reg R7  */
end_comment

begin_define
define|#
directive|define
name|RISC_R8
value|RISC_BLOCK+0x10
end_define

begin_comment
comment|/* RW*: GP Reg R8  */
end_comment

begin_define
define|#
directive|define
name|RISC_R9
value|RISC_BLOCK+0x12
end_define

begin_comment
comment|/* RW*: GP Reg R9  */
end_comment

begin_define
define|#
directive|define
name|RISC_R10
value|RISC_BLOCK+0x14
end_define

begin_comment
comment|/* RW*: GP Reg R10 */
end_comment

begin_define
define|#
directive|define
name|RISC_R11
value|RISC_BLOCK+0x16
end_define

begin_comment
comment|/* RW*: GP Reg R11 */
end_comment

begin_define
define|#
directive|define
name|RISC_R12
value|RISC_BLOCK+0x18
end_define

begin_comment
comment|/* RW*: GP Reg R12 */
end_comment

begin_define
define|#
directive|define
name|RISC_R13
value|RISC_BLOCK+0x1a
end_define

begin_comment
comment|/* RW*: GP Reg R13 */
end_comment

begin_define
define|#
directive|define
name|RISC_R14
value|RISC_BLOCK+0x1c
end_define

begin_comment
comment|/* RW*: GP Reg R14 */
end_comment

begin_define
define|#
directive|define
name|RISC_R15
value|RISC_BLOCK+0x1e
end_define

begin_comment
comment|/* RW*: GP Reg R15 */
end_comment

begin_define
define|#
directive|define
name|RISC_PSR
value|RISC_BLOCK+0x20
end_define

begin_comment
comment|/* RW*: Processor Status */
end_comment

begin_define
define|#
directive|define
name|RISC_IVR
value|RISC_BLOCK+0x22
end_define

begin_comment
comment|/* RW*: Interrupt Vector */
end_comment

begin_define
define|#
directive|define
name|RISC_PCR
value|RISC_BLOCK+0x24
end_define

begin_comment
comment|/* RW*: Processor Ctrl */
end_comment

begin_define
define|#
directive|define
name|RISC_RAR0
value|RISC_BLOCK+0x26
end_define

begin_comment
comment|/* RW*: Ram Address #0 */
end_comment

begin_define
define|#
directive|define
name|RISC_RAR1
value|RISC_BLOCK+0x28
end_define

begin_comment
comment|/* RW*: Ram Address #1 */
end_comment

begin_define
define|#
directive|define
name|RISC_LCR
value|RISC_BLOCK+0x2a
end_define

begin_comment
comment|/* RW*: Loop Counter */
end_comment

begin_define
define|#
directive|define
name|RISC_PC
value|RISC_BLOCK+0x2c
end_define

begin_comment
comment|/* R  : Program Counter */
end_comment

begin_define
define|#
directive|define
name|RISC_MTR
value|RISC_BLOCK+0x2e
end_define

begin_comment
comment|/* RW*: Memory Timing */
end_comment

begin_define
define|#
directive|define
name|RISC_MTR2100
value|RISC_BLOCK+0x30
end_define

begin_define
define|#
directive|define
name|RISC_EMB
value|RISC_BLOCK+0x30
end_define

begin_comment
comment|/* RW*: Ext Mem Boundary */
end_comment

begin_define
define|#
directive|define
name|DUAL_BANK
value|8
end_define

begin_define
define|#
directive|define
name|RISC_SP
value|RISC_BLOCK+0x32
end_define

begin_comment
comment|/* RW*: Stack Pointer */
end_comment

begin_define
define|#
directive|define
name|RISC_HRL
value|RISC_BLOCK+0x3e
end_define

begin_comment
comment|/* R *: Hardware Rev Level */
end_comment

begin_define
define|#
directive|define
name|HCCR
value|RISC_BLOCK+0x40
end_define

begin_comment
comment|/* RW : Host Command& Ctrl */
end_comment

begin_define
define|#
directive|define
name|BP0
value|RISC_BLOCK+0x42
end_define

begin_comment
comment|/* RW : Processor Brkpt #0 */
end_comment

begin_define
define|#
directive|define
name|BP1
value|RISC_BLOCK+0x44
end_define

begin_comment
comment|/* RW : Processor Brkpt #1 */
end_comment

begin_define
define|#
directive|define
name|TCR
value|RISC_BLOCK+0x46
end_define

begin_comment
comment|/*  W : Test Control */
end_comment

begin_define
define|#
directive|define
name|TMR
value|RISC_BLOCK+0x48
end_define

begin_comment
comment|/*  W : Test Mode */
end_comment

begin_comment
comment|/* PROCESSOR STATUS REGISTER */
end_comment

begin_define
define|#
directive|define
name|RISC_PSR_FORCE_TRUE
value|0x8000
end_define

begin_define
define|#
directive|define
name|RISC_PSR_LOOP_COUNT_DONE
value|0x4000
end_define

begin_define
define|#
directive|define
name|RISC_PSR_RISC_INT
value|0x2000
end_define

begin_define
define|#
directive|define
name|RISC_PSR_TIMER_ROLLOVER
value|0x1000
end_define

begin_define
define|#
directive|define
name|RISC_PSR_ALU_OVERFLOW
value|0x0800
end_define

begin_define
define|#
directive|define
name|RISC_PSR_ALU_MSB
value|0x0400
end_define

begin_define
define|#
directive|define
name|RISC_PSR_ALU_CARRY
value|0x0200
end_define

begin_define
define|#
directive|define
name|RISC_PSR_ALU_ZERO
value|0x0100
end_define

begin_define
define|#
directive|define
name|RISC_PSR_PCI_ULTRA
value|0x0080
end_define

begin_define
define|#
directive|define
name|RISC_PSR_SBUS_ULTRA
value|0x0020
end_define

begin_define
define|#
directive|define
name|RISC_PSR_DMA_INT
value|0x0010
end_define

begin_define
define|#
directive|define
name|RISC_PSR_SXP_INT
value|0x0008
end_define

begin_define
define|#
directive|define
name|RISC_PSR_HOST_INT
value|0x0004
end_define

begin_define
define|#
directive|define
name|RISC_PSR_INT_PENDING
value|0x0002
end_define

begin_define
define|#
directive|define
name|RISC_PSR_FORCE_FALSE
value|0x0001
end_define

begin_comment
comment|/* Host Command and Control */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_NOP
value|0x0000
end_define

begin_comment
comment|/* NOP */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_RESET
value|0x1000
end_define

begin_comment
comment|/* Reset RISC */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_PAUSE
value|0x2000
end_define

begin_comment
comment|/* Pause RISC */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_RELEASE
value|0x3000
end_define

begin_comment
comment|/* Release Paused RISC */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_STEP
value|0x4000
end_define

begin_comment
comment|/* Single Step RISC */
end_comment

begin_define
define|#
directive|define
name|HCCR_2X00_DISABLE_PARITY_PAUSE
value|0x4001
end_define

begin_comment
comment|/* 						 * Disable RISC pause on FPM 						 * parity error. 						 */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_SET_HOST_INT
value|0x5000
end_define

begin_comment
comment|/* Set Host Interrupt */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_CLEAR_HOST_INT
value|0x6000
end_define

begin_comment
comment|/* Clear Host Interrupt */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_CLEAR_RISC_INT
value|0x7000
end_define

begin_comment
comment|/* Clear RISC interrupt */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_BREAKPOINT
value|0x8000
end_define

begin_comment
comment|/* Change breakpoint enables */
end_comment

begin_define
define|#
directive|define
name|PCI_HCCR_CMD_BIOS
value|0x9000
end_define

begin_comment
comment|/* Write BIOS (disable) */
end_comment

begin_define
define|#
directive|define
name|PCI_HCCR_CMD_PARITY
value|0xA000
end_define

begin_comment
comment|/* Write parity enable */
end_comment

begin_define
define|#
directive|define
name|PCI_HCCR_CMD_PARITY_ERR
value|0xE000
end_define

begin_comment
comment|/* Generate parity error */
end_comment

begin_define
define|#
directive|define
name|HCCR_CMD_TEST_MODE
value|0xF000
end_define

begin_comment
comment|/* Set Test Mode */
end_comment

begin_define
define|#
directive|define
name|ISP2100_HCCR_PARITY_ENABLE_2
value|0x0400
end_define

begin_define
define|#
directive|define
name|ISP2100_HCCR_PARITY_ENABLE_1
value|0x0200
end_define

begin_define
define|#
directive|define
name|ISP2100_HCCR_PARITY_ENABLE_0
value|0x0100
end_define

begin_define
define|#
directive|define
name|ISP2100_HCCR_PARITY
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCI_HCCR_PARITY
value|0x0400
end_define

begin_comment
comment|/* Parity error flag */
end_comment

begin_define
define|#
directive|define
name|PCI_HCCR_PARITY_ENABLE_1
value|0x0200
end_define

begin_comment
comment|/* Parity enable bank 1 */
end_comment

begin_define
define|#
directive|define
name|PCI_HCCR_PARITY_ENABLE_0
value|0x0100
end_define

begin_comment
comment|/* Parity enable bank 0 */
end_comment

begin_define
define|#
directive|define
name|HCCR_HOST_INT
value|0x0080
end_define

begin_comment
comment|/* R  : Host interrupt set */
end_comment

begin_define
define|#
directive|define
name|HCCR_RESET
value|0x0040
end_define

begin_comment
comment|/* R  : reset in progress */
end_comment

begin_define
define|#
directive|define
name|HCCR_PAUSE
value|0x0020
end_define

begin_comment
comment|/* R  : RISC paused */
end_comment

begin_define
define|#
directive|define
name|PCI_HCCR_BIOS
value|0x0001
end_define

begin_comment
comment|/*  W : BIOS enable */
end_comment

begin_comment
comment|/*  * Defines for Interrupts  */
end_comment

begin_define
define|#
directive|define
name|ISP_INTS_ENABLED
parameter_list|(
name|isp
parameter_list|)
define|\
value|((IS_SCSI(isp))?  							\   (ISP_READ(isp, BIU_ICR)& BIU_IMASK) :				\    (IS_24XX(isp)? (ISP_READ(isp, BIU2400_ICR)& BIU2400_IMASK) :	\    (ISP_READ(isp, BIU_ICR)& BIU2100_IMASK)))
end_define

begin_define
define|#
directive|define
name|ISP_ENABLE_INTS
parameter_list|(
name|isp
parameter_list|)
define|\
value|(IS_SCSI(isp) ?  							\    ISP_WRITE(isp, BIU_ICR, BIU_IMASK) :					\    (IS_24XX(isp) ?							\     (ISP_WRITE(isp, BIU2400_ICR, BIU2400_IMASK)) :			\     (ISP_WRITE(isp, BIU_ICR, BIU2100_IMASK))))
end_define

begin_define
define|#
directive|define
name|ISP_DISABLE_INTS
parameter_list|(
name|isp
parameter_list|)
define|\
value|IS_24XX(isp)? ISP_WRITE(isp, BIU2400_ICR, 0) : ISP_WRITE(isp, BIU_ICR, 0)
end_define

begin_comment
comment|/*  * NVRAM Definitions (PCI cards only)  */
end_comment

begin_define
define|#
directive|define
name|ISPBSMX
parameter_list|(
name|c
parameter_list|,
name|byte
parameter_list|,
name|shift
parameter_list|,
name|mask
parameter_list|)
define|\
value|(((c)[(byte)]>> (shift))& (mask))
end_define

begin_comment
comment|/*  * Qlogic 1020/1040 NVRAM is an array of 128 bytes.  *  * Some portion of the front of this is for general host adapter properties  * This is followed by an array of per-target parameters, and is tailed off  * with a checksum xor byte at offset 127. For non-byte entities data is  * stored in Little Endian order.  */
end_comment

begin_define
define|#
directive|define
name|ISP_NVRAM_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_VERSION
parameter_list|(
name|c
parameter_list|)
value|(c)[4]
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_FIFO_THRESHOLD
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 5, 0, 0x03)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_BIOS_DISABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 5, 2, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_HBA_ENABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 5, 3, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_INITIATOR_ID
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 5, 4, 0x0f)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_BUS_RESET_DELAY
parameter_list|(
name|c
parameter_list|)
value|(c)[6]
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_BUS_RETRY_COUNT
parameter_list|(
name|c
parameter_list|)
value|(c)[7]
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_BUS_RETRY_DELAY
parameter_list|(
name|c
parameter_list|)
value|(c)[8]
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_ASYNC_DATA_SETUP_TIME
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 9, 0, 0x0f)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_REQ_ACK_ACTIVE_NEGATION
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 9, 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_DATA_LINE_ACTIVE_NEGATION
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 9, 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_DATA_DMA_BURST_ENABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 9, 6, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_CMD_DMA_BURST_ENABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 9, 7, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TAG_AGE_LIMIT
parameter_list|(
name|c
parameter_list|)
value|(c)[10]
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_LOWTRM_ENABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 11, 0, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_HITRM_ENABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 11, 1, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_PCMC_BURST_ENABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 11, 2, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_ENABLE_60_MHZ
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 11, 3, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_SCSI_RESET_DISABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 11, 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_ENABLE_AUTO_TERM
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 11, 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_FIFO_THRESHOLD_128
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 11, 6, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_AUTO_TERM_SUPPORT
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 11, 7, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_SELECTION_TIMEOUT
parameter_list|(
name|c
parameter_list|)
value|(((c)[12]) | ((c)[13]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_MAX_QUEUE_DEPTH
parameter_list|(
name|c
parameter_list|)
value|(((c)[14]) | ((c)[15]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_SCSI_BUS_SIZE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 16, 0, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_SCSI_BUS_TYPE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 16, 1, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_ADAPTER_CLK_SPEED
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 16, 2, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_SOFT_TERM_SUPPORT
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 16, 3, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_FLASH_ONBOARD
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 16, 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_FAST_MTTR_ENABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 22, 0, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TARGOFF
value|28
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TARGSIZE
value|6
end_define

begin_define
define|#
directive|define
name|_IxT
parameter_list|(
name|tgt
parameter_list|,
name|tidx
parameter_list|)
define|\
value|(ISP_NVRAM_TARGOFF + (ISP_NVRAM_TARGSIZE * (tgt)) + (tidx))
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_RENEG
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 0), 0, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_QFRZ
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 0), 1, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_ARQ
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 0), 2, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_TQING
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 0), 3, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_SYNC
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 0), 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_WIDE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 0), 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_PARITY
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 0), 6, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_DISC
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 0), 7, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_EXEC_THROTTLE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 1), 0, 0xff)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_SYNC_PERIOD
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 2), 0, 0xff)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_SYNC_OFFSET
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 3), 0, 0x0f)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_DEVICE_ENABLE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 3), 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP_NVRAM_TGT_LUN_DISABLE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|)
value|ISPBSMX(c, _IxT(t, 3), 5, 0x01)
end_define

begin_comment
comment|/*  * Qlogic 1080/1240 NVRAM is an array of 256 bytes.  *  * Some portion of the front of this is for general host adapter properties  * This is followed by an array of per-target parameters, and is tailed off  * with a checksum xor byte at offset 256. For non-byte entities data is  * stored in Little Endian order.  */
end_comment

begin_define
define|#
directive|define
name|ISP1080_NVRAM_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_VERSION
parameter_list|(
name|c
parameter_list|)
value|ISP_NVRAM_VERSION(c)
end_define

begin_comment
comment|/* Offset 5 */
end_comment

begin_comment
comment|/* 	uint8_t bios_configuration_mode     :2; 	uint8_t bios_disable                :1; 	uint8_t selectable_scsi_boot_enable :1; 	uint8_t cd_rom_boot_enable          :1; 	uint8_t disable_loading_risc_code   :1; 	uint8_t enable_64bit_addressing     :1; 	uint8_t unused_7                    :1;  */
end_comment

begin_comment
comment|/* Offsets 6, 7 */
end_comment

begin_comment
comment|/*         uint8_t boot_lun_number    :5;         uint8_t scsi_bus_number    :1;         uint8_t unused_6           :1;         uint8_t unused_7           :1;         uint8_t boot_target_number :4;         uint8_t unused_12          :1;         uint8_t unused_13          :1;         uint8_t unused_14          :1;         uint8_t unused_15          :1;  */
end_comment

begin_define
define|#
directive|define
name|ISP1080_NVRAM_HBA_ENABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 16, 3, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_BURST_ENABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 16, 1, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_FIFO_THRESHOLD
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 16, 4, 0x0f)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_AUTO_TERM_SUPPORT
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 17, 7, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_BUS0_TERM_MODE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 17, 0, 0x03)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_BUS1_TERM_MODE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 17, 2, 0x03)
end_define

begin_define
define|#
directive|define
name|ISP1080_ISP_PARAMETER
parameter_list|(
name|c
parameter_list|)
define|\
value|(((c)[18]) | ((c)[19]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP1080_FAST_POST
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 20, 0, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_REPORT_LVD_TRANSITION
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 20, 1, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_BUS1_OFF
value|112
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_INITIATOR_ID
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, ((b == 0)? 0 : ISP1080_BUS1_OFF) + 24, 0, 0x0f)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_BUS_RESET_DELAY
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
define|\
value|(c)[((b == 0)? 0 : ISP1080_BUS1_OFF) + 25]
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_BUS_RETRY_COUNT
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
define|\
value|(c)[((b == 0)? 0 : ISP1080_BUS1_OFF) + 26]
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_BUS_RETRY_DELAY
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
define|\
value|(c)[((b == 0)? 0 : ISP1080_BUS1_OFF) + 27]
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_ASYNC_DATA_SETUP_TIME
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, ((b == 0)? 0 : ISP1080_BUS1_OFF) + 28, 0, 0x0f)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_REQ_ACK_ACTIVE_NEGATION
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, ((b == 0)? 0 : ISP1080_BUS1_OFF) + 28, 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_DATA_LINE_ACTIVE_NEGATION
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, ((b == 0)? 0 : ISP1080_BUS1_OFF) + 28, 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_SELECTION_TIMEOUT
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
define|\
value|(((c)[((b == 0)? 0 : ISP1080_BUS1_OFF) + 30]) | \ 	((c)[((b == 0)? 0 : ISP1080_BUS1_OFF) + 31]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_MAX_QUEUE_DEPTH
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
define|\
value|(((c)[((b == 0)? 0 : ISP1080_BUS1_OFF) + 32]) | \ 	((c)[((b == 0)? 0 : ISP1080_BUS1_OFF) + 33]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TARGOFF
parameter_list|(
name|b
parameter_list|)
define|\
value|((b == 0)? 40: (40 + ISP1080_BUS1_OFF))
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TARGSIZE
value|6
end_define

begin_define
define|#
directive|define
name|_IxT8
parameter_list|(
name|tgt
parameter_list|,
name|tidx
parameter_list|,
name|b
parameter_list|)
define|\
value|(ISP1080_NVRAM_TARGOFF((b)) + (ISP1080_NVRAM_TARGSIZE * (tgt)) + (tidx))
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_RENEG
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 0, (b)), 0, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_QFRZ
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 0, (b)), 1, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_ARQ
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 0, (b)), 2, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_TQING
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 0, (b)), 3, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_SYNC
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 0, (b)), 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_WIDE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 0, (b)), 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_PARITY
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 0, (b)), 6, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_DISC
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 0, (b)), 7, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_EXEC_THROTTLE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 1, (b)), 0, 0xff)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_SYNC_PERIOD
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 2, (b)), 0, 0xff)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_SYNC_OFFSET
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 3, (b)), 0, 0x0f)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_DEVICE_ENABLE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 3, (b)), 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP1080_NVRAM_TGT_LUN_DISABLE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT8(t, 3, (b)), 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_HBA_ENABLE
value|ISP1080_NVRAM_HBA_ENABLE
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_BURST_ENABLE
value|ISP1080_NVRAM_BURST_ENABLE
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_FIFO_THRESHOLD
value|ISP1080_NVRAM_FIFO_THRESHOLD
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_AUTO_TERM_SUPPORT
value|ISP1080_NVRAM_AUTO_TERM_SUPPORT
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_BUS0_TERM_MODE
value|ISP1080_NVRAM_BUS0_TERM_MODE
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_BUS1_TERM_MODE
value|ISP1080_NVRAM_BUS1_TERM_MODE
end_define

begin_define
define|#
directive|define
name|ISP12160_ISP_PARAMETER
value|ISP12160_ISP_PARAMETER
end_define

begin_define
define|#
directive|define
name|ISP12160_FAST_POST
value|ISP1080_FAST_POST
end_define

begin_define
define|#
directive|define
name|ISP12160_REPORT_LVD_TRANSITION
value|ISP1080_REPORT_LVD_TRANSTION
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_INITIATOR_ID
define|\
value|ISP1080_NVRAM_INITIATOR_ID
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_BUS_RESET_DELAY
define|\
value|ISP1080_NVRAM_BUS_RESET_DELAY
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_BUS_RETRY_COUNT
define|\
value|ISP1080_NVRAM_BUS_RETRY_COUNT
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_BUS_RETRY_DELAY
define|\
value|ISP1080_NVRAM_BUS_RETRY_DELAY
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_ASYNC_DATA_SETUP_TIME
define|\
value|ISP1080_NVRAM_ASYNC_DATA_SETUP_TIME
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_REQ_ACK_ACTIVE_NEGATION
define|\
value|ISP1080_NVRAM_REQ_ACK_ACTIVE_NEGATION
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_DATA_LINE_ACTIVE_NEGATION
define|\
value|ISP1080_NVRAM_DATA_LINE_ACTIVE_NEGATION
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_SELECTION_TIMEOUT
define|\
value|ISP1080_NVRAM_SELECTION_TIMEOUT
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_MAX_QUEUE_DEPTH
define|\
value|ISP1080_NVRAM_MAX_QUEUE_DEPTH
end_define

begin_define
define|#
directive|define
name|ISP12160_BUS0_OFF
value|24
end_define

begin_define
define|#
directive|define
name|ISP12160_BUS1_OFF
value|136
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TARGOFF
parameter_list|(
name|b
parameter_list|)
define|\
value|(((b == 0)? ISP12160_BUS0_OFF : ISP12160_BUS1_OFF) + 16)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TARGSIZE
value|6
end_define

begin_define
define|#
directive|define
name|_IxT16
parameter_list|(
name|tgt
parameter_list|,
name|tidx
parameter_list|,
name|b
parameter_list|)
define|\
value|(ISP12160_NVRAM_TARGOFF((b))+(ISP12160_NVRAM_TARGSIZE * (tgt))+(tidx))
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_RENEG
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 0, (b)), 0, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_QFRZ
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 0, (b)), 1, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_ARQ
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 0, (b)), 2, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_TQING
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 0, (b)), 3, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_SYNC
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 0, (b)), 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_WIDE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 0, (b)), 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_PARITY
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 0, (b)), 6, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_DISC
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 0, (b)), 7, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_EXEC_THROTTLE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 1, (b)), 0, 0xff)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_SYNC_PERIOD
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 2, (b)), 0, 0xff)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_SYNC_OFFSET
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 3, (b)), 0, 0x1f)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_TGT_DEVICE_ENABLE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 3, (b)), 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_PPR_OPTIONS
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 4, (b)), 0, 0x0f)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_PPR_WIDTH
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 4, (b)), 4, 0x03)
end_define

begin_define
define|#
directive|define
name|ISP12160_NVRAM_PPR_ENABLE
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|b
parameter_list|)
define|\
value|ISPBSMX(c, _IxT16(t, 4, (b)), 7, 0x01)
end_define

begin_comment
comment|/*  * Qlogic 2100 thru 2300 NVRAM is an array of 256 bytes.  *  * Some portion of the front of this is for general RISC engine parameters,  * mostly reflecting the state of the last INITIALIZE FIRMWARE mailbox command.  *  * This is followed by some general host adapter parameters, and ends with  * a checksum xor byte at offset 255. For non-byte entities data is stored  * in Little Endian order.  */
end_comment

begin_define
define|#
directive|define
name|ISP2100_NVRAM_SIZE
value|256
end_define

begin_comment
comment|/* ISP_NVRAM_VERSION is in same overall place */
end_comment

begin_define
define|#
directive|define
name|ISP2100_NVRAM_RISCVER
parameter_list|(
name|c
parameter_list|)
value|(c)[6]
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_OPTIONS
parameter_list|(
name|c
parameter_list|)
value|((c)[8] | ((c)[9]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_MAXFRAMELENGTH
parameter_list|(
name|c
parameter_list|)
value|(((c)[10]) | ((c)[11]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_MAXIOCBALLOCATION
parameter_list|(
name|c
parameter_list|)
value|(((c)[12]) | ((c)[13]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_EXECUTION_THROTTLE
parameter_list|(
name|c
parameter_list|)
value|(((c)[14]) | ((c)[15]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_RETRY_COUNT
parameter_list|(
name|c
parameter_list|)
value|(c)[16]
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_RETRY_DELAY
parameter_list|(
name|c
parameter_list|)
value|(c)[17]
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_PORT_NAME
parameter_list|(
name|c
parameter_list|)
value|(\ 		(((uint64_t)(c)[18])<< 56) | \ 		(((uint64_t)(c)[19])<< 48) | \ 		(((uint64_t)(c)[20])<< 40) | \ 		(((uint64_t)(c)[21])<< 32) | \ 		(((uint64_t)(c)[22])<< 24) | \ 		(((uint64_t)(c)[23])<< 16) | \ 		(((uint64_t)(c)[24])<<  8) | \ 		(((uint64_t)(c)[25])<<  0))
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_HARDLOOPID
parameter_list|(
name|c
parameter_list|)
value|((c)[26] | ((c)[27]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_TOV
parameter_list|(
name|c
parameter_list|)
value|((c)[29])
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_NODE_NAME
parameter_list|(
name|c
parameter_list|)
value|(\ 		(((uint64_t)(c)[30])<< 56) | \ 		(((uint64_t)(c)[31])<< 48) | \ 		(((uint64_t)(c)[32])<< 40) | \ 		(((uint64_t)(c)[33])<< 32) | \ 		(((uint64_t)(c)[34])<< 24) | \ 		(((uint64_t)(c)[35])<< 16) | \ 		(((uint64_t)(c)[36])<<  8) | \ 		(((uint64_t)(c)[37])<<  0))
end_define

begin_define
define|#
directive|define
name|ISP2100_XFW_OPTIONS
parameter_list|(
name|c
parameter_list|)
value|((c)[38] | ((c)[39]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2100_RACC_TIMER
parameter_list|(
name|c
parameter_list|)
value|(c)[40]
end_define

begin_define
define|#
directive|define
name|ISP2100_IDELAY_TIMER
parameter_list|(
name|c
parameter_list|)
value|(c)[41]
end_define

begin_define
define|#
directive|define
name|ISP2100_ZFW_OPTIONS
parameter_list|(
name|c
parameter_list|)
value|((c)[42] | ((c)[43]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2100_SERIAL_LINK
parameter_list|(
name|c
parameter_list|)
value|((c)[68] | ((c)[69]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_HBA_OPTIONS
parameter_list|(
name|c
parameter_list|)
value|((c)[70] | ((c)[71]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_HBA_DISABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 70, 0, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_BIOS_DISABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 70, 1, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_LUN_DISABLE
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 70, 2, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_ENABLE_SELECT_BOOT
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 70, 3, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_DISABLE_CODELOAD
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 70, 4, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_SET_CACHELINESZ
parameter_list|(
name|c
parameter_list|)
value|ISPBSMX(c, 70, 5, 0x01)
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_BOOT_NODE_NAME
parameter_list|(
name|c
parameter_list|)
value|(\ 		(((uint64_t)(c)[72])<< 56) | \ 		(((uint64_t)(c)[73])<< 48) | \ 		(((uint64_t)(c)[74])<< 40) | \ 		(((uint64_t)(c)[75])<< 32) | \ 		(((uint64_t)(c)[76])<< 24) | \ 		(((uint64_t)(c)[77])<< 16) | \ 		(((uint64_t)(c)[78])<<  8) | \ 		(((uint64_t)(c)[79])<<  0))
end_define

begin_define
define|#
directive|define
name|ISP2100_NVRAM_BOOT_LUN
parameter_list|(
name|c
parameter_list|)
value|(c)[80]
end_define

begin_define
define|#
directive|define
name|ISP2100_RESET_DELAY
parameter_list|(
name|c
parameter_list|)
value|(c)[81]
end_define

begin_define
define|#
directive|define
name|ISP2100_HBA_FEATURES
parameter_list|(
name|c
parameter_list|)
value|((c)[232] | ((c)[233]<< 8))
end_define

begin_comment
comment|/*  * Qlogic 2400 NVRAM is an array of 512 bytes with a 32 bit checksum.  */
end_comment

begin_define
define|#
directive|define
name|ISP2400_NVRAM_PORT0_ADDR
value|0x80
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_PORT1_ADDR
value|0x180
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_VERSION
parameter_list|(
name|c
parameter_list|)
value|((c)[4] | ((c)[5]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_MAXFRAMELENGTH
parameter_list|(
name|c
parameter_list|)
value|(((c)[12]) | ((c)[13]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_EXECUTION_THROTTLE
parameter_list|(
name|c
parameter_list|)
value|(((c)[14]) | ((c)[15]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_EXCHANGE_COUNT
parameter_list|(
name|c
parameter_list|)
value|(((c)[16]) | ((c)[17]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_HARDLOOPID
parameter_list|(
name|c
parameter_list|)
value|((c)[18] | ((c)[19]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_PORT_NAME
parameter_list|(
name|c
parameter_list|)
value|(\ 		(((uint64_t)(c)[20])<< 56) | \ 		(((uint64_t)(c)[21])<< 48) | \ 		(((uint64_t)(c)[22])<< 40) | \ 		(((uint64_t)(c)[23])<< 32) | \ 		(((uint64_t)(c)[24])<< 24) | \ 		(((uint64_t)(c)[25])<< 16) | \ 		(((uint64_t)(c)[26])<<  8) | \ 		(((uint64_t)(c)[27])<<  0))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_NODE_NAME
parameter_list|(
name|c
parameter_list|)
value|(\ 		(((uint64_t)(c)[28])<< 56) | \ 		(((uint64_t)(c)[29])<< 48) | \ 		(((uint64_t)(c)[30])<< 40) | \ 		(((uint64_t)(c)[31])<< 32) | \ 		(((uint64_t)(c)[32])<< 24) | \ 		(((uint64_t)(c)[33])<< 16) | \ 		(((uint64_t)(c)[34])<<  8) | \ 		(((uint64_t)(c)[35])<<  0))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_LOGIN_RETRY_CNT
parameter_list|(
name|c
parameter_list|)
value|((c)[36] | ((c)[37]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_LINK_DOWN_ON_NOS
parameter_list|(
name|c
parameter_list|)
value|((c)[38] | ((c)[39]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_INTERRUPT_DELAY
parameter_list|(
name|c
parameter_list|)
value|((c)[40] | ((c)[41]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_LOGIN_TIMEOUT
parameter_list|(
name|c
parameter_list|)
value|((c)[42] | ((c)[43]<< 8))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_FIRMWARE_OPTIONS1
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)[44] | ((c)[45]<< 8) | ((c)[46]<< 16) | ((c)[47]<< 24))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_FIRMWARE_OPTIONS2
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)[48] | ((c)[49]<< 8) | ((c)[50]<< 16) | ((c)[51]<< 24))
end_define

begin_define
define|#
directive|define
name|ISP2400_NVRAM_FIRMWARE_OPTIONS3
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)[52] | ((c)[53]<< 8) | ((c)[54]<< 16) | ((c)[55]<< 24))
end_define

begin_comment
comment|/*  * Firmware Crash Dump  *  * QLogic needs specific information format when they look at firmware crashes.  *  * This is incredibly kernel memory consumptive (to say the least), so this  * code is only compiled in when needed.  */
end_comment

begin_define
define|#
directive|define
name|QLA2200_RISC_IMAGE_DUMP_SIZE
define|\
value|(1 * sizeof (uint16_t)) +
comment|/* 'used' flag (also HBA type) */
value|\ 	(352 * sizeof (uint16_t)) +
comment|/* RISC registers */
value|\  	(61440 * sizeof (uint16_t))
end_define

begin_comment
comment|/* RISC SRAM (offset 0x1000..0xffff) */
end_comment

begin_define
define|#
directive|define
name|QLA2300_RISC_IMAGE_DUMP_SIZE
define|\
value|(1 * sizeof (uint16_t)) +
comment|/* 'used' flag (also HBA type) */
value|\ 	(464 * sizeof (uint16_t)) +
comment|/* RISC registers */
value|\  	(63488 * sizeof (uint16_t)) +
comment|/* RISC SRAM (0x0800..0xffff) */
value|\ 	(4096 * sizeof (uint16_t)) +
comment|/* RISC SRAM (0x10000..0x10FFF) */
value|\ 	(61440 * sizeof (uint16_t))
end_define

begin_comment
comment|/* RISC SRAM (0x11000..0x1FFFF) */
end_comment

begin_comment
comment|/* the larger of the two */
end_comment

begin_define
define|#
directive|define
name|ISP_CRASH_IMAGE_SIZE
value|QLA2300_RISC_IMAGE_DUMP_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPREG_H */
end_comment

end_unit

