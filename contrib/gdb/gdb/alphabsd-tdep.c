begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common target dependent code for GDB on Alpha systems running BSD.    Copyright 2000, 2001, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"alpha-tdep.h"
end_include

begin_include
include|#
directive|include
file|"alphabsd-tdep.h"
end_include

begin_comment
comment|/* Conviently, GDB uses the same register numbering as the    ptrace register structure used by BSD on Alpha.  */
end_comment

begin_function
name|void
name|alphabsd_supply_reg
parameter_list|(
name|char
modifier|*
name|regs
parameter_list|,
name|int
name|regno
parameter_list|)
block|{
comment|/* PC is at slot 32; UNIQUE not present.  */
name|alpha_supply_int_regs
argument_list|(
name|regno
argument_list|,
name|regs
argument_list|,
name|regs
operator|+
literal|31
operator|*
literal|8
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|alphabsd_fill_reg
parameter_list|(
name|char
modifier|*
name|regs
parameter_list|,
name|int
name|regno
parameter_list|)
block|{
comment|/* PC is at slot 32; UNIQUE not present.  */
name|alpha_fill_int_regs
argument_list|(
name|regno
argument_list|,
name|regs
argument_list|,
name|regs
operator|+
literal|31
operator|*
literal|8
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|alphabsd_supply_fpreg
parameter_list|(
name|char
modifier|*
name|fpregs
parameter_list|,
name|int
name|regno
parameter_list|)
block|{
comment|/* FPCR is at slot 33; slot 32 unused.  */
name|alpha_supply_fp_regs
argument_list|(
name|regno
argument_list|,
name|fpregs
argument_list|,
name|fpregs
operator|+
literal|32
operator|*
literal|8
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|alphabsd_fill_fpreg
parameter_list|(
name|char
modifier|*
name|fpregs
parameter_list|,
name|int
name|regno
parameter_list|)
block|{
comment|/* FPCR is at slot 33; slot 32 unused.  */
name|alpha_fill_fp_regs
argument_list|(
name|regno
argument_list|,
name|fpregs
argument_list|,
name|fpregs
operator|+
literal|32
operator|*
literal|8
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

