begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX4_POSIX4_H_
end_ifndef

begin_define
define|#
directive|define
name|_POSIX4_POSIX4_H_
end_define

begin_comment
comment|/*-  * Copyright (c) 1996, 1997, 1998  *	HD Associates, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HD Associates, Inc  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
operator|&&
name|_POSIX_VERSION
operator|>=
literal|199309L
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_comment
comment|/*  * This defines POSIX4_VISIBLE to indicate posix4 extensions should show up.  * You should test this when you add a posix4 extension to a header  * that exists in POSIX.1.  Try "man 9 posix4".  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|&&
name|_POSIX_C_SOURCE
operator|>=
literal|199309L
end_if

begin_define
define|#
directive|define
name|POSIX4_VISIBLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   *  * March 1, 1998: Details from here on change and this header file  * is volatile.  *  * Locally I've got PRIORITY SCHEDULING  * set as a system call available only to root   * and I'm still using a pseudo device to gate everything else.  *  * This interface vectors us into the kernel through a  * POSIX4 pseudo device with some user privilege authorization along  * the way.  *  * XXX I'm going with option 3.  *  * This has drawbacks from the point of view of ktrace.  There  * are (at least) three ways to do this:  *  * 1. As it is being done, which is bad for ktrace and is hokey  *    but is easy to extend during development;  * 2. Add a system call for every POSIX4 entry point, which  *    will result in many more system calls (on the order of 64)  * 3. Add a system call for each POSIX4 option, which is a bit more  *    useful for ktrace and will add only about 14 new system calls.  *   */
end_comment

begin_define
define|#
directive|define
name|POSIX4_FACILITIES
value|16
end_define

begin_define
define|#
directive|define
name|POSIX4_ONE_ONLY
end_define

begin_comment
comment|/*   * All facility request structures have a posix4_dispatch header  * at the front.  Return values are always an indication of  * success or failure and are automatically converted into an errno  * by the kernel.  "Non-errno" return codes are handled via ret.  */
end_comment

begin_struct
struct|struct
name|posix4_dispatch
block|{
name|int
name|op
decl_stmt|;
name|int
name|ret
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_PRIORITY_SCHEDULING
argument_list|)
end_if

begin_comment
comment|/*   * KSCHED_OP_RW is a vector of read/write flags for each entry indexed  * by the enum ksched_op.  *  * 1 means you need write access, 0 means read is sufficient.  */
end_comment

begin_enum
enum|enum
name|ksched_op
block|{
define|#
directive|define
name|KSCHED_OP_RW
value|{ 1, 0, 1, 0, 0, 0, 0, 0 }
name|SCHED_SETPARAM
block|,
name|SCHED_GETPARAM
block|,
name|SCHED_SETSCHEDULER
block|,
name|SCHED_GETSCHEDULER
block|,
name|SCHED_YIELD
block|,
name|SCHED_GET_PRIORITY_MAX
block|,
name|SCHED_GET_PRIORITY_MIN
block|,
name|SCHED_RR_GET_INTERVAL
block|,
name|SCHED_OP_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ksched
block|{
name|struct
name|posix4_dispatch
name|dispatch
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
name|int
name|policy
decl_stmt|;
name|struct
name|sched_param
name|param
decl_stmt|;
name|struct
name|timespec
name|interval
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_PRIORITY_SCHEDULING */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_MEMLOCK
argument_list|)
operator|^
name|defined
argument_list|(
name|_POSIX_MEMLOCK_RANGE
argument_list|)
end_if

begin_comment
comment|/* This implementation expects these two options to always be together.  * If one isn't handled it should be disabled at  * run time.  */
end_comment

begin_error
error|#
directive|error
error|_POSIX_MEMLOCK and _POSIX_MEMLOCK_RANGE should always be together
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_MEMLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|_POSIX_MEMLOCK_RANGE
argument_list|)
end_if

