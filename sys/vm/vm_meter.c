begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vm_meter.c	8.4 (Berkeley) 1/4/94  */
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
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_decl_stmt
name|struct
name|vmmeter
name|vm_cnt
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_vm
argument_list|,
name|VM_V_FREE_MIN
argument_list|,
name|v_free_min
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|vm_cnt
operator|.
name|v_free_min
argument_list|,
literal|0
argument_list|,
literal|"Minimum low-free-pages threshold"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_vm
argument_list|,
name|VM_V_FREE_TARGET
argument_list|,
name|v_free_target
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|vm_cnt
operator|.
name|v_free_target
argument_list|,
literal|0
argument_list|,
literal|"Desired free pages"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_vm
argument_list|,
name|VM_V_FREE_RESERVED
argument_list|,
name|v_free_reserved
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|vm_cnt
operator|.
name|v_free_reserved
argument_list|,
literal|0
argument_list|,
literal|"Pages reserved for deadlock"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_vm
argument_list|,
name|VM_V_INACTIVE_TARGET
argument_list|,
name|v_inactive_target
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|vm_cnt
operator|.
name|v_inactive_target
argument_list|,
literal|0
argument_list|,
literal|"Pages desired inactive"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_vm
argument_list|,
name|VM_V_PAGEOUT_FREE_MIN
argument_list|,
name|v_pageout_free_min
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|vm_cnt
operator|.
name|v_pageout_free_min
argument_list|,
literal|0
argument_list|,
literal|"Min pages reserved for kernel"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_vm
argument_list|,
name|OID_AUTO
argument_list|,
name|v_free_severe
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|vm_cnt
operator|.
name|v_free_severe
argument_list|,
literal|0
argument_list|,
literal|"Severe page depletion point"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|sysctl_vm_loadavg
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SCTL_MASK32
name|u_int32_t
name|la
index|[
literal|4
index|]
decl_stmt|;
if|if
condition|(
name|req
operator|->
name|flags
operator|&
name|SCTL_MASK32
condition|)
block|{
name|la
index|[
literal|0
index|]
operator|=
name|averunnable
operator|.
name|ldavg
index|[
literal|0
index|]
expr_stmt|;
name|la
index|[
literal|1
index|]
operator|=
name|averunnable
operator|.
name|ldavg
index|[
literal|1
index|]
expr_stmt|;
name|la
index|[
literal|2
index|]
operator|=
name|averunnable
operator|.
name|ldavg
index|[
literal|2
index|]
expr_stmt|;
name|la
index|[
literal|3
index|]
operator|=
name|averunnable
operator|.
name|fscale
expr_stmt|;
return|return
name|SYSCTL_OUT
argument_list|(
name|req
argument_list|,
name|la
argument_list|,
sizeof|sizeof
argument_list|(
name|la
argument_list|)
argument_list|)
return|;
block|}
else|else
endif|#
directive|endif
return|return
name|SYSCTL_OUT
argument_list|(
name|req
argument_list|,
operator|&
name|averunnable
argument_list|,
sizeof|sizeof
argument_list|(
name|averunnable
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_vm
argument_list|,
name|VM_LOADAVG
argument_list|,
name|loadavg
argument_list|,
name|CTLTYPE_STRUCT
operator||
name|CTLFLAG_RD
operator||
name|CTLFLAG_MPSAFE
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|sysctl_vm_loadavg
argument_list|,
literal|"S,loadavg"
argument_list|,
literal|"Machine loadaverage history"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This function aims to determine if the object is mapped,  * specifically, if it is referenced by a vm_map_entry.  Because  * objects occasionally acquire transient references that do not  * represent a mapping, the method used here is inexact.  However, it  * has very low overhead and is good enough for the advisory  * vm.vmtotal sysctl.  */
end_comment

begin_function
specifier|static
name|bool
name|is_object_active
parameter_list|(
name|vm_object_t
name|obj
parameter_list|)
block|{
return|return
operator|(
name|obj
operator|->
name|ref_count
operator|>
name|obj
operator|->
name|shadow_count
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|vmtotal
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|struct
name|vmtotal
name|total
decl_stmt|;
name|vm_object_t
name|object
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|bzero
argument_list|(
operator|&
name|total
argument_list|,
sizeof|sizeof
argument_list|(
name|total
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Calculate process statistics. 	 */
name|sx_slock
argument_list|(
operator|&
name|allproc_lock
argument_list|)
expr_stmt|;
name|FOREACH_PROC_IN_SYSTEM
argument_list|(
argument|p
argument_list|)
block|{
if|if
condition|(
operator|(
name|p
operator|->
name|p_flag
operator|&
name|P_SYSTEM
operator|)
operator|!=
literal|0
condition|)
continue|continue;
name|PROC_LOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|p_state
operator|!=
name|PRS_NEW
condition|)
block|{
name|FOREACH_THREAD_IN_PROC
argument_list|(
argument|p
argument_list|,
argument|td
argument_list|)
block|{
name|thread_lock
argument_list|(
name|td
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|td
operator|->
name|td_state
condition|)
block|{
case|case
name|TDS_INHIBITED
case|:
if|if
condition|(
name|TD_IS_SWAPPED
argument_list|(
name|td
argument_list|)
condition|)
name|total
operator|.
name|t_sw
operator|++
expr_stmt|;
elseif|else
if|if
condition|(
name|TD_IS_SLEEPING
argument_list|(
name|td
argument_list|)
condition|)
block|{
if|if
condition|(
name|td
operator|->
name|td_priority
operator|<=
name|PZERO
condition|)
name|total
operator|.
name|t_dw
operator|++
expr_stmt|;
else|else
name|total
operator|.
name|t_sl
operator|++
expr_stmt|;
if|if
condition|(
name|td
operator|->
name|td_wchan
operator|==
operator|&
name|vm_cnt
operator|.
name|v_free_count
condition|)
name|total
operator|.
name|t_pw
operator|++
expr_stmt|;
block|}
break|break;
case|case
name|TDS_CAN_RUN
case|:
name|total
operator|.
name|t_sw
operator|++
expr_stmt|;
break|break;
case|case
name|TDS_RUNQ
case|:
case|case
name|TDS_RUNNING
case|:
name|total
operator|.
name|t_rq
operator|++
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|thread_unlock
argument_list|(
name|td
argument_list|)
expr_stmt|;
block|}
block|}
name|PROC_UNLOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
name|sx_sunlock
argument_list|(
operator|&
name|allproc_lock
argument_list|)
expr_stmt|;
comment|/* 	 * Calculate object memory usage statistics. 	 */
name|mtx_lock
argument_list|(
operator|&
name|vm_object_list_mtx
argument_list|)
expr_stmt|;
name|TAILQ_FOREACH
argument_list|(
argument|object
argument_list|,
argument|&vm_object_list
argument_list|,
argument|object_list
argument_list|)
block|{
comment|/* 		 * Perform unsynchronized reads on the object.  In 		 * this case, the lack of synchronization should not 		 * impair the accuracy of the reported statistics. 		 */
if|if
condition|(
operator|(
name|object
operator|->
name|flags
operator|&
name|OBJ_FICTITIOUS
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* 			 * Devices, like /dev/mem, will badly skew our totals. 			 */
continue|continue;
block|}
if|if
condition|(
name|object
operator|->
name|ref_count
operator|==
literal|0
condition|)
block|{
comment|/* 			 * Also skip unreferenced objects, including 			 * vnodes representing mounted file systems. 			 */
continue|continue;
block|}
if|if
condition|(
name|object
operator|->
name|ref_count
operator|==
literal|1
operator|&&
operator|(
name|object
operator|->
name|flags
operator|&
name|OBJ_NOSPLIT
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* 			 * Also skip otherwise unreferenced swap 			 * objects backing tmpfs vnodes, and POSIX or 			 * SysV shared memory. 			 */
continue|continue;
block|}
name|total
operator|.
name|t_vm
operator|+=
name|object
operator|->
name|size
expr_stmt|;
name|total
operator|.
name|t_rm
operator|+=
name|object
operator|->
name|resident_page_count
expr_stmt|;
if|if
condition|(
name|is_object_active
argument_list|(
name|object
argument_list|)
condition|)
block|{
name|total
operator|.
name|t_avm
operator|+=
name|object
operator|->
name|size
expr_stmt|;
name|total
operator|.
name|t_arm
operator|+=
name|object
operator|->
name|resident_page_count
expr_stmt|;
block|}
if|if
condition|(
name|object
operator|->
name|shadow_count
operator|>
literal|1
condition|)
block|{
comment|/* shared object */
name|total
operator|.
name|t_vmshr
operator|+=
name|object
operator|->
name|size
expr_stmt|;
name|total
operator|.
name|t_rmshr
operator|+=
name|object
operator|->
name|resident_page_count
expr_stmt|;
if|if
condition|(
name|is_object_active
argument_list|(
name|object
argument_list|)
condition|)
block|{
name|total
operator|.
name|t_avmshr
operator|+=
name|object
operator|->
name|size
expr_stmt|;
name|total
operator|.
name|t_armshr
operator|+=
name|object
operator|->
name|resident_page_count
expr_stmt|;
block|}
block|}
block|}
name|mtx_unlock
argument_list|(
operator|&
name|vm_object_list_mtx
argument_list|)
expr_stmt|;
name|total
operator|.
name|t_free
operator|=
name|vm_cnt
operator|.
name|v_free_count
expr_stmt|;
return|return
operator|(
name|sysctl_handle_opaque
argument_list|(
name|oidp
argument_list|,
operator|&
name|total
argument_list|,
sizeof|sizeof
argument_list|(
name|total
argument_list|)
argument_list|,
name|req
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * vm_meter_cnt() -	accumulate statistics from all cpus and the global cnt  *			structure.  *  *	The vmmeter structure is now per-cpu as well as global.  Those  *	statistics which can be kept on a per-cpu basis (to avoid cache  *	stalls between cpus) can be moved to the per-cpu vmmeter.  Remaining  *	statistics, such as v_free_reserved, are left in the global  *	structure.  */
end_comment

begin_function
name|u_int
name|vm_meter_cnt
parameter_list|(
name|size_t
name|offset
parameter_list|)
block|{
name|struct
name|pcpu
modifier|*
name|pcpu
decl_stmt|;
name|u_int
name|count
decl_stmt|;
name|int
name|i
decl_stmt|;
name|count
operator|=
operator|*
operator|(
name|u_int
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
name|vm_cnt
operator|+
name|offset
operator|)
expr_stmt|;
name|CPU_FOREACH
argument_list|(
argument|i
argument_list|)
block|{
name|pcpu
operator|=
name|pcpu_find
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|count
operator|+=
operator|*
operator|(
name|u_int
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
name|pcpu
operator|->
name|pc_cnt
operator|+
name|offset
operator|)
expr_stmt|;
block|}
return|return
operator|(
name|count
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|cnt_sysctl
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|u_int
name|count
decl_stmt|;
name|count
operator|=
name|vm_meter_cnt
argument_list|(
operator|(
name|char
operator|*
operator|)
name|arg1
operator|-
operator|(
name|char
operator|*
operator|)
operator|&
name|vm_cnt
argument_list|)
expr_stmt|;
return|return
operator|(
name|SYSCTL_OUT
argument_list|(
name|req
argument_list|,
operator|&
name|count
argument_list|,
sizeof|sizeof
argument_list|(
name|count
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_vm
argument_list|,
name|VM_TOTAL
argument_list|,
name|vmtotal
argument_list|,
name|CTLTYPE_OPAQUE
operator||
name|CTLFLAG_RD
operator||
name|CTLFLAG_MPSAFE
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|vmtotal
argument_list|)
argument_list|,
name|vmtotal
argument_list|,
literal|"S,vmtotal"
argument_list|,
literal|"System virtual memory statistics"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_vm
argument_list|,
name|OID_AUTO
argument_list|,
name|stats
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"VM meter stats"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|SYSCTL_NODE
argument_list|(
name|_vm_stats
argument_list|,
name|OID_AUTO
argument_list|,
name|sys
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"VM meter sys stats"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|SYSCTL_NODE
argument_list|(
name|_vm_stats
argument_list|,
name|OID_AUTO
argument_list|,
name|vm
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"VM meter vm stats"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_vm_stats
argument_list|,
name|OID_AUTO
argument_list|,
name|misc
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"VM meter misc stats"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VM_STATS
parameter_list|(
name|parent
parameter_list|,
name|var
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_PROC(parent, OID_AUTO, var, \ 	    CTLTYPE_UINT | CTLFLAG_RD | CTLFLAG_MPSAFE,&vm_cnt.var, 0,	\ 	    cnt_sysctl, "IU", descr)
end_define

begin_define
define|#
directive|define
name|VM_STATS_VM
parameter_list|(
name|var
parameter_list|,
name|descr
parameter_list|)
value|VM_STATS(_vm_stats_vm, var, descr)
end_define

begin_define
define|#
directive|define
name|VM_STATS_SYS
parameter_list|(
name|var
parameter_list|,
name|descr
parameter_list|)
value|VM_STATS(_vm_stats_sys, var, descr)
end_define

begin_expr_stmt
name|VM_STATS_SYS
argument_list|(
name|v_swtch
argument_list|,
literal|"Context switches"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_SYS
argument_list|(
name|v_trap
argument_list|,
literal|"Traps"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_SYS
argument_list|(
name|v_syscall
argument_list|,
literal|"System calls"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_SYS
argument_list|(
name|v_intr
argument_list|,
literal|"Device interrupts"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_SYS
argument_list|(
name|v_soft
argument_list|,
literal|"Software interrupts"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_vm_faults
argument_list|,
literal|"Address memory faults"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_io_faults
argument_list|,
literal|"Page faults requiring I/O"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_cow_faults
argument_list|,
literal|"Copy-on-write faults"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_cow_optim
argument_list|,
literal|"Optimized COW faults"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_zfod
argument_list|,
literal|"Pages zero-filled on demand"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_ozfod
argument_list|,
literal|"Optimized zero fill pages"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_swapin
argument_list|,
literal|"Swap pager pageins"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_swapout
argument_list|,
literal|"Swap pager pageouts"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_swappgsin
argument_list|,
literal|"Swap pages swapped in"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_swappgsout
argument_list|,
literal|"Swap pages swapped out"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_vnodein
argument_list|,
literal|"Vnode pager pageins"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_vnodeout
argument_list|,
literal|"Vnode pager pageouts"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_vnodepgsin
argument_list|,
literal|"Vnode pages paged in"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_vnodepgsout
argument_list|,
literal|"Vnode pages paged out"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_intrans
argument_list|,
literal|"In transit page faults"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_reactivated
argument_list|,
literal|"Pages reactivated by pagedaemon"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_pdwakeups
argument_list|,
literal|"Pagedaemon wakeups"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_pdpages
argument_list|,
literal|"Pages analyzed by pagedaemon"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_pdshortfalls
argument_list|,
literal|"Page reclamation shortfalls"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_tcached
argument_list|,
literal|"Total pages cached"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_dfree
argument_list|,
literal|"Pages freed by pagedaemon"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_pfree
argument_list|,
literal|"Pages freed by exiting processes"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_tfree
argument_list|,
literal|"Total pages freed"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_page_size
argument_list|,
literal|"Page size in bytes"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_page_count
argument_list|,
literal|"Total number of pages in system"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_free_reserved
argument_list|,
literal|"Pages reserved for deadlock"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_free_target
argument_list|,
literal|"Pages desired free"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_free_min
argument_list|,
literal|"Minimum low-free-pages threshold"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_free_count
argument_list|,
literal|"Free pages"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_wire_count
argument_list|,
literal|"Wired pages"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_active_count
argument_list|,
literal|"Active pages"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_inactive_target
argument_list|,
literal|"Desired inactive pages"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_inactive_count
argument_list|,
literal|"Inactive pages"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_laundry_count
argument_list|,
literal|"Pages eligible for laundering"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_cache_count
argument_list|,
literal|"Pages on cache queue"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_pageout_free_min
argument_list|,
literal|"Min pages reserved for kernel"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_interrupt_free_min
argument_list|,
literal|"Reserved pages for interrupt code"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_forks
argument_list|,
literal|"Number of fork() calls"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_vforks
argument_list|,
literal|"Number of vfork() calls"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_rforks
argument_list|,
literal|"Number of rfork() calls"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_kthreads
argument_list|,
literal|"Number of fork() calls by kernel"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_forkpages
argument_list|,
literal|"VM pages affected by fork()"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_vforkpages
argument_list|,
literal|"VM pages affected by vfork()"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_rforkpages
argument_list|,
literal|"VM pages affected by rfork()"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VM_STATS_VM
argument_list|(
name|v_kthreadpages
argument_list|,
literal|"VM pages affected by fork() by kernel"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_vm_stats_misc
argument_list|,
name|OID_AUTO
argument_list|,
name|zero_page_count
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|vm_page_zero_count
argument_list|,
literal|0
argument_list|,
literal|"Number of zero-ed free pages"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

