begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1996 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_LINUX_LINUX_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_LINUX_LINUX_H_
end_define

begin_include
include|#
directive|include
file|<alpha/linux/linux_syscall.h>
end_include

begin_comment
comment|/*  * debugging support  */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|linux_debug_map
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ldebug
parameter_list|(
name|name
parameter_list|)
value|isclr(linux_debug_map, LINUX_SYS_linux_ ## name)
end_define

begin_define
define|#
directive|define
name|ARGS
parameter_list|(
name|nm
parameter_list|,
name|fmt
parameter_list|)
value|"linux(%ld): "#nm"("fmt")\n", (long)p->p_pid
end_define

begin_define
define|#
directive|define
name|LMSG
parameter_list|(
name|fmt
parameter_list|)
value|"linux(%ld): "fmt"\n", (long)p->p_pid
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_LINUX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|l_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|l_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|l_longlong
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|l_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|l_uint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|l_ulong
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|l_ulonglong
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|l_ushort
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|l_caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_long
name|l_clock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_int
name|l_daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_uint
name|l_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_uint
name|l_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_ushort
name|l_gid16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_uint
name|l_ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_int
name|l_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_long
name|l_loff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_uint
name|l_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_long
name|l_off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_int
name|l_pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_ulong
name|l_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_long
name|l_suseconds_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_long
name|l_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_uint
name|l_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_ushort
name|l_uid16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|l_int
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|l_fsid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|l_time_t
name|tv_sec
decl_stmt|;
name|l_suseconds_t
name|tv_usec
decl_stmt|;
block|}
name|l_timeval
typedef|;
end_typedef

begin_define
define|#
directive|define
name|l_fd_set
value|fd_set
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

