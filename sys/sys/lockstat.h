begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2009 Stacey Son<sson@FreeBSD.org>   *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * DTrace lockstat provider definitions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LOCKSTAT_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LOCKSTAT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/sdt.h>
end_include

begin_expr_stmt
name|SDT_PROVIDER_DECLARE
argument_list|(
name|lockstat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|adaptive__acquire
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|adaptive__release
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|adaptive__spin
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|adaptive__block
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|spin__acquire
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|spin__release
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|spin__spin
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__acquire
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__release
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__block
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__spin
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__upgrade
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|rw__downgrade
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__acquire
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__release
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__block
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__spin
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__upgrade
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|sx__downgrade
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|lockstat
argument_list|, , ,
name|thread__spin
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|LOCKSTAT_WRITER
value|0
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_READER
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|lockstat_enabled
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KDTRACE_HOOKS
end_ifdef

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD0
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|)
define|\
value|SDT_PROBE1(lockstat, , , probe, lp)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD1
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|)
define|\
value|SDT_PROBE2(lockstat, , , probe, lp, arg1)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD2
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|SDT_PROBE3(lockstat, , , probe, lp, arg1, arg2)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD3
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|SDT_PROBE4(lockstat, , , probe, lp, arg1, arg2, arg3)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD4
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|SDT_PROBE5(lockstat, , , probe, lp, arg1, arg2, arg3, arg4)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_OBTAIN_LOCK_SUCCESS
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|c
parameter_list|,
name|wt
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
value|do { \ 	lock_profile_obtain_lock_success(&(lp)->lock_object, c, wt, f, l); \ 	LOCKSTAT_RECORD0(probe, lp);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_OBTAIN_RWLOCK_SUCCESS
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|c
parameter_list|,
name|wt
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|,
name|a
parameter_list|)
value|do { \ 	lock_profile_obtain_lock_success(&(lp)->lock_object, c, wt, f, l); \ 	LOCKSTAT_RECORD1(probe, lp, a);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_RELEASE_LOCK
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|)
value|do {			\ 	lock_profile_release_lock(&(lp)->lock_object);			\ 	LOCKSTAT_RECORD0(probe, lp);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_RELEASE_RWLOCK
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|a
parameter_list|)
value|do {		\ 	lock_profile_release_lock(&(lp)->lock_object);			\ 	LOCKSTAT_RECORD1(probe, lp, a);					\ } while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_PROFILING
end_ifndef

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_ENABLED
parameter_list|(
name|probe
parameter_list|)
value|__predict_false(lockstat_enabled)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_OOL_PROFILE_ENABLED
parameter_list|(
name|probe
parameter_list|)
value|LOCKSTAT_PROFILE_ENABLED(probe)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCKSTAT_OOL_PROFILE_ENABLED
parameter_list|(
name|probe
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|lock_object
struct_decl|;
end_struct_decl

begin_function_decl
name|uint64_t
name|lockstat_nsecs
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KDTRACE_HOOKS */
end_comment

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD0
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD1
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD2
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD3
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_RECORD4
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_OBTAIN_LOCK_SUCCESS
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|c
parameter_list|,
name|wt
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|lock_profile_obtain_lock_success(&(lp)->lock_object, c, wt, f, l)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_OBTAIN_RWLOCK_SUCCESS
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|c
parameter_list|,
name|wt
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|,
name|a
parameter_list|)
define|\
value|LOCKSTAT_PROFILE_OBTAIN_LOCK_SUCCESS(probe, lp, c, wt, f, l)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_RELEASE_LOCK
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|)
define|\
value|lock_profile_release_lock(&(lp)->lock_object)
end_define

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_RELEASE_RWLOCK
parameter_list|(
name|probe
parameter_list|,
name|lp
parameter_list|,
name|a
parameter_list|)
define|\
value|LOCKSTAT_PROFILE_RELEASE_LOCK(probe, lp)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_PROFILING
end_ifndef

begin_define
define|#
directive|define
name|LOCKSTAT_PROFILE_ENABLED
parameter_list|(
name|probe
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOCKSTAT_OOL_PROFILE_ENABLED
parameter_list|(
name|probe
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KDTRACE_HOOKS */
end_comment

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
comment|/* _SYS_LOCKSTAT_H */
end_comment

end_unit

