begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Dmitry Chagin  * Copyright (c) 1994-1996 SÃ¸ren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AMD64_LINUX_H_
end_ifndef

begin_define
define|#
directive|define
name|_AMD64_LINUX_H_
end_define

begin_include
include|#
directive|include
file|<compat/linux/linux.h>
end_include

begin_include
include|#
directive|include
file|<amd64/linux/linux_syscall.h>
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
value|"linux(%ld/%ld): "#nm"("fmt")\n",			\ 			(long)td->td_proc->p_pid, (long)td->td_tid
end_define

begin_define
define|#
directive|define
name|LMSG
parameter_list|(
name|fmt
parameter_list|)
value|"linux(%ld/%ld): "fmt"\n",				\ 			(long)td->td_proc->p_pid, (long)td->td_tid
end_define

begin_define
define|#
directive|define
name|LINUX_DTRACE
value|linuxulator
end_define

begin_define
define|#
directive|define
name|PTRIN
parameter_list|(
name|v
parameter_list|)
value|(void *)(v)
end_define

begin_define
define|#
directive|define
name|PTROUT
parameter_list|(
name|v
parameter_list|)
value|(uintptr_t)(v)
end_define

begin_define
define|#
directive|define
name|CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|fld
parameter_list|)
value|do { (dst).fld = (src).fld; } while (0)
end_define

begin_define
define|#
directive|define
name|CP2
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|sfld
parameter_list|,
name|dfld
parameter_list|)
value|do { (dst).dfld = (src).sfld; } while (0)
end_define

begin_define
define|#
directive|define
name|PTRIN_CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|fld
parameter_list|)
define|\
value|do { (dst).fld = PTRIN((src).fld); } while (0)
end_define

begin_comment
comment|/*  * Provide a separate set of types for the Linux types.  */
end_comment

begin_typedef
typedef|typedef
name|int32_t
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
name|int16_t
name|l_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
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
name|uint16_t
name|l_ushort
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_ulong
name|l_uintptr_t
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
name|l_ulong
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
name|l_ulong
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
name|l_ssize_t
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
name|l_int
name|l_timer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_int
name|l_mqd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_size_t
name|l_socklen_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_ulong
name|l_fd_mask
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
name|LINUX_CTL_MAXNAME
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_AT_COUNT
value|19
end_define

begin_comment
comment|/* Count of used aux entry types. */
end_comment

