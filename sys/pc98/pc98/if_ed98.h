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
name|unit
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
value|ed_novell_nic_offset[unit]
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
value|ed_novell_asic_offset[unit]
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
value|ed_novell_data[unit]
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
value|ed_novell_reset[unit]
end_define

begin_comment
comment|/*  * Card type  *  * Type  Card  *   0   Allied Telesis CenterCom LA-98-T  *   1   MELCO LPC-TJ, LPC-TS / IO-DATA PCLA/T  *   2   PLANET SMART COM 98 EN-2298 / ELECOM LANEED LD-BDN[123]A  *   3   MELCO EGY-98  *   4   MELCO LGY-98, IND-SP, IND-SS / MACNICA NE2098(XXX)  *   5   ICM DT-ET-25, DT-ET-T5, IF-2766ET, IF-2771ET /  *       D-Link DE-298P{T,CAT}, DE-298{T,TP,CAT}  *   6   Allied Telesis SIC-98  *   8   NEC PC-9801-108  *   9   IO-DATA LA-98  */
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
name|ED_TYPE98
parameter_list|(
name|x
parameter_list|)
value|(((x->id_flags& 0xffff0000)>> 16) | ED_TYPE98_BASE)
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
value|edp[unit][0x00]
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
value|edp[unit][0x01]
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
value|edp[unit][0x01]
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
value|edp[unit][0x02]
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
value|edp[unit][0x02]
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
value|edp[unit][0x03]
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
value|edp[unit][0x04]
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
value|edp[unit][0x04]
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
value|edp[unit][0x05]
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
value|edp[unit][0x05]
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
value|edp[unit][0x06]
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
value|edp[unit][0x06]
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
value|edp[unit][0x07]
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
value|edp[unit][0x08]
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
value|edp[unit][0x08]
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
value|edp[unit][0x09]
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
value|edp[unit][0x09]
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
value|edp[unit][0x0a]
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
value|edp[unit][0x0b]
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
value|edp[unit][0x0c]
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
value|edp[unit][0x0c]
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
value|edp[unit][0x0d]
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
value|edp[unit][0x0d]
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
value|edp[unit][0x0e]
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
value|edp[unit][0x0e]
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
value|edp[unit][0x0f]
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
value|edp[unit][0x0f]
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
value|edp[unit][0x00]
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
value|edp[unit][0x01]
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
value|edp[unit][0x02]
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
value|edp[unit][0x03]
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
value|edp[unit][0x04]
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
value|edp[unit][0x05]
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
value|edp[unit][0x06]
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
value|edp[unit][0x07]
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
value|edp[unit][0x08]
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
value|edp[unit][0x09]
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
value|edp[unit][0x0a]
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
value|edp[unit][0x0b]
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
value|edp[unit][0x0c]
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
value|edp[unit][0x0d]
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
value|edp[unit][0x0e]
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
value|edp[unit][0x0f]
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
value|edp[unit][0x00]
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
value|edp[unit][0x01]
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
value|edp[unit][0x01]
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
value|edp[unit][0x02]
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
value|edp[unit][0x02]
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
value|edp[unit][0x03]
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
value|edp[unit][0x04]
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
value|edp[unit][0x05]
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
value|edp[unit][0x06]
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
value|edp[unit][0x07]
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
value|edp[unit][0x0c]
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
value|edp[unit][0x0d]
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
value|edp[unit][0x0e]
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
value|edp[unit][0x0f]
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
value|ed_pc_misc[unit]
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
value|ed_pc_reset[unit]
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
comment|/* register offsets */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
modifier|*
name|edp
index|[
name|NED
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|pc98_io_skip
index|[
name|NED
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ed_novell_nic_offset
index|[
name|NED
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ed_novell_asic_offset
index|[
name|NED
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ed_novell_data
index|[
name|NED
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ed_novell_reset
index|[
name|NED
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ed_pc_misc
index|[
name|NED
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ed_pc_reset
index|[
name|NED
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NE2000, LGY-98, ICM, LPC-T */
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
name|unit
parameter_list|,
name|int
name|type
parameter_list|)
block|{
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
name|edp
index|[
name|unit
index|]
operator|=
name|edp_generic
expr_stmt|;
name|pc98_io_skip
index|[
name|unit
index|]
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
name|edp
index|[
name|unit
index|]
operator|=
name|edp_generic
expr_stmt|;
name|pc98_io_skip
index|[
name|unit
index|]
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
name|edp
index|[
name|unit
index|]
operator|=
name|edp_egy98
expr_stmt|;
name|pc98_io_skip
index|[
name|unit
index|]
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
name|edp
index|[
name|unit
index|]
operator|=
name|edp_generic
expr_stmt|;
name|pc98_io_skip
index|[
name|unit
index|]
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
name|edp
index|[
name|unit
index|]
operator|=
name|edp_bdn98
expr_stmt|;
name|pc98_io_skip
index|[
name|unit
index|]
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
name|edp
index|[
name|unit
index|]
operator|=
name|edp_sic98
expr_stmt|;
name|pc98_io_skip
index|[
name|unit
index|]
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
name|ED_PC_RESET
operator|=
literal|0x1f
expr_stmt|;
break|break;
case|case
name|ED_TYPE98_LPC
case|:
name|edp
index|[
name|unit
index|]
operator|=
name|edp_generic
expr_stmt|;
name|pc98_io_skip
index|[
name|unit
index|]
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
name|edp
index|[
name|unit
index|]
operator|=
name|edp_nec108
expr_stmt|;
name|pc98_io_skip
index|[
name|unit
index|]
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
name|edp
index|[
name|unit
index|]
operator|=
name|edp_la98
expr_stmt|;
name|pc98_io_skip
index|[
name|unit
index|]
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

