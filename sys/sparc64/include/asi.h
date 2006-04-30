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
name|ASI_AIUPL
value|0x18
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
name|ASI_SL
value|0x89
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
comment|/*  * UltraSPARC extensions. ASIs limited to a certain family are annotated.  */
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
name|ASI_PCACHE_STATUS_DATA
value|0x30
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_PCACHE_DATA
value|0x31
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_PCACHE_TAG
value|0x32
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_PCACHE_SNOOP_TAG
value|0x33
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_ATOMIC_QUAD_LDD_PHYS
value|0x34
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_WCACHE_VALID_BITS
value|0x38
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_WCACHE_DATA
value|0x39
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_WCACHE_TAG
value|0x3a
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_WCACHE_SNOOP_TAG
value|0x3b
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_ATOMIC_QUAD_LDD_PHYS_L
value|0x3c
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_SRAM_FAST_INIT
value|0x40
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_DCACHE_INVALIDATE
value|0x42
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_DCACHE_UTAG
value|0x43
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_DCACHE_SNOOP_TAG
value|0x44
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_comment
comment|/* Named ASI_DCUCR on US-III, but is mostly identical except for added bits. */
end_comment

begin_define
define|#
directive|define
name|ASI_LSU_CTL_REG
value|0x45
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
name|ASI_UPA_CONFIG_REG
value|0x4a
end_define

begin_comment
comment|/* US-I, II */
end_comment

begin_define
define|#
directive|define
name|ASI_FIREPLANE_CONFIG_REG
value|0x4a
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_FIREPLANE_CONFIG
value|0x0
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_FIREPLANE_ADDRESS
value|0x8
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_ESTATE_ERROR_EN_REG
value|0x4b
end_define

begin_define
define|#
directive|define
name|AA_ESTATE_CEEN
value|0x1
end_define

begin_define
define|#
directive|define
name|AA_ESTATE_NCEEN
value|0x2
end_define

begin_define
define|#
directive|define
name|AA_ESTATE_ISAPEN
value|0x4
end_define

begin_define
define|#
directive|define
name|ASI_AFSR
value|0x4c
end_define

begin_define
define|#
directive|define
name|ASI_AFAR
value|0x4d
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
name|AA_IMMU_TSB_PEXT_REG
value|0x48
end_define

begin_comment
comment|/* US-III family */
end_comment

begin_define
define|#
directive|define
name|AA_IMMU_TSB_SEXT_REG
value|0x50
end_define

begin_comment
comment|/* US-III family */
end_comment

begin_define
define|#
directive|define
name|AA_IMMU_TSB_NEXT_REG
value|0x58
end_define

begin_comment
comment|/* US-III family */
end_comment

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
name|ASI_SERIAL_ID
value|0x53
end_define

begin_comment
comment|/* US-III family */
end_comment

begin_define
define|#
directive|define
name|ASI_ITLB_DATA_IN_REG
value|0x54
end_define

begin_comment
comment|/* US-III Cu: also ASI_ITLB_CAM_ADDRESS_REG */
end_comment

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
name|AA_DMMU_TSB_PEXT_REG
value|0x48
end_define

begin_define
define|#
directive|define
name|AA_DMMU_TSB_SEXT_REG
value|0x50
end_define

begin_define
define|#
directive|define
name|AA_DMMU_TSB_NEXT_REG
value|0x58
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

begin_comment
comment|/* US-III Cu: also ASI_DTLB_CAM_ADDRESS_REG */
end_comment

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
name|ASI_IIU_INST_TRAP
value|0x60
end_define

begin_comment
comment|/* US-III family */
end_comment

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
name|ASI_ICACHE_SNOOP_TAG
value|0x68
end_define

begin_comment
comment|/* US-III family */
end_comment

begin_define
define|#
directive|define
name|ASI_ICACHE_PRE_DECODE
value|0x6e
end_define

begin_comment
comment|/* US-I, II */
end_comment

begin_define
define|#
directive|define
name|ASI_ICACHE_PRE_NEXT_FIELD
value|0x6f
end_define

begin_comment
comment|/* US-I, II */
end_comment

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
name|ASI_MCU_CONFIG_REG
value|0x72
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_MCU_TIMING1_REG
value|0x0
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_MCU_TIMING2_REG
value|0x8
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_MCU_TIMING3_REG
value|0x10
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_MCU_TIMING4_REG
value|0x18
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_MCU_DEC1_REG
value|0x20
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_MCU_DEC2_REG
value|0x28
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_MCU_DEC3_REG
value|0x30
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_MCU_DEC4_REG
value|0x38
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|AA_MCU_ADDR_CNTL_REG
value|0x40
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_ECACHE_DATA
value|0x74
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_ECACHE_CONTROL
value|0x75
end_define

