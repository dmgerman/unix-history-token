begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for SVR4 Unix running on i386's, for GDB.    Copyright 1988, 1989, 1991, 1992, 1996, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_REG_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/reg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"i387-nat.h"
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

begin_comment
comment|/* Prototypes for supply_gregset etc. */
end_comment

begin_include
include|#
directive|include
file|"gregset.h"
end_include

begin_comment
comment|/*  The /proc interface divides the target machine's register set up into    two different sets, the general register set (gregset) and the floating    point register set (fpregset).  For each set, there is an ioctl to get    the current register set and another ioctl to set the current values.     The actual structure passed through the ioctl interface is, of course,    naturally machine dependent, and is different for each set of registers.    For the i386 for example, the general register set is typically defined    by:     typedef int gregset_t[19];           (in<sys/regset.h>)     #define GS   0                       (in<sys/reg.h>)    #define FS   1    ...    #define UESP 17    #define SS   18     and the floating point set by:     typedef struct fpregset    {    union    {    struct fpchip_state  // fp extension state //    {    int state[27];       // 287/387 saved state //    int status;          // status word saved at exception //    } fpchip_state;    struct fp_emul_space // for emulators //    {    char fp_emul[246];    char fp_epad[2];    } fp_emul_space;    int f_fpregs[62];    // union of the above //    } fp_reg_set;    long f_wregs[33];            // saved weitek state //    } fpregset_t;     These routines provide the packing and unpacking of gregset_t and    fpregset_t formatted data.   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GREGSET_T
end_ifdef

begin_comment
comment|/* This is a duplicate of the table in i386-xdep.c. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|regmap
index|[]
init|=
block|{
name|EAX
block|,
name|ECX
block|,
name|EDX
block|,
name|EBX
block|,
name|UESP
block|,
name|EBP
block|,
name|ESI
block|,
name|EDI
block|,
name|EIP
block|,
name|EFL
block|,
name|CS
block|,
name|SS
block|,
name|DS
block|,
name|ES
block|,
name|FS
block|,
name|GS
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prototypes for local functions */
end_comment

begin_function_decl
name|void
name|fill_gregset
parameter_list|(
name|gregset_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|supply_gregset
parameter_list|(
name|gregset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|supply_fpregset
parameter_list|(
name|fpregset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fill_fpregset
parameter_list|(
name|fpregset_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  FIXME:  These routine absolutely depends upon (NUM_REGS - NUM_FREGS)    being less than or equal to the number of registers that can be stored    in a gregset_t.  Note that with the current scheme there will typically    be more registers actually stored in a gregset_t that what we know    about.  This is bogus and should be fixed. */
end_comment

begin_comment
comment|/*  Given a pointer to a general register set in /proc format (gregset_t *),    unpack the register contents and supply them as gdb's idea of the current    register values. */
end_comment

begin_function
name|void
name|supply_gregset
parameter_list|(
name|gregset_t
modifier|*
name|gregsetp
parameter_list|)
block|{
specifier|register
name|int
name|regi
decl_stmt|;
specifier|register
name|greg_t
modifier|*
name|regp
init|=
operator|(
name|greg_t
operator|*
operator|)
name|gregsetp
decl_stmt|;
specifier|extern
name|int
name|regmap
index|[]
decl_stmt|;
for|for
control|(
name|regi
operator|=
literal|0
init|;
name|regi
operator|<
operator|(
name|NUM_REGS
operator|-
name|NUM_FREGS
operator|)
condition|;
name|regi
operator|++
control|)
block|{
name|supply_register
argument_list|(
name|regi
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|(
name|regp
operator|+
name|regmap
index|[
name|regi
index|]
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|fill_gregset
parameter_list|(
name|gregset_t
modifier|*
name|gregsetp
parameter_list|,
name|int
name|regno
parameter_list|)
block|{
name|int
name|regi
decl_stmt|;
specifier|register
name|greg_t
modifier|*
name|regp
init|=
operator|(
name|greg_t
operator|*
operator|)
name|gregsetp
decl_stmt|;
specifier|extern
name|int
name|regmap
index|[]
decl_stmt|;
for|for
control|(
name|regi
operator|=
literal|0
init|;
name|regi
operator|<
operator|(
name|NUM_REGS
operator|-
name|NUM_FREGS
operator|)
condition|;
name|regi
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|regno
operator|==
operator|-
literal|1
operator|)
operator|||
operator|(
name|regno
operator|==
name|regi
operator|)
condition|)
block|{
operator|*
operator|(
name|regp
operator|+
name|regmap
index|[
name|regi
index|]
operator|)
operator|=
operator|*
operator|(
name|int
operator|*
operator|)
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|regi
argument_list|)
index|]
expr_stmt|;
block|}
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GREGSET_T */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FPREGSET_T
argument_list|)
end_if

begin_comment
comment|/*  Given a pointer to a floating point register set in /proc format    (fpregset_t *), unpack the register contents and supply them as gdb's    idea of the current floating point register values. */
end_comment

begin_comment
comment|/* FIXME: Assumes that fpregsetp contains an i387 FSAVE area. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FPREGSET_FSAVE_OFFSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|FPREGSET_FSAVE_OFFSET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|supply_fpregset
parameter_list|(
name|fpregset_t
modifier|*
name|fpregsetp
parameter_list|)
block|{
if|if
condition|(
name|NUM_FREGS
operator|==
literal|0
condition|)
return|return;
name|i387_supply_fsave
argument_list|(
operator|(
name|char
operator|*
operator|)
name|fpregsetp
operator|+
name|FPREGSET_FSAVE_OFFSET
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  Given a pointer to a floating point register set in /proc format    (fpregset_t *), update the register specified by REGNO from gdb's idea    of the current floating point register set.  If REGNO is -1, update    them all. */
end_comment

begin_function
name|void
name|fill_fpregset
parameter_list|(
name|fpregset_t
modifier|*
name|fpregsetp
parameter_list|,
name|int
name|regno
parameter_list|)
block|{
if|if
condition|(
name|NUM_FREGS
operator|==
literal|0
condition|)
return|return;
name|i387_fill_fsave
argument_list|(
operator|(
name|char
operator|*
operator|)
name|fpregsetp
operator|+
name|FPREGSET_FSAVE_OFFSET
argument_list|,
name|regno
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (HAVE_FPREGSET_T) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PROCFS_H */
end_comment

end_unit

