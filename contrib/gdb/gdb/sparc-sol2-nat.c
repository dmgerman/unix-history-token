begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for Solaris SPARC.     Copyright 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_include
include|#
directive|include
file|<sys/procfs.h>
end_include

begin_include
include|#
directive|include
file|"gregset.h"
end_include

begin_include
include|#
directive|include
file|"sparc-tdep.h"
end_include

begin_comment
comment|/* This file provids the (temporary) glue between the Solaris SPARC    target dependent code and the machine independent SVR4 /proc    support.  */
end_comment

begin_comment
comment|/* Solaris 7 (Solaris 2.7, SunOS 5.7) and up support two process data    models, the traditional 32-bit data model (ILP32) and the 64-bit    data model (LP64).  The format of /proc depends on the data model    of the observer (the controlling process, GDB in our case).  The    Solaris header files conveniently define PR_MODEL_NATIVE to the    data model of the controlling process.  If its value is    PR_MODEL_LP64, we know that GDB is being compiled as a 64-bit    program.     GNU/Linux uses the same formats as Solaris for its core files (but    not for ptrace(2)).  The GNU/Linux headers don't define    PR_MODEL_NATIVE though.  Therefore we rely on the __arch64__ define    provided by GCC to determine the appropriate data model.     Note that a 32-bit GDB won't be able to debug a 64-bit target    process using /proc on Solaris.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|PR_MODEL_NATIVE
argument_list|)
operator|&&
operator|(
name|PR_MODEL_NATIVE
operator|==
name|PR_MODEL_LP64
operator|)
operator|)
operator|)
end_if

begin_include
include|#
directive|include
file|"sparc64-tdep.h"
end_include

begin_define
define|#
directive|define
name|sparc_supply_gregset
value|sparc64_supply_gregset
end_define

begin_define
define|#
directive|define
name|sparc_supply_fpregset
value|sparc64_supply_fpregset
end_define

begin_define
define|#
directive|define
name|sparc_collect_gregset
value|sparc64_collect_gregset
end_define

begin_define
define|#
directive|define
name|sparc_collect_fpregset
value|sparc64_collect_fpregset
end_define

begin_define
define|#
directive|define
name|sparc_sol2_gregset
value|sparc64_sol2_gregset
end_define

begin_define
define|#
directive|define
name|sparc_sol2_fpregset
value|sparc64_sol2_fpregset
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sparc_supply_gregset
value|sparc32_supply_gregset
end_define

begin_define
define|#
directive|define
name|sparc_supply_fpregset
value|sparc32_supply_fpregset
end_define

begin_define
define|#
directive|define
name|sparc_collect_gregset
value|sparc32_collect_gregset
end_define

begin_define
define|#
directive|define
name|sparc_collect_fpregset
value|sparc32_collect_fpregset
end_define

begin_define
define|#
directive|define
name|sparc_sol2_gregset
value|sparc32_sol2_gregset
end_define

begin_define
define|#
directive|define
name|sparc_sol2_fpregset
value|sparc32_sol2_fpregset
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|supply_gregset
parameter_list|(
name|prgregset_t
modifier|*
name|gregs
parameter_list|)
block|{
name|sparc_supply_gregset
argument_list|(
operator|&
name|sparc_sol2_gregset
argument_list|,
name|current_regcache
argument_list|,
operator|-
literal|1
argument_list|,
name|gregs
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|supply_fpregset
parameter_list|(
name|prfpregset_t
modifier|*
name|fpregs
parameter_list|)
block|{
name|sparc_supply_fpregset
argument_list|(
name|current_regcache
argument_list|,
operator|-
literal|1
argument_list|,
name|fpregs
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fill_gregset
parameter_list|(
name|prgregset_t
modifier|*
name|gregs
parameter_list|,
name|int
name|regnum
parameter_list|)
block|{
name|sparc_collect_gregset
argument_list|(
operator|&
name|sparc_sol2_gregset
argument_list|,
name|current_regcache
argument_list|,
name|regnum
argument_list|,
name|gregs
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fill_fpregset
parameter_list|(
name|prfpregset_t
modifier|*
name|fpregs
parameter_list|,
name|int
name|regnum
parameter_list|)
block|{
name|sparc_collect_fpregset
argument_list|(
name|current_regcache
argument_list|,
name|regnum
argument_list|,
name|fpregs
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

