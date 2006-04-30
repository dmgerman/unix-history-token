begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine independent GDB support for core files on systems using "regsets".     Copyright 1993, 1994, 1995, 1996, 1998, 1999, 2000, 2003    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file is used by most systems that use ELF for their core    dumps.  This includes most systems that have SVR4-ish variant of    /proc.  For these systems, the registers are laid out the same way    in core files as in the gregset_t and fpregset_t structures that    are used in the interaction with /proc (Irix 4 is an exception and    therefore doesn't use this file).  Quite a few systems without a    SVR4-ish /proc define these structures too, and can make use of    this code too.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"gdb_string.h"
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PROCFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/procfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prototypes for supply_gregset etc.  */
end_comment

begin_include
include|#
directive|include
file|"gregset.h"
end_include

begin_comment
comment|/* Provide registers to GDB from a core file.     CORE_REG_SECT points to an array of bytes, which are the contents    of a `note' from a core file which BFD thinks might contain    register contents.  CORE_REG_SIZE is its size.     WHICH says which register set corelow suspects this is:      0 --- the general-purpose register set, in gregset_t format      2 --- the floating-point register set, in fpregset_t format     REG_ADDR is ignored.  */
end_comment

begin_function
specifier|static
name|void
name|fetch_core_registers
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
block|{
name|gdb_gregset_t
name|gregset
decl_stmt|;
name|gdb_fpregset_t
name|fpregset
decl_stmt|;
switch|switch
condition|(
name|which
condition|)
block|{
case|case
literal|0
case|:
if|if
condition|(
name|core_reg_size
operator|!=
sizeof|sizeof
argument_list|(
name|gregset
argument_list|)
condition|)
name|warning
argument_list|(
literal|"Wrong size gregset in core file."
argument_list|)
expr_stmt|;
else|else
block|{
name|memcpy
argument_list|(
operator|&
name|gregset
argument_list|,
name|core_reg_sect
argument_list|,
sizeof|sizeof
argument_list|(
name|gregset
argument_list|)
argument_list|)
expr_stmt|;
name|supply_gregset
argument_list|(
operator|&
name|gregset
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|2
case|:
if|if
condition|(
name|core_reg_size
operator|!=
sizeof|sizeof
argument_list|(
name|fpregset
argument_list|)
condition|)
name|warning
argument_list|(
literal|"Wrong size fpregset in core file."
argument_list|)
expr_stmt|;
else|else
block|{
name|memcpy
argument_list|(
operator|&
name|fpregset
argument_list|,
name|core_reg_sect
argument_list|,
sizeof|sizeof
argument_list|(
name|fpregset
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FP0_REGNUM
operator|>=
literal|0
condition|)
name|supply_fpregset
argument_list|(
operator|&
name|fpregset
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
comment|/* We've covered all the kinds of registers we know about here,          so this must be something we wouldn't know what to do with          anyway.  Just ignore it.  */
break|break;
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Register that we are able to handle ELF core file formats using    standard procfs "regset" structures.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|core_fns
name|regset_core_fns
init|=
block|{
name|bfd_target_elf_flavour
block|,
comment|/* core_flavour */
name|default_check_format
block|,
comment|/* check_format */
name|default_core_sniffer
block|,
comment|/* core_sniffer */
name|fetch_core_registers
block|,
comment|/* core_read_registers */
name|NULL
comment|/* next */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Provide a prototype to silence -Wmissing-prototypes.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_initialize_core_regset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_core_regset
parameter_list|(
name|void
parameter_list|)
block|{
name|add_core_fns
argument_list|(
operator|&
name|regset_core_fns
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

