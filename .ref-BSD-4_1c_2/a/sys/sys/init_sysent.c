begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	init_sysent.c	4.34	83/01/13	*/
end_comment

begin_comment
comment|/*  * System call switch table.  */
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/systm.h"
end_include

begin_function_decl
name|int
name|nosys
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 1.1 processes and protection */
end_comment

begin_decl_stmt
name|int
name|sethostid
argument_list|()
decl_stmt|,
name|gethostid
argument_list|()
decl_stmt|,
name|sethostname
argument_list|()
decl_stmt|,
name|gethostname
argument_list|()
decl_stmt|,
name|getpid
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
decl_stmt|,
name|wait
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getuid
argument_list|()
decl_stmt|,
name|setreuid
argument_list|()
decl_stmt|,
name|getgid
argument_list|()
decl_stmt|,
name|getgroups
argument_list|()
decl_stmt|,
name|setregid
argument_list|()
decl_stmt|,
name|setgroups
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getpgrp
argument_list|()
decl_stmt|,
name|setpgrp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2 memory management */
end_comment

begin_decl_stmt
name|int
name|sbrk
argument_list|()
decl_stmt|,
name|sstk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getpagesize
argument_list|()
decl_stmt|,
name|smmap
argument_list|()
decl_stmt|,
name|mremap
argument_list|()
decl_stmt|,
name|munmap
argument_list|()
decl_stmt|,
name|mprotect
argument_list|()
decl_stmt|,
name|madvise
argument_list|()
decl_stmt|,
name|mincore
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.3 signals XXX still old XXX */
end_comment

begin_decl_stmt
name|int
name|sigvec
argument_list|()
decl_stmt|,
name|sigblock
argument_list|()
decl_stmt|,
name|sigsetmask
argument_list|()
decl_stmt|,
name|sigpause
argument_list|()
decl_stmt|,
name|sigstack
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_function_decl
name|int
name|kill
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|killpg
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
name|getdtablesize
argument_list|()
decl_stmt|,
name|getdprop
argument_list|()
decl_stmt|,
name|dup
argument_list|()
decl_stmt|,
name|dup2
argument_list|()
decl_stmt|,
name|close
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|select
argument_list|()
decl_stmt|,
name|getdopt
argument_list|()
decl_stmt|,
name|setdopt
argument_list|()
decl_stmt|,
name|wrap
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.6 resource controls */
end_comment

begin_decl_stmt
name|int
name|getpriority
argument_list|()
decl_stmt|,
name|setpriority
argument_list|()
decl_stmt|,
name|getrusage
argument_list|()
decl_stmt|,
name|getrlimit
argument_list|()
decl_stmt|,
name|setrlimit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|QUOTA
end_ifdef

begin_decl_stmt
name|int
name|setquota
argument_list|()
decl_stmt|,
name|qquota
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MUSH
end_ifdef

begin_function_decl
name|int
name|mu_msg
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 1.7 system operation support */
end_comment

begin_function_decl
name|int
name|unmount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smount
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
name|int
name|swapon
argument_list|()
decl_stmt|,
name|swapoff
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|sync
argument_list|()
decl_stmt|,
name|reboot
argument_list|()
decl_stmt|,
name|sysacct
argument_list|()
decl_stmt|,
name|revoke
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2.1 generic operations */
end_comment

begin_decl_stmt
name|int
name|read
argument_list|()
decl_stmt|,
name|write
argument_list|()
decl_stmt|,
name|readv
argument_list|()
decl_stmt|,
name|writev
argument_list|()
decl_stmt|,
name|ioctl
argument_list|()
decl_stmt|;
end_decl_stmt

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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|open
argument_list|()
decl_stmt|,
name|mknod
argument_list|()
decl_stmt|,
name|portal
argument_list|()
decl_stmt|,
name|unlink
argument_list|()
decl_stmt|,
name|stat
argument_list|()
decl_stmt|,
name|fstat
argument_list|()
decl_stmt|,
name|lstat
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
decl_stmt|,
name|utimes
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
name|flock
argument_list|()
decl_stmt|,
name|fsync
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2.3 communications */
end_comment

begin_decl_stmt
name|int
name|socket
argument_list|()
decl_stmt|,
name|bind
argument_list|()
decl_stmt|,
name|listen
argument_list|()
decl_stmt|,
name|accept
argument_list|()
decl_stmt|,
name|connect
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|socketpair
argument_list|()
decl_stmt|,
name|sendto
argument_list|()
decl_stmt|,
name|send
argument_list|()
decl_stmt|,
name|recvfrom
argument_list|()
decl_stmt|,
name|recv
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sendmsg
argument_list|()
decl_stmt|,
name|recvmsg
argument_list|()
decl_stmt|,
name|shutdown
argument_list|()
decl_stmt|,
name|setsockopt
argument_list|()
decl_stmt|,
name|getsockopt
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|pipe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssocketaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

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

begin_function_decl
name|int
name|ptrace
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 2.5 terminals */
end_comment

begin_comment
comment|/* emulations for backwards compatibility */
end_comment

begin_function_decl
name|int
name|owait
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now receive message on channel */
end_comment

