begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for the Macraigor Systems BDM Wiggler    Copyright 1996, 1997 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_decl_stmt
name|void
name|ocd_open
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|int
name|from_tty
operator|,
expr|enum
name|ocd_target_type
operator|,
expr|struct
name|target_ops
operator|*
name|ops
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_close
name|PARAMS
argument_list|(
operator|(
name|int
name|quitting
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_detach
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|args
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_resume
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|,
name|int
name|step
operator|,
expr|enum
name|target_signal
name|siggnal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_prepare_to_store
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_stop
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_files_info
name|PARAMS
argument_list|(
operator|(
expr|struct
name|target_ops
operator|*
name|ignore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ocd_xfer_memory
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|memaddr
operator|,
name|char
operator|*
name|myaddr
operator|,
name|int
name|len
operator|,
name|int
name|should_write
operator|,
expr|struct
name|target_ops
operator|*
name|target
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_mourn
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_create_inferior
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|exec_file
operator|,
name|char
operator|*
name|args
operator|,
name|char
operator|*
operator|*
name|env
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ocd_thread_alive
name|PARAMS
argument_list|(
operator|(
name|int
name|th
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_error
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|int
name|error_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_kill
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_load
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|args
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|ocd_read_bdm_registers
name|PARAMS
argument_list|(
operator|(
name|int
name|first_bdm_regno
operator|,
name|int
name|last_bdm_regno
operator|,
name|int
operator|*
name|reglen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|ocd_read_bdm_register
name|PARAMS
argument_list|(
operator|(
name|int
name|bdm_regno
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_write_bdm_registers
name|PARAMS
argument_list|(
operator|(
name|int
name|first_bdm_regno
operator|,
name|unsigned
name|char
operator|*
name|regptr
operator|,
name|int
name|reglen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ocd_write_bdm_register
name|PARAMS
argument_list|(
operator|(
name|int
name|bdm_regno
operator|,
name|CORE_ADDR
name|reg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ocd_wait
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ocd_insert_breakpoint
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|addr
operator|,
name|char
operator|*
name|contents_cache
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ocd_remove_breakpoint
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|addr
operator|,
name|char
operator|*
name|contents_cache
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ocd_write_bytes
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|memaddr
operator|,
name|char
operator|*
name|myaddr
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OCD_H */
end_comment

end_unit

