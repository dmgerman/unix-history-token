begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine independent variables that describe the core file under GDB.    Copyright 1986, 1987, 1989, 1990, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Interface routines for core, executable, etc.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDBCORE_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|GDBCORE_H
value|1
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_comment
comment|/* Binary File Description */
end_comment

begin_comment
comment|/* Return the name of the executable file as a string.    ERR nonzero means get error if there is none specified;    otherwise return 0 in that case.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|get_exec_file
name|PARAMS
argument_list|(
operator|(
name|int
name|err
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if there is a core file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|have_core_file_p
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read "memory data" from whatever target or inferior we have.     Returns zero if successful, errno value if not.  EIO is used    for address out of bounds.  If breakpoints are inserted, returns    shadow contents, not the breakpoints themselves.  From breakpoint.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|read_memory_nobpt
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
name|unsigned
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report a memory error with error().  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|memory_error
name|PARAMS
argument_list|(
operator|(
name|int
name|status
operator|,
name|CORE_ADDR
name|memaddr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like target_read_memory, but report an error if can't read.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|read_memory
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

begin_comment
comment|/* Read an integer from debugged memory, given address and number of bytes.  */
end_comment

begin_decl_stmt
specifier|extern
name|LONGEST
name|read_memory_integer
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|memaddr
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read an unsigned integer from debugged memory, given address and number of bytes.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|LONGEST
name|read_memory_unsigned_integer
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|memaddr
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If this is prototyped, need to deal with void* vs. char*.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|write_memory
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

begin_comment
comment|/* Hook for `exec_file_command' command to call.  */
end_comment

begin_extern
extern|extern void (*exec_file_display_hook
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|void
name|specify_exec_file_hook
name|PARAMS
argument_list|(
operator|(
name|void
argument_list|(
operator|*
name|hook
argument_list|)
argument_list|(
name|char
operator|*
name|filename
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Binary File Diddlers for the exec and core files */
end_comment

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|core_bfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|exec_bfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether to open exec and core files read-only or read-write.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|write_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|core_file_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|exec_file_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|validate_files
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|register_addr
name|PARAMS
argument_list|(
operator|(
name|int
name|regno
operator|,
name|int
name|blockend
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xfer_core_file
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

begin_decl_stmt
specifier|extern
name|void
name|fetch_core_registers
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|core_reg_sect
operator|,
name|unsigned
name|core_reg_size
operator|,
name|int
name|which
operator|,
name|unsigned
name|int
name|reg_addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|registers_fetched
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL_U_ADDR
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|kernel_u_addr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|kernel_u_addr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The target vector for core files */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|target_ops
name|core_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* target vector functions called directly from elsewhere */
end_comment

begin_decl_stmt
name|void
name|core_open
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|core_detach
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current default bfd target.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|gnutarget
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_gnutarget
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (GDBCORE_H) */
end_comment

end_unit