begin_function_decl
name|int
name|ocreat
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use 3 arg open */
end_comment

begin_function_decl
name|int
name|otime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use gettimeofday */
end_comment

begin_function_decl
name|int
name|obreak
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use sbrk */
end_comment

begin_function_decl
name|int
name|oumount
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use unmount */
end_comment

begin_function_decl
name|int
name|ostime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use settimeofday */
end_comment

begin_function_decl
name|int
name|oalarm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use setitimer */
end_comment

begin_function_decl
name|int
name|outime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use utimes */
end_comment

begin_decl_stmt
name|int
name|ostty
argument_list|()
decl_stmt|,
name|ogtty
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* now use ioctl */
end_comment

begin_function_decl
name|int
name|opause
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use sigpause */
end_comment

begin_function_decl
name|int
name|onice
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use setpriority,getpriority */
end_comment

begin_function_decl
name|int
name|oftime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use gettimeofday */
end_comment

begin_function_decl
name|int
name|okill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osetpgrp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ??? */
end_comment

begin_function_decl
name|int
name|otimes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use getrusage */
end_comment

begin_function_decl
name|int
name|ossig
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use sigvec, etc */
end_comment

begin_function_decl
name|int
name|vfork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ovadvise
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use madvise */
end_comment

begin_function_decl
name|int
name|ovlimit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use setlimit,getlimit */
end_comment

begin_function_decl
name|int
name|oswapon
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now pass more information */
end_comment

begin_function_decl
name|int
name|ovtimes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use getrusage */
end_comment

begin_function_decl
name|int
name|osetuid
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use setreuid */
end_comment

begin_function_decl
name|int
name|osetgid
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use setregid */
end_comment

begin_function_decl
name|int
name|ostat
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use stat */
end_comment

begin_function_decl
name|int
name|ofstat
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* now use fstat */
end_comment

begin_comment
comment|/* mpxchan: now emulated yields core dump */
end_comment

begin_comment
comment|/* BEGIN JUNK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_function_decl
name|int
name|resuba
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|profil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vhangup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* should just do in exit() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_function_decl
name|int
name|vtrace
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END JUNK */
end_comment

