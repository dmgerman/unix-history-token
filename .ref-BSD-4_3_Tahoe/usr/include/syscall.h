begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)syscall.h	5.4 (Berkeley) 4/3/86  */
end_comment

begin_define
define|#
directive|define
name|SYS_exit
value|1
end_define

begin_define
define|#
directive|define
name|SYS_fork
value|2
end_define

begin_define
define|#
directive|define
name|SYS_read
value|3
end_define

begin_define
define|#
directive|define
name|SYS_write
value|4
end_define

begin_define
define|#
directive|define
name|SYS_open
value|5
end_define

begin_define
define|#
directive|define
name|SYS_close
value|6
end_define

begin_comment
comment|/*  7 is old: wait */
end_comment

begin_define
define|#
directive|define
name|SYS_creat
value|8
end_define

begin_define
define|#
directive|define
name|SYS_link
value|9
end_define

begin_define
define|#
directive|define
name|SYS_unlink
value|10
end_define

begin_define
define|#
directive|define
name|SYS_execv
value|11
end_define

begin_define
define|#
directive|define
name|SYS_chdir
value|12
end_define

begin_comment
comment|/* 13 is old: time */
end_comment

begin_define
define|#
directive|define
name|SYS_mknod
value|14
end_define

begin_define
define|#
directive|define
name|SYS_chmod
value|15
end_define

begin_define
define|#
directive|define
name|SYS_chown
value|16
end_define

begin_comment
comment|/* 17 is old: sbreak */
end_comment

begin_comment
comment|/* 18 is old: stat */
end_comment

begin_define
define|#
directive|define
name|SYS_lseek
value|19
end_define

begin_define
define|#
directive|define
name|SYS_getpid
value|20
end_define

begin_define
define|#
directive|define
name|SYS_mount
value|21
end_define

begin_define
define|#
directive|define
name|SYS_umount
value|22
end_define

begin_comment
comment|/* 23 is old: setuid */
end_comment

begin_define
define|#
directive|define
name|SYS_getuid
value|24
end_define

begin_comment
comment|/* 25 is old: stime */
end_comment

begin_define
define|#
directive|define
name|SYS_ptrace
value|26
end_define

begin_comment
comment|/* 27 is old: alarm */
end_comment

begin_comment
comment|/* 28 is old: fstat */
end_comment

begin_comment
comment|/* 29 is old: pause */
end_comment

begin_comment
comment|/* 30 is old: utime */
end_comment

begin_comment
comment|/* 31 is old: stty */
end_comment

begin_comment
comment|/* 32 is old: gtty */
end_comment

begin_define
define|#
directive|define
name|SYS_access
value|33
end_define

begin_comment
comment|/* 34 is old: nice */
end_comment

begin_comment
comment|/* 35 is old: ftime */
end_comment

begin_define
define|#
directive|define
name|SYS_sync
value|36
end_define

begin_define
define|#
directive|define
name|SYS_kill
value|37
end_define

begin_define
define|#
directive|define
name|SYS_stat
value|38
end_define

begin_comment
comment|/* 39 is old: setpgrp */
end_comment

begin_define
define|#
directive|define
name|SYS_lstat
value|40
end_define

begin_define
define|#
directive|define
name|SYS_dup
value|41
end_define

begin_define
define|#
directive|define
name|SYS_pipe
value|42
end_define

begin_comment
comment|/* 43 is old: times */
end_comment

begin_define
define|#
directive|define
name|SYS_profil
value|44
end_define

begin_comment
comment|/* 45 is unused */
end_comment

begin_comment
comment|/* 46 is old: setgid */
end_comment

begin_define
define|#
directive|define
name|SYS_getgid
value|47
end_define

begin_comment
comment|/* 48 is old: sigsys */
end_comment

begin_comment
comment|/* 49 is unused */
end_comment

begin_comment
comment|/* 50 is unused */
end_comment

begin_define
define|#
directive|define
name|SYS_acct
value|51
end_define

