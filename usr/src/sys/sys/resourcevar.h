begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)resourcevar.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RESOURCEVAR_H_
end_ifndef

begin_comment
comment|/* tmp for user.h */
end_comment

begin_define
define|#
directive|define
name|_SYS_RESOURCEVAR_H_
end_define

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
name|int
name|p_lflags
decl_stmt|;
comment|/* below */
name|int
name|p_refcnt
decl_stmt|;
comment|/* number of references */
block|}
struct|;
end_struct

begin_comment
comment|/* pl_lflags: */
end_comment

begin_define
define|#
directive|define
name|PL_SHAREMOD
value|0x01
end_define

begin_comment
comment|/* modifications are shared */
end_comment

begin_comment
comment|/* make copy of plimit structure */
end_comment

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

begin_comment
comment|/* add profiling ticks: in interrupt context, and from AST */
end_comment

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

begin_comment
comment|/* add user profiling from AST */
end_comment

begin_define
define|#
directive|define
name|ADDUPROF
parameter_list|(
name|p
parameter_list|)
value|addupc_task(p, (p)->p_stats->p_prof.pr_addr, \ 			    (p)->p_stats->p_prof.pr_ticks)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_RESOURCEVAR_H_ */
end_comment

end_unit