begin_comment
comment|/* US-III Cu */
end_comment

begin_define
define|#
directive|define
name|ASI_ECACHE_W
value|0x76
end_define

begin_comment
comment|/*  * With the advent of the US-III, the numbering has changed, as additional  * registers were inserted in between. We retain the original ordering for  * now, and append an A to the inserted registers.  * Exceptions are AA_SDB_INTR_D6 and AA_SDB_INTR_D7, which were appended  * at the end.  */
end_comment

begin_define
define|#
directive|define
name|ASI_SDB_ERROR_W
value|0x77
end_define

begin_define
define|#
directive|define
name|ASI_SDB_CONTROL_W
value|0x77
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
name|AA_SDB_ERR_HIGH
value|0x0
end_define

begin_define
define|#
directive|define
name|AA_SDB_ERR_LOW
value|0x18
end_define

begin_define
define|#
directive|define
name|AA_SDB_CNTL_HIGH
value|0x20
end_define

begin_define
define|#
directive|define
name|AA_SDB_CNTL_LOW
value|0x38
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
name|AA_SDB_INTR_D0A
value|0x48
end_define

begin_comment
comment|/* US-III family */
end_comment

begin_define
define|#
directive|define
name|AA_SDB_INTR_D1
value|0x50
end_define

begin_define
define|#
directive|define
name|AA_SDB_INTR_D1A
value|0x5A
end_define

begin_comment
comment|/* US-III family */
end_comment

begin_define
define|#
directive|define
name|AA_SDB_INTR_D2
value|0x60
end_define

begin_define
define|#
directive|define
name|AA_SDB_INTR_D2A
value|0x68
end_define

begin_comment
comment|/* US-III family */
end_comment

begin_define
define|#
directive|define
name|AA_INTR_SEND
value|0x70
end_define

begin_define
define|#
directive|define
name|AA_SDB_INTR_D6
value|0x80
end_define

begin_comment
comment|/* US-III family */
end_comment

begin_define
define|#
directive|define
name|AA_SDB_INTR_D7
value|0x88
end_define

begin_comment
comment|/* US-III family */
end_comment

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

begin_comment
comment|/*  * These have the same registers as their corresponding write versions  * except for AA_INTR_SEND.  */
end_comment

begin_define
define|#
directive|define
name|ASI_SDB_ERROR_R
value|0x7f
end_define

begin_define
define|#
directive|define
name|ASI_SDB_CONTROL_R
value|0x7f
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
name|ASI_PST8_P
value|0xc0
end_define

begin_define
define|#
directive|define
name|ASI_PST8_S
value|0xc1
end_define

begin_define
define|#
directive|define
name|ASI_PST16_P
value|0xc2
end_define

begin_define
define|#
directive|define
name|ASI_PST16_S
value|0xc3
end_define

begin_define
define|#
directive|define
name|ASI_PST32_P
value|0xc4
end_define

begin_define
define|#
directive|define
name|ASI_PST32_S
value|0xc5
end_define

begin_define
define|#
directive|define
name|ASI_PST8_PL
value|0xc8
end_define

begin_define
define|#
directive|define
name|ASI_PST8_SL
value|0xc9
end_define

begin_define
define|#
directive|define
name|ASI_PST16_PL
value|0xca
end_define

begin_define
define|#
directive|define
name|ASI_PST16_SL
value|0xcb
end_define

begin_define
define|#
directive|define
name|ASI_PST32_PL
value|0xcc
end_define

begin_define
define|#
directive|define
name|ASI_PST32_SL
value|0xcd
end_define

begin_define
define|#
directive|define
name|ASI_FL8_P
value|0xd0
end_define

begin_define
define|#
directive|define
name|ASI_FL8_S
value|0xd1
end_define

begin_define
define|#
directive|define
name|ASI_FL16_P
value|0xd2
end_define

begin_define
define|#
directive|define
name|ASI_FL16_S
value|0xd3
end_define

begin_define
define|#
directive|define
name|ASI_FL8_PL
value|0xd8
end_define

begin_define
define|#
directive|define
name|ASI_FL8_SL
value|0xd9
end_define

begin_define
define|#
directive|define
name|ASI_FL16_PL
value|0xda
end_define

begin_define
define|#
directive|define
name|ASI_FL16_SL
value|0xdb
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

