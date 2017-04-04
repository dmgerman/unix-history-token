begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_INIT_TOOL__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_INIT_TOOL__
end_define

begin_comment
comment|/**************************************/
end_comment

begin_comment
comment|/* Init Tool HSI constants and macros */
end_comment

begin_comment
comment|/**************************************/
end_comment

begin_comment
comment|/* Width of GRC address in bits (addresses are specified in dwords) */
end_comment

begin_define
define|#
directive|define
name|GRC_ADDR_BITS
value|23
end_define

begin_define
define|#
directive|define
name|MAX_GRC_ADDR
value|((1<< GRC_ADDR_BITS) - 1)
end_define

begin_comment
comment|/* indicates an init that should be applied to any phase ID */
end_comment

begin_define
define|#
directive|define
name|ANY_PHASE_ID
value|0xffff
end_define

begin_comment
comment|/* Max size in dwords of a zipped array */
end_comment

begin_define
define|#
directive|define
name|MAX_ZIPPED_SIZE
value|8192
end_define

begin_enum
enum|enum
name|chip_ids
block|{
name|CHIP_BB
block|,
name|CHIP_K2
block|,
name|CHIP_E5
block|,
name|MAX_CHIP_IDS
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fw_asserts_ram_section
block|{
name|__le16
name|section_ram_line_offset
comment|/* The offset of the section in the RAM in RAM lines (64-bit units) */
decl_stmt|;
name|__le16
name|section_ram_line_size
comment|/* The size of the section in RAM lines (64-bit units) */
decl_stmt|;
name|u8
name|list_dword_offset
comment|/* The offset of the asserts list within the section in dwords */
decl_stmt|;
name|u8
name|list_element_dword_size
comment|/* The size of an assert list element in dwords */
decl_stmt|;
name|u8
name|list_num_elements
comment|/* The number of elements in the asserts list */
decl_stmt|;
name|u8
name|list_next_index_dword_offset
comment|/* The offset of the next list index field within the section in dwords */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ver_num
block|{
name|u8
name|major
comment|/* Firmware major version number */
decl_stmt|;
name|u8
name|minor
comment|/* Firmware minor version number */
decl_stmt|;
name|u8
name|rev
comment|/* Firmware revision version number */
decl_stmt|;
name|u8
name|eng
comment|/* Firmware engineering version number (for bootleg versions) */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_ver_info
block|{
name|__le16
name|tools_ver
comment|/* Tools version number */
decl_stmt|;
name|u8
name|image_id
comment|/* FW image ID (e.g. main, l2b, kuku) */
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
name|struct
name|fw_ver_num
name|num
comment|/* FW version number */
decl_stmt|;
name|__le32
name|timestamp
comment|/* FW Timestamp in unix time  (sec. since 1970) */
decl_stmt|;
name|__le32
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_info
block|{
name|struct
name|fw_ver_info
name|ver
comment|/* FW version information */
decl_stmt|;
name|struct
name|fw_asserts_ram_section
name|fw_asserts_section
comment|/* Info regarding the FW asserts section in the Storm RAM */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_info_location
block|{
name|__le32
name|grc_addr
comment|/* GRC address where the fw_info struct is located. */
decl_stmt|;
name|__le32
name|size
comment|/* Size of the fw_info structure (thats located at the grc_addr). */
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|init_modes
block|{
name|MODE_BB_A0_DEPRECATED
block|,
name|MODE_BB
block|,
name|MODE_K2
block|,
name|MODE_ASIC
block|,
name|MODE_EMUL_REDUCED
block|,
name|MODE_EMUL_FULL
block|,
name|MODE_FPGA
block|,
name|MODE_CHIPSIM
block|,
name|MODE_SF
block|,
name|MODE_MF_SD
block|,
name|MODE_MF_SI
block|,
name|MODE_PORTS_PER_ENG_1
block|,
name|MODE_PORTS_PER_ENG_2
block|,
name|MODE_PORTS_PER_ENG_4
block|,
name|MODE_100G
block|,
name|MODE_E5
block|,
name|MAX_INIT_MODES
block|}
enum|;
end_enum

begin_enum
enum|enum
name|init_phases
block|{
name|PHASE_ENGINE
block|,
name|PHASE_PORT
block|,
name|PHASE_PF
block|,
name|PHASE_VF
block|,
name|PHASE_QM_PF
block|,
name|MAX_INIT_PHASES
block|}
enum|;
end_enum

begin_enum
enum|enum
name|init_split_types
block|{
name|SPLIT_TYPE_NONE
block|,
name|SPLIT_TYPE_PORT
block|,
name|SPLIT_TYPE_PF
block|,
name|SPLIT_TYPE_PORT_PF
block|,
name|SPLIT_TYPE_VF
block|,
name|MAX_INIT_SPLIT_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Binary buffer header  */
end_comment

begin_struct
struct|struct
name|bin_buffer_hdr
block|{
name|__le32
name|offset
comment|/* buffer offset in bytes from the beginning of the binary file */
decl_stmt|;
name|__le32
name|length
comment|/* buffer length in bytes */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * binary init buffer types  */
end_comment

begin_enum
enum|enum
name|bin_init_buffer_type
block|{
name|BIN_BUF_INIT_FW_VER_INFO
comment|/* fw_ver_info struct */
block|,
name|BIN_BUF_INIT_CMD
comment|/* init commands */
block|,
name|BIN_BUF_INIT_VAL
comment|/* init data */
block|,
name|BIN_BUF_INIT_MODE_TREE
comment|/* init modes tree */
block|,
name|BIN_BUF_INIT_IRO
comment|/* internal RAM offsets */
block|,
name|MAX_BIN_INIT_BUFFER_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * init array header: raw  */
end_comment

begin_struct
struct|struct
name|init_array_raw_hdr
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|INIT_ARRAY_RAW_HDR_TYPE_MASK
value|0xF
comment|/* Init array type, from init_array_types enum */
define|#
directive|define
name|INIT_ARRAY_RAW_HDR_TYPE_SHIFT
value|0
define|#
directive|define
name|INIT_ARRAY_RAW_HDR_PARAMS_MASK
value|0xFFFFFFF
comment|/* init array params */
define|#
directive|define
name|INIT_ARRAY_RAW_HDR_PARAMS_SHIFT
value|4
block|}
struct|;
end_struct

begin_comment
comment|/*  * init array header: standard  */
end_comment

begin_struct
struct|struct
name|init_array_standard_hdr
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|INIT_ARRAY_STANDARD_HDR_TYPE_MASK
value|0xF
comment|/* Init array type, from init_array_types enum */
define|#
directive|define
name|INIT_ARRAY_STANDARD_HDR_TYPE_SHIFT
value|0
define|#
directive|define
name|INIT_ARRAY_STANDARD_HDR_SIZE_MASK
value|0xFFFFFFF
comment|/* Init array size (in dwords) */
define|#
directive|define
name|INIT_ARRAY_STANDARD_HDR_SIZE_SHIFT
value|4
block|}
struct|;
end_struct

begin_comment
comment|/*  * init array header: zipped  */
end_comment

begin_struct
struct|struct
name|init_array_zipped_hdr
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|INIT_ARRAY_ZIPPED_HDR_TYPE_MASK
value|0xF
comment|/* Init array type, from init_array_types enum */
define|#
directive|define
name|INIT_ARRAY_ZIPPED_HDR_TYPE_SHIFT
value|0
define|#
directive|define
name|INIT_ARRAY_ZIPPED_HDR_ZIPPED_SIZE_MASK
value|0xFFFFFFF
comment|/* Init array zipped size (in bytes) */
define|#
directive|define
name|INIT_ARRAY_ZIPPED_HDR_ZIPPED_SIZE_SHIFT
value|4
block|}
struct|;
end_struct

begin_comment
comment|/*  * init array header: pattern  */
end_comment

begin_struct
struct|struct
name|init_array_pattern_hdr
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|INIT_ARRAY_PATTERN_HDR_TYPE_MASK
value|0xF
comment|/* Init array type, from init_array_types enum */
define|#
directive|define
name|INIT_ARRAY_PATTERN_HDR_TYPE_SHIFT
value|0
define|#
directive|define
name|INIT_ARRAY_PATTERN_HDR_PATTERN_SIZE_MASK
value|0xF
comment|/* pattern size in dword */
define|#
directive|define
name|INIT_ARRAY_PATTERN_HDR_PATTERN_SIZE_SHIFT
value|4
define|#
directive|define
name|INIT_ARRAY_PATTERN_HDR_REPETITIONS_MASK
value|0xFFFFFF
comment|/* pattern repetitions */
define|#
directive|define
name|INIT_ARRAY_PATTERN_HDR_REPETITIONS_SHIFT
value|8
block|}
struct|;
end_struct

begin_comment
comment|/*  * init array header union  */
end_comment

begin_union
union|union
name|init_array_hdr
block|{
name|struct
name|init_array_raw_hdr
name|raw
comment|/* raw init array header */
decl_stmt|;
name|struct
name|init_array_standard_hdr
name|standard
comment|/* standard init array header */
decl_stmt|;
name|struct
name|init_array_zipped_hdr
name|zipped
comment|/* zipped init array header */
decl_stmt|;
name|struct
name|init_array_pattern_hdr
name|pattern
comment|/* pattern init array header */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * init array types  */
end_comment

begin_enum
enum|enum
name|init_array_types
block|{
name|INIT_ARR_STANDARD
comment|/* standard init array */
block|,
name|INIT_ARR_ZIPPED
comment|/* zipped init array */
block|,
name|INIT_ARR_PATTERN
comment|/* a repeated pattern */
block|,
name|MAX_INIT_ARRAY_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * init operation: callback  */
end_comment

begin_struct
struct|struct
name|init_callback_op
block|{
name|__le32
name|op_data
decl_stmt|;
define|#
directive|define
name|INIT_CALLBACK_OP_OP_MASK
value|0xF
comment|/* Init operation, from init_op_types enum */
define|#
directive|define
name|INIT_CALLBACK_OP_OP_SHIFT
value|0
define|#
directive|define
name|INIT_CALLBACK_OP_RESERVED_MASK
value|0xFFFFFFF
define|#
directive|define
name|INIT_CALLBACK_OP_RESERVED_SHIFT
value|4
name|__le16
name|callback_id
comment|/* Callback ID */
decl_stmt|;
name|__le16
name|block_id
comment|/* Blocks ID */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * init operation: delay  */
end_comment

begin_struct
struct|struct
name|init_delay_op
block|{
name|__le32
name|op_data
decl_stmt|;
define|#
directive|define
name|INIT_DELAY_OP_OP_MASK
value|0xF
comment|/* Init operation, from init_op_types enum */
define|#
directive|define
name|INIT_DELAY_OP_OP_SHIFT
value|0
define|#
directive|define
name|INIT_DELAY_OP_RESERVED_MASK
value|0xFFFFFFF
define|#
directive|define
name|INIT_DELAY_OP_RESERVED_SHIFT
value|4
name|__le32
name|delay
comment|/* delay in us */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * init operation: if_mode  */
end_comment

begin_struct
struct|struct
name|init_if_mode_op
block|{
name|__le32
name|op_data
decl_stmt|;
define|#
directive|define
name|INIT_IF_MODE_OP_OP_MASK
value|0xF
comment|/* Init operation, from init_op_types enum */
define|#
directive|define
name|INIT_IF_MODE_OP_OP_SHIFT
value|0
define|#
directive|define
name|INIT_IF_MODE_OP_RESERVED1_MASK
value|0xFFF
define|#
directive|define
name|INIT_IF_MODE_OP_RESERVED1_SHIFT
value|4
define|#
directive|define
name|INIT_IF_MODE_OP_CMD_OFFSET_MASK
value|0xFFFF
comment|/* Commands to skip if the modes dont match */
define|#
directive|define
name|INIT_IF_MODE_OP_CMD_OFFSET_SHIFT
value|16
name|__le16
name|reserved2
decl_stmt|;
name|__le16
name|modes_buf_offset
comment|/* offset (in bytes) in modes expression buffer */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * init operation: if_phase  */
end_comment

begin_struct
struct|struct
name|init_if_phase_op
block|{
name|__le32
name|op_data
decl_stmt|;
define|#
directive|define
name|INIT_IF_PHASE_OP_OP_MASK
value|0xF
comment|/* Init operation, from init_op_types enum */
define|#
directive|define
name|INIT_IF_PHASE_OP_OP_SHIFT
value|0
define|#
directive|define
name|INIT_IF_PHASE_OP_DMAE_ENABLE_MASK
value|0x1
comment|/* Indicates if DMAE is enabled in this phase */
define|#
directive|define
name|INIT_IF_PHASE_OP_DMAE_ENABLE_SHIFT
value|4
define|#
directive|define
name|INIT_IF_PHASE_OP_RESERVED1_MASK
value|0x7FF
define|#
directive|define
name|INIT_IF_PHASE_OP_RESERVED1_SHIFT
value|5
define|#
directive|define
name|INIT_IF_PHASE_OP_CMD_OFFSET_MASK
value|0xFFFF
comment|/* Commands to skip if the phases dont match */
define|#
directive|define
name|INIT_IF_PHASE_OP_CMD_OFFSET_SHIFT
value|16
name|__le32
name|phase_data
decl_stmt|;
define|#
directive|define
name|INIT_IF_PHASE_OP_PHASE_MASK
value|0xFF
comment|/* Init phase */
define|#
directive|define
name|INIT_IF_PHASE_OP_PHASE_SHIFT
value|0
define|#
directive|define
name|INIT_IF_PHASE_OP_RESERVED2_MASK
value|0xFF
define|#
directive|define
name|INIT_IF_PHASE_OP_RESERVED2_SHIFT
value|8
define|#
directive|define
name|INIT_IF_PHASE_OP_PHASE_ID_MASK
value|0xFFFF
comment|/* Init phase ID */
define|#
directive|define
name|INIT_IF_PHASE_OP_PHASE_ID_SHIFT
value|16
block|}
struct|;
end_struct

begin_comment
comment|/*  * init mode operators  */
end_comment

begin_enum
enum|enum
name|init_mode_ops
block|{
name|INIT_MODE_OP_NOT
comment|/* init mode not operator */
block|,
name|INIT_MODE_OP_OR
comment|/* init mode or operator */
block|,
name|INIT_MODE_OP_AND
comment|/* init mode and operator */
block|,
name|MAX_INIT_MODE_OPS
block|}
enum|;
end_enum

begin_comment
comment|/*  * init operation: raw  */
end_comment

begin_struct
struct|struct
name|init_raw_op
block|{
name|__le32
name|op_data
decl_stmt|;
define|#
directive|define
name|INIT_RAW_OP_OP_MASK
value|0xF
comment|/* Init operation, from init_op_types enum */
define|#
directive|define
name|INIT_RAW_OP_OP_SHIFT
value|0
define|#
directive|define
name|INIT_RAW_OP_PARAM1_MASK
value|0xFFFFFFF
comment|/* init param 1 */
define|#
directive|define
name|INIT_RAW_OP_PARAM1_SHIFT
value|4
name|__le32
name|param2
comment|/* Init param 2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * init array params  */
end_comment

begin_struct
struct|struct
name|init_op_array_params
block|{
name|__le16
name|size
comment|/* array size in dwords */
decl_stmt|;
name|__le16
name|offset
comment|/* array start offset in dwords */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Write init operation arguments  */
end_comment

begin_union
union|union
name|init_write_args
block|{
name|__le32
name|inline_val
comment|/* value to write, used when init source is INIT_SRC_INLINE */
decl_stmt|;
name|__le32
name|zeros_count
comment|/* number of zeros to write, used when init source is INIT_SRC_ZEROS */
decl_stmt|;
name|__le32
name|array_offset
comment|/* array offset to write, used when init source is INIT_SRC_ARRAY */
decl_stmt|;
name|struct
name|init_op_array_params
name|runtime
comment|/* runtime array params to write, used when init source is INIT_SRC_RUNTIME */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * init operation: write  */
end_comment

begin_struct
struct|struct
name|init_write_op
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|INIT_WRITE_OP_OP_MASK
value|0xF
comment|/* init operation, from init_op_types enum */
define|#
directive|define
name|INIT_WRITE_OP_OP_SHIFT
value|0
define|#
directive|define
name|INIT_WRITE_OP_SOURCE_MASK
value|0x7
comment|/* init source type, taken from init_source_types enum */
define|#
directive|define
name|INIT_WRITE_OP_SOURCE_SHIFT
value|4
define|#
directive|define
name|INIT_WRITE_OP_RESERVED_MASK
value|0x1
define|#
directive|define
name|INIT_WRITE_OP_RESERVED_SHIFT
value|7
define|#
directive|define
name|INIT_WRITE_OP_WIDE_BUS_MASK
value|0x1
comment|/* indicates if the register is wide-bus */
define|#
directive|define
name|INIT_WRITE_OP_WIDE_BUS_SHIFT
value|8
define|#
directive|define
name|INIT_WRITE_OP_ADDRESS_MASK
value|0x7FFFFF
comment|/* internal (absolute) GRC address, in dwords */
define|#
directive|define
name|INIT_WRITE_OP_ADDRESS_SHIFT
value|9
name|union
name|init_write_args
name|args
comment|/* Write init operation arguments */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * init operation: read  */
end_comment

begin_struct
struct|struct
name|init_read_op
block|{
name|__le32
name|op_data
decl_stmt|;
define|#
directive|define
name|INIT_READ_OP_OP_MASK
value|0xF
comment|/* init operation, from init_op_types enum */
define|#
directive|define
name|INIT_READ_OP_OP_SHIFT
value|0
define|#
directive|define
name|INIT_READ_OP_POLL_TYPE_MASK
value|0xF
comment|/* polling type, from init_poll_types enum */
define|#
directive|define
name|INIT_READ_OP_POLL_TYPE_SHIFT
value|4
define|#
directive|define
name|INIT_READ_OP_RESERVED_MASK
value|0x1
define|#
directive|define
name|INIT_READ_OP_RESERVED_SHIFT
value|8
define|#
directive|define
name|INIT_READ_OP_ADDRESS_MASK
value|0x7FFFFF
comment|/* internal (absolute) GRC address, in dwords */
define|#
directive|define
name|INIT_READ_OP_ADDRESS_SHIFT
value|9
name|__le32
name|expected_val
comment|/* expected polling value, used only when polling is done */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Init operations union  */
end_comment

begin_union
union|union
name|init_op
block|{
name|struct
name|init_raw_op
name|raw
comment|/* raw init operation */
decl_stmt|;
name|struct
name|init_write_op
name|write
comment|/* write init operation */
decl_stmt|;
name|struct
name|init_read_op
name|read
comment|/* read init operation */
decl_stmt|;
name|struct
name|init_if_mode_op
name|if_mode
comment|/* if_mode init operation */
decl_stmt|;
name|struct
name|init_if_phase_op
name|if_phase
comment|/* if_phase init operation */
decl_stmt|;
name|struct
name|init_callback_op
name|callback
comment|/* callback init operation */
decl_stmt|;
name|struct
name|init_delay_op
name|delay
comment|/* delay init operation */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Init command operation types  */
end_comment

begin_enum
enum|enum
name|init_op_types
block|{
name|INIT_OP_READ
comment|/* GRC read init command */
block|,
name|INIT_OP_WRITE
comment|/* GRC write init command */
block|,
name|INIT_OP_IF_MODE
comment|/* Skip init commands if the init modes expression doesnt match */
block|,
name|INIT_OP_IF_PHASE
comment|/* Skip init commands if the init phase doesnt match */
block|,
name|INIT_OP_DELAY
comment|/* delay init command */
block|,
name|INIT_OP_CALLBACK
comment|/* callback init command */
block|,
name|MAX_INIT_OP_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * init polling types  */
end_comment

begin_enum
enum|enum
name|init_poll_types
block|{
name|INIT_POLL_NONE
comment|/* No polling */
block|,
name|INIT_POLL_EQ
comment|/* init value is included in the init command */
block|,
name|INIT_POLL_OR
comment|/* init value is all zeros */
block|,
name|INIT_POLL_AND
comment|/* init value is an array of values */
block|,
name|MAX_INIT_POLL_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * init source types  */
end_comment

begin_enum
enum|enum
name|init_source_types
block|{
name|INIT_SRC_INLINE
comment|/* init value is included in the init command */
block|,
name|INIT_SRC_ZEROS
comment|/* init value is all zeros */
block|,
name|INIT_SRC_ARRAY
comment|/* init value is an array of values */
block|,
name|INIT_SRC_RUNTIME
comment|/* init value is provided during runtime */
block|,
name|MAX_INIT_SOURCE_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Internal RAM Offsets macro data  */
end_comment

begin_struct
struct|struct
name|iro
block|{
name|__le32
name|base
comment|/* RAM field offset */
decl_stmt|;
name|__le16
name|m1
comment|/* multiplier 1 */
decl_stmt|;
name|__le16
name|m2
comment|/* multiplier 2 */
decl_stmt|;
name|__le16
name|m3
comment|/* multiplier 3 */
decl_stmt|;
name|__le16
name|size
comment|/* RAM field size */
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_HSI_INIT_TOOL__ */
end_comment

end_unit

