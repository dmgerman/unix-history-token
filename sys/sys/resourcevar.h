begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)resourcevar.h	8.4 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RESOURCEVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RESOURCEVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Kernel per-process accounting / statistics  * (not necessarily resident except when running).  *  * Locking key:  *      b - created at fork, never changes  *      c - locked by proc mtx  *      j - locked by proc slock  *      k - only accessed by curthread  */
end_comment

begin_struct
struct|struct
name|pstats
block|{
define|#
directive|define
name|pstat_startzero
value|p_cru
name|struct
name|rusage
name|p_cru
decl_stmt|;
comment|/* Stats for reaped children. */
name|struct
name|itimerval
name|p_timer
index|[
literal|3
index|]
decl_stmt|;
comment|/* (j) Virtual-time timers. */
define|#
directive|define
name|pstat_endzero
value|pstat_startcopy
define|#
directive|define
name|pstat_startcopy
value|p_prof
struct|struct
name|uprof
block|{
comment|/* Profile arguments. */
name|caddr_t
name|pr_base
decl_stmt|;
comment|/* (c + j) Buffer base. */
name|u_long
name|pr_size
decl_stmt|;
comment|/* (c + j) Buffer size. */
name|u_long
name|pr_off
decl_stmt|;
comment|/* (c + j) PC offset. */
name|u_long
name|pr_scale
decl_stmt|;
comment|/* (c + j) PC scaling. */
block|}
name|p_prof
struct|;
define|#
directive|define
name|pstat_endcopy
value|p_start
name|struct
name|timeval
name|p_start
decl_stmt|;
comment|/* (b) Starting time. */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Kernel shareable process resource limits.  Because this structure  * is moderately large but changes infrequently, it is normally  * shared copy-on-write after forks.  */
end_comment

begin_struct
struct|struct
name|plimit
block|{
name|struct
name|rlimit
name|pl_rlimit
index|[
name|RLIM_NLIMITS
index|]
decl_stmt|;
name|int
name|pl_refcnt
decl_stmt|;
comment|/* number of references */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|racct
struct_decl|;
end_struct_decl

begin_comment
comment|/*-  * Per uid resource consumption.  This structure is used to track  * the total resource consumption (process count, socket buffer size,  * etc) for the uid and impose limits.  *  * Locking guide:  * (a) Constant from inception  * (b) Lockless, updated using atomics  * (c) Locked by global uihashtbl_mtx  * (d) Locked by the ui_vmsize_mtx  */
end_comment

begin_struct
struct|struct
name|uidinfo
block|{
name|LIST_ENTRY
argument_list|(
argument|uidinfo
argument_list|)
name|ui_hash
expr_stmt|;
comment|/* (c) hash chain of uidinfos */
name|struct
name|mtx
name|ui_vmsize_mtx
decl_stmt|;
name|vm_ooffset_t
name|ui_vmsize
decl_stmt|;
comment|/* (d) swap reservation by uid */
name|long
name|ui_sbsize
decl_stmt|;
comment|/* (b) socket buffer space consumed */
name|long
name|ui_proccnt
decl_stmt|;
comment|/* (b) number of processes */
name|long
name|ui_ptscnt
decl_stmt|;
comment|/* (b) number of pseudo-terminals */
name|long
name|ui_kqcnt
decl_stmt|;
comment|/* (b) number of kqueues */
name|uid_t
name|ui_uid
decl_stmt|;
comment|/* (a) uid */
name|u_int
name|ui_ref
decl_stmt|;
comment|/* (b) reference count */
name|struct
name|racct
modifier|*
name|ui_racct
decl_stmt|;
comment|/* (a) resource accounting */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UIDINFO_VMSIZE_LOCK
parameter_list|(
name|ui
parameter_list|)
value|mtx_lock(&((ui)->ui_vmsize_mtx))
end_define

begin_define
define|#
directive|define
name|UIDINFO_VMSIZE_UNLOCK
parameter_list|(
name|ui
parameter_list|)
value|mtx_unlock(&((ui)->ui_vmsize_mtx))
end_define

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rusage_ext
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|addupc_intr
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|uintfptr_t
name|pc
parameter_list|,
name|u_int
name|ticks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addupc_task
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|uintfptr_t
name|pc
parameter_list|,
name|u_int
name|ticks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|calccru
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|timeval
modifier|*
name|up
parameter_list|,
name|struct
name|timeval
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|calcru
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|timeval
modifier|*
name|up
parameter_list|,
name|struct
name|timeval
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chgkqcnt
parameter_list|(
name|struct
name|uidinfo
modifier|*
name|uip
parameter_list|,
name|int
name|diff
parameter_list|,
name|rlim_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chgproccnt
parameter_list|(
name|struct
name|uidinfo
modifier|*
name|uip
parameter_list|,
name|int
name|diff
parameter_list|,
name|rlim_t
name|maxval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chgsbsize
parameter_list|(
name|struct
name|uidinfo
modifier|*
name|uip
parameter_list|,
name|u_int
modifier|*
name|hiwat
parameter_list|,
name|u_int
name|to
parameter_list|,
name|rlim_t
name|maxval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chgptscnt
parameter_list|(
name|struct
name|uidinfo
modifier|*
name|uip
parameter_list|,
name|int
name|diff
parameter_list|,
name|rlim_t
name|maxval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fuswintr
parameter_list|(
name|void
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kern_proc_setrlimit
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|u_int
name|which
parameter_list|,
name|struct
name|rlimit
modifier|*
name|limp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|plimit
modifier|*
name|lim_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lim_copy
parameter_list|(
name|struct
name|plimit
modifier|*
name|dst
parameter_list|,
name|struct
name|plimit
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rlim_t
name|lim_cur
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lim_fork
parameter_list|(
name|struct
name|proc
modifier|*
name|p1
parameter_list|,
name|struct
name|proc
modifier|*
name|p2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lim_free
parameter_list|(
name|struct
name|plimit
modifier|*
name|limp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|plimit
modifier|*
name|lim_hold
parameter_list|(
name|struct
name|plimit
modifier|*
name|limp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rlim_t
name|lim_max
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lim_rlimit
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|which
parameter_list|,
name|struct
name|rlimit
modifier|*
name|rlp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ruadd
parameter_list|(
name|struct
name|rusage
modifier|*
name|ru
parameter_list|,
name|struct
name|rusage_ext
modifier|*
name|rux
parameter_list|,
name|struct
name|rusage
modifier|*
name|ru2
parameter_list|,
name|struct
name|rusage_ext
modifier|*
name|rux2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rucollect
parameter_list|(
name|struct
name|rusage
modifier|*
name|ru
parameter_list|,
name|struct
name|rusage
modifier|*
name|ru2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rufetch
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|rusage
modifier|*
name|ru
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rufetchcalc
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|rusage
modifier|*
name|ru
parameter_list|,
name|struct
name|timeval
modifier|*
name|up
parameter_list|,
name|struct
name|timeval
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rufetchtd
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|rusage
modifier|*
name|ru
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ruxagg
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|suswintr
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|int
name|word
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|uidinfo
modifier|*
name|uifind
parameter_list|(
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uifree
parameter_list|(
name|struct
name|uidinfo
modifier|*
name|uip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uihashinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uihold
parameter_list|(
name|struct
name|uidinfo
modifier|*
name|uip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ui_racct_foreach
parameter_list|(
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|racct
modifier|*
name|racct
parameter_list|,
name|void
modifier|*
name|arg2
parameter_list|,
name|void
modifier|*
name|arg3
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg2
parameter_list|,
name|void
modifier|*
name|arg3
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_RESOURCEVAR_H_ */
end_comment

end_unit

