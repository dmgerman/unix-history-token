begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* DPX2 host interface.    Copyright 1988, 1989, 1991, 1993, 1995, 2000    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"gdb_string.h"
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
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/reg.h>
end_include

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_escape
end_escape

begin_comment
comment|/* This table must line up with REGISTER_NAME in "m68k-tdep.c".  */
end_comment

begin_comment
comment|/* symbols like 'A0' come from<sys/reg.h> */
end_comment

begin_decl_stmt
specifier|static
name|int
name|regmap
index|[]
init|=
block|{
name|R0
block|,
name|R1
block|,
name|R2
block|,
name|R3
block|,
name|R4
block|,
name|R5
block|,
name|R6
block|,
name|R7
block|,
name|A0
block|,
name|A1
block|,
name|A2
block|,
name|A3
block|,
name|A4
block|,
name|A5
block|,
name|A6
block|,
name|SP
block|,
name|PS
block|,
name|PC
block|,
name|FP0
block|,
name|FP1
block|,
name|FP2
block|,
name|FP3
block|,
name|FP4
block|,
name|FP5
block|,
name|FP6
block|,
name|FP7
block|,
name|FP_CR
block|,
name|FP_SR
block|,
name|FP_IAR
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* blockend is the value of u.u_ar0, and points to the  * place where D0 is stored  */
end_comment

begin_function
name|int
name|dpx2_register_u_addr
parameter_list|(
name|int
name|blockend
parameter_list|,
name|int
name|regnum
parameter_list|)
block|{
if|if
condition|(
name|regnum
operator|<
name|FP0_REGNUM
condition|)
return|return
operator|(
name|blockend
operator|+
literal|4
operator|*
name|regmap
index|[
name|regnum
index|]
operator|)
return|;
else|else
return|return
operator|(
name|int
operator|)
operator|&
operator|(
operator|(
operator|(
expr|struct
name|user
operator|*
operator|)
literal|0
operator|)
operator|->
name|u_fpstate
index|[
name|regmap
index|[
name|regnum
index|]
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.    Unfortunately this is not provided in the system header files.    To make matters worse, this value also differs between    the dpx/2200 and dpx/2300 models and nlist is not available on the dpx2.    We use utsname() to decide on which model we are running.    FIXME: This breaks cross examination of core files (it would not be hard    to check whether u.u_ar0 is between 0x7fff5000 and 0x7fffc000 and if so    use 0x7fff5000 and if not use 0x7fffc000.  FIXME).  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR_200
value|0x7fff5000
end_define

begin_define
define|#
directive|define
name|KERNEL_U_ADDR_300
value|0x7fffc000
end_define

begin_decl_stmt
name|CORE_ADDR
name|kernel_u_addr
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_initialize_dpx2_nat
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|utsname
name|uts
decl_stmt|;
if|if
condition|(
name|uname
argument_list|(
operator|&
name|uts
argument_list|)
operator|==
literal|0
operator|&&
name|strcmp
argument_list|(
name|uts
operator|.
name|machine
argument_list|,
literal|"DPX/2200"
argument_list|)
operator|==
literal|0
condition|)
name|kernel_u_addr
operator|=
name|KERNEL_U_ADDR_200
expr_stmt|;
else|else
name|kernel_u_addr
operator|=
name|KERNEL_U_ADDR_300
expr_stmt|;
block|}
end_function

end_unit

