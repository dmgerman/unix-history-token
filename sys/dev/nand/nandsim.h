begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2009-2012 Semihalf  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NANDSIM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NANDSIM_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|MAX_SIM_DEV
value|4
end_define

begin_define
define|#
directive|define
name|MAX_CTRL_CS
value|4
end_define

begin_define
define|#
directive|define
name|MAX_ECC_BYTES
value|512
end_define

begin_define
define|#
directive|define
name|MAX_BAD_BLOCKS
value|512
end_define

begin_define
define|#
directive|define
name|DEV_MODEL_STR_SIZE
value|21
end_define

begin_define
define|#
directive|define
name|MAN_STR_SIZE
value|13
end_define

begin_define
define|#
directive|define
name|FILENAME_SIZE
value|20
end_define

begin_define
define|#
directive|define
name|MAX_CHIPS
value|(MAX_SIM_DEV*MAX_CTRL_CS)
end_define

begin_define
define|#
directive|define
name|NANDSIM_OUTPUT_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|NANDSIM_OUTPUT_CONSOLE
value|0x1
end_define

begin_define
define|#
directive|define
name|NANDSIM_OUTPUT_RAM
value|0x2
end_define

begin_define
define|#
directive|define
name|NANDSIM_OUTPUT_FILE
value|0x3
end_define

