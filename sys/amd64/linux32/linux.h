begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Tim J. Robbins  * Copyright (c) 2001 Doug Rabson  * Copyright (c) 1994-1996 SÃ¸ren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<amd64/linux32/linux32_syscall.h>
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
value|isclr(linux_debug_map, LINUX32_SYS_linux_ ## name)
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
value|linuxulator32
end_define

begin_define
define|#
directive|define
name|LINUX32_MAXUSER
value|((1ul<< 32) - PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|LINUX32_SHAREDPAGE
value|(LINUX32_MAXUSER - PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|LINUX32_USRSTACK
value|LINUX32_SHAREDPAGE
end_define

begin_comment
comment|/* XXX 16 = sizeof(linux32_ps_strings) */
end_comment

begin_define
define|#
directive|define
name|LINUX32_PS_STRINGS
value|(LINUX32_USRSTACK - 16)
end_define

begin_define
define|#
directive|define
name|LINUX32_MAXDSIZ
value|(512 * 1024 * 1024)
end_define

begin_comment
comment|/* 512MB */
end_comment

begin_define
define|#
directive|define
name|LINUX32_MAXSSIZ
value|(64 * 1024 * 1024)
end_define

begin_comment
comment|/* 64MB */
end_comment

begin_define
define|#
directive|define
name|LINUX32_MAXVMEM
value|0
end_define

begin_comment
comment|/* Unlimited */
end_comment

begin_define
define|#
directive|define
name|PTRIN
parameter_list|(
name|v
parameter_list|)
value|(void *)(uintptr_t)(v)
end_define

begin_define
define|#
directive|define
name|PTROUT
parameter_list|(
name|v
parameter_list|)
value|(l_uintptr_t)(uintptr_t)(v)
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
name|int
name|l_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
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
name|uint32_t
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
name|l_ushort
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
name|l_longlong
name|l_loff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|l_ushort
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
name|l_uint
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
name|__packed
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
name|LINUX_AT_COUNT
value|20
end_define

begin_comment
comment|/* Count of used aux entry types. 					 * Keep this synchronized with 					 * elf_linux_fixup() code. 					 */
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
name|__packed
struct|;
end_struct

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
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_rusage
block|{
name|l_timeval
name|ru_utime
decl_stmt|;
name|l_timeval
name|ru_stime
decl_stmt|;
name|l_long
name|ru_maxrss
decl_stmt|;
name|l_long
name|ru_ixrss
decl_stmt|;
name|l_long
name|ru_idrss
decl_stmt|;
name|l_long
name|ru_isrss
decl_stmt|;
name|l_long
name|ru_minflt
decl_stmt|;
name|l_long
name|ru_majflt
decl_stmt|;
name|l_long
name|ru_nswap
decl_stmt|;
name|l_long
name|ru_inblock
decl_stmt|;
name|l_long
name|ru_oublock
decl_stmt|;
name|l_long
name|ru_msgsnd
decl_stmt|;
name|l_long
name|ru_msgrcv
decl_stmt|;
name|l_long
name|ru_nsignals
decl_stmt|;
name|l_long
name|ru_nvcsw
decl_stmt|;
name|l_long
name|ru_nivcsw
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_mmap_argv
block|{
name|l_uintptr_t
name|addr
decl_stmt|;
name|l_size_t
name|len
decl_stmt|;
name|l_int
name|prot
decl_stmt|;
name|l_int
name|flags
decl_stmt|;
name|l_int
name|fd
decl_stmt|;
name|l_ulong
name|pgoff
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
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_newstat
block|{
name|l_ushort
name|st_dev
decl_stmt|;
name|l_ushort
name|__pad1
decl_stmt|;
name|l_ulong
name|st_ino
decl_stmt|;
name|l_ushort
name|st_mode
decl_stmt|;
name|l_ushort
name|st_nlink
decl_stmt|;
name|l_ushort
name|st_uid
decl_stmt|;
name|l_ushort
name|st_gid
decl_stmt|;
name|l_ushort
name|st_rdev
decl_stmt|;
name|l_ushort
name|__pad2
decl_stmt|;
name|l_ulong
name|st_size
decl_stmt|;
name|l_ulong
name|st_blksize
decl_stmt|;
name|l_ulong
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
name|l_ulong
name|__unused4
decl_stmt|;
name|l_ulong
name|__unused5
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_stat
block|{
name|l_ushort
name|st_dev
decl_stmt|;
name|l_ulong
name|st_ino
decl_stmt|;
name|l_ushort
name|st_mode
decl_stmt|;
name|l_ushort
name|st_nlink
decl_stmt|;
name|l_ushort
name|st_uid
decl_stmt|;
name|l_ushort
name|st_gid
decl_stmt|;
name|l_ushort
name|st_rdev
decl_stmt|;
name|l_long
name|st_size
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
name|st_blksize
decl_stmt|;
name|l_long
name|st_blocks
decl_stmt|;
name|l_ulong
name|st_flags
decl_stmt|;
name|l_ulong
name|st_gen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l_stat64
block|{
name|l_ushort
name|st_dev
decl_stmt|;
name|u_char
name|__pad0
index|[
literal|10
index|]
decl_stmt|;
name|l_ulong
name|__st_ino
decl_stmt|;
name|l_uint
name|st_mode
decl_stmt|;
name|l_uint
name|st_nlink
decl_stmt|;
name|l_ulong
name|st_uid
decl_stmt|;
name|l_ulong
name|st_gid
decl_stmt|;
name|l_ushort
name|st_rdev
decl_stmt|;
name|u_char
name|__pad3
index|[
literal|10
index|]
decl_stmt|;
name|l_longlong
name|st_size
decl_stmt|;
name|l_ulong
name|st_blksize
decl_stmt|;
name|l_ulong
name|st_blocks
decl_stmt|;
name|l_ulong
name|__pad4
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
name|l_ulonglong
name|st_ino
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_statfs64
block|{
name|l_int
name|f_type
decl_stmt|;
name|l_int
name|f_bsize
decl_stmt|;
name|uint64_t
name|f_blocks
decl_stmt|;
name|uint64_t
name|f_bfree
decl_stmt|;
name|uint64_t
name|f_bavail
decl_stmt|;
name|uint64_t
name|f_files
decl_stmt|;
name|uint64_t
name|f_ffree
decl_stmt|;
name|l_fsid_t
name|f_fsid
decl_stmt|;
name|l_int
name|f_namelen
decl_stmt|;
name|l_int
name|f_frsize
decl_stmt|;
name|l_int
name|f_flags
decl_stmt|;
name|l_int
name|f_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
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
name|l_uintptr_t
name|l_handler_t
typedef|;
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
name|l_handler_t
name|lsa_handler
decl_stmt|;
name|l_osigset_t
name|lsa_mask
decl_stmt|;
name|l_ulong
name|lsa_flags
decl_stmt|;
name|l_uintptr_t
name|lsa_restorer
decl_stmt|;
block|}
name|__packed
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
name|l_uintptr_t
name|lsa_restorer
decl_stmt|;
name|l_sigset_t
name|lsa_mask
decl_stmt|;
block|}
name|__packed
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
name|__packed
name|l_stack_t
typedef|;
end_typedef

begin_comment
comment|/* The Linux sigcontext, pretty much a standard 386 trapframe. */
end_comment

begin_struct
struct|struct
name|l_sigcontext
block|{
name|l_uint
name|sc_gs
decl_stmt|;
name|l_uint
name|sc_fs
decl_stmt|;
name|l_uint
name|sc_es
decl_stmt|;
name|l_uint
name|sc_ds
decl_stmt|;
name|l_uint
name|sc_edi
decl_stmt|;
name|l_uint
name|sc_esi
decl_stmt|;
name|l_uint
name|sc_ebp
decl_stmt|;
name|l_uint
name|sc_esp
decl_stmt|;
name|l_uint
name|sc_ebx
decl_stmt|;
name|l_uint
name|sc_edx
decl_stmt|;
name|l_uint
name|sc_ecx
decl_stmt|;
name|l_uint
name|sc_eax
decl_stmt|;
name|l_uint
name|sc_trapno
decl_stmt|;
name|l_uint
name|sc_err
decl_stmt|;
name|l_uint
name|sc_eip
decl_stmt|;
name|l_uint
name|sc_cs
decl_stmt|;
name|l_uint
name|sc_eflags
decl_stmt|;
name|l_uint
name|sc_esp_at_signal
decl_stmt|;
name|l_uint
name|sc_ss
decl_stmt|;
name|l_uint
name|sc_387
decl_stmt|;
name|l_uint
name|sc_mask
decl_stmt|;
name|l_uint
name|sc_cr2
decl_stmt|;
block|}
name|__packed
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
name|__packed
struct|;
end_struct

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
value|((LINUX_SI_MAX_SIZE/sizeof(l_int)) - 3)
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
name|__packed
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
name|l_int
argument_list|)
index|]
decl_stmt|;
name|l_sigval_t
name|_sigval
decl_stmt|;
name|l_int
name|_sys_private
decl_stmt|;
block|}
name|__packed
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
name|l_sigval_t
name|_sigval
decl_stmt|;
block|}
name|__packed
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
name|__packed
name|_sigchld
struct|;
struct|struct
block|{
name|l_uintptr_t
name|_addr
decl_stmt|;
comment|/* Faulting insn/memory ref. */
block|}
name|__packed
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
name|__packed
name|_sigpoll
struct|;
block|}
name|_sifields
union|;
block|}
name|__packed
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

begin_struct
struct|struct
name|l_fpreg
block|{
name|u_int16_t
name|significand
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|exponent
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_fpxreg
block|{
name|u_int16_t
name|significand
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|exponent
decl_stmt|;
name|u_int16_t
name|padding
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_xmmreg
block|{
name|u_int32_t
name|element
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_fpstate
block|{
comment|/* Regular FPU environment */
name|u_int32_t
name|cw
decl_stmt|;
name|u_int32_t
name|sw
decl_stmt|;
name|u_int32_t
name|tag
decl_stmt|;
name|u_int32_t
name|ipoff
decl_stmt|;
name|u_int32_t
name|cssel
decl_stmt|;
name|u_int32_t
name|dataoff
decl_stmt|;
name|u_int32_t
name|datasel
decl_stmt|;
name|struct
name|l_fpreg
name|_st
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|status
decl_stmt|;
name|u_int16_t
name|magic
decl_stmt|;
comment|/* 0xffff = regular FPU data */
comment|/* FXSR FPU environment */
name|u_int32_t
name|_fxsr_env
index|[
literal|6
index|]
decl_stmt|;
comment|/* env is ignored. */
name|u_int32_t
name|mxcsr
decl_stmt|;
name|u_int32_t
name|reserved
decl_stmt|;
name|struct
name|l_fpxreg
name|_fxsr_st
index|[
literal|8
index|]
decl_stmt|;
comment|/* reg data is ignored. */
name|struct
name|l_xmmreg
name|_xmm
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|padding
index|[
literal|56
index|]
decl_stmt|;
block|}
name|__packed
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
name|struct
name|l_fpstate
name|sf_fpstate
decl_stmt|;
name|l_uint
name|sf_extramask
index|[
literal|1
index|]
decl_stmt|;
name|l_handler_t
name|sf_handler
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_rt_sigframe
block|{
name|l_int
name|sf_sig
decl_stmt|;
name|l_uintptr_t
name|sf_siginfo
decl_stmt|;
name|l_uintptr_t
name|sf_ucontext
decl_stmt|;
name|l_siginfo_t
name|sf_si
decl_stmt|;
name|struct
name|l_ucontext
name|sf_sc
decl_stmt|;
name|l_handler_t
name|sf_handler
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * arch specific open/fcntl flags  */
end_comment

begin_define
define|#
directive|define
name|LINUX_F_GETLK64
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLK64
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLKW64
value|14
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
name|__packed
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
name|__packed
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
name|__packed
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
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|l_user_desc
block|{
name|l_uint
name|entry_number
decl_stmt|;
name|l_uint
name|base_addr
decl_stmt|;
name|l_uint
name|limit
decl_stmt|;
name|l_uint
name|seg_32bit
range|:
literal|1
decl_stmt|;
name|l_uint
name|contents
range|:
literal|2
decl_stmt|;
name|l_uint
name|read_exec_only
range|:
literal|1
decl_stmt|;
name|l_uint
name|limit_in_pages
range|:
literal|1
decl_stmt|;
name|l_uint
name|seg_not_present
range|:
literal|1
decl_stmt|;
name|l_uint
name|useable
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LINUX_LOWERWORD
value|0x0000ffff
end_define

begin_comment
comment|/*  * Macros which does the same thing as those in Linux include/asm-um/ldt-i386.h.  * These convert Linux user space descriptor to machine one.  */
end_comment

begin_define
define|#
directive|define
name|LINUX_LDT_entry_a
parameter_list|(
name|info
parameter_list|)
define|\
value|((((info)->base_addr& LINUX_LOWERWORD)<< 16) |	\ 	((info)->limit& LINUX_LOWERWORD))
end_define

begin_define
define|#
directive|define
name|LINUX_ENTRY_B_READ_EXEC_ONLY
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_ENTRY_B_CONTENTS
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_ENTRY_B_SEG_NOT_PRESENT
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_ENTRY_B_BASE_ADDR
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_ENTRY_B_USEABLE
value|20
end_define

begin_define
define|#
directive|define
name|LINUX_ENTRY_B_SEG32BIT
value|22
end_define

begin_define
define|#
directive|define
name|LINUX_ENTRY_B_LIMIT
value|23
end_define

begin_define
define|#
directive|define
name|LINUX_LDT_entry_b
parameter_list|(
name|info
parameter_list|)
define|\
value|(((info)->base_addr& 0xff000000) |					\ 	((info)->limit& 0xf0000) |						\ 	((info)->contents<< LINUX_ENTRY_B_CONTENTS) |				\ 	(((info)->seg_not_present == 0)<< LINUX_ENTRY_B_SEG_NOT_PRESENT) |	\ 	(((info)->base_addr& 0x00ff0000)>> LINUX_ENTRY_B_BASE_ADDR) |		\ 	(((info)->read_exec_only == 0)<< LINUX_ENTRY_B_READ_EXEC_ONLY) |	\ 	((info)->seg_32bit<< LINUX_ENTRY_B_SEG32BIT) |				\ 	((info)->useable<< LINUX_ENTRY_B_USEABLE) |				\ 	((info)->limit_in_pages<< LINUX_ENTRY_B_LIMIT) | 0x7000)
end_define

begin_define
define|#
directive|define
name|LINUX_LDT_empty
parameter_list|(
name|info
parameter_list|)
define|\
value|((info)->base_addr == 0&&	\ 	(info)->limit == 0&&		\ 	(info)->contents == 0&&	\ 	(info)->seg_not_present == 1&&	\ 	(info)->read_exec_only == 1&&	\ 	(info)->seg_32bit == 0&&	\ 	(info)->limit_in_pages == 0&&	\ 	(info)->useable == 0)
end_define

begin_comment
comment|/*  * Macros for converting segments.  * They do the same as those in arch/i386/kernel/process.c in Linux.  */
end_comment

begin_define
define|#
directive|define
name|LINUX_GET_BASE
parameter_list|(
name|desc
parameter_list|)
define|\
value|((((desc)->a>> 16)& LINUX_LOWERWORD) |	\ 	(((desc)->b<< 16)& 0x00ff0000) |		\ 	((desc)->b& 0xff000000))
end_define

begin_define
define|#
directive|define
name|LINUX_GET_LIMIT
parameter_list|(
name|desc
parameter_list|)
define|\
value|(((desc)->a& LINUX_LOWERWORD) |	\ 	((desc)->b& 0xf0000))
end_define

begin_define
define|#
directive|define
name|LINUX_GET_32BIT
parameter_list|(
name|desc
parameter_list|)
define|\
value|(((desc)->b>> LINUX_ENTRY_B_SEG32BIT)& 1)
end_define

begin_define
define|#
directive|define
name|LINUX_GET_CONTENTS
parameter_list|(
name|desc
parameter_list|)
define|\
value|(((desc)->b>> LINUX_ENTRY_B_CONTENTS)& 3)
end_define

begin_define
define|#
directive|define
name|LINUX_GET_WRITABLE
parameter_list|(
name|desc
parameter_list|)
define|\
value|(((desc)->b>> LINUX_ENTRY_B_READ_EXEC_ONLY)& 1)
end_define

begin_define
define|#
directive|define
name|LINUX_GET_LIMIT_PAGES
parameter_list|(
name|desc
parameter_list|)
define|\
value|(((desc)->b>> LINUX_ENTRY_B_LIMIT)& 1)
end_define

begin_define
define|#
directive|define
name|LINUX_GET_PRESENT
parameter_list|(
name|desc
parameter_list|)
define|\
value|(((desc)->b>> LINUX_ENTRY_B_SEG_NOT_PRESENT)& 1)
end_define

begin_define
define|#
directive|define
name|LINUX_GET_USEABLE
parameter_list|(
name|desc
parameter_list|)
define|\
value|(((desc)->b>> LINUX_ENTRY_B_USEABLE)& 1)
end_define

begin_struct_decl
struct_decl|struct
name|iovec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|l_iovec32
block|{
name|uint32_t
name|iov_base
decl_stmt|;
name|l_size_t
name|iov_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|linux32_copyiniov
parameter_list|(
name|struct
name|l_iovec32
modifier|*
name|iovp32
parameter_list|,
name|l_ulong
name|iovcnt
parameter_list|,
name|struct
name|iovec
modifier|*
modifier|*
name|iovp
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux32_copyinuio
parameter_list|(
name|struct
name|l_iovec32
modifier|*
name|iovp
parameter_list|,
name|l_ulong
name|iovcnt
parameter_list|,
name|struct
name|uio
modifier|*
modifier|*
name|uiop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_copyout_rusage
parameter_list|(
name|struct
name|rusage
modifier|*
name|ru
parameter_list|,
name|void
modifier|*
name|uaddr
parameter_list|)
function_decl|;
end_function_decl

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

