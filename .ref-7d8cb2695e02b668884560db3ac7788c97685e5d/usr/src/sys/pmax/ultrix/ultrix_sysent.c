begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: hpux_sysent.c 1.1 90/07/09$  *  *	@(#)ultrix_sysent.c	7.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * System call switch table.  */
end_comment

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

begin_decl_stmt
name|int
name|nosys
argument_list|()
decl_stmt|,
name|notimp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|rexit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ocreat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|link
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mknod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|obreak
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ptrace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|saccess
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ostat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|olstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pipe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|profil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ultrixtobsd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioctl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reboot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|symlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execve
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|umask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chroot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ogetpagesize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sstk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getgroups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setgroups
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ultrixgetpgrp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ultrixsetpgrp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setitimer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ultrixwait3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getitimer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ogethostname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osethostname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getdtablesize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dup2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fcntl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|select
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fsync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpriority
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|connect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oaccept
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpriority
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|orecv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigreturn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setsockopt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|listen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ultrixsigvec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osigblock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osigsetmask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigsuspend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osigstack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|orecvmsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osendmsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gettimeofday
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getrusage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getsockopt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|writev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|settimeofday
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fchown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fchmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|orecvfrom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osetreuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osetregid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|truncate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ftruncate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|flock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sendto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shutdown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|socketpair
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rmdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|utimes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adjtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ogetpeername
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ogethostid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osethostid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getrlimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setrlimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|okillpg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ogetsockname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ogetdirentries
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ultrixgetdomainname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ultrixsetdomainname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ultrixgetsysinfo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reserved/unimplemented system calls in the range 0-150 inclusive  * are reserved for use in future Berkeley releases.  * Additional system calls implemented in vendor and other  * redistributions should be placed in the reserved range at the end  * of the current calls.  */
end_comment

begin_decl_stmt
name|struct
name|sysent
name|ultrixsysent
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
name|read
block|,
comment|/*   3 = read */
literal|3
block|,
name|write
block|,
comment|/*   4 = write */
literal|3
block|,
name|open
block|,
comment|/*   5 = open */
literal|1
block|,
name|close
block|,
comment|/*   6 = close */
literal|0
block|,
name|nosys
block|,
comment|/*   7 = old wait */
literal|2
block|,
name|ocreat
block|,
comment|/*   8 = creat */
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
literal|0
block|,
name|nosys
block|,
comment|/*  11 = old execv */
literal|1
block|,
name|chdir
block|,
comment|/*  12 = chdir */
literal|0
block|,
name|nosys
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
comment|/*  16 = chown */
literal|1
block|,
name|obreak
block|,
comment|/*  17 = old break */
literal|0
block|,
name|nosys
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
literal|0
block|,
name|nosys
block|,
comment|/*  23 = old setuid */
literal|0
block|,
name|getuid
block|,
comment|/*  24 = getuid */
literal|0
block|,
name|nosys
block|,
comment|/*  25 = old stime */
literal|4
block|,
name|ptrace
block|,
comment|/*  26 = ptrace */
literal|0
block|,
name|nosys
block|,
comment|/*  27 = old alarm */
literal|0
block|,
name|nosys
block|,
comment|/*  28 = old fstat */
literal|0
block|,
name|nosys
block|,
comment|/*  29 = old pause */
literal|0
block|,
name|nosys
block|,
comment|/*  30 = old utime */
literal|0
block|,
name|nosys
block|,
comment|/*  31 = old stty */
literal|0
block|,
name|nosys
block|,
comment|/*  32 = old gtty */
literal|2
block|,
name|saccess
block|,
comment|/*  33 = access */
literal|0
block|,
name|nosys
block|,
comment|/*  34 = old nice */
literal|0
block|,
name|nosys
block|,
comment|/*  35 = old ftime */
literal|0
block|,
name|sync
block|,
comment|/*  36 = sync */
literal|2
block|,
name|kill
block|,
comment|/*  37 = kill */
literal|2
block|,
name|ostat
block|,
comment|/*  38 = stat */
literal|0
block|,
name|nosys
block|,
comment|/*  39 = old setpgrp */
literal|2
block|,
name|olstat
block|,
comment|/*  40 = lstat */
literal|1
block|,
name|dup
block|,
comment|/*  41 = dup */
literal|1
block|,
name|pipe
block|,
comment|/*  42 = pipe */
literal|0
block|,
name|nosys
block|,
comment|/*  43 = old times */
literal|4
block|,
name|profil
block|,
comment|/*  44 = profil */
literal|0
block|,
name|ultrixtobsd
block|,
comment|/*  45 = unused */
literal|0
block|,
name|nosys
block|,
comment|/*  46 = old setgid */
literal|0
block|,
name|getgid
block|,
comment|/*  47 = getgid */
literal|0
block|,
name|nosys
block|,
comment|/*  48 = old sigsys */
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
name|ioctl
block|,
comment|/*  54 = ioctl */
literal|1
block|,
name|reboot
block|,
comment|/*  55 = reboot */
literal|0
block|,
name|nosys
block|,
comment|/*  56 = old mpxchan */
literal|2
block|,
name|symlink
block|,
comment|/*  57 = symlink */
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
literal|2
block|,
name|ofstat
block|,
comment|/*  62 = fstat */
literal|0
block|,
name|nosys
block|,
comment|/*  63 = unused */
literal|0
block|,
name|ogetpagesize
block|,
comment|/*  64 = getpagesize */
literal|0
block|,
name|notimp
block|,
comment|/*  65 = mremap */
literal|0
block|,
name|vfork
block|,
comment|/*  66 = vfork */
literal|0
block|,
name|nosys
block|,
comment|/*  67 = old vread */
literal|0
block|,
name|nosys
block|,
comment|/*  68 = old vwrite */
literal|1
block|,
name|sbrk
block|,
comment|/*  69 = sbrk */
literal|1
block|,
name|sstk
block|,
comment|/*  70 = sstk */
literal|0
block|,
name|nosys
block|,
comment|/*  71 = mmap */
literal|0
block|,
name|nosys
block|,
comment|/*  72 = old vadvise */
literal|0
block|,
name|notimp
block|,
comment|/*  73 = munmap */
literal|0
block|,
name|notimp
block|,
comment|/*  74 = mprotect */
literal|0
block|,
name|notimp
block|,
comment|/*  75 = madvise */
literal|0
block|,
name|notimp
block|,
comment|/*  76 = vhangup */
literal|0
block|,
name|nosys
block|,
comment|/*  77 = old vlimit */
literal|0
block|,
name|nosys
block|,
comment|/*  78 = mincore */
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
name|ultrixgetpgrp
block|,
comment|/*  81 = getpgrp */
literal|2
block|,
name|ultrixsetpgrp
block|,
comment|/*  82 = setpgrp */
literal|3
block|,
name|setitimer
block|,
comment|/*  83 = setitimer */
literal|3
block|,
name|ultrixwait3
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
literal|2
block|,
name|ogethostname
block|,
comment|/*  87 = gethostname */
literal|2
block|,
name|osethostname
block|,
comment|/*  88 = sethostname */
literal|0
block|,
name|getdtablesize
block|,
comment|/*  89 = getdtablesize */
literal|2
block|,
name|dup2
block|,
comment|/*  90 = dup2 */
literal|0
block|,
name|notimp
block|,
comment|/*  91 = getdopt */
literal|3
block|,
name|fcntl
block|,
comment|/*  92 = fcntl */
literal|5
block|,
name|select
block|,
comment|/*  93 = select */
literal|0
block|,
name|notimp
block|,
comment|/*  94 = setdopt */
literal|1
block|,
name|fsync
block|,
comment|/*  95 = fsync */
literal|3
block|,
name|setpriority
block|,
comment|/*  96 = setpriority */
literal|3
block|,
name|socket
block|,
comment|/*  97 = socket */
literal|3
block|,
name|connect
block|,
comment|/*  98 = connect */
literal|3
block|,
name|oaccept
block|,
comment|/*  99 = accept */
literal|2
block|,
name|getpriority
block|,
comment|/* 100 = getpriority */
literal|4
block|,
name|osend
block|,
comment|/* 101 = send */
literal|4
block|,
name|orecv
block|,
comment|/* 102 = recv */
literal|1
block|,
name|sigreturn
block|,
comment|/* 103 = sigreturn */
literal|3
block|,
name|bind
block|,
comment|/* 104 = bind */
literal|5
block|,
name|setsockopt
block|,
comment|/* 105 = setsockopt */
literal|2
block|,
name|listen
block|,
comment|/* 106 = listen */
literal|0
block|,
name|nosys
block|,
comment|/* 107 = old vtimes */
literal|4
block|,
name|ultrixsigvec
block|,
comment|/* 108 = sigvec */
literal|1
block|,
name|osigblock
block|,
comment|/* 109 = sigblock */
literal|1
block|,
name|osigsetmask
block|,
comment|/* 110 = sigsetmask */
literal|1
block|,
name|sigsuspend
block|,
comment|/* 111 = sigpause */
literal|2
block|,
name|osigstack
block|,
comment|/* 112 = sigstack */
literal|3
block|,
name|orecvmsg
block|,
comment|/* 113 = recvmsg */
literal|3
block|,
name|osendmsg
block|,
comment|/* 114 = sendmsg */
literal|0
block|,
name|nosys
block|,
comment|/* 115 = old vtrace */
literal|2
block|,
name|gettimeofday
block|,
comment|/* 116 = gettimeofday */
literal|2
block|,
name|getrusage
block|,
comment|/* 117 = getrusage */
literal|5
block|,
name|getsockopt
block|,
comment|/* 118 = getsockopt */
literal|0
block|,
name|nosys
block|,
comment|/* 119 = old resuba */
literal|3
block|,
name|readv
block|,
comment|/* 120 = readv */
literal|3
block|,
name|writev
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
literal|6
block|,
name|orecvfrom
block|,
comment|/* 125 = recvfrom */
literal|2
block|,
name|osetreuid
block|,
comment|/* 126 = setreuid */
literal|2
block|,
name|osetregid
block|,
comment|/* 127 = setregid */
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
literal|2
block|,
name|flock
block|,
comment|/* 131 = flock */
literal|0
block|,
name|nosys
block|,
comment|/* 132 = nosys */
literal|6
block|,
name|sendto
block|,
comment|/* 133 = sendto */
literal|2
block|,
name|shutdown
block|,
comment|/* 134 = shutdown */
literal|5
block|,
name|socketpair
block|,
comment|/* 135 = socketpair */
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
literal|2
block|,
name|utimes
block|,
comment|/* 138 = utimes */
literal|1
block|,
name|sigreturn
block|,
comment|/* 139 = internal (4.2 sigreturn) */
literal|2
block|,
name|adjtime
block|,
comment|/* 140 = adjtime */
literal|3
block|,
name|ogetpeername
block|,
comment|/* 141 = getpeername */
literal|2
block|,
name|ogethostid
block|,
comment|/* 142 = gethostid */
literal|2
block|,
name|osethostid
block|,
comment|/* 143 = sethostid */
literal|2
block|,
name|getrlimit
block|,
comment|/* 144 = getrlimit */
literal|2
block|,
name|setrlimit
block|,
comment|/* 145 = setrlimit */
literal|2
block|,
name|okillpg
block|,
comment|/* 146 = killpg */
literal|0
block|,
name|nosys
block|,
comment|/* 147 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 148 = setquota */
literal|0
block|,
name|notimp
block|,
comment|/* 149 = quota */
literal|3
block|,
name|ogetsockname
block|,
comment|/* 150 = getsockname */
comment|/* 	 * ULTRIX specific syscalls 	 */
literal|0
block|,
name|notimp
block|,
comment|/* 151 = sysmips */
literal|0
block|,
name|notimp
block|,
comment|/* 152 = cacheflush */
literal|0
block|,
name|notimp
block|,
comment|/* 153 = cachectl */
literal|0
block|,
name|notimp
block|,
comment|/* 154 = debug */
literal|0
block|,
name|nosys
block|,
comment|/* 155 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 156 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 157 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 158 = nfs_svc */
literal|4
block|,
name|ogetdirentries
block|,
comment|/* 159 = getdirentries */
literal|0
block|,
name|nosys
block|,
comment|/* 160 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 161 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 162 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 163 = nfs_biod */
literal|0
block|,
name|notimp
block|,
comment|/* 164 = nfs_getfh */
literal|0
block|,
name|ultrixgetdomainname
block|,
comment|/* 165 = getdomainname */
literal|0
block|,
name|ultrixsetdomainname
block|,
comment|/* 166 = setdomainname */
literal|0
block|,
name|nosys
block|,
comment|/* 167 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 168 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 169 = exportfs */
literal|0
block|,
name|nosys
block|,
comment|/* 170 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 171 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 172 = msgctl */
literal|0
block|,
name|notimp
block|,
comment|/* 173 = msgget */
literal|0
block|,
name|notimp
block|,
comment|/* 174 = msgrcv */
literal|0
block|,
name|notimp
block|,
comment|/* 175 = msgsnd */
literal|0
block|,
name|notimp
block|,
comment|/* 176 = semctl */
literal|0
block|,
name|notimp
block|,
comment|/* 177 = semget */
literal|0
block|,
name|notimp
block|,
comment|/* 178 = semop */
literal|0
block|,
name|notimp
block|,
comment|/* 179 = uname */
literal|0
block|,
name|notimp
block|,
comment|/* 180 = shmsys */
literal|0
block|,
name|notimp
block|,
comment|/* 181 = plock */
literal|0
block|,
name|notimp
block|,
comment|/* 182 = lockf */
literal|0
block|,
name|notimp
block|,
comment|/* 183 = ustat */
literal|0
block|,
name|notimp
block|,
comment|/* 184 = getmnt */
literal|0
block|,
name|notimp
block|,
comment|/* 185 = mount */
literal|0
block|,
name|notimp
block|,
comment|/* 186 = umount */
literal|0
block|,
name|notimp
block|,
comment|/* 187 = sigpending */
literal|0
block|,
name|nosys
block|,
comment|/* 188 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 189 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 190 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 191 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 192 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 193 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 194 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 195 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 196 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 197 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 198 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 199 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 200 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 201 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 202 = nosys */
literal|0
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
literal|0
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
literal|0
block|,
name|nosys
block|,
comment|/* 209 = nosys */
literal|0
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
literal|0
block|,
name|nosys
block|,
comment|/* 220 = nosys */
literal|0
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
literal|0
block|,
name|nosys
block|,
comment|/* 225 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 226 = nosys */
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
name|nosys
block|,
comment|/* 229 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 230 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 231 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 232 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 233 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 234 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 235 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 236 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 237 = nosys */
literal|0
block|,
name|notimp
block|,
comment|/* 238 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 239 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 240 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 241 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 242 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 243 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 244 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 245 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 246 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 247 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 248 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 249 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 250 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 251 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 252 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 253 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 254 = nosys */
literal|0
block|,
name|nosys
block|,
comment|/* 255 = nosys */
literal|0
block|,
name|ultrixgetsysinfo
block|,
comment|/* 256 = getsysinfo */
literal|0
block|,
name|notimp
block|,
comment|/* 257 = setsysinfo */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ultrixnsysent
init|=
sizeof|sizeof
argument_list|(
name|ultrixsysent
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ultrixsysent
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

