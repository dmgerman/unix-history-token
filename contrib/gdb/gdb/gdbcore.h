begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine independent variables that describe the core file under GDB.    Copyright 1986, 1987, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996,    1997, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_comment
comment|/* Return the name of the executable file as a string.    ERR nonzero means get error if there is none specified;    otherwise return 0 in that case.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_exec_file
parameter_list|(
name|int
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Nonzero if there is a core file.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|have_core_file_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read "memory data" from whatever target or inferior we have.    Returns zero if successful, errno value if not.  EIO is used for    address out of bounds.  If breakpoints are inserted, returns shadow    contents, not the breakpoints themselves.  From breakpoint.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|read_memory_nobpt
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|char
modifier|*
name|myaddr
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Report a memory error with error().  */
end_comment

begin_function_decl
specifier|extern
name|void
name|memory_error
parameter_list|(
name|int
name|status
parameter_list|,
name|CORE_ADDR
name|memaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like target_read_memory, but report an error if can't read.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|read_memory
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

begin_comment
comment|/* Read an integer from debugged memory, given address and number of    bytes.  */
end_comment

begin_function_decl
specifier|extern
name|LONGEST
name|read_memory_integer
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|safe_read_memory_integer
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|int
name|len
parameter_list|,
name|LONGEST
modifier|*
name|return_value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read an unsigned integer from debugged memory, given address and    number of bytes.  */
end_comment

begin_function_decl
specifier|extern
name|ULONGEST
name|read_memory_unsigned_integer
parameter_list|(
name|CORE_ADDR
name|memaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a null-terminated string from the debuggee's memory, given address,  * a buffer into which to place the string, and the maximum available space */
end_comment

begin_function_decl
specifier|extern
name|void
name|read_memory_string
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read the pointer of type TYPE at ADDR, and return the address it    represents. */
end_comment

begin_function_decl
name|CORE_ADDR
name|read_memory_typed_address
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This takes a char *, not void *.  This is probably right, because    passing in an int * or whatever is wrong with respect to    byteswapping, alignment, different sizes for host vs. target types,    etc.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|write_memory
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

begin_comment
comment|/* Store VALUE at ADDR in the inferior as a LEN-byte unsigned integer.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|write_memory_unsigned_integer
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|ULONGEST
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Store VALUE at ADDR in the inferior as a LEN-byte unsigned integer.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|write_memory_signed_integer
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|LONGEST
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_search
parameter_list|(
name|int
name|len
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|char
modifier|*
name|mask
parameter_list|,
name|CORE_ADDR
name|startaddr
parameter_list|,
name|int
name|increment
parameter_list|,
name|CORE_ADDR
name|lorange
parameter_list|,
name|CORE_ADDR
name|hirange
parameter_list|,
name|CORE_ADDR
modifier|*
name|addr_found
parameter_list|,
name|char
modifier|*
name|data_found
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Hook for `exec_file_command' command to call.  */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|exec_file_display_hook
function_decl|)
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Hook for "file_command", which is more useful than above    (because it is invoked AFTER symbols are read, not before) */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|file_changed_hook
function_decl|)
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|specify_exec_file_hook
parameter_list|(
name|void
function_decl|(
modifier|*
name|hook
function_decl|)
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|void
name|core_file_command
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exec_open
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exec_file_attach
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exec_file_clear
parameter_list|(
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|validate_files
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|register_addr
parameter_list|(
name|int
name|regno
parameter_list|,
name|CORE_ADDR
name|blockend
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* The target vector for core files. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|target_ops
name|core_ops
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

begin_function_decl
specifier|extern
name|void
name|set_gnutarget
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Structure to keep track of core register reading functions for    various core file types.  */
end_comment

begin_struct
struct|struct
name|core_fns
block|{
comment|/* BFD flavour that a core file handler is prepared to read.  This        can be used by the handler's core tasting function as a first        level filter to reject BFD's that don't have the right        flavour. */
name|enum
name|bfd_flavour
name|core_flavour
decl_stmt|;
comment|/* Core file handler function to call to recognize corefile        formats that BFD rejects.  Some core file format just don't fit        into the BFD model, or may require other resources to identify        them, that simply aren't available to BFD (such as symbols from        another file).  Returns nonzero if the handler recognizes the        format, zero otherwise. */
name|int
function_decl|(
modifier|*
name|check_format
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
comment|/* Core file handler function to call to ask if it can handle a        given core file format or not.  Returns zero if it can't,        nonzero otherwise. */
name|int
function_decl|(
modifier|*
name|core_sniffer
function_decl|)
parameter_list|(
name|struct
name|core_fns
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
comment|/* Extract the register values out of the core file and store them where        `read_register' will find them.         CORE_REG_SECT points to the register values themselves, read into        memory.         CORE_REG_SIZE is the size of that area.         WHICH says which set of registers we are handling:          0 --- integer registers          2 --- floating-point registers, on machines where they are                discontiguous          3 --- extended floating-point registers, on machines where                these are present in yet a third area.  (GNU/Linux uses                this to get at the SSE registers.)         REG_ADDR is the offset from u.u_ar0 to the register values relative to        core_reg_sect.  This is used with old-fashioned core files to locate the        registers in a large upage-plus-stack ".reg" section.  Original upage        address X is at location core_reg_sect+x+reg_addr. */
name|void
function_decl|(
modifier|*
name|core_read_registers
function_decl|)
parameter_list|(
name|char
modifier|*
name|core_reg_sect
parameter_list|,
name|unsigned
name|core_reg_size
parameter_list|,
name|int
name|which
parameter_list|,
name|CORE_ADDR
name|reg_addr
parameter_list|)
function_decl|;
comment|/* Finds the next struct core_fns.  They are allocated and initialized        in whatever module implements the functions pointed to; an         initializer calls add_core_fns to add them to the global chain.  */
name|struct
name|core_fns
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|add_core_fns
parameter_list|(
name|struct
name|core_fns
modifier|*
name|cf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|default_core_sniffer
parameter_list|(
name|struct
name|core_fns
modifier|*
name|cf
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|default_check_format
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (GDBCORE_H) */
end_comment

end_unit

