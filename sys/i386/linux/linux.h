begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1996 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_LINUX_LINUX_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_LINUX_LINUX_H_
end_define

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_comment
comment|/* for sigval union */
end_comment

begin_include
include|#
directive|include
file|<i386/linux/linux_syscall.h>
end_include

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
comment|/* address space limit */
end_comment

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
name|LINUX_MAP_FIXED
value|0x0010
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_ANON
value|0x0020
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_GROWSDOWN
value|0x0100
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|linux_caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|linux_clock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|linux_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|linux_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|linux_ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|linux_key_t
typedef|;
end_typedef

begin_comment
comment|/* XXX */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|linux_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|linux_nlink_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|linux_off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|linux_pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|linux_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|linux_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|linux_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|linux_fsid_t
typedef|;
end_typedef

begin_struct
struct|struct
name|linux_new_utsname
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

begin_comment
comment|/* sigaltstack */
end_comment

begin_define
define|#
directive|define
name|LINUX_MINSIGSTKSZ
value|2048
end_define

begin_define
define|#
directive|define
name|LINUX_SS_ONSTACK
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SS_DISABLE
value|2
end_define

begin_function_decl
name|int
name|linux_to_bsd_sigaltstack
parameter_list|(
name|int
name|lsa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bsd_to_linux_sigaltstack
parameter_list|(
name|int
name|bsa
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|linux_handler_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|linux_osigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|__bits
index|[
name|LINUX_NSIG_WORDS
index|]
decl_stmt|;
block|}
name|linux_sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|linux_handler_t
name|lsa_handler
decl_stmt|;
name|linux_osigset_t
name|lsa_mask
decl_stmt|;
name|u_long
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
name|linux_osigaction_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|linux_handler_t
name|lsa_handler
decl_stmt|;
name|u_long
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
name|linux_sigset_t
name|lsa_mask
decl_stmt|;
block|}
name|linux_sigaction_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|ss_sp
decl_stmt|;
name|int
name|ss_flags
decl_stmt|;
name|linux_size_t
name|ss_size
decl_stmt|;
block|}
name|linux_stack_t
typedef|;
end_typedef

begin_comment
comment|/* The Linux sigcontext, pretty much a standard 386 trapframe. */
end_comment

