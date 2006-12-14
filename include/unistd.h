begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)unistd.h	8.12 (Berkeley) 4/27/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNISTD_H_
end_ifndef

begin_define
define|#
directive|define
name|_UNISTD_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* XXX adds too much pollution. */
end_comment

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_GID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__gid_t
name|gid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_GID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_OFF_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__off_t
name|off_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_OFF_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__pid_t
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SSIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ssize_t
name|ssize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SSIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uid_t
name|uid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_USECONDS_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__useconds_t
name|useconds_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_USECONDS_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_comment
comment|/* standard input file descriptor */
end_comment

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_comment
comment|/* standard output file descriptor */
end_comment

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_comment
comment|/* standard error file descriptor */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|F_ULOCK
value|0
end_define

begin_comment
comment|/* unlock locked section */
end_comment

begin_define
define|#
directive|define
name|F_LOCK
value|1
end_define

begin_comment
comment|/* lock a section for exclusive use */
end_comment

begin_define
define|#
directive|define
name|F_TLOCK
value|2
end_define

begin_comment
comment|/* test and lock a section for exclusive use */
end_comment

begin_define
define|#
directive|define
name|F_TEST
value|3
end_define

begin_comment
comment|/* test a section for locks by other procs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * POSIX options and option groups we unconditionally do or don't  * implement.  This list includes those options which are exclusively  * implemented (or not) in user mode.  Please keep this list in  * alphabetical order.  *  * Anything which is defined as zero below **must** have an  * implementation for the corresponding sysconf() which is able to  * determine conclusively whether or not the feature is supported.  * Anything which is defined as other than -1 below **must** have  * complete headers, types, and function declarations as specified by  * the POSIX standard; however, if the relevant sysconf() function  * returns -1, the functions may be stubbed out.  */
end_comment

begin_define
define|#
directive|define
name|_POSIX_BARRIERS
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_READER_WRITER_LOCKS
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_REGEXP
value|1
end_define

begin_define
define|#
directive|define
name|_POSIX_SHELL
value|1
end_define

begin_define
define|#
directive|define
name|_POSIX_SPAWN
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_SPIN_LOCKS
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_ATTR_STACKADDR
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_ATTR_STACKSIZE
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_CPUTIME
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_PRIO_INHERIT
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_PRIO_PROTECT
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_PRIORITY_SCHEDULING
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_PROCESS_SHARED
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_SAFE_FUNCTIONS
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_THREAD_SPORADIC_SERVER
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_THREADS
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX_TRACE
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_TRACE_EVENT_FILTER
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_TRACE_INHERIT
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX_TRACE_LOG
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX2_C_BIND
value|200112L
end_define

begin_comment
comment|/* mandatory */
end_comment

begin_define
define|#
directive|define
name|_POSIX2_C_DEV
value|-1
end_define

begin_comment
comment|/* need c99 utility */
end_comment

begin_define
define|#
directive|define
name|_POSIX2_CHAR_TERM
value|1
end_define

begin_define
define|#
directive|define
name|_POSIX2_FORT_DEV
value|-1
end_define

begin_comment
comment|/* need fort77 utility */
end_comment

begin_define
define|#
directive|define
name|_POSIX2_FORT_RUN
value|200112L
end_define

begin_define
define|#
directive|define
name|_POSIX2_LOCALEDEF
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX2_PBS
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX2_PBS_ACCOUNTING
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX2_PBS_CHECKPOINT
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX2_PBS_LOCATE
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX2_PBS_MESSAGE
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX2_PBS_TRACK
value|-1
end_define

begin_define
define|#
directive|define
name|_POSIX2_SW_DEV
value|-1
end_define

begin_comment
comment|/* XXX ??? */
end_comment

begin_define
define|#
directive|define
name|_POSIX2_UPE
value|200112L
end_define

begin_define
define|#
directive|define
name|_V6_ILP32_OFF32
value|-1
end_define

begin_define
define|#
directive|define
name|_V6_ILP32_OFFBIG
value|0
end_define

begin_define
define|#
directive|define
name|_V6_LP64_OFF64
value|0
end_define

begin_define
define|#
directive|define
name|_V6_LPBIG_OFFBIG
value|-1
end_define

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|_XOPEN_CRYPT
value|-1
end_define