begin_enum
enum|enum
name|kmemlock_op
block|{
define|#
directive|define
name|KMEMLOCK_OP_RW
value|{ 1, 1, 1, 1 }
name|MEMLOCK_MLOCKALL
block|,
name|MEMLOCK_MUNLOCKALL
block|,
name|MEMLOCK_MLOCK
block|,
name|MEMLOCK_MUNLOCK
block|,
name|MEMLOCK_OP_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|kmemlock
block|{
name|struct
name|posix4_dispatch
name|dispatch
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|void
modifier|*
name|addr
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_MEMLOCK&& _POSIX_MEMLOCK_RANGE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
modifier|*
name|posix4malloc
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|posix4free
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|posix4proc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|pid_t
operator|,
expr|struct
name|proc
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|posix4ioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|posix4attach
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|posix4_facility
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|lkm_table
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|posix4_init
name|__P
argument_list|(
operator|(
expr|struct
name|lkm_table
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_PRIORITY_SCHEDULING
end_ifdef

begin_function_decl
name|int
name|ksched_attach
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_detach
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_setparam
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_getparam
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_setscheduler
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_getscheduler
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_yield
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_get_priority_max
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_get_priority_min
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_rr_get_interval
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_PRIORITY_SCHEDULING */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_MEMLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|_POSIX_MEMLOCK_RANGE
argument_list|)
end_if

begin_function_decl
name|int
name|kmemlock_attach
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kmemlock_detach
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kmlockall
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kmunlockall
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kmlock
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kmunlock
parameter_list|(
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_MEMLOCK&& _POSIX_MEMLOCK_RANGE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/* A facility is an implementation of one of the optional portions of  * POSIX4 as selected by the feature test macros, such as the fixed  * priority scheduler or the realtime signals.  */
end_comment

begin_comment
comment|/* Each facility has a facility code, an opcode, and r-w attributes.  * To exercise the operation associated with an opcode you need the  * appropriate privileges on the POSIX4 device with the facility  * bit set in the minor number.  This means that every facility has  * a protection bit: Probably more than we need, but it may have  * advantages.  *  */
end_comment

begin_define
define|#
directive|define
name|posix4encode
parameter_list|(
name|FACILITY
parameter_list|,
name|RW
parameter_list|)
value|(FACILITY)
end_define

begin_define
define|#
directive|define
name|posix4decode
parameter_list|(
name|X
parameter_list|,
name|FACILITY_P
parameter_list|)
define|\
value|do { \ 		*(FACILITY_P) = ((X)& 0xff); \ 	} while (0)
end_define

begin_comment
comment|/*  * The dispatch codes:  */
end_comment

begin_define
define|#
directive|define
name|IO_POSIX4_PRIORITY_SCHEDULING
value|_IOWR('r', \ 	CTL_POSIX4_PRIORITY_SCHEDULING, struct ksched)
end_define

begin_define
define|#
directive|define
name|IO_POSIX4_MEMLOCK
value|_IOWR('r', \ 	CTL_POSIX4_MEMLOCK, struct ksched)
end_define

begin_comment
comment|/*  * CTL_POSIX4 definitions for syscfg  */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_ASYNCHRONOUS_IO
value|1
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_MAPPED_FILES
value|2
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_MEMLOCK
value|3
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_MEMLOCK_RANGE
value|4
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_MEMORY_PROTECTION
value|5
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_MESSAGE_PASSING
value|6
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_PRIORITIZED_IO
value|7
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_PRIORITY_SCHEDULING
value|8
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_REALTIME_SIGNALS
value|9
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_SEMAPHORES
value|10
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_FSYNC
value|11
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_SHARED_MEMORY_OBJECTS
value|12
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_SYNCHRONIZED_IO
value|13
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_TIMERS
value|14
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_AIO_LISTIO_MAX
value|15
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_AIO_MAX
value|16
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_AIO_PRIO_DELTA_MAX
value|17
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_DELAYTIMER_MAX
value|18
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_MQ_OPEN_MAX
value|19
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_PAGESIZE
value|20
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_RTSIG_MAX
value|21
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_SEM_NSEMS_MAX
value|22
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_SEM_VALUE_MAX
value|23
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_SIGQUEUE_MAX
value|24
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_TIMER_MAX
value|25
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_POSIX4_N_CTLS
value|25
end_define

begin_define
define|#
directive|define
name|CTL_POSIX4_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "asynchronous_io", CTLTYPE_INT }, \ 	{ "mapped_files", CTLTYPE_INT }, \ 	{ "memlock", CTLTYPE_INT }, \ 	{ "memlock_range", CTLTYPE_INT }, \ 	{ "memory_protection", CTLTYPE_INT }, \ 	{ "message_passing", CTLTYPE_INT }, \ 	{ "prioritized_io", CTLTYPE_INT }, \ 	{ "priority_scheduling", CTLTYPE_INT }, \ 	{ "realtime_signals", CTLTYPE_INT }, \ 	{ "semaphores", CTLTYPE_INT }, \ 	{ "fsync", CTLTYPE_INT }, \ 	{ "shared_memory_objects", CTLTYPE_INT }, \ 	{ "synchronized_io", CTLTYPE_INT }, \ 	{ "timers", CTLTYPE_INT }, \ 	{ "aio_listio_max", CTLTYPE_INT }, \ 	{ "aio_max", CTLTYPE_INT }, \ 	{ "aio_prio_delta_max", CTLTYPE_INT }, \ 	{ "delaytimer_max", CTLTYPE_INT }, \ 	{ "mq_open_max", CTLTYPE_INT }, \ 	{ "pagesize", CTLTYPE_INT }, \ 	{ "rtsig_max", CTLTYPE_INT }, \ 	{ "nsems_max", CTLTYPE_INT }, \ 	{ "sem_value_max", CTLTYPE_INT }, \ 	{ "sigqueue_max", CTLTYPE_INT }, \ 	{ "timer_max", CTLTYPE_INT }, \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION>= 199309L */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX4_POSIX4_H_ */
end_comment

end_unit

