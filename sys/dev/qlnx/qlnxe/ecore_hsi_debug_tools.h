begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_DEBUG_TOOLS__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_DEBUG_TOOLS__
end_define

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/* Debug Tools HSI constants and macros */
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_enum
enum|enum
name|block_addr
block|{
name|GRCBASE_GRC
init|=
literal|0x50000
block|,
name|GRCBASE_MISCS
init|=
literal|0x9000
block|,
name|GRCBASE_MISC
init|=
literal|0x8000
block|,
name|GRCBASE_DBU
init|=
literal|0xa000
block|,
name|GRCBASE_PGLUE_B
init|=
literal|0x2a8000
block|,
name|GRCBASE_CNIG
init|=
literal|0x218000
block|,
name|GRCBASE_CPMU
init|=
literal|0x30000
block|,
name|GRCBASE_NCSI
init|=
literal|0x40000
block|,
name|GRCBASE_OPTE
init|=
literal|0x53000
block|,
name|GRCBASE_BMB
init|=
literal|0x540000
block|,
name|GRCBASE_PCIE
init|=
literal|0x54000
block|,
name|GRCBASE_MCP
init|=
literal|0xe00000
block|,
name|GRCBASE_MCP2
init|=
literal|0x52000
block|,
name|GRCBASE_PSWHST
init|=
literal|0x2a0000
block|,
name|GRCBASE_PSWHST2
init|=
literal|0x29e000
block|,
name|GRCBASE_PSWRD
init|=
literal|0x29c000
block|,
name|GRCBASE_PSWRD2
init|=
literal|0x29d000
block|,
name|GRCBASE_PSWWR
init|=
literal|0x29a000
block|,
name|GRCBASE_PSWWR2
init|=
literal|0x29b000
block|,
name|GRCBASE_PSWRQ
init|=
literal|0x280000
block|,
name|GRCBASE_PSWRQ2
init|=
literal|0x240000
block|,
name|GRCBASE_PGLCS
init|=
literal|0x0
block|,
name|GRCBASE_DMAE
init|=
literal|0xc000
block|,
name|GRCBASE_PTU
init|=
literal|0x560000
block|,
name|GRCBASE_TCM
init|=
literal|0x1180000
block|,
name|GRCBASE_MCM
init|=
literal|0x1200000
block|,
name|GRCBASE_UCM
init|=
literal|0x1280000
block|,
name|GRCBASE_XCM
init|=
literal|0x1000000
block|,
name|GRCBASE_YCM
init|=
literal|0x1080000
block|,
name|GRCBASE_PCM
init|=
literal|0x1100000
block|,
name|GRCBASE_QM
init|=
literal|0x2f0000
block|,
name|GRCBASE_TM
init|=
literal|0x2c0000
block|,
name|GRCBASE_DORQ
init|=
literal|0x100000
block|,
name|GRCBASE_BRB
init|=
literal|0x340000
block|,
name|GRCBASE_SRC
init|=
literal|0x238000
block|,
name|GRCBASE_PRS
init|=
literal|0x1f0000
block|,
name|GRCBASE_TSDM
init|=
literal|0xfb0000
block|,
name|GRCBASE_MSDM
init|=
literal|0xfc0000
block|,
name|GRCBASE_USDM
init|=
literal|0xfd0000
block|,
name|GRCBASE_XSDM
init|=
literal|0xf80000
block|,
name|GRCBASE_YSDM
init|=
literal|0xf90000
block|,
name|GRCBASE_PSDM
init|=
literal|0xfa0000
block|,
name|GRCBASE_TSEM
init|=
literal|0x1700000
block|,
name|GRCBASE_MSEM
init|=
literal|0x1800000
block|,
name|GRCBASE_USEM
init|=
literal|0x1900000
block|,
name|GRCBASE_XSEM
init|=
literal|0x1400000
block|,
name|GRCBASE_YSEM
init|=
literal|0x1500000
block|,
name|GRCBASE_PSEM
init|=
literal|0x1600000
block|,
name|GRCBASE_RSS
init|=
literal|0x238800
block|,
name|GRCBASE_TMLD
init|=
literal|0x4d0000
block|,
name|GRCBASE_MULD
init|=
literal|0x4e0000
block|,
name|GRCBASE_YULD
init|=
literal|0x4c8000
block|,
name|GRCBASE_XYLD
init|=
literal|0x4c0000
block|,
name|GRCBASE_PTLD
init|=
literal|0x590000
block|,
name|GRCBASE_YPLD
init|=
literal|0x5b0000
block|,
name|GRCBASE_PRM
init|=
literal|0x230000
block|,
name|GRCBASE_PBF_PB1
init|=
literal|0xda0000
block|,
name|GRCBASE_PBF_PB2
init|=
literal|0xda4000
block|,
name|GRCBASE_RPB
init|=
literal|0x23c000
block|,
name|GRCBASE_BTB
init|=
literal|0xdb0000
block|,
name|GRCBASE_PBF
init|=
literal|0xd80000
block|,
name|GRCBASE_RDIF
init|=
literal|0x300000
block|,
name|GRCBASE_TDIF
init|=
literal|0x310000
block|,
name|GRCBASE_CDU
init|=
literal|0x580000
block|,
name|GRCBASE_CCFC
init|=
literal|0x2e0000
block|,
name|GRCBASE_TCFC
init|=
literal|0x2d0000
block|,
name|GRCBASE_IGU
init|=
literal|0x180000
block|,
name|GRCBASE_CAU
init|=
literal|0x1c0000
block|,
name|GRCBASE_RGFS
init|=
literal|0xf00000
block|,
name|GRCBASE_RGSRC
init|=
literal|0x320000
block|,
name|GRCBASE_TGFS
init|=
literal|0xd00000
block|,
name|GRCBASE_TGSRC
init|=
literal|0x322000
block|,
name|GRCBASE_UMAC
init|=
literal|0x51000
block|,
name|GRCBASE_XMAC
init|=
literal|0x210000
block|,
name|GRCBASE_DBG
init|=
literal|0x10000
block|,
name|GRCBASE_NIG
init|=
literal|0x500000
block|,
name|GRCBASE_WOL
init|=
literal|0x600000
block|,
name|GRCBASE_BMBN
init|=
literal|0x610000
block|,
name|GRCBASE_IPC
init|=
literal|0x20000
block|,
name|GRCBASE_NWM
init|=
literal|0x800000
block|,
name|GRCBASE_NWS
init|=
literal|0x700000
block|,
name|GRCBASE_MS
init|=
literal|0x6a0000
block|,
name|GRCBASE_PHY_PCIE
init|=
literal|0x620000
block|,
name|GRCBASE_LED
init|=
literal|0x6b8000
block|,
name|GRCBASE_AVS_WRAP
init|=
literal|0x6b0000
block|,
name|GRCBASE_MISC_AEU
init|=
literal|0x8000
block|,
name|GRCBASE_BAR0_MAP
init|=
literal|0x1c00000
block|,
name|MAX_BLOCK_ADDR
block|}
enum|;
end_enum

