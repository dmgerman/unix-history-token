begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * from: Utah $Hdr: hpux_sysent.c 1.14 89/08/14$  *  *	@(#)hpux_sysent.c	7.4 (Berkeley) 6/22/90  */
end_comment

begin_comment
comment|/*  * System call switch table.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_decl_stmt
name|int
name|nosys
argument_list|()
decl_stmt|,
name|notimp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.1 processes and protection */
end_comment

begin_function_decl
name|int
name|getpid
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|hpuxgetdomainname
argument_list|()
decl_stmt|,
name|hpuxsetdomainname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fork
argument_list|()
decl_stmt|,
name|rexit
argument_list|()
decl_stmt|,
name|execv
argument_list|()
decl_stmt|,
name|execve
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getuid
argument_list|()
decl_stmt|,
name|getgid
argument_list|()
decl_stmt|,
name|getgroups
argument_list|()
decl_stmt|,
name|setgroups
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setuid
argument_list|()
decl_stmt|,
name|setgid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2 memory management */
end_comment

begin_comment
comment|/* 1.3 signals */
end_comment

begin_function_decl
name|int
name|sigstack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* sigreturn is not HPUX, but we need it to make signals work */
end_comment

begin_function_decl
name|int
name|sigreturn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 1.4 timing and statistics */
end_comment

begin_decl_stmt
name|int
name|gettimeofday
argument_list|()
decl_stmt|,
name|settimeofday
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getitimer
argument_list|()
decl_stmt|,
name|setitimer
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.5 descriptors */
end_comment

begin_decl_stmt
name|int
name|dup2
argument_list|()
decl_stmt|,
name|close
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|select
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 1.6 resource controls */
end_comment

begin_comment
comment|/* 1.7 system operation support */
end_comment

begin_function_decl
name|int
name|sync
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 2.2 file system */
end_comment

begin_decl_stmt
name|int
name|chdir
argument_list|()
decl_stmt|,
name|chroot
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mkdir
argument_list|()
decl_stmt|,
name|rmdir
argument_list|()
decl_stmt|,
name|getdirentries
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ocreat
argument_list|()
decl_stmt|,
name|mknod
argument_list|()
decl_stmt|,
name|unlink
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chown
argument_list|()
decl_stmt|,
name|fchown
argument_list|()
decl_stmt|,
name|chmod
argument_list|()
decl_stmt|,
name|fchmod
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|link
argument_list|()
decl_stmt|,
name|symlink
argument_list|()
decl_stmt|,
name|readlink
argument_list|()
decl_stmt|,
name|rename
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lseek
argument_list|()
decl_stmt|,
name|truncate
argument_list|()
decl_stmt|,
name|ftruncate
argument_list|()
decl_stmt|,
name|saccess
argument_list|()
decl_stmt|,
name|fsync
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2.3 communications */
end_comment

begin_function_decl
name|int
name|pipe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umask
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* 2.4 processes */
end_comment

begin_comment
comment|/* 2.5 terminals */
end_comment

begin_comment
comment|/* HPUX junk */
end_comment

begin_decl_stmt
name|int
name|hpuxwait
argument_list|()
decl_stmt|,
name|hpuxdup
argument_list|()
decl_stmt|,
name|hpuxuname
argument_list|()
decl_stmt|,
name|hpuxulimit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hpuxadvise
argument_list|()
decl_stmt|,
name|hpuxstat
argument_list|()
decl_stmt|,
name|hpuxfstat
argument_list|()
decl_stmt|,
name|hpuxlstat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hpuxsigvec
argument_list|()
decl_stmt|,
name|hpuxsigblock
argument_list|()
decl_stmt|,
name|hpuxsigsetmask
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hpuxsigpause
argument_list|()
decl_stmt|,
name|hpuxkill
argument_list|()
decl_stmt|,
name|hpuxptrace
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hpuxopen
argument_list|()
decl_stmt|,
name|hpuxfcntl
argument_list|()
decl_stmt|,
name|hpuxread
argument_list|()
decl_stmt|,
name|hpuxwrite
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hpuxreadv
argument_list|()
decl_stmt|,
name|hpuxwritev
argument_list|()
decl_stmt|,
name|hpuxioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hpuxnetioctl
argument_list|()
decl_stmt|,
name|hpuxrtprio
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|hpuxgetcontext
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|hpuxlockf
argument_list|()
decl_stmt|,
name|hpuxgetpgrp2
argument_list|()
decl_stmt|,
name|hpuxsetpgrp2
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hpuxwait3
argument_list|()
decl_stmt|,
name|hpuxwaitpid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVSHM
end_ifdef

begin_decl_stmt
name|int
name|hpuxshmctl
argument_list|()
decl_stmt|,
name|hpuxshmget
argument_list|()
decl_stmt|,
name|hpuxshmat
argument_list|()
decl_stmt|,
name|hpuxshmdt
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|hpuxsemctl
argument_list|()
decl_stmt|,
name|hpuxsemget
argument_list|()
decl_stmt|,
name|hpuxsemop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Old 4.2 compatibility routines.  * Still needed for HP-UX?  */
end_comment

begin_define
define|#
directive|define
name|compat
parameter_list|(
name|n
parameter_list|,
name|name
parameter_list|)
value|n, o
comment|/**/
value|name
end_define

begin_function_decl
name|int
name|ohpuxtime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use gettimeofday */
end_comment

begin_function_decl
name|int
name|ohpuxstime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use settimeofday */
end_comment

begin_function_decl
name|int
name|ohpuxalarm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use setitimer */
end_comment

begin_function_decl
name|int
name|ohpuxutime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use utimes */
end_comment

begin_function_decl
name|int
name|ohpuxpause
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use sigpause */
end_comment

begin_function_decl
name|int
name|ohpuxnice
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use setpriority,getpriority */
end_comment

begin_function_decl
name|int
name|ohpuxftime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use gettimeofday */
end_comment

begin_function_decl
name|int
name|ohpuxtimes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use getrusage */
end_comment

begin_function_decl
name|int
name|ohpuxstat
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use stat */
end_comment

begin_function_decl
name|int
name|ohpuxfstat
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use fstat */
end_comment

begin_function_decl
name|int
name|ohpuxssig
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use sigvec, etc */
end_comment

begin_function_decl
name|int
name|ohpuxgtty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use hpuxioctl */
end_comment

begin_function_decl
name|int
name|ohpuxstty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use hpuxioctl */
end_comment

begin_function_decl
name|int
name|ohpuxsetpgrp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SYS5 style setpgrp */
end_comment

begin_comment
comment|/* BEGIN JUNK */
end_comment

begin_function_decl
name|int
name|profil
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 'cuz sys calls are interruptible */
end_comment

begin_function_decl
name|int
name|vfork
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* awaiting fork w/ copy on write */
end_comment

begin_function_decl
name|int
name|obreak
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* awaiting new sbrk */
end_comment

begin_comment
comment|/* END JUNK */
end_comment

begin_comment
comment|/*  * Reserved/unimplemented system calls in the range 0-150 inclusive  * are reserved for use in future Berkeley releases.  * Additional system calls implemented in vendor and other  * redistributions should be placed in the reserved range at the end  * of the current calls.  */
end_comment

begin_decl_stmt
name|struct
name|sysent
name|hpuxsysent
index|[]
init|=
block|{
literal|0
block|,
name|nosys
block|,
comment|/*   0 = out of range */
literal|1
block|,
name|rexit
block|,
comment|/*   1 = exit */
literal|0
block|,
name|fork
block|,
comment|/*   2 = fork */
literal|3
block|,
name|hpuxread
block|,
comment|/*   3 = read */
literal|3
block|,
name|hpuxwrite
block|,
comment|/*   4 = write */
literal|3
block|,
name|hpuxopen
block|,
comment|/*   5 = open */
literal|1
block|,
name|close
block|,
comment|/*   6 = close */
literal|1
block|,
name|hpuxwait
block|,
comment|/*   7 = HPUX style wait */
literal|2
block|,
name|ocreat
block|,
comment|/*   8 = ocreat */
literal|2
block|,
name|link
block|,
comment|/*   9 = link */
literal|1
block|,
name|unlink
block|,
comment|/*  10 = unlink */
literal|2
block|,
name|execv
block|,
comment|/*  11 = execv */
literal|1
block|,
name|chdir
block|,
comment|/*  12 = chdir */
name|compat
argument_list|(
literal|1
argument_list|,
name|hpuxtime
argument_list|)
block|,
comment|/*  13 = old time */
literal|3
block|,
name|mknod
block|,
comment|/*  14 = mknod */
literal|2
block|,
name|chmod
block|,
comment|/*  15 = chmod */
literal|3
block|,
name|chown
block|,
comment|/*  16 = chown; now 3 args */
literal|1
block|,
name|obreak
block|,
comment|/*  17 = old break */
name|compat
argument_list|(
literal|2
argument_list|,
name|hpuxstat
argument_list|)
block|,
comment|/*  18 = old stat */
literal|3
block|,
name|lseek
block|,
comment|/*  19 = lseek */
literal|0
block|,
name|getpid
block|,
comment|/*  20 = getpid */
literal|3
block|,
name|notimp
block|,
comment|/*  21 = mount */
literal|1
block|,
name|notimp
block|,
comment|/*  22 = umount */
literal|1
block|,
name|setuid
block|,
comment|/*  23 = setuid */
literal|0
block|,
name|getuid
block|,
comment|/*  24 = getuid */
name|compat
argument_list|(
literal|1
argument_list|,
name|hpuxstime
argument_list|)
block|,
comment|/*  25 = old stime */
literal|4
block|,
name|hpuxptrace
block|,
comment|/*  26 = ptrace */
name|compat
argument_list|(
literal|1
argument_list|,
name|hpuxalarm
argument_list|)
block|,
comment|/*  27 = old alarm */
name|compat
argument_list|(
literal|2
argument_list|,
name|hpuxfstat
argument_list|)
block|,
comment|/*  28 = old fstat */
name|compat
argument_list|(
literal|0
argument_list|,
name|hpuxpause
argument_list|)
block|,
comment|/*  29 = opause */
name|compat
argument_list|(
literal|2
argument_list|,
name|hpuxutime
argument_list|)
block|,
comment|/*  30 = old utime */
name|compat
argument_list|(
literal|2
argument_list|,
name|hpuxstty
argument_list|)
block|,
comment|/*  31 = HPUX style stty */
name|compat
argument_list|(
literal|2
argument_list|,
name|hpuxgtty
argument_list|)
block|,
comment|/*  32 = HPUX style gtty */
literal|2
block|,
name|saccess
block|,
comment|/*  33 = access */
name|compat
argument_list|(
literal|1
argument_list|,
name|hpuxnice
argument_list|)
block|,
comment|/*  34 = old nice */
name|compat
argument_list|(
literal|1
argument_list|,
name|hpuxftime
argument_list|)
block|,
comment|/*  35 = old ftime */
literal|0
block|,
name|sync
block|,
comment|/*  36 = sync */
literal|2
block|,
name|hpuxkill
block|,
comment|/*  37 = HPUX style kill */
literal|2
block|,
name|hpuxstat
block|,
comment|/*  38 = HPUX style stat */
name|compat
argument_list|(
literal|1
argument_list|,
name|hpuxsetpgrp
argument_list|)
block|,
comment|/*  39 = HPUX style old setpgrp */
literal|2
block|,
name|hpuxlstat
block|,
comment|/*  40 = HPUX style lstat */
literal|1
block|,
name|hpuxdup
block|,
comment|/*  41 = HPUX style dup */
literal|0
block|,
name|pipe
block|,
comment|/*  42 = pipe */
name|compat
argument_list|(
literal|1
argument_list|,
name|hpuxtimes
argument_list|)
block|,
comment|/*  43 = old times */
literal|4
block|,
name|profil
block|,
comment|/*  44 = profil */
literal|4
block|,
name|notimp
block|,
comment|/*  45 = ki_syscall */
literal|1
block|,
name|setgid
block|,
comment|/*  46 = setgid */
literal|0
block|,
name|getgid
block|,
comment|/*  47 = getgid */
name|compat
argument_list|(
literal|2
argument_list|,
name|hpuxssig
argument_list|)
block|,
comment|/*  48 = old sig */
literal|0
block|,
name|nosys
block|,
comment|/*  49 = reserved for USG */
literal|0
block|,
name|nosys
block|,
comment|/*  50 = reserved for USG */
literal|1
block|,
name|notimp
block|,
comment|/*  51 = acct */
literal|0
block|,
name|nosys
block|,
comment|/*  52 = old set phys addr */
literal|0
block|,
name|nosys
block|,
comment|/*  53 = old lock in core */
literal|3
block|,
name|hpuxioctl
block|,
comment|/*  54 = HPUX ioctl */
literal|4
block|,
name|notimp
block|,
comment|/*  55 = reboot */
literal|2
block|,
name|symlink
block|,
comment|/*  56 = symlink */
literal|3
block|,
name|hpuxuname
block|,
comment|/*  57 = HPUX uname */
literal|3
block|,
name|readlink
block|,
comment|/*  58 = readlink */
literal|3
block|,
name|execve
block|,
comment|/*  59 = execve */
literal|1
block|,
name|umask
block|,
comment|/*  60 = umask */
literal|1
block|,
name|chroot
block|,
comment|/*  61 = chroot */
literal|3
block|,
name|hpuxfcntl
block|,
comment|/*  62 = fcntl (swapped with fstat) */
literal|2
block|,
name|hpuxulimit
block|,
comment|/*  63 = HPUX ulimit */
literal|0
block|,
name|nosys
block|,
comment|/*  64 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  65 = nosys */
literal|0
block|,
name|vfork
block|,
comment|/*  66 = vfork */
literal|0
block|,
name|hpuxread
block|,
comment|/*  67 = old vread */
literal|0
block|,
name|hpuxwrite
block|,
comment|/*  68 = old vwrite */
literal|0
block|,
name|nosys
block|,
comment|/*  69 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  70 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  71 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  72 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  73 = nosys */
literal|3
block|,
name|notimp
block|,
comment|/*  74 = mprotect */
literal|0
block|,
name|nosys
block|,
comment|/*  75 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  76 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  77 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  78 = nosys */
literal|2
block|,
name|getgroups
block|,
comment|/*  79 = getgroups */
literal|2
block|,
name|setgroups
block|,
comment|/*  80 = setgroups */
literal|1
block|,
name|hpuxgetpgrp2
block|,
comment|/*  81 = HPUX getpgrp2 */
literal|2
block|,
name|hpuxsetpgrp2
block|,
comment|/*  82 = HPUX setpgrp2 */
literal|3
block|,
name|setitimer
block|,
comment|/*  83 = setitimer */
literal|3
block|,
name|hpuxwait3
block|,
comment|/*  84 = wait3 */
literal|1
block|,
name|notimp
block|,
comment|/*  85 = swapon */
literal|2
block|,
name|getitimer
block|,
comment|/*  86 = getitimer */
literal|0
block|,
name|nosys
block|,
comment|/*  87 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  88 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/*  89 = nosys */
literal|2
block|,
name|dup2
block|,
comment|/*  90 = dup2 */
literal|2
block|,
name|nosys
block|,
comment|/*  91 = nosys */
literal|2
block|,
name|hpuxfstat
block|,
comment|/*  92 = fstat (swapped with fcntl) */
literal|5
block|,
name|select
block|,
comment|/*  93 = select */
literal|0
block|,
name|nosys
block|,
comment|/*  94 = nosys */
literal|1
block|,
name|fsync
block|,
comment|/*  95 = fsync */
literal|0
block|,
name|nosys
block|,
comment|/*  96 = nosys */
literal|3
block|,
name|nosys
block|,
comment|/*  97 = nosys */
literal|2
block|,
name|nosys
block|,
comment|/*  98 = nosys */
literal|2
block|,
name|nosys
block|,
comment|/*  99 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 100 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 101 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 102 = nosys */
literal|1
block|,
name|sigreturn
block|,
comment|/* 103 = sigreturn (not HPUX) */
literal|2
block|,
name|nosys
block|,
comment|/* 104 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 105 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 106 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 107 = nosys */
literal|3
block|,
name|hpuxsigvec
block|,
comment|/* 108 = sigvec */
literal|1
block|,
name|hpuxsigblock
block|,
comment|/* 109 = sigblock */
literal|1
block|,
name|hpuxsigsetmask
block|,
comment|/* 110 = sigsetmask */
literal|1
block|,
name|hpuxsigpause
block|,
comment|/* 111 = sigpause */
literal|2
block|,
name|sigstack
block|,
comment|/* 112 = sigstack */
literal|0
block|,
name|nosys
block|,
comment|/* 113 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 114 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 115 = nosys */
literal|2
block|,
name|gettimeofday
block|,
comment|/* 116 = gettimeofday */
literal|0
block|,
name|nosys
block|,
comment|/* 117 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 118 = nosys */
literal|3
block|,
name|notimp
block|,
comment|/* 119 = hpib_io_stub */
literal|3
block|,
name|hpuxreadv
block|,
comment|/* 120 = readv */
literal|3
block|,
name|hpuxwritev
block|,
comment|/* 121 = writev */
literal|2
block|,
name|settimeofday
block|,
comment|/* 122 = settimeofday */
literal|3
block|,
name|fchown
block|,
comment|/* 123 = fchown */
literal|2
block|,
name|fchmod
block|,
comment|/* 124 = fchmod */
literal|0
block|,
name|nosys
block|,
comment|/* 125 = nosys */
literal|3
block|,
name|notimp
block|,
comment|/* 126 = setresuid */
literal|3
block|,
name|notimp
block|,
comment|/* 127 = setresgid */
literal|2
block|,
name|rename
block|,
comment|/* 128 = rename */
literal|2
block|,
name|truncate
block|,
comment|/* 129 = truncate */
literal|2
block|,
name|ftruncate
block|,
comment|/* 130 = ftruncate */
literal|0
block|,
name|nosys
block|,
comment|/* 131 = nosys */
literal|1
block|,
name|notimp
block|,
comment|/* 132 = sysconf */
literal|0
block|,
name|nosys
block|,
comment|/* 133 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 134 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 135 = nosys */
literal|2
block|,
name|mkdir
block|,
comment|/* 136 = mkdir */
literal|1
block|,
name|rmdir
block|,
comment|/* 137 = rmdir */
literal|0
block|,
name|nosys
block|,
comment|/* 138 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 139 = internal (4.2 sigreturn) */
literal|0
block|,
name|nosys
block|,
comment|/* 140 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 141 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 142 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 143 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 144 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 145 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 146 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 147 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 148 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 149 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 150 = nosys */
comment|/* 	 * HPUX specific syscalls 	 */
literal|3
block|,
name|notimp
block|,
comment|/* 151 = privgrp */
literal|2
block|,
name|hpuxrtprio
block|,
comment|/* 152 = rtprio */
literal|1
block|,
name|notimp
block|,
comment|/* 153 = plock */
literal|2
block|,
name|hpuxnetioctl
block|,
comment|/* 154 = BSD networking */
literal|4
block|,
name|hpuxlockf
block|,
comment|/* 155 = HPUX lockf */
literal|3
block|,
name|hpuxsemget
block|,
comment|/* 156 = semget */
literal|4
block|,
name|hpuxsemctl
block|,
comment|/* 157 = semctl */
literal|3
block|,
name|hpuxsemop
block|,
comment|/* 158 = semop */
literal|2
block|,
name|notimp
block|,
comment|/* 159 = msgget */
literal|3
block|,
name|notimp
block|,
comment|/* 160 = msgctl */
literal|4
block|,
name|notimp
block|,
comment|/* 161 = msgsnd */
literal|5
block|,
name|notimp
block|,
comment|/* 162 = msgrcv */
ifdef|#
directive|ifdef
name|SYSVSHM
literal|3
block|,
name|hpuxshmget
block|,
comment|/* 163 = shmget */
literal|3
block|,
name|hpuxshmctl
block|,
comment|/* 164 = shmctl */
literal|3
block|,
name|hpuxshmat
block|,
comment|/* 165 = shmat */
literal|1
block|,
name|hpuxshmdt
block|,
comment|/* 166 = shmdt */
else|#
directive|else
literal|3
block|,
name|notimp
block|,
comment|/* 163 = shmget */
literal|3
block|,
name|notimp
block|,
comment|/* 164 = shmctl */
literal|3
block|,
name|notimp
block|,
comment|/* 165 = shmat */
literal|1
block|,
name|notimp
block|,
comment|/* 166 = shmdt */
endif|#
directive|endif
literal|1
block|,
name|hpuxadvise
block|,
comment|/* 167 = m68020_advise */
literal|0
block|,
name|notimp
block|,
comment|/* 168 = dux_notconfigured */
literal|3
block|,
name|notimp
block|,
comment|/* 169 = cluster */
literal|4
block|,
name|notimp
block|,
comment|/* 170 = mkrnod */
literal|0
block|,
name|nosys
block|,
comment|/* 171 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 172 = dux_notconfigured */
literal|0
block|,
name|nosys
block|,
comment|/* 173 = nosys */
literal|3
block|,
name|hpuxgetcontext
block|,
comment|/* 174 = getcontext */
literal|0
block|,
name|nosys
block|,
comment|/* 175 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 176 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 177 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 178 = lsync */
literal|0
block|,
name|nosys
block|,
comment|/* 179 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 180 = mysite */
literal|0
block|,
name|notimp
block|,
comment|/* 181 = returnzero */
literal|0
block|,
name|nosys
block|,
comment|/* 182 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 183 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 184 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 185 = nosys */
literal|3
block|,
name|nosys
block|,
comment|/* 186 = setacl */
literal|3
block|,
name|nosys
block|,
comment|/* 187 = fsetacl */
literal|3
block|,
name|nosys
block|,
comment|/* 188 = getacl */
literal|3
block|,
name|nosys
block|,
comment|/* 189 = fgetacl */
literal|6
block|,
name|nosys
block|,
comment|/* 190 = getaccess */
literal|0
block|,
name|nosys
block|,
comment|/* 191 = getaudid */
literal|1
block|,
name|nosys
block|,
comment|/* 192 = setaudid */
literal|0
block|,
name|nosys
block|,
comment|/* 193 = getaudproc */
literal|1
block|,
name|nosys
block|,
comment|/* 194 = setaudproc */
literal|2
block|,
name|nosys
block|,
comment|/* 195 = getevent */
literal|2
block|,
name|nosys
block|,
comment|/* 196 = setevent */
literal|1
block|,
name|nosys
block|,
comment|/* 197 = audwrite */
literal|1
block|,
name|nosys
block|,
comment|/* 198 = audswitch */
literal|4
block|,
name|nosys
block|,
comment|/* 199 = audctl */
literal|3
block|,
name|hpuxwaitpid
block|,
comment|/* 200 = waitpid */
literal|0
block|,
name|nosys
block|,
comment|/* 201 = nosys */
literal|2
block|,
name|nosys
block|,
comment|/* 202 = netioctl */
literal|6
block|,
name|nosys
block|,
comment|/* 203 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 204 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 205 = nosys */
literal|9
block|,
name|nosys
block|,
comment|/* 206 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 207 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 208 = nosys */
literal|6
block|,
name|nosys
block|,
comment|/* 209 = nosys */
literal|5
block|,
name|nosys
block|,
comment|/* 210 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 211 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 212 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 213 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 214 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 215 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 216 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 217 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 218 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 219 = nosys */
literal|4
block|,
name|nosys
block|,
comment|/* 220 = nosys */
literal|10
block|,
name|nosys
block|,
comment|/* 221 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 222 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 223 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 224 = nosys */
literal|2
block|,
name|notimp
block|,
comment|/* 225 = pathconf */
literal|2
block|,
name|notimp
block|,
comment|/* 226 = fpathconf */
literal|0
block|,
name|nosys
block|,
comment|/* 227 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 228 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 229 = async_daemon */
literal|3
block|,
name|notimp
block|,
comment|/* 230 = nfs_fcntl */
literal|4
block|,
name|getdirentries
block|,
comment|/* 231 = getdirentries */
literal|2
block|,
name|hpuxgetdomainname
block|,
comment|/* 232 = getdomainname */
literal|2
block|,
name|notimp
block|,
comment|/* 233 = nfs_getfh */
literal|4
block|,
name|notimp
block|,
comment|/* 234 = vfsmount */
literal|1
block|,
name|notimp
block|,
comment|/* 235 = nfs_svc */
literal|2
block|,
name|hpuxsetdomainname
block|,
comment|/* 236 = setdomainname */
literal|0
block|,
name|notimp
block|,
comment|/* 237 = statfs */
literal|0
block|,
name|notimp
block|,
comment|/* 238 = fstatfs */
literal|3
block|,
name|notimp
block|,
comment|/* 239 = sigaction */
literal|3
block|,
name|notimp
block|,
comment|/* 240 = sigprocmask */
literal|1
block|,
name|notimp
block|,
comment|/* 241 = sigpending */
literal|1
block|,
name|notimp
block|,
comment|/* 242 = sigsuspend */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hpuxnsysent
init|=
sizeof|sizeof
argument_list|(
name|hpuxsysent
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|hpuxsysent
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

