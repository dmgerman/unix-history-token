begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for NetBSD/i386, for GDB.    Copyright 1988, 1989, 1991, 1992, 1994, 1996, 2000, 2001, 2002    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GREGSET_T
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|reg
name|gregset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FPREGSET_T
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|fpreg
name|fpregset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gregset.h"
end_include

begin_comment
comment|/* Prototypes for i387_supply_fsave etc.  */
end_comment

begin_include
include|#
directive|include
file|"i387-nat.h"
end_include

begin_struct
struct|struct
name|md_core
block|{
name|struct
name|reg
name|intreg
decl_stmt|;
name|char
name|freg
index|[
literal|108
index|]
decl_stmt|;
block|}
struct|;
end_struct

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
name|ignore
parameter_list|)
block|{
name|struct
name|md_core
modifier|*
name|core_reg
init|=
operator|(
expr|struct
name|md_core
operator|*
operator|)
name|core_reg_sect
decl_stmt|;
comment|/* We get everything from one section.  */
if|if
condition|(
name|which
operator|!=
literal|0
condition|)
return|return;
comment|/* Integer registers.  */
name|supply_gregset
argument_list|(
operator|&
name|core_reg
operator|->
name|intreg
argument_list|)
expr_stmt|;
comment|/* Floating point registers.  */
name|i387_supply_fsave
argument_list|(
name|core_reg
operator|->
name|freg
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|fetch_elfcore_registers
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
name|ignore
parameter_list|)
block|{
name|gregset_t
name|gregset
decl_stmt|;
switch|switch
condition|(
name|which
condition|)
block|{
case|case
literal|0
case|:
comment|/* Integer registers.  */
if|if
condition|(
name|core_reg_size
operator|!=
sizeof|sizeof
argument_list|(
expr|struct
name|reg
argument_list|)
condition|)
name|warning
argument_list|(
literal|"Wrong size register set in core file."
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
comment|/* Floating point registers.  */
if|if
condition|(
name|core_reg_size
operator|!=
literal|108
condition|)
name|warning
argument_list|(
literal|"Wrong size FP register set in core file."
argument_list|)
expr_stmt|;
else|else
name|i387_supply_fsave
argument_list|(
name|core_reg_sect
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
comment|/* "Extended" floating point registers.  This is gdb-speak 		for SSE/SSE2. */
if|if
condition|(
name|core_reg_size
operator|!=
literal|512
condition|)
name|warning
argument_list|(
literal|"Wrong size XMM register set in core file."
argument_list|)
expr_stmt|;
else|else
name|i387_supply_fxsave
argument_list|(
name|core_reg_sect
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* Don't know what kind of register request this is; just ignore it.  */
break|break;
block|}
block|}
end_function

begin_comment
comment|/* Register that we are able to handle i386nbsd core file formats.    FIXME: is this really bfd_target_unknown_flavour? */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|core_fns
name|i386nbsd_core_fns
init|=
block|{
name|bfd_target_unknown_flavour
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

begin_decl_stmt
specifier|static
name|struct
name|core_fns
name|i386nbsd_elfcore_fns
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
name|fetch_elfcore_registers
block|,
comment|/* core_read_registers */
name|NULL
comment|/* next */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_initialize_i386nbsd_nat
parameter_list|(
name|void
parameter_list|)
block|{
name|add_core_fns
argument_list|(
operator|&
name|i386nbsd_core_fns
argument_list|)
expr_stmt|;
name|add_core_fns
argument_list|(
operator|&
name|i386nbsd_elfcore_fns
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

