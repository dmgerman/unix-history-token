begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Bjoern A. Zeeb  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-11-C-0249  * ("MRC2"), as part of the DARPA MRC research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_TIMER_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_TIMER_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__LINUX_ARCH_SIGEV_PREAMBLE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|__LINUX_ARCH_SIGEV_PREAMBLE_SIZE
define|\
value|(sizeof(l_int) * 2 + sizeof(l_sigval_t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINUX_SIGEV_MAX_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|LINUX_SIGEV_PAD_SIZE
define|\
value|((LINUX_SIGEV_MAX_SIZE - __LINUX_ARCH_SIGEV_PREAMBLE_SIZE) / \ 	sizeof(l_int))
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_REALTIME
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_MONOTONIC
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_PROCESS_CPUTIME_ID
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_THREAD_CPUTIME_ID
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_MONOTONIC_RAW
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_REALTIME_COARSE
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_MONOTONIC_COARSE
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_BOOTTIME
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_REALTIME_ALARM
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_BOOTTIME_ALARM
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_SGI_CYCLE
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_TAI
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_CPUCLOCK_PERTHREAD_MASK
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_CPUCLOCK_MASK
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_CPUCLOCK_WHICH
parameter_list|(
name|clock
parameter_list|)
define|\
value|((clock)& (clockid_t) LINUX_CPUCLOCK_MASK)
end_define

begin_define
define|#
directive|define
name|LINUX_CPUCLOCK_PROF
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_CPUCLOCK_VIRT
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_CPUCLOCK_SCHED
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_CPUCLOCK_MAX
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCKFD
value|LINUX_CPUCLOCK_MAX
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCKFD_MASK
define|\
value|(LINUX_CPUCLOCK_PERTHREAD_MASK|LINUX_CPUCLOCK_MASK)
end_define

begin_define
define|#
directive|define
name|LINUX_CPUCLOCK_ID
parameter_list|(
name|clock
parameter_list|)
value|((pid_t) ~((clock)>> 3))
end_define

begin_define
define|#
directive|define
name|LINUX_CPUCLOCK_PERTHREAD
parameter_list|(
name|clock
parameter_list|)
define|\
value|(((clock)& (clockid_t) LINUX_CPUCLOCK_PERTHREAD_MASK) != 0)
end_define

begin_define
define|#
directive|define
name|LINUX_TIMER_ABSTIME
value|0x01
end_define

begin_define
define|#
directive|define
name|L_SIGEV_SIGNAL
value|0
end_define

begin_define
define|#
directive|define
name|L_SIGEV_NONE
value|1
end_define

begin_define
define|#
directive|define
name|L_SIGEV_THREAD
value|2
end_define

begin_define
define|#
directive|define
name|L_SIGEV_THREAD_ID
value|4
end_define

begin_define
define|#
directive|define
name|TS_CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|fld
parameter_list|)
value|do {			\ 	CP((src).fld,(dst).fld,tv_sec);		\ 	CP((src).fld,(dst).fld,tv_nsec);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|ITS_CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|do {			\ 	TS_CP((src), (dst), it_interval);	\ 	TS_CP((src), (dst), it_value);		\ } while (0)
end_define

begin_struct
struct|struct
name|l_sigevent
block|{
name|l_sigval_t
name|sigev_value
decl_stmt|;
name|l_int
name|sigev_signo
decl_stmt|;
name|l_int
name|sigev_notify
decl_stmt|;
union|union
block|{
name|l_int
name|_pad
index|[
name|LINUX_SIGEV_PAD_SIZE
index|]
decl_stmt|;
name|l_int
name|_tid
decl_stmt|;
struct|struct
block|{
name|l_uintptr_t
name|_function
decl_stmt|;
name|l_uintptr_t
name|_attribute
decl_stmt|;
block|}
name|_l_sigev_thread
struct|;
block|}
name|_l_sigev_un
union|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|&&
name|defined
argument_list|(
name|COMPAT_LINUX32
argument_list|)
name|__packed
endif|#
directive|endif
struct|;
end_struct

begin_struct
struct|struct
name|l_itimerspec
block|{
name|struct
name|l_timespec
name|it_interval
decl_stmt|;
name|struct
name|l_timespec
name|it_value
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|native_to_linux_timespec
parameter_list|(
name|struct
name|l_timespec
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_to_native_timespec
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|l_timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_to_native_clockid
parameter_list|(
name|clockid_t
modifier|*
parameter_list|,
name|clockid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|native_to_linux_itimerspec
parameter_list|(
name|struct
name|l_itimerspec
modifier|*
parameter_list|,
name|struct
name|itimerspec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_to_native_itimerspec
parameter_list|(
name|struct
name|itimerspec
modifier|*
parameter_list|,
name|struct
name|l_itimerspec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_to_native_timerflags
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_TIMER_H */
end_comment

end_unit

