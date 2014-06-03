begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2013 Alexander Motin<mav@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TIMEEC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TIMEEC_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/*  * `struct eventtimer' is the interface between the hardware which implements  * a event timer and the MI code which uses this to receive time events.  */
end_comment

begin_struct_decl
struct_decl|struct
name|eventtimer
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|et_start_t
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|,
name|sbintime_t
name|first
parameter_list|,
name|sbintime_t
name|period
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|et_stop_t
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|et_event_cb_t
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|et_deregister_cb_t
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|eventtimer
block|{
name|SLIST_ENTRY
argument_list|(
argument|eventtimer
argument_list|)
name|et_all
expr_stmt|;
comment|/* Pointer to the next event timer. */
name|char
modifier|*
name|et_name
decl_stmt|;
comment|/* Name of the event timer. */
name|int
name|et_flags
decl_stmt|;
comment|/* Set of capabilities flags: */
define|#
directive|define
name|ET_FLAGS_PERIODIC
value|1
define|#
directive|define
name|ET_FLAGS_ONESHOT
value|2
define|#
directive|define
name|ET_FLAGS_PERCPU
value|4
define|#
directive|define
name|ET_FLAGS_C3STOP
value|8
define|#
directive|define
name|ET_FLAGS_POW2DIV
value|16
name|int
name|et_quality
decl_stmt|;
comment|/* 		 * Used to determine if this timecounter is better than 		 * another timecounter. Higher means better. 		 */
name|int
name|et_active
decl_stmt|;
name|u_int64_t
name|et_frequency
decl_stmt|;
comment|/* Base frequency in Hz. */
name|sbintime_t
name|et_min_period
decl_stmt|;
name|sbintime_t
name|et_max_period
decl_stmt|;
name|et_start_t
modifier|*
name|et_start
decl_stmt|;
name|et_stop_t
modifier|*
name|et_stop
decl_stmt|;
name|et_event_cb_t
modifier|*
name|et_event_cb
decl_stmt|;
name|et_deregister_cb_t
modifier|*
name|et_deregister_cb
decl_stmt|;
name|void
modifier|*
name|et_arg
decl_stmt|;
name|void
modifier|*
name|et_priv
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|et_sysctl
decl_stmt|;
comment|/* Pointer to the event timer's private parts. */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|et_eventtimers_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ET_LOCK
parameter_list|()
value|mtx_lock(&et_eventtimers_mtx)
end_define

begin_define
define|#
directive|define
name|ET_UNLOCK
parameter_list|()
value|mtx_unlock(&et_eventtimers_mtx)
end_define

begin_comment
comment|/* Driver API */
end_comment

begin_function_decl
name|int
name|et_register
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|et_deregister
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|et_change_frequency
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|,
name|uint64_t
name|newfreq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Consumer API  */
end_comment

begin_function_decl
name|struct
name|eventtimer
modifier|*
name|et_find
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|check
parameter_list|,
name|int
name|want
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|et_init
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|,
name|et_event_cb_t
modifier|*
name|event
parameter_list|,
name|et_deregister_cb_t
modifier|*
name|deregister
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|et_start
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|,
name|sbintime_t
name|first
parameter_list|,
name|sbintime_t
name|period
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|et_stop
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|et_ban
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|et_free
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_eventtimer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TIMETC_H_ */
end_comment

end_unit