begin_enum
enum|enum
name|block_id
block|{
name|BLOCK_GRC
block|,
name|BLOCK_MISCS
block|,
name|BLOCK_MISC
block|,
name|BLOCK_DBU
block|,
name|BLOCK_PGLUE_B
block|,
name|BLOCK_CNIG
block|,
name|BLOCK_CPMU
block|,
name|BLOCK_NCSI
block|,
name|BLOCK_OPTE
block|,
name|BLOCK_BMB
block|,
name|BLOCK_PCIE
block|,
name|BLOCK_MCP
block|,
name|BLOCK_MCP2
block|,
name|BLOCK_PSWHST
block|,
name|BLOCK_PSWHST2
block|,
name|BLOCK_PSWRD
block|,
name|BLOCK_PSWRD2
block|,
name|BLOCK_PSWWR
block|,
name|BLOCK_PSWWR2
block|,
name|BLOCK_PSWRQ
block|,
name|BLOCK_PSWRQ2
block|,
name|BLOCK_PGLCS
block|,
name|BLOCK_DMAE
block|,
name|BLOCK_PTU
block|,
name|BLOCK_TCM
block|,
name|BLOCK_MCM
block|,
name|BLOCK_UCM
block|,
name|BLOCK_XCM
block|,
name|BLOCK_YCM
block|,
name|BLOCK_PCM
block|,
name|BLOCK_QM
block|,
name|BLOCK_TM
block|,
name|BLOCK_DORQ
block|,
name|BLOCK_BRB
block|,
name|BLOCK_SRC
block|,
name|BLOCK_PRS
block|,
name|BLOCK_TSDM
block|,
name|BLOCK_MSDM
block|,
name|BLOCK_USDM
block|,
name|BLOCK_XSDM
block|,
name|BLOCK_YSDM
block|,
name|BLOCK_PSDM
block|,
name|BLOCK_TSEM
block|,
name|BLOCK_MSEM
block|,
name|BLOCK_USEM
block|,
name|BLOCK_XSEM
block|,
name|BLOCK_YSEM
block|,
name|BLOCK_PSEM
block|,
name|BLOCK_RSS
block|,
name|BLOCK_TMLD
block|,
name|BLOCK_MULD
block|,
name|BLOCK_YULD
block|,
name|BLOCK_XYLD
block|,
name|BLOCK_PTLD
block|,
name|BLOCK_YPLD
block|,
name|BLOCK_PRM
block|,
name|BLOCK_PBF_PB1
block|,
name|BLOCK_PBF_PB2
block|,
name|BLOCK_RPB
block|,
name|BLOCK_BTB
block|,
name|BLOCK_PBF
block|,
name|BLOCK_RDIF
block|,
name|BLOCK_TDIF
block|,
name|BLOCK_CDU
block|,
name|BLOCK_CCFC
block|,
name|BLOCK_TCFC
block|,
name|BLOCK_IGU
block|,
name|BLOCK_CAU
block|,
name|BLOCK_RGFS
block|,
name|BLOCK_RGSRC
block|,
name|BLOCK_TGFS
block|,
name|BLOCK_TGSRC
block|,
name|BLOCK_UMAC
block|,
name|BLOCK_XMAC
block|,
name|BLOCK_DBG
block|,
name|BLOCK_NIG
block|,
name|BLOCK_WOL
block|,
name|BLOCK_BMBN
block|,
name|BLOCK_IPC
block|,
name|BLOCK_NWM
block|,
name|BLOCK_NWS
block|,
name|BLOCK_MS
block|,
name|BLOCK_PHY_PCIE
block|,
name|BLOCK_LED
block|,
name|BLOCK_AVS_WRAP
block|,
name|BLOCK_MISC_AEU
block|,
name|BLOCK_BAR0_MAP
block|,
name|MAX_BLOCK_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * binary debug buffer types  */
end_comment

begin_enum
enum|enum
name|bin_dbg_buffer_type
block|{
name|BIN_BUF_DBG_MODE_TREE
comment|/* init modes tree */
block|,
name|BIN_BUF_DBG_DUMP_REG
comment|/* GRC Dump registers */
block|,
name|BIN_BUF_DBG_DUMP_MEM
comment|/* GRC Dump memories */
block|,
name|BIN_BUF_DBG_IDLE_CHK_REGS
comment|/* Idle Check registers */
block|,
name|BIN_BUF_DBG_IDLE_CHK_IMMS
comment|/* Idle Check immediates */
block|,
name|BIN_BUF_DBG_IDLE_CHK_RULES
comment|/* Idle Check rules */
block|,
name|BIN_BUF_DBG_IDLE_CHK_PARSING_DATA
comment|/* Idle Check parsing data */
block|,
name|BIN_BUF_DBG_ATTN_BLOCKS
comment|/* Attention blocks */
block|,
name|BIN_BUF_DBG_ATTN_REGS
comment|/* Attention registers */
block|,
name|BIN_BUF_DBG_ATTN_INDEXES
comment|/* Attention indexes */
block|,
name|BIN_BUF_DBG_ATTN_NAME_OFFSETS
comment|/* Attention name offsets */
block|,
name|BIN_BUF_DBG_BUS_BLOCKS
comment|/* Debug Bus blocks */
block|,
name|BIN_BUF_DBG_BUS_LINES
comment|/* Debug Bus lines */
block|,
name|BIN_BUF_DBG_BUS_BLOCKS_USER_DATA
comment|/* Debug Bus blocks user data */
block|,
name|BIN_BUF_DBG_BUS_LINE_NAME_OFFSETS
comment|/* Debug Bus line name offsets */
block|,
name|BIN_BUF_DBG_PARSING_STRINGS
comment|/* Debug Tools parsing strings */
block|,
name|MAX_BIN_DBG_BUFFER_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Attention bit mapping  */
end_comment

begin_struct
struct|struct
name|dbg_attn_bit_mapping
block|{
name|__le16
name|data
decl_stmt|;
define|#
directive|define
name|DBG_ATTN_BIT_MAPPING_VAL_MASK
value|0x7FFF
comment|/* The index of an attention in the blocks attentions list (if is_unused_bit_cnt=0), or a number of consecutive unused attention bits (if is_unused_bit_cnt=1) */
define|#
directive|define
name|DBG_ATTN_BIT_MAPPING_VAL_SHIFT
value|0
define|#
directive|define
name|DBG_ATTN_BIT_MAPPING_IS_UNUSED_BIT_CNT_MASK
value|0x1
comment|/* if set, the val field indicates the number of consecutive unused attention bits */
define|#
directive|define
name|DBG_ATTN_BIT_MAPPING_IS_UNUSED_BIT_CNT_SHIFT
value|15
block|}
struct|;
end_struct

begin_comment
comment|/*  * Attention block per-type data  */
end_comment

begin_struct
struct|struct
name|dbg_attn_block_type_data
block|{
name|__le16
name|names_offset
comment|/* Offset of this block attention names in the debug attention name offsets array */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
name|u8
name|num_regs
comment|/* Number of attention registers in this block */
decl_stmt|;
name|u8
name|reserved2
decl_stmt|;
name|__le16
name|regs_offset
comment|/* Offset of this blocks attention registers in the attention registers array (in dbg_attn_reg units) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Block attentions  */
end_comment

begin_struct
struct|struct
name|dbg_attn_block
block|{
name|struct
name|dbg_attn_block_type_data
name|per_type_data
index|[
literal|2
index|]
comment|/* attention block per-type data. Count must match the number of elements in dbg_attn_type. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Attention register result  */
end_comment

begin_struct
struct|struct
name|dbg_attn_reg_result
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|DBG_ATTN_REG_RESULT_STS_ADDRESS_MASK
value|0xFFFFFF
comment|/* STS attention register GRC address (in dwords) */
define|#
directive|define
name|DBG_ATTN_REG_RESULT_STS_ADDRESS_SHIFT
value|0
define|#
directive|define
name|DBG_ATTN_REG_RESULT_NUM_REG_ATTN_MASK
value|0xFF
comment|/* Number of attention indexes in this register */
define|#
directive|define
name|DBG_ATTN_REG_RESULT_NUM_REG_ATTN_SHIFT
value|24
name|__le16
name|block_attn_offset
comment|/* The offset of this registers attentions within the blocks attentions list (a value in the range 0..number of block attentions-1) */
decl_stmt|;
name|__le16
name|reserved
decl_stmt|;
name|__le32
name|sts_val
comment|/* Value read from the STS attention register */
decl_stmt|;
name|__le32
name|mask_val
comment|/* Value read from the MASK attention register */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Attention block result  */
end_comment

begin_struct
struct|struct
name|dbg_attn_block_result
block|{
name|u8
name|block_id
comment|/* Registers block ID */
decl_stmt|;
name|u8
name|data
decl_stmt|;
define|#
directive|define
name|DBG_ATTN_BLOCK_RESULT_ATTN_TYPE_MASK
value|0x3
comment|/* Value from dbg_attn_type enum */
define|#
directive|define
name|DBG_ATTN_BLOCK_RESULT_ATTN_TYPE_SHIFT
value|0
define|#
directive|define
name|DBG_ATTN_BLOCK_RESULT_NUM_REGS_MASK
value|0x3F
comment|/* Number of registers in the block in which at least one attention bit is set */
define|#
directive|define
name|DBG_ATTN_BLOCK_RESULT_NUM_REGS_SHIFT
value|2
name|__le16
name|names_offset
comment|/* Offset of this registers block attention names in the attention name offsets array */
decl_stmt|;
name|struct
name|dbg_attn_reg_result
name|reg_results
index|[
literal|15
index|]
comment|/* result data for each register in the block in which at least one attention bit is set */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * mode header  */
end_comment

begin_struct
struct|struct
name|dbg_mode_hdr
block|{
name|__le16
name|data
decl_stmt|;
define|#
directive|define
name|DBG_MODE_HDR_EVAL_MODE_MASK
value|0x1
comment|/* indicates if a mode expression should be evaluated (0/1) */
define|#
directive|define
name|DBG_MODE_HDR_EVAL_MODE_SHIFT
value|0
define|#
directive|define
name|DBG_MODE_HDR_MODES_BUF_OFFSET_MASK
value|0x7FFF
comment|/* offset (in bytes) in modes expression buffer. valid only if eval_mode is set. */
define|#
directive|define
name|DBG_MODE_HDR_MODES_BUF_OFFSET_SHIFT
value|1
block|}
struct|;
end_struct

begin_comment
comment|/*  * Attention register  */
end_comment

begin_struct
struct|struct
name|dbg_attn_reg
block|{
name|struct
name|dbg_mode_hdr
name|mode
comment|/* Mode header */
decl_stmt|;
name|__le16
name|block_attn_offset
comment|/* The offset of this registers attentions within the blocks attentions list (a value in the range 0..number of block attentions-1) */
decl_stmt|;
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|DBG_ATTN_REG_STS_ADDRESS_MASK
value|0xFFFFFF
comment|/* STS attention register GRC address (in dwords) */
define|#
directive|define
name|DBG_ATTN_REG_STS_ADDRESS_SHIFT
value|0
define|#
directive|define
name|DBG_ATTN_REG_NUM_REG_ATTN_MASK
value|0xFF
comment|/* Number of attention in this register */
define|#
directive|define
name|DBG_ATTN_REG_NUM_REG_ATTN_SHIFT
value|24
name|__le32
name|sts_clr_address
comment|/* STS_CLR attention register GRC address (in dwords) */
decl_stmt|;
name|__le32
name|mask_address
comment|/* MASK attention register GRC address (in dwords) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * attention types  */
end_comment

begin_enum
enum|enum
name|dbg_attn_type
block|{
name|ATTN_TYPE_INTERRUPT
block|,
name|ATTN_TYPE_PARITY
block|,
name|MAX_DBG_ATTN_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug Bus block data  */
end_comment

begin_struct
struct|struct
name|dbg_bus_block
block|{
name|u8
name|num_of_lines
comment|/* Number of debug lines in this block (excluding signature and latency events). */
decl_stmt|;
name|u8
name|has_latency_events
comment|/* Indicates if this block has a latency events debug line (0/1). */
decl_stmt|;
name|__le16
name|lines_offset
comment|/* Offset of this blocks lines in the Debug Bus lines array. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug Bus block user data  */
end_comment

begin_struct
struct|struct
name|dbg_bus_block_user_data
block|{
name|u8
name|num_of_lines
comment|/* Number of debug lines in this block (excluding signature and latency events). */
decl_stmt|;
name|u8
name|has_latency_events
comment|/* Indicates if this block has a latency events debug line (0/1). */
decl_stmt|;
name|__le16
name|names_offset
comment|/* Offset of this blocks lines in the debug bus line name offsets array. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Block Debug line data  */
end_comment

begin_struct
struct|struct
name|dbg_bus_line
block|{
name|u8
name|data
decl_stmt|;
define|#
directive|define
name|DBG_BUS_LINE_NUM_OF_GROUPS_MASK
value|0xF
comment|/* Number of groups in the line (0-3) */
define|#
directive|define
name|DBG_BUS_LINE_NUM_OF_GROUPS_SHIFT
value|0
define|#
directive|define
name|DBG_BUS_LINE_IS_256B_MASK
value|0x1
comment|/* Indicates if this is a 128b line (0) or a 256b line (1). */
define|#
directive|define
name|DBG_BUS_LINE_IS_256B_SHIFT
value|4
define|#
directive|define
name|DBG_BUS_LINE_RESERVED_MASK
value|0x7
define|#
directive|define
name|DBG_BUS_LINE_RESERVED_SHIFT
value|5
name|u8
name|group_sizes
comment|/* Four 2-bit values, indicating the size of each group minus 1 (i.e. value=0 means size=1, value=1 means size=2, etc), starting from lsb. The sizes are in dwords (if is_256b=0) or in qwords (if is_256b=1). */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * condition header for registers dump  */
end_comment

begin_struct
struct|struct
name|dbg_dump_cond_hdr
block|{
name|struct
name|dbg_mode_hdr
name|mode
comment|/* Mode header */
decl_stmt|;
name|u8
name|block_id
comment|/* block ID */
decl_stmt|;
name|u8
name|data_size
comment|/* size in dwords of the data following this header */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * memory data for registers dump  */
end_comment

begin_struct
struct|struct
name|dbg_dump_mem
block|{
name|__le32
name|dword0
decl_stmt|;
define|#
directive|define
name|DBG_DUMP_MEM_ADDRESS_MASK
value|0xFFFFFF
comment|/* register address (in dwords) */
define|#
directive|define
name|DBG_DUMP_MEM_ADDRESS_SHIFT
value|0
define|#
directive|define
name|DBG_DUMP_MEM_MEM_GROUP_ID_MASK
value|0xFF
comment|/* memory group ID */
define|#
directive|define
name|DBG_DUMP_MEM_MEM_GROUP_ID_SHIFT
value|24
name|__le32
name|dword1
decl_stmt|;
define|#
directive|define
name|DBG_DUMP_MEM_LENGTH_MASK
value|0xFFFFFF
comment|/* register size (in dwords) */
define|#
directive|define
name|DBG_DUMP_MEM_LENGTH_SHIFT
value|0
define|#
directive|define
name|DBG_DUMP_MEM_WIDE_BUS_MASK
value|0x1
comment|/* indicates if the register is wide-bus */
define|#
directive|define
name|DBG_DUMP_MEM_WIDE_BUS_SHIFT
value|24
define|#
directive|define
name|DBG_DUMP_MEM_RESERVED_MASK
value|0x7F
define|#
directive|define
name|DBG_DUMP_MEM_RESERVED_SHIFT
value|25
block|}
struct|;
end_struct

begin_comment
comment|/*  * register data for registers dump  */
end_comment

begin_struct
struct|struct
name|dbg_dump_reg
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|DBG_DUMP_REG_ADDRESS_MASK
value|0x7FFFFF
comment|/* register address (in dwords) */
define|#
directive|define
name|DBG_DUMP_REG_ADDRESS_SHIFT
value|0
define|#
directive|define
name|DBG_DUMP_REG_WIDE_BUS_MASK
value|0x1
comment|/* indicates if the register is wide-bus */
define|#
directive|define
name|DBG_DUMP_REG_WIDE_BUS_SHIFT
value|23
define|#
directive|define
name|DBG_DUMP_REG_LENGTH_MASK
value|0xFF
comment|/* register size (in dwords) */
define|#
directive|define
name|DBG_DUMP_REG_LENGTH_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * split header for registers dump  */
end_comment

begin_struct
struct|struct
name|dbg_dump_split_hdr
block|{
name|__le32
name|hdr
decl_stmt|;
define|#
directive|define
name|DBG_DUMP_SPLIT_HDR_DATA_SIZE_MASK
value|0xFFFFFF
comment|/* size in dwords of the data following this header */
define|#
directive|define
name|DBG_DUMP_SPLIT_HDR_DATA_SIZE_SHIFT
value|0
define|#
directive|define
name|DBG_DUMP_SPLIT_HDR_SPLIT_TYPE_ID_MASK
value|0xFF
comment|/* split type ID */
define|#
directive|define
name|DBG_DUMP_SPLIT_HDR_SPLIT_TYPE_ID_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * condition header for idle check  */
end_comment

begin_struct
struct|struct
name|dbg_idle_chk_cond_hdr
block|{
name|struct
name|dbg_mode_hdr
name|mode
comment|/* Mode header */
decl_stmt|;
name|__le16
name|data_size
comment|/* size in dwords of the data following this header */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Idle Check condition register  */
end_comment

begin_struct
struct|struct
name|dbg_idle_chk_cond_reg
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|DBG_IDLE_CHK_COND_REG_ADDRESS_MASK
value|0x7FFFFF
comment|/* Register GRC address (in dwords) */
define|#
directive|define
name|DBG_IDLE_CHK_COND_REG_ADDRESS_SHIFT
value|0
define|#
directive|define
name|DBG_IDLE_CHK_COND_REG_WIDE_BUS_MASK
value|0x1
comment|/* indicates if the register is wide-bus */
define|#
directive|define
name|DBG_IDLE_CHK_COND_REG_WIDE_BUS_SHIFT
value|23
define|#
directive|define
name|DBG_IDLE_CHK_COND_REG_BLOCK_ID_MASK
value|0xFF
comment|/* value from block_id enum */
define|#
directive|define
name|DBG_IDLE_CHK_COND_REG_BLOCK_ID_SHIFT
value|24
name|__le16
name|num_entries
comment|/* number of registers entries to check */
decl_stmt|;
name|u8
name|entry_size
comment|/* size of registers entry (in dwords) */
decl_stmt|;
name|u8
name|start_entry
comment|/* index of the first entry to check */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Idle Check info register  */
end_comment

begin_struct
struct|struct
name|dbg_idle_chk_info_reg
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|DBG_IDLE_CHK_INFO_REG_ADDRESS_MASK
value|0x7FFFFF
comment|/* Register GRC address (in dwords) */
define|#
directive|define
name|DBG_IDLE_CHK_INFO_REG_ADDRESS_SHIFT
value|0
define|#
directive|define
name|DBG_IDLE_CHK_INFO_REG_WIDE_BUS_MASK
value|0x1
comment|/* indicates if the register is wide-bus */
define|#
directive|define
name|DBG_IDLE_CHK_INFO_REG_WIDE_BUS_SHIFT
value|23
define|#
directive|define
name|DBG_IDLE_CHK_INFO_REG_BLOCK_ID_MASK
value|0xFF
comment|/* value from block_id enum */
define|#
directive|define
name|DBG_IDLE_CHK_INFO_REG_BLOCK_ID_SHIFT
value|24
name|__le16
name|size
comment|/* register size in dwords */
decl_stmt|;
name|struct
name|dbg_mode_hdr
name|mode
comment|/* Mode header */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Idle Check register  */
end_comment

begin_union
union|union
name|dbg_idle_chk_reg
block|{
name|struct
name|dbg_idle_chk_cond_reg
name|cond_reg
comment|/* condition register */
decl_stmt|;
name|struct
name|dbg_idle_chk_info_reg
name|info_reg
comment|/* info register */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Idle Check result header  */
end_comment

begin_struct
struct|struct
name|dbg_idle_chk_result_hdr
block|{
name|__le16
name|rule_id
comment|/* Failing rule index */
decl_stmt|;
name|__le16
name|mem_entry_id
comment|/* Failing memory entry index */
decl_stmt|;
name|u8
name|num_dumped_cond_regs
comment|/* number of dumped condition registers */
decl_stmt|;
name|u8
name|num_dumped_info_regs
comment|/* number of dumped condition registers */
decl_stmt|;
name|u8
name|severity
comment|/* from dbg_idle_chk_severity_types enum */
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Idle Check result register header  */
end_comment

begin_struct
struct|struct
name|dbg_idle_chk_result_reg_hdr
block|{
name|u8
name|data
decl_stmt|;
define|#
directive|define
name|DBG_IDLE_CHK_RESULT_REG_HDR_IS_MEM_MASK
value|0x1
comment|/* indicates if this register is a memory */
define|#
directive|define
name|DBG_IDLE_CHK_RESULT_REG_HDR_IS_MEM_SHIFT
value|0
define|#
directive|define
name|DBG_IDLE_CHK_RESULT_REG_HDR_REG_ID_MASK
value|0x7F
comment|/* register index within the failing rule */
define|#
directive|define
name|DBG_IDLE_CHK_RESULT_REG_HDR_REG_ID_SHIFT
value|1
name|u8
name|start_entry
comment|/* index of the first checked entry */
decl_stmt|;
name|__le16
name|size
comment|/* register size in dwords */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Idle Check rule  */
end_comment

begin_struct
struct|struct
name|dbg_idle_chk_rule
block|{
name|__le16
name|rule_id
comment|/* Idle Check rule ID */
decl_stmt|;
name|u8
name|severity
comment|/* value from dbg_idle_chk_severity_types enum */
decl_stmt|;
name|u8
name|cond_id
comment|/* Condition ID */
decl_stmt|;
name|u8
name|num_cond_regs
comment|/* number of condition registers */
decl_stmt|;
name|u8
name|num_info_regs
comment|/* number of info registers */
decl_stmt|;
name|u8
name|num_imms
comment|/* number of immediates in the condition */
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
name|__le16
name|reg_offset
comment|/* offset of this rules registers in the idle check register array (in dbg_idle_chk_reg units) */
decl_stmt|;
name|__le16
name|imm_offset
comment|/* offset of this rules immediate values in the immediate values array (in dwords) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Idle Check rule parsing data  */
end_comment

begin_struct
struct|struct
name|dbg_idle_chk_rule_parsing_data
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|DBG_IDLE_CHK_RULE_PARSING_DATA_HAS_FW_MSG_MASK
value|0x1
comment|/* indicates if this register has a FW message */
define|#
directive|define
name|DBG_IDLE_CHK_RULE_PARSING_DATA_HAS_FW_MSG_SHIFT
value|0
define|#
directive|define
name|DBG_IDLE_CHK_RULE_PARSING_DATA_STR_OFFSET_MASK
value|0x7FFFFFFF
comment|/* Offset of this rules strings in the debug strings array (in bytes) */
define|#
directive|define
name|DBG_IDLE_CHK_RULE_PARSING_DATA_STR_OFFSET_SHIFT
value|1
block|}
struct|;
end_struct

begin_comment
comment|/*  * idle check severity types  */
end_comment

begin_enum
enum|enum
name|dbg_idle_chk_severity_types
block|{
name|IDLE_CHK_SEVERITY_ERROR
comment|/* idle check failure should cause an error */
block|,
name|IDLE_CHK_SEVERITY_ERROR_NO_TRAFFIC
comment|/* idle check failure should cause an error only if theres no traffic */
block|,
name|IDLE_CHK_SEVERITY_WARNING
comment|/* idle check failure should cause a warning */
block|,
name|MAX_DBG_IDLE_CHK_SEVERITY_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug Bus block data  */
end_comment

begin_struct
struct|struct
name|dbg_bus_block_data
block|{
name|__le16
name|data
decl_stmt|;
define|#
directive|define
name|DBG_BUS_BLOCK_DATA_ENABLE_MASK_MASK
value|0xF
comment|/* 4-bit value: bit i set -> dword/qword i is enabled. */
define|#
directive|define
name|DBG_BUS_BLOCK_DATA_ENABLE_MASK_SHIFT
value|0
define|#
directive|define
name|DBG_BUS_BLOCK_DATA_RIGHT_SHIFT_MASK
value|0xF
comment|/* Number of dwords/qwords to shift right the debug data (0-3) */
define|#
directive|define
name|DBG_BUS_BLOCK_DATA_RIGHT_SHIFT_SHIFT
value|4
define|#
directive|define
name|DBG_BUS_BLOCK_DATA_FORCE_VALID_MASK_MASK
value|0xF
comment|/* 4-bit value: bit i set -> dword/qword i is forced valid. */
define|#
directive|define
name|DBG_BUS_BLOCK_DATA_FORCE_VALID_MASK_SHIFT
value|8
define|#
directive|define
name|DBG_BUS_BLOCK_DATA_FORCE_FRAME_MASK_MASK
value|0xF
comment|/* 4-bit value: bit i set -> dword/qword i frame bit is forced. */
define|#
directive|define
name|DBG_BUS_BLOCK_DATA_FORCE_FRAME_MASK_SHIFT
value|12
name|u8
name|line_num
comment|/* Debug line number to select */
decl_stmt|;
name|u8
name|hw_id
comment|/* HW ID associated with the block */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug Bus Clients  */
end_comment

begin_enum
enum|enum
name|dbg_bus_clients
block|{
name|DBG_BUS_CLIENT_RBCN
block|,
name|DBG_BUS_CLIENT_RBCP
block|,
name|DBG_BUS_CLIENT_RBCR
block|,
name|DBG_BUS_CLIENT_RBCT
block|,
name|DBG_BUS_CLIENT_RBCU
block|,
name|DBG_BUS_CLIENT_RBCF
block|,
name|DBG_BUS_CLIENT_RBCX
block|,
name|DBG_BUS_CLIENT_RBCS
block|,
name|DBG_BUS_CLIENT_RBCH
block|,
name|DBG_BUS_CLIENT_RBCZ
block|,
name|DBG_BUS_CLIENT_OTHER_ENGINE
block|,
name|DBG_BUS_CLIENT_TIMESTAMP
block|,
name|DBG_BUS_CLIENT_CPU
block|,
name|DBG_BUS_CLIENT_RBCY
block|,
name|DBG_BUS_CLIENT_RBCQ
block|,
name|DBG_BUS_CLIENT_RBCM
block|,
name|DBG_BUS_CLIENT_RBCB
block|,
name|DBG_BUS_CLIENT_RBCW
block|,
name|DBG_BUS_CLIENT_RBCV
block|,
name|MAX_DBG_BUS_CLIENTS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug Bus constraint operation types  */
end_comment

begin_enum
enum|enum
name|dbg_bus_constraint_ops
block|{
name|DBG_BUS_CONSTRAINT_OP_EQ
comment|/* equal */
block|,
name|DBG_BUS_CONSTRAINT_OP_NE
comment|/* not equal */
block|,
name|DBG_BUS_CONSTRAINT_OP_LT
comment|/* less than */
block|,
name|DBG_BUS_CONSTRAINT_OP_LTC
comment|/* less than (cyclic) */
block|,
name|DBG_BUS_CONSTRAINT_OP_LE
comment|/* less than or equal */
block|,
name|DBG_BUS_CONSTRAINT_OP_LEC
comment|/* less than or equal (cyclic) */
block|,
name|DBG_BUS_CONSTRAINT_OP_GT
comment|/* greater than */
block|,
name|DBG_BUS_CONSTRAINT_OP_GTC
comment|/* greater than (cyclic) */
block|,
name|DBG_BUS_CONSTRAINT_OP_GE
comment|/* greater than or equal */
block|,
name|DBG_BUS_CONSTRAINT_OP_GEC
comment|/* greater than or equal (cyclic) */
block|,
name|MAX_DBG_BUS_CONSTRAINT_OPS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug Bus trigger state data  */
end_comment

begin_struct
struct|struct
name|dbg_bus_trigger_state_data
block|{
name|u8
name|data
decl_stmt|;
define|#
directive|define
name|DBG_BUS_TRIGGER_STATE_DATA_BLOCK_SHIFTED_ENABLE_MASK_MASK
value|0xF
comment|/* 4-bit value: bit i set -> dword i of the trigger state block (after right shift) is enabled. */
define|#
directive|define
name|DBG_BUS_TRIGGER_STATE_DATA_BLOCK_SHIFTED_ENABLE_MASK_SHIFT
value|0
define|#
directive|define
name|DBG_BUS_TRIGGER_STATE_DATA_CONSTRAINT_DWORD_MASK_MASK
value|0xF
comment|/* 4-bit value: bit i set -> dword i is compared by a constraint */
define|#
directive|define
name|DBG_BUS_TRIGGER_STATE_DATA_CONSTRAINT_DWORD_MASK_SHIFT
value|4
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug Bus memory address  */
end_comment

begin_struct
struct|struct
name|dbg_bus_mem_addr
block|{
name|__le32
name|lo
decl_stmt|;
name|__le32
name|hi
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug Bus PCI buffer data  */
end_comment

begin_struct
struct|struct
name|dbg_bus_pci_buf_data
block|{
name|struct
name|dbg_bus_mem_addr
name|phys_addr
comment|/* PCI buffer physical address */
decl_stmt|;
name|struct
name|dbg_bus_mem_addr
name|virt_addr
comment|/* PCI buffer virtual address */
decl_stmt|;
name|__le32
name|size
comment|/* PCI buffer size in bytes */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug Bus Storm EID range filter params  */
end_comment

begin_struct
struct|struct
name|dbg_bus_storm_eid_range_params
block|{
name|u8
name|min
comment|/* Minimal event ID to filter on */
decl_stmt|;
name|u8
name|max
comment|/* Maximal event ID to filter on */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug Bus Storm EID mask filter params  */
end_comment

begin_struct
struct|struct
name|dbg_bus_storm_eid_mask_params
block|{
name|u8
name|val
comment|/* Event ID value */
decl_stmt|;
name|u8
name|mask
comment|/* Event ID mask. 1s in the mask = dont care bits. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug Bus Storm EID filter params  */
end_comment

begin_union
union|union
name|dbg_bus_storm_eid_params
block|{
name|struct
name|dbg_bus_storm_eid_range_params
name|range
comment|/* EID range filter params */
decl_stmt|;
name|struct
name|dbg_bus_storm_eid_mask_params
name|mask
comment|/* EID mask filter params */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Debug Bus Storm data  */
end_comment

begin_struct
struct|struct
name|dbg_bus_storm_data
block|{
name|u8
name|enabled
comment|/* indicates if the Storm is enabled for recording */
decl_stmt|;
name|u8
name|mode
comment|/* Storm debug mode, valid only if the Storm is enabled */
decl_stmt|;
name|u8
name|hw_id
comment|/* HW ID associated with the Storm */
decl_stmt|;
name|u8
name|eid_filter_en
comment|/* Indicates if EID filtering is performed (0/1) */
decl_stmt|;
name|u8
name|eid_range_not_mask
comment|/* 1 = EID range filter, 0 = EID mask filter. Valid only if eid_filter_en is set,  */
decl_stmt|;
name|u8
name|cid_filter_en
comment|/* Indicates if CID filtering is performed (0/1) */
decl_stmt|;
name|union
name|dbg_bus_storm_eid_params
name|eid_filter_params
comment|/* EID filter params to filter on. Valid only if eid_filter_en is set. */
decl_stmt|;
name|__le32
name|cid
comment|/* CID to filter on. Valid only if cid_filter_en is set. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug Bus data  */
end_comment

begin_struct
struct|struct
name|dbg_bus_data
block|{
name|__le32
name|app_version
comment|/* The tools version number of the application */
decl_stmt|;
name|u8
name|state
comment|/* The current debug bus state */
decl_stmt|;
name|u8
name|hw_dwords
comment|/* HW dwords per cycle */
decl_stmt|;
name|__le16
name|hw_id_mask
comment|/* The HW IDs of the recorded HW blocks, where bits i*3..i*3+2 contain the HW ID of dword/qword i */
decl_stmt|;
name|u8
name|num_enabled_blocks
comment|/* Number of blocks enabled for recording */
decl_stmt|;
name|u8
name|num_enabled_storms
comment|/* Number of Storms enabled for recording */
decl_stmt|;
name|u8
name|target
comment|/* Output target */
decl_stmt|;
name|u8
name|one_shot_en
comment|/* Indicates if one-shot mode is enabled (0/1) */
decl_stmt|;
name|u8
name|grc_input_en
comment|/* Indicates if GRC recording is enabled (0/1) */
decl_stmt|;
name|u8
name|timestamp_input_en
comment|/* Indicates if timestamp recording is enabled (0/1) */
decl_stmt|;
name|u8
name|filter_en
comment|/* Indicates if the recording filter is enabled (0/1) */
decl_stmt|;
name|u8
name|adding_filter
comment|/* If true, the next added constraint belong to the filter. Otherwise, it belongs to the last added trigger state. Valid only if either filter or triggers are enabled. */
decl_stmt|;
name|u8
name|filter_pre_trigger
comment|/* Indicates if the recording filter should be applied before the trigger. Valid only if both filter and trigger are enabled (0/1) */
decl_stmt|;
name|u8
name|filter_post_trigger
comment|/* Indicates if the recording filter should be applied after the trigger. Valid only if both filter and trigger are enabled (0/1) */
decl_stmt|;
name|__le16
name|reserved
decl_stmt|;
name|u8
name|trigger_en
comment|/* Indicates if the recording trigger is enabled (0/1) */
decl_stmt|;
name|struct
name|dbg_bus_trigger_state_data
name|trigger_states
index|[
literal|3
index|]
comment|/* trigger states data */
decl_stmt|;
name|u8
name|next_trigger_state
comment|/* ID of next trigger state to be added */
decl_stmt|;
name|u8
name|next_constraint_id
comment|/* ID of next filter/trigger constraint to be added */
decl_stmt|;
name|u8
name|unify_inputs
comment|/* If true, all inputs are associated with HW ID 0. Otherwise, each input is assigned a different HW ID (0/1) */
decl_stmt|;
name|u8
name|rcv_from_other_engine
comment|/* Indicates if the other engine sends it NW recording to this engine (0/1) */
decl_stmt|;
name|struct
name|dbg_bus_pci_buf_data
name|pci_buf
comment|/* Debug Bus PCI buffer data. Valid only when the target is DBG_BUS_TARGET_ID_PCI. */
decl_stmt|;
name|struct
name|dbg_bus_block_data
name|blocks
index|[
literal|88
index|]
comment|/* Debug Bus data for each block */
decl_stmt|;
name|struct
name|dbg_bus_storm_data
name|storms
index|[
literal|6
index|]
comment|/* Debug Bus data for each block */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug bus filter types  */
end_comment

begin_enum
enum|enum
name|dbg_bus_filter_types
block|{
name|DBG_BUS_FILTER_TYPE_OFF
comment|/* filter always off */
block|,
name|DBG_BUS_FILTER_TYPE_PRE
comment|/* filter before trigger only */
block|,
name|DBG_BUS_FILTER_TYPE_POST
comment|/* filter after trigger only */
block|,
name|DBG_BUS_FILTER_TYPE_ON
comment|/* filter always on */
block|,
name|MAX_DBG_BUS_FILTER_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug bus frame modes  */
end_comment

begin_enum
enum|enum
name|dbg_bus_frame_modes
block|{
name|DBG_BUS_FRAME_MODE_0HW_4ST
init|=
literal|0
comment|/* 0 HW dwords, 4 Storm dwords */
block|,
name|DBG_BUS_FRAME_MODE_4HW_0ST
init|=
literal|3
comment|/* 4 HW dwords, 0 Storm dwords */
block|,
name|DBG_BUS_FRAME_MODE_8HW_0ST
init|=
literal|4
comment|/* 8 HW dwords, 0 Storm dwords */
block|,
name|MAX_DBG_BUS_FRAME_MODES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug bus other engine mode  */
end_comment

begin_enum
enum|enum
name|dbg_bus_other_engine_modes
block|{
name|DBG_BUS_OTHER_ENGINE_MODE_NONE
block|,
name|DBG_BUS_OTHER_ENGINE_MODE_DOUBLE_BW_TX
block|,
name|DBG_BUS_OTHER_ENGINE_MODE_DOUBLE_BW_RX
block|,
name|DBG_BUS_OTHER_ENGINE_MODE_CROSS_ENGINE_TX
block|,
name|DBG_BUS_OTHER_ENGINE_MODE_CROSS_ENGINE_RX
block|,
name|MAX_DBG_BUS_OTHER_ENGINE_MODES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug bus post-trigger recording types  */
end_comment

begin_enum
enum|enum
name|dbg_bus_post_trigger_types
block|{
name|DBG_BUS_POST_TRIGGER_RECORD
comment|/* start recording after trigger */
block|,
name|DBG_BUS_POST_TRIGGER_DROP
comment|/* drop data after trigger */
block|,
name|MAX_DBG_BUS_POST_TRIGGER_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug bus pre-trigger recording types  */
end_comment

begin_enum
enum|enum
name|dbg_bus_pre_trigger_types
block|{
name|DBG_BUS_PRE_TRIGGER_START_FROM_ZERO
comment|/* start recording from time 0 */
block|,
name|DBG_BUS_PRE_TRIGGER_NUM_CHUNKS
comment|/* start recording some chunks before trigger */
block|,
name|DBG_BUS_PRE_TRIGGER_DROP
comment|/* drop data before trigger */
block|,
name|MAX_DBG_BUS_PRE_TRIGGER_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug bus SEMI frame modes  */
end_comment

begin_enum
enum|enum
name|dbg_bus_semi_frame_modes
block|{
name|DBG_BUS_SEMI_FRAME_MODE_0SLOW_4FAST
init|=
literal|0
comment|/* 0 slow dwords, 4 fast dwords */
block|,
name|DBG_BUS_SEMI_FRAME_MODE_4SLOW_0FAST
init|=
literal|3
comment|/* 4 slow dwords, 0 fast dwords */
block|,
name|MAX_DBG_BUS_SEMI_FRAME_MODES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug bus states  */
end_comment

begin_enum
enum|enum
name|dbg_bus_states
block|{
name|DBG_BUS_STATE_IDLE
comment|/* debug bus idle state (not recording) */
block|,
name|DBG_BUS_STATE_READY
comment|/* debug bus is ready for configuration and recording */
block|,
name|DBG_BUS_STATE_RECORDING
comment|/* debug bus is currently recording */
block|,
name|DBG_BUS_STATE_STOPPED
comment|/* debug bus recording has stopped */
block|,
name|MAX_DBG_BUS_STATES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug Bus Storm modes  */
end_comment

begin_enum
enum|enum
name|dbg_bus_storm_modes
block|{
name|DBG_BUS_STORM_MODE_PRINTF
comment|/* store data (fast debug) */
block|,
name|DBG_BUS_STORM_MODE_PRAM_ADDR
comment|/* pram address (fast debug) */
block|,
name|DBG_BUS_STORM_MODE_DRA_RW
comment|/* DRA read/write data (fast debug) */
block|,
name|DBG_BUS_STORM_MODE_DRA_W
comment|/* DRA write data (fast debug) */
block|,
name|DBG_BUS_STORM_MODE_LD_ST_ADDR
comment|/* load/store address (fast debug) */
block|,
name|DBG_BUS_STORM_MODE_DRA_FSM
comment|/* DRA state machines (fast debug) */
block|,
name|DBG_BUS_STORM_MODE_RH
comment|/* recording handlers (fast debug) */
block|,
name|DBG_BUS_STORM_MODE_FOC
comment|/* FOC: FIN + DRA Rd (slow debug) */
block|,
name|DBG_BUS_STORM_MODE_EXT_STORE
comment|/* FOC: External Store (slow) */
block|,
name|MAX_DBG_BUS_STORM_MODES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug bus target IDs  */
end_comment

begin_enum
enum|enum
name|dbg_bus_targets
block|{
name|DBG_BUS_TARGET_ID_INT_BUF
comment|/* records debug bus to DBG block internal buffer */
block|,
name|DBG_BUS_TARGET_ID_NIG
comment|/* records debug bus to the NW */
block|,
name|DBG_BUS_TARGET_ID_PCI
comment|/* records debug bus to a PCI buffer */
block|,
name|MAX_DBG_BUS_TARGETS
block|}
enum|;
end_enum

begin_comment
comment|/*  * GRC Dump data  */
end_comment

begin_struct
struct|struct
name|dbg_grc_data
block|{
name|u8
name|params_initialized
comment|/* Indicates if the GRC parameters were initialized */
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
name|__le16
name|reserved2
decl_stmt|;
name|__le32
name|param_val
index|[
literal|48
index|]
comment|/* Value of each GRC parameter. Array size must match the enum dbg_grc_params. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug GRC params  */
end_comment

begin_enum
enum|enum
name|dbg_grc_params
block|{
name|DBG_GRC_PARAM_DUMP_TSTORM
comment|/* dump Tstorm memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_MSTORM
comment|/* dump Mstorm memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_USTORM
comment|/* dump Ustorm memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_XSTORM
comment|/* dump Xstorm memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_YSTORM
comment|/* dump Ystorm memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_PSTORM
comment|/* dump Pstorm memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_REGS
comment|/* dump non-memory registers (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_RAM
comment|/* dump Storm internal RAMs (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_PBUF
comment|/* dump Storm passive buffer (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_IOR
comment|/* dump Storm IORs (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_VFC
comment|/* dump VFC memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_CM_CTX
comment|/* dump CM contexts (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_PXP
comment|/* dump PXP memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_RSS
comment|/* dump RSS memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_CAU
comment|/* dump CAU memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_QM
comment|/* dump QM memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_MCP
comment|/* dump MCP memories (0/1) */
block|,
name|DBG_GRC_PARAM_RESERVED
comment|/* reserved */
block|,
name|DBG_GRC_PARAM_DUMP_CFC
comment|/* dump CFC memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_IGU
comment|/* dump IGU memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_BRB
comment|/* dump BRB memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_BTB
comment|/* dump BTB memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_BMB
comment|/* dump BMB memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_NIG
comment|/* dump NIG memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_MULD
comment|/* dump MULD memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_PRS
comment|/* dump PRS memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_DMAE
comment|/* dump PRS memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_TM
comment|/* dump TM (timers) memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_SDM
comment|/* dump SDM memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_DIF
comment|/* dump DIF memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_STATIC
comment|/* dump static debug data (0/1) */
block|,
name|DBG_GRC_PARAM_UNSTALL
comment|/* un-stall Storms after dump (0/1) */
block|,
name|DBG_GRC_PARAM_NUM_LCIDS
comment|/* number of LCIDs (0..320) */
block|,
name|DBG_GRC_PARAM_NUM_LTIDS
comment|/* number of LTIDs (0..320) */
block|,
name|DBG_GRC_PARAM_EXCLUDE_ALL
comment|/* preset: exclude all memories from dump (1 only) */
block|,
name|DBG_GRC_PARAM_CRASH
comment|/* preset: include memories for crash dump (1 only) */
block|,
name|DBG_GRC_PARAM_PARITY_SAFE
comment|/* perform dump only if MFW is responding (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_CM
comment|/* dump CM memories (0/1) */
block|,
name|DBG_GRC_PARAM_DUMP_PHY
comment|/* dump PHY memories (0/1) */
block|,
name|DBG_GRC_PARAM_NO_MCP
comment|/* dont perform MCP commands (0/1) */
block|,
name|DBG_GRC_PARAM_NO_FW_VER
comment|/* dont read FW/MFW version (0/1) */
block|,
name|MAX_DBG_GRC_PARAMS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug reset registers  */
end_comment

begin_enum
enum|enum
name|dbg_reset_regs
block|{
name|DBG_RESET_REG_MISCS_PL_UA
block|,
name|DBG_RESET_REG_MISCS_PL_HV
block|,
name|DBG_RESET_REG_MISCS_PL_HV_2
block|,
name|DBG_RESET_REG_MISC_PL_UA
block|,
name|DBG_RESET_REG_MISC_PL_HV
block|,
name|DBG_RESET_REG_MISC_PL_PDA_VMAIN_1
block|,
name|DBG_RESET_REG_MISC_PL_PDA_VMAIN_2
block|,
name|DBG_RESET_REG_MISC_PL_PDA_VAUX
block|,
name|MAX_DBG_RESET_REGS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug status codes  */
end_comment

begin_enum
enum|enum
name|dbg_status
block|{
name|DBG_STATUS_OK
block|,
name|DBG_STATUS_APP_VERSION_NOT_SET
block|,
name|DBG_STATUS_UNSUPPORTED_APP_VERSION
block|,
name|DBG_STATUS_DBG_BLOCK_NOT_RESET
block|,
name|DBG_STATUS_INVALID_ARGS
block|,
name|DBG_STATUS_OUTPUT_ALREADY_SET
block|,
name|DBG_STATUS_INVALID_PCI_BUF_SIZE
block|,
name|DBG_STATUS_PCI_BUF_ALLOC_FAILED
block|,
name|DBG_STATUS_PCI_BUF_NOT_ALLOCATED
block|,
name|DBG_STATUS_TOO_MANY_INPUTS
block|,
name|DBG_STATUS_INPUT_OVERLAP
block|,
name|DBG_STATUS_HW_ONLY_RECORDING
block|,
name|DBG_STATUS_STORM_ALREADY_ENABLED
block|,
name|DBG_STATUS_STORM_NOT_ENABLED
block|,
name|DBG_STATUS_BLOCK_ALREADY_ENABLED
block|,
name|DBG_STATUS_BLOCK_NOT_ENABLED
block|,
name|DBG_STATUS_NO_INPUT_ENABLED
block|,
name|DBG_STATUS_NO_FILTER_TRIGGER_64B
block|,
name|DBG_STATUS_FILTER_ALREADY_ENABLED
block|,
name|DBG_STATUS_TRIGGER_ALREADY_ENABLED
block|,
name|DBG_STATUS_TRIGGER_NOT_ENABLED
block|,
name|DBG_STATUS_CANT_ADD_CONSTRAINT
block|,
name|DBG_STATUS_TOO_MANY_TRIGGER_STATES
block|,
name|DBG_STATUS_TOO_MANY_CONSTRAINTS
block|,
name|DBG_STATUS_RECORDING_NOT_STARTED
block|,
name|DBG_STATUS_DATA_DIDNT_TRIGGER
block|,
name|DBG_STATUS_NO_DATA_RECORDED
block|,
name|DBG_STATUS_DUMP_BUF_TOO_SMALL
block|,
name|DBG_STATUS_DUMP_NOT_CHUNK_ALIGNED
block|,
name|DBG_STATUS_UNKNOWN_CHIP
block|,
name|DBG_STATUS_VIRT_MEM_ALLOC_FAILED
block|,
name|DBG_STATUS_BLOCK_IN_RESET
block|,
name|DBG_STATUS_INVALID_TRACE_SIGNATURE
block|,
name|DBG_STATUS_INVALID_NVRAM_BUNDLE
block|,
name|DBG_STATUS_NVRAM_GET_IMAGE_FAILED
block|,
name|DBG_STATUS_NON_ALIGNED_NVRAM_IMAGE
block|,
name|DBG_STATUS_NVRAM_READ_FAILED
block|,
name|DBG_STATUS_IDLE_CHK_PARSE_FAILED
block|,
name|DBG_STATUS_MCP_TRACE_BAD_DATA
block|,
name|DBG_STATUS_MCP_TRACE_NO_META
block|,
name|DBG_STATUS_MCP_COULD_NOT_HALT
block|,
name|DBG_STATUS_MCP_COULD_NOT_RESUME
block|,
name|DBG_STATUS_DMAE_FAILED
block|,
name|DBG_STATUS_SEMI_FIFO_NOT_EMPTY
block|,
name|DBG_STATUS_IGU_FIFO_BAD_DATA
block|,
name|DBG_STATUS_MCP_COULD_NOT_MASK_PRTY
block|,
name|DBG_STATUS_FW_ASSERTS_PARSE_FAILED
block|,
name|DBG_STATUS_REG_FIFO_BAD_DATA
block|,
name|DBG_STATUS_PROTECTION_OVERRIDE_BAD_DATA
block|,
name|DBG_STATUS_DBG_ARRAY_NOT_SET
block|,
name|DBG_STATUS_FILTER_BUG
block|,
name|DBG_STATUS_NON_MATCHING_LINES
block|,
name|DBG_STATUS_INVALID_TRIGGER_DWORD_OFFSET
block|,
name|DBG_STATUS_DBG_BUS_IN_USE
block|,
name|MAX_DBG_STATUS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debug Storms IDs  */
end_comment

begin_enum
enum|enum
name|dbg_storms
block|{
name|DBG_TSTORM_ID
block|,
name|DBG_MSTORM_ID
block|,
name|DBG_USTORM_ID
block|,
name|DBG_XSTORM_ID
block|,
name|DBG_YSTORM_ID
block|,
name|DBG_PSTORM_ID
block|,
name|MAX_DBG_STORMS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Idle Check data  */
end_comment

begin_struct
struct|struct
name|idle_chk_data
block|{
name|__le32
name|buf_size
comment|/* Idle check buffer size in dwords */
decl_stmt|;
name|u8
name|buf_size_set
comment|/* Indicates if the idle check buffer size was set (0/1) */
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
name|__le16
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debug Tools data (per HW function)  */
end_comment

begin_struct
struct|struct
name|dbg_tools_data
block|{
name|struct
name|dbg_grc_data
name|grc
comment|/* GRC Dump data */
decl_stmt|;
name|struct
name|dbg_bus_data
name|bus
comment|/* Debug Bus data */
decl_stmt|;
name|struct
name|idle_chk_data
name|idle_chk
comment|/* Idle Check data */
decl_stmt|;
name|u8
name|mode_enable
index|[
literal|40
index|]
comment|/* Indicates if a mode is enabled (0/1) */
decl_stmt|;
name|u8
name|block_in_reset
index|[
literal|88
index|]
comment|/* Indicates if a block is in reset state (0/1) */
decl_stmt|;
name|u8
name|chip_id
comment|/* Chip ID (from enum chip_ids) */
decl_stmt|;
name|u8
name|platform_id
comment|/* Platform ID */
decl_stmt|;
name|u8
name|initialized
comment|/* Indicates if the data was initialized */
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_HSI_DEBUG_TOOLS__ */
end_comment

end_unit

