begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Alcove - Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPCREG_H
end_ifndef

begin_define
define|#
directive|define
name|__PPCREG_H
end_define

begin_comment
comment|/*  * Parallel Port Chipset type.  */
end_comment

begin_define
define|#
directive|define
name|SMC_LIKE
value|0
end_define

begin_define
define|#
directive|define
name|SMC_37C665GT
value|1
end_define

begin_define
define|#
directive|define
name|SMC_37C666GT
value|2
end_define

begin_define
define|#
directive|define
name|NS_PC87332
value|3
end_define

begin_define
define|#
directive|define
name|NS_PC87306
value|4
end_define

begin_define
define|#
directive|define
name|INTEL_820191AA
value|5
end_define

begin_comment
comment|/* XXX not implemented */
end_comment

begin_define
define|#
directive|define
name|GENERIC
value|6
end_define

begin_define
define|#
directive|define
name|WINB_W83877F
value|7
end_define

begin_define
define|#
directive|define
name|WINB_W83877AF
value|8
end_define

begin_define
define|#
directive|define
name|WINB_UNKNOWN
value|9
end_define

begin_define
define|#
directive|define
name|NS_PC87334
value|10
end_define

begin_define
define|#
directive|define
name|SMC_37C935
value|11
end_define

begin_define
define|#
directive|define
name|NS_PC87303
value|12
end_define

begin_comment
comment|/*  * Parallel Port Chipset Type. SMC versus GENERIC (others)  */
end_comment

begin_define
define|#
directive|define
name|PPC_TYPE_SMCLIKE
value|0
end_define

begin_define
define|#
directive|define
name|PPC_TYPE_GENERIC
value|1
end_define

begin_comment
comment|/*  * Generic structure to hold parallel port chipset info.  */
end_comment

