begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: BSDI: asi.h,v 1.3 1997/08/08 14:31:42 torek  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASI_H_
end_define

begin_comment
comment|/*  * Standard v9 asis  */
end_comment

begin_define
define|#
directive|define
name|ASI_N
value|0x4
end_define

begin_define
define|#
directive|define
name|ASI_NL
value|0xc
end_define

begin_define
define|#
directive|define
name|ASI_AIUP
value|0x10
end_define

begin_define
define|#
directive|define
name|ASI_AIUS
value|0x11
end_define

begin_define
define|#
directive|define
name|ASI_AIUSL
value|0x19
end_define

begin_define
define|#
directive|define
name|ASI_P
value|0x80
end_define

begin_define
define|#
directive|define
name|ASI_S
value|0x81
end_define

begin_define
define|#
directive|define
name|ASI_PNF
value|0x82
end_define

begin_define
define|#
directive|define
name|ASI_SNF
value|0x83
end_define

begin_define
define|#
directive|define
name|ASI_PL
value|0x88
end_define

begin_define
define|#
directive|define
name|ASI_PNFL
value|0x8a
end_define

begin_define
define|#
directive|define
name|ASI_SNFL
value|0x8b
end_define

begin_comment
comment|/*  * UltraSPARC extensions  */
end_comment

begin_define
define|#
directive|define
name|ASI_PHYS_USE_EC
value|0x14
end_define

begin_define
define|#
directive|define
name|ASI_PHYS_BYPASS_EC_WITH_EBIT
value|0x15
end_define

begin_define
define|#
directive|define
name|ASI_PHYS_USE_EC_L
value|0x1c
end_define

begin_define
define|#
directive|define
name|ASI_PHYS_BYPASS_EC_WITH_EBIT_L
value|0x1d
end_define

begin_define
define|#
directive|define
name|ASI_NUCLEUS_QUAD_LDD
value|0x24
end_define

begin_define
define|#
directive|define
name|ASI_NUCLEUS_QUAD_LDD_L
value|0x2c
end_define

begin_define
define|#
directive|define
name|ASI_LSU_CTL_REG
value|0x45
end_define

begin_define
define|#
directive|define
name|ASI_INTR_DISPATCH_STATUS
value|0x48
end_define

begin_define
define|#
directive|define
name|ASI_INTR_RECEIVE
value|0x49
end_define

begin_define
define|#
directive|define
name|ASI_IMMU_TAG_TARGET_REG
value|0x50
end_define

begin_define
define|#
directive|define
name|ASI_IMMU
value|0x50
end_define

begin_define
define|#
directive|define
name|AA_IMMU_TTR
value|0x0
end_define

begin_define
define|#
directive|define
name|AA_IMMU_SFSR
value|0x18
end_define

begin_define
define|#
directive|define
name|AA_IMMU_TSB
value|0x28
end_define

begin_define
define|#
directive|define
name|AA_IMMU_TAR
value|0x30
end_define

begin_define
define|#
directive|define
name|ASI_IMMU_TSB_8KB_PTR_REG
value|0x51
end_define

begin_define
define|#
directive|define
name|ASI_IMMU_TSB_64KB_PTR_REG
value|0x52
end_define

begin_define
define|#
directive|define
name|ASI_ITLB_DATA_IN_REG
value|0x54
end_define

begin_define
define|#
directive|define
name|ASI_ITLB_DATA_ACCESS_REG
value|0x55
end_define

begin_define
define|#
directive|define
name|ASI_ITLB_TAG_READ_REG
value|0x56
end_define

begin_define
define|#
directive|define
name|ASI_IMMU_DEMAP
value|0x57
end_define

begin_define
define|#
directive|define
name|ASI_DMMU_TAG_TARGET_REG
value|0x58
end_define

begin_define
define|#
directive|define
name|ASI_DMMU
value|0x58
end_define

begin_define
define|#
directive|define
name|AA_DMMU_TTR
value|0x0
end_define

begin_define
define|#
directive|define
name|AA_DMMU_PCXR
value|0x8
end_define

