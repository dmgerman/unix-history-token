begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)strings.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * adb - readonly data  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|VERSION
index|[]
init|=
literal|"\nVERSION VM/VAX4.3	DATE %G%\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|BADMOD
index|[]
init|=
literal|"bad modifier"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|BADCOM
index|[]
init|=
literal|"bad command"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|BADSYM
index|[]
init|=
literal|"symbol not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|BADLOC
index|[]
init|=
literal|"automatic variable not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NOCFN
index|[]
init|=
literal|"c routine not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NOMATCH
index|[]
init|=
literal|"cannot locate value"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NOBKPT
index|[]
init|=
literal|"no breakpoint set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NOADR
index|[]
init|=
literal|"address expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NOPCS
index|[]
init|=
literal|"no process"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|BADVAR
index|[]
init|=
literal|"bad variable"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|EXBKPT
index|[]
init|=
literal|"too many breakpoints"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ADDRWRAP
index|[]
init|=
literal|"address wrap around"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|BADEQ
index|[]
init|=
literal|"unexpected `='"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|BADWAIT
index|[]
init|=
literal|"wait error: process disappeared!"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ENDPCS
index|[]
init|=
literal|"process terminated"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NOFORK
index|[]
init|=
literal|"try again"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|BADSYN
index|[]
init|=
literal|"syntax error"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NOEOR
index|[]
init|=
literal|"newline expected"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|SZBKPT
index|[]
init|=
literal|"bkpt: command too long"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|LONGFIL
index|[]
init|=
literal|"filename too long"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|NOTOPEN
index|[]
init|=
literal|"cannot open"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|TOODEEP
index|[]
init|=
literal|"$<< nesting too deep"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|syscalls
index|[]
init|=
block|{
literal|"indir"
block|,
literal|"exit"
block|,
literal|"fork"
block|,
literal|"read"
block|,
literal|"write"
block|,
literal|"open"
block|,
literal|"close"
block|,
literal|"owait"
block|,
literal|"creat"
block|,
literal|"link"
block|,
literal|"unlink"
block|,
literal|"execv"
block|,
literal|"chdir"
block|,
literal|"otime"
block|,
literal|"mknod"
block|,
literal|"chmod"
block|,
literal|"chown"
block|,
literal|"obreak"
block|,
literal|"ostat"
block|,
literal|"lseek"
block|,
literal|"getpid"
block|,
literal|"mount"
block|,
literal|"umount"
block|,
literal|"osetuid"
block|,
literal|"getuid"
block|,
literal|"ostime"
block|,
literal|"ptrace"
block|,
literal|"oalarm"
block|,
literal|"ofstat"
block|,
literal|"opause"
block|,
literal|"outime"
block|,
literal|"ostty"
block|,
literal|"ogtty"
block|,
literal|"access"
block|,
literal|"onice"
block|,
literal|"oftime"
block|,
literal|"sync"
block|,
literal|"kill"
block|,
literal|"stat"
block|,
literal|"osetpgrp"
block|,
literal|"lstat"
block|,
literal|"dup"
block|,
literal|"pipe"
block|,
literal|"otimes"
block|,
literal|"profil"
block|,
literal|0
block|,
literal|"osetgid"
block|,
literal|"getgid"
block|,
literal|"osig"
block|,
literal|0
block|,
literal|0
block|,
literal|"acct"
block|,
literal|"ophys"
block|,
literal|"olock"
block|,
literal|"ioctl"
block|,
literal|"reboot"
block|,
literal|"ompxchan"
block|,
literal|"symlink"
block|,
literal|"readlink"
block|,
literal|"execve"
block|,
literal|"umask"
block|,
literal|"chroot"
block|,
literal|"fstat"
block|,
literal|0
block|,
literal|"getpagesize"
block|,
literal|"mremap"
block|,
literal|"vfork"
block|,
literal|"ovread"
block|,
literal|"ovwrite"
block|,
literal|"sbrk"
block|,
literal|"sstk"
block|,
literal|"mmap"
block|,
literal|"ovadvise"
block|,
literal|"munmap"
block|,
literal|"mprotect"
block|,
literal|"madvise"
block|,
literal|"vhangup"
block|,
literal|"ovlimit"
block|,
literal|"mincore"
block|,
literal|"getgroups"
block|,
literal|"setgroups"
block|,
literal|"getpgrp"
block|,
literal|"setpgrp"
block|,
literal|"setitimer"
block|,
literal|"wait"
block|,
literal|"swapon"
block|,
literal|"getitimer"
block|,
literal|"gethostname"
block|,
literal|"sethostname"
block|,
literal|"getdtablesize"
block|,
literal|"dup2"
block|,
literal|"getdopt"
block|,
literal|"fcntl"
block|,
literal|"select"
block|,
literal|"setdopt"
block|,
literal|"fsync"
block|,
literal|"setpriority"
block|,
literal|"socket"
block|,
literal|"connect"
block|,
literal|"accept"
block|,
literal|"getpriority"
block|,
literal|"send"
block|,
literal|"recv"
block|,
literal|"osocketaddr"
block|,
literal|"bind"
block|,
literal|"setsockopt"
block|,
literal|"listen"
block|,
literal|"ovtimes"
block|,
literal|"sigvec"
block|,
literal|"sigblock"
block|,
literal|"sigsetmask"
block|,
literal|"sigpause"
block|,
literal|"sigstack"
block|,
literal|"recvmsg"
block|,
literal|"sendmsg"
block|,
literal|"vtrace"
block|,
literal|"gettimeofday"
block|,
literal|"getrusage"
block|,
literal|"getsockopt"
block|,
literal|"resuba"
block|,
literal|"readv"
block|,
literal|"writev"
block|,
literal|"settimeofday"
block|,
literal|"fchown"
block|,
literal|"fchmod"
block|,
literal|"recvfrom"
block|,
literal|"setreuid"
block|,
literal|"setregid"
block|,
literal|"rename"
block|,
literal|"truncate"
block|,
literal|"ftruncate"
block|,
literal|"flock"
block|,
literal|0
block|,
literal|"sendto"
block|,
literal|"shutdown"
block|,
literal|"socketpair"
block|,
literal|"mkdir"
block|,
literal|"rmdir"
block|,
literal|"utimes"
block|,
literal|0
block|,
literal|0
block|,
literal|"getpeername"
block|,
literal|"gethostid"
block|,
literal|"sethostid"
block|,
literal|"getrlimit"
block|,
literal|"setrlimit"
block|,
literal|"killpg"
block|,
literal|0
block|,
literal|"quota"
block|,
literal|"qquota"
block|,
literal|"getsockname"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsys
init|=
sizeof|sizeof
argument_list|(
name|syscalls
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|syscalls
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

