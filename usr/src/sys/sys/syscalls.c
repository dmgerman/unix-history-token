begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)syscalls.c	7.2 (Berkeley) 7/10/87  */
end_comment

begin_comment
comment|/*  * System call names.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|syscallnames
index|[]
init|=
block|{
literal|"indir"
block|,
comment|/*   0 = indir */
literal|"exit"
block|,
comment|/*   1 = exit */
literal|"fork"
block|,
comment|/*   2 = fork */
literal|"read"
block|,
comment|/*   3 = read */
literal|"write"
block|,
comment|/*   4 = write */
literal|"open"
block|,
comment|/*   5 = open */
literal|"close"
block|,
comment|/*   6 = close */
literal|"old wait"
block|,
comment|/*   7 = old wait */
literal|"creat"
block|,
comment|/*   8 = creat */
literal|"link"
block|,
comment|/*   9 = link */
literal|"unlink"
block|,
comment|/*  10 = unlink */
literal|"execv"
block|,
comment|/*  11 = execv */
literal|"chdir"
block|,
comment|/*  12 = chdir */
literal|"old time"
block|,
comment|/*  13 = old time */
literal|"mknod"
block|,
comment|/*  14 = mknod */
literal|"chmod"
block|,
comment|/*  15 = chmod */
literal|"chown"
block|,
comment|/*  16 = chown; now 3 args */
literal|"old break"
block|,
comment|/*  17 = old break */
literal|"old stat"
block|,
comment|/*  18 = old stat */
literal|"lseek"
block|,
comment|/*  19 = lseek */
literal|"getpid"
block|,
comment|/*  20 = getpid */
literal|"mount"
block|,
comment|/*  21 = mount */
literal|"umount"
block|,
comment|/*  22 = umount */
literal|"old setuid"
block|,
comment|/*  23 = old setuid */
literal|"getuid"
block|,
comment|/*  24 = getuid */
literal|"old stime"
block|,
comment|/*  25 = old stime */
literal|"ptrace"
block|,
comment|/*  26 = ptrace */
literal|"old alarm"
block|,
comment|/*  27 = old alarm */
literal|"old fstat"
block|,
comment|/*  28 = old fstat */
literal|"old pause"
block|,
comment|/*  29 = old pause */
literal|"old utime"
block|,
comment|/*  30 = old utime */
literal|"old stty - nosys"
block|,
comment|/*  31 = old stty */
literal|"old gtty - nosys"
block|,
comment|/*  32 = old gtty */
literal|"access"
block|,
comment|/*  33 = access */
literal|"old nice"
block|,
comment|/*  34 = old nice */
literal|"old ftime"
block|,
comment|/*  35 = old ftime */
literal|"sync"
block|,
comment|/*  36 = sync */
literal|"kill"
block|,
comment|/*  37 = kill */
literal|"stat"
block|,
comment|/*  38 = stat */
literal|"old setpgrp"
block|,
comment|/*  39 = old setpgrp */
literal|"lstat"
block|,
comment|/*  40 = lstat */
literal|"dup"
block|,
comment|/*  41 = dup */
literal|"pipe"
block|,
comment|/*  42 = pipe */
literal|"old times"
block|,
comment|/*  43 = old times */
literal|"profil"
block|,
comment|/*  44 = profil */
literal|"#45"
block|,
comment|/*  45 = nosys */
literal|"old setgid"
block|,
comment|/*  46 = old setgid */
literal|"getgid"
block|,
comment|/*  47 = getgid */
literal|"old signal"
block|,
comment|/*  48 = old sig */
literal|"#49"
block|,
comment|/*  49 = reserved for USG */
literal|"#50"
block|,
comment|/*  50 = reserved for USG */
literal|"acct"
block|,
comment|/*  51 = turn acct off/on */
literal|"old phys - nosys"
block|,
comment|/*  52 = old set phys addr */
literal|"old lock - nosys"
block|,
comment|/*  53 = old lock in core */
literal|"ioctl"
block|,
comment|/*  54 = ioctl */
literal|"reboot"
block|,
comment|/*  55 = reboot */
literal|"old mpx - nosys"
block|,
comment|/*  56 = old mpxchan */
literal|"symlink"
block|,
comment|/*  57 = symlink */
literal|"readlink"
block|,
comment|/*  58 = readlink */
literal|"execve"
block|,
comment|/*  59 = execve */
literal|"umask"
block|,
comment|/*  60 = umask */
literal|"chroot"
block|,
comment|/*  61 = chroot */
literal|"fstat"
block|,
comment|/*  62 = fstat */
literal|"#63"
block|,
comment|/*  63 = used internally */
literal|"getpagesize"
block|,
comment|/*  64 = getpagesize */
literal|"msync"
block|,
comment|/*  65 = msync */
literal|"vfork"
block|,
comment|/*  66 = vfork */
literal|"old vread - read"
block|,
comment|/*  67 = old vread */
literal|"old vwrite - write"
block|,
comment|/*  68 = old vwrite */
literal|"sbrk"
block|,
comment|/*  69 = sbrk */
literal|"sstk"
block|,
comment|/*  70 = sstk */
literal|"mmap"
block|,
comment|/*  71 = mmap */
literal|"old vadvise"
block|,
comment|/*  72 = old vadvise */
literal|"munmap"
block|,
comment|/*  73 = munmap */
literal|"mprotect"
block|,
comment|/*  74 = mprotect */
literal|"madvise"
block|,
comment|/*  75 = madvise */
literal|"vhangup"
block|,
comment|/*  76 = vhangup */
literal|"old vlimit"
block|,
comment|/*  77 = old vlimit */
literal|"mincore"
block|,
comment|/*  78 = mincore */
literal|"getgroups"
block|,
comment|/*  79 = getgroups */
literal|"setgroups"
block|,
comment|/*  80 = setgroups */
literal|"getpgrp"
block|,
comment|/*  81 = getpgrp */
literal|"setpgrp"
block|,
comment|/*  82 = setpgrp */
literal|"setitimer"
block|,
comment|/*  83 = setitimer */
literal|"wait"
block|,
comment|/*  84 = wait */
literal|"swapon"
block|,
comment|/*  85 = swapon */
literal|"getitimer"
block|,
comment|/*  86 = getitimer */
literal|"gethostname"
block|,
comment|/*  87 = gethostname */
literal|"sethostname"
block|,
comment|/*  88 = sethostname */
literal|"getdtablesize"
block|,
comment|/*  89 = getdtablesize */
literal|"dup2"
block|,
comment|/*  90 = dup2 */
literal|"getdopt"
block|,
comment|/*  91 = getdopt */
literal|"fcntl"
block|,
comment|/*  92 = fcntl */
literal|"select"
block|,
comment|/*  93 = select */
literal|"setdopt"
block|,
comment|/*  94 = setdopt */
literal|"fsync"
block|,
comment|/*  95 = fsync */
literal|"setpriority"
block|,
comment|/*  96 = setpriority */
literal|"socket"
block|,
comment|/*  97 = socket */
literal|"connect"
block|,
comment|/*  98 = connect */
literal|"accept"
block|,
comment|/*  99 = accept */
literal|"getpriority"
block|,
comment|/* 100 = getpriority */
literal|"send"
block|,
comment|/* 101 = send */
literal|"recv"
block|,
comment|/* 102 = recv */
literal|"sigreturn"
block|,
comment|/* 103 = sigreturn */
literal|"bind"
block|,
comment|/* 104 = bind */
literal|"setsockopt"
block|,
comment|/* 105 = setsockopt */
literal|"listen"
block|,
comment|/* 106 = listen */
literal|"old vtimes"
block|,
comment|/* 107 = old vtimes */
literal|"sigvec"
block|,
comment|/* 108 = sigvec */
literal|"sigblock"
block|,
comment|/* 109 = sigblock */
literal|"sigsetmask"
block|,
comment|/* 110 = sigsetmask */
literal|"sigpause"
block|,
comment|/* 111 = sigpause */
literal|"sigstack"
block|,
comment|/* 112 = sigstack */
literal|"recvmsg"
block|,
comment|/* 113 = recvmsg */
literal|"sendmsg"
block|,
comment|/* 114 = sendmsg */
ifdef|#
directive|ifdef
name|TRACE
literal|"old vtrace"
block|,
comment|/* 115 = old vtrace */
else|#
directive|else
literal|"#115"
block|,
comment|/* 115 = nosys */
endif|#
directive|endif
literal|"gettimeofday"
block|,
comment|/* 116 = gettimeofday */
literal|"getrusage"
block|,
comment|/* 117 = getrusage */
literal|"getsockopt"
block|,
comment|/* 118 = getsockopt */
ifdef|#
directive|ifdef
name|vax
literal|"resuba"
block|,
comment|/* 119 = resuba */
else|#
directive|else
literal|"#119"
block|,
comment|/* 119 = nosys */
endif|#
directive|endif
literal|"readv"
block|,
comment|/* 120 = readv */
literal|"writev"
block|,
comment|/* 121 = writev */
literal|"settimeofday"
block|,
comment|/* 122 = settimeofday */
literal|"fchown"
block|,
comment|/* 123 = fchown */
literal|"fchmod"
block|,
comment|/* 124 = fchmod */
literal|"recvfrom"
block|,
comment|/* 125 = recvfrom */
literal|"setreuid"
block|,
comment|/* 126 = setreuid */
literal|"setregid"
block|,
comment|/* 127 = setregid */
literal|"rename"
block|,
comment|/* 128 = rename */
literal|"truncate"
block|,
comment|/* 129 = truncate */
literal|"ftruncate"
block|,
comment|/* 130 = ftruncate */
literal|"flock"
block|,
comment|/* 131 = flock */
literal|"old portal - nosys"
block|,
comment|/* 132 = old portal */
literal|"sendto"
block|,
comment|/* 133 = sendto */
literal|"shutdown"
block|,
comment|/* 134 = shutdown */
literal|"socketpair"
block|,
comment|/* 135 = socketpair */
literal|"mkdir"
block|,
comment|/* 136 = mkdir */
literal|"rmdir"
block|,
comment|/* 137 = rmdir */
literal|"utimes"
block|,
comment|/* 138 = utimes */
literal|"4.2 sigreturn"
block|,
comment|/* 139 = old 4.2 sigreturn */
literal|"adjtime"
block|,
comment|/* 140 = adjtime */
literal|"getpeername"
block|,
comment|/* 141 = getpeername */
literal|"gethostid"
block|,
comment|/* 142 = gethostid */
literal|"sethostid"
block|,
comment|/* 143 = sethostid */
literal|"getrlimit"
block|,
comment|/* 144 = getrlimit */
literal|"setrlimit"
block|,
comment|/* 145 = setrlimit */
literal|"killpg"
block|,
comment|/* 146 = killpg */
literal|"#147"
block|,
comment|/* 147 = nosys */
literal|"setquota"
block|,
comment|/* 148 = setquota */
literal|"quota"
block|,
comment|/* 149 = quota */
literal|"getsockname"
block|,
comment|/* 150 = getsockname */
block|}
decl_stmt|;
end_decl_stmt

end_unit

