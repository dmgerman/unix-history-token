begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)bsd_audioreg.h	7.3 (Berkeley) %G%  *  * from: $Header: bsd_audioreg.h,v 1.3 92/06/07 21:12:50 mccanne Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Bit encodings for chip commands from "Microprocessor Access Guide for  * Indirect Registers", p.19 Am79C30A/32A Advanced Micro Devices spec   * sheet (preliminary).  *  * Indirect register numbers (the value written into cr to select a given  * chip registers) have the form AMDR_*.  Register fields look like AMD_*.  */
end_comment

begin_struct
struct|struct
name|amd7930
block|{
name|u_char
name|cr
decl_stmt|;
comment|/* command register (wo) */
define|#
directive|define
name|ir
value|cr
comment|/* interrupt register (ro) */
name|u_char
name|dr
decl_stmt|;
comment|/* data register (rw) */
name|u_char
name|dsr1
decl_stmt|;
comment|/* D-channel status register 1 (ro) */
name|u_char
name|der
decl_stmt|;
comment|/* D-channel error register (ro) */
name|u_char
name|dctb
decl_stmt|;
comment|/* D-channel transmit register (wo) */
define|#
directive|define
name|dcrb
value|dctb
comment|/* D-channel receive register (ro) */
name|u_char
name|bbtb
decl_stmt|;
comment|/* Bb-channel transmit register (wo) */
define|#
directive|define
name|bbrb
value|bbtb
comment|/* Bb-channel receive register (ro) */
name|u_char
name|bctb
decl_stmt|;
comment|/* Bc-channel transmit register (wo) */
define|#
directive|define
name|bcrb
value|bctb
comment|/* Bc-channel receive register (ro) */
name|u_char
name|dsr2
decl_stmt|;
comment|/* D-channel status register 2 (ro) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AMDR_INIT
value|0x21
end_define

begin_define
define|#
directive|define
name|AMD_INIT_PMS_IDLE
value|0x00
end_define

begin_define
define|#
directive|define
name|AMD_INIT_PMS_ACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|AMD_INIT_PMS_ACTIVE_DATA
value|0x02
end_define

begin_define
define|#
directive|define
name|AMD_INIT_INT_DISABLE
value|(0x01<< 2)
end_define

begin_define
define|#
directive|define
name|AMD_INIT_CDS_DIV2
value|(0x00<< 3)
end_define

begin_define
define|#
directive|define
name|AMD_INIT_CDS_DIV1
value|(0x01<< 3)
end_define

begin_define
define|#
directive|define
name|AMD_INIT_CDS_DIV4
value|(0x02<< 3)
end_define

begin_define
define|#
directive|define
name|AMD_INIT_AS_RX
value|(0x01<< 6)
end_define

begin_define
define|#
directive|define
name|AMD_INIT_AS_TX
value|(0x01<< 7)
end_define

begin_define
define|#
directive|define
name|AMDR_LIU_LSR
value|0xa1
end_define

begin_define
define|#
directive|define
name|AMDR_LIU_LPR
value|0xa2
end_define

begin_define
define|#
directive|define
name|AMDR_LIU_LMR1
value|0xa3
end_define

begin_define
define|#
directive|define
name|AMDR_LIU_LMR2
value|0xa4
end_define

begin_define
define|#
directive|define
name|AMDR_LIU_2_4
value|0xa5
end_define

begin_define
define|#
directive|define
name|AMDR_LIU_MF
value|0xa6
end_define

begin_define
define|#
directive|define
name|AMDR_LIU_MFSB
value|0xa7
end_define

begin_define
define|#
directive|define
name|AMDR_LIU_MFQB
value|0xa8
end_define

begin_define
define|#
directive|define
name|AMDR_MUX_MCR1
value|0x41
end_define

begin_define
define|#
directive|define
name|AMDR_MUX_MCR2
value|0x42
end_define

begin_define
define|#
directive|define
name|AMDR_MUX_MCR3
value|0x43
end_define

begin_define
define|#
directive|define
name|AMD_MCRCHAN_NC
value|0x00
end_define

begin_define
define|#
directive|define
name|AMD_MCRCHAN_B1
value|0x01
end_define

begin_define
define|#
directive|define
name|AMD_MCRCHAN_B2
value|0x02
end_define

begin_define
define|#
directive|define
name|AMD_MCRCHAN_BA
value|0x03
end_define

begin_define
define|#
directive|define
name|AMD_MCRCHAN_BB
value|0x04
end_define

begin_define
define|#
directive|define
name|AMD_MCRCHAN_BC
value|0x05
end_define

begin_define
define|#
directive|define
name|AMD_MCRCHAN_BD
value|0x06
end_define

begin_define
define|#
directive|define
name|AMD_MCRCHAN_BE
value|0x07
end_define

begin_define
define|#
directive|define
name|AMD_MCRCHAN_BF
value|0x08
end_define

begin_define
define|#
directive|define
name|AMDR_MUX_MCR4
value|0x44
end_define

begin_define
define|#
directive|define
name|AMD_MCR4_INT_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AMD_MCR4_SWAPBB
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AMD_MCR4_SWAPBC
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AMDR_MUX_1_4
value|0x45
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_X
value|0x61
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_R
value|0x62
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_GX
value|0x63
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_GR
value|0x64
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_GER
value|0x65
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_STG
value|0x66
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_FTGR
value|0x67
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_ATGR
value|0x68
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_MMR1
value|0x69
end_define

begin_define
define|#
directive|define
name|AMD_MMR1_ALAW
value|0x01
end_define

begin_define
define|#
directive|define
name|AMD_MMR1_GX
value|0x02
end_define

begin_define
define|#
directive|define
name|AMD_MMR1_GR
value|0x04
end_define

begin_define
define|#
directive|define
name|AMD_MMR1_GER
value|0x08
end_define

begin_define
define|#
directive|define
name|AMD_MMR1_X
value|0x10
end_define

begin_define
define|#
directive|define
name|AMD_MMR1_R
value|0x20
end_define

begin_define
define|#
directive|define
name|AMD_MMR1_STG
value|0x40
end_define

begin_define
define|#
directive|define
name|AMD_MMR1_LOOP
value|0x80
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_MMR2
value|0x6a
end_define

begin_define
define|#
directive|define
name|AMD_MMR2_AINB
value|0x01
end_define

begin_define
define|#
directive|define
name|AMD_MMR2_LS
value|0x02
end_define

begin_define
define|#
directive|define
name|AMD_MMR2_DTMF
value|0x04
end_define

begin_define
define|#
directive|define
name|AMD_MMR2_GEN
value|0x08
end_define

begin_define
define|#
directive|define
name|AMD_MMR2_RNG
value|0x10
end_define

begin_define
define|#
directive|define
name|AMD_MMR2_DIS_HPF
value|0x20
end_define

begin_define
define|#
directive|define
name|AMD_MMR2_DIS_AZ
value|0x40
end_define

begin_define
define|#
directive|define
name|AMDR_MAP_1_10
value|0x6b
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_FRAR123
value|0x81
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_SRAR123
value|0x82
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_TAR
value|0x83
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_DRLR
value|0x84
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_DTCR
value|0x85
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_DMR1
value|0x86
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_DMR2
value|0x87
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_1_7
value|0x88
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_DRCR
value|0x89
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_RNGR1
value|0x8a
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_RNGR2
value|0x8b
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_FRAR4
value|0x8c
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_SRAR4
value|0x8d
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_DMR3
value|0x8e
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_DMR4
value|0x8f
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_12_15
value|0x90
end_define

begin_define
define|#
directive|define
name|AMDR_DLC_ASR
value|0x91
end_define

end_unit

