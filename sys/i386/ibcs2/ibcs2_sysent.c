begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Søren Schmidt  * Copyright (c) 1994 Sean Eric Fagan  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2.h>
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
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_define
define|#
directive|define
name|NERR
value|80
end_define

begin_comment
comment|/* XXX must match sys/errno.h */
end_comment

begin_comment
comment|/* errno conversion tables */
end_comment

begin_decl_stmt
name|int
name|bsd_to_svr3_errno
index|[
name|NERR
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
literal|45
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
literal|118
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
literal|63
block|,
literal|110
block|,
literal|111
block|,
literal|112
block|,
literal|113
block|,
literal|114
block|,
literal|115
block|,
literal|31
block|,
literal|78
block|,
literal|116
block|,
literal|117
block|,
literal|145
block|,
literal|11
block|,
literal|11
block|,
literal|11
block|,
literal|0
block|,
literal|66
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|46
block|,
literal|89
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* function defines */
end_comment

begin_function_decl
name|int
name|ibcs2_access
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_advfs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_alarm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_break
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_chdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_chmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_chown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_chroot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_cisc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_clocal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_creat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_cxenix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_dup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_exec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_exece
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_fcntl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_fork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_fstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_fstatfs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_fsync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_getdents
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_getgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_getmsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_getpid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_getuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_gtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_gtty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_ioctl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_kill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_libattach
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_libdetach
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_link
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_lstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_mkdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_mknod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_msgsys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_nice
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_nosys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_pause
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_pipe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_plock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_poll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_procids
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_profil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_ptrace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_putmsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_read
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_readlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_rfdebug
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_rfstart
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_rfstop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_rfsys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_rmdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_rmount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_rumount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_secure
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_seek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_semsys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_setgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_setuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_shmsys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_sigsys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_smount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_stat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_statfs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_stime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_stty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_sumount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_symlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_sync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_sysacct
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_sysfs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_sysi86
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_times
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_uadmin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_ulimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_umask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_unadvfs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_unlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_utime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_utssys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_wait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_write
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibcs2_traceemu
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
name|int
name|sigreturn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* ibcs2 svr3 sysent table */
end_comment

begin_decl_stmt
name|struct
name|sysent
name|svr3_sysent
index|[]
init|=
block|{
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/*  0 = indir */
literal|1
block|,
name|ibcs2_exit
block|,
comment|/*  1 = exit */
literal|0
block|,
name|ibcs2_fork
block|,
comment|/*  2 = fork */
literal|3
block|,
name|ibcs2_read
block|,
comment|/*  3 = read */
literal|3
block|,
name|ibcs2_write
block|,
comment|/*  4 = write */
literal|3
block|,
name|ibcs2_open
block|,
comment|/*  5 = open */
literal|1
block|,
name|ibcs2_close
block|,
comment|/*  6 = close */
literal|3
block|,
name|ibcs2_wait
block|,
comment|/*  7 = wait */
literal|2
block|,
name|ibcs2_creat
block|,
comment|/*  8 = creat */
literal|2
block|,
name|ibcs2_link
block|,
comment|/*  9 = link */
literal|1
block|,
name|ibcs2_unlink
block|,
comment|/* 10 = unlink */
literal|2
block|,
name|ibcs2_exec
block|,
comment|/* 11 = exec */
literal|1
block|,
name|ibcs2_chdir
block|,
comment|/* 12 = chdir */
literal|0
block|,
name|ibcs2_gtime
block|,
comment|/* 13 = time */
literal|3
block|,
name|ibcs2_mknod
block|,
comment|/* 14 = mknod */
literal|2
block|,
name|ibcs2_chmod
block|,
comment|/* 15 = chmod */
literal|3
block|,
name|ibcs2_chown
block|,
comment|/* 16 = chown */
literal|1
block|,
name|ibcs2_break
block|,
comment|/* 17 = break */
literal|2
block|,
name|ibcs2_stat
block|,
comment|/* 18 = stat */
literal|3
block|,
name|ibcs2_seek
block|,
comment|/* 19 = seek */
literal|0
block|,
name|ibcs2_getpid
block|,
comment|/* 20 = getpid */
literal|6
block|,
name|ibcs2_smount
block|,
comment|/* 21 = mount */
literal|1
block|,
name|ibcs2_sumount
block|,
comment|/* 22 = umount */
literal|1
block|,
name|ibcs2_setuid
block|,
comment|/* 23 = setuid */
literal|0
block|,
name|ibcs2_getuid
block|,
comment|/* 24 = getuid */
literal|1
block|,
name|ibcs2_stime
block|,
comment|/* 25 = stime */
literal|4
block|,
name|ibcs2_ptrace
block|,
comment|/* 26 = ptrace */
literal|1
block|,
name|ibcs2_alarm
block|,
comment|/* 27 = alarm */
literal|2
block|,
name|ibcs2_fstat
block|,
comment|/* 28 = fstat */
literal|0
block|,
name|ibcs2_pause
block|,
comment|/* 29 = pause */
literal|2
block|,
name|ibcs2_utime
block|,
comment|/* 30 = utime */
literal|2
block|,
name|ibcs2_stty
block|,
comment|/* 31 = stty */
literal|2
block|,
name|ibcs2_gtty
block|,
comment|/* 32 = gtty */
literal|2
block|,
name|ibcs2_access
block|,
comment|/* 33 = access */
literal|1
block|,
name|ibcs2_nice
block|,
comment|/* 34 = nice */
literal|4
block|,
name|ibcs2_statfs
block|,
comment|/* 35 = statfs */
literal|0
block|,
name|ibcs2_sync
block|,
comment|/* 36 = sync */
literal|2
block|,
name|ibcs2_kill
block|,
comment|/* 37 = kill */
literal|4
block|,
name|ibcs2_fstatfs
block|,
comment|/* 38 = fstatfs */
literal|1
block|,
name|ibcs2_procids
block|,
comment|/* 39 = procids */
literal|5
block|,
name|ibcs2_cxenix
block|,
comment|/* 40 = XENIX special system call */
literal|1
block|,
name|ibcs2_dup
block|,
comment|/* 41 = dup */
literal|1
block|,
name|ibcs2_pipe
block|,
comment|/* 42 = pipe */
literal|1
block|,
name|ibcs2_times
block|,
comment|/* 43 = times */
literal|4
block|,
name|ibcs2_profil
block|,
comment|/* 44 = prof */
literal|1
block|,
name|ibcs2_plock
block|,
comment|/* 45 = proc lock */
literal|1
block|,
name|ibcs2_setgid
block|,
comment|/* 46 = setgid */
literal|0
block|,
name|ibcs2_getgid
block|,
comment|/* 47 = getgid */
literal|2
block|,
name|ibcs2_sigsys
block|,
comment|/* 48 = signal */
literal|6
block|,
name|ibcs2_msgsys
block|,
comment|/* 49 = IPC message */
literal|4
block|,
name|ibcs2_sysi86
block|,
comment|/* 50 = i386-specific system call */
literal|1
block|,
name|ibcs2_sysacct
block|,
comment|/* 51 = turn acct off/on */
literal|4
block|,
name|ibcs2_shmsys
block|,
comment|/* 52 = shared memory */
literal|5
block|,
name|ibcs2_semsys
block|,
comment|/* 53 = IPC semaphores */
literal|3
block|,
name|ibcs2_ioctl
block|,
comment|/* 54 = ioctl */
literal|3
block|,
name|ibcs2_uadmin
block|,
comment|/* 55 = uadmin */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 56 = reserved for exch */
literal|3
block|,
name|ibcs2_utssys
block|,
comment|/* 57 = utssys */
literal|1
block|,
name|ibcs2_fsync
block|,
comment|/* 58 = fsync */
literal|3
block|,
name|ibcs2_exece
block|,
comment|/* 59 = exece */
literal|1
block|,
name|ibcs2_umask
block|,
comment|/* 60 = umask */
literal|1
block|,
name|ibcs2_chroot
block|,
comment|/* 61 = chroot */
literal|3
block|,
name|ibcs2_fcntl
block|,
comment|/* 62 = fcntl */
literal|2
block|,
name|ibcs2_ulimit
block|,
comment|/* 63 = ulimit */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 64 = nosys */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 65 = nosys */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 66 = nosys */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 67 = file locking call */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 68 = local system calls */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 69 = inode open */
literal|4
block|,
name|ibcs2_advfs
block|,
comment|/* 70 = advfs */
literal|1
block|,
name|ibcs2_unadvfs
block|,
comment|/* 71 = unadvfs */
literal|4
block|,
name|ibcs2_rmount
block|,
comment|/* 72 = rmount */
literal|1
block|,
name|ibcs2_rumount
block|,
comment|/* 73 = rumount */
literal|5
block|,
name|ibcs2_rfstart
block|,
comment|/* 74 = rfstart */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 75 = not used */
literal|1
block|,
name|ibcs2_rfdebug
block|,
comment|/* 76 = rfdebug */
literal|0
block|,
name|ibcs2_rfstop
block|,
comment|/* 77 = rfstop */
literal|6
block|,
name|ibcs2_rfsys
block|,
comment|/* 78 = rfsys */
literal|1
block|,
name|ibcs2_rmdir
block|,
comment|/* 79 = rmdir */
literal|2
block|,
name|ibcs2_mkdir
block|,
comment|/* 80 = mkdir */
literal|4
block|,
name|ibcs2_getdents
block|,
comment|/* 81 = getdents */
literal|3
block|,
name|ibcs2_libattach
block|,
comment|/* 82 = libattach */
literal|1
block|,
name|ibcs2_libdetach
block|,
comment|/* 83 = libdetach */
literal|3
block|,
name|ibcs2_sysfs
block|,
comment|/* 84 = sysfs */
literal|4
block|,
name|ibcs2_getmsg
block|,
comment|/* 85 = getmsg */
literal|4
block|,
name|ibcs2_putmsg
block|,
comment|/* 86 = putmsg */
literal|3
block|,
name|ibcs2_poll
block|,
comment|/* 87 = poll */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 88 = not used */
literal|6
block|,
name|ibcs2_secure
block|,
comment|/* 89 = secureware */
literal|2
block|,
name|ibcs2_symlink
block|,
comment|/* 90 = symlink */
literal|2
block|,
name|ibcs2_lstat
block|,
comment|/* 91 = lstat */
literal|3
block|,
name|ibcs2_readlink
block|,
comment|/* 92 = readlink */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 93 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 94 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 95 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 96 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 97 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 98 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 99 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 100 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 101 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 102 = not used */
literal|1
block|,
name|sigreturn
block|,
comment|/* 103 = BSD sigreturn XXX */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 104 = not used */
literal|5
block|,
name|ibcs2_cisc
block|,
comment|/* 105 = ISC special */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 106 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 107 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 108 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 109 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 110 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 111 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 112 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 113 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 114 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 115 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 116 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 117 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 118 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 119 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 120 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 121 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 122 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 123 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 124 = not used */
literal|0
block|,
name|ibcs2_nosys
block|,
comment|/* 125 = not used */
literal|1
block|,
name|ibcs2_traceemu
block|,
comment|/* 126 = ibcs2 emulator trace cntl */
literal|5
block|,
name|ibcs2_clocal
block|,
comment|/* 127 = local system calls */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sysentvec
name|ibcs2_svr3_sysvec
init|=
block|{
sizeof|sizeof
argument_list|(
name|svr3_sysent
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|svr3_sysent
index|[
literal|0
index|]
argument_list|)
block|,
name|svr3_sysent
block|,
literal|0x7F
block|,
name|NSIG
block|,
name|bsd_to_ibcs2_signal
block|,
name|NERR
block|,
name|bsd_to_svr3_errno
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|int	ibcs2_acancel(); int	ibcs2_adjtime(); int	ibcs2_context(); int	ibcs2_evsys(); int	ibcs2_evtrapret(); int	ibcs2_fchdir(); int	ibcs2_fchmod(); int	ibcs2_fchown(); int	ibcs2_fstatvfs(); int	ibcs2_fxstat(); int	ibcs2_getgroups(); int	ibcs2_getpmsg(); int	ibcs2_getrlimit(); int	ibcs2_hrtsys(); int	ibcs2_lchown(); int	ibcs2_lxstat(); int	ibcs2_memcntl(); int	ibcs2_mincore(); int	ibcs2_mmap(); int	ibcs2_mprotect(); int	ibcs2_munmap(); int	ibcs2_pathconf(); int	ibcs2_priocntlsys(); int	ibcs2_putgmsg(); int	ibcs2_readv(); int	ibcs2_rename(); int	ibcs2_setegid(); int	ibcs2_seteuid(); int	ibcs2_setgroups(); int	ibcs2_setrlimit(); int	ibcs2_sigaction(); int	ibcs2_sigaltstack(); int	ibcs2_sigpending(); int	ibcs2_sigprocmask(); int	ibcs2_sigsendsys(); int	ibcs2_sigsuspend(); int	ibcs2_statvfs(); int	ibcs2_sysconfig(); int	ibcs2_systeminfo(); int	ibcs2_vfork(); int	ibcs2_waitsys(); int	ibcs2_writev(); int	ibcs2_xmknod(); int	ibcs2_xstat();  int bsd_to_svr4_errno[NERR] = { 	  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 	 10, 45, 12, 13, 14, 15, 16, 17, 18, 19, 	 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 	 30, 31, 32, 33, 34, 11,150,149, 95, 96, 	 97, 98, 99,120,121,122,123,124,125,126, 	127,128,129,130,131,132,133,134,143,144, 	145,146, 90, 78,147,148, 93, 11, 94, 11, 	  0,  0,  0,  0,  0,  0,  0, 46, 89,  0, };
comment|/* ibcs2 svr4 sysent table */
end_comment

begin_comment
unit|struct sysent svr4_sysent[] = { 	0, ibcs2_nosys,
comment|/*  0 = indir */
end_comment

begin_comment
unit|1, ibcs2_exit,
comment|/*  1 = exit */
end_comment

begin_comment
unit|0, ibcs2_fork,
comment|/*  2 = fork */
end_comment

begin_comment
unit|3, ibcs2_read,
comment|/*  3 = read */
end_comment

begin_comment
unit|3, ibcs2_write,
comment|/*  4 = write */
end_comment

begin_comment
unit|3, ibcs2_open,
comment|/*  5 = open */
end_comment

begin_comment
unit|1, ibcs2_close,
comment|/*  6 = close */
end_comment

begin_comment
unit|3, ibcs2_wait,
comment|/*  7 = wait */
end_comment

begin_comment
unit|2, ibcs2_creat,
comment|/*  8 = creat */
end_comment

begin_comment
unit|2, ibcs2_link,
comment|/*  9 = link */
end_comment

begin_comment
unit|1, ibcs2_unlink,
comment|/* 10 = unlink */
end_comment

begin_comment
unit|2, ibcs2_exec,
comment|/* 11 = exec */
end_comment

begin_comment
unit|1, ibcs2_chdir,
comment|/* 12 = chdir */
end_comment

begin_comment
unit|0, ibcs2_gtime,
comment|/* 13 = time */
end_comment

begin_comment
unit|3, ibcs2_mknod,
comment|/* 14 = mknod */
end_comment

begin_comment
unit|2, ibcs2_chmod,
comment|/* 15 = chmod */
end_comment

begin_comment
unit|3, ibcs2_chown,
comment|/* 16 = chown */
end_comment

begin_comment
unit|1, ibcs2_break,
comment|/* 17 = break */
end_comment

begin_comment
unit|2, ibcs2_stat,
comment|/* 18 = stat */
end_comment

begin_comment
unit|3, ibcs2_seek,
comment|/* 19 = seek */
end_comment

begin_comment
unit|0, ibcs2_getpid,
comment|/* 20 = getpid */
end_comment

begin_comment
unit|6, ibcs2_smount,
comment|/* 21 = mount */
end_comment

begin_comment
unit|1, ibcs2_sumount,
comment|/* 22 = umount */
end_comment

begin_comment
unit|1, ibcs2_setuid,
comment|/* 23 = setuid */
end_comment

begin_comment
unit|0, ibcs2_getuid,
comment|/* 24 = getuid */
end_comment

begin_comment
unit|1, ibcs2_stime,
comment|/* 25 = stime */
end_comment

begin_comment
unit|4, ibcs2_ptrace,
comment|/* 26 = ptrace */
end_comment

begin_comment
unit|1, ibcs2_alarm,
comment|/* 27 = alarm */
end_comment

begin_comment
unit|2, ibcs2_fstat,
comment|/* 28 = fstat */
end_comment

begin_comment
unit|0, ibcs2_pause,
comment|/* 29 = pause */
end_comment

begin_comment
unit|2, ibcs2_utime,
comment|/* 30 = utime */
end_comment

begin_comment
unit|2, ibcs2_stty,
comment|/* 31 = stty */
end_comment

begin_comment
unit|2, ibcs2_gtty,
comment|/* 32 = gtty */
end_comment

begin_comment
unit|2, ibcs2_access,
comment|/* 33 = access */
end_comment

begin_comment
unit|1, ibcs2_nice,
comment|/* 34 = nice */
end_comment

begin_comment
unit|4, ibcs2_statfs,
comment|/* 35 = statfs */
end_comment

begin_comment
unit|0, ibcs2_sync,
comment|/* 36 = sync */
end_comment

begin_comment
unit|2, ibcs2_kill,
comment|/* 37 = kill */
end_comment

begin_comment
unit|4, ibcs2_fstatfs,
comment|/* 38 = fstatfs */
end_comment

begin_comment
unit|1, ibcs2_procids,
comment|/* 39 = procids */
end_comment

begin_comment
unit|5, ibcs2_cxenix,
comment|/* 40 = XENIX special system call */
end_comment

begin_comment
unit|1, ibcs2_dup,
comment|/* 41 = dup */
end_comment

begin_comment
unit|1, ibcs2_pipe,
comment|/* 42 = pipe */
end_comment

begin_comment
unit|1, ibcs2_times,
comment|/* 43 = times */
end_comment

begin_comment
unit|4, ibcs2_profil,
comment|/* 44 = prof */
end_comment

begin_comment
unit|1, ibcs2_plock,
comment|/* 45 = proc lock */
end_comment

begin_comment
unit|1, ibcs2_setgid,
comment|/* 46 = setgid */
end_comment

begin_comment
unit|0, ibcs2_getgid,
comment|/* 47 = getgid */
end_comment

begin_comment
unit|2, ibcs2_sigsys,
comment|/* 48 = signal */
end_comment

begin_comment
unit|6, ibcs2_msgsys,
comment|/* 49 = IPC message */
end_comment

begin_comment
unit|4, ibcs2_sysi86,
comment|/* 50 = i386-specific system call */
end_comment

begin_comment
unit|1, ibcs2_sysacct,
comment|/* 51 = turn acct off/on */
end_comment

begin_comment
unit|4, ibcs2_shmsys,
comment|/* 52 = shared memory */
end_comment

begin_comment
unit|5, ibcs2_semsys,
comment|/* 53 = IPC semaphores */
end_comment

begin_comment
unit|3, ibcs2_ioctl,
comment|/* 54 = ioctl */
end_comment

begin_comment
unit|3, ibcs2_uadmin,
comment|/* 55 = uadmin */
end_comment

begin_comment
unit|0, ibcs2_nosys,
comment|/* 56 = reserved for exch */
end_comment

begin_comment
unit|3, ibcs2_utssys,
comment|/* 57 = utssys */
end_comment

begin_comment
unit|1, ibcs2_fsync,
comment|/* 58 = fsync */
end_comment

begin_comment
unit|3, ibcs2_exece,
comment|/* 59 = exece */
end_comment

begin_comment
unit|1, ibcs2_umask,
comment|/* 60 = umask */
end_comment

begin_comment
unit|1, ibcs2_chroot,
comment|/* 61 = chroot */
end_comment

begin_comment
unit|3, ibcs2_fcntl,
comment|/* 62 = fcntl */
end_comment

begin_comment
unit|2, ibcs2_ulimit,
comment|/* 63 = ulimit */
end_comment

begin_comment
unit|0, ibcs2_nosys,
comment|/* 64 = nosys */
end_comment

begin_comment
unit|0, ibcs2_nosys,
comment|/* 65 = nosys */
end_comment

begin_comment
unit|0, ibcs2_nosys,
comment|/* 66 = nosys */
end_comment

begin_comment
unit|0, ibcs2_nosys,
comment|/* 67 = file locking call */
end_comment

begin_comment
unit|0, ibcs2_nosys,
comment|/* 68 = local system calls */
end_comment

begin_comment
unit|0, ibcs2_nosys,
comment|/* 69 = inode open */
end_comment

begin_comment
unit|4, ibcs2_advfs,
comment|/* 70 = advfs */
end_comment

begin_comment
unit|1, ibcs2_unadvfs,
comment|/* 71 = unadvfs */
end_comment

begin_comment
unit|4, ibcs2_rmount,
comment|/* 72 = rmount */
end_comment

begin_comment
unit|1, ibcs2_rumount,
comment|/* 73 = rumount */
end_comment

begin_comment
unit|5, ibcs2_rfstart,
comment|/* 74 = rfstart */
end_comment

begin_comment
unit|0, ibcs2_nosys,
comment|/* 75 = not used */
end_comment

begin_comment
unit|1, ibcs2_rfdebug,
comment|/* 76 = rfdebug */
end_comment

begin_comment
unit|0, ibcs2_rfstop,
comment|/* 77 = rfstop */
end_comment

begin_comment
unit|6, ibcs2_rfsys,
comment|/* 78 = rfsys */
end_comment

begin_comment
unit|1, ibcs2_rmdir,
comment|/* 79 = rmdir */
end_comment

begin_comment
unit|2, ibcs2_mkdir,
comment|/* 80 = mkdir */
end_comment

begin_comment
unit|4, ibcs2_getdents,
comment|/* 81 = getdents */
end_comment

begin_comment
unit|3, ibcs2_libattach,
comment|/* 82 = libattach */
end_comment

begin_comment
unit|1, ibcs2_libdetach,
comment|/* 83 = libdetach */
end_comment

begin_comment
unit|3, ibcs2_sysfs,
comment|/* 84 = sysfs */
end_comment

begin_comment
unit|4, ibcs2_getmsg,
comment|/* 85 = getmsg */
end_comment

begin_comment
unit|4, ibcs2_putmsg,
comment|/* 86 = putmsg */
end_comment

begin_comment
unit|3, ibcs2_poll,
comment|/* 87 = poll */
end_comment

begin_comment
unit|6, ibcs2_lstat,
comment|/* 88 = lstat */
end_comment

begin_comment
unit|2, ibcs2_symlink,
comment|/* 89 = symlink */
end_comment

begin_comment
unit|3, ibcs2_readlink,
comment|/* 90 = readlink */
end_comment

begin_comment
unit|2, ibcs2_setgroups,
comment|/* 91 = setgroups */
end_comment

begin_comment
unit|2, ibcs2_getgroups,
comment|/* 92 = getgroups */
end_comment

begin_comment
unit|2, ibcs2_fchmod,
comment|/* 93 = fchmod */
end_comment

begin_comment
unit|3, ibcs2_fchown,
comment|/* 94 = fchown */
end_comment

begin_comment
unit|3, ibcs2_sigprocmask,
comment|/* 95 = sigprocmask */
end_comment

begin_comment
unit|0, ibcs2_sigsuspend,
comment|/* 96 = sigsuspend */
end_comment

begin_comment
unit|2, ibcs2_sigaltstack,
comment|/* 97 = sigaltstack */
end_comment

begin_comment
unit|3, ibcs2_sigaction,
comment|/* 98 = sigaction */
end_comment

begin_comment
unit|1, ibcs2_sigpending,
comment|/* 99 = sigpending */
end_comment

begin_comment
unit|0, ibcs2_context,
comment|/* 100 = context */
end_comment

begin_comment
unit|0, ibcs2_evsys,
comment|/* 101 = evsys */
end_comment

begin_comment
unit|0, ibcs2_evtrapret,
comment|/* 102 = evtrapret */
end_comment

begin_comment
unit|0, ibcs2_statvfs,
comment|/* 103 = statvfs */
end_comment

begin_comment
unit|0, ibcs2_fstatvfs,
comment|/* 104 = fstatvfs */
end_comment

begin_comment
unit|5, ibcs2_cisc,
comment|/* 105 = ISC special */
end_comment

begin_comment
unit|0, ibcs2_nfssys,
comment|/* 106 = nfssys */
end_comment

begin_comment
unit|0, ibcs2_waitsys,
comment|/* 107 = waitsys */
end_comment

begin_comment
unit|0, ibcs2_sigsendsys,
comment|/* 108 = sigsendsys */
end_comment

begin_comment
unit|0, ibcs2_hrtsys,
comment|/* 109 = hrtsys */
end_comment

begin_comment
unit|0, ibcs2_acancel,
comment|/* 110 = acancel */
end_comment

begin_comment
unit|0, ibcs2_async,
comment|/* 111 = async */
end_comment

begin_comment
unit|0, ibcs2_priocntlsys,
comment|/* 112 = priocntlsys */
end_comment

begin_comment
unit|0, ibcs2_pathconf,
comment|/* 113 = pathconf */
end_comment

begin_comment
unit|0, ibcs2_mincore,
comment|/* 114 = mincore */
end_comment

begin_comment
unit|6, ibcs2_mmap,
comment|/* 115 = mmap */
end_comment

begin_comment
unit|3, ibcs2_mprotect,
comment|/* 116 = mprotect */
end_comment

begin_comment
unit|2, ibcs2_munmap,
comment|/* 117 = munmap */
end_comment

begin_comment
unit|0, ibcs2_pathconf,
comment|/* 118 = fpathconf */
end_comment

begin_comment
unit|0, ibcs2_vfork,
comment|/* 119 = vfork */
end_comment

begin_comment
unit|0, ibcs2_fchdir,
comment|/* 120 = fchdir */
end_comment

begin_comment
unit|0, ibcs2_readv,
comment|/* 121 = readv */
end_comment

begin_comment
unit|0, ibcs2_writev,
comment|/* 122 = writev */
end_comment

begin_comment
unit|3, ibcs2_xstat,
comment|/* 123 = xstat */
end_comment

begin_comment
unit|3, ibcs2_lxstat,
comment|/* 124 = lxstat */
end_comment

begin_comment
unit|3, ibcs2_fxstat,
comment|/* 125 = fxstat */
end_comment

begin_comment
unit|4, ibcs2_xmknod,
comment|/* 126 = xmknod */
end_comment

begin_comment
unit|5, ibcs2_clocal,
comment|/* 127 = local system calls */
end_comment

begin_comment
unit|0, ibcs2_setrlimit,
comment|/* 128 = setrlimit */
end_comment

begin_comment
unit|0, ibcs2_getrlimit,
comment|/* 129 = getrlimit */
end_comment

begin_comment
unit|0, ibcs2_lchown,
comment|/* 130 = lchown */
end_comment

begin_comment
unit|0, ibcs2_memcntl,
comment|/* 131 = memcntl */
end_comment

begin_comment
unit|0, ibcs2_getpmsg,
comment|/* 132 = getpmsg */
end_comment

begin_comment
unit|0, ibcs2_putgmsg,
comment|/* 133 = putgmsg */
end_comment

begin_comment
unit|2, ibcs2_rename,
comment|/* 134 = rename */
end_comment

begin_comment
unit|1, ibcs2_uname,
comment|/* 135 = uname */
end_comment

begin_comment
unit|0, ibcs2_setegid,
comment|/* 136 = setegid */
end_comment

begin_comment
unit|0, ibcs2_sysconfig,
comment|/* 137 = sysconfig */
end_comment

begin_comment
unit|0, ibcs2_adjtime,
comment|/* 138 = adjtime */
end_comment

begin_comment
unit|0, ibcs2_systeminfo,
comment|/* 139 = systeminfo */
end_comment

begin_comment
unit|0, ibcs2_nosys,
comment|/* 140 = not used */
end_comment

begin_comment
unit|0, ibcs2_seteuid,
comment|/* 141 = seteuid */
end_comment

begin_endif
unit|};  struct sysentvec ibcs2_svr4_sysvec = { 	sizeof (svr4_sysent) / sizeof (svr4_sysent[0]), 	svr4_sysent, 	0xFF, 	NSIG, 	bsd_to_ibcs2_signal, 	NERR, 	bsd_to_svr4_errno };
endif|#
directive|endif
end_endif

end_unit

