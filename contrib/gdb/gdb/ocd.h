begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for the Macraigor Systems BDM Wiggler    Copyright 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OCD_H
end_ifndef

begin_define
define|#
directive|define
name|OCD_H
end_define

begin_struct_decl
struct_decl|struct
name|mem_attrib
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_comment
comment|/* Wiggler serial protocol definitions */
end_comment

begin_define
define|#
directive|define
name|DLE
value|020
end_define

begin_comment
comment|/* Quote char */
end_comment

begin_define
define|#
directive|define
name|SYN
value|026
end_define

begin_comment
comment|/* Start of packet */
end_comment

begin_define
define|#
directive|define
name|RAW_SYN
value|((026<< 8) | 026)
end_define

begin_comment
comment|/* get_quoted_char found a naked SYN */
end_comment

begin_comment
comment|/* Status flags */
end_comment

begin_define
define|#
directive|define
name|OCD_FLAG_RESET
value|0x01
end_define

begin_comment
comment|/* Target is being reset */
end_comment

begin_define
define|#
directive|define
name|OCD_FLAG_STOPPED
value|0x02
end_define

begin_comment
comment|/* Target is halted */
end_comment

begin_define
define|#
directive|define
name|OCD_FLAG_BDM
value|0x04
end_define

begin_comment
comment|/* Target is in BDM */
end_comment

begin_define
define|#
directive|define
name|OCD_FLAG_PWF
value|0x08
end_define

begin_comment
comment|/* Power failed */
end_comment

begin_define
define|#
directive|define
name|OCD_FLAG_CABLE_DISC
value|0x10
end_define

begin_comment
comment|/* BDM cable disconnected */
end_comment

begin_comment
comment|/* Commands */
end_comment

begin_define
define|#
directive|define
name|OCD_AYT
value|0x0
end_define

begin_comment
comment|/* Are you there? */
end_comment

begin_define
define|#
directive|define
name|OCD_GET_VERSION
value|0x1
end_define

begin_comment
comment|/* Get Version */
end_comment

begin_define
define|#
directive|define
name|OCD_SET_BAUD_RATE
value|0x2
end_define

begin_comment
comment|/* Set Baud Rate */
end_comment

begin_define
define|#
directive|define
name|OCD_INIT
value|0x10
end_define

begin_comment
comment|/* Initialize Wiggler */
end_comment

begin_define
define|#
directive|define
name|OCD_SET_SPEED
value|0x11
end_define

begin_comment
comment|/* Set Speed */
end_comment

begin_define
define|#
directive|define
name|OCD_GET_STATUS_MASK
value|0x12
end_define

begin_comment
comment|/* Get Status Mask */
end_comment

begin_define
define|#
directive|define
name|OCD_GET_CTRS
value|0x13
end_define

begin_comment
comment|/* Get Error Counters */
end_comment

begin_define
define|#
directive|define
name|OCD_SET_FUNC_CODE
value|0x14
end_define

begin_comment
comment|/* Set Function Code */
end_comment

begin_define
define|#
directive|define
name|OCD_SET_CTL_FLAGS
value|0x15
end_define

begin_comment
comment|/* Set Control Flags */
end_comment

begin_define
define|#
directive|define
name|OCD_SET_BUF_ADDR
value|0x16
end_define

begin_comment
comment|/* Set Register Buffer Address */
end_comment

begin_define
define|#
directive|define
name|OCD_RUN
value|0x20
end_define

begin_comment
comment|/* Run Target from PC */
end_comment

begin_define
define|#
directive|define
name|OCD_RUN_ADDR
value|0x21
end_define

begin_comment
comment|/* Run Target from Specified Address */
end_comment

begin_define
define|#
directive|define
name|OCD_STOP
value|0x22
end_define

begin_comment
comment|/* Stop Target */
end_comment

begin_define
define|#
directive|define
name|OCD_RESET_RUN
value|0x23
end_define

begin_comment
comment|/* Reset Target and Run */
end_comment

begin_define
define|#
directive|define
name|OCD_RESET
value|0x24
end_define

begin_comment
comment|/* Reset Target and Halt */
end_comment

begin_define
define|#
directive|define
name|OCD_STEP
value|0x25
end_define

begin_comment
comment|/* Single step */
end_comment

begin_define
define|#
directive|define
name|OCD_READ_REGS
value|0x30
end_define

begin_comment
comment|/* Read Registers */
end_comment

begin_define
define|#
directive|define
name|OCD_WRITE_REGS
value|0x31
end_define

begin_comment
comment|/* Write Registers */
end_comment

begin_define
define|#
directive|define
name|OCD_READ_MEM
value|0x32
end_define

begin_comment
comment|/* Read Memory */
end_comment

begin_define
define|#
directive|define
name|OCD_WRITE_MEM
value|0x33
end_define

begin_comment
comment|/* Write Memory */
end_comment

