begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) KATO Takenori, 1996.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * PC-9801 specific definitions for National Semiconductor DP8390 NIC  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PC98_PC98_IF_ED98_H__
end_ifndef

begin_define
define|#
directive|define
name|__PC98_PC98_IF_ED98_H__
end_define

begin_comment
comment|/* PC98 only */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PC98
end_ifndef

begin_error
error|#
directive|error
error|Why you include if_ed98.h?
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|void
name|pc98_set_register
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|dev
operator|,
name|int
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Vendor types  */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_MISC
value|0xf0
end_define

begin_comment
comment|/* others */
end_comment

begin_comment
comment|/*  * Register offsets/total  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ED_NOVELL_NIC_OFFSET
end_ifdef

begin_undef
undef|#
directive|undef
name|ED_NOVELL_NIC_OFFSET
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ED_NOVELL_NIC_OFFSET
value|sc->edreg.nic_offset
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ED_NOVELL_ASIC_OFFSET
end_ifdef

begin_undef
undef|#
directive|undef
name|ED_NOVELL_ASIC_OFFSET
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ED_NOVELL_ASIC_OFFSET
value|sc->edreg.asic_offset
end_define

begin_comment
comment|/*  * Remote DMA data register; for reading or writing to the NIC mem  *	via programmed I/O (offset from ASIC base)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ED_NOVELL_DATA
end_ifdef

begin_undef
undef|#
directive|undef
name|ED_NOVELL_DATA
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ED_NOVELL_DATA
value|sc->edreg.data
end_define

begin_comment
comment|/*  * Reset register; reading from this register causes a board reset  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ED_NOVELL_RESET
end_ifdef

begin_undef
undef|#
directive|undef
name|ED_NOVELL_RESET
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ED_NOVELL_RESET
value|sc->edreg.reset
end_define

begin_comment
comment|/*  * Card type  *  * Type  Card  * 0x00  Allied Telesis CenterCom LA-98-T  * 0x10  MELCO LPC-TJ, LPC-TS / IO-DATA PCLA/T  * 0x20  PLANET SMART COM 98 EN-2298 / ELECOM LANEED LD-BDN[123]A  * 0x30  MELCO EGY-98 / Contec C-NET(98)E-A/L-A  * 0x40  MELCO LGY-98, IND-SP, IND-SS / MACNICA NE2098(XXX)  * 0x50  ICM DT-ET-25, DT-ET-T5, IF-2766ET, IF-2771ET /  *       D-Link DE-298P{T,CAT}, DE-298{T,TP,CAT}  * 0x60  Allied Telesis SIC-98  * 0x80  NEC PC-9801-108  * 0x90  IO-DATA LA-98  * 0xa0  Contec C-NET(98)  * 0xb0  Contec C-NET(98)E/L  */
end_comment

begin_define
define|#
directive|define
name|ED_TYPE98_BASE
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_GENERIC
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_LPC
value|0x11
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_BDN
value|0x12
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_EGY
value|0x13
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_LGY
value|0x14
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_ICM
value|0x15
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_SIC
value|0x16
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_108
value|0x18
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_LA98
value|0x19
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_CNET98
value|0x1a
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_CNET98EL
value|0x1b
end_define

begin_define
define|#
directive|define
name|ED_TYPE98_UE2212
value|0x1c
end_define

begin_define
define|#
directive|define
name|ED_TYPE98
parameter_list|(
name|x
parameter_list|)
value|(((x& 0xffff0000)>> 20) | ED_TYPE98_BASE)
end_define

begin_define
define|#
directive|define
name|ED_TYPE98SUB
parameter_list|(
name|x
parameter_list|)
value|((x& 0xf0000)>> 16)
end_define

begin_comment
comment|/*  * Page 0 register offsets  */
end_comment

begin_undef
undef|#
directive|undef
name|ED_P0_CR
end_undef

begin_define
define|#
directive|define
name|ED_P0_CR
value|sc->edreg.port[0x00]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_CLDA0
end_undef

