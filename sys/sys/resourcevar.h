begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)resourcevar.h	7.1 (Berkeley) 5/9/91  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RESOURCEVAR_H_
end_ifndef

begin_comment
comment|/* tmp for user.h */
end_comment

begin_define
define|#
directive|define
name|_RESOURCEVAR_H_
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
name|short
modifier|*
name|pr_base
decl_stmt|;
comment|/* buffer base */
name|unsigned
name|pr_size
decl_stmt|;
comment|/* buffer size */
name|unsigned
name|pr_off
decl_stmt|;
comment|/* pc offset */
name|unsigned
name|pr_scale
decl_stmt|;
comment|/* pc scaling */
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

begin_function_decl
name|void
name|addupc
parameter_list|(
name|int
parameter_list|,
name|struct
name|uprof
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* process profiling */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RESOURCEVAR_H_ */
end_comment

end_unit