begin_decl_stmt
name|struct
name|sysent
name|sysent
index|[]
init|=
block|{
literal|0
block|,
name|nosys
block|,
comment|/*   0 = indir */
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
name|owait
block|,
comment|/*   7 = old wait */
literal|2
block|,
name|ocreat
block|,
comment|/*   8 = old creat */
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
literal|0
block|,
name|otime
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
literal|2
block|,
name|ostat
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
name|smount
block|,
comment|/*  21 = mount */
literal|1
block|,
name|oumount
block|,
comment|/*  22 = umount */
literal|1
block|,
name|osetuid
block|,
comment|/*  23 = old setuid */
literal|0
block|,
name|getuid
block|,
comment|/*  24 = getuid */
literal|1
block|,
name|ostime
block|,
comment|/*  25 = old stime */
literal|4
block|,
name|ptrace
block|,
comment|/*  26 = ptrace */
literal|1
block|,
name|oalarm
block|,
comment|/*  27 = old alarm */
literal|2
block|,
name|ofstat
block|,
comment|/*  28 = old fstat */
literal|0
block|,
name|opause
block|,
comment|/*  29 = opause */
literal|2
block|,
name|outime
block|,
comment|/*  30 = old utime */
literal|2
block|,
name|ostty
block|,
comment|/*  31 = old stty */
literal|2
block|,
name|ogtty
block|,
comment|/*  32 = old gtty */
literal|2
block|,
name|saccess
block|,
comment|/*  33 = access */
literal|1
block|,
name|onice
block|,
comment|/*  34 = old nice */
literal|1
block|,
name|oftime
block|,
comment|/*  35 = old ftime */
literal|0
block|,
name|sync
block|,
comment|/*  36 = sync */
literal|2
block|,
name|okill
block|,
comment|/*  37 = old kill */
literal|2
block|,
name|stat
block|,
comment|/*  38 = stat */
literal|2
block|,
name|osetpgrp
block|,
comment|/*  39 = old setpgrp */
literal|2
block|,
name|lstat
block|,
comment|/*  40 = lstat */
literal|2
block|,
name|dup
block|,
comment|/*  41 = dup */
literal|0
block|,
name|pipe
block|,
comment|/*  42 = pipe */
literal|1
block|,
name|otimes
block|,
comment|/*  43 = old times */
literal|4
block|,
name|profil
block|,
comment|/*  44 = profil */
literal|0
block|,
name|nosys
block|,
comment|/*  45 = nosys */
literal|1
block|,
name|osetgid
block|,
comment|/*  46 = old setgid */
literal|0
block|,
name|getgid
block|,
comment|/*  47 = getgid */
literal|2
block|,
name|ossig
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
name|sysacct
block|,
comment|/*  51 = turn acct off/on */
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
name|fstat
block|,
comment|/*  62 = fstat */
literal|0
block|,
name|nosys
block|,
comment|/*  63 = used internally */
literal|1
block|,
name|getpagesize
block|,
comment|/*  64 = getpagesize */
literal|5
block|,
name|mremap
block|,
comment|/*  65 = mremap */
literal|0
block|,
name|vfork
block|,
comment|/*  66 = vfork */
literal|0
block|,
name|read
block|,
comment|/*  67 = old vread */
literal|0
block|,
name|write
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
literal|6
block|,
name|smmap
block|,
comment|/*  71 = mmap */
literal|1
block|,
name|ovadvise
block|,
comment|/*  72 = old vadvise */
literal|2
block|,
name|munmap
block|,
comment|/*  73 = munmap */
literal|3
block|,
name|mprotect
block|,
comment|/*  74 = mprotect */
literal|3
block|,
name|madvise
block|,
comment|/*  75 = madvise */
literal|1
block|,
name|vhangup
block|,
comment|/*  76 = vhangup */
literal|2
block|,
name|ovlimit
block|,
comment|/*  77 = old vlimit */
literal|3
block|,
name|mincore
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
name|getpgrp
block|,
comment|/*  81 = getpgrp */
literal|2
block|,
name|setpgrp
block|,
comment|/*  82 = setpgrp */
literal|3
block|,
name|setitimer
block|,
comment|/*  83 = setitimer */
literal|0
block|,
name|wait
block|,
comment|/*  84 = wait */
literal|1
block|,
name|oswapon
block|,
comment|/*  85 = old swapon */
literal|2
block|,
name|getitimer
block|,
comment|/*  86 = getitimer */
literal|2
block|,
name|gethostname
block|,
comment|/*  87 = gethostname */
literal|2
block|,
name|sethostname
block|,
comment|/*  88 = sethostname */
literal|0
block|,
name|getdtablesize
block|,
comment|/*  89 = getdtablesize */
literal|1
block|,
name|dup2
block|,
comment|/*  90 = dup2 */
literal|2
block|,
name|getdopt
block|,
comment|/*  91 = getdopt */
literal|2
block|,
name|wrap
block|,
comment|/*  92 = wrap */
literal|5
block|,
name|select
block|,
comment|/*  93 = select */
literal|2
block|,
name|setdopt
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
name|accept
block|,
comment|/*  99 = accept */
literal|2
block|,
name|getpriority
block|,
comment|/* 100 = getpriority */
literal|4
block|,
name|send
block|,
comment|/* 101 = send */
literal|4
block|,
name|recv
block|,
comment|/* 102 = recv */
literal|2
block|,
name|ssocketaddr
block|,
comment|/* 103 = socketaddr */
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
literal|2
block|,
name|ovtimes
block|,
comment|/* 107 = old vtimes */
literal|2
block|,
name|sigvec
block|,
comment|/* 108 = sigvec */
literal|1
block|,
name|sigblock
block|,
comment|/* 109 = sigblock */
literal|1
block|,
name|sigsetmask
block|,
comment|/* 110 = sigsetmask */
literal|1
block|,
name|sigpause
block|,
comment|/* 111 = sigpause */
literal|2
block|,
name|sigstack
block|,
comment|/* 112 = sigstack */
literal|3
block|,
name|recvmsg
block|,
comment|/* 113 = recvmsg */
literal|3
block|,
name|sendmsg
block|,
comment|/* 114 = sendmsg */
ifdef|#
directive|ifdef
name|TRACE
literal|2
block|,
name|vtrace
block|,
comment|/* 115 = vtrace */
else|#
directive|else
literal|0
block|,
name|nosys
block|,
comment|/* 115 = nosys */
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|vax
literal|1
block|,
name|resuba
block|,
comment|/* 119 = resuba */
else|#
directive|else
literal|0
block|,
name|nosys
block|,
comment|/* 119 = nosys */
endif|#
directive|endif
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
name|recvfrom
block|,
comment|/* 125 = recvfrom */
literal|2
block|,
name|setreuid
block|,
comment|/* 126 = setreuid */
literal|2
block|,
name|setregid
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
literal|3
block|,
name|flock
block|,
comment|/* 131 = flock */
literal|7
block|,
name|portal
block|,
comment|/* 132 = portal */
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
literal|2
block|,
name|getdprop
block|,
comment|/* 139 = getdprop */
literal|1
block|,
name|revoke
block|,
comment|/* 140 = revoke */
literal|2
block|,
name|unmount
block|,
comment|/* 141 = unmount */
literal|2
block|,
name|gethostid
block|,
comment|/* 142 = gethostid */
literal|2
block|,
name|sethostid
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
name|killpg
block|,
comment|/* 146 = killpg */
ifdef|#
directive|ifdef
name|MUSH
literal|3
block|,
name|mu_msg
block|,
comment|/* 147 = mu_msg */
else|#
directive|else
literal|0
block|,
name|nosys
block|,
comment|/* 147 = nosys */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QUOTA
literal|2
block|,
name|setquota
block|,
comment|/* 148 = quota */
literal|4
block|,
name|qquota
block|,
comment|/* 149 = qquota */
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsysent
init|=
sizeof|sizeof
argument_list|(
name|sysent
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|sysent
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

