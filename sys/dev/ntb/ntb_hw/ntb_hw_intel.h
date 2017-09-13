begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Alexander Motin<mav@FreeBSD.org>  * Copyright (C) 2013 Intel Corporation  * Copyright (C) 2015 EMC Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NTB_REGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NTB_REGS_H_
end_define

begin_define
define|#
directive|define
name|NTB_LINK_STATUS_ACTIVE
value|0x2000
end_define

begin_define
define|#
directive|define
name|NTB_LINK_SPEED_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|NTB_LINK_WIDTH_MASK
value|0x03f0
end_define

begin_define
define|#
directive|define
name|NTB_LNK_STA_WIDTH
parameter_list|(
name|sta
parameter_list|)
value|(((sta)& NTB_LINK_WIDTH_MASK)>> 4)
end_define

begin_define
define|#
directive|define
name|XEON_SNB_MW_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XEON_HSX_SPLIT_MW_COUNT
value|3
end_define

begin_comment
comment|/* Reserve the uppermost bit for link interrupt */
end_comment

begin_define
define|#
directive|define
name|XEON_DB_COUNT
value|15
end_define

begin_define
define|#
directive|define
name|XEON_DB_TOTAL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|XEON_DB_LINK
value|15
end_define

begin_define
define|#
directive|define
name|XEON_DB_MSIX_VECTOR_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|XEON_DB_MSIX_VECTOR_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|XEON_DB_LINK_BIT
value|(1<< XEON_DB_LINK)
end_define

begin_define
define|#
directive|define
name|XEON_NONLINK_DB_MSIX_BITS
value|3
end_define

begin_define
define|#
directive|define
name|XEON_SPCICMD_OFFSET
value|0x0504
end_define

begin_define
define|#
directive|define
name|XEON_DEVCTRL_OFFSET
value|0x0598
end_define

begin_define
define|#
directive|define
name|XEON_DEVSTS_OFFSET
value|0x059a
end_define

begin_define
define|#
directive|define
name|XEON_LINK_STATUS_OFFSET
value|0x01a2
end_define

begin_define
define|#
directive|define
name|XEON_SLINK_STATUS_OFFSET
value|0x05a2
end_define

begin_define
define|#
directive|define
name|XEON_PBAR2LMT_OFFSET
value|0x0000
end_define

begin_define
define|#
directive|define
name|XEON_PBAR4LMT_OFFSET
value|0x0008
end_define

begin_define
define|#
directive|define
name|XEON_PBAR5LMT_OFFSET
value|0x000c
end_define

begin_define
define|#
directive|define
name|XEON_PBAR2XLAT_OFFSET
value|0x0010
end_define

begin_define
define|#
directive|define
name|XEON_PBAR4XLAT_OFFSET
value|0x0018
end_define

begin_define
define|#
directive|define
name|XEON_PBAR5XLAT_OFFSET
value|0x001c
end_define

begin_define
define|#
directive|define
name|XEON_SBAR2LMT_OFFSET
value|0x0020
end_define

begin_define
define|#
directive|define
name|XEON_SBAR4LMT_OFFSET
value|0x0028
end_define

begin_define
define|#
directive|define
name|XEON_SBAR5LMT_OFFSET
value|0x002c
end_define

begin_define
define|#
directive|define
name|XEON_SBAR2XLAT_OFFSET
value|0x0030
end_define

begin_define
define|#
directive|define
name|XEON_SBAR4XLAT_OFFSET
value|0x0038
end_define

begin_define
define|#
directive|define
name|XEON_SBAR5XLAT_OFFSET
value|0x003c
end_define

begin_define
define|#
directive|define
name|XEON_SBAR0BASE_OFFSET
value|0x0040
end_define

begin_define
define|#
directive|define
name|XEON_SBAR2BASE_OFFSET
value|0x0048
end_define

begin_define
define|#
directive|define
name|XEON_SBAR4BASE_OFFSET
value|0x0050
end_define

begin_define
define|#
directive|define
name|XEON_SBAR5BASE_OFFSET
value|0x0054
end_define

begin_define
define|#
directive|define
name|XEON_NTBCNTL_OFFSET
value|0x0058
end_define

begin_define
define|#
directive|define
name|XEON_SBDF_OFFSET
value|0x005c
end_define

begin_define
define|#
directive|define
name|XEON_PDOORBELL_OFFSET
value|0x0060
end_define

