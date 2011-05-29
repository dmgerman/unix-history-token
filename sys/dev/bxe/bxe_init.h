begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2011 Broadcom Corporation. All rights reserved.  *  *    Gary Zambrano<zambrano@broadcom.com>  *    David Christensen<davidch@broadcom.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Broadcom Corporation nor the name of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written consent.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BXE_INIT_H
end_ifndef

begin_define
define|#
directive|define
name|BXE_INIT_H
end_define

begin_comment
comment|/*  * bxe_init.h: Broadcom Everest network driver.  * Structures and macros needed during the initialization.  */
end_comment

begin_comment
comment|/* RAM0 size in bytes */
end_comment

begin_define
define|#
directive|define
name|STORM_INTMEM_SIZE_E1
value|0x5800
end_define

begin_define
define|#
directive|define
name|STORM_INTMEM_SIZE_E1H
value|0x10000
end_define

begin_define
define|#
directive|define
name|STORM_INTMEM_SIZE
parameter_list|(
name|sc
parameter_list|)
define|\
value|((CHIP_IS_E1(sc) ? STORM_INTMEM_SIZE_E1 : STORM_INTMEM_SIZE_E1H) / 4)
end_define

begin_comment
comment|/* Init operation types and structures */
end_comment

begin_comment
comment|/* Common for both E1 and E1H */
end_comment

begin_define
define|#
directive|define
name|OP_RD
value|0x1
end_define

begin_comment
comment|/* read single register */
end_comment

begin_define
define|#
directive|define
name|OP_WR
value|0x2
end_define

begin_comment
comment|/* write single register */
end_comment

begin_define
define|#
directive|define
name|OP_IW
value|0x3
end_define

begin_comment
comment|/* write single register using mailbox */
end_comment

begin_define
define|#
directive|define
name|OP_SW
value|0x4
end_define

begin_comment
comment|/* copy a string to the device */
end_comment

begin_define
define|#
directive|define
name|OP_SI
value|0x5
end_define

begin_comment
comment|/* copy a string using mailbox */
end_comment

begin_define
define|#
directive|define
name|OP_ZR
value|0x6
end_define

begin_comment
comment|/* clear memory */
end_comment

begin_define
define|#
directive|define
name|OP_ZP
value|0x7
end_define

begin_comment
comment|/* unzip then copy with DMAE */
end_comment

begin_define
define|#
directive|define
name|OP_WR_64
value|0x8
end_define

begin_comment
comment|/* write 64 bit pattern */
end_comment

begin_define
define|#
directive|define
name|OP_WB
value|0x9
end_define

begin_comment
comment|/* copy a string using DMAE */
end_comment

begin_comment
comment|/* FPGA and EMUL specific operations */
end_comment

begin_define
define|#
directive|define
name|OP_WR_EMUL
value|0xa
end_define

begin_comment
comment|/* write single register on Emulation */
end_comment

begin_define
define|#
directive|define
name|OP_WR_FPGA
value|0xb
end_define

begin_comment
comment|/* write single register on FPGA */
end_comment

begin_define
define|#
directive|define
name|OP_WR_ASIC
value|0xc
end_define

begin_comment
comment|/* write single register on ASIC */
end_comment

begin_comment
comment|/* Init stages */
end_comment

begin_comment
comment|/* Never reorder stages !!! */
end_comment

begin_define
define|#
directive|define
name|COMMON_STAGE
value|0
end_define

begin_define
define|#
directive|define
name|PORT0_STAGE
value|1
end_define

begin_define
define|#
directive|define
name|PORT1_STAGE
value|2
end_define

begin_define
define|#
directive|define
name|FUNC0_STAGE
value|3
end_define

begin_define
define|#
directive|define
name|FUNC1_STAGE
value|4
end_define

begin_define
define|#
directive|define
name|FUNC2_STAGE
value|5
end_define

begin_define
define|#
directive|define
name|FUNC3_STAGE
value|6
end_define

begin_define
define|#
directive|define
name|FUNC4_STAGE
value|7
end_define

begin_define
define|#
directive|define
name|FUNC5_STAGE
value|8
end_define

begin_define
define|#
directive|define
name|FUNC6_STAGE
value|9
end_define

begin_define
define|#
directive|define
name|FUNC7_STAGE
value|10
end_define

begin_define
define|#
directive|define
name|STAGE_IDX_MAX
value|11
end_define

begin_define
define|#
directive|define
name|STAGE_START
value|0
end_define

begin_define
define|#
directive|define
name|STAGE_END
value|1
end_define

begin_comment
comment|/* Indices of blocks */
end_comment

begin_define
define|#
directive|define
name|PRS_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|SRCH_BLOCK
value|1
end_define

begin_define
define|#
directive|define
name|TSDM_BLOCK
value|2
end_define

begin_define
define|#
directive|define
name|TCM_BLOCK
value|3
end_define

begin_define
define|#
directive|define
name|BRB1_BLOCK
value|4
end_define

begin_define
define|#
directive|define
name|TSEM_BLOCK
value|5
end_define

