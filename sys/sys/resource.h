begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)resource.h	8.4 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RESOURCE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RESOURCE_H_
end_define

begin_comment
comment|/*  * Process priority specifications to get/setpriority.  */
end_comment

begin_define
define|#
directive|define
name|PRIO_MIN
value|-20
end_define

begin_define
define|#
directive|define
name|PRIO_MAX
value|20
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|PRIO_TOTAL
value|(PRIO_MAX - PRIO_MIN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|PRIO_PROCESS
value|0
end_define

begin_define
define|#
directive|define
name|PRIO_PGRP
value|1
end_define

begin_define
define|#
directive|define
name|PRIO_USER
value|2
end_define

begin_comment
comment|/*  * Resource utilization information.  */
end_comment

begin_define
define|#
directive|define
name|RUSAGE_SELF
value|0
end_define

begin_define
define|#
directive|define
name|RUSAGE_CHILDREN
value|-1
end_define

begin_struct
struct|struct
name|rusage
block|{
name|struct
name|timeval
name|ru_utime
decl_stmt|;
comment|/* user time used */
name|struct
name|timeval
name|ru_stime
decl_stmt|;
comment|/* system time used */
name|long
name|ru_maxrss
decl_stmt|;
comment|/* max resident set size */
define|#
directive|define
name|ru_first
value|ru_ixrss
name|long
name|ru_ixrss
decl_stmt|;
comment|/* integral shared memory size */
name|long
name|ru_idrss
decl_stmt|;
comment|/* integral unshared data " */
name|long
name|ru_isrss
decl_stmt|;
comment|/* integral unshared stack " */
name|long
name|ru_minflt
decl_stmt|;
comment|/* page reclaims */
name|long
name|ru_majflt
decl_stmt|;
comment|/* page faults */
name|long
name|ru_nswap
decl_stmt|;
comment|/* swaps */
name|long
name|ru_inblock
decl_stmt|;
comment|/* block input operations */
name|long
name|ru_oublock
decl_stmt|;
comment|/* block output operations */
name|long
name|ru_msgsnd
decl_stmt|;
comment|/* messages sent */
name|long
name|ru_msgrcv
decl_stmt|;
comment|/* messages received */
name|long
name|ru_nsignals
decl_stmt|;
comment|/* signals received */
name|long
name|ru_nvcsw
decl_stmt|;
comment|/* voluntary context switches */
name|long
name|ru_nivcsw
decl_stmt|;
comment|/* involuntary " */
define|#
directive|define
name|ru_last
value|ru_nivcsw
block|}
struct|;
end_struct

begin_comment
comment|/*  * Resource limits  */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_CPU
value|0
end_define

begin_comment
comment|/* cpu time in milliseconds */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_FSIZE
value|1
end_define

begin_comment
comment|/* maximum file size */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_DATA
value|2
end_define

begin_comment
comment|/* data size */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_STACK
value|3
end_define

begin_comment
comment|/* stack size */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_CORE
value|4
end_define

begin_comment
comment|/* core file size */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_RSS
value|5
end_define

begin_comment
comment|/* resident set size */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_MEMLOCK
value|6
end_define

begin_comment
comment|/* locked-in-memory address space */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_NPROC
value|7
end_define

begin_comment
comment|/* number of processes */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_NOFILE
value|8
end_define

begin_comment
comment|/* number of open files */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_SBSIZE
value|9
end_define

begin_comment
comment|/* maximum size of all socket buffers */
end_comment

begin_define
define|#
directive|define
name|RLIM_NLIMITS
value|10
end_define

begin_comment
comment|/* number of resource limits */
end_comment

begin_define
define|#
directive|define
name|RLIM_INFINITY
value|((rlim_t)(((u_quad_t)1<< 63) - 1))
end_define

begin_comment
comment|/*  * Resource limit string identifiers  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_RLIMIT_IDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rlimit_ident
index|[]
init|=
block|{
literal|"cpu"
block|,
literal|"fsize"
block|,
literal|"data"
block|,
literal|"stack"
block|,
literal|"core"
block|,
literal|"rss"
block|,
literal|"memlock"
block|,
literal|"nproc"
block|,
literal|"nofile"
block|,
literal|"sbsize"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|orlimit
block|{
name|int32_t
name|rlim_cur
decl_stmt|;
comment|/* current (soft) limit */
name|int32_t
name|rlim_max
decl_stmt|;
comment|/* maximum value for rlim_cur */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rlimit
block|{
name|rlim_t
name|rlim_cur
decl_stmt|;
comment|/* current (soft) limit */
name|rlim_t
name|rlim_max
decl_stmt|;
comment|/* maximum value for rlim_cur */
block|}
struct|;
end_struct

begin_comment
comment|/* Load average structure. */
end_comment

begin_struct
struct|struct
name|loadavg
block|{
name|fixpt_t
name|ldavg
index|[
literal|3
index|]
decl_stmt|;
name|long
name|fscale
decl_stmt|;
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
name|loadavg
name|averunnable
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|dosetrlimit
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|rlimit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|getpriority
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getrlimit
parameter_list|(
name|int
parameter_list|,
name|struct
name|rlimit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getrusage
parameter_list|(
name|int
parameter_list|,
name|struct
name|rusage
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpriority
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setrlimit
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|rlimit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

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
comment|/* !_SYS_RESOURCE_H_ */
end_comment

end_unit

