begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)resourcevar.h	8.4 (Berkeley) 1/9/95  * $FreeBSD$  */
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

begin_comment
comment|/*  * Kernel per-process accounting / statistics  * (not necessarily resident except when running).  */
end_comment

begin_struct
struct|struct
name|pstats
block|{
define|#
directive|define
name|pstat_startzero
value|p_ru
name|struct
name|rusage
name|p_ru
decl_stmt|;
comment|/* stats for this proc */
name|struct
name|rusage
name|p_cru
decl_stmt|;
comment|/* sum of stats for reaped children */
define|#
directive|define
name|pstat_endzero
value|pstat_startcopy
define|#
directive|define
name|pstat_startcopy
value|p_timer
name|struct
name|itimerval
name|p_timer
index|[
literal|3
index|]
decl_stmt|;
comment|/* virtual-time timers */
struct|struct
name|uprof
block|{
comment|/* profile arguments */
name|caddr_t
name|pr_base
decl_stmt|;
comment|/* buffer base */
name|u_long
name|pr_size
decl_stmt|;
comment|/* buffer size */
name|u_long
name|pr_off
decl_stmt|;
comment|/* pc offset */
name|u_long
name|pr_scale
decl_stmt|;
comment|/* pc scaling */
name|u_long
name|pr_addr
decl_stmt|;
comment|/* temp storage for addr until AST */
name|u_long
name|pr_ticks
decl_stmt|;
comment|/* temp storage for ticks until AST */
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
comment|/* starting time */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Kernel shareable process resource limits.  Because this structure  * is moderately large but changes infrequently, it is normally  * shared copy-on-write after forks.  If a group of processes  * ("threads") share modifications, the PL_SHAREMOD flag is set,  * and a copy must be made for the child of a new fork that isn't  * sharing modifications to the limits.  */
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
define|#
directive|define
name|PL_SHAREMOD
value|0x01
comment|/* modifications are shared */
name|int
name|p_lflags
decl_stmt|;
name|int
name|p_refcnt
decl_stmt|;
comment|/* number of references */
name|rlim_t
name|p_cpulimit
decl_stmt|;
comment|/* current cpu limit in usec */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per uid resource consumption  */
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
name|rlim_t
name|ui_sbsize
decl_stmt|;
comment|/* socket buffer space consumed */
name|long
name|ui_proccnt
decl_stmt|;
comment|/* number of processes */
name|uid_t
name|ui_uid
decl_stmt|;
comment|/* uid */
name|u_short
name|ui_ref
decl_stmt|;
comment|/* reference count */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|uihold
parameter_list|(
name|uip
parameter_list|)
value|(uip)->ui_ref++
end_define

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|addupc_intr
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|u_long
name|pc
operator|,
name|u_int
name|ticks
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addupc_task
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|u_long
name|pc
operator|,
name|u_int
name|ticks
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|calcru
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|timeval
operator|*
name|up
operator|,
expr|struct
name|timeval
operator|*
name|sp
operator|,
expr|struct
name|timeval
operator|*
name|ip
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chgproccnt
name|__P
argument_list|(
operator|(
expr|struct
name|uidinfo
operator|*
name|uip
operator|,
name|int
name|diff
operator|,
name|int
name|max
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chgsbsize
name|__P
argument_list|(
operator|(
expr|struct
name|uidinfo
operator|*
name|uip
operator|,
name|u_long
operator|*
name|hiwat
operator|,
name|u_long
name|to
operator|,
name|rlim_t
name|max
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fuswintr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|plimit
modifier|*
name|limcopy
name|__P
argument_list|(
operator|(
expr|struct
name|plimit
operator|*
name|lim
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ruadd
name|__P
argument_list|(
operator|(
expr|struct
name|rusage
operator|*
name|ru
operator|,
expr|struct
name|rusage
operator|*
name|ru2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suswintr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|,
name|int
name|word
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uidinfo
modifier|*
name|uifind
name|__P
argument_list|(
operator|(
name|uid_t
name|uid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uifree
name|__P
argument_list|(
operator|(
expr|struct
name|uidinfo
operator|*
name|uip
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uihashinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_RESOURCEVAR_H_ */
end_comment

end_unit

