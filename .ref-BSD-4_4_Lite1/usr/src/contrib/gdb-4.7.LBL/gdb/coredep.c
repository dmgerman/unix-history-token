begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Extract registers from a "standard" core file, for GDB.    Copyright (C) 1988-1991  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* core.c is supposed to be the more machine-independent aspects of this;    this file is more machine-specific.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"nm.h"
end_include

begin_comment
comment|/* These are needed on various systems to expand REGISTER_U_ADDR.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extract the register values out of the core file and store    them where `read_register' will find them.     CORE_REG_SECT points to the register values themselves, read into memory.    CORE_REG_SIZE is the size of that area.    WHICH says which set of registers we are handling (0 = int, 2 = float          on machines where they are discontiguous).    REG_ADDR is the offset from u.u_ar0 to the register values relative to             core_reg_sect.  This is used with old-fashioned core files to 	    locate the registers in a large upage-plus-stack ".reg" section. 	    Original upage address X is at location core_reg_sect+x+reg_addr.  */
end_comment

begin_function
name|void
name|fetch_core_registers
parameter_list|(
name|core_reg_sect
parameter_list|,
name|core_reg_size
parameter_list|,
name|which
parameter_list|,
name|reg_addr
parameter_list|)
name|char
modifier|*
name|core_reg_sect
decl_stmt|;
name|unsigned
name|core_reg_size
decl_stmt|;
name|int
name|which
decl_stmt|;
name|unsigned
name|reg_addr
decl_stmt|;
block|{
specifier|register
name|int
name|regno
decl_stmt|;
specifier|register
name|unsigned
name|int
name|addr
decl_stmt|;
name|int
name|bad_reg
init|=
operator|-
literal|1
decl_stmt|;
specifier|register
name|reg_ptr
operator|=
operator|-
name|reg_addr
expr_stmt|;
comment|/* Original u.u_ar0 is -reg_addr. */
comment|/* If u.u_ar0 was an absolute address in the core file, relativize it now,      so we can use it as an offset into core_reg_sect.  When we're done,      "register 0" will be at core_reg_sect+reg_ptr, and we can use      register_addr to offset to the other registers.  If this is a modern      core file without a upage, reg_ptr will be zero and this is all a big      NOP.  */
if|if
condition|(
name|reg_ptr
operator|>
name|core_reg_size
condition|)
name|reg_ptr
operator|-=
name|KERNEL_U_ADDR
expr_stmt|;
for|for
control|(
name|regno
operator|=
literal|0
init|;
name|regno
operator|<
name|NUM_REGS
condition|;
name|regno
operator|++
control|)
block|{
name|addr
operator|=
name|register_addr
argument_list|(
name|regno
argument_list|,
name|reg_ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|addr
operator|>=
name|core_reg_size
condition|)
block|{
if|if
condition|(
name|bad_reg
operator|<
literal|0
condition|)
name|bad_reg
operator|=
name|regno
expr_stmt|;
block|}
else|else
block|{
name|supply_register
argument_list|(
name|regno
argument_list|,
name|core_reg_sect
operator|+
name|addr
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|bad_reg
operator|>=
literal|0
condition|)
block|{
name|error
argument_list|(
literal|"Register %s not found in core file."
argument_list|,
name|reg_names
index|[
name|bad_reg
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|REGISTER_U_ADDR
end_ifdef

begin_comment
comment|/* Return the address in the core dump or inferior of register REGNO.    BLOCKEND is the address of the end of the user structure.  */
end_comment

begin_function
name|unsigned
name|int
name|register_addr
parameter_list|(
name|regno
parameter_list|,
name|blockend
parameter_list|)
name|int
name|regno
decl_stmt|;
name|int
name|blockend
decl_stmt|;
block|{
name|int
name|addr
decl_stmt|;
if|if
condition|(
name|regno
operator|<
literal|0
operator|||
name|regno
operator|>=
name|NUM_REGS
condition|)
name|error
argument_list|(
literal|"Invalid register number %d."
argument_list|,
name|regno
argument_list|)
expr_stmt|;
name|REGISTER_U_ADDR
argument_list|(
name|addr
argument_list|,
name|blockend
argument_list|,
name|regno
argument_list|)
expr_stmt|;
return|return
name|addr
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REGISTER_U_ADDR */
end_comment

end_unit

