begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Extract registers from a "standard" core file, for GDB.    Copyright (C) 1988-1998  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Typically used on systems that have a.out format executables.    corefile.c is supposed to contain the more machine-independent    aspects of reading registers from core files, while this file is    more machine specific.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PTRACE_H
end_ifdef

begin_include
include|#
directive|include
file|<ptrace.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PTRACE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
file|"value.h"
end_include

begin_comment
comment|/* For supply_register.  */
end_comment

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_comment
comment|/* For ARCH_NUM_REGS. */
end_comment

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
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|"gdb_stat.h"
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CORE_REGISTER_ADDR
end_ifndef

begin_define
define|#
directive|define
name|CORE_REGISTER_ADDR
parameter_list|(
name|regno
parameter_list|,
name|regptr
parameter_list|)
value|register_addr(regno, regptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CORE_REGISTER_ADDR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SYS_CORE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/core.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|void
name|fetch_core_registers
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|unsigned
operator|,
name|int
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_initialize_core_aout
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Extract the register values out of the core file and store    them where `read_register' will find them.     CORE_REG_SECT points to the register values themselves, read into memory.    CORE_REG_SIZE is the size of that area.    WHICH says which set of registers we are handling (0 = int, 2 = float          on machines where they are discontiguous).    REG_ADDR is the offset from u.u_ar0 to the register values relative to             core_reg_sect.  This is used with old-fashioned core files to 	    locate the registers in a large upage-plus-stack ".reg" section. 	    Original upage address X is at location core_reg_sect+x+reg_addr.  */
end_comment

begin_function
specifier|static
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
name|CORE_ADDR
name|reg_addr
decl_stmt|;
block|{
name|int
name|regno
decl_stmt|;
name|CORE_ADDR
name|addr
decl_stmt|;
name|int
name|bad_reg
init|=
operator|-
literal|1
decl_stmt|;
name|CORE_ADDR
name|reg_ptr
init|=
operator|-
name|reg_addr
decl_stmt|;
comment|/* Original u.u_ar0 is -reg_addr. */
name|int
name|numregs
init|=
name|ARCH_NUM_REGS
decl_stmt|;
comment|/* If u.u_ar0 was an absolute address in the core file, relativize it now,      so we can use it as an offset into core_reg_sect.  When we're done,      "register 0" will be at core_reg_sect+reg_ptr, and we can use      CORE_REGISTER_ADDR to offset to the other registers.  If this is a modern      core file without a upage, reg_ptr will be zero and this is all a big      NOP.  */
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
name|numregs
condition|;
name|regno
operator|++
control|)
block|{
name|addr
operator|=
name|CORE_REGISTER_ADDR
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
operator|&&
name|bad_reg
operator|<
literal|0
condition|)
name|bad_reg
operator|=
name|regno
expr_stmt|;
else|else
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
if|if
condition|(
name|bad_reg
operator|>=
literal|0
condition|)
name|error
argument_list|(
literal|"Register %s not found in core file."
argument_list|,
name|REGISTER_NAME
argument_list|(
name|bad_reg
argument_list|)
argument_list|)
expr_stmt|;
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
name|CORE_ADDR
name|register_addr
parameter_list|(
name|regno
parameter_list|,
name|blockend
parameter_list|)
name|int
name|regno
decl_stmt|;
name|CORE_ADDR
name|blockend
decl_stmt|;
block|{
name|CORE_ADDR
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
name|ARCH_NUM_REGS
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

begin_escape
end_escape

begin_comment
comment|/* Register that we are able to handle aout (trad-core) file formats.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|core_fns
name|aout_core_fns
init|=
block|{
name|bfd_target_unknown_flavour
block|,
name|fetch_core_registers
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_initialize_core_aout
parameter_list|()
block|{
name|add_core_fns
argument_list|(
operator|&
name|aout_core_fns
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

