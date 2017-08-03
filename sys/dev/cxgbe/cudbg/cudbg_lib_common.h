begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Chelsio Communications, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CUDBG_LIB_COMMON_H__
end_ifndef

begin_define
define|#
directive|define
name|__CUDBG_LIB_COMMON_H__
end_define

begin_comment
comment|/* Extended entity  *  * Layout of the cudbg dump file when extended entity is present.  *  *  *           ----------------  *           | Global header |  *           |---------------|  *           |entity headers |  *           |---------------|  *           | Entity data   |  *           |      *        |  *           |      *        |  *           |      *        |  *           |---------------|  *           |extended entity|  *           |    header     |  *           |---------------|  *           |extended entity|  *           |     data      |  *           -----------------  *  *  * Extended entity: This comes into picture only when cudbg_collect() is called  * multiple times.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CUDBG_LITE
end_ifndef

begin_include
include|#
directive|include
file|"common/t4_hw.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CUDBG_SF_MAX_SECTOR
value|(FLASH_CUDBG_START_SEC + FLASH_CUDBG_NSECS)
end_define

begin_define
define|#
directive|define
name|CUDBG_SF_SECTOR_SIZE
value|SF_SEC_SIZE
end_define

begin_define
define|#
directive|define
name|CUDBG_START_SEC
value|FLASH_CUDBG_START_SEC
end_define

begin_define
define|#
directive|define
name|CUDBG_FLASH_SIZE
value|FLASH_CUDBG_MAX_SIZE
end_define

begin_define
define|#
directive|define
name|CUDBG_EXT_DATA_BIT
value|0
end_define

begin_define
define|#
directive|define
name|CUDBG_EXT_DATA_VALID
value|(1<< CUDBG_EXT_DATA_BIT)
end_define

begin_struct
struct|struct
name|cudbg_hdr
block|{
name|u32
name|signature
decl_stmt|;
name|u32
name|hdr_len
decl_stmt|;
name|u16
name|major_ver
decl_stmt|;
name|u16
name|minor_ver
decl_stmt|;
name|u32
name|data_len
decl_stmt|;
name|u32
name|hdr_flags
decl_stmt|;
name|u16
name|max_entities
decl_stmt|;
name|u8
name|chip_ver
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
name|u32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cudbg_entity_hdr
block|{
name|u32
name|entity_type
decl_stmt|;
name|u32
name|start_offset
decl_stmt|;
name|u32
name|size
decl_stmt|;
name|int
name|hdr_flags
decl_stmt|;
name|u32
name|sys_warn
decl_stmt|;
name|u32
name|sys_err
decl_stmt|;
name|u8
name|num_pad
decl_stmt|;
name|u8
name|flag
decl_stmt|;
comment|/* bit 0 is used to indicate ext data */
name|u8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|u32
name|next_ext_offset
decl_stmt|;
comment|/* pointer to next extended entity meta data */
name|u32
name|reserved
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cudbg_ver_hdr
block|{
name|u32
name|signature
decl_stmt|;
name|u16
name|revision
decl_stmt|;
name|u16
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cudbg_buffer
block|{
name|u32
name|size
decl_stmt|;
name|u32
name|offset
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cudbg_error
block|{
name|int
name|sys_err
decl_stmt|;
name|int
name|sys_warn
decl_stmt|;
name|int
name|app_err
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cudbg_flash_sec_info
block|{
name|int
name|par_sec
decl_stmt|;
comment|/* Represent partially filled sector no */
name|int
name|par_sec_offset
decl_stmt|;
comment|/* Offset in partially filled sector */
name|int
name|cur_seq_no
decl_stmt|;
name|u32
name|max_seq_no
decl_stmt|;
name|u32
name|max_seq_sec
decl_stmt|;
name|u32
name|hdr_data_len
decl_stmt|;
comment|/* Total data */
name|u32
name|skip_size
decl_stmt|;
comment|/* Total size of large entities. */
name|u64
name|max_timestamp
decl_stmt|;
name|char
name|sec_data
index|[
name|CUDBG_SF_SECTOR_SIZE
index|]
decl_stmt|;
name|u8
name|sec_bitmap
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cudbg_private
block|{
name|struct
name|cudbg_init
name|dbg_init
decl_stmt|;
name|struct
name|cudbg_flash_sec_info
name|sec_info
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HTONL_NIBBLE
parameter_list|(
name|data
parameter_list|)
value|( \ 			    (((uint32_t)(data)>> 28)& 0x0000000F) | \ 			    (((uint32_t)(data)>> 20)& 0x000000F0) | \ 			    (((uint32_t)(data)>> 12)& 0x00000F00) | \ 			    (((uint32_t)(data)>> 4)& 0x0000F000) | \ 			    (((uint32_t)(data)<< 4)& 0x000F0000) | \ 			    (((uint32_t)(data)<< 12)& 0x00F00000) | \ 			    (((uint32_t)(data)<< 20)& 0x0F000000) | \ 			    (((uint32_t)(data)<< 28)& 0xF0000000))
end_define

begin_define
define|#
directive|define
name|CDUMP_MAX_COMP_BUF_SIZE
value|((64 * 1024) - 1)
end_define

begin_define
define|#
directive|define
name|CUDBG_CHUNK_SIZE
value|((CDUMP_MAX_COMP_BUF_SIZE/1024) * 1024)
end_define

begin_define
define|#
directive|define
name|CUDBG_LEGACY_SIGNATURE
value|123
end_define

begin_define
define|#
directive|define
name|CUDBG_SIGNATURE
value|67856866
end_define

begin_comment
comment|/* CUDB in ascii */
end_comment

begin_define
define|#
directive|define
name|CUDBG_FL_SIGNATURE
value|0x4355464c
end_define

begin_comment
comment|/* CUFL in ascii */
end_comment

begin_define
define|#
directive|define
name|CUDBG_FL_MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|CUDBG_FL_MINOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|CUDBG_FL_BUILD_VERSION
value|0
end_define

begin_function_decl
name|void
name|update_skip_size
parameter_list|(
name|struct
name|cudbg_flash_sec_info
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_compression_hdr
parameter_list|(
name|struct
name|cudbg_buffer
modifier|*
parameter_list|,
name|struct
name|cudbg_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|compress_buff
parameter_list|(
name|struct
name|cudbg_buffer
modifier|*
parameter_list|,
name|struct
name|cudbg_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_scratch_buff
parameter_list|(
name|struct
name|cudbg_buffer
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|struct
name|cudbg_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|release_scratch_buff
parameter_list|(
name|struct
name|cudbg_buffer
modifier|*
parameter_list|,
name|struct
name|cudbg_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decompress_buffer
parameter_list|(
name|struct
name|cudbg_buffer
modifier|*
parameter_list|,
name|struct
name|cudbg_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|validate_buffer
parameter_list|(
name|struct
name|cudbg_buffer
modifier|*
name|compressed_buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decompress_buffer_wrapper
parameter_list|(
name|struct
name|cudbg_buffer
modifier|*
name|pc_buff
parameter_list|,
name|struct
name|cudbg_buffer
modifier|*
name|pdc_buff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_entity_rev
parameter_list|(
name|struct
name|cudbg_ver_hdr
modifier|*
name|ver_hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sort_t
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|int
name|num
parameter_list|,
name|int
name|size
parameter_list|,
name|int
function_decl|(
modifier|*
name|cmp_func
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|swap_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
name|size
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cudbg_read_flash
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|u32
name|size
parameter_list|,
name|int
name|data_flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cudbg_write_flash
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|u64
name|timestamp
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|u32
name|start_offset
parameter_list|,
name|u32
name|start_hdr_offset
parameter_list|,
name|u32
name|cur_entity_size
parameter_list|,
name|u32
name|ext_size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