begin_struct
struct|struct
name|l___sysctl_args
block|{
name|l_int
modifier|*
name|name
decl_stmt|;
name|l_int
name|nlen
decl_stmt|;
name|void
modifier|*
name|oldval
decl_stmt|;
name|l_size_t
modifier|*
name|oldlenp
decl_stmt|;
name|void
modifier|*
name|newval
decl_stmt|;
name|l_size_t
name|newlen
decl_stmt|;
name|l_ulong
name|__spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

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

begin_comment
comment|/* Resource limits */
end_comment

begin_define
define|#
directive|define
name|LINUX_RLIMIT_CPU
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_FSIZE
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_DATA
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_STACK
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_CORE
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_RSS
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_AS
value|7
end_define

begin_comment
comment|/* address space limit */
end_comment

begin_define
define|#
directive|define
name|LINUX_RLIMIT_NPROC
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_NOFILE
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_MEMLOCK
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_RLIM_NLIMITS
value|10
end_define

begin_comment
comment|/* mmap options */
end_comment

begin_define
define|#
directive|define
name|LINUX_MAP_SHARED
value|0x0001
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_PRIVATE
value|0x0002
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_ANON
value|0x0010
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_FIXED
value|0x0100
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_GROWSDOWN
value|0x1000
end_define

begin_comment
comment|/*  * stat family of syscalls  */
end_comment

begin_struct
struct|struct
name|l_timespec
block|{
name|l_ulong
name|tv_sec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l_newstat
block|{
name|l_uint
name|st_dev
decl_stmt|;
name|l_uint
name|st_ino
decl_stmt|;
name|l_uint
name|st_mode
decl_stmt|;
name|l_uint
name|st_nlink
decl_stmt|;
name|l_uint
name|st_uid
decl_stmt|;
name|l_uint
name|st_gid
decl_stmt|;
name|l_uint
name|st_rdev
decl_stmt|;
name|l_long
name|st_size
decl_stmt|;
name|struct
name|l_timespec
name|st_atimespec
decl_stmt|;
name|struct
name|l_timespec
name|st_mtimespec
decl_stmt|;
name|struct
name|l_timespec
name|st_ctimespec
decl_stmt|;
name|l_uint
name|st_blksize
decl_stmt|;
name|l_int
name|st_blocks
decl_stmt|;
name|l_uint
name|st_flags
decl_stmt|;
name|l_uint
name|st_gen
decl_stmt|;
block|}
struct|;
end_struct

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

begin_comment
comment|/*  * Signalling  */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_SIGILL
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTRAP
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_SIGABRT
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SIGIOT
value|LINUX_SIGABRT
end_define

begin_define
define|#
directive|define
name|LINUX_SIGBUS
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_SIGFPE
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_SIGUSR1
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSEGV
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_SIGUSR2
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPIPE
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_SIGALRM
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTERM
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSTKFLT
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_SIGCHLD
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_SIGCONT
value|18
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSTOP
value|19
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTSTP
value|20
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTTIN
value|21
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTTOU
value|22
end_define

begin_define
define|#
directive|define
name|LINUX_SIGURG
value|23
end_define

begin_define
define|#
directive|define
name|LINUX_SIGXCPU
value|24
end_define

begin_define
define|#
directive|define
name|LINUX_SIGXFSZ
value|25
end_define

begin_define
define|#
directive|define
name|LINUX_SIGVTALRM
value|26
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPROF
value|27
end_define

begin_define
define|#
directive|define
name|LINUX_SIGWINCH
value|28
end_define

begin_define
define|#
directive|define
name|LINUX_SIGIO
value|29
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPOLL
value|LINUX_SIGIO
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPWR
value|30
end_define

begin_define
define|#
directive|define
name|LINUX_SIGUNUSED
value|31
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTBLSZ
value|31
end_define

begin_define
define|#
directive|define
name|LINUX_NSIG_WORDS
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_NBPW
value|32
end_define

begin_define
define|#
directive|define
name|LINUX_NSIG
value|(LINUX_NBPW * LINUX_NSIG_WORDS)
end_define

begin_comment
comment|/* sigaction flags */
end_comment

begin_define
define|#
directive|define
name|LINUX_SA_ONSTACK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LINUX_SA_RESTART
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LINUX_SA_NOCLDSTOP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LINUX_SA_NODEFER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LINUX_SA_RESETHAND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LINUX_SA_NOCLDWAIT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LINUX_SA_SIGINFO
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LINUX_SA_RESTORER
value|0x04000000
end_define

begin_define
define|#
directive|define
name|LINUX_SA_INTERRUPT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|LINUX_SA_NOMASK
value|LINUX_SA_NODEFER
end_define

begin_define
define|#
directive|define
name|LINUX_SA_ONESHOT
value|LINUX_SA_RESETHAND
end_define

begin_comment
comment|/* sigprocmask actions */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIG_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_SIG_UNBLOCK
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SIG_SETMASK
value|2
end_define

begin_comment
comment|/* sigset_t macros */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIGEMPTYSET
parameter_list|(
name|set
parameter_list|)
value|(set).__bits[0] = (set).__bits[1] = 0
end_define

begin_define
define|#
directive|define
name|LINUX_SIGISMEMBER
parameter_list|(
name|set
parameter_list|,
name|sig
parameter_list|)
value|SIGISMEMBER(set, sig)
end_define

begin_define
define|#
directive|define
name|LINUX_SIGADDSET
parameter_list|(
name|set
parameter_list|,
name|sig
parameter_list|)
value|SIGADDSET(set, sig)
end_define

begin_define
define|#
directive|define
name|LINUX_MINSIGSTKSZ
value|4096
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|l_handler_t
function_decl|)
parameter_list|(
name|l_int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|l_ulong
name|l_osigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|l_uint
name|__bits
index|[
name|LINUX_NSIG_WORDS
index|]
decl_stmt|;
block|}
name|l_sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|l_handler_t
name|lsa_handler
decl_stmt|;
name|l_osigset_t
name|lsa_mask
decl_stmt|;
name|l_ulong
name|lsa_flags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|lsa_restorer
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
name|l_osigaction_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|l_handler_t
name|lsa_handler
decl_stmt|;
name|l_ulong
name|lsa_flags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|lsa_restorer
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|l_sigset_t
name|lsa_mask
decl_stmt|;
block|}
name|l_sigaction_t
typedef|;
end_typedef