begin_struct
struct|struct
name|sim_ctrl_chip
block|{
name|uint8_t
name|ctrl_num
decl_stmt|;
name|uint8_t
name|chip_num
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDSIM_BASE
value|'A'
end_define

begin_struct
struct|struct
name|sim_param
block|{
name|uint8_t
name|log_level
decl_stmt|;
name|uint8_t
name|log_output
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDSIM_SIM_PARAM
value|_IOW(NANDSIM_BASE, 1, struct sim_param)
end_define

begin_struct
struct|struct
name|sim_ctrl
block|{
name|uint8_t
name|running
decl_stmt|;
name|uint8_t
name|created
decl_stmt|;
name|uint8_t
name|num
decl_stmt|;
name|uint8_t
name|num_cs
decl_stmt|;
name|uint8_t
name|ecc
decl_stmt|;
name|char
name|filename
index|[
name|FILENAME_SIZE
index|]
decl_stmt|;
name|uint16_t
name|ecc_layout
index|[
name|MAX_ECC_BYTES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDSIM_CREATE_CTRL
value|_IOW(NANDSIM_BASE, 2, struct sim_ctrl)
end_define

begin_define
define|#
directive|define
name|NANDSIM_DESTROY_CTRL
value|_IOW(NANDSIM_BASE, 3, int)
end_define

begin_struct
struct|struct
name|sim_chip
block|{
name|uint8_t
name|num
decl_stmt|;
name|uint8_t
name|ctrl_num
decl_stmt|;
name|uint8_t
name|created
decl_stmt|;
name|uint8_t
name|device_id
decl_stmt|;
name|uint8_t
name|manufact_id
decl_stmt|;
name|char
name|device_model
index|[
name|DEV_MODEL_STR_SIZE
index|]
decl_stmt|;
name|char
name|manufacturer
index|[
name|MAN_STR_SIZE
index|]
decl_stmt|;
name|uint8_t
name|col_addr_cycles
decl_stmt|;
name|uint8_t
name|row_addr_cycles
decl_stmt|;
name|uint8_t
name|features
decl_stmt|;
name|uint8_t
name|width
decl_stmt|;
name|uint32_t
name|page_size
decl_stmt|;
name|uint32_t
name|oob_size
decl_stmt|;
name|uint32_t
name|pgs_per_blk
decl_stmt|;
name|uint32_t
name|blks_per_lun
decl_stmt|;
name|uint32_t
name|luns
decl_stmt|;
name|uint32_t
name|prog_time
decl_stmt|;
name|uint32_t
name|erase_time
decl_stmt|;
name|uint32_t
name|read_time
decl_stmt|;
name|uint32_t
name|ccs_time
decl_stmt|;
name|uint32_t
name|error_ratio
decl_stmt|;
name|uint32_t
name|wear_level
decl_stmt|;
name|uint32_t
name|bad_block_map
index|[
name|MAX_BAD_BLOCKS
index|]
decl_stmt|;
name|uint8_t
name|is_wp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDSIM_CREATE_CHIP
value|_IOW(NANDSIM_BASE, 3, struct sim_chip)
end_define

begin_struct
struct|struct
name|sim_chip_destroy
block|{
name|uint8_t
name|ctrl_num
decl_stmt|;
name|uint8_t
name|chip_num
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDSIM_DESTROY_CHIP
value|_IOW(NANDSIM_BASE, 4, struct sim_chip_destroy)
end_define

begin_define
define|#
directive|define
name|NANDSIM_START_CTRL
value|_IOW(NANDSIM_BASE, 5, int)
end_define

begin_define
define|#
directive|define
name|NANDSIM_STOP_CTRL
value|_IOW(NANDSIM_BASE, 6, int)
end_define

begin_define
define|#
directive|define
name|NANDSIM_RESTART_CTRL
value|_IOW(NANDSIM_BASE, 7, int)
end_define

begin_define
define|#
directive|define
name|NANDSIM_STATUS_CTRL
value|_IOWR(NANDSIM_BASE, 8, struct sim_ctrl)
end_define

begin_define
define|#
directive|define
name|NANDSIM_STATUS_CHIP
value|_IOWR(NANDSIM_BASE, 9, struct sim_chip)
end_define

begin_struct
struct|struct
name|sim_mod
block|{
name|uint8_t
name|chip_num
decl_stmt|;
name|uint8_t
name|ctrl_num
decl_stmt|;
name|uint32_t
name|field
decl_stmt|;
name|uint32_t
name|new_value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIM_MOD_LOG_LEVEL
value|0
end_define

begin_define
define|#
directive|define
name|SIM_MOD_ERASE_TIME
value|1
end_define

begin_define
define|#
directive|define
name|SIM_MOD_PROG_TIME
value|2
end_define

begin_define
define|#
directive|define
name|SIM_MOD_READ_TIME
value|3
end_define

begin_define
define|#
directive|define
name|SIM_MOD_CCS_TIME
value|4
end_define

begin_define
define|#
directive|define
name|SIM_MOD_ERROR_RATIO
value|5
end_define

begin_define
define|#
directive|define
name|NANDSIM_MODIFY
value|_IOW(NANDSIM_BASE, 10, struct sim_mod)
end_define

begin_define
define|#
directive|define
name|NANDSIM_FREEZE
value|_IOW(NANDSIM_BASE, 11, struct sim_ctrl_chip)
end_define

begin_struct
struct|struct
name|sim_error
block|{
name|uint8_t
name|ctrl_num
decl_stmt|;
name|uint8_t
name|chip_num
decl_stmt|;
name|uint32_t
name|page_num
decl_stmt|;
name|uint32_t
name|column
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|pattern
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDSIM_INJECT_ERROR
value|_IOW(NANDSIM_BASE, 20, struct sim_error)
end_define

begin_define
define|#
directive|define
name|NANDSIM_GOOD_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|NANDSIM_BAD_BLOCK
value|1
end_define

begin_struct
struct|struct
name|sim_block_state
block|{
name|uint8_t
name|ctrl_num
decl_stmt|;
name|uint8_t
name|chip_num
decl_stmt|;
name|uint32_t
name|block_num
decl_stmt|;
name|int
name|wearout
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDSIM_SET_BLOCK_STATE
value|_IOW(NANDSIM_BASE, 21, struct sim_block_state)
end_define

begin_define
define|#
directive|define
name|NANDSIM_GET_BLOCK_STATE
value|_IOWR(NANDSIM_BASE, 22, struct sim_block_state)
end_define

begin_struct
struct|struct
name|sim_log
block|{
name|uint8_t
name|ctrl_num
decl_stmt|;
name|char
modifier|*
name|log
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDSIM_PRINT_LOG
value|_IOWR(NANDSIM_BASE, 23, struct sim_log)
end_define

begin_struct
struct|struct
name|sim_dump
block|{
name|uint8_t
name|ctrl_num
decl_stmt|;
name|uint8_t
name|chip_num
decl_stmt|;
name|uint32_t
name|block_num
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDSIM_DUMP
value|_IOWR(NANDSIM_BASE, 24, struct sim_dump)
end_define

begin_define
define|#
directive|define
name|NANDSIM_RESTORE
value|_IOWR(NANDSIM_BASE, 25, struct sim_dump)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NANDSIM_H_ */
end_comment

end_unit

