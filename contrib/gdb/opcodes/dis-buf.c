begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Disassemble from a buffer, for GNU.    Copyright (C) 1993, 1994 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"dis-asm.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* Get LENGTH bytes from info's buffer, at target address memaddr.    Transfer them to myaddr.  */
end_comment

begin_function
name|int
name|buffer_read_memory
parameter_list|(
name|memaddr
parameter_list|,
name|myaddr
parameter_list|,
name|length
parameter_list|,
name|info
parameter_list|)
name|bfd_vma
name|memaddr
decl_stmt|;
name|bfd_byte
modifier|*
name|myaddr
decl_stmt|;
name|int
name|length
decl_stmt|;
name|struct
name|disassemble_info
modifier|*
name|info
decl_stmt|;
block|{
if|if
condition|(
name|memaddr
operator|<
name|info
operator|->
name|buffer_vma
operator|||
name|memaddr
operator|+
name|length
operator|>
name|info
operator|->
name|buffer_vma
operator|+
name|info
operator|->
name|buffer_length
condition|)
comment|/* Out of bounds.  Use EIO because GDB uses it.  */
return|return
name|EIO
return|;
name|memcpy
argument_list|(
name|myaddr
argument_list|,
name|info
operator|->
name|buffer
operator|+
operator|(
name|memaddr
operator|-
name|info
operator|->
name|buffer_vma
operator|)
argument_list|,
name|length
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Print an error message.  We can assume that this is in response to    an error return from buffer_read_memory.  */
end_comment

begin_function
name|void
name|perror_memory
parameter_list|(
name|status
parameter_list|,
name|memaddr
parameter_list|,
name|info
parameter_list|)
name|int
name|status
decl_stmt|;
name|bfd_vma
name|memaddr
decl_stmt|;
name|struct
name|disassemble_info
modifier|*
name|info
decl_stmt|;
block|{
if|if
condition|(
name|status
operator|!=
name|EIO
condition|)
comment|/* Can't happen.  */
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"Unknown error %d\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
else|else
comment|/* Actually, address between memaddr and memaddr + len was        out of bounds.  */
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"Address 0x%x is out of bounds.\n"
argument_list|,
name|memaddr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This could be in a separate file, to save miniscule amounts of space    in statically linked executables.  */
end_comment

begin_comment
comment|/* Just print the address is hex.  This is included for completeness even    though both GDB and objdump provide their own (to print symbolic    addresses).  */
end_comment

begin_function
name|void
name|generic_print_address
parameter_list|(
name|addr
parameter_list|,
name|info
parameter_list|)
name|bfd_vma
name|addr
decl_stmt|;
name|struct
name|disassemble_info
modifier|*
name|info
decl_stmt|;
block|{
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"0x%x"
argument_list|,
name|addr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