begin_struct
struct|struct
name|linux_sigcontext
block|{
name|int
name|sc_gs
decl_stmt|;
name|int
name|sc_fs
decl_stmt|;
name|int
name|sc_es
decl_stmt|;
name|int
name|sc_ds
decl_stmt|;
name|int
name|sc_edi
decl_stmt|;
name|int
name|sc_esi
decl_stmt|;
name|int
name|sc_ebp
decl_stmt|;
name|int
name|sc_esp
decl_stmt|;
name|int
name|sc_ebx
decl_stmt|;
name|int
name|sc_edx
decl_stmt|;
name|int
name|sc_ecx
decl_stmt|;
name|int
name|sc_eax
decl_stmt|;
name|int
name|sc_trapno
decl_stmt|;
name|int
name|sc_err
decl_stmt|;
name|int
name|sc_eip
decl_stmt|;
name|int
name|sc_cs
decl_stmt|;
name|int
name|sc_eflags
decl_stmt|;
name|int
name|sc_esp_at_signal
decl_stmt|;
name|int
name|sc_ss
decl_stmt|;
name|int
name|sc_387
decl_stmt|;
name|int
name|sc_mask
decl_stmt|;
name|int
name|sc_cr2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_ucontext
block|{
name|unsigned
name|long
name|uc_flags
decl_stmt|;
name|void
modifier|*
name|uc_link
decl_stmt|;
name|linux_stack_t
name|uc_stack
decl_stmt|;
name|struct
name|linux_sigcontext
name|uc_mcontext
decl_stmt|;
name|linux_sigset_t
name|uc_sigmask
decl_stmt|;
block|}
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
value|((LINUX_SI_MAX_SIZE/sizeof(int)) - 3)
end_define

begin_typedef
typedef|typedef
struct|struct
name|siginfo
block|{
name|int
name|lsi_signo
decl_stmt|;
name|int
name|lsi_errno
decl_stmt|;
name|int
name|lsi_code
decl_stmt|;
union|union
block|{
name|int
name|_pad
index|[
name|LINUX_SI_PAD_SIZE
index|]
decl_stmt|;
struct|struct
block|{
name|linux_pid_t
name|_pid
decl_stmt|;
name|linux_uid_t
name|_uid
decl_stmt|;
block|}
name|_kill
struct|;
struct|struct
block|{
name|unsigned
name|int
name|_timer1
decl_stmt|;
name|unsigned
name|int
name|_timer2
decl_stmt|;
block|}
name|_timer
struct|;
struct|struct
block|{
name|linux_pid_t
name|_pid
decl_stmt|;
comment|/* sender's pid */
name|linux_uid_t
name|_uid
decl_stmt|;
comment|/* sender's uid */
name|union
name|sigval
name|_sigval
decl_stmt|;
block|}
name|_rt
struct|;
struct|struct
block|{
name|linux_pid_t
name|_pid
decl_stmt|;
comment|/* which child */
name|linux_uid_t
name|_uid
decl_stmt|;
comment|/* sender's uid */
name|int
name|_status
decl_stmt|;
comment|/* exit code */
name|linux_clock_t
name|_utime
decl_stmt|;
name|linux_clock_t
name|_stime
decl_stmt|;
block|}
name|_sigchld
struct|;
struct|struct
block|{
name|void
modifier|*
name|_addr
decl_stmt|;
comment|/* faulting insn/memory ref. */
block|}
name|_sigfault
struct|;
struct|struct
block|{
name|int
name|_band
decl_stmt|;
comment|/* POLL_IN, POLL_OUT, POLL_MSG */
name|int
name|_fd
decl_stmt|;
block|}
name|_sigpoll
struct|;
block|}
name|_sifields
union|;
block|}
name|linux_siginfo_t
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
name|linux_fpreg
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
struct|;
end_struct

begin_struct
struct|struct
name|linux_fpxreg
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
struct|;
end_struct

begin_struct
struct|struct
name|linux_xmmreg
block|{
name|u_int32_t
name|element
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_fpstate
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
name|linux_fpreg
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
comment|/* env is ignored */
name|u_int32_t
name|mxcsr
decl_stmt|;
name|u_int32_t
name|reserved
decl_stmt|;
name|struct
name|linux_fpxreg
name|_fxsr_st
index|[
literal|8
index|]
decl_stmt|;
comment|/* reg data is ignored */
name|struct
name|linux_xmmreg
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
struct|;
end_struct

begin_comment
comment|/*  * We make the stack look like Linux expects it when calling a signal  * handler, but use the BSD way of calling the handler and sigreturn().  * This means that we need to pass the pointer to the handler too.  * It is appended to the frame to not interfere with the rest of it.  */
end_comment

begin_struct
struct|struct
name|linux_sigframe
block|{
name|int
name|sf_sig
decl_stmt|;
name|struct
name|linux_sigcontext
name|sf_sc
decl_stmt|;
name|struct
name|linux_fpstate
name|sf_fpstate
decl_stmt|;
name|u_int
name|sf_extramask
index|[
name|LINUX_NSIG_WORDS
operator|-
literal|1
index|]
decl_stmt|;
name|linux_handler_t
name|sf_handler
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linux_rt_sigframe
block|{
name|int
name|sf_sig
decl_stmt|;
name|linux_siginfo_t
modifier|*
name|sf_siginfo
decl_stmt|;
name|struct
name|linux_ucontext
modifier|*
name|sf_ucontext
decl_stmt|;
name|linux_siginfo_t
name|sf_si
decl_stmt|;
name|struct
name|linux_ucontext
name|sf_sc
decl_stmt|;
name|linux_handler_t
name|sf_handler
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|bsd_to_linux_signal
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linux_to_bsd_signal
index|[]
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
name|LINUX_O_CREAT
value|0100
end_define

begin_define
define|#
directive|define
name|LINUX_O_EXCL
value|0200
end_define

begin_define
define|#
directive|define
name|LINUX_O_NOCTTY
value|0400
end_define

begin_define
define|#
directive|define
name|LINUX_O_TRUNC
value|01000
end_define

begin_define
define|#
directive|define
name|LINUX_O_APPEND
value|02000
end_define

begin_define
define|#
directive|define
name|LINUX_O_NONBLOCK
value|04000
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
value|010000
end_define

begin_define
define|#
directive|define
name|LINUX_FASYNC
value|020000
end_define

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
name|LINUX_F_GETLK
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLK
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLKW
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETOWN
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETOWN
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_F_RDLCK
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_F_WRLCK
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_F_UNLCK
value|2
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
name|linux_sockaddr
block|{
name|u_short
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
name|linux_ifmap
block|{
name|u_long
name|mem_start
decl_stmt|;
name|u_long
name|mem_end
decl_stmt|;
name|u_short
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
name|linux_ifreq
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
name|linux_sockaddr
name|ifru_addr
decl_stmt|;
name|struct
name|linux_sockaddr
name|ifru_dstaddr
decl_stmt|;
name|struct
name|linux_sockaddr
name|ifru_broadaddr
decl_stmt|;
name|struct
name|linux_sockaddr
name|ifru_netmask
decl_stmt|;
name|struct
name|linux_sockaddr
name|ifru_hwaddr
decl_stmt|;
name|short
name|ifru_flags
decl_stmt|;
name|int
name|ifru_metric
decl_stmt|;
name|int
name|ifru_mtu
decl_stmt|;
name|struct
name|linux_ifmap
name|ifru_map
decl_stmt|;
name|char
name|ifru_slave
index|[
name|LINUX_IFNAMSIZ
index|]
decl_stmt|;
comment|/* Just fits the size */
name|linux_caddr_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_LINUX_LINUX_H_ */
end_comment

end_unit