begin_define
define|#
directive|define
name|ED_P0_CLDA0
value|sc->edreg.port[0x01]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_PSTART
end_undef

begin_define
define|#
directive|define
name|ED_P0_PSTART
value|sc->edreg.port[0x01]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_CLDA1
end_undef

begin_define
define|#
directive|define
name|ED_P0_CLDA1
value|sc->edreg.port[0x02]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_PSTOP
end_undef

begin_define
define|#
directive|define
name|ED_P0_PSTOP
value|sc->edreg.port[0x02]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_BNRY
end_undef

begin_define
define|#
directive|define
name|ED_P0_BNRY
value|sc->edreg.port[0x03]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_TSR
end_undef

begin_define
define|#
directive|define
name|ED_P0_TSR
value|sc->edreg.port[0x04]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_TPSR
end_undef

begin_define
define|#
directive|define
name|ED_P0_TPSR
value|sc->edreg.port[0x04]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_NCR
end_undef

begin_define
define|#
directive|define
name|ED_P0_NCR
value|sc->edreg.port[0x05]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_TBCR0
end_undef

begin_define
define|#
directive|define
name|ED_P0_TBCR0
value|sc->edreg.port[0x05]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_FIFO
end_undef

begin_define
define|#
directive|define
name|ED_P0_FIFO
value|sc->edreg.port[0x06]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_TBCR1
end_undef

begin_define
define|#
directive|define
name|ED_P0_TBCR1
value|sc->edreg.port[0x06]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_ISR
end_undef

begin_define
define|#
directive|define
name|ED_P0_ISR
value|sc->edreg.port[0x07]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_CRDA0
end_undef

begin_define
define|#
directive|define
name|ED_P0_CRDA0
value|sc->edreg.port[0x08]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_RSAR0
end_undef

begin_define
define|#
directive|define
name|ED_P0_RSAR0
value|sc->edreg.port[0x08]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_CRDA1
end_undef

begin_define
define|#
directive|define
name|ED_P0_CRDA1
value|sc->edreg.port[0x09]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_RSAR1
end_undef

begin_define
define|#
directive|define
name|ED_P0_RSAR1
value|sc->edreg.port[0x09]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_RBCR0
end_undef

begin_define
define|#
directive|define
name|ED_P0_RBCR0
value|sc->edreg.port[0x0a]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_RBCR1
end_undef

begin_define
define|#
directive|define
name|ED_P0_RBCR1
value|sc->edreg.port[0x0b]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_RSR
end_undef

begin_define
define|#
directive|define
name|ED_P0_RSR
value|sc->edreg.port[0x0c]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_RCR
end_undef

begin_define
define|#
directive|define
name|ED_P0_RCR
value|sc->edreg.port[0x0c]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_CNTR0
end_undef

begin_define
define|#
directive|define
name|ED_P0_CNTR0
value|sc->edreg.port[0x0d]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_TCR
end_undef

begin_define
define|#
directive|define
name|ED_P0_TCR
value|sc->edreg.port[0x0d]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_CNTR1
end_undef

begin_define
define|#
directive|define
name|ED_P0_CNTR1
value|sc->edreg.port[0x0e]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_DCR
end_undef

begin_define
define|#
directive|define
name|ED_P0_DCR
value|sc->edreg.port[0x0e]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_CNTR2
end_undef

begin_define
define|#
directive|define
name|ED_P0_CNTR2
value|sc->edreg.port[0x0f]
end_define

begin_undef
undef|#
directive|undef
name|ED_P0_IMR
end_undef

begin_define
define|#
directive|define
name|ED_P0_IMR
value|sc->edreg.port[0x0f]
end_define

begin_comment
comment|/*  * Page 1 register offsets  */
end_comment

begin_undef
undef|#
directive|undef
name|ED_P1_CR
end_undef

begin_define
define|#
directive|define
name|ED_P1_CR
value|sc->edreg.port[0x00]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_PAR0
end_undef

begin_define
define|#
directive|define
name|ED_P1_PAR0
value|sc->edreg.port[0x01]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_PAR1
end_undef