begin_struct
struct|struct
name|ppc_data
block|{
name|int
name|ppc_unit
decl_stmt|;
name|int
name|ppc_model
decl_stmt|;
comment|/* chipset model if detected */
name|int
name|ppc_type
decl_stmt|;
comment|/* generic or smclike chipset type */
name|int
name|ppc_mode
decl_stmt|;
comment|/* chipset current mode */
name|int
name|ppc_avm
decl_stmt|;
comment|/* chipset available modes */
name|int
name|ppc_dtm
decl_stmt|;
comment|/* chipset detected modes */
define|#
directive|define
name|PPC_IRQ_NONE
value|0x0
define|#
directive|define
name|PPC_IRQ_nACK
value|0x1
define|#
directive|define
name|PPC_IRQ_DMA
value|0x2
define|#
directive|define
name|PPC_IRQ_FIFO
value|0x4
define|#
directive|define
name|PPC_IRQ_nFAULT
value|0x8
name|int
name|ppc_irqstat
decl_stmt|;
comment|/* remind irq settings */
define|#
directive|define
name|PPC_DMA_INIT
value|0x01
define|#
directive|define
name|PPC_DMA_STARTED
value|0x02
define|#
directive|define
name|PPC_DMA_COMPLETE
value|0x03
define|#
directive|define
name|PPC_DMA_INTERRUPTED
value|0x04
define|#
directive|define
name|PPC_DMA_ERROR
value|0x05
name|int
name|ppc_dmastat
decl_stmt|;
comment|/* dma state */
name|int
name|ppc_dmachan
decl_stmt|;
comment|/* dma channel */
name|int
name|ppc_dmaflags
decl_stmt|;
comment|/* dma transfer flags */
name|caddr_t
name|ppc_dmaddr
decl_stmt|;
comment|/* buffer address */
name|u_int
name|ppc_dmacnt
decl_stmt|;
comment|/* count of bytes sent with dma */
define|#
directive|define
name|PPC_PWORD_MASK
value|0x30
define|#
directive|define
name|PPC_PWORD_16
value|0x00
define|#
directive|define
name|PPC_PWORD_8
value|0x10
define|#
directive|define
name|PPC_PWORD_32
value|0x20
name|char
name|ppc_pword
decl_stmt|;
comment|/* PWord size */
name|short
name|ppc_fifo
decl_stmt|;
comment|/* FIFO threshold */
name|short
name|ppc_wthr
decl_stmt|;
comment|/* writeIntrThresold */
name|short
name|ppc_rthr
decl_stmt|;
comment|/* readIntrThresold */
name|char
modifier|*
name|ppc_ptr
decl_stmt|;
comment|/* microseq current pointer */
name|int
name|ppc_accum
decl_stmt|;
comment|/* microseq accumulator */
name|int
name|ppc_base
decl_stmt|;
comment|/* parallel port base address */
name|int
name|ppc_epp
decl_stmt|;
comment|/* EPP mode (1.7 or 1.9) */
name|int
name|ppc_irq
decl_stmt|;
name|unsigned
name|char
name|ppc_flags
decl_stmt|;
name|device_t
name|ppbus
decl_stmt|;
comment|/* parallel port chipset corresponding ppbus */
name|int
name|rid_irq
decl_stmt|,
name|rid_drq
decl_stmt|,
name|rid_ioport
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_irq
decl_stmt|,
modifier|*
name|res_drq
decl_stmt|,
modifier|*
name|res_ioport
decl_stmt|;
name|void
modifier|*
name|intr_cookie
decl_stmt|;
name|int
name|ppc_registered
decl_stmt|;
comment|/* 1 if ppcintr() is the registered interrupt */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parallel Port Chipset registers.  */
end_comment

begin_define
define|#
directive|define
name|PPC_SPP_DTR
value|0
end_define

begin_comment
comment|/* SPP data register */
end_comment

begin_define
define|#
directive|define
name|PPC_ECP_A_FIFO
value|0
end_define

begin_comment
comment|/* ECP Address fifo register */
end_comment

begin_define
define|#
directive|define
name|PPC_SPP_STR
value|1
end_define

begin_comment
comment|/* SPP status register */
end_comment

begin_define
define|#
directive|define
name|PPC_SPP_CTR
value|2
end_define

begin_comment
comment|/* SPP control register */
end_comment

begin_define
define|#
directive|define
name|PPC_EPP_ADDR
value|3
end_define

begin_comment
comment|/* EPP address register (8 bit) */
end_comment

begin_define
define|#
directive|define
name|PPC_EPP_DATA
value|4
end_define

begin_comment
comment|/* EPP data register (8, 16 or 32 bit) */
end_comment

begin_define
define|#
directive|define
name|PPC_ECP_D_FIFO
value|0x400
end_define

begin_comment
comment|/* ECP Data fifo register */
end_comment

begin_define
define|#
directive|define
name|PPC_ECP_CNFGA
value|0x400
end_define

begin_comment
comment|/* Configuration register A */
end_comment

begin_define
define|#
directive|define
name|PPC_ECP_CNFGB
value|0x401
end_define

begin_comment
comment|/* Configuration register B */
end_comment

begin_define
define|#
directive|define
name|PPC_ECP_ECR
value|0x402
end_define

begin_comment
comment|/* ECP extended control register */
end_comment

begin_define
define|#
directive|define
name|PPC_FIFO_EMPTY
value|0x1
end_define

begin_comment
comment|/* ecr register - bit 0 */
end_comment

begin_define
define|#
directive|define
name|PPC_FIFO_FULL
value|0x2
end_define

begin_comment
comment|/* ecr register - bit 1 */
end_comment

begin_define
define|#
directive|define
name|PPC_SERVICE_INTR
value|0x4
end_define

begin_comment
comment|/* ecr register - bit 2 */
end_comment

begin_define
define|#
directive|define
name|PPC_ENABLE_DMA
value|0x8
end_define

begin_comment
comment|/* ecr register - bit 3 */
end_comment

begin_define
define|#
directive|define
name|PPC_nFAULT_INTR
value|0x10
end_define

begin_comment
comment|/* ecr register - bit 4 */
end_comment

begin_define
define|#
directive|define
name|PPC_ECR_STD
value|0x0
end_define

begin_define
define|#
directive|define
name|PPC_ECR_PS2
value|0x20
end_define

begin_define
define|#
directive|define
name|PPC_ECR_FIFO
value|0x40
end_define

begin_define
define|#
directive|define
name|PPC_ECR_ECP
value|0x60
end_define

begin_define
define|#
directive|define
name|PPC_ECR_EPP
value|0x80
end_define

begin_define
define|#
directive|define
name|PPC_DISABLE_INTR
value|(PPC_SERVICE_INTR | PPC_nFAULT_INTR)
end_define

begin_define
define|#
directive|define
name|PPC_ECR_RESET
value|(PPC_ECR_PS2 | PPC_DISABLE_INTR)
end_define

begin_define
define|#
directive|define
name|r_dtr
parameter_list|(
name|ppc
parameter_list|)
value|(inb((ppc)->ppc_base + PPC_SPP_DTR))
end_define

begin_define
define|#
directive|define
name|r_str
parameter_list|(
name|ppc
parameter_list|)
value|(inb((ppc)->ppc_base + PPC_SPP_STR))
end_define

begin_define
define|#
directive|define
name|r_ctr
parameter_list|(
name|ppc
parameter_list|)
value|(inb((ppc)->ppc_base + PPC_SPP_CTR))
end_define

begin_define
define|#
directive|define
name|r_epp_A
parameter_list|(
name|ppc
parameter_list|)
value|(inb((ppc)->ppc_base + PPC_EPP_ADDR))
end_define

begin_define
define|#
directive|define
name|r_epp_D
parameter_list|(
name|ppc
parameter_list|)
value|(inb((ppc)->ppc_base + PPC_EPP_DATA))
end_define

begin_define
define|#
directive|define
name|r_cnfgA
parameter_list|(
name|ppc
parameter_list|)
value|(inb((ppc)->ppc_base + PPC_ECP_CNFGA))
end_define

begin_define
define|#
directive|define
name|r_cnfgB
parameter_list|(
name|ppc
parameter_list|)
value|(inb((ppc)->ppc_base + PPC_ECP_CNFGB))
end_define

begin_define
define|#
directive|define
name|r_ecr
parameter_list|(
name|ppc
parameter_list|)
value|(inb((ppc)->ppc_base + PPC_ECP_ECR))
end_define

begin_define
define|#
directive|define
name|r_fifo
parameter_list|(
name|ppc
parameter_list|)
value|(inb((ppc)->ppc_base + PPC_ECP_D_FIFO))
end_define

begin_define
define|#
directive|define
name|w_dtr
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_SPP_DTR, byte)
end_define