begin_define
define|#
directive|define
name|AA_DMMU_SCXR
value|0x10
end_define

begin_define
define|#
directive|define
name|AA_DMMU_SFSR
value|0x18
end_define

begin_define
define|#
directive|define
name|AA_DMMU_SFAR
value|0x20
end_define

begin_define
define|#
directive|define
name|AA_DMMU_TSB
value|0x28
end_define

begin_define
define|#
directive|define
name|AA_DMMU_TAR
value|0x30
end_define

begin_define
define|#
directive|define
name|AA_DMMU_VWPR
value|0x38
end_define

begin_define
define|#
directive|define
name|AA_DMMU_PWPR
value|0x40
end_define

begin_define
define|#
directive|define
name|ASI_DCACHE_DATA
value|0x46
end_define

begin_define
define|#
directive|define
name|ASI_DCACHE_TAG
value|0x47
end_define

begin_define
define|#
directive|define
name|ASI_ECACHE_TAG_DATA
value|0x4e
end_define

begin_define
define|#
directive|define
name|ASI_DMMU_TSB_8KB_PTR_REG
value|0x59
end_define

begin_define
define|#
directive|define
name|ASI_DMMU_TSB_64KB_PTR_REG
value|0x5a
end_define

begin_define
define|#
directive|define
name|ASI_DMMU_TSB_DIRECT_PTR_REG
value|0x5b
end_define

begin_define
define|#
directive|define
name|ASI_DTLB_DATA_IN_REG
value|0x5c
end_define

begin_define
define|#
directive|define
name|ASI_DTLB_DATA_ACCESS_REG
value|0x5d
end_define

begin_define
define|#
directive|define
name|ASI_DTLB_TAG_READ_REG
value|0x5e
end_define

begin_define
define|#
directive|define
name|ASI_DMMU_DEMAP
value|0x5f
end_define

begin_define
define|#
directive|define
name|ASI_ICACHE_INSTR
value|0x66
end_define

begin_define
define|#
directive|define
name|ASI_ICACHE_TAG
value|0x67
end_define

begin_define
define|#
directive|define
name|ASI_ICACHE_PRE_DECODE
value|0x6e
end_define

begin_define
define|#
directive|define
name|ASI_ICACHE_PRE_NEXT_FIELD
value|0x6f
end_define

begin_define
define|#
directive|define
name|ASI_BLK_AUIP
value|0x70
end_define

begin_define
define|#
directive|define
name|ASI_BLK_AIUS
value|0x71
end_define

begin_define
define|#
directive|define
name|ASI_ECACHE_W
value|0x76
end_define

begin_define
define|#
directive|define
name|ASI_SDB_INTR_W
value|0x77
end_define

begin_define
define|#
directive|define
name|AA_SDB_INTR_D0
value|0x40
end_define

begin_define
define|#
directive|define
name|AA_SDB_INTR_D1
value|0x50
end_define

begin_define
define|#
directive|define
name|AA_SDB_INTR_D2
value|0x60
end_define

begin_define
define|#
directive|define
name|ASI_BLK_AIUPL
value|0x78
end_define

begin_define
define|#
directive|define
name|ASI_BLK_AIUSL
value|0x79
end_define

begin_define
define|#
directive|define
name|ASI_ECACHE_R
value|0x7e
end_define

begin_define
define|#
directive|define
name|ASI_SDB_INTR_R
value|0x7f
end_define

begin_define
define|#
directive|define
name|ASI_BLK_COMMIT_P
value|0xe0
end_define

begin_define
define|#
directive|define
name|ASI_BLK_COMMIT_S
value|0xe1
end_define

begin_define
define|#
directive|define
name|ASI_BLK_P
value|0xf0
end_define

begin_define
define|#
directive|define
name|ASI_BLK_S
value|0xf1
end_define

begin_define
define|#
directive|define
name|ASI_BLK_PL
value|0xf8
end_define

begin_define
define|#
directive|define
name|ASI_BLK_SL
value|0xf9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASI_H_ */
end_comment

end_unit