begin_define
define|#
directive|define
name|ED_P1_PAR1
value|sc->edreg.port[0x02]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_PAR2
end_undef

begin_define
define|#
directive|define
name|ED_P1_PAR2
value|sc->edreg.port[0x03]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_PAR3
end_undef

begin_define
define|#
directive|define
name|ED_P1_PAR3
value|sc->edreg.port[0x04]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_PAR4
end_undef

begin_define
define|#
directive|define
name|ED_P1_PAR4
value|sc->edreg.port[0x05]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_PAR5
end_undef

begin_define
define|#
directive|define
name|ED_P1_PAR5
value|sc->edreg.port[0x06]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_CURR
end_undef

begin_define
define|#
directive|define
name|ED_P1_CURR
value|sc->edreg.port[0x07]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_MAR0
end_undef

begin_define
define|#
directive|define
name|ED_P1_MAR0
value|sc->edreg.port[0x08]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_MAR1
end_undef

begin_define
define|#
directive|define
name|ED_P1_MAR1
value|sc->edreg.port[0x09]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_MAR2
end_undef

begin_define
define|#
directive|define
name|ED_P1_MAR2
value|sc->edreg.port[0x0a]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_MAR3
end_undef

begin_define
define|#
directive|define
name|ED_P1_MAR3
value|sc->edreg.port[0x0b]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_MAR4
end_undef

begin_define
define|#
directive|define
name|ED_P1_MAR4
value|sc->edreg.port[0x0c]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_MAR5
end_undef

begin_define
define|#
directive|define
name|ED_P1_MAR5
value|sc->edreg.port[0x0d]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_MAR6
end_undef

begin_define
define|#
directive|define
name|ED_P1_MAR6
value|sc->edreg.port[0x0e]
end_define

begin_undef
undef|#
directive|undef
name|ED_P1_MAR7
end_undef

begin_define
define|#
directive|define
name|ED_P1_MAR7
value|sc->edreg.port[0x0f]
end_define

begin_comment
comment|/*  * Page 2 register offsets  */
end_comment

begin_undef
undef|#
directive|undef
name|ED_P2_CR
end_undef

begin_define
define|#
directive|define
name|ED_P2_CR
value|sc->edreg.port[0x00]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_PSTART
end_undef

begin_define
define|#
directive|define
name|ED_P2_PSTART
value|sc->edreg.port[0x01]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_CLDA0
end_undef

begin_define
define|#
directive|define
name|ED_P2_CLDA0
value|sc->edreg.port[0x01]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_PSTOP
end_undef

begin_define
define|#
directive|define
name|ED_P2_PSTOP
value|sc->edreg.port[0x02]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_CLDA1
end_undef

begin_define
define|#
directive|define
name|ED_P2_CLDA1
value|sc->edreg.port[0x02]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_RNPP
end_undef

begin_define
define|#
directive|define
name|ED_P2_RNPP
value|sc->edreg.port[0x03]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_TPSR
end_undef

begin_define
define|#
directive|define
name|ED_P2_TPSR
value|sc->edreg.port[0x04]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_LNPP
end_undef

begin_define
define|#
directive|define
name|ED_P2_LNPP
value|sc->edreg.port[0x05]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_ACU
end_undef

begin_define
define|#
directive|define
name|ED_P2_ACU
value|sc->edreg.port[0x06]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_ACL
end_undef

begin_define
define|#
directive|define
name|ED_P2_ACL
value|sc->edreg.port[0x07]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_RCR
end_undef

begin_define
define|#
directive|define
name|ED_P2_RCR
value|sc->edreg.port[0x0c]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_TCR
end_undef

begin_define
define|#
directive|define
name|ED_P2_TCR
value|sc->edreg.port[0x0d]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_DCR
end_undef

begin_define
define|#
directive|define
name|ED_P2_DCR
value|sc->edreg.port[0x0e]
end_define

begin_undef
undef|#
directive|undef
name|ED_P2_IMR
end_undef

