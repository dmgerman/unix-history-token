begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASI_H_ */
end_comment

end_unit

