begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Kip Macy  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: BSDI: asi.h,v 1.3 1997/08/08 14:31:42 torek  * $FreeBSD$  */
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
comment|/*  *  UltraSPARC Architecture 2005 ASIs  */
end_comment

begin_define
define|#
directive|define
name|ASI_N
value|0x04
end_define

begin_comment
comment|/* ASI_NUCLEUS                           */
end_comment

begin_define
define|#
directive|define
name|ASI_NL
value|0x0c
end_define

begin_comment
comment|/* ASI_NUCLEUS_LITTLE                    */
end_comment

begin_define
define|#
directive|define
name|ASI_AIUP
value|0x10
end_define

begin_comment
comment|/* ASI_AS_IF_USER_PRIMARY                */
end_comment

begin_define
define|#
directive|define
name|ASI_AIUS
value|0x11
end_define

begin_comment
comment|/* ASI_AS_IF_USER_SECONDARY              */
end_comment

begin_define
define|#
directive|define
name|ASI_REAL
value|0x14
end_define

begin_define
define|#
directive|define
name|ASI_REAL_IO
value|0x15
end_define

begin_define
define|#
directive|define
name|ASI_BLK_AIUP
value|0x16
end_define

begin_comment
comment|/* ASI_BLOCK_AS_IF_USER_PRIMARY          */
end_comment

begin_define
define|#
directive|define
name|ASI_BLK_AIUS
value|0x17
end_define

begin_comment
comment|/* ASI_BLOCK_AS_IF_USER_SECONDARY        */
end_comment

begin_define
define|#
directive|define
name|ASI_AIUPL
value|0x18
end_define

begin_comment
comment|/* ASI_AS_IF_USER_PRIMARY_LITTLE         */
end_comment

begin_define
define|#
directive|define
name|ASI_AIUSL
value|0x19
end_define

begin_comment
comment|/* ASI_AS_IF_USER_SECONDARY_LITTLE       */
end_comment

begin_define
define|#
directive|define
name|ASI_REAL_L
value|0x1C
end_define

begin_comment
comment|/* ASI_REAL_LITTLE                       */
end_comment

begin_define
define|#
directive|define
name|ASI_REAL_IO_L
value|0x1D
end_define

begin_comment
comment|/* ASI_REAL_IO_LITTLE                    */
end_comment

begin_define
define|#
directive|define
name|ASI_BLK_AIUPL
value|0x1E
end_define

begin_comment
comment|/* ASI_BLOCK_AS_IF_USER_PRIMARY_LITTLE   */
end_comment

begin_define
define|#
directive|define
name|ASI_BLK_AIUSL
value|0x1F
end_define

begin_comment
comment|/* ASI_BLOCK_AS_IF_USER_SECONDARY_LITTLE */
end_comment

begin_define
define|#
directive|define
name|ASI_SCRATCHPAD
value|0x20
end_define

begin_define
define|#
directive|define
name|ASI_MMU_CONTEXTID
value|0x21
end_define

begin_define
define|#
directive|define
name|ASI_LDTD_AIUP
value|0x22
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_AS_IF_USER_PRIMARY   */
end_comment

begin_define
define|#
directive|define
name|ASI_LDSTBI_AIUP
value|0x22
end_define

begin_define
define|#
directive|define
name|ASI_LDTD_AIUS
value|0x23
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_AS_IF_USER_SECONDARY */
end_comment

begin_define
define|#
directive|define
name|ASI_LDSTBI_AIUS
value|0x23
end_define

begin_define
define|#
directive|define
name|ASI_QUEUE
value|0x25
end_define

begin_define
define|#
directive|define
name|ASI_LDTD_REAL
value|0x26
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_REAL                 */
end_comment

begin_define
define|#
directive|define
name|ASI_STBI_REAL
value|0x26
end_define

begin_define
define|#
directive|define
name|ASI_LDTD_N
value|0x27
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_NUCLEUS              */
end_comment

begin_define
define|#
directive|define
name|ASI_LDSTBI_N
value|0x27
end_define

begin_define
define|#
directive|define
name|ASI_LDTD_AIUPL
value|0x2A
end_define

begin_comment
comment|/* ASI_LD_TWIN_DW_AS_IF_USER_PRIMARY_LITTLE   */
end_comment

begin_define
define|#
directive|define
name|ASI_LDTD_AIUSL
value|0x2B
end_define

begin_comment
comment|/* ASI_LD_TWIN_DW_AS_IF_USER_SECONDARY_LITTLE */
end_comment

begin_define
define|#
directive|define
name|ASI_LDTD_REAL_L
value|0x2E
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_REAL_LITTLE           */
end_comment

begin_define
define|#
directive|define
name|ASI_LDTD_NL
value|0x2F
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_NUCLEUS_LITTLE        */
end_comment

begin_define
define|#
directive|define
name|ASI_P
value|0x80
end_define

begin_comment
comment|/* ASI_PRIMARY                            */
end_comment

begin_define
define|#
directive|define
name|ASI_S
value|0x81
end_define

begin_comment
comment|/* ASI_SECONDARY                          */
end_comment

begin_define
define|#
directive|define
name|ASI_PNF
value|0x82
end_define

begin_comment
comment|/* ASI_PRIMARY_NO_FAULT                   */
end_comment

