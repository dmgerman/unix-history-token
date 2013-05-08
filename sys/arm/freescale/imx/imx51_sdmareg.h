begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Oleksandr Rybalko under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Internal Registers definition for Freescale i.MX515 SDMA Core */
end_comment

begin_comment
comment|/* SDMA Core Instruction Memory Space */
end_comment

begin_define
define|#
directive|define
name|SDMA_IBUS_ROM_ADDR_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|SDMA_IBUS_ROM_ADDR_SIZE
value|0x07ff
end_define

begin_define
define|#
directive|define
name|SDMA_IBUS_RAM_ADDR_BASE
value|0x1000
end_define

begin_define
define|#
directive|define
name|SDMA_IBUS_RAM_ADDR_SIZE
value|0x1fff
end_define

begin_comment
comment|/* SDMA Core Internal Registers */
end_comment

begin_define
define|#
directive|define
name|SDMA_MC0PTR
value|0x7000
end_define

begin_comment
comment|/* AP (MCU) Channel 0 Pointer R */
end_comment

begin_define
define|#
directive|define
name|SDMA_CCPTR
value|0x7002
end_define

begin_comment
comment|/* Current Channel Pointer R */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_CCPTR_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_CCPTR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_CCR
value|0x7003
end_define

begin_comment
comment|/* Current Channel Register R */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_CCR_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_CCR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_NCR
value|0x7004
end_define

begin_comment
comment|/* Highest Pending Channel Register R */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_NCR_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_NCR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_EVENTS
value|0x7005
end_define

begin_comment
comment|/* External DMA Requests Mirror R */
end_comment

begin_define
define|#
directive|define
name|SDMA_CCPRI
value|0x7006
end_define

begin_comment
comment|/* Current Channel Priority R */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_CCPRI_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_CCPRI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_NCPRI
value|0x7007
end_define

begin_comment
comment|/* Next Channel Priority R */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_NCPRI_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_NCPRI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_ECOUNT
value|0x7009
end_define

begin_comment
comment|/* OnCE Event Cell Counter R/W */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_ECOUNT_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_ECOUNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL
value|0x700A
end_define

begin_comment
comment|/* OnCE Event Cell Control Register R/W */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_CNT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_ECTC_MASK
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_ECTC_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_DTC_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_DTC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_ATC_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_ATC_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_ABTC_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_ABTC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_AATC_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_AATC_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_ATS_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_ATS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_EAA
value|0x700B
end_define

begin_comment
comment|/* OnCE Event Address Register A R/W */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_EAA_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_EAA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_EAB
value|0x700C
end_define

begin_comment
comment|/* OnCE Event Cell Address Register B R/W */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_EAB_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_EAB_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_EAM
value|0x700D
end_define

begin_comment
comment|/* OnCE Event Cell Address Mask R/W */
end_comment

begin_define
define|#
directive|define
name|SDMA_ECTL_EAM_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|SDMA_ECTL_EAM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_ED
value|0x700E
end_define

begin_comment
comment|/* OnCE Event Cell Data Register R/W */
end_comment

begin_define
define|#
directive|define
name|SDMA_EDM
value|0x700F
end_define

begin_comment
comment|/* OnCE Event Cell Data Mask R/W */
end_comment

begin_define
define|#
directive|define
name|SDMA_RTB
value|0x7018
end_define

begin_comment
comment|/* OnCE Real-Time Buffer R/W */
end_comment

begin_define
define|#
directive|define
name|SDMA_TB
value|0x7019
end_define

begin_comment
comment|/* OnCE Trace Buffer R */
end_comment

begin_define
define|#
directive|define
name|SDMA_TB_TBF
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|SDMA_TB_TADDR_MASK
value|0x0fffc000
end_define

begin_define
define|#
directive|define
name|SDMA_TB_TADDR_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|SDMA_TB_CHFADDR_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|SDMA_TB_CHFADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_OSTAT
value|0x701A
end_define

begin_comment
comment|/* OnCE Status R */
end_comment

begin_define
define|#
directive|define
name|SDMA_OSTAT_PST_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|SDMA_OSTAT_PST_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SDMA_OSTAT_RCV
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SDMA_OSTAT_EDR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SDMA_OSTAT_ODR
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SDMA_OSTAT_SWB
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SDMA_OSTAT_MST
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SDMA_OSTAT_ECDR_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SDMA_OSTAT_ECDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_MCHN0ADDR
value|0x701C
end_define

begin_comment
comment|/* Channel 0 Boot Address R */
end_comment

begin_define
define|#
directive|define
name|SDMA_MCHN0ADDR_SMS_Z
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SDMA_MCHN0ADDR_CHN0ADDR_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|SDMA_MCHN0ADDR_CHN0ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SDMA_MODE
value|0x701D
end_define

begin_comment
comment|/* Mode Status Register R */
end_comment

begin_define
define|#
directive|define
name|SDMA_MODE_DSPCtrl
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SDMA_MODE_AP_END
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDMA_LOCK
value|0x701E
end_define

begin_comment
comment|/* Lock Status Register R */
end_comment

begin_define
define|#
directive|define
name|SDMA_LOCK_LOCK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDMA_EVENTS2
value|0x701F
end_define

begin_comment
comment|/* External DMA Requests Mirror #2 R */
end_comment

begin_define
define|#
directive|define
name|SDMA_HE
value|0x7020
end_define

begin_comment
comment|/* AP Enable Register R */
end_comment

begin_define
define|#
directive|define
name|SDMA_PRIV
value|0x7022
end_define

begin_comment
comment|/* Current Channel BP Privilege Register R */
end_comment

begin_define
define|#
directive|define
name|SDMA_PRIV_BPPRIV
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDMA_PRF_CNT
value|0x7023
end_define

begin_comment
comment|/* Profile Free Running Register R/W */
end_comment

begin_define
define|#
directive|define
name|SDMA_PRF_CNT_SEL_MASK
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|SDMA_PRF_CNT_SEL_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|SDMA_PRF_CNT_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SDMA_PRF_CNT_OFL
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|SDMA_PRF_CNT_COUNTER_MASK
value|0x003fffff
end_define

begin_define
define|#
directive|define
name|SDMA_PRF_CNT_COUNTER_SHIFT
value|0
end_define

end_unit