begin_comment
comment|/* XXX ??? */
end_comment

begin_define
define|#
directive|define
name|_XOPEN_ENH_I18N
value|-1
end_define

begin_comment
comment|/* mandatory in XSI */
end_comment

begin_define
define|#
directive|define
name|_XOPEN_LEGACY
value|-1
end_define

begin_define
define|#
directive|define
name|_XOPEN_REALTIME
value|-1
end_define

begin_define
define|#
directive|define
name|_XOPEN_REALTIME_THREADS
value|-1
end_define

begin_define
define|#
directive|define
name|_XOPEN_UNIX
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the POSIX.2 version we target for compliance. */
end_comment

begin_define
define|#
directive|define
name|_POSIX2_VERSION
value|199212L
end_define

begin_comment
comment|/*  * POSIX-style system configuration variable accessors (for the  * sysconf function).  The kernel does not directly implement the  * sysconf() interface; rather, a C library stub translates references  * to sysconf() into calls to sysctl() using a giant switch statement.  * Those that are marked `user' are implemented entirely in the C  * library and never query the kernel.  pathconf() is implemented  * directly by the kernel so those are not defined here.  */
end_comment

begin_define
define|#
directive|define
name|_SC_ARG_MAX
value|1
end_define

begin_define
define|#
directive|define
name|_SC_CHILD_MAX
value|2
end_define

begin_define
define|#
directive|define
name|_SC_CLK_TCK
value|3
end_define

begin_define
define|#
directive|define
name|_SC_NGROUPS_MAX
value|4
end_define

begin_define
define|#
directive|define
name|_SC_OPEN_MAX
value|5
end_define

begin_define
define|#
directive|define
name|_SC_JOB_CONTROL
value|6
end_define

begin_define
define|#
directive|define
name|_SC_SAVED_IDS
value|7
end_define

begin_define
define|#
directive|define
name|_SC_VERSION
value|8
end_define

begin_define
define|#
directive|define
name|_SC_BC_BASE_MAX
value|9
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_BC_DIM_MAX
value|10
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_BC_SCALE_MAX
value|11
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_BC_STRING_MAX
value|12
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_COLL_WEIGHTS_MAX
value|13
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_EXPR_NEST_MAX
value|14
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_LINE_MAX
value|15
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_RE_DUP_MAX
value|16
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_VERSION
value|17
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_C_BIND
value|18
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_C_DEV
value|19
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_CHAR_TERM
value|20
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_FORT_DEV
value|21
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_FORT_RUN
value|22
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_LOCALEDEF
value|23
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_SW_DEV
value|24
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_UPE
value|25
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_STREAM_MAX
value|26
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_TZNAME_MAX
value|27
end_define

begin_comment
comment|/* user */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199309
end_if

begin_define
define|#
directive|define
name|_SC_ASYNCHRONOUS_IO
value|28
end_define

begin_define
define|#
directive|define
name|_SC_MAPPED_FILES
value|29
end_define

begin_define
define|#
directive|define
name|_SC_MEMLOCK
value|30
end_define

begin_define
define|#
directive|define
name|_SC_MEMLOCK_RANGE
value|31
end_define

begin_define
define|#
directive|define
name|_SC_MEMORY_PROTECTION
value|32
end_define

begin_define
define|#
directive|define
name|_SC_MESSAGE_PASSING
value|33
end_define

begin_define
define|#
directive|define
name|_SC_PRIORITIZED_IO
value|34
end_define

begin_define
define|#
directive|define
name|_SC_PRIORITY_SCHEDULING
value|35
end_define

begin_define
define|#
directive|define
name|_SC_REALTIME_SIGNALS
value|36
end_define

begin_define
define|#
directive|define
name|_SC_SEMAPHORES
value|37
end_define

begin_define
define|#
directive|define
name|_SC_FSYNC
value|38
end_define

begin_define
define|#
directive|define
name|_SC_SHARED_MEMORY_OBJECTS
value|39
end_define

begin_define
define|#
directive|define
name|_SC_SYNCHRONIZED_IO
value|40
end_define

begin_define
define|#
directive|define
name|_SC_TIMERS
value|41
end_define

begin_define
define|#
directive|define
name|_SC_AIO_LISTIO_MAX
value|42
end_define

