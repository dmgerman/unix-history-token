begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Roman Divacky  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MISC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MISC_H_
end_define

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_comment
comment|/* bits per mask */
end_comment

begin_define
define|#
directive|define
name|LINUX_NFDBITS
value|sizeof(l_fd_mask) * 8
end_define

begin_comment
comment|/*  * Miscellaneous  */
end_comment

begin_define
define|#
directive|define
name|LINUX_NAME_MAX
value|255
end_define

begin_define
define|#
directive|define
name|LINUX_MAX_UTSNAME
value|65
end_define

begin_define
define|#
directive|define
name|LINUX_CTL_MAXNAME
value|10
end_define

begin_comment
comment|/* defines for prctl */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_SET_PDEATHSIG
value|1
end_define

begin_comment
comment|/* Second arg is a signal. */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_GET_PDEATHSIG
value|2
end_define

begin_comment
comment|/* 					 * Second arg is a ptr to return the 					 * signal. 					 */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_GET_KEEPCAPS
value|7
end_define

begin_comment
comment|/* Get drop capabilities on setuid */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_SET_KEEPCAPS
value|8
end_define

begin_comment
comment|/* Set drop capabilities on setuid */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_SET_NAME
value|15
end_define

begin_comment
comment|/* Set process name. */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_GET_NAME
value|16
end_define

begin_comment
comment|/* Get process name. */
end_comment

begin_define
define|#
directive|define
name|LINUX_MAX_COMM_LEN
value|16
end_define

begin_comment
comment|/* Maximum length of the process name. */
end_comment

begin_define
define|#
directive|define
name|LINUX_MREMAP_MAYMOVE
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_MREMAP_FIXED
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_PATH_MAX
value|4096
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|linux_kplatform
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Non-standard aux entry types used in Linux ELF binaries.  */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_PLATFORM
value|15
end_define

begin_comment
comment|/* String identifying CPU */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_HWCAP
value|16
end_define

begin_comment
comment|/* CPU capabilities */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_CLKTCK
value|17
end_define

begin_comment
comment|/* frequency at which times() increments */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_SECURE
value|23
end_define

begin_comment
comment|/* secure mode boolean */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_BASE_PLATFORM
value|24
end_define

begin_comment
comment|/* string identifying real platform, may 					 * differ from AT_PLATFORM. 					 */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_RANDOM
value|25
end_define

begin_comment
comment|/* address of random bytes */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_EXECFN
value|31
end_define

begin_comment
comment|/* filename of program */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_SYSINFO
value|32
end_define

begin_comment
comment|/* vsyscall */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_SYSINFO_EHDR
value|33
end_define

begin_comment
comment|/* vdso header */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_RANDOM_LEN
value|16
end_define

begin_comment
comment|/* size of random bytes */
end_comment

begin_comment
comment|/* Linux sets the i387 to extended precision. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__LINUX_NPXCW__
value|0x37f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINUX_CLONE_VM
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_FS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_FILES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_SIGHAND
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_PID
value|0x00001000
end_define

begin_comment
comment|/* No longer exist in Linux */
end_comment

begin_define
define|#
directive|define
name|LINUX_CLONE_VFORK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_PARENT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_THREAD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_SETTLS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_PARENT_SETTID
value|0x00100000
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_CHILD_CLEARTID
value|0x00200000
end_define

begin_define
define|#
directive|define
name|LINUX_CLONE_CHILD_SETTID
value|0x01000000
end_define

begin_comment
comment|/* Scheduling policies */
end_comment

begin_define
define|#
directive|define
name|LINUX_SCHED_OTHER
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_SCHED_FIFO
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SCHED_RR
value|2
end_define

begin_struct
struct|struct
name|l_new_utsname
block|{
name|char
name|sysname
index|[
name|LINUX_MAX_UTSNAME
index|]
decl_stmt|;
name|char
name|nodename
index|[
name|LINUX_MAX_UTSNAME
index|]
decl_stmt|;
name|char
name|release
index|[
name|LINUX_MAX_UTSNAME
index|]
decl_stmt|;
name|char
name|version
index|[
name|LINUX_MAX_UTSNAME
index|]
decl_stmt|;
name|char
name|machine
index|[
name|LINUX_MAX_UTSNAME
index|]
decl_stmt|;
name|char
name|domainname
index|[
name|LINUX_MAX_UTSNAME
index|]
decl_stmt|;
block|}
struct|;
end_struct

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
name|LINUX_CLOCK_REALTIME_HR
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCK_MONOTONIC_HR
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_UTIME_NOW
value|0x3FFFFFFF
end_define

begin_define
define|#
directive|define
name|LINUX_UTIME_OMIT
value|0x3FFFFFFE
end_define

begin_decl_stmt
specifier|extern
name|int
name|stclohz
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LINUX_WNOHANG
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LINUX_WUNTRACED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LINUX_WSTOPPED
value|LINUX_WUNTRACED
end_define

begin_define
define|#
directive|define
name|LINUX_WEXITED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LINUX_WCONTINUED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LINUX_WNOWAIT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|__WNOTHREAD
value|0x20000000
end_define

begin_define
define|#
directive|define
name|__WALL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|__WCLONE
value|0x80000000
end_define

begin_comment
comment|/* Linux waitid idtype  */
end_comment

begin_define
define|#
directive|define
name|LINUX_P_ALL
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_P_PID
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_P_PGID
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_LOCKS
value|RLIM_NLIMITS + 1
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_SIGPENDING
value|RLIM_NLIMITS + 2
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_MSGQUEUE
value|RLIM_NLIMITS + 3
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_NICE
value|RLIM_NLIMITS + 4
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_RTPRIO
value|RLIM_NLIMITS + 5
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_RTTIME
value|RLIM_NLIMITS + 6
end_define

begin_define
define|#
directive|define
name|LINUX_RLIM_INFINITY
value|(~0UL)
end_define

begin_function_decl
name|int
name|linux_common_wait
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|pid
parameter_list|,
name|int
modifier|*
name|status
parameter_list|,
name|int
name|options
parameter_list|,
name|struct
name|rusage
modifier|*
name|ru
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_to_bsd_waitopts
parameter_list|(
name|int
name|options
parameter_list|,
name|int
modifier|*
name|bsdopts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_set_upcall_kse
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|register_t
name|stack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_set_cloned_tls
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|void
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|linux_tdfind
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|lwpid_t
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_sysctl_debug
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MISC_H_ */
end_comment

end_unit

