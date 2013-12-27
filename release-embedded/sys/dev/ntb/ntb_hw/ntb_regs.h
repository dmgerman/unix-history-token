begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2013 Intel Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|NTB_LINK_ENABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|NTB_LINK_DISABLE
value|0x0002
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
name|XEON_MSIX_CNT
value|4
end_define

begin_define
define|#
directive|define
name|XEON_MAX_SPADS
value|16
end_define

begin_define
define|#
directive|define
name|XEON_MAX_COMPAT_SPADS
value|8
end_define

begin_comment
comment|/* Reserve the uppermost bit for link interrupt */
end_comment

begin_define
define|#
directive|define
name|XEON_MAX_DB_BITS
value|15
end_define

begin_define
define|#
directive|define
name|XEON_DB_BITS_PER_VEC
value|5
end_define

begin_define
define|#
directive|define
name|XEON_DB_HW_LINK
value|0x8000
end_define

begin_define
define|#
directive|define
name|XEON_PCICMD_OFFSET
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
name|XEON_LINK_STATUS_OFFSET
value|0x01a2
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
name|XEON_USMEMMISS
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
name|XEON_B2B_XLAT_OFFSET
value|0x0144
end_define

begin_define
define|#
directive|define
name|SOC_MSIX_CNT
value|34
end_define

begin_define
define|#
directive|define
name|SOC_MAX_SPADS
value|16
end_define

begin_define
define|#
directive|define
name|SOC_MAX_COMPAT_SPADS
value|16
end_define

begin_define
define|#
directive|define
name|SOC_MAX_DB_BITS
value|34
end_define

begin_define
define|#
directive|define
name|SOC_DB_BITS_PER_VEC
value|1
end_define

begin_define
define|#
directive|define
name|SOC_PCICMD_OFFSET
value|0xb004
end_define

begin_define
define|#
directive|define
name|SOC_MBAR23_OFFSET
value|0xb018
end_define

begin_define
define|#
directive|define
name|SOC_MBAR45_OFFSET
value|0xb020
end_define

begin_define
define|#
directive|define
name|SOC_DEVCTRL_OFFSET
value|0xb048
end_define

begin_define
define|#
directive|define
name|SOC_LINK_STATUS_OFFSET
value|0xb052
end_define

begin_define
define|#
directive|define
name|SOC_ERRCORSTS_OFFSET
value|0xb110
end_define

begin_define
define|#
directive|define
name|SOC_SBAR2XLAT_OFFSET
value|0x0008
end_define

begin_define
define|#
directive|define
name|SOC_SBAR4XLAT_OFFSET
value|0x0010
end_define

begin_define
define|#
directive|define
name|SOC_PDOORBELL_OFFSET
value|0x0020
end_define

begin_define
define|#
directive|define
name|SOC_PDBMSK_OFFSET
value|0x0028
end_define

begin_define
define|#
directive|define
name|SOC_NTBCNTL_OFFSET
value|0x0060
end_define

begin_define
define|#
directive|define
name|SOC_EBDF_OFFSET
value|0x0064
end_define

begin_define
define|#
directive|define
name|SOC_SPAD_OFFSET
value|0x0080
end_define

begin_define
define|#
directive|define
name|SOC_SPADSEMA_OFFSET
value|0x00c0
end_define

begin_define
define|#
directive|define
name|SOC_STKYSPAD_OFFSET
value|0x00c4
end_define

begin_define
define|#
directive|define
name|SOC_PBAR2XLAT_OFFSET
value|0x8008
end_define

begin_define
define|#
directive|define
name|SOC_PBAR4XLAT_OFFSET
value|0x8010
end_define

begin_define
define|#
directive|define
name|SOC_B2B_DOORBELL_OFFSET
value|0x8020
end_define

begin_define
define|#
directive|define
name|SOC_B2B_SPAD_OFFSET
value|0x8080
end_define