begin_comment
comment|/*  * The Linux sigcontext  */
end_comment

begin_struct
struct|struct
name|l_sigcontext
block|{
name|l_long
name|sc_onstack
decl_stmt|;
name|l_long
name|sc_mask
decl_stmt|;
name|l_long
name|sc_pc
decl_stmt|;
name|l_long
name|sc_ps
decl_stmt|;
name|l_long
name|sc_regs
index|[
literal|32
index|]
decl_stmt|;
name|l_long
name|sc_ownedfp
decl_stmt|;
name|l_long
name|sc_fpregs
index|[
literal|32
index|]
decl_stmt|;
name|l_ulong
name|sc_fpcr
decl_stmt|;
name|l_ulong
name|sc_fp_control
decl_stmt|;
name|l_ulong
name|sc_reserved1
decl_stmt|,
name|sc_reserved2
decl_stmt|;
name|l_ulong
name|sc_ssize
decl_stmt|;
name|char
modifier|*
name|sc_sbase
decl_stmt|;
name|l_ulong
name|sc_traparg_a0
decl_stmt|;
name|l_ulong
name|sc_traparg_a1
decl_stmt|;
name|l_ulong
name|sc_traparg_a2
decl_stmt|;
name|l_ulong
name|sc_fp_trap_pc
decl_stmt|;
name|l_ulong
name|sc_fp_trigger_sum
decl_stmt|;
name|l_ulong
name|sc_fp_trigger_inst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * We make the stack look like Linux expects it when calling a signal  * handler, but use the BSD way of calling the handler and sigreturn().  * This means that we need to pass the pointer to the handler too.  * It is appended to the frame to not interfere with the rest of it.  */
end_comment

begin_struct
struct|struct
name|l_sigframe
block|{
name|l_int
name|sf_sig
decl_stmt|;
name|struct
name|l_sigcontext
name|sf_sc
decl_stmt|;
name|l_handler_t
name|sf_handler
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Pluggable ioctl handlers  */
end_comment

begin_struct_decl
struct_decl|struct
name|linker_set
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|linux_ioctl_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|linux_ioctl_function_t
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|linux_ioctl_args
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|linux_ioctl_handler
block|{
name|linux_ioctl_function_t
modifier|*
name|func
decl_stmt|;
name|int
name|low
decl_stmt|,
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|linux_ioctl_register_handler
parameter_list|(
name|struct
name|linux_ioctl_handler
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_ioctl_register_handlers
parameter_list|(
name|struct
name|linker_set
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_ioctl_unregister_handler
parameter_list|(
name|struct
name|linux_ioctl_handler
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_ioctl_unregister_handlers
parameter_list|(
name|struct
name|linker_set
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * open/fcntl flags  */
end_comment

begin_define
define|#
directive|define
name|LINUX_O_RDONLY
value|00
end_define

begin_define
define|#
directive|define
name|LINUX_O_WRONLY
value|01
end_define

begin_define
define|#
directive|define
name|LINUX_O_RDWR
value|02
end_define

begin_define
define|#
directive|define
name|LINUX_O_NONBLOCK
value|04
end_define

begin_define
define|#
directive|define
name|LINUX_O_APPEND
value|010
end_define

begin_define
define|#
directive|define
name|LINUX_O_CREAT
value|01000
end_define

begin_define
define|#
directive|define
name|LINUX_O_TRUNC
value|02000
end_define

begin_define
define|#
directive|define
name|LINUX_O_EXCL
value|04000
end_define

begin_define
define|#
directive|define
name|LINUX_O_NOCTTY
value|010000
end_define

begin_define
define|#
directive|define
name|LINUX_O_NDELAY
value|LINUX_O_NONBLOCK
end_define

begin_define
define|#
directive|define
name|LINUX_O_SYNC
value|040000
end_define

begin_define
define|#
directive|define
name|LINUX_FASYNC
value|020000
end_define

begin_comment
comment|/* fcntl flags */
end_comment

begin_define
define|#
directive|define
name|LINUX_F_DUPFD
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETFD
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETFD
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETFL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETFL
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETOWN
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETOWN
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETLK
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLK
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLKW
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETSIG
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETSIG
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_F_RDLCK
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_F_WRLCK
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_F_UNLCK
value|8
end_define

begin_comment
comment|/*  * mount flags  */
end_comment

begin_define
define|#
directive|define
name|LINUX_MS_RDONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|LINUX_MS_NOSUID
value|0x0002
end_define

begin_define
define|#
directive|define
name|LINUX_MS_NODEV
value|0x0004
end_define

begin_define
define|#
directive|define
name|LINUX_MS_NOEXEC
value|0x0008
end_define

begin_define
define|#
directive|define
name|LINUX_MS_REMOUNT
value|0x0020
end_define

begin_comment
comment|/*  * SystemV IPC defines  */
end_comment

begin_define
define|#
directive|define
name|LINUX_SEMOP
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SEMGET
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SEMCTL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_MSGSND
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_MSGRCV
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_MSGGET
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_MSGCTL
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_SHMAT
value|21
end_define

begin_define
define|#
directive|define
name|LINUX_SHMDT
value|22
end_define

begin_define
define|#
directive|define
name|LINUX_SHMGET
value|23
end_define

begin_define
define|#
directive|define
name|LINUX_SHMCTL
value|24
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_RMID
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_SET
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_STAT
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_INFO
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_LOCK
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_UNLOCK
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_STAT
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_INFO
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_RDONLY
value|0x1000
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_RND
value|0x2000
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_REMAP
value|0x4000
end_define

begin_comment
comment|/* semctl commands */
end_comment

begin_define
define|#
directive|define
name|LINUX_GETPID
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_GETVAL
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_GETALL
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_GETNCNT
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_GETZCNT
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_SETVAL
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_SETALL
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_SEM_STAT
value|18
end_define

begin_define
define|#
directive|define
name|LINUX_SEM_INFO
value|19
end_define

begin_union
union|union
name|l_semun
block|{
name|l_int
name|val
decl_stmt|;
name|struct
name|l_semid_ds
modifier|*
name|buf
decl_stmt|;
name|l_ushort
modifier|*
name|array
decl_stmt|;
name|struct
name|l_seminfo
modifier|*
name|__buf
decl_stmt|;
name|void
modifier|*
name|__pad
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Socket defines  */
end_comment

begin_define
define|#
directive|define
name|LINUX_SOCKET
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_BIND
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_CONNECT
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_LISTEN
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_ACCEPT
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_GETSOCKNAME
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_GETPEERNAME
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_SOCKETPAIR
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_SEND
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_RECV
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_SENDTO
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_RECVFROM
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SHUTDOWN
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_SETSOCKOPT
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_GETSOCKOPT
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_SENDMSG
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_RECVMSG
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_AF_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_AF_UNIX
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_AF_INET
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_AF_AX25
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_AF_IPX
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_AF_APPLETALK
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_SOCKET
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_IP
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_TCP
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_UDP
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_IPX
value|256
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_AX25
value|257
end_define

begin_define
define|#
directive|define
name|LINUX_SO_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SO_REUSEADDR
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SO_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_SO_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_SO_DONTROUTE
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_SO_BROADCAST
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SO_SNDBUF
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_SO_RCVBUF
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_SO_KEEPALIVE
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_SO_OOBINLINE
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_SO_NO_CHECK
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_SO_PRIORITY
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SO_LINGER
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_IP_TOS
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_IP_TTL
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_IP_HDRINCL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_IP_OPTIONS
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_IP_MULTICAST_IF
value|32
end_define

begin_define
define|#
directive|define
name|LINUX_IP_MULTICAST_TTL
value|33
end_define

begin_define
define|#
directive|define
name|LINUX_IP_MULTICAST_LOOP
value|34
end_define

begin_define
define|#
directive|define
name|LINUX_IP_ADD_MEMBERSHIP
value|35
end_define

begin_define
define|#
directive|define
name|LINUX_IP_DROP_MEMBERSHIP
value|36
end_define

begin_struct
struct|struct
name|l_sockaddr
block|{
name|l_ushort
name|sa_family
decl_stmt|;
name|char
name|sa_data
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l_ifmap
block|{
name|l_ulong
name|mem_start
decl_stmt|;
name|l_ulong
name|mem_end
decl_stmt|;
name|l_ushort
name|base_addr
decl_stmt|;
name|u_char
name|irq
decl_stmt|;
name|u_char
name|dma
decl_stmt|;
name|u_char
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LINUX_IFHWADDRLEN
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_IFNAMSIZ
value|16
end_define

begin_struct
struct|struct
name|l_ifreq
block|{
union|union
block|{
name|char
name|ifrn_name
index|[
name|LINUX_IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
block|}
name|ifr_ifrn
union|;
union|union
block|{
name|struct
name|l_sockaddr
name|ifru_addr
decl_stmt|;
name|struct
name|l_sockaddr
name|ifru_dstaddr
decl_stmt|;
name|struct
name|l_sockaddr
name|ifru_broadaddr
decl_stmt|;
name|struct
name|l_sockaddr
name|ifru_netmask
decl_stmt|;
name|struct
name|l_sockaddr
name|ifru_hwaddr
decl_stmt|;
name|l_short
name|ifru_flags
index|[
literal|1
index|]
decl_stmt|;
name|l_int
name|ifru_metric
decl_stmt|;
name|l_int
name|ifru_mtu
decl_stmt|;
name|struct
name|l_ifmap
name|ifru_map
decl_stmt|;
name|char
name|ifru_slave
index|[
name|LINUX_IFNAMSIZ
index|]
decl_stmt|;
name|l_caddr_t
name|ifru_data
decl_stmt|;
block|}
name|ifr_ifru
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ifr_name
value|ifr_ifrn.ifrn_name
end_define

begin_comment
comment|/* interface name */
end_comment

begin_define
define|#
directive|define
name|ifr_hwaddr
value|ifr_ifru.ifru_hwaddr
end_define

begin_comment
comment|/* MAC address */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|linux_sigcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linux_szsigcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sysent
name|linux_sysent
index|[
name|LINUX_SYS_MAXSYSCALL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sysentvec
name|linux_sysvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sysentvec
name|elf_linux_sysvec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dummy struct definitions */
end_comment

begin_struct_decl
struct_decl|struct
name|image_params
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * poll()  */
end_comment

begin_define
define|#
directive|define
name|LINUX_POLLIN
value|0x0001
end_define

begin_define
define|#
directive|define
name|LINUX_POLLPRI
value|0x0002
end_define

begin_define
define|#
directive|define
name|LINUX_POLLOUT
value|0x0004
end_define

begin_define
define|#
directive|define
name|LINUX_POLLERR
value|0x0008
end_define

begin_define
define|#
directive|define
name|LINUX_POLLHUP
value|0x0010
end_define

begin_define
define|#
directive|define
name|LINUX_POLLNVAL
value|0x0020
end_define

begin_define
define|#
directive|define
name|LINUX_POLLRDNORM
value|0x0040
end_define

begin_define
define|#
directive|define
name|LINUX_POLLRDBAND
value|0x0080
end_define

begin_define
define|#
directive|define
name|LINUX_POLLWRNORM
value|0x0100
end_define

begin_define
define|#
directive|define
name|LINUX_POLLWRBAND
value|0x0200
end_define

begin_define
define|#
directive|define
name|LINUX_POLLMSG
value|0x0400
end_define

begin_struct
struct|struct
name|l_pollfd
block|{
name|l_int
name|fd
decl_stmt|;
name|l_short
name|events
decl_stmt|;
name|l_short
name|revents
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ALPHA_LINUX_LINUX_H_ */
end_comment

end_unit