begin_define
define|#
directive|define
name|ASI_SNF
value|0x83
end_define

begin_comment
comment|/* ASI_SECONDARY_NO_FAULT                 */
end_comment

begin_define
define|#
directive|define
name|ASI_PL
value|0x88
end_define

begin_comment
comment|/* ASI_PRIMARY_LITTLE                     */
end_comment

begin_define
define|#
directive|define
name|ASI_SL
value|0x89
end_define

begin_comment
comment|/* ASI_SECONDARY_LITTLE                   */
end_comment

begin_define
define|#
directive|define
name|ASI_PNFL
value|0x8a
end_define

begin_comment
comment|/* ASI_PRIMARY_NO_FAULT_LITTLE            */
end_comment

begin_define
define|#
directive|define
name|ASI_SNFL
value|0x8b
end_define

begin_comment
comment|/* ASI_SECONDARY_NO_FAULT_LITTLE          */
end_comment

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
name|ASI_LDTD_P
value|0xe2
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_PRIMARY              */
end_comment

begin_define
define|#
directive|define
name|ASI_LDSTBI_P
value|0xe2
end_define

begin_define
define|#
directive|define
name|ASI_LDTD_S
value|0xe3
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_SECONDARY            */
end_comment

begin_define
define|#
directive|define
name|ASI_LDTD_PL
value|0xea
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_PRIMARY_LITTLE       */
end_comment

begin_define
define|#
directive|define
name|ASI_LDTD_SL
value|0xeb
end_define

begin_comment
comment|/* ASI_LOAD_TWIN_DW_SECONDARY_LITTLE     */
end_comment

begin_define
define|#
directive|define
name|ASI_BLK_P
value|0xf0
end_define

begin_comment
comment|/* ASI_BLOCK_PRIMARY                     */
end_comment

begin_define
define|#
directive|define
name|ASI_BLK_S
value|0xf1
end_define

begin_comment
comment|/* ASI_BLOCK_SECONDARY                   */
end_comment

begin_define
define|#
directive|define
name|ASI_BLK_PL
value|0xf8
end_define

begin_comment
comment|/* ASI_BLOCK_PRIMARY_LITTLE              */
end_comment

begin_define
define|#
directive|define
name|ASI_BLK_SL
value|0xf9
end_define

begin_comment
comment|/* ASI_BLOCK_SECONDARY_LITTLE            */
end_comment

begin_define
define|#
directive|define
name|ASI_SCRATCHPAD_0_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|ASI_SCRATCHPAD_1_REG
value|0x08
end_define

begin_define
define|#
directive|define
name|ASI_SCRATCHPAD_2_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|ASI_SCRATCHPAD_3_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|ASI_SCRATCHPAD_6_REG
value|0x30
end_define

begin_define
define|#
directive|define
name|ASI_SCRATCHPAD_7_REG
value|0x38
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG_MMFSA
value|ASI_SCRATCHPAD_0_REG
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG_PCPU
value|ASI_SCRATCHPAD_1_REG
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG_HASH_KERNEL
value|ASI_SCRATCHPAD_2_REG
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG_TSB_KERNEL
value|ASI_SCRATCHPAD_3_REG
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG_HASH_USER
value|ASI_SCRATCHPAD_6_REG
end_define

begin_define
define|#
directive|define
name|SCRATCH_REG_TSB_USER
value|ASI_SCRATCHPAD_7_REG
end_define

begin_define
define|#
directive|define
name|MMU_CID_P
value|0x08
end_define

begin_define
define|#
directive|define
name|MMU_CID_S
value|0x10
end_define

begin_define
define|#
directive|define
name|CPU_MONDO_QUEUE_HEAD
value|0x3c0
end_define

begin_define
define|#
directive|define
name|CPU_MONDO_QUEUE_TAIL
value|0x3c8
end_define

begin_define
define|#
directive|define
name|DEV_MONDO_QUEUE_HEAD
value|0x3d0
end_define

begin_define
define|#
directive|define
name|DEV_MONDO_QUEUE_TAIL
value|0x3d8
end_define

begin_define
define|#
directive|define
name|RESUMABLE_ERROR_QUEUE_HEAD
value|0x3e0
end_define

begin_define
define|#
directive|define
name|RESUMABLE_ERROR_QUEUE_TAIL
value|0x3e8
end_define

begin_define
define|#
directive|define
name|NONRESUMABLE_ERROR_QUEUE_HEAD
value|0x3f0
end_define

begin_define
define|#
directive|define
name|NONRESUMABLE_ERROR_QUEUE_TAIL
value|0x3f8
end_define

begin_define
define|#
directive|define
name|Q
parameter_list|(
name|queue_head
parameter_list|)
value|(queue_head>> 4)
end_define

begin_comment
comment|/*  * sparc64 compat for the loader  */
end_comment

begin_define
define|#
directive|define
name|AA_IMMU_TAR
value|0x30
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
name|ASI_UPA_CONFIG_REG
value|0x4a
end_define

begin_comment
comment|/* US-I, II */
end_comment

begin_define
define|#
directive|define
name|ASI_IMMU
value|0x50
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
name|ASI_DMMU
value|0x58
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASI_H_ */
end_comment

end_unit