begin_define
define|#
directive|define
name|ED_P2_IMR
value|sc->edreg.port[0x0f]
end_define

begin_comment
comment|/* PCCARD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ED_PC_MISC
end_ifdef

begin_undef
undef|#
directive|undef
name|ED_PC_MISC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ED_PC_MISC
value|sc->edreg.pc_misc
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ED_PC_RESET
end_ifdef

begin_undef
undef|#
directive|undef
name|ED_PC_RESET
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ED_PC_RESET
value|sc->edreg.pc_reset
end_define

begin_comment
comment|/* LPC-T support */
end_comment

begin_define
define|#
directive|define
name|LPCT_1d0_ON
parameter_list|()
define|\
value|{ \ 	outb(0x2a8e, 0x84); \ 	outw(0x4a8e, 0x1d0); \ 	outw(0x5a8e, 0x0310); \ }
end_define

begin_define
define|#
directive|define
name|LPCT_1d0_OFF
parameter_list|()
define|\
value|{ \ 	outb(0x2a8e, 0xa4); \ 	outw(0x4a8e, 0xd0); \ 	outw(0x5a8e, 0x0300); \ }
end_define

begin_comment
comment|/*  * C-NET(98)  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_INIT_ADDR
value|0xaaed
end_define

begin_comment
comment|/* 0xaaed reset register  */
end_comment

begin_comment
comment|/* 0xaaef i/o address set */
end_comment

begin_comment
comment|/* offset NIC address */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_MAP_REG0L
value|1
end_define

begin_comment
comment|/* MAPPING register0 Low  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_MAP_REG1L
value|3
end_define

begin_comment
comment|/* MAPPING register1 Low  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_MAP_REG2L
value|5
end_define

begin_comment
comment|/* MAPPING register2 Low  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_MAP_REG3L
value|7
end_define

begin_comment
comment|/* MAPPING register3 Low  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_MAP_REG0H
value|9
end_define

begin_comment
comment|/* MAPPING register0 Hi   */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_MAP_REG1H
value|11
end_define

begin_comment
comment|/* MAPPING register1 Hi   */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_MAP_REG2H
value|13
end_define

begin_comment
comment|/* MAPPING register2 Hi   */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_MAP_REG3H
value|15
end_define

begin_comment
comment|/* MAPPING register3 Hi   */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_WIN_REG
value|(0x400 +  1)
end_define

begin_comment
comment|/* window register        */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_INT_LEV
value|(0x400 +  3)
end_define

begin_comment
comment|/* init level register    */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_INT_REQ
value|(0x400 +  5)
end_define

begin_comment
comment|/* init request register  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_INT_MASK
value|(0x400 +  7)
end_define

begin_comment
comment|/* init mask register     */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_INT_STAT
value|(0x400 +  9)
end_define

begin_comment
comment|/* init status register   */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_INT_CLR
value|(0x400 +  9)
end_define

begin_comment
comment|/* init clear register    */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98_RESERVE1
value|(0x400 + 11)
end_define

begin_define
define|#
directive|define
name|ED_CNET98_RESERVE2
value|(0x400 + 13)
end_define

begin_define
define|#
directive|define
name|ED_CNET98_RESERVE3
value|(0x400 + 15)
end_define

begin_comment
comment|/*  * C-NET(98)E/L  */
end_comment

begin_comment
comment|/*  * NIC Initial Register(on board JP1)  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_INIT
value|0xaaed
end_define

begin_define
define|#
directive|define
name|ED_CNET98EL_INIT2
value|0x55ed
end_define

begin_define
define|#
directive|define
name|ED_CNET98EL_NIC_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|ED_CNET98EL_ASIC_OFFSET
value|0x400
end_define

begin_comment
comment|/* offset to nic i/o regs */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_PAGE_OFFSET
value|0x0000
end_define

begin_comment
comment|/* page offset for NIC access to mem */
end_comment

begin_comment
comment|/*  * XXX - The I/O address range is fragmented in the CNET98E/L; this is the  *    number of regs at iobase.  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_IO_PORTS
value|16
end_define

begin_comment
comment|/* # of i/o addresses used */
end_comment