begin_define
define|#
directive|define
name|_SC_AIO_MAX
value|43
end_define

begin_define
define|#
directive|define
name|_SC_AIO_PRIO_DELTA_MAX
value|44
end_define

begin_define
define|#
directive|define
name|_SC_DELAYTIMER_MAX
value|45
end_define

begin_define
define|#
directive|define
name|_SC_MQ_OPEN_MAX
value|46
end_define

begin_define
define|#
directive|define
name|_SC_PAGESIZE
value|47
end_define

begin_define
define|#
directive|define
name|_SC_RTSIG_MAX
value|48
end_define

begin_define
define|#
directive|define
name|_SC_SEM_NSEMS_MAX
value|49
end_define

begin_define
define|#
directive|define
name|_SC_SEM_VALUE_MAX
value|50
end_define

begin_define
define|#
directive|define
name|_SC_SIGQUEUE_MAX
value|51
end_define

begin_define
define|#
directive|define
name|_SC_TIMER_MAX
value|52
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|_SC_2_PBS
value|59
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_PBS_ACCOUNTING
value|60
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_PBS_CHECKPOINT
value|61
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_PBS_LOCATE
value|62
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_PBS_MESSAGE
value|63
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_2_PBS_TRACK
value|64
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_ADVISORY_INFO
value|65
end_define

begin_define
define|#
directive|define
name|_SC_BARRIERS
value|66
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_CLOCK_SELECTION
value|67
end_define

begin_define
define|#
directive|define
name|_SC_CPUTIME
value|68
end_define

begin_define
define|#
directive|define
name|_SC_FILE_LOCKING
value|69
end_define

begin_define
define|#
directive|define
name|_SC_GETGR_R_SIZE_MAX
value|70
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_GETPW_R_SIZE_MAX
value|71
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_HOST_NAME_MAX
value|72
end_define

begin_define
define|#
directive|define
name|_SC_LOGIN_NAME_MAX
value|73
end_define

begin_define
define|#
directive|define
name|_SC_MONOTONIC_CLOCK
value|74
end_define

begin_define
define|#
directive|define
name|_SC_MQ_PRIO_MAX
value|75
end_define

begin_define
define|#
directive|define
name|_SC_READER_WRITER_LOCKS
value|76
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_REGEXP
value|77
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_SHELL
value|78
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_SPAWN
value|79
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_SPIN_LOCKS
value|80
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_SPORADIC_SERVER
value|81
end_define

begin_define
define|#
directive|define
name|_SC_THREAD_ATTR_STACKADDR
value|82
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_ATTR_STACKSIZE
value|83
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_CPUTIME
value|84
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_DESTRUCTOR_ITERATIONS
value|85
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_KEYS_MAX
value|86
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_PRIO_INHERIT
value|87
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_PRIO_PROTECT
value|88
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_PRIORITY_SCHEDULING
value|89
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_PROCESS_SHARED
value|90
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_SAFE_FUNCTIONS
value|91
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_SPORADIC_SERVER
value|92
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_STACK_MIN
value|93
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREAD_THREADS_MAX
value|94
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_TIMEOUTS
value|95
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_THREADS
value|96
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_TRACE
value|97
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_TRACE_EVENT_FILTER
value|98
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_TRACE_INHERIT
value|99
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_TRACE_LOG
value|100
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_TTY_NAME_MAX
value|101
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_TYPED_MEMORY_OBJECTS
value|102
end_define

begin_define
define|#
directive|define
name|_SC_V6_ILP32_OFF32
value|103
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_V6_ILP32_OFFBIG
value|104
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_V6_LP64_OFF64
value|105
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_V6_LPBIG_OFFBIG
value|106
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_IPV6
value|118
end_define

begin_define
define|#
directive|define
name|_SC_RAW_SOCKETS
value|119
end_define

begin_define
define|#
directive|define
name|_SC_SYMLOOP_MAX
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|_SC_ATEXIT_MAX
value|107
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_IOV_MAX
value|56
end_define

begin_define
define|#
directive|define
name|_SC_PAGE_SIZE
value|_SC_PAGESIZE
end_define