begin_comment
comment|/* 52 is old: phys */
end_comment

begin_comment
comment|/* 53 is old: syslock */
end_comment

begin_define
define|#
directive|define
name|SYS_ioctl
value|54
end_define

begin_define
define|#
directive|define
name|SYS_reboot
value|55
end_define

begin_comment
comment|/* 56 is old: mpxchan */
end_comment

begin_define
define|#
directive|define
name|SYS_symlink
value|57
end_define

begin_define
define|#
directive|define
name|SYS_readlink
value|58
end_define

begin_define
define|#
directive|define
name|SYS_execve
value|59
end_define

begin_define
define|#
directive|define
name|SYS_umask
value|60
end_define

begin_define
define|#
directive|define
name|SYS_chroot
value|61
end_define

begin_define
define|#
directive|define
name|SYS_fstat
value|62
end_define

begin_comment
comment|/* 63 is unused */
end_comment

begin_define
define|#
directive|define
name|SYS_getpagesize
value|64
end_define

begin_define
define|#
directive|define
name|SYS_mremap
value|65
end_define

begin_comment
comment|/* 66 is old: vfork */
end_comment

begin_comment
comment|/* 67 is old: vread */
end_comment

begin_comment
comment|/* 68 is old: vwrite */
end_comment

begin_define
define|#
directive|define
name|SYS_sbrk
value|69
end_define

begin_define
define|#
directive|define
name|SYS_sstk
value|70
end_define

begin_define
define|#
directive|define
name|SYS_mmap
value|71
end_define

begin_comment
comment|/* 72 is old: vadvise */
end_comment

begin_define
define|#
directive|define
name|SYS_munmap
value|73
end_define

begin_define
define|#
directive|define
name|SYS_mprotect
value|74
end_define

begin_define
define|#
directive|define
name|SYS_madvise
value|75
end_define

begin_define
define|#
directive|define
name|SYS_vhangup
value|76
end_define

begin_comment
comment|/* 77 is old: vlimit */
end_comment

begin_define
define|#
directive|define
name|SYS_mincore
value|78
end_define

begin_define
define|#
directive|define
name|SYS_getgroups
value|79
end_define

begin_define
define|#
directive|define
name|SYS_setgroups
value|80
end_define

begin_define
define|#
directive|define
name|SYS_getpgrp
value|81
end_define

begin_define
define|#
directive|define
name|SYS_setpgrp
value|82
end_define

begin_define
define|#
directive|define
name|SYS_setitimer
value|83
end_define

begin_define
define|#
directive|define
name|SYS_wait
value|84
end_define

begin_define
define|#
directive|define
name|SYS_swapon
value|85
end_define

begin_define
define|#
directive|define
name|SYS_getitimer
value|86
end_define

begin_define
define|#
directive|define
name|SYS_gethostname
value|87
end_define

begin_define
define|#
directive|define
name|SYS_sethostname
value|88
end_define

begin_define
define|#
directive|define
name|SYS_getdtablesize
value|89
end_define

begin_define
define|#
directive|define
name|SYS_dup2
value|90
end_define

begin_define
define|#
directive|define
name|SYS_getdopt
value|91
end_define

begin_define
define|#
directive|define
name|SYS_fcntl
value|92
end_define

begin_define
define|#
directive|define
name|SYS_select
value|93
end_define

begin_define
define|#
directive|define
name|SYS_setdopt
value|94
end_define

begin_define
define|#
directive|define
name|SYS_fsync
value|95
end_define

begin_define
define|#
directive|define
name|SYS_setpriority
value|96
end_define

begin_define
define|#
directive|define
name|SYS_socket
value|97
end_define

begin_define
define|#
directive|define
name|SYS_connect
value|98
end_define

begin_define
define|#
directive|define
name|SYS_accept
value|99
end_define

begin_define
define|#
directive|define
name|SYS_getpriority
value|100
end_define

begin_define
define|#
directive|define
name|SYS_send
value|101
end_define

