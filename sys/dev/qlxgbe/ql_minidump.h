begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013-2016 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * File: ql_minidump.h  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QL_MINIDUMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_QL_MINIDUMP_H_
end_define

begin_define
define|#
directive|define
name|QL_DBG_STATE_ARRAY_LEN
value|16
end_define

begin_define
define|#
directive|define
name|QL_DBG_CAP_SIZE_ARRAY_LEN
value|8
end_define

begin_define
define|#
directive|define
name|QL_NO_OF_OCM_WINDOWS
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|ql_mdump_tmplt_hdr
block|{
name|uint32_t
name|entry_type
decl_stmt|;
name|uint32_t
name|first_entry_offset
decl_stmt|;
name|uint32_t
name|size_of_template
decl_stmt|;
name|uint32_t
name|recommended_capture_mask
decl_stmt|;
name|uint32_t
name|num_of_entries
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|driver_timestamp
decl_stmt|;
name|uint32_t
name|checksum
decl_stmt|;
name|uint32_t
name|driver_capture_mask
decl_stmt|;
name|uint32_t
name|driver_info_word2
decl_stmt|;
name|uint32_t
name|driver_info_word3
decl_stmt|;
name|uint32_t
name|driver_info_word4
decl_stmt|;
name|uint32_t
name|saved_state_array
index|[
name|QL_DBG_STATE_ARRAY_LEN
index|]
decl_stmt|;
name|uint32_t
name|capture_size_array
index|[
name|QL_DBG_CAP_SIZE_ARRAY_LEN
index|]
decl_stmt|;
name|uint32_t
name|ocm_window_array
index|[
name|QL_NO_OF_OCM_WINDOWS
index|]
decl_stmt|;
block|}
name|ql_minidump_template_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * MIU AGENT ADDRESSES.  */
end_comment

begin_define
define|#
directive|define
name|MD_TA_CTL_ENABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|MD_TA_CTL_START
value|0x1
end_define

begin_define
define|#
directive|define
name|MD_TA_CTL_BUSY
value|0x8
end_define

begin_define
define|#
directive|define
name|MD_TA_CTL_CHECK
value|1000
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_CTRL
value|0x41000090
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_ADDR_LO
value|0x41000094
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_ADDR_HI
value|0x41000098
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_RDDATA_0_31
value|0x410000A8
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_RDDATA_32_63
value|0x410000AC
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_RDDATA_64_95
value|0x410000B8
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_RDDATA_96_127
value|0x410000BC
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_WRDATA_0_31
value|0x410000A0
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_WRDATA_32_63
value|0x410000A4
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_WRDATA_64_95
value|0x410000B0
end_define

begin_define
define|#
directive|define
name|MD_MIU_TEST_AGT_WRDATA_96_127
value|0x410000B4
end_define

begin_comment
comment|/*  * ROM Read Address  */
end_comment

begin_define
define|#
directive|define
name|MD_DIRECT_ROM_WINDOW
value|0x42110030
end_define

begin_define
define|#
directive|define
name|MD_DIRECT_ROM_READ_BASE
value|0x42150000
end_define

begin_comment
comment|/*  * Entry Type Defines  */
end_comment

begin_define
define|#
directive|define
name|RDNOP
value|0
end_define

begin_define
define|#
directive|define
name|RDCRB
value|1
end_define

begin_define
define|#
directive|define
name|RDMUX
value|2
end_define

begin_define
define|#
directive|define
name|QUEUE
value|3
end_define

begin_define
define|#
directive|define
name|BOARD
value|4
end_define

begin_define
define|#
directive|define
name|RDOCM
value|6
end_define

begin_define
define|#
directive|define
name|L1DAT
value|11
end_define

begin_define
define|#
directive|define
name|L1INS
value|12
end_define

begin_define
define|#
directive|define
name|L2DTG
value|21
end_define

begin_define
define|#
directive|define
name|L2ITG
value|22
end_define

begin_define
define|#
directive|define
name|L2DAT
value|23
end_define

begin_define
define|#
directive|define
name|L2INS
value|24
end_define