begin_define
define|#
directive|define
name|PXPCS_BLOCK
value|6
end_define

begin_define
define|#
directive|define
name|EMAC0_BLOCK
value|7
end_define

begin_define
define|#
directive|define
name|EMAC1_BLOCK
value|8
end_define

begin_define
define|#
directive|define
name|DBU_BLOCK
value|9
end_define

begin_define
define|#
directive|define
name|MISC_BLOCK
value|10
end_define

begin_define
define|#
directive|define
name|DBG_BLOCK
value|11
end_define

begin_define
define|#
directive|define
name|NIG_BLOCK
value|12
end_define

begin_define
define|#
directive|define
name|MCP_BLOCK
value|13
end_define

begin_define
define|#
directive|define
name|UPB_BLOCK
value|14
end_define

begin_define
define|#
directive|define
name|CSDM_BLOCK
value|15
end_define

begin_define
define|#
directive|define
name|USDM_BLOCK
value|16
end_define

begin_define
define|#
directive|define
name|CCM_BLOCK
value|17
end_define

begin_define
define|#
directive|define
name|UCM_BLOCK
value|18
end_define

begin_define
define|#
directive|define
name|USEM_BLOCK
value|19
end_define

begin_define
define|#
directive|define
name|CSEM_BLOCK
value|20
end_define

begin_define
define|#
directive|define
name|XPB_BLOCK
value|21
end_define

begin_define
define|#
directive|define
name|DQ_BLOCK
value|22
end_define

begin_define
define|#
directive|define
name|TIMERS_BLOCK
value|23
end_define

begin_define
define|#
directive|define
name|XSDM_BLOCK
value|24
end_define

begin_define
define|#
directive|define
name|QM_BLOCK
value|25
end_define

begin_define
define|#
directive|define
name|PBF_BLOCK
value|26
end_define

begin_define
define|#
directive|define
name|XCM_BLOCK
value|27
end_define

begin_define
define|#
directive|define
name|XSEM_BLOCK
value|28
end_define

begin_define
define|#
directive|define
name|CDU_BLOCK
value|29
end_define

begin_define
define|#
directive|define
name|DMAE_BLOCK
value|30
end_define

begin_define
define|#
directive|define
name|PXP_BLOCK
value|31
end_define

begin_define
define|#
directive|define
name|CFC_BLOCK
value|32
end_define

begin_define
define|#
directive|define
name|HC_BLOCK
value|33
end_define

begin_define
define|#
directive|define
name|PXP2_BLOCK
value|34
end_define

begin_define
define|#
directive|define
name|MISC_AEU_BLOCK
value|35
end_define

begin_define
define|#
directive|define
name|PGLUE_B_BLOCK
value|36
end_define

begin_define
define|#
directive|define
name|IGU_BLOCK
value|37
end_define

begin_comment
comment|/* Returns the index of start or end of a specific block stage in ops array. */
end_comment

begin_define
define|#
directive|define
name|BLOCK_OPS_IDX
parameter_list|(
name|block
parameter_list|,
name|stage
parameter_list|,
name|end
parameter_list|)
define|\
value|(2 * (((block) * STAGE_IDX_MAX) + (stage)) + (end))
end_define

begin_struct
struct|struct
name|raw_op
block|{
name|uint32_t
name|op
range|:
literal|8
decl_stmt|;
name|uint32_t
name|offset
range|:
literal|24
decl_stmt|;
name|uint32_t
name|raw_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|op_read
block|{
name|uint32_t
name|op
range|:
literal|8
decl_stmt|;
name|uint32_t
name|offset
range|:
literal|24
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|op_write
block|{
name|uint32_t
name|op
range|:
literal|8
decl_stmt|;
name|uint32_t
name|offset
range|:
literal|24
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|op_string_write
block|{
name|uint32_t
name|op
range|:
literal|8
decl_stmt|;
name|uint32_t
name|offset
range|:
literal|24
decl_stmt|;
ifdef|#
directive|ifdef
name|__LITTLE_ENDIAN
name|uint16_t
name|data_off
decl_stmt|;
name|uint16_t
name|data_len
decl_stmt|;
else|#
directive|else
comment|/* __BIG_ENDIAN */
name|uint16_t
name|data_len
decl_stmt|;
name|uint16_t
name|data_off
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|op_zero
block|{
name|uint32_t
name|op
range|:
literal|8
decl_stmt|;
name|uint32_t
name|offset
range|:
literal|24
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|init_op
block|{
name|struct
name|op_read
name|read
decl_stmt|;
name|struct
name|op_write
name|write
decl_stmt|;
name|struct
name|op_string_write
name|str_wr
decl_stmt|;
name|struct
name|op_zero
name|zero
decl_stmt|;
name|struct
name|raw_op
name|raw
decl_stmt|;
block|}
union|;
end_union

begin_include
include|#
directive|include
file|"bxe_init_values_e1.h"
end_include

begin_include
include|#
directive|include
file|"bxe_init_values_e1h.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BXE_INIT_H */
end_comment

end_unit