begin_define
define|#
directive|define
name|SYS_recv
value|102
end_define

begin_define
define|#
directive|define
name|SYS_sigreturn
value|103
end_define

begin_define
define|#
directive|define
name|SYS_bind
value|104
end_define

begin_define
define|#
directive|define
name|SYS_setsockopt
value|105
end_define

begin_define
define|#
directive|define
name|SYS_listen
value|106
end_define

begin_comment
comment|/* 107 was vtimes */
end_comment

begin_define
define|#
directive|define
name|SYS_sigvec
value|108
end_define

begin_define
define|#
directive|define
name|SYS_sigblock
value|109
end_define

begin_define
define|#
directive|define
name|SYS_sigsetmask
value|110
end_define

begin_define
define|#
directive|define
name|SYS_sigpause
value|111
end_define

begin_define
define|#
directive|define
name|SYS_sigstack
value|112
end_define

begin_define
define|#
directive|define
name|SYS_recvmsg
value|113
end_define

begin_define
define|#
directive|define
name|SYS_sendmsg
value|114
end_define

begin_comment
comment|/* 115 is old vtrace */
end_comment

begin_define
define|#
directive|define
name|SYS_gettimeofday
value|116
end_define

begin_define
define|#
directive|define
name|SYS_getrusage
value|117
end_define

begin_define
define|#
directive|define
name|SYS_getsockopt
value|118
end_define

begin_comment
comment|/* 119 is old resuba */
end_comment

begin_define
define|#
directive|define
name|SYS_readv
value|120
end_define

begin_define
define|#
directive|define
name|SYS_writev
value|121
end_define

begin_define
define|#
directive|define
name|SYS_settimeofday
value|122
end_define

begin_define
define|#
directive|define
name|SYS_fchown
value|123
end_define

begin_define
define|#
directive|define
name|SYS_fchmod
value|124
end_define

begin_define
define|#
directive|define
name|SYS_recvfrom
value|125
end_define

begin_define
define|#
directive|define
name|SYS_setreuid
value|126
end_define

begin_define
define|#
directive|define
name|SYS_setregid
value|127
end_define

begin_define
define|#
directive|define
name|SYS_rename
value|128
end_define

begin_define
define|#
directive|define
name|SYS_truncate
value|129
end_define

begin_define
define|#
directive|define
name|SYS_ftruncate
value|130
end_define

begin_define
define|#
directive|define
name|SYS_flock
value|131
end_define

begin_comment
comment|/* 132 is unused */
end_comment

begin_define
define|#
directive|define
name|SYS_sendto
value|133
end_define

begin_define
define|#
directive|define
name|SYS_shutdown
value|134
end_define

begin_define
define|#
directive|define
name|SYS_socketpair
value|135
end_define

begin_define
define|#
directive|define
name|SYS_mkdir
value|136
end_define

begin_define
define|#
directive|define
name|SYS_rmdir
value|137
end_define

begin_define
define|#
directive|define
name|SYS_utimes
value|138
end_define

begin_comment
comment|/* 139 is unused */
end_comment

begin_define
define|#
directive|define
name|SYS_adjtime
value|140
end_define

begin_define
define|#
directive|define
name|SYS_getpeername
value|141
end_define

begin_define
define|#
directive|define
name|SYS_gethostid
value|142
end_define

begin_define
define|#
directive|define
name|SYS_sethostid
value|143
end_define

begin_define
define|#
directive|define
name|SYS_getrlimit
value|144
end_define

begin_define
define|#
directive|define
name|SYS_setrlimit
value|145
end_define

begin_define
define|#
directive|define
name|SYS_killpg
value|146
end_define

begin_comment
comment|/* 147 is unused */
end_comment

begin_define
define|#
directive|define
name|SYS_setquota
value|148
end_define

begin_define
define|#
directive|define
name|SYS_quota
value|149
end_define

begin_define
define|#
directive|define
name|SYS_getsockname
value|150
end_define

end_unit