begin_define
define|#
directive|define
name|POLLRD
value|35
end_define

begin_define
define|#
directive|define
name|RDMUX2
value|36
end_define

begin_define
define|#
directive|define
name|POLLRDMWR
value|37
end_define

begin_define
define|#
directive|define
name|RDROM
value|71
end_define

begin_define
define|#
directive|define
name|RDMEM
value|72
end_define

begin_define
define|#
directive|define
name|CNTRL
value|98
end_define

begin_define
define|#
directive|define
name|TLHDR
value|99
end_define

begin_define
define|#
directive|define
name|RDEND
value|255
end_define

begin_comment
comment|/*  * Index of State Table.  The Template header maintains  * an array of 8 (0..7) words that is used to store some  * "State Information" from the board.  */
end_comment

begin_define
define|#
directive|define
name|QL_PCIE_FUNC_INDX
value|0
end_define

begin_define
define|#
directive|define
name|QL_CLK_STATE_INDX
value|1
end_define

begin_define
define|#
directive|define
name|QL_SRE_STATE_INDX
value|2
end_define

begin_define
define|#
directive|define
name|QL_OCM0_ADDR_INDX
value|3
end_define

begin_define
define|#
directive|define
name|QL_REVID_STATE_INDX
value|4
end_define

begin_define
define|#
directive|define
name|QL_MAJVER_STATE_INDX
value|5
end_define

begin_define
define|#
directive|define
name|QL_MINVER_STATE_INDX
value|6
end_define

begin_define
define|#
directive|define
name|QL_SUBVER_STATE_INDX
value|7
end_define

begin_comment
comment|/*  * Opcodes for Control Entries.  * These Flags are bit fields.  */
end_comment

begin_define
define|#
directive|define
name|QL_DBG_OPCODE_WR
value|0x01
end_define

begin_define
define|#
directive|define
name|QL_DBG_OPCODE_RW
value|0x02
end_define

begin_define
define|#
directive|define
name|QL_DBG_OPCODE_AND
value|0x04
end_define

begin_define
define|#
directive|define
name|QL_DBG_OPCODE_OR
value|0x08
end_define

begin_define
define|#
directive|define
name|QL_DBG_OPCODE_POLL
value|0x10
end_define

begin_define
define|#
directive|define
name|QL_DBG_OPCODE_RDSTATE
value|0x20
end_define

begin_define
define|#
directive|define
name|QL_DBG_OPCODE_WRSTATE
value|0x40
end_define

begin_define
define|#
directive|define
name|QL_DBG_OPCODE_MDSTATE
value|0x80
end_define

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_hdr_s
block|{
name|uint32_t
name|entry_type
decl_stmt|;
name|uint32_t
name|entry_size
decl_stmt|;
name|uint32_t
name|entry_capture_size
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|entry_capture_mask
decl_stmt|;
name|uint8_t
name|entry_code
decl_stmt|;
name|uint8_t
name|driver_code
decl_stmt|;
name|uint8_t
name|driver_flags
decl_stmt|;
block|}
struct|;
name|uint32_t
name|entry_ctrl_word
decl_stmt|;
block|}
union|;
block|}
name|ql_minidump_entry_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Driver Flags  */
end_comment

begin_define
define|#
directive|define
name|QL_DBG_SKIPPED_FLAG
value|0x80
end_define

begin_comment
comment|/*  driver skipped this entry  */
end_comment

begin_define
define|#
directive|define
name|QL_DBG_SIZE_ERR_FLAG
value|0x40
end_define

begin_comment
comment|/*  entry size vs capture size mismatch*/
end_comment

