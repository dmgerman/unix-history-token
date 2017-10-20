begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  * Copyright (c) 1994 John S. Dyson  * All rights reserved.  * Copyright (c) 1994 David Greenman  * All rights reserved.  * Copyright (c) 2005 Yahoo! Technologies Norway AS  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vm_pageout.c	7.4 (Berkeley) 5/7/91  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Avadis Tevanian, Jr., Michael Wayne Young  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_pageout.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|vm_swap_enabled
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_vm
argument_list|,
name|VM_SWAPPING_ENABLED
argument_list|,
name|swap_enabled
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|vm_swap_enabled
argument_list|,
literal|0
argument_list|,
literal|"Enable entire process swapout"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|vm_swap_idle_enabled
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_vm
argument_list|,
name|OID_AUTO
argument_list|,
name|swap_idle_enabled
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|vm_swap_idle_enabled
argument_list|,
literal|0
argument_list|,
literal|"Allow swapout on idle criteria"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|vm_swapout_run
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|vm_swapout_run_idle
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|faultin
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
block|{
name|PROC_LOCK_ASSERT
argument_list|(
name|p
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|->
name|p_flag
operator|&
name|P_INMEM
operator|)
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"faultin: proc %p swapped out with NO_SWAPPING"
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|swapper
parameter_list|(
name|void
parameter_list|)
block|{
for|for
control|(
init|;
condition|;
control|)
name|tsleep
argument_list|(
operator|&
name|proc0
argument_list|,
name|PVM
argument_list|,
literal|"swapin"
argument_list|,
name|MAXSLP
operator|*
name|hz
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