begin_define
define|#
directive|define
name|OCD_FILL_MEM
value|0x34
end_define

begin_comment
comment|/* Fill Memory */
end_comment

begin_define
define|#
directive|define
name|OCD_MOVE_MEM
value|0x35
end_define

begin_comment
comment|/* Move Memory */
end_comment

begin_define
define|#
directive|define
name|OCD_READ_INT_MEM
value|0x80
end_define

begin_comment
comment|/* Read Internal Memory */
end_comment

begin_define
define|#
directive|define
name|OCD_WRITE_INT_MEM
value|0x81
end_define

begin_comment
comment|/* Write Internal Memory */
end_comment

begin_define
define|#
directive|define
name|OCD_JUMP
value|0x82
end_define

begin_comment
comment|/* Jump to Subroutine */
end_comment

begin_define
define|#
directive|define
name|OCD_ERASE_FLASH
value|0x90
end_define

begin_comment
comment|/* Erase flash memory */
end_comment

begin_define
define|#
directive|define
name|OCD_PROGRAM_FLASH
value|0x91
end_define

begin_comment
comment|/* Write flash memory */
end_comment

begin_define
define|#
directive|define
name|OCD_EXIT_MON
value|0x93
end_define

begin_comment
comment|/* Exit the flash programming monitor  */
end_comment

begin_define
define|#
directive|define
name|OCD_ENTER_MON
value|0x94
end_define

begin_comment
comment|/* Enter the flash programming monitor  */
end_comment

begin_define
define|#
directive|define
name|OCD_SET_STATUS
value|0x0a
end_define

begin_comment
comment|/* Set status */
end_comment

begin_define
define|#
directive|define
name|OCD_SET_CONNECTION
value|0xf0
end_define

begin_comment
comment|/* Set connection (init Wigglers.dll) */
end_comment

begin_define
define|#
directive|define
name|OCD_LOG_FILE
value|0xf1
end_define

begin_comment
comment|/* Cmd to get Wigglers.dll to log cmds */
end_comment

begin_define
define|#
directive|define
name|OCD_FLAG_STOP
value|0x0
end_define

begin_comment
comment|/* Stop the target, enter BDM */
end_comment

begin_define
define|#
directive|define
name|OCD_FLAG_START
value|0x01
end_define

begin_comment
comment|/* Start the target at PC */
end_comment

begin_define
define|#
directive|define
name|OCD_FLAG_RETURN_STATUS
value|0x04
end_define

begin_comment
comment|/* Return async status */
end_comment

begin_comment
comment|/* Target type (for OCD_INIT command) */
end_comment

begin_enum
enum|enum
name|ocd_target_type
block|{
name|OCD_TARGET_CPU32
init|=
literal|0x0
block|,
comment|/* Moto cpu32 family */
name|OCD_TARGET_CPU16
init|=
literal|0x1
block|,
name|OCD_TARGET_MOTO_PPC
init|=
literal|0x2
block|,
comment|/* Motorola PPC 5xx/8xx */
name|OCD_TARGET_IBM_PPC
init|=
literal|0x3
block|}
enum|;
end_enum

begin_comment
comment|/* IBM PPC 4xx */
end_comment

begin_function_decl
name|void
name|ocd_open
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|from_tty
parameter_list|,
name|enum
name|ocd_target_type
parameter_list|,
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_close
parameter_list|(
name|int
name|quitting
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_detach
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_resume
parameter_list|(
name|ptid_t
name|ptid
parameter_list|,
name|int
name|step
parameter_list|,
name|enum
name|target_signal
name|siggnal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_prepare_to_store
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_files_info
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ocd_xfer_memory
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|should_write
parameter_list|,
name|struct
name|mem_attrib
modifier|*
name|attrib
parameter_list|,
name|struct
name|target_ops
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_mourn
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_create_inferior
parameter_list|(
name|char
modifier|*
name|exec_file
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|char
modifier|*
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ocd_thread_alive
parameter_list|(
name|ptid_t
name|th
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_error
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|int
name|error_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_kill
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_load
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|ocd_read_bdm_registers
parameter_list|(
name|int
name|first_bdm_regno
parameter_list|,
name|int
name|last_bdm_regno
parameter_list|,
name|int
modifier|*
name|reglen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CORE_ADDR
name|ocd_read_bdm_register
parameter_list|(
name|int
name|bdm_regno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_write_bdm_registers
parameter_list|(
name|int
name|first_bdm_regno
parameter_list|,
name|unsigned
name|char
modifier|*
name|regptr
parameter_list|,
name|int
name|reglen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ocd_write_bdm_register
parameter_list|(
name|int
name|bdm_regno
parameter_list|,
name|CORE_ADDR
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ocd_wait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ocd_insert_breakpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|char
modifier|*
name|contents_cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ocd_remove_breakpoint
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|char
modifier|*
name|contents_cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ocd_write_bytes
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OCD_H */
end_comment

end_unit

