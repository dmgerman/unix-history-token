begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vmmeter.h	8.2 (Berkeley) 7/10/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VMMETER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VMMETER_H_
end_define

begin_comment
comment|/*  * System wide statistics counters.  */
end_comment

begin_struct
struct|struct
name|vmmeter
block|{
comment|/* 	 * General system activity. 	 */
name|u_int
name|v_swtch
decl_stmt|;
comment|/* context switches */
name|u_int
name|v_trap
decl_stmt|;
comment|/* calls to trap */
name|u_int
name|v_syscall
decl_stmt|;
comment|/* calls to syscall() */
name|u_int
name|v_intr
decl_stmt|;
comment|/* device interrupts */
name|u_int
name|v_soft
decl_stmt|;
comment|/* software interrupts */
comment|/* 	 * Virtual memory activity. 	 */
name|u_int
name|v_vm_faults
decl_stmt|;
comment|/* number of address memory faults */
name|u_int
name|v_cow_faults
decl_stmt|;
comment|/* number of copy-on-writes */
name|u_int
name|v_cow_optim
decl_stmt|;
comment|/* number of optimized copy-on-writes */
name|u_int
name|v_zfod
decl_stmt|;
comment|/* pages zero filled on demand */
name|u_int
name|v_ozfod
decl_stmt|;
comment|/* optimized zero fill pages */
name|u_int
name|v_swapin
decl_stmt|;
comment|/* swap pager pageins */
name|u_int
name|v_swapout
decl_stmt|;
comment|/* swap pager pageouts */
name|u_int
name|v_swappgsin
decl_stmt|;
comment|/* swap pager pages paged in */
name|u_int
name|v_swappgsout
decl_stmt|;
comment|/* swap pager pages paged out */
name|u_int
name|v_vnodein
decl_stmt|;
comment|/* vnode pager pageins */
name|u_int
name|v_vnodeout
decl_stmt|;
comment|/* vnode pager pageouts */
name|u_int
name|v_vnodepgsin
decl_stmt|;
comment|/* vnode_pager pages paged in */
name|u_int
name|v_vnodepgsout
decl_stmt|;
comment|/* vnode pager pages paged out */
name|u_int
name|v_intrans
decl_stmt|;
comment|/* intransit blocking page faults */
name|u_int
name|v_reactivated
decl_stmt|;
comment|/* number of pages reactivated from free list */
name|u_int
name|v_pdwakeups
decl_stmt|;
comment|/* number of times daemon has awaken from sleep */
name|u_int
name|v_pdpages
decl_stmt|;
comment|/* number of pages analyzed by daemon */
name|u_int
name|v_dfree
decl_stmt|;
comment|/* pages freed by daemon */
name|u_int
name|v_pfree
decl_stmt|;
comment|/* pages freed by exiting processes */
name|u_int
name|v_tfree
decl_stmt|;
comment|/* total pages freed */
comment|/* 	 * Distribution of page usages. 	 */
name|u_int
name|v_page_size
decl_stmt|;
comment|/* page size in bytes */
name|u_int
name|v_page_count
decl_stmt|;
comment|/* total number of pages in system */
name|u_int
name|v_free_reserved
decl_stmt|;
comment|/* number of pages reserved for deadlock */
name|u_int
name|v_free_target
decl_stmt|;
comment|/* number of pages desired free */
name|u_int
name|v_free_min
decl_stmt|;
comment|/* minimum number of pages desired free */
name|u_int
name|v_free_count
decl_stmt|;
comment|/* number of pages free */
name|u_int
name|v_wire_count
decl_stmt|;
comment|/* number of pages wired down */
name|u_int
name|v_active_count
decl_stmt|;
comment|/* number of pages active */
name|u_int
name|v_inactive_target
decl_stmt|;
comment|/* number of pages desired inactive */
name|u_int
name|v_inactive_count
decl_stmt|;
comment|/* number of pages inactive */
name|u_int
name|v_cache_count
decl_stmt|;
comment|/* number of pages on buffer cache queue */
name|u_int
name|v_cache_min
decl_stmt|;
comment|/* min number of pages desired on cache queue */
name|u_int
name|v_cache_max
decl_stmt|;
comment|/* max number of pages in cached obj */
name|u_int
name|v_pageout_free_min
decl_stmt|;
comment|/* min number pages reserved for kernel */
name|u_int
name|v_interrupt_free_min
decl_stmt|;
comment|/* reserved number of pages for int code */
name|u_int
name|v_free_severe
decl_stmt|;
comment|/* severe depletion of pages below this pt */
comment|/* 	 * Fork/vfork/rfork activity. 	 */
name|u_int
name|v_forks
decl_stmt|;
comment|/* number of fork() calls */
name|u_int
name|v_vforks
decl_stmt|;
comment|/* number of vfork() calls */
name|u_int
name|v_rforks
decl_stmt|;
comment|/* number of rfork() calls */
name|u_int
name|v_kthreads
decl_stmt|;
comment|/* number of fork() calls by kernel */
name|u_int
name|v_forkpages
decl_stmt|;
comment|/* number of VM pages affected by fork() */
name|u_int
name|v_vforkpages
decl_stmt|;
comment|/* number of VM pages affected by vfork() */
name|u_int
name|v_rforkpages
decl_stmt|;
comment|/* number of VM pages affected by rfork() */
name|u_int
name|v_kthreadpages
decl_stmt|;
comment|/* number of VM pages affected by fork() by kernel */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vmmeter
name|cnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return TRUE if we are under our reserved low-free-pages threshold  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vm_page_count_reserved
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|cnt
operator|.
name|v_free_reserved
operator|>
operator|(
name|cnt
operator|.
name|v_free_count
operator|+
name|cnt
operator|.
name|v_cache_count
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return TRUE if we are under our severe low-free-pages threshold  *  * This routine is typically used at the user<->system interface to determine  * whether we need to block in order to avoid a low memory deadlock.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vm_page_count_severe
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|cnt
operator|.
name|v_free_severe
operator|>
operator|(
name|cnt
operator|.
name|v_free_count
operator|+
name|cnt
operator|.
name|v_cache_count
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return TRUE if we are under our minimum low-free-pages threshold.  *  * This routine is typically used within the system to determine whether  * we can execute potentially very expensive code in terms of memory.  It  * is also used by the pageout daemon to calculate when to sleep, when  * to wake waiters up, and when (after making a pass) to become more  * desparate.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vm_page_count_min
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|cnt
operator|.
name|v_free_min
operator|>
operator|(
name|cnt
operator|.
name|v_free_count
operator|+
name|cnt
operator|.
name|v_cache_count
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return TRUE if we have not reached our free page target during  * free page recovery operations.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vm_page_count_target
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|cnt
operator|.
name|v_free_target
operator|>
operator|(
name|cnt
operator|.
name|v_free_count
operator|+
name|cnt
operator|.
name|v_cache_count
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return the number of pages we need to free-up or cache  * A positive number indicates that we do not have enough free pages.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vm_paging_target
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|cnt
operator|.
name|v_free_target
operator|+
name|cnt
operator|.
name|v_cache_min
operator|)
operator|-
operator|(
name|cnt
operator|.
name|v_free_count
operator|+
name|cnt
operator|.
name|v_cache_count
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Returns TRUE if the pagedaemon needs to be woken up.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vm_paging_needed
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|cnt
operator|.
name|v_free_reserved
operator|+
name|cnt
operator|.
name|v_cache_min
operator|)
operator|>
operator|(
name|cnt
operator|.
name|v_free_count
operator|+
name|cnt
operator|.
name|v_cache_count
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* systemwide totals computed every five seconds */
end_comment

begin_struct
struct|struct
name|vmtotal
block|{
name|int16_t
name|t_rq
decl_stmt|;
comment|/* length of the run queue */
name|int16_t
name|t_dw
decl_stmt|;
comment|/* jobs in ``disk wait'' (neg priority) */
name|int16_t
name|t_pw
decl_stmt|;
comment|/* jobs in page wait */
name|int16_t
name|t_sl
decl_stmt|;
comment|/* jobs sleeping in core */
name|int16_t
name|t_sw
decl_stmt|;
comment|/* swapped out runnable/short block jobs */
name|int32_t
name|t_vm
decl_stmt|;
comment|/* total virtual memory */
name|int32_t
name|t_avm
decl_stmt|;
comment|/* active virtual memory */
name|int32_t
name|t_rm
decl_stmt|;
comment|/* total real memory in use */
name|int32_t
name|t_arm
decl_stmt|;
comment|/* active real memory */
name|int32_t
name|t_vmshr
decl_stmt|;
comment|/* shared virtual memory */
name|int32_t
name|t_avmshr
decl_stmt|;
comment|/* active shared virtual memory */
name|int32_t
name|t_rmshr
decl_stmt|;
comment|/* shared real memory */
name|int32_t
name|t_armshr
decl_stmt|;
comment|/* active shared real memory */
name|int32_t
name|t_free
decl_stmt|;
comment|/* free memory pages */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