begin_define
define|#
directive|define
name|XEON_PDBMSK_OFFSET
value|0x0062
end_define

begin_define
define|#
directive|define
name|XEON_SDOORBELL_OFFSET
value|0x0064
end_define

begin_define
define|#
directive|define
name|XEON_SDBMSK_OFFSET
value|0x0066
end_define

begin_define
define|#
directive|define
name|XEON_USMEMMISS_OFFSET
value|0x0070
end_define

begin_define
define|#
directive|define
name|XEON_SPAD_OFFSET
value|0x0080
end_define

begin_define
define|#
directive|define
name|XEON_SPAD_COUNT
value|16
end_define

begin_define
define|#
directive|define
name|XEON_SPADSEMA4_OFFSET
value|0x00c0
end_define

begin_define
define|#
directive|define
name|XEON_WCCNTRL_OFFSET
value|0x00e0
end_define

begin_define
define|#
directive|define
name|XEON_UNCERRSTS_OFFSET
value|0x014c
end_define

begin_define
define|#
directive|define
name|XEON_CORERRSTS_OFFSET
value|0x0158
end_define

begin_define
define|#
directive|define
name|XEON_B2B_SPAD_OFFSET
value|0x0100
end_define

begin_define
define|#
directive|define
name|XEON_B2B_DOORBELL_OFFSET
value|0x0140
end_define

begin_define
define|#
directive|define
name|XEON_B2B_XLAT_OFFSETL
value|0x0144
end_define

begin_define
define|#
directive|define
name|XEON_B2B_XLAT_OFFSETU
value|0x0148
end_define

begin_define
define|#
directive|define
name|ATOM_MW_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_DB_COUNT
value|34
end_define

begin_define
define|#
directive|define
name|ATOM_DB_MSIX_VECTOR_COUNT
value|34
end_define

begin_define
define|#
directive|define
name|ATOM_DB_MSIX_VECTOR_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_SPCICMD_OFFSET
value|0xb004
end_define

begin_define
define|#
directive|define
name|ATOM_MBAR23_OFFSET
value|0xb018
end_define

begin_define
define|#
directive|define
name|ATOM_MBAR45_OFFSET
value|0xb020
end_define

begin_define
define|#
directive|define
name|ATOM_DEVCTRL_OFFSET
value|0xb048
end_define

begin_define
define|#
directive|define
name|ATOM_LINK_STATUS_OFFSET
value|0xb052
end_define

begin_define
define|#
directive|define
name|ATOM_ERRCORSTS_OFFSET
value|0xb110
end_define

begin_define
define|#
directive|define
name|ATOM_SBAR2XLAT_OFFSET
value|0x0008
end_define

begin_define
define|#
directive|define
name|ATOM_SBAR4XLAT_OFFSET
value|0x0010
end_define

begin_define
define|#
directive|define
name|ATOM_PDOORBELL_OFFSET
value|0x0020
end_define

begin_define
define|#
directive|define
name|ATOM_PDBMSK_OFFSET
value|0x0028
end_define

begin_define
define|#
directive|define
name|ATOM_NTBCNTL_OFFSET
value|0x0060
end_define

begin_define
define|#
directive|define
name|ATOM_EBDF_OFFSET
value|0x0064
end_define

begin_define
define|#
directive|define
name|ATOM_SPAD_OFFSET
value|0x0080
end_define

begin_define
define|#
directive|define
name|ATOM_SPAD_COUNT
value|16
end_define

begin_define
define|#
directive|define
name|ATOM_SPADSEMA_OFFSET
value|0x00c0
end_define

begin_define
define|#
directive|define
name|ATOM_STKYSPAD_OFFSET
value|0x00c4
end_define

begin_define
define|#
directive|define
name|ATOM_PBAR2XLAT_OFFSET
value|0x8008
end_define

begin_define
define|#
directive|define
name|ATOM_PBAR4XLAT_OFFSET
value|0x8010
end_define

begin_define
define|#
directive|define
name|ATOM_B2B_DOORBELL_OFFSET
value|0x8020
end_define

begin_define
define|#
directive|define
name|ATOM_B2B_SPAD_OFFSET
value|0x8080
end_define

begin_define
define|#
directive|define
name|ATOM_B2B_SPADSEMA_OFFSET
value|0x80c0
end_define