begin_define
define|#
directive|define
name|_SC_XOPEN_CRYPT
value|108
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_XOPEN_ENH_I18N
value|109
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_XOPEN_LEGACY
value|110
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|_SC_XOPEN_REALTIME
value|111
end_define

begin_define
define|#
directive|define
name|_SC_XOPEN_REALTIME_THREADS
value|112
end_define

begin_define
define|#
directive|define
name|_SC_XOPEN_SHM
value|113
end_define

begin_define
define|#
directive|define
name|_SC_XOPEN_STREAMS
value|114
end_define

begin_define
define|#
directive|define
name|_SC_XOPEN_UNIX
value|115
end_define

begin_define
define|#
directive|define
name|_SC_XOPEN_VERSION
value|116
end_define

begin_define
define|#
directive|define
name|_SC_XOPEN_XCU_VERSION
value|117
end_define

begin_comment
comment|/* user */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|_SC_NPROCESSORS_CONF
value|57
end_define

begin_define
define|#
directive|define
name|_SC_NPROCESSORS_ONLN
value|58
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extensions found in Solaris and Linux. */
end_comment

begin_define
define|#
directive|define
name|_SC_PHYS_PAGES
value|121
end_define

begin_comment
comment|/* Keys for the confstr(3) function. */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199209
end_if

begin_define
define|#
directive|define
name|_CS_PATH
value|1
end_define