begin_define
define|#
directive|define
name|w_str
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_SPP_STR, byte)
end_define

begin_define
define|#
directive|define
name|w_ctr
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_SPP_CTR, byte)
end_define

begin_define
define|#
directive|define
name|w_epp_A
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_EPP_ADDR, byte)
end_define

begin_define
define|#
directive|define
name|w_epp_D
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_EPP_DATA, byte)
end_define

begin_define
define|#
directive|define
name|w_ecr
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_ECP_ECR, byte)
end_define

begin_define
define|#
directive|define
name|w_fifo
parameter_list|(
name|ppc
parameter_list|,
name|byte
parameter_list|)
value|outb((ppc)->ppc_base + PPC_ECP_D_FIFO, byte)
end_define

begin_comment
comment|/*  * Register defines for the PC873xx parts  */
end_comment

begin_define
define|#
directive|define
name|PC873_FER
value|0x00
end_define

begin_define
define|#
directive|define
name|PC873_PPENABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PC873_FAR
value|0x01
end_define

begin_define
define|#
directive|define
name|PC873_PTR
value|0x02
end_define

begin_define
define|#
directive|define
name|PC873_CFGLOCK
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|PC873_EPPRDIR
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|PC873_EXTENDED
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|PC873_LPTBIRQ7
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PC873_FCR
value|0x03
end_define

begin_define
define|#
directive|define
name|PC873_ZWS
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PC873_ZWSPWDN
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|PC873_PCR
value|0x04
end_define

begin_define
define|#
directive|define
name|PC873_EPPEN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PC873_EPP19
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PC873_ECPEN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PC873_ECPCLK
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PC873_PMC
value|0x06
end_define

begin_define
define|#
directive|define
name|PC873_TUP
value|0x07
end_define

begin_define
define|#
directive|define
name|PC873_SID
value|0x08
end_define

begin_define
define|#
directive|define
name|PC873_PNP0
value|0x1b
end_define

begin_define
define|#
directive|define
name|PC873_PNP1
value|0x1c
end_define

begin_define
define|#
directive|define
name|PC873_LPTBA
value|0x19
end_define

begin_comment
comment|/*  * Register defines for the SMC FDC37C66xGT parts  */
end_comment

begin_comment
comment|/* Init codes */
end_comment

begin_define
define|#
directive|define
name|SMC665_iCODE
value|0x55
end_define

begin_define
define|#
directive|define
name|SMC666_iCODE
value|0x44
end_define

begin_comment
comment|/* Base configuration ports */
end_comment

begin_define
define|#
directive|define
name|SMC66x_CSR
value|0x3F0
end_define

begin_define
define|#
directive|define
name|SMC666_CSR
value|0x370
end_define

begin_comment
comment|/* hard-configured value for 666 */
end_comment

begin_comment
comment|/* Bits */
end_comment

begin_define
define|#
directive|define
name|SMC_CR1_ADDR
value|0x3
end_define

begin_comment
comment|/* bit 0 and 1 */
end_comment

begin_define
define|#
directive|define
name|SMC_CR1_MODE
value|(1<<3)
end_define

begin_comment
comment|/* bit 3 */
end_comment

begin_define
define|#
directive|define
name|SMC_CR4_EMODE
value|0x3
end_define

begin_comment
comment|/* bits 0 and 1 */
end_comment

begin_define
define|#
directive|define
name|SMC_CR4_EPPTYPE
value|(1<<6)
end_define

begin_comment
comment|/* bit 6 */
end_comment

begin_comment
comment|/* Extended modes */
end_comment

begin_define
define|#
directive|define
name|SMC_SPP
value|0x0
end_define

