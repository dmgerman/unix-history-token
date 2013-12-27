begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_MMCHS_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_MMCHS_H_
end_define

begin_comment
comment|/**  * Header file for the TI MMC/SD/SDIO driver.  *  * Simply contains register addresses and bit flags.  */
end_comment

begin_comment
comment|/* Register offsets within each of the MMC/SD/SDIO controllers */
end_comment

begin_define
define|#
directive|define
name|MMCHS_SYSCONFIG
value|0x010
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSSTATUS
value|0x014
end_define

begin_define
define|#
directive|define
name|MMCHS_CSRE
value|0x024
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSTEST
value|0x028
end_define

begin_define
define|#
directive|define
name|MMCHS_CON
value|0x02C
end_define

begin_define
define|#
directive|define
name|MMCHS_PWCNT
value|0x030
end_define

begin_define
define|#
directive|define
name|MMCHS_BLK
value|0x104
end_define

begin_define
define|#
directive|define
name|MMCHS_ARG
value|0x108
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD
value|0x10C
end_define

begin_define
define|#
directive|define
name|MMCHS_RSP10
value|0x110
end_define

begin_define
define|#
directive|define
name|MMCHS_RSP32
value|0x114
end_define

begin_define
define|#
directive|define
name|MMCHS_RSP54
value|0x118
end_define

begin_define
define|#
directive|define
name|MMCHS_RSP76
value|0x11C
end_define

begin_define
define|#
directive|define
name|MMCHS_DATA
value|0x120
end_define

begin_define
define|#
directive|define
name|MMCHS_PSTATE
value|0x124
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL
value|0x128
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL
value|0x12C
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT
value|0x130
end_define

begin_define
define|#
directive|define
name|MMCHS_IE
value|0x134
end_define

begin_define
define|#
directive|define
name|MMCHS_ISE
value|0x138
end_define

begin_define
define|#
directive|define
name|MMCHS_AC12
value|0x13C
end_define

begin_define
define|#
directive|define
name|MMCHS_CAPA
value|0x140
end_define

begin_define
define|#
directive|define
name|MMCHS_CUR_CAPA
value|0x148
end_define

begin_define
define|#
directive|define
name|MMCHS_REV
value|0x1FC
end_define

begin_comment
comment|/* OMAP4 and OMAP4 have different register addresses */
end_comment

begin_define
define|#
directive|define
name|OMAP3_MMCHS_REG_OFFSET
value|0x000
end_define

begin_define
define|#
directive|define
name|OMAP4_MMCHS_REG_OFFSET
value|0x100
end_define

begin_define
define|#
directive|define
name|AM335X_MMCHS_REG_OFFSET
value|0x100
end_define

begin_comment
comment|/* Register bit settings */
end_comment

begin_define
define|#
directive|define
name|MMCHS_SYSCONFIG_CLK_FUN
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCONFIG_CLK_IFC
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCONFIG_SIDL
value|(2<< 3)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCONFIG_ENW
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCONFIG_SRST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCONFIG_AIDL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_BADA
value|(1UL<< 29)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_CERR
value|(1UL<< 28)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_ACE
value|(1UL<< 24)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_DEB
value|(1UL<< 22)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_DCRC
value|(1UL<< 21)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_DTO
value|(1UL<< 20)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_CIE
value|(1UL<< 19)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_CEB
value|(1UL<< 18)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_CCRC
value|(1UL<< 17)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_CTO
value|(1UL<< 16)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_ERRI
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_OBI
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_CIRQ
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_BRR
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_BWR
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_BGE
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_TC
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_CC
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|MMCHS_STAT_CLEAR_MASK
value|0x3BFF8337UL
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_SRD
value|(1UL<< 26)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_SRC
value|(1UL<< 25)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_SRA
value|(1UL<< 24)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_DTO
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 16)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_DTO_MASK
value|MMCHS_SYSCTL_DTO(0xf)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_CLKD
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3ff)<< 6)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_CLKD_MASK
value|MMCHS_SYSCTL_CLKD(0x3ff)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_CEN
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_ICS
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|MMCHS_SYSCTL_ICE
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_OBWE
value|(1UL<< 27)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_REM
value|(1UL<< 26)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_INS
value|(1UL<< 25)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_IWE
value|(1UL<< 24)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_IBG
value|(1UL<< 19)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_RWC
value|(1UL<< 18)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_CR
value|(1UL<< 17)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_SBGR
value|(1UL<< 16)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_SDVS_MASK
value|(7UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_SDVS_V18
value|(5UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_SDVS_V30
value|(6UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_SDVS_V33
value|(7UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_SDBP
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|MMCHS_HCTL_DTW
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|MMCHS_CAPA_VS18
value|(1UL<< 26)
end_define

begin_define
define|#
directive|define
name|MMCHS_CAPA_VS30
value|(1UL<< 25)
end_define

begin_define
define|#
directive|define
name|MMCHS_CAPA_VS33
value|(1UL<< 24)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_CMD_TYPE_IO_ABORT
value|(3UL<< 21)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_CMD_TYPE_FUNC_SEL
value|(2UL<< 21)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_CMD_TYPE_SUSPEND
value|(1UL<< 21)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_CMD_TYPE_OTHERS
value|(0UL<< 21)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_CMD_TYPE_MASK
value|(3UL<< 22)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_DP
value|(1UL<< 21)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_CICE
value|(1UL<< 20)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_CCCE
value|(1UL<< 19)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_RSP_TYPE_MASK
value|(3UL<< 16)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_RSP_TYPE_NO
value|(0UL<< 16)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_RSP_TYPE_136
value|(1UL<< 16)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_RSP_TYPE_48
value|(2UL<< 16)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_RSP_TYPE_48_BSY
value|(3UL<< 16)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_MSBS
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_DDIR
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_ACEN
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_BCE
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|MMCHS_CMD_DE
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_CLKEXTFREE
value|(1UL<< 16)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_PADEN
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_OBIE
value|(1UL<< 14)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_OBIP
value|(1UL<< 13)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_CEATA
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_CTPL
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_DVAL_8_4MS
value|(3UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_DVAL_1MS
value|(2UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_DVAL_231US
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_DVAL_33US
value|(0UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_DVAL_MASK
value|(3UL<< 9)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_WPP
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_CDP
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_MIT
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_DW8
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_MODE
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_STR
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_HR
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_INIT
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|MMCHS_CON_OD
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|MMCHS_CAPA_VS18
value|(1UL<< 26)
end_define

begin_define
define|#
directive|define
name|MMCHS_CAPA_VS30
value|(1UL<< 25)
end_define

begin_define
define|#
directive|define
name|MMCHS_CAPA_VS33
value|(1UL<< 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_MMCHS_H_ */
end_comment

end_unit