begin_comment
comment|/* default value of PATH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|_CS_POSIX_V6_ILP32_OFF32_CFLAGS
value|2
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_ILP32_OFF32_LDFLAGS
value|3
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_ILP32_OFF32_LIBS
value|4
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_ILP32_OFFBIG_CFLAGS
value|5
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS
value|6
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_ILP32_OFFBIG_LIBS
value|7
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_LP64_OFF64_CFLAGS
value|8
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_LP64_OFF64_LDFLAGS
value|9
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_LP64_OFF64_LIBS
value|10
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS
value|11
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS
value|12
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_LPBIG_OFFBIG_LIBS
value|13
end_define

begin_define
define|#
directive|define
name|_CS_POSIX_V6_WIDTH_RESTRICTED_ENVS
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__BEGIN_DECLS
comment|/* 1003.1-1990 */
name|void
name|_exit
argument_list|(
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|access
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|alarm
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chdir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chown
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dup2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eaccess
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execle
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execlp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execve
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execvp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|fork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|fpathconf
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getcwd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gid_t
name|getegid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uid_t
name|geteuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gid_t
name|getgid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getgroups
parameter_list|(
name|int
parameter_list|,
name|gid_t
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getlogin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|getpgrp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|getpid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|getppid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uid_t
name|getuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isatty
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|link
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_LSEEK_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_LSEEK_DECLARED
end_define

begin_function_decl
name|off_t
name|lseek
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|pathconf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pause
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pipe
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|read
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rmdir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setgid
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpgid
parameter_list|(
name|pid_t
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setproctitle
parameter_list|(
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printf0like
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|pid_t
name|setsid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|sleep
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|sysconf
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|tcgetpgrp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcsetpgrp
parameter_list|(
name|int
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ttyname
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ttyname_r
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 1003.2-1992 */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199209
operator|||
name|__XSI_VISIBLE
end_if

begin_function_decl
name|size_t
name|confstr
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_GETOPT_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_GETOPT_DECLARED
end_define

begin_function_decl
name|int
name|getopt
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
specifier|const
type|[]
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getopt(3) external variables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|,
name|opterr
decl_stmt|,
name|optopt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GETOPT_DECLARED */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISO/IEC 9945-1: 1996 */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199506
operator|||
name|__XSI_VISIBLE
end_if

begin_function_decl
name|int
name|fsync
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ftruncate() was in the POSIX Realtime Extension (it's used for shared  * memory), but truncate() was not.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FTRUNCATE_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_FTRUNCATE_DECLARED
end_define

begin_function_decl
name|int
name|ftruncate
parameter_list|(
name|int
parameter_list|,
name|off_t
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

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199506
end_if

begin_function_decl
name|int
name|getlogin_r
parameter_list|(
name|char
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
comment|/* 1003.1-2001 */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
operator|||
name|__XSI_VISIBLE
end_if

begin_function_decl
name|int
name|fchown
parameter_list|(
name|int
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
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

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_function_decl
name|int
name|gethostname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setegid
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|seteuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * symlink() was originally in POSIX.1a, which was withdrawn after  * being overtaken by events (1003.1-2001).  It was in XPG4.2, and of  * course has been in BSD since 4.2.  */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
operator|||
name|__XSI_VISIBLE
operator|>=
literal|402
operator|||
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|symlink
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* X/Open System Interfaces */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* char	*ctermid(char *); */
end_comment

begin_comment
comment|/* XXX ??? */
end_comment

begin_function_decl
name|int
name|encrypt
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fchdir
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|gethostid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpgid
parameter_list|(
name|pid_t
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getsid
parameter_list|(
name|pid_t
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* LEGACY: obsoleted by getcwd() */
end_comment

begin_function_decl
name|int
name|lchown
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockf
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nice
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|pread
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|pwrite
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpgrp
parameter_list|(
name|pid_t
name|_pid
parameter_list|,
name|pid_t
name|_pgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* obsoleted by setpgid() */
end_comment

begin_function_decl
name|int
name|setregid
parameter_list|(
name|gid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setreuid
parameter_list|(
name|uid_t
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_SWAB_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_SWAB_DECLARED
end_define

begin_function_decl
name|void
name|swab
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|,
name|ssize_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SWAB_DECLARED */
end_comment

begin_function_decl
name|void
name|sync
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|useconds_t
name|ualarm
parameter_list|(
name|useconds_t
parameter_list|,
name|useconds_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usleep
parameter_list|(
name|useconds_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|vfork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* See comment at ftruncate() above. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TRUNCATE_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_TRUNCATE_DECLARED
end_define

begin_function_decl
name|int
name|truncate
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|off_t
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
comment|/* __XSI_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
operator|<=
literal|500
operator|||
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|brk
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chroot
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getdtablesize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|getpagesize
argument_list|(
name|void
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getpass
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|sbrk
parameter_list|(
name|intptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_comment
comment|/* select(2) */
end_comment

begin_function_decl
name|int
name|acct
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|async_daemon
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_utility_compat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|crypt_get_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crypt_set_format
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_cipher
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_setkey
parameter_list|(
specifier|const
name|char
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exect
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execvP
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fflagstostr
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getdomainname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getgrouplist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mode_t
name|getmode
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpeereid
parameter_list|(
name|int
parameter_list|,
name|uid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getresgid
parameter_list|(
name|gid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getresuid
parameter_list|(
name|uid_t
modifier|*
parameter_list|,
name|uid_t
modifier|*
parameter_list|,
name|uid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initgroups
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iruserok
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iruserok_sa
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|issetugid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mkdtemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_MKNOD_DECLARED
end_ifndef

begin_function_decl
name|int
name|mknod
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_MKNOD_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MKSTEMP_DECLARED
end_ifndef

begin_function_decl
name|int
name|mkstemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_MKSTEMP_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|mkstemps
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_MKTEMP_DECLARED
end_ifndef

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_MKTEMP_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|nfssvc
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|profil
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcmd
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcmd_af
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcmdsh
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|re_comp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|re_exec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reboot
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|revoke
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|rfork
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|rfork_thread
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rresvport
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rresvport_af
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ruserok
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_SELECT_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_SELECT_DECLARED
end_define

begin_function_decl
name|int
name|select
parameter_list|(
name|int
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
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

begin_function_decl
name|int
name|setdomainname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setgroups
parameter_list|(
name|int
parameter_list|,
specifier|const
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sethostid
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sethostname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_SETKEY_DECLARED
end_ifndef

begin_function_decl
name|int
name|setkey
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_SETKEY_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|setlogin
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|setmode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setresgid
parameter_list|(
name|gid_t
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setresuid
parameter_list|(
name|uid_t
parameter_list|,
name|uid_t
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setrgid
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setruid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strtofflags
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swapon
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swapoff
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syscall
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|__syscall
parameter_list|(
name|quad_t
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ttyslot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|undelete
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unwhiteout
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|valloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* obsoleted by malloc() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPTRESET_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_OPTRESET_DECLARED
end_define

begin_decl_stmt
specifier|extern
name|int
name|optreset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getopt(3) external variable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UNISTD_H_ */
end_comment

end_unit