begin_define
define|#
directive|define
name|SOC_B2B_SPADSEMA_OFFSET
value|0x80c0
end_define

begin_define
define|#
directive|define
name|SOC_B2B_STKYSPAD_OFFSET
value|0x80c4
end_define

begin_define
define|#
directive|define
name|SOC_MODPHY_PCSREG4
value|0x1c004
end_define

begin_define
define|#
directive|define
name|SOC_MODPHY_PCSREG6
value|0x1c006
end_define

begin_define
define|#
directive|define
name|SOC_IP_BASE
value|0xc000
end_define

begin_define
define|#
directive|define
name|SOC_DESKEWSTS_OFFSET
value|(SOC_IP_BASE + 0x3024)
end_define

begin_define
define|#
directive|define
name|SOC_LTSSMERRSTS0_OFFSET
value|(SOC_IP_BASE + 0x3180)
end_define

begin_define
define|#
directive|define
name|SOC_LTSSMSTATEJMP_OFFSET
value|(SOC_IP_BASE + 0x3040)
end_define

begin_define
define|#
directive|define
name|SOC_IBSTERRRCRVSTS0_OFFSET
value|(SOC_IP_BASE + 0x3324)
end_define

begin_define
define|#
directive|define
name|SOC_DESKEWSTS_DBERR
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|SOC_LTSSMERRSTS0_UNEXPECTEDEI
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|SOC_LTSSMSTATEJMP_FORCEDETECT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SOC_IBIST_ERR_OFLOW
value|0x7fff7fff
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_BAR23_SNOOP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|NTB_CNTL_BAR45_SNOOP
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SOC_CNTL_LINK_DOWN
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
name|SOC_PPD_INIT_LINK
value|0x0008
end_define

begin_define
define|#
directive|define
name|SOC_PPD_CONN_TYPE
value|0x0300
end_define

begin_define
define|#
directive|define
name|SOC_PPD_DEV_TYPE
value|0x1000
end_define

begin_define
define|#
directive|define
name|NTB_CONN_CLASSIC
value|0
end_define

begin_define
define|#
directive|define
name|NTB_CONN_B2B
value|1
end_define

begin_define
define|#
directive|define
name|NTB_CONN_RP
value|2
end_define

begin_define
define|#
directive|define
name|NTB_DEV_DSD
value|1
end_define

begin_define
define|#
directive|define
name|NTB_DEV_USD
value|0
end_define

begin_define
define|#
directive|define
name|PBAR2XLAT_USD_ADDR
value|0x0000004000000000
end_define

begin_define
define|#
directive|define
name|PBAR4XLAT_USD_ADDR
value|0x0000008000000000
end_define

begin_define
define|#
directive|define
name|MBAR01_USD_ADDR
value|0x000000210000000c
end_define

begin_define
define|#
directive|define
name|MBAR23_USD_ADDR
value|0x000000410000000c
end_define

begin_define
define|#
directive|define
name|MBAR45_USD_ADDR
value|0x000000810000000c
end_define

begin_define
define|#
directive|define
name|PBAR2XLAT_DSD_ADDR
value|0x0000004100000000
end_define

begin_define
define|#
directive|define
name|PBAR4XLAT_DSD_ADDR
value|0x0000008100000000
end_define

begin_define
define|#
directive|define
name|MBAR01_DSD_ADDR
value|0x000000200000000c
end_define

begin_define
define|#
directive|define
name|MBAR23_DSD_ADDR
value|0x000000400000000c
end_define

begin_define
define|#
directive|define
name|MBAR45_DSD_ADDR
value|0x000000800000000c
end_define

begin_comment
comment|/* XEON Shadowed MMIO Space */
end_comment

begin_define
define|#
directive|define
name|XEON_SHADOW_PDOORBELL_OFFSET
value|0x60
end_define

begin_define
define|#
directive|define
name|XEON_SHADOW_SPAD_OFFSET
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NTB_REGS_H_ */
end_comment

end_unit

