begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1995 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<i386/linux/linux.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/imgact.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_function_decl
specifier|extern
name|int
name|access
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acct
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_adjtimex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_alarm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_bdflush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_break
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_brk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|chdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|chmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|chown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|chroot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_clone
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_creat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_create_module
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_delete_module
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dup2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|execve
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fchdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fchmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fchown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_fcntl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_fork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_fstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_fstatfs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fsync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_ftime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|oftruncate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_get_kernel_syms
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getegid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|geteuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getgroups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getitimer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_getpgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getpgrp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getpid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getppid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getpriority
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ogetrlimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getrusage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gettimeofday
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_gtty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_idle
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_init_module
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_ioctl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_ioperm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_iopl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_ipc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_kill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|link
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_lock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ostat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mkdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mknod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_mmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_modify_ldt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_mount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mprotect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_mpx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|munmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_newfstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_newlstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_newstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_newuname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_nice
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_olduname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_pause
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_phys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_pipe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_prof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|profil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_ptrace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_quotactl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|read
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_readdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|readlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|reboot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rmdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_select
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setdomainname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setgroups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|osethostname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setitimer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setpgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setpriority
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setregid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setreuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|osetrlimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setsid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|settimeofday
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sigreturn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_setup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_sigaction
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_siggetmask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_signal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_sigpending
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_sigprocmask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_sigreturn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_sigsetmask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_sigsuspend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_socketcall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_stat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_statfs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_stime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_stty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_swapoff
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|swapon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_sysinfo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_syslog
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_times
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|otruncate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_ulimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|umask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_umount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_uname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_uselib
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_ustat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_utime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_vhangup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_vm86
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_wait4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_waitpid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|write
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|sysent
name|linux_sysent
index|[]
init|=
block|{
literal|0
block|,
name|linux_setup
block|,
comment|/* 0 */
literal|1
block|,
name|exit
block|,
comment|/* 1 */
literal|0
block|,
name|linux_fork
block|,
comment|/* 2 */
literal|3
block|,
name|read
block|,
comment|/* 3 */
literal|3
block|,
name|write
block|,
comment|/* 4 */
literal|3
block|,
name|linux_open
block|,
comment|/* 5 */
literal|1
block|,
name|close
block|,
comment|/* 6 */
literal|3
block|,
name|linux_waitpid
block|,
comment|/* 7 */
literal|2
block|,
name|linux_creat
block|,
comment|/* 8 */
literal|2
block|,
name|link
block|,
comment|/* 9 */
literal|1
block|,
name|unlink
block|,
comment|/* 10 */
literal|3
block|,
name|execve
block|,
comment|/* 11 */
literal|1
block|,
name|chdir
block|,
comment|/* 12 */
literal|1
block|,
name|linux_time
block|,
comment|/* 13 */
literal|3
block|,
name|mknod
block|,
comment|/* 14 */
literal|2
block|,
name|chmod
block|,
comment|/* 15 */
literal|3
block|,
name|chown
block|,
comment|/* 16 */
literal|1
block|,
name|linux_break
block|,
comment|/* 17 */
literal|2
block|,
name|linux_stat
block|,
comment|/* 18 */
literal|3
block|,
name|linux_lseek
block|,
comment|/* 19 */
literal|0
block|,
name|getpid
block|,
comment|/* 20 */
literal|5
block|,
name|linux_mount
block|,
comment|/* 21 */
literal|1
block|,
name|linux_umount
block|,
comment|/* 22 */
literal|1
block|,
name|setuid
block|,
comment|/* 23 */
literal|0
block|,
name|getuid
block|,
comment|/* 24 */
literal|1
block|,
name|linux_stime
block|,
comment|/* 25 */
literal|4
block|,
name|linux_ptrace
block|,
comment|/* 26 */
literal|1
block|,
name|linux_alarm
block|,
comment|/* 27 */
literal|2
block|,
name|linux_fstat
block|,
comment|/* 28 */
literal|0
block|,
name|linux_pause
block|,
comment|/* 29 */
literal|2
block|,
name|linux_utime
block|,
comment|/* 30 */
literal|0
block|,
name|linux_stty
block|,
comment|/* 31 */
literal|0
block|,
name|linux_gtty
block|,
comment|/* 32 */
literal|2
block|,
name|access
block|,
comment|/* 33 */
literal|1
block|,
name|linux_nice
block|,
comment|/* 34 */
literal|0
block|,
name|linux_ftime
block|,
comment|/* 35 */
literal|0
block|,
name|sync
block|,
comment|/* 36 */
literal|2
block|,
name|linux_kill
block|,
comment|/* 37 */
literal|2
block|,
name|rename
block|,
comment|/* 38 */
literal|2
block|,
name|mkdir
block|,
comment|/* 39 */
literal|1
block|,
name|rmdir
block|,
comment|/* 40 */
literal|1
block|,
name|dup
block|,
comment|/* 41 */
literal|1
block|,
name|linux_pipe
block|,
comment|/* 42 */
literal|1
block|,
name|linux_times
block|,
comment|/* 43 */
literal|0
block|,
name|linux_prof
block|,
comment|/* 44 */
literal|1
block|,
name|linux_brk
block|,
comment|/* 45 */
literal|1
block|,
name|setgid
block|,
comment|/* 46 */
literal|0
block|,
name|getgid
block|,
comment|/* 47 */
literal|2
block|,
name|linux_signal
block|,
comment|/* 48 */
literal|0
block|,
name|geteuid
block|,
comment|/* 49 */
literal|0
block|,
name|getegid
block|,
comment|/* 50 */
literal|0
block|,
name|acct
block|,
comment|/* 51 */
literal|0
block|,
name|linux_phys
block|,
comment|/* 52 */
literal|0
block|,
name|linux_lock
block|,
comment|/* 53 */
literal|3
block|,
name|linux_ioctl
block|,
comment|/* 54 */
literal|3
block|,
name|linux_fcntl
block|,
comment|/* 55 */
literal|0
block|,
name|linux_mpx
block|,
comment|/* 56 */
literal|2
block|,
name|setpgid
block|,
comment|/* 57 */
literal|0
block|,
name|linux_ulimit
block|,
comment|/* 58 */
literal|1
block|,
name|linux_olduname
block|,
comment|/* 59 */
literal|1
block|,
name|umask
block|,
comment|/* 60 */
literal|1
block|,
name|chroot
block|,
comment|/* 61 */
literal|2
block|,
name|linux_ustat
block|,
comment|/* 62 */
literal|2
block|,
name|dup2
block|,
comment|/* 63 */
literal|0
block|,
name|getppid
block|,
comment|/* 64 */
literal|0
block|,
name|getpgrp
block|,
comment|/* 65 */
literal|0
block|,
name|setsid
block|,
comment|/* 66 */
literal|3
block|,
name|linux_sigaction
block|,
comment|/* 67 */
literal|0
block|,
name|linux_siggetmask
block|,
comment|/* 68 */
literal|1
block|,
name|linux_sigsetmask
block|,
comment|/* 69 */
literal|2
block|,
name|setreuid
block|,
comment|/* 70 */
literal|2
block|,
name|setregid
block|,
comment|/* 71 */
literal|1
block|,
name|linux_sigsuspend
block|,
comment|/* 72 */
literal|1
block|,
name|linux_sigpending
block|,
comment|/* 73 */
literal|2
block|,
name|osethostname
block|,
comment|/* 74 */
literal|2
block|,
name|osetrlimit
block|,
comment|/* 75 */
literal|2
block|,
name|ogetrlimit
block|,
comment|/* 76 */
literal|2
block|,
name|getrusage
block|,
comment|/* 77 */
literal|2
block|,
name|gettimeofday
block|,
comment|/* 78 */
literal|2
block|,
name|settimeofday
block|,
comment|/* 79 */
literal|2
block|,
name|getgroups
block|,
comment|/* 80 */
literal|2
block|,
name|setgroups
block|,
comment|/* 81 */
literal|1
block|,
name|linux_select
block|,
comment|/* 82 */
literal|2
block|,
name|symlink
block|,
comment|/* 83 */
literal|2
block|,
name|ostat
block|,
comment|/* 84 */
literal|3
block|,
name|readlink
block|,
comment|/* 85 */
literal|1
block|,
name|linux_uselib
block|,
comment|/* 86 */
literal|1
block|,
name|swapon
block|,
comment|/* 87 */
literal|3
block|,
name|reboot
block|,
comment|/* 88 */
literal|3
block|,
name|linux_readdir
block|,
comment|/* 89 */
literal|1
block|,
name|linux_mmap
block|,
comment|/* 90 */
literal|2
block|,
name|munmap
block|,
comment|/* 91 */
literal|2
block|,
name|otruncate
block|,
comment|/* 92 */
literal|2
block|,
name|oftruncate
block|,
comment|/* 93 */
literal|2
block|,
name|fchmod
block|,
comment|/* 94 */
literal|3
block|,
name|fchown
block|,
comment|/* 95 */
literal|2
block|,
name|getpriority
block|,
comment|/* 96 */
literal|3
block|,
name|setpriority
block|,
comment|/* 97 */
literal|0
block|,
name|profil
block|,
comment|/* 98 */
literal|2
block|,
name|linux_statfs
block|,
comment|/* 99 */
literal|2
block|,
name|linux_fstatfs
block|,
comment|/* 100 */
literal|3
block|,
name|linux_ioperm
block|,
comment|/* 101 */
literal|2
block|,
name|linux_socketcall
block|,
comment|/* 102 */
literal|3
block|,
name|linux_syslog
block|,
comment|/* 103 */
literal|3
block|,
name|setitimer
block|,
comment|/* 104 */
literal|2
block|,
name|getitimer
block|,
comment|/* 105 */
literal|2
block|,
name|linux_newstat
block|,
comment|/* 106 */
literal|2
block|,
name|linux_newlstat
block|,
comment|/* 107 */
literal|2
block|,
name|linux_newfstat
block|,
comment|/* 108 */
literal|2
block|,
name|linux_uname
block|,
comment|/* 109 */
literal|1
block|,
name|linux_iopl
block|,
comment|/* 110 */
literal|0
block|,
name|linux_vhangup
block|,
comment|/* 111 */
literal|0
block|,
name|linux_idle
block|,
comment|/* 112 */
literal|1
block|,
name|linux_vm86
block|,
comment|/* 113 */
literal|4
block|,
name|linux_wait4
block|,
comment|/* 114 */
literal|1
block|,
name|linux_swapoff
block|,
comment|/* 115 */
literal|1
block|,
name|linux_sysinfo
block|,
comment|/* 116 */
literal|4
block|,
name|linux_ipc
block|,
comment|/* 117 */
literal|1
block|,
name|fsync
block|,
comment|/* 118 */
literal|1
block|,
name|linux_sigreturn
block|,
comment|/* 119 */
literal|0
block|,
name|linux_clone
block|,
comment|/* 120 */
literal|2
block|,
name|setdomainname
block|,
comment|/* 121 */
literal|1
block|,
name|linux_newuname
block|,
comment|/* 122 */
literal|3
block|,
name|linux_modify_ldt
block|,
comment|/* 123 */
literal|1
block|,
name|linux_adjtimex
block|,
comment|/* 124 */
literal|3
block|,
name|mprotect
block|,
comment|/* 125 */
literal|3
block|,
name|linux_sigprocmask
block|,
comment|/* 126 */
literal|2
block|,
name|linux_create_module
block|,
comment|/* 127 */
literal|4
block|,
name|linux_init_module
block|,
comment|/* 128 */
literal|1
block|,
name|linux_delete_module
block|,
comment|/* 129 */
literal|1
block|,
name|linux_get_kernel_syms
block|,
comment|/* 130 */
literal|0
block|,
name|linux_quotactl
block|,
comment|/* 131 */
literal|1
block|,
name|linux_getpgid
block|,
comment|/* 132 */
literal|1
block|,
name|fchdir
block|,
comment|/* 133 */
literal|0
block|,
name|linux_bdflush
block|,
comment|/* 134 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bsd_to_linux_errno
index|[
name|ELAST
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|35
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|16
block|,
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|,
literal|34
block|,
literal|11
block|,
literal|115
block|,
literal|114
block|,
literal|88
block|,
literal|89
block|,
literal|90
block|,
literal|91
block|,
literal|92
block|,
literal|93
block|,
literal|94
block|,
literal|95
block|,
literal|96
block|,
literal|97
block|,
literal|98
block|,
literal|99
block|,
literal|100
block|,
literal|101
block|,
literal|102
block|,
literal|103
block|,
literal|104
block|,
literal|105
block|,
literal|106
block|,
literal|107
block|,
literal|108
block|,
literal|109
block|,
literal|110
block|,
literal|111
block|,
literal|40
block|,
literal|36
block|,
literal|112
block|,
literal|113
block|,
literal|39
block|,
literal|11
block|,
literal|87
block|,
literal|122
block|,
literal|116
block|,
literal|66
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|6
block|,
literal|37
block|,
literal|38
block|,
literal|9
block|,
literal|6
block|,  }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bsd_to_linux_signal
index|[
name|NSIG
index|]
init|=
block|{
literal|0
block|,
name|LINUX_SIGHUP
block|,
name|LINUX_SIGINT
block|,
name|LINUX_SIGQUIT
block|,
name|LINUX_SIGILL
block|,
name|LINUX_SIGTRAP
block|,
name|LINUX_SIGABRT
block|,
literal|0
block|,
name|LINUX_SIGFPE
block|,
name|LINUX_SIGKILL
block|,
name|LINUX_SIGBUS
block|,
name|LINUX_SIGSEGV
block|,
literal|0
block|,
name|LINUX_SIGPIPE
block|,
name|LINUX_SIGALRM
block|,
name|LINUX_SIGTERM
block|,
name|LINUX_SIGURG
block|,
name|LINUX_SIGSTOP
block|,
name|LINUX_SIGTSTP
block|,
name|LINUX_SIGCONT
block|,
name|LINUX_SIGCHLD
block|,
name|LINUX_SIGTTIN
block|,
name|LINUX_SIGTTOU
block|,
name|LINUX_SIGIO
block|,
name|LINUX_SIGXCPU
block|,
name|LINUX_SIGXFSZ
block|,
name|LINUX_SIGVTALRM
block|,
name|LINUX_SIGPROF
block|,
name|LINUX_SIGWINCH
block|,
literal|0
block|,
name|LINUX_SIGUSR1
block|,
name|LINUX_SIGUSR2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linux_to_bsd_signal
index|[
name|LINUX_NSIG
index|]
init|=
block|{
literal|0
block|,
name|SIGHUP
block|,
name|SIGINT
block|,
name|SIGQUIT
block|,
name|SIGILL
block|,
name|SIGTRAP
block|,
name|SIGABRT
block|,
name|SIGEMT
block|,
name|SIGFPE
block|,
name|SIGKILL
block|,
name|SIGUSR1
block|,
name|SIGSEGV
block|,
name|SIGUSR2
block|,
name|SIGPIPE
block|,
name|SIGALRM
block|,
name|SIGTERM
block|,
name|SIGBUS
block|,
name|SIGCHLD
block|,
name|SIGCONT
block|,
name|SIGSTOP
block|,
name|SIGTSTP
block|,
name|SIGTTIN
block|,
name|SIGTTOU
block|,
name|SIGIO
block|,
name|SIGXCPU
block|,
name|SIGXFSZ
block|,
name|SIGVTALRM
block|,
name|SIGPROF
block|,
name|SIGWINCH
block|,
name|SIGURG
block|,
name|SIGURG
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|linux_fixup
parameter_list|(
name|int
modifier|*
modifier|*
name|stack_base
parameter_list|,
name|struct
name|image_params
modifier|*
name|iparams
parameter_list|)
block|{
name|int
modifier|*
name|argv
decl_stmt|,
modifier|*
name|envp
decl_stmt|;
name|argv
operator|=
operator|*
name|stack_base
expr_stmt|;
name|envp
operator|=
operator|*
name|stack_base
operator|+
operator|(
name|iparams
operator|->
name|argc
operator|+
literal|1
operator|)
expr_stmt|;
operator|(
operator|*
name|stack_base
operator|)
operator|--
expr_stmt|;
operator|*
operator|*
name|stack_base
operator|=
operator|(
name|int
operator|)
name|envp
expr_stmt|;
operator|(
operator|*
name|stack_base
operator|)
operator|--
expr_stmt|;
operator|*
operator|*
name|stack_base
operator|=
operator|(
name|int
operator|)
name|argv
expr_stmt|;
operator|(
operator|*
name|stack_base
operator|)
operator|--
expr_stmt|;
operator|*
operator|*
name|stack_base
operator|=
operator|(
name|int
operator|)
name|iparams
operator|->
name|argc
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|struct
name|sysentvec
name|linux_sysvec
init|=
block|{
sizeof|sizeof
argument_list|(
name|linux_sysent
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|linux_sysent
index|[
literal|0
index|]
argument_list|)
block|,
name|linux_sysent
block|,
literal|0xff
block|,
name|NSIG
block|,
name|bsd_to_linux_signal
block|,
name|ELAST
block|,
name|bsd_to_linux_errno
block|,
name|linux_fixup
block|}
decl_stmt|;
end_decl_stmt

end_unit

