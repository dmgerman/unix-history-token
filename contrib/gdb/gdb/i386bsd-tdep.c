begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for i386 BSD's.    Copyright 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_comment
comment|/* Support for signal handlers.  */
end_comment

begin_comment
comment|/* Range in which to find the signaltramp routine, traditionally found    on the use stack, just below the user area.  Initialized to values    that work for NetBSD and FreeBSD.  */
end_comment

begin_decl_stmt
name|CORE_ADDR
name|i386bsd_sigtramp_start
init|=
literal|0xbfbfdf20
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|i386bsd_sigtramp_end
init|=
literal|0xbfbfdff0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return whether PC is in a BSD sigtramp routine.  */
end_comment

begin_function
name|int
name|i386bsd_in_sigtramp
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
operator|(
name|pc
operator|>=
name|i386bsd_sigtramp_start
operator|&&
name|pc
operator|<
name|i386bsd_sigtramp_end
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Offset in the sigcontext structure of the program counter.    Initialized to the value from 4.4 BSD Lite.  */
end_comment

begin_decl_stmt
name|int
name|i386bsd_sigcontext_pc_offset
init|=
literal|20
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assuming FRAME is for a BSD sigtramp routine, return the address of    the associated sigcontext structure.  */
end_comment

begin_function
specifier|static
name|CORE_ADDR
name|i386bsd_sigcontext_addr
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
block|{
if|if
condition|(
name|frame
operator|->
name|next
condition|)
comment|/* If this isn't the top frame, the next frame must be for the        signal handler itself.  A pointer to the sigcontext structure        is passed as the third argument to the signal handler.  */
return|return
name|read_memory_unsigned_integer
argument_list|(
name|frame
operator|->
name|next
operator|->
name|frame
operator|+
literal|16
argument_list|,
literal|4
argument_list|)
return|;
comment|/* This is the top frame.  We'll have to find the address of the      sigcontext structure by looking at the stack pointer.  */
return|return
name|read_memory_unsigned_integer
argument_list|(
name|read_register
argument_list|(
name|SP_REGNUM
argument_list|)
operator|+
literal|8
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Assuming FRAME is for a BSD sigtramp routine, return the saved    program counter.  */
end_comment

begin_function
specifier|static
name|CORE_ADDR
name|i386bsd_sigtramp_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
block|{
name|CORE_ADDR
name|addr
decl_stmt|;
name|addr
operator|=
name|i386bsd_sigcontext_addr
argument_list|(
name|frame
argument_list|)
expr_stmt|;
return|return
name|read_memory_unsigned_integer
argument_list|(
name|addr
operator|+
name|i386bsd_sigcontext_pc_offset
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Return the saved program counter for FRAME.  */
end_comment

begin_function
name|CORE_ADDR
name|i386bsd_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
block|{
if|if
condition|(
name|frame
operator|->
name|signal_handler_caller
condition|)
return|return
name|i386bsd_sigtramp_saved_pc
argument_list|(
name|frame
argument_list|)
return|;
return|return
name|read_memory_unsigned_integer
argument_list|(
name|frame
operator|->
name|frame
operator|+
literal|4
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

end_unit

