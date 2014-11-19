begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)callout.h	8.2 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CALLOUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CALLOUT_H_
end_define

begin_include
include|#
directive|include
file|<sys/_callout.h>
end_include

begin_define
define|#
directive|define
name|CALLOUT_LOCAL_ALLOC
value|0x0001
end_define

begin_comment
comment|/* was allocated from callfree */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_ACTIVE
value|0x0002
end_define

begin_comment
comment|/* callout is currently active */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_PENDING
value|0x0004
end_define

begin_comment
comment|/* callout is waiting for timeout */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_MPSAFE
value|0x0008
end_define

begin_comment
comment|/* callout handler is mp safe */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_RETURNUNLOCKED
value|0x0010
end_define

begin_comment
comment|/* handler returns with mtx unlocked */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_SHAREDLOCK
value|0x0020
end_define

begin_comment
comment|/* callout lock held in shared mode */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_DFRMIGRATION
value|0x0040
end_define

begin_comment
comment|/* callout in deferred migration mode */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_PROCESSED
value|0x0080
end_define

begin_comment
comment|/* callout in wheel or processing list? */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_DIRECT
value|0x0100
end_define

begin_comment
comment|/* allow exec from hw int context */
end_comment

begin_define
define|#
directive|define
name|C_DIRECT_EXEC
value|0x0001
end_define

begin_comment
comment|/* direct execution of callout */
end_comment

begin_define
define|#
directive|define
name|C_PRELBITS
value|7
end_define

begin_define
define|#
directive|define
name|C_PRELRANGE
value|((1<< C_PRELBITS) - 1)
end_define

begin_define
define|#
directive|define
name|C_PREL
parameter_list|(
name|x
parameter_list|)
value|(((x) + 1)<< 1)
end_define

begin_define
define|#
directive|define
name|C_PRELGET
parameter_list|(
name|x
parameter_list|)
value|(int)((((x)>> 1)& C_PRELRANGE) - 1)
end_define

begin_define
define|#
directive|define
name|C_HARDCLOCK
value|0x0100
end_define

begin_comment
comment|/* align to hardclock() calls */
end_comment

begin_define
define|#
directive|define
name|C_ABSOLUTE
value|0x0200
end_define

begin_comment
comment|/* event time is absolute. */
end_comment

begin_struct
struct|struct
name|callout_handle
block|{
name|struct
name|callout
modifier|*
name|callout
decl_stmt|;
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
name|callout_active
parameter_list|(
name|c
parameter_list|)
value|((c)->c_flags& CALLOUT_ACTIVE)
end_define

begin_define
define|#
directive|define
name|callout_deactivate
parameter_list|(
name|c
parameter_list|)
value|((c)->c_flags&= ~CALLOUT_ACTIVE)
end_define

begin_define
define|#
directive|define
name|callout_drain
parameter_list|(
name|c
parameter_list|)
value|_callout_stop_safe(c, 1)
end_define

begin_function_decl
name|void
name|callout_init
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_callout_init_lock
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|,
name|struct
name|lock_object
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|callout_init_mtx
parameter_list|(
name|c
parameter_list|,
name|mtx
parameter_list|,
name|flags
parameter_list|)
define|\
value|_callout_init_lock((c), ((mtx) != NULL) ?&(mtx)->lock_object :	\ 	    NULL, (flags))
end_define

begin_define
define|#
directive|define
name|callout_init_rm
parameter_list|(
name|c
parameter_list|,
name|rm
parameter_list|,
name|flags
parameter_list|)
define|\
value|_callout_init_lock((c), ((rm) != NULL) ?&(rm)->lock_object : 	\ 	    NULL, (flags))
end_define

begin_define
define|#
directive|define
name|callout_init_rw
parameter_list|(
name|c
parameter_list|,
name|rw
parameter_list|,
name|flags
parameter_list|)
define|\
value|_callout_init_lock((c), ((rw) != NULL) ?&(rw)->lock_object :	\ 	   NULL, (flags))
end_define

begin_define
define|#
directive|define
name|callout_pending
parameter_list|(
name|c
parameter_list|)
value|((c)->c_flags& CALLOUT_PENDING)
end_define

begin_function_decl
name|int
name|callout_reset_sbt_on
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|,
name|sbintime_t
parameter_list|,
name|sbintime_t
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|callout_reset_sbt
parameter_list|(
name|c
parameter_list|,
name|sbt
parameter_list|,
name|pr
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|,
name|flags
parameter_list|)
define|\
value|callout_reset_sbt_on((c), (sbt), (pr), (fn), (arg), (c)->c_cpu, flags)
end_define

begin_define
define|#
directive|define
name|callout_reset_sbt_curcpu
parameter_list|(
name|c
parameter_list|,
name|sbt
parameter_list|,
name|pr
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|,
name|flags
parameter_list|)
define|\
value|callout_reset_sbt_on((c), (sbt), (pr), (fn), (arg), PCPU_GET(cpuid), flags)
end_define

begin_define
define|#
directive|define
name|callout_reset_on
parameter_list|(
name|c
parameter_list|,
name|to_ticks
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|,
name|cpu
parameter_list|)
define|\
value|callout_reset_sbt_on((c), (tick_sbt * (to_ticks)), 0, (fn), (arg), \         (cpu), C_HARDCLOCK)
end_define

begin_define
define|#
directive|define
name|callout_reset
parameter_list|(
name|c
parameter_list|,
name|on_tick
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|)
define|\
value|callout_reset_on((c), (on_tick), (fn), (arg), (c)->c_cpu)
end_define

begin_define
define|#
directive|define
name|callout_reset_curcpu
parameter_list|(
name|c
parameter_list|,
name|on_tick
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|)
define|\
value|callout_reset_on((c), (on_tick), (fn), (arg), PCPU_GET(cpuid))
end_define

begin_function_decl
name|int
name|callout_schedule
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|callout_schedule_on
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|callout_schedule_curcpu
parameter_list|(
name|c
parameter_list|,
name|on_tick
parameter_list|)
define|\
value|callout_schedule_on((c), (on_tick), PCPU_GET(cpuid))
end_define

begin_define
define|#
directive|define
name|callout_stop
parameter_list|(
name|c
parameter_list|)
value|_callout_stop_safe(c, 0)
end_define

begin_function_decl
name|int
name|_callout_stop_safe
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|callout_process
parameter_list|(
name|sbintime_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_CALLOUT_H_ */
end_comment

end_unit

