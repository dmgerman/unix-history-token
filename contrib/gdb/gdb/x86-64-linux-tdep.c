begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for GNU/Linux running on x86-64, for GDB.     Copyright 2001 Free Software Foundation, Inc.     Contributed by Jiri Smid, SuSE Labs.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"inferior.h"
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

begin_include
include|#
directive|include
file|"x86-64-tdep.h"
end_include

begin_include
include|#
directive|include
file|"dwarf2cfi.h"
end_include

begin_define
define|#
directive|define
name|LINUX_SIGTRAMP_INSN0
value|(0x48)
end_define

begin_comment
comment|/* mov $NNNNNNNN,%rax */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIGTRAMP_OFFSET0
value|(0)
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTRAMP_INSN1
value|(0x0f)
end_define

begin_comment
comment|/* syscall */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIGTRAMP_OFFSET1
value|(7)
end_define

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|char
name|linux_sigtramp_code
index|[]
init|=
block|{
name|LINUX_SIGTRAMP_INSN0
block|,
literal|0xc7
block|,
literal|0xc0
block|,
literal|0x89
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/*  mov $0x89,%rax */
name|LINUX_SIGTRAMP_INSN1
block|,
literal|0x05
comment|/* syscall */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LINUX_SIGTRAMP_LEN
value|(sizeof linux_sigtramp_code)
end_define

begin_comment
comment|/* If PC is in a sigtramp routine, return the address of the start of    the routine.  Otherwise, return 0.  */
end_comment

begin_function
specifier|static
name|CORE_ADDR
name|x86_64_linux_sigtramp_start
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
block|{
name|unsigned
name|char
name|buf
index|[
name|LINUX_SIGTRAMP_LEN
index|]
decl_stmt|;
if|if
condition|(
name|read_memory_nobpt
argument_list|(
name|pc
argument_list|,
operator|(
name|char
operator|*
operator|)
name|buf
argument_list|,
name|LINUX_SIGTRAMP_LEN
argument_list|)
operator|!=
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|buf
index|[
literal|0
index|]
operator|!=
name|LINUX_SIGTRAMP_INSN0
condition|)
block|{
if|if
condition|(
name|buf
index|[
literal|0
index|]
operator|!=
name|LINUX_SIGTRAMP_INSN1
condition|)
return|return
literal|0
return|;
name|pc
operator|-=
name|LINUX_SIGTRAMP_OFFSET1
expr_stmt|;
if|if
condition|(
name|read_memory_nobpt
argument_list|(
name|pc
argument_list|,
operator|(
name|char
operator|*
operator|)
name|buf
argument_list|,
name|LINUX_SIGTRAMP_LEN
argument_list|)
operator|!=
literal|0
condition|)
return|return
literal|0
return|;
block|}
if|if
condition|(
name|memcmp
argument_list|(
name|buf
argument_list|,
name|linux_sigtramp_code
argument_list|,
name|LINUX_SIGTRAMP_LEN
argument_list|)
operator|!=
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|pc
return|;
block|}
end_function

begin_define
define|#
directive|define
name|LINUX_SIGINFO_SIZE
value|128
end_define

begin_comment
comment|/* Offset to struct sigcontext in ucontext, from<asm/ucontext.h>.  */
end_comment

begin_define
define|#
directive|define
name|LINUX_UCONTEXT_SIGCONTEXT_OFFSET
value|(36)
end_define

begin_comment
comment|/* Assuming FRAME is for a GNU/Linux sigtramp routine, return the    address of the associated sigcontext structure.  */
end_comment

begin_function
name|CORE_ADDR
name|x86_64_linux_sigcontext_addr
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
block|{
name|CORE_ADDR
name|pc
decl_stmt|;
name|pc
operator|=
name|x86_64_linux_sigtramp_start
argument_list|(
name|frame
operator|->
name|pc
argument_list|)
expr_stmt|;
if|if
condition|(
name|pc
condition|)
block|{
if|if
condition|(
name|frame
operator|->
name|next
condition|)
comment|/* If this isn't the top frame, the next frame must be for the 	   signal handler itself.  The sigcontext structure is part of 	   the user context. */
return|return
name|frame
operator|->
name|next
operator|->
name|frame
operator|+
name|LINUX_SIGINFO_SIZE
operator|+
name|LINUX_UCONTEXT_SIGCONTEXT_OFFSET
return|;
comment|/* This is the top frame. */
return|return
name|read_register
argument_list|(
name|SP_REGNUM
argument_list|)
operator|+
name|LINUX_SIGINFO_SIZE
operator|+
name|LINUX_UCONTEXT_SIGCONTEXT_OFFSET
return|;
block|}
name|error
argument_list|(
literal|"Couldn't recognize signal trampoline."
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Offset to saved PC in sigcontext, from<asm/sigcontext.h>.  */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIGCONTEXT_PC_OFFSET
value|(136)
end_define

begin_comment
comment|/* Assuming FRAME is for a GNU/Linux sigtramp routine, return the    saved program counter.  */
end_comment

begin_function
name|CORE_ADDR
name|x86_64_linux_sigtramp_saved_pc
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
name|x86_64_linux_sigcontext_addr
argument_list|(
name|frame
argument_list|)
expr_stmt|;
return|return
name|read_memory_integer
argument_list|(
name|addr
operator|+
name|LINUX_SIGCONTEXT_PC_OFFSET
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Immediately after a function call, return the saved pc.  */
end_comment

begin_function
name|CORE_ADDR
name|x86_64_linux_saved_pc_after_call
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
name|x86_64_linux_sigtramp_saved_pc
argument_list|(
name|frame
argument_list|)
return|;
return|return
name|read_memory_integer
argument_list|(
name|read_register
argument_list|(
name|SP_REGNUM
argument_list|)
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Saved Pc.  Get it from sigcontext if within sigtramp.  */
end_comment

begin_function
name|CORE_ADDR
name|x86_64_linux_frame_saved_pc
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
name|x86_64_linux_sigtramp_saved_pc
argument_list|(
name|frame
argument_list|)
return|;
return|return
name|cfi_get_ra
argument_list|(
name|frame
argument_list|)
return|;
block|}
end_function

end_unit