begin_struct
struct|struct
name|l___sysctl_args
block|{
name|l_uintptr_t
name|name
decl_stmt|;
name|l_int
name|nlen
decl_stmt|;
name|l_uintptr_t
name|oldval
decl_stmt|;
name|l_uintptr_t
name|oldlenp
decl_stmt|;
name|l_uintptr_t
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
name|LINUX_RLIMIT_NPROC
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_NOFILE
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_MEMLOCK
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_RLIMIT_AS
value|9
end_define

begin_comment
comment|/* Address space limit */
end_comment

begin_define
define|#
directive|define
name|LINUX_RLIM_NLIMITS
value|10
end_define

begin_struct
struct|struct
name|l_rlimit
block|{
name|l_ulong
name|rlim_cur
decl_stmt|;
name|l_ulong
name|rlim_max
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * stat family of syscalls  */
end_comment

begin_struct
struct|struct
name|l_timespec
block|{
name|l_time_t
name|tv_sec
decl_stmt|;
name|l_long
name|tv_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l_newstat
block|{
name|l_dev_t
name|st_dev
decl_stmt|;
name|l_ino_t
name|st_ino
decl_stmt|;
name|l_ulong
name|st_nlink
decl_stmt|;
name|l_uint
name|st_mode
decl_stmt|;
name|l_uid_t
name|st_uid
decl_stmt|;
name|l_gid_t
name|st_gid
decl_stmt|;
name|l_uint
name|__st_pad1
decl_stmt|;
name|l_dev_t
name|st_rdev
decl_stmt|;
name|l_off_t
name|st_size
decl_stmt|;
name|l_long
name|st_blksize
decl_stmt|;
name|l_long
name|st_blocks
decl_stmt|;
name|struct
name|l_timespec
name|st_atim
decl_stmt|;
name|struct
name|l_timespec
name|st_mtim
decl_stmt|;
name|struct
name|l_timespec
name|st_ctim
decl_stmt|;
name|l_long
name|__unused1
decl_stmt|;
name|l_long
name|__unused2
decl_stmt|;
name|l_long
name|__unused3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sigaction flags */
end_comment

begin_define
define|#
directive|define
name|LINUX_SA_NOCLDSTOP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LINUX_SA_NOCLDWAIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LINUX_SA_SIGINFO
value|0x00000004
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
name|LINUX_SA_ONSTACK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|LINUX_SA_RESTART
value|0x10000000
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
value|0x40000000
end_define

begin_define
define|#
directive|define
name|LINUX_SA_ONESHOT
value|0x80000000
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
comment|/* sigaltstack */
end_comment

begin_define
define|#
directive|define
name|LINUX_MINSIGSTKSZ
value|2048
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
struct|struct
block|{
name|l_handler_t
name|lsa_handler
decl_stmt|;
name|l_ulong
name|lsa_flags
decl_stmt|;
name|l_uintptr_t
name|lsa_restorer
decl_stmt|;
name|l_sigset_t
name|lsa_mask
decl_stmt|;
block|}
name|l_sigaction_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|l_uintptr_t
name|ss_sp
decl_stmt|;
name|l_int
name|ss_flags
decl_stmt|;
name|l_size_t
name|ss_size
decl_stmt|;
block|}
name|l_stack_t
typedef|;
end_typedef

begin_struct
struct|struct
name|l_fpstate
block|{
name|u_int16_t
name|cwd
decl_stmt|;
name|u_int16_t
name|swd
decl_stmt|;
name|u_int16_t
name|twd
decl_stmt|;
name|u_int16_t
name|fop
decl_stmt|;
name|u_int64_t
name|rip
decl_stmt|;
name|u_int64_t
name|rdp
decl_stmt|;
name|u_int32_t
name|mxcsr
decl_stmt|;
name|u_int32_t
name|mxcsr_mask
decl_stmt|;
name|u_int32_t
name|st_space
index|[
literal|32
index|]
decl_stmt|;
name|u_int32_t
name|xmm_space
index|[
literal|64
index|]
decl_stmt|;
name|u_int32_t
name|reserved2
index|[
literal|24
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l_sigcontext
block|{
name|l_ulong
name|sc_r8
decl_stmt|;
name|l_ulong
name|sc_r9
decl_stmt|;
name|l_ulong
name|sc_r10
decl_stmt|;
name|l_ulong
name|sc_r11
decl_stmt|;
name|l_ulong
name|sc_r12
decl_stmt|;
name|l_ulong
name|sc_r13
decl_stmt|;
name|l_ulong
name|sc_r14
decl_stmt|;
name|l_ulong
name|sc_r15
decl_stmt|;
name|l_ulong
name|sc_rdi
decl_stmt|;
name|l_ulong
name|sc_rsi
decl_stmt|;
name|l_ulong
name|sc_rbp
decl_stmt|;
name|l_ulong
name|sc_rbx
decl_stmt|;
name|l_ulong
name|sc_rdx
decl_stmt|;
name|l_ulong
name|sc_rax
decl_stmt|;
name|l_ulong
name|sc_rcx
decl_stmt|;
name|l_ulong
name|sc_rsp
decl_stmt|;
name|l_ulong
name|sc_rip
decl_stmt|;
name|l_ulong
name|sc_rflags
decl_stmt|;
name|l_ushort
name|sc_cs
decl_stmt|;
name|l_ushort
name|sc_gs
decl_stmt|;
name|l_ushort
name|sc_fs
decl_stmt|;
name|l_ushort
name|sc___pad0
decl_stmt|;
name|l_ulong
name|sc_err
decl_stmt|;
name|l_ulong
name|sc_trapno
decl_stmt|;
name|l_sigset_t
name|sc_mask
decl_stmt|;
name|l_ulong
name|sc_cr2
decl_stmt|;
name|struct
name|l_fpstate
modifier|*
name|sc_fpstate
decl_stmt|;
name|l_ulong
name|sc_reserved1
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l_ucontext
block|{
name|l_ulong
name|uc_flags
decl_stmt|;
name|l_uintptr_t
name|uc_link
decl_stmt|;
name|l_stack_t
name|uc_stack
decl_stmt|;
name|struct
name|l_sigcontext
name|uc_mcontext
decl_stmt|;
name|l_sigset_t
name|uc_sigmask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LINUX_SI_PREAMBLE_SIZE
value|(4 * sizeof(int))
end_define

begin_define
define|#
directive|define
name|LINUX_SI_MAX_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|LINUX_SI_PAD_SIZE
value|((LINUX_SI_MAX_SIZE - \ 				    LINUX_SI_PREAMBLE_SIZE) / sizeof(l_int))
end_define

begin_typedef
typedef|typedef
union|union
name|l_sigval
block|{
name|l_int
name|sival_int
decl_stmt|;
name|l_uintptr_t
name|sival_ptr
decl_stmt|;
block|}
name|l_sigval_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|l_siginfo
block|{
name|l_int
name|lsi_signo
decl_stmt|;
name|l_int
name|lsi_errno
decl_stmt|;
name|l_int
name|lsi_code
decl_stmt|;
union|union
block|{
name|l_int
name|_pad
index|[
name|LINUX_SI_PAD_SIZE
index|]
decl_stmt|;
struct|struct
block|{
name|l_pid_t
name|_pid
decl_stmt|;
name|l_uid_t
name|_uid
decl_stmt|;
block|}
name|_kill
struct|;
struct|struct
block|{
name|l_timer_t
name|_tid
decl_stmt|;
name|l_int
name|_overrun
decl_stmt|;
name|char
name|_pad
index|[
sizeof|sizeof
argument_list|(
name|l_uid_t
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
name|union
name|l_sigval
name|_sigval
decl_stmt|;
name|l_uint
name|_sys_private
decl_stmt|;
block|}
name|_timer
struct|;
struct|struct
block|{
name|l_pid_t
name|_pid
decl_stmt|;
comment|/* sender's pid */
name|l_uid_t
name|_uid
decl_stmt|;
comment|/* sender's uid */
name|union
name|l_sigval
name|_sigval
decl_stmt|;
block|}
name|_rt
struct|;
struct|struct
block|{
name|l_pid_t
name|_pid
decl_stmt|;
comment|/* which child */
name|l_uid_t
name|_uid
decl_stmt|;
comment|/* sender's uid */
name|l_int
name|_status
decl_stmt|;
comment|/* exit code */
name|l_clock_t
name|_utime
decl_stmt|;
name|l_clock_t
name|_stime
decl_stmt|;
block|}
name|_sigchld
struct|;
struct|struct
block|{
name|l_uintptr_t
name|_addr
decl_stmt|;
comment|/* Faulting insn/memory ref. */
block|}
name|_sigfault
struct|;
struct|struct
block|{
name|l_long
name|_band
decl_stmt|;
comment|/* POLL_IN,POLL_OUT,POLL_MSG */
name|l_int
name|_fd
decl_stmt|;
block|}
name|_sigpoll
struct|;
block|}
name|_sifields
union|;
block|}
name|l_siginfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lsi_pid
value|_sifields._kill._pid
end_define

begin_define
define|#
directive|define
name|lsi_uid
value|_sifields._kill._uid
end_define

begin_define
define|#
directive|define
name|lsi_tid
value|_sifields._timer._tid
end_define

begin_define
define|#
directive|define
name|lsi_overrun
value|_sifields._timer._overrun
end_define

begin_define
define|#
directive|define
name|lsi_sys_private
value|_sifields._timer._sys_private
end_define

begin_define
define|#
directive|define
name|lsi_status
value|_sifields._sigchld._status
end_define

begin_define
define|#
directive|define
name|lsi_utime
value|_sifields._sigchld._utime
end_define

begin_define
define|#
directive|define
name|lsi_stime
value|_sifields._sigchld._stime
end_define

begin_define
define|#
directive|define
name|lsi_value
value|_sifields._rt._sigval
end_define

begin_define
define|#
directive|define
name|lsi_int
value|_sifields._rt._sigval.sival_int
end_define

begin_define
define|#
directive|define
name|lsi_ptr
value|_sifields._rt._sigval.sival_ptr
end_define

begin_define
define|#
directive|define
name|lsi_addr
value|_sifields._sigfault._addr
end_define

begin_define
define|#
directive|define
name|lsi_band
value|_sifields._sigpoll._band
end_define

begin_define
define|#
directive|define
name|lsi_fd
value|_sifields._sigpoll._fd
end_define

begin_comment
comment|/*  * We make the stack look like Linux expects it when calling a signal  * handler, but use the BSD way of calling the handler and sigreturn().  * This means that we need to pass the pointer to the handler too.  * It is appended to the frame to not interfere with the rest of it.  */
end_comment

begin_struct
struct|struct
name|l_rt_sigframe
block|{
name|struct
name|l_ucontext
name|sf_sc
decl_stmt|;
name|struct
name|l_siginfo
name|sf_si
decl_stmt|;
name|l_handler_t
name|sf_handler
decl_stmt|;
block|}
struct|;
end_struct

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
name|l_uintptr_t
name|buf
decl_stmt|;
name|l_uintptr_t
name|array
decl_stmt|;
name|l_uintptr_t
name|__buf
decl_stmt|;
name|l_uintptr_t
name|__pad
decl_stmt|;
block|}
union|;
end_union

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
name|__packed
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
name|ifru_ivalue
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
name|l_uintptr_t
name|ifru_data
decl_stmt|;
block|}
name|ifr_ifru
union|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|ifr_name
value|ifr_ifrn.ifrn_name
end_define

begin_comment
comment|/* Interface name */
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

begin_define
define|#
directive|define
name|ifr_ifindex
value|ifr_ifru.ifru_ivalue
end_define

begin_comment
comment|/* Interface index */
end_comment

begin_struct
struct|struct
name|l_ifconf
block|{
name|int
name|ifc_len
decl_stmt|;
union|union
block|{
name|l_uintptr_t
name|ifcu_buf
decl_stmt|;
name|l_uintptr_t
name|ifcu_req
decl_stmt|;
block|}
name|ifc_ifcu
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ifc_buf
value|ifc_ifcu.ifcu_buf
end_define

begin_define
define|#
directive|define
name|ifc_req
value|ifc_ifcu.ifcu_req
end_define

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

begin_define
define|#
directive|define
name|LINUX_ARCH_SET_GS
value|0x1001
end_define

begin_define
define|#
directive|define
name|LINUX_ARCH_SET_FS
value|0x1002
end_define

begin_define
define|#
directive|define
name|LINUX_ARCH_GET_FS
value|0x1003
end_define

begin_define
define|#
directive|define
name|LINUX_ARCH_GET_GS
value|0x1004
end_define

begin_define
define|#
directive|define
name|linux_copyout_rusage
parameter_list|(
name|r
parameter_list|,
name|u
parameter_list|)
value|copyout(r, u, sizeof(*r))
end_define

begin_comment
comment|/* robust futexes */
end_comment

begin_struct
struct|struct
name|linux_robust_list
block|{
name|l_uintptr_t
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_robust_list_head
block|{
name|struct
name|linux_robust_list
name|list
decl_stmt|;
name|l_long
name|futex_offset
decl_stmt|;
name|l_uintptr_t
name|pending_list
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AMD64_LINUX_H_ */
end_comment

end_unit