begin_comment
comment|/* SPP */
end_comment

begin_define
define|#
directive|define
name|SMC_EPPSPP
value|0x1
end_define

begin_comment
comment|/* EPP and SPP */
end_comment

begin_define
define|#
directive|define
name|SMC_ECP
value|0x2
end_define

begin_comment
comment|/* ECP */
end_comment

begin_define
define|#
directive|define
name|SMC_ECPEPP
value|0x3
end_define

begin_comment
comment|/* ECP and EPP */
end_comment

begin_comment
comment|/*  * Register defines for the SMC FDC37C935 parts  */
end_comment

begin_comment
comment|/* Configuration ports */
end_comment

begin_define
define|#
directive|define
name|SMC935_CFG
value|0x370
end_define

begin_define
define|#
directive|define
name|SMC935_IND
value|0x370
end_define

begin_define
define|#
directive|define
name|SMC935_DAT
value|0x371
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|SMC935_LOGDEV
value|0x7
end_define

begin_define
define|#
directive|define
name|SMC935_ID
value|0x20
end_define

begin_define
define|#
directive|define
name|SMC935_PORTHI
value|0x60
end_define

begin_define
define|#
directive|define
name|SMC935_PORTLO
value|0x61
end_define

begin_define
define|#
directive|define
name|SMC935_PPMODE
value|0xf0
end_define

begin_comment
comment|/* Parallel port modes */
end_comment

begin_define
define|#
directive|define
name|SMC935_SPP
value|0x38 + 0
end_define

begin_define
define|#
directive|define
name|SMC935_EPP19SPP
value|0x38 + 1
end_define

begin_define
define|#
directive|define
name|SMC935_ECP
value|0x38 + 2
end_define

begin_define
define|#
directive|define
name|SMC935_ECPEPP19
value|0x38 + 3
end_define

begin_define
define|#
directive|define
name|SMC935_CENT
value|0x38 + 4
end_define

begin_define
define|#
directive|define
name|SMC935_EPP17SPP
value|0x38 + 5
end_define

begin_define
define|#
directive|define
name|SMC935_UNUSED
value|0x38 + 6
end_define

begin_define
define|#
directive|define
name|SMC935_ECPEPP17
value|0x38 + 7
end_define

begin_comment
comment|/*  * Register defines for the Winbond W83877F parts  */
end_comment

begin_define
define|#
directive|define
name|WINB_W83877F_ID
value|0xa
end_define

begin_define
define|#
directive|define
name|WINB_W83877AF_ID
value|0xb
end_define

begin_comment
comment|/* Configuration bits */
end_comment

begin_define
define|#
directive|define
name|WINB_HEFERE
value|(1<<5)
end_define

begin_comment
comment|/* CROC bit 5 */
end_comment

begin_define
define|#
directive|define
name|WINB_HEFRAS
value|(1<<0)
end_define

begin_comment
comment|/* CR16 bit 0 */
end_comment

begin_define
define|#
directive|define
name|WINB_PNPCVS
value|(1<<2)
end_define

begin_comment
comment|/* CR16 bit 2 */
end_comment

begin_define
define|#
directive|define
name|WINB_CHIPID
value|0xf
end_define

begin_comment
comment|/* CR9 bits 0-3 */
end_comment

begin_define
define|#
directive|define
name|WINB_PRTMODS0
value|(1<<2)
end_define

begin_comment
comment|/* CR0 bit 2 */
end_comment

begin_define
define|#
directive|define
name|WINB_PRTMODS1
value|(1<<3)
end_define

begin_comment
comment|/* CR0 bit 3 */
end_comment

begin_define
define|#
directive|define
name|WINB_PRTMODS2
value|(1<<7)
end_define

begin_comment
comment|/* CR9 bit 7 */
end_comment

begin_comment
comment|/* W83877F modes: CR9/bit7 | CR0/bit3 | CR0/bit2 */
end_comment

begin_define
define|#
directive|define
name|WINB_W83757
value|0x0
end_define

begin_define
define|#
directive|define
name|WINB_EXTFDC
value|0x4
end_define

begin_define
define|#
directive|define
name|WINB_EXTADP
value|0x8
end_define

begin_define
define|#
directive|define
name|WINB_EXT2FDD
value|0xc
end_define

begin_define
define|#
directive|define
name|WINB_JOYSTICK
value|0x80
end_define

begin_define
define|#
directive|define
name|WINB_PARALLEL
value|0x80
end_define

begin_define
define|#
directive|define
name|WINB_EPP_SPP
value|0x4
end_define

begin_define
define|#
directive|define
name|WINB_ECP
value|0x8
end_define

begin_define
define|#
directive|define
name|WINB_ECP_EPP
value|0xc
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