begin_define
define|#
directive|define
name|ATOM_B2B_STKYSPAD_OFFSET
value|0x80c4
end_define

begin_define
define|#
directive|define
name|ATOM_MODPHY_PCSREG4
value|0x1c004
end_define

begin_define
define|#
directive|define
name|ATOM_MODPHY_PCSREG6
value|0x1c006
end_define

begin_define
define|#
directive|define
name|ATOM_IP_BASE
value|0xc000
end_define

begin_define
define|#
directive|define
name|ATOM_DESKEWSTS_OFFSET
value|(ATOM_IP_BASE + 0x3024)
end_define

begin_define
define|#
directive|define
name|ATOM_LTSSMERRSTS0_OFFSET
value|(ATOM_IP_BASE + 0x3180)
end_define

begin_define
define|#
directive|define
name|ATOM_LTSSMSTATEJMP_OFFSET
value|(ATOM_IP_BASE + 0x3040)
end_define

begin_define
define|#
directive|define
name|ATOM_IBSTERRRCRVSTS0_OFFSET
value|(ATOM_IP_BASE + 0x3324)
end_define

begin_define
define|#
directive|define
name|ATOM_DESKEWSTS_DBERR
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|ATOM_LTSSMERRSTS0_UNEXPECTEDEI
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|ATOM_LTSSMSTATEJMP_FORCEDETECT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATOM_IBIST_ERR_OFLOW
value|0x7fff7fff
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_CFG_LOCK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_LINK_DISABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_S2P_BAR23_SNOOP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_P2S_BAR23_SNOOP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_S2P_BAR4_SNOOP
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_P2S_BAR4_SNOOP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_S2P_BAR5_SNOOP
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_P2S_BAR5_SNOOP
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|ATOM_CNTL_LINK_DOWN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|XEON_PBAR23SZ_OFFSET
value|0x00d0
end_define

begin_define
define|#
directive|define
name|XEON_PBAR45SZ_OFFSET
value|0x00d1
end_define

begin_define
define|#
directive|define
name|XEON_PBAR4SZ_OFFSET
value|0x00d1
end_define

begin_define
define|#
directive|define
name|XEON_PBAR5SZ_OFFSET
value|0x00d5
end_define

begin_define
define|#
directive|define
name|XEON_SBAR23SZ_OFFSET
value|0x00d2
end_define

begin_define
define|#
directive|define
name|XEON_SBAR4SZ_OFFSET
value|0x00d3
end_define

begin_define
define|#
directive|define
name|XEON_SBAR5SZ_OFFSET
value|0x00d6
end_define

begin_define
define|#
directive|define
name|NTB_PPD_OFFSET
value|0x00d4
end_define

begin_define
define|#
directive|define
name|XEON_PPD_CONN_TYPE
value|0x0003
end_define

begin_define
define|#
directive|define
name|XEON_PPD_DEV_TYPE
value|0x0010
end_define

begin_define
define|#
directive|define
name|XEON_PPD_SPLIT_BAR
value|0x0040
end_define

begin_define
define|#
directive|define
name|ATOM_PPD_INIT_LINK
value|0x0008
end_define

begin_define
define|#
directive|define
name|ATOM_PPD_CONN_TYPE
value|0x0300
end_define

begin_define
define|#
directive|define
name|ATOM_PPD_DEV_TYPE
value|0x1000
end_define

begin_comment
comment|/* All addresses are in low 32-bit space so 32-bit BARs can function */
end_comment

begin_define
define|#
directive|define
name|XEON_B2B_BAR0_ADDR
value|0x1000000000000000ull
end_define

begin_define
define|#
directive|define
name|XEON_B2B_BAR2_ADDR64
value|0x2000000000000000ull
end_define

begin_define
define|#
directive|define
name|XEON_B2B_BAR4_ADDR64
value|0x4000000000000000ull
end_define

begin_define
define|#
directive|define
name|XEON_B2B_BAR4_ADDR32
value|0x20000000ull
end_define

begin_define
define|#
directive|define
name|XEON_B2B_BAR5_ADDR32
value|0x40000000ull
end_define

begin_comment
comment|/* The peer ntb secondary config space is 32KB fixed size */
end_comment

begin_define
define|#
directive|define
name|XEON_B2B_MIN_SIZE
value|0x8000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NTB_REGS_H_ */
end_comment

end_unit