begin_comment
comment|/*  *    Interrupt Configuration Register (offset from ASIC base)  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_ICR
value|0x02
end_define

begin_define
define|#
directive|define
name|ED_CNET98EL_ICR_IRQ3
value|0x01
end_define

begin_comment
comment|/* Interrupt request 3 select */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_ICR_IRQ5
value|0x02
end_define

begin_comment
comment|/* Interrupt request 5 select */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_ICR_IRQ6
value|0x04
end_define

begin_comment
comment|/* Interrupt request 6 select */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_ICR_IRQ12
value|0x20
end_define

begin_comment
comment|/* Interrupt request 12 select */
end_comment

begin_comment
comment|/*  *    Interrupt Mask Register (offset from ASIC base)  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_IMR
value|0x04
end_define

begin_comment
comment|/*  *    Interrupt Status Register (offset from ASIC base)  */
end_comment

begin_define
define|#
directive|define
name|ED_CNET98EL_ISR
value|0x05
end_define

begin_comment
comment|/* NE2000, LGY-98, ICM, LPC-T, C-NET(98)E/L */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|edp_generic
index|[
literal|16
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EGY-98 */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|edp_egy98
index|[
literal|16
index|]
init|=
block|{
literal|0
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x06
block|,
literal|0x08
block|,
literal|0x0a
block|,
literal|0x0c
block|,
literal|0x0e
block|,
literal|0x100
block|,
literal|0x102
block|,
literal|0x104
block|,
literal|0x106
block|,
literal|0x108
block|,
literal|0x10a
block|,
literal|0x10c
block|,
literal|0x10e
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LD-BDN */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|edp_bdn98
index|[
literal|16
index|]
init|=
block|{
literal|0x00000
block|,
literal|0x01000
block|,
literal|0x02000
block|,
literal|0x03000
block|,
literal|0x04000
block|,
literal|0x05000
block|,
literal|0x06000
block|,
literal|0x07000
block|,
literal|0x08000
block|,
literal|0x0a000
block|,
literal|0x0b000
block|,
literal|0x0c000
block|,
literal|0x0d000
block|,
literal|0x0d000
block|,
literal|0x0e000
block|,
literal|0x0f000
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SIC-98 */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|edp_sic98
index|[
literal|16
index|]
init|=
block|{
literal|0x0000
block|,
literal|0x0200
block|,
literal|0x0400
block|,
literal|0x0600
block|,
literal|0x0800
block|,
literal|0x0a00
block|,
literal|0x0c00
block|,
literal|0x0e00
block|,
literal|0x1000
block|,
literal|0x1200
block|,
literal|0x1400
block|,
literal|0x1600
block|,
literal|0x1800
block|,
literal|0x1a00
block|,
literal|0x1c00
block|,
literal|0x1e00
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IO-DATA LA-98 */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|edp_la98
index|[
literal|16
index|]
init|=
block|{
literal|0x0000
block|,
literal|0x1000
block|,
literal|0x2000
block|,
literal|0x3000
block|,
literal|0x4000
block|,
literal|0x5000
block|,
literal|0x6000
block|,
literal|0x7000
block|,
literal|0x8000
block|,
literal|0x9000
block|,
literal|0xa000
block|,
literal|0xb000
block|,
literal|0xc000
block|,
literal|0xd000
block|,
literal|0xe000
block|,
literal|0xf000
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NEC PC-9801-108 */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|edp_nec108
index|[
literal|16
index|]
init|=
block|{
literal|0x0000
block|,
literal|0x0002
block|,
literal|0x0004
block|,
literal|0x0006
block|,
literal|0x0008
block|,
literal|0x000a
block|,
literal|0x000c
block|,
literal|0x000e
block|,
literal|0x1000
block|,
literal|0x1002
block|,
literal|0x1004
block|,
literal|0x1006
block|,
literal|0x1008
block|,
literal|0x100a
block|,
literal|0x100c
block|,
literal|0x100e
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Contec C-NET(98) */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|edp_cnet98
index|[
literal|16
index|]
init|=
block|{
literal|0x0000
block|,
literal|0x0002
block|,
literal|0x0004
block|,
literal|0x0006
block|,
literal|0x0008
block|,
literal|0x000a
block|,
literal|0x000c
block|,
literal|0x000e
block|,
literal|0x0400
block|,
literal|0x0402
block|,
literal|0x0404
block|,
literal|0x0406
block|,
literal|0x0408
block|,
literal|0x040a
block|,
literal|0x040c
block|,
literal|0x040e
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|pc98_set_register
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|int
name|type
parameter_list|)
block|{
name|struct
name|ed_softc
modifier|*
name|sc
init|=
operator|&
name|ed_softc
index|[
name|dev
operator|->
name|id_unit
index|]
decl_stmt|;
name|int
name|adj
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|ED_TYPE98_GENERIC
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_generic
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|1
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x0010
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|0x000f
expr_stmt|;
name|ED_PC_MISC
operator|=
literal|0x18
expr_stmt|;
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_LGY
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_generic
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|1
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x0200
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|0x0100
expr_stmt|;
name|ED_PC_MISC
operator|=
literal|0x18
expr_stmt|;
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_EGY
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_egy98
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|2
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x0200
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|0x0100
expr_stmt|;
name|ED_PC_MISC
operator|=
literal|0x18
expr_stmt|;
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_ICM
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_generic
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|1
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x0100
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|0x000f
expr_stmt|;
name|ED_PC_MISC
operator|=
literal|0x18
expr_stmt|;
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_BDN
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_bdn98
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|0x1000
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x0100
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|0xc100
expr_stmt|;
name|ED_PC_MISC
operator|=
literal|0x18
expr_stmt|;
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_SIC
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_sic98
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|0x200
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x2000
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0x00
expr_stmt|;
comment|/* dummy */
name|ED_NOVELL_RESET
operator|=
literal|0x00
expr_stmt|;
name|ED_PC_MISC
operator|=
literal|0x18
expr_stmt|;
comment|/* dummy */
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
comment|/* dummy */
break|break;
case|case
name|ED_TYPE98_LPC
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_generic
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|0x1
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x0100
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|0x0200
expr_stmt|;
name|ED_PC_MISC
operator|=
literal|0x108
expr_stmt|;
name|ED_PC_RESET
operator|=
literal|0x10f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_108
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_nec108
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|2
expr_stmt|;
name|adj
operator|=
operator|(
name|dev
operator|->
name|id_iobase
operator|&
literal|0xf000
operator|)
operator|/
literal|2
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
operator|(
literal|0x888
operator||
name|adj
operator|)
operator|-
name|dev
operator|->
name|id_iobase
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|4
expr_stmt|;
name|ED_PC_MISC
operator|=
literal|0x18
expr_stmt|;
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_LA98
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_la98
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|0x1000
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x100
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0x0000
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|0xf000
expr_stmt|;
name|ED_PC_MISC
operator|=
literal|0x18
expr_stmt|;
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_CNET98EL
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_generic
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|1
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x0400
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0x000e
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|0x0000
expr_stmt|;
comment|/* dummy */
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_CNET98
case|:
name|sc
operator|->
name|edreg
operator|.
name|port
operator|=
name|edp_cnet98
expr_stmt|;
name|sc
operator|->
name|edreg
operator|.
name|ioskip
operator|=
literal|2
expr_stmt|;
name|ED_NOVELL_NIC_OFFSET
operator|=
literal|0
expr_stmt|;
name|ED_NOVELL_ASIC_OFFSET
operator|=
literal|0x0400
expr_stmt|;
name|ED_NOVELL_DATA
operator|=
literal|0x000e
expr_stmt|;
name|ED_NOVELL_RESET
operator|=
literal|0x0000
expr_stmt|;
comment|/* dummy */
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PC98_PC98_IF_ED98_H__ */
end_comment

end_unit

