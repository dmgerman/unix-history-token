begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine independent GDB support for core files on systems using "regsets".    Copyright 1993-1998 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*			N  O  T  E  S  This file is used by most systems that implement /proc.  For these systems, the general registers are laid out the same way in both the core file and the gregset_p structure.  The current exception to this is Irix-4.*, where the gregset_p structure is split up into two pieces in the core file.  The general register and floating point register sets are manipulated by separate ioctl's.  This file makes the assumption that if FP0_REGNUM is defined, then support for the floating point register set is desired, regardless of whether or not the actual target has floating point hardware.   */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
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
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

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
name|_initialize_core_regset
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  GLOBAL FUNCTION  	fetch_core_registers -- fetch current registers from core file  SYNOPSIS  	void fetch_core_registers (char *core_reg_sect, 					  unsigned core_reg_size, 					  int which, CORE_ADDR reg_addr)  DESCRIPTION  	Read the values of either the general register set (WHICH equals 0) 	or the floating point register set (WHICH equals 2) from the core 	file data (pointed to by CORE_REG_SECT), and update gdb's idea of 	their current values.  The CORE_REG_SIZE parameter is ignored.  NOTES  	Use the indicated sizes to validate the gregset and fpregset 	structures. */
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
comment|/* Unused in this version */
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GREGSET_T
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_FPREGSET_T
argument_list|)
name|gregset_t
name|gregset
decl_stmt|;
name|fpregset_t
name|fpregset
decl_stmt|;
if|if
condition|(
name|which
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|core_reg_size
operator|!=
sizeof|sizeof
argument_list|(
name|gregset
argument_list|)
condition|)
block|{
name|warning
argument_list|(
literal|"wrong size gregset struct in core file"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
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
block|}
elseif|else
if|if
condition|(
name|which
operator|==
literal|2
condition|)
block|{
if|if
condition|(
name|core_reg_size
operator|!=
sizeof|sizeof
argument_list|(
name|fpregset
argument_list|)
condition|)
block|{
name|warning
argument_list|(
literal|"wrong size fpregset struct in core file"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
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
if|#
directive|if
name|defined
argument_list|(
name|FP0_REGNUM
argument_list|)
name|supply_fpregset
argument_list|(
operator|&
name|fpregset
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
endif|#
directive|endif
comment|/* defined(HAVE_GREGSET_T)&& defined (HAVE_FPREGSET_T) */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Register that we are able to handle ELF file formats using standard    procfs "regset" structures.  */
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
name|fetch_core_registers
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_initialize_core_regset
parameter_list|()
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