begin_comment
comment|/*  * Generic Entry Including Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_s
block|{
name|ql_minidump_entry_hdr_t
name|hdr
decl_stmt|;
name|uint32_t
name|entry_data00
decl_stmt|;
name|uint32_t
name|entry_data01
decl_stmt|;
name|uint32_t
name|entry_data02
decl_stmt|;
name|uint32_t
name|entry_data03
decl_stmt|;
name|uint32_t
name|entry_data04
decl_stmt|;
name|uint32_t
name|entry_data05
decl_stmt|;
name|uint32_t
name|entry_data06
decl_stmt|;
name|uint32_t
name|entry_data07
decl_stmt|;
block|}
name|ql_minidump_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  *  Read CRB Entry Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_rdcrb_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|addr_stride
decl_stmt|;
name|uint8_t
name|rsvd_0
decl_stmt|;
name|uint16_t
name|rsvd_1
decl_stmt|;
block|}
struct|;
name|uint32_t
name|addr_cntrl
decl_stmt|;
block|}
union|;
name|uint32_t
name|data_size
decl_stmt|;
name|uint32_t
name|op_count
decl_stmt|;
name|uint32_t
name|rsvd_2
decl_stmt|;
name|uint32_t
name|rsvd_3
decl_stmt|;
name|uint32_t
name|rsvd_4
decl_stmt|;
name|uint32_t
name|rsvd_5
decl_stmt|;
block|}
name|ql_minidump_entry_rdcrb_t
typedef|;
end_typedef

begin_comment
comment|/*  * Cache Entry Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_cache_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|tag_reg_addr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint16_t
name|tag_value_stride
decl_stmt|;
name|uint16_t
name|init_tag_value
decl_stmt|;
block|}
struct|;
name|uint32_t
name|select_addr_cntrl
decl_stmt|;
block|}
union|;
name|uint32_t
name|data_size
decl_stmt|;
name|uint32_t
name|op_count
decl_stmt|;
name|uint32_t
name|control_addr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint16_t
name|write_value
decl_stmt|;
name|uint8_t
name|poll_mask
decl_stmt|;
name|uint8_t
name|poll_wait
decl_stmt|;
block|}
struct|;
name|uint32_t
name|control_value
decl_stmt|;
block|}
union|;
name|uint32_t
name|read_addr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|read_addr_stride
decl_stmt|;
name|uint8_t
name|read_addr_cnt
decl_stmt|;
name|uint16_t
name|rsvd_1
decl_stmt|;
block|}
struct|;
name|uint32_t
name|read_addr_cntrl
decl_stmt|;
block|}
union|;
block|}
name|ql_minidump_entry_cache_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read OCM Entry Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_rdocm_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|rsvd_0
decl_stmt|;
name|uint32_t
name|rsvd_1
decl_stmt|;
name|uint32_t
name|data_size
decl_stmt|;
name|uint32_t
name|op_count
decl_stmt|;
name|uint32_t
name|rsvd_2
decl_stmt|;
name|uint32_t
name|rsvd_3
decl_stmt|;
name|uint32_t
name|read_addr
decl_stmt|;
name|uint32_t
name|read_addr_stride
decl_stmt|;
block|}
name|ql_minidump_entry_rdocm_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read MEM Entry Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_rdmem_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|rsvd_0
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|read_addr
decl_stmt|;
name|uint32_t
name|read_data_size
decl_stmt|;
block|}
name|ql_minidump_entry_rdmem_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read ROM Entry Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_rdrom_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|rsvd_0
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|read_addr
decl_stmt|;
name|uint32_t
name|read_data_size
decl_stmt|;
block|}
name|ql_minidump_entry_rdrom_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read MUX Entry Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_mux_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|select_addr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|rsvd_0
decl_stmt|;
block|}
struct|;
name|uint32_t
name|select_addr_cntrl
decl_stmt|;
block|}
union|;
name|uint32_t
name|data_size
decl_stmt|;
name|uint32_t
name|op_count
decl_stmt|;
name|uint32_t
name|select_value
decl_stmt|;
name|uint32_t
name|select_value_stride
decl_stmt|;
name|uint32_t
name|read_addr
decl_stmt|;
name|uint32_t
name|rsvd_1
decl_stmt|;
block|}
name|ql_minidump_entry_mux_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read MUX2 Entry Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_mux2_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|select_addr_1
decl_stmt|;
name|uint32_t
name|select_addr_2
decl_stmt|;
name|uint32_t
name|select_value_1
decl_stmt|;
name|uint32_t
name|select_value_2
decl_stmt|;
name|uint32_t
name|select_value_count
decl_stmt|;
name|uint32_t
name|select_value_mask
decl_stmt|;
name|uint32_t
name|read_addr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|select_value_stride
decl_stmt|;
name|uint8_t
name|data_size
decl_stmt|;
name|uint8_t
name|reserved_0
decl_stmt|;
name|uint8_t
name|reserved_1
decl_stmt|;
block|}
struct|;
name|uint32_t
name|select_addr_value_cntrl
decl_stmt|;
block|}
union|;
block|}
name|ql_minidump_entry_mux2_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read QUEUE Entry Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_queue_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|select_addr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint16_t
name|queue_id_stride
decl_stmt|;
name|uint16_t
name|rsvd_0
decl_stmt|;
block|}
struct|;
name|uint32_t
name|select_addr_cntrl
decl_stmt|;
block|}
union|;
name|uint32_t
name|data_size
decl_stmt|;
name|uint32_t
name|op_count
decl_stmt|;
name|uint32_t
name|rsvd_1
decl_stmt|;
name|uint32_t
name|rsvd_2
decl_stmt|;
name|uint32_t
name|read_addr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|read_addr_stride
decl_stmt|;
name|uint8_t
name|read_addr_cnt
decl_stmt|;
name|uint16_t
name|rsvd_3
decl_stmt|;
block|}
struct|;
name|uint32_t
name|read_addr_cntrl
decl_stmt|;
block|}
union|;
block|}
name|ql_minidump_entry_queue_t
typedef|;
end_typedef

begin_comment
comment|/*  * Control Entry Header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_cntrl_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|addr_stride
decl_stmt|;
name|uint8_t
name|state_index_a
decl_stmt|;
name|uint16_t
name|poll_timeout
decl_stmt|;
block|}
struct|;
name|uint32_t
name|addr_cntrl
decl_stmt|;
block|}
union|;
name|uint32_t
name|data_size
decl_stmt|;
name|uint32_t
name|op_count
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|state_index_v
decl_stmt|;
name|uint8_t
name|shl
decl_stmt|;
name|uint8_t
name|shr
decl_stmt|;
block|}
struct|;
name|uint32_t
name|control_value
decl_stmt|;
block|}
union|;
name|uint32_t
name|value_1
decl_stmt|;
name|uint32_t
name|value_2
decl_stmt|;
name|uint32_t
name|value_3
decl_stmt|;
block|}
name|ql_minidump_entry_cntrl_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read with poll.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_rdcrb_with_poll_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|select_addr
decl_stmt|;
name|uint32_t
name|read_addr
decl_stmt|;
name|uint32_t
name|select_value
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint16_t
name|select_value_stride
decl_stmt|;
name|uint16_t
name|op_count
decl_stmt|;
block|}
struct|;
name|uint32_t
name|select_value_cntrl
decl_stmt|;
block|}
union|;
name|uint32_t
name|poll
decl_stmt|;
name|uint32_t
name|mask
decl_stmt|;
name|uint32_t
name|data_size
decl_stmt|;
name|uint32_t
name|rsvd_0
decl_stmt|;
block|}
name|ql_minidump_entry_pollrd_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read_Modify_Write with poll.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ql_minidump_entry_rd_modify_wr_with_poll_s
block|{
name|ql_minidump_entry_hdr_t
name|h
decl_stmt|;
name|uint32_t
name|addr_1
decl_stmt|;
name|uint32_t
name|addr_2
decl_stmt|;
name|uint32_t
name|value_1
decl_stmt|;
name|uint32_t
name|value_2
decl_stmt|;
name|uint32_t
name|poll
decl_stmt|;
name|uint32_t
name|mask
decl_stmt|;
name|uint32_t
name|modify_mask
decl_stmt|;
name|uint32_t
name|data_size
decl_stmt|;
block|}
name|ql_minidump_entry_rd_modify_wr_with_poll_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QL_MINIDUMP_H_ */
end_comment

end_unit

