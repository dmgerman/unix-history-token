begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Apple Computer, Inc.  * All rights reserved.  *  * @APPLE_BSD_LICENSE_HEADER_START@  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * @APPLE_BSD_LICENSE_HEADER_END@  *  * $P4: //depot/projects/trustedbsd/openbsm/bsm/audit_kevents.h#47 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSM_AUDIT_KEVENTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSM_AUDIT_KEVENTS_H_
end_define

begin_comment
comment|/*  * Values marked as AUE_NULL are not required to be audited as per CAPP.  *  * Some conflicts exist in the assignment of name to event number mappings  * between BSM implementations.  In general, we prefer the OpenSolaris  * definition as we consider Solaris BSM to be authoritative.  _DARWIN_ has  * been inserted for the Darwin variants.  If necessary, other tags will be  * added in the future.  */
end_comment

begin_define
define|#
directive|define
name|AUE_NULL
value|0
end_define

begin_define
define|#
directive|define
name|AUE_EXIT
value|1
end_define

begin_define
define|#
directive|define
name|AUE_FORK
value|2
end_define

begin_define
define|#
directive|define
name|AUE_OPEN
value|3
end_define

begin_define
define|#
directive|define
name|AUE_CREAT
value|4
end_define

begin_define
define|#
directive|define
name|AUE_LINK
value|5
end_define

begin_define
define|#
directive|define
name|AUE_UNLINK
value|6
end_define

begin_define
define|#
directive|define
name|AUE_DELETE
value|AUE_UNLINK
end_define

begin_define
define|#
directive|define
name|AUE_EXEC
value|7
end_define

begin_define
define|#
directive|define
name|AUE_CHDIR
value|8
end_define

begin_define
define|#
directive|define
name|AUE_MKNOD
value|9
end_define

begin_define
define|#
directive|define
name|AUE_CHMOD
value|10
end_define

begin_define
define|#
directive|define
name|AUE_CHOWN
value|11
end_define

begin_define
define|#
directive|define
name|AUE_UMOUNT
value|12
end_define

begin_define
define|#
directive|define
name|AUE_JUNK
value|13
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACCESS
value|14
end_define

begin_define
define|#
directive|define
name|AUE_CHECKUSERACCESS
value|AUE_ACCESS
end_define

begin_define
define|#
directive|define
name|AUE_KILL
value|15
end_define

begin_define
define|#
directive|define
name|AUE_STAT
value|16
end_define

begin_define
define|#
directive|define
name|AUE_LSTAT
value|17
end_define

begin_define
define|#
directive|define
name|AUE_ACCT
value|18
end_define

begin_define
define|#
directive|define
name|AUE_MCTL
value|19
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_REBOOT
value|20
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_SYMLINK
value|21
end_define

begin_define
define|#
directive|define
name|AUE_READLINK
value|22
end_define

begin_define
define|#
directive|define
name|AUE_EXECVE
value|23
end_define

begin_define
define|#
directive|define
name|AUE_CHROOT
value|24
end_define

begin_define
define|#
directive|define
name|AUE_VFORK
value|25
end_define

begin_define
define|#
directive|define
name|AUE_SETGROUPS
value|26
end_define

begin_define
define|#
directive|define
name|AUE_SETPGRP
value|27
end_define

begin_define
define|#
directive|define
name|AUE_SWAPON
value|28
end_define

begin_define
define|#
directive|define
name|AUE_SETHOSTNAME
value|29
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_FCNTL
value|30
end_define

begin_define
define|#
directive|define
name|AUE_SETPRIORITY
value|31
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_CONNECT
value|32
end_define

begin_define
define|#
directive|define
name|AUE_ACCEPT
value|33
end_define

begin_define
define|#
directive|define
name|AUE_BIND
value|34
end_define

begin_define
define|#
directive|define
name|AUE_SETSOCKOPT
value|35
end_define

begin_define
define|#
directive|define
name|AUE_VTRACE
value|36
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SETTIMEOFDAY
value|37
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_FCHOWN
value|38
end_define

begin_define
define|#
directive|define
name|AUE_FCHMOD
value|39
end_define

begin_define
define|#
directive|define
name|AUE_SETREUID
value|40
end_define

begin_define
define|#
directive|define
name|AUE_SETREGID
value|41
end_define

begin_define
define|#
directive|define
name|AUE_RENAME
value|42
end_define

begin_define
define|#
directive|define
name|AUE_TRUNCATE
value|43
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_FTRUNCATE
value|44
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_FLOCK
value|45
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_SHUTDOWN
value|46
end_define

begin_define
define|#
directive|define
name|AUE_MKDIR
value|47
end_define

begin_define
define|#
directive|define
name|AUE_RMDIR
value|48
end_define

begin_define
define|#
directive|define
name|AUE_UTIMES
value|49
end_define

begin_define
define|#
directive|define
name|AUE_ADJTIME
value|50
end_define

begin_define
define|#
directive|define
name|AUE_SETRLIMIT
value|51
end_define

begin_define
define|#
directive|define
name|AUE_KILLPG
value|52
end_define

begin_define
define|#
directive|define
name|AUE_NFS_SVC
value|53
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_STATFS
value|54
end_define

begin_define
define|#
directive|define
name|AUE_FSTATFS
value|55
end_define

begin_define
define|#
directive|define
name|AUE_UNMOUNT
value|56
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_ASYNC_DAEMON
value|57
end_define

begin_define
define|#
directive|define
name|AUE_NFS_GETFH
value|58
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_SETDOMAINNAME
value|59
end_define

begin_define
define|#
directive|define
name|AUE_QUOTACTL
value|60
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXPORTFS
value|61
end_define

begin_define
define|#
directive|define
name|AUE_MOUNT
value|62
end_define

begin_define
define|#
directive|define
name|AUE_SEMSYS
value|63
end_define

begin_define
define|#
directive|define
name|AUE_MSGSYS
value|64
end_define

begin_define
define|#
directive|define
name|AUE_SHMSYS
value|65
end_define

begin_define
define|#
directive|define
name|AUE_BSMSYS
value|66
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_RFSSYS
value|67
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_FCHDIR
value|68
end_define

begin_define
define|#
directive|define
name|AUE_FCHROOT
value|69
end_define

begin_define
define|#
directive|define
name|AUE_VPIXSYS
value|70
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_PATHCONF
value|71
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_R
value|72
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_RC
value|73
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_RT
value|74
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_RTC
value|75
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_W
value|76
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_WC
value|77
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_WT
value|78
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_WTC
value|79
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_RW
value|80
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_RWC
value|81
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_RWT
value|82
end_define

begin_define
define|#
directive|define
name|AUE_OPEN_RWTC
value|83
end_define

begin_define
define|#
directive|define
name|AUE_MSGCTL
value|84
end_define

begin_define
define|#
directive|define
name|AUE_MSGCTL_RMID
value|85
end_define

begin_define
define|#
directive|define
name|AUE_MSGCTL_SET
value|86
end_define

begin_define
define|#
directive|define
name|AUE_MSGCTL_STAT
value|87
end_define

begin_define
define|#
directive|define
name|AUE_MSGGET
value|88
end_define

begin_define
define|#
directive|define
name|AUE_MSGRCV
value|89
end_define

begin_define
define|#
directive|define
name|AUE_MSGSND
value|90
end_define

begin_define
define|#
directive|define
name|AUE_SHMCTL
value|91
end_define

begin_define
define|#
directive|define
name|AUE_SHMCTL_RMID
value|92
end_define

begin_define
define|#
directive|define
name|AUE_SHMCTL_SET
value|93
end_define

begin_define
define|#
directive|define
name|AUE_SHMCTL_STAT
value|94
end_define

begin_define
define|#
directive|define
name|AUE_SHMGET
value|95
end_define

begin_define
define|#
directive|define
name|AUE_SHMAT
value|96
end_define

begin_define
define|#
directive|define
name|AUE_SHMDT
value|97
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL
value|98
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_RMID
value|99
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_SET
value|100
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_STAT
value|101
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_GETNCNT
value|102
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_GETPID
value|103
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_GETVAL
value|104
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_GETALL
value|105
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_GETZCNT
value|106
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_SETVAL
value|107
end_define

begin_define
define|#
directive|define
name|AUE_SEMCTL_SETALL
value|108
end_define

begin_define
define|#
directive|define
name|AUE_SEMGET
value|109
end_define

begin_define
define|#
directive|define
name|AUE_SEMOP
value|110
end_define

begin_define
define|#
directive|define
name|AUE_CORE
value|111
end_define

begin_comment
comment|/* Solaris-specific, currently. */
end_comment

begin_define
define|#
directive|define
name|AUE_CLOSE
value|112
end_define

begin_define
define|#
directive|define
name|AUE_SYSTEMBOOT
value|113
end_define

begin_define
define|#
directive|define
name|AUE_ASYNC_DAEMON_EXIT
value|114
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_NFSSVC_EXIT
value|115
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_WRITEL
value|128
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_WRITEVL
value|129
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_GETAUID
value|130
end_define

begin_define
define|#
directive|define
name|AUE_SETAUID
value|131
end_define

begin_define
define|#
directive|define
name|AUE_GETAUDIT
value|132
end_define

begin_define
define|#
directive|define
name|AUE_SETAUDIT
value|133
end_define

begin_define
define|#
directive|define
name|AUE_GETUSERAUDIT
value|134
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SETUSERAUDIT
value|135
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_AUDITSVC
value|136
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_AUDITUSER
value|137
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_AUDITON
value|138
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_GTERMID
value|139
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_AUDITON_STERMID
value|140
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_AUDITON_GPOLICY
value|141
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_SPOLICY
value|142
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_GQCTRL
value|145
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_SQCTRL
value|146
end_define

begin_define
define|#
directive|define
name|AUE_GETKERNSTATE
value|147
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SETKERNSTATE
value|148
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_GETPORTAUDIT
value|149
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_AUDISTAT
value|150
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_ENTERPROM
value|153
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXITPROM
value|154
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_IOCTL
value|158
end_define

begin_define
define|#
directive|define
name|AUE_SOCKET
value|183
end_define

begin_define
define|#
directive|define
name|AUE_SENDTO
value|184
end_define

begin_define
define|#
directive|define
name|AUE_PIPE
value|185
end_define

begin_define
define|#
directive|define
name|AUE_SOCKETPAIR
value|186
end_define

begin_comment
comment|/* XXX: Darwin conflict. */
end_comment

begin_define
define|#
directive|define
name|AUE_SEND
value|187
end_define

begin_define
define|#
directive|define
name|AUE_SENDMSG
value|188
end_define

begin_define
define|#
directive|define
name|AUE_RECV
value|189
end_define

begin_define
define|#
directive|define
name|AUE_RECVMSG
value|190
end_define

begin_define
define|#
directive|define
name|AUE_RECVFROM
value|191
end_define

begin_define
define|#
directive|define
name|AUE_READ
value|192
end_define

begin_define
define|#
directive|define
name|AUE_LSEEK
value|194
end_define

begin_define
define|#
directive|define
name|AUE_WRITE
value|195
end_define

begin_define
define|#
directive|define
name|AUE_WRITEV
value|196
end_define

begin_define
define|#
directive|define
name|AUE_NFS
value|197
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_READV
value|198
end_define

begin_comment
comment|/* XXXRW: XXX Solaris old stat()? */
end_comment

begin_define
define|#
directive|define
name|AUE_SETUID
value|200
end_define

begin_comment
comment|/* XXXRW: Solaris old setuid? */
end_comment

begin_define
define|#
directive|define
name|AUE_STIME
value|201
end_define

begin_comment
comment|/* XXXRW: Solaris old stime? */
end_comment

begin_define
define|#
directive|define
name|AUE_UTIME
value|202
end_define

begin_comment
comment|/* XXXRW: Solaris old utime? */
end_comment

begin_define
define|#
directive|define
name|AUE_NICE
value|203
end_define

begin_comment
comment|/* XXXRW: Solaris old nice? */
end_comment

begin_comment
comment|/* XXXRW: Solaris old setpgrp? */
end_comment

begin_define
define|#
directive|define
name|AUE_SETGID
value|205
end_define

begin_comment
comment|/* XXXRW: Solaris old setgid? */
end_comment

begin_comment
comment|/* XXXRW: Solaris readl? */
end_comment

begin_comment
comment|/* XXXRW: Solaris readvl()? */
end_comment

begin_define
define|#
directive|define
name|AUE_DUP2
value|209
end_define

begin_define
define|#
directive|define
name|AUE_MMAP
value|210
end_define

begin_define
define|#
directive|define
name|AUE_AUDIT
value|211
end_define

begin_define
define|#
directive|define
name|AUE_PRIOCNTLSYS
value|212
end_define

begin_define
define|#
directive|define
name|AUE_MUNMAP
value|213
end_define

begin_define
define|#
directive|define
name|AUE_SETEGID
value|214
end_define

begin_define
define|#
directive|define
name|AUE_SETEUID
value|215
end_define

begin_define
define|#
directive|define
name|AUE_PUTMSG
value|216
end_define

begin_define
define|#
directive|define
name|AUE_GETMSG
value|217
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_PUTPMSG
value|218
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_GETPMSG
value|219
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_AUDITSYS
value|220
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_AUDITON_GETKMASK
value|221
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_SETKMASK
value|222
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_GETCWD
value|223
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_GETCAR
value|224
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_GETSTAT
value|225
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_SETSTAT
value|226
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_SETUMASK
value|227
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_SETSMASK
value|228
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_GETCOND
value|229
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_SETCOND
value|230
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_GETCLASS
value|231
end_define

begin_define
define|#
directive|define
name|AUE_AUDITON_SETCLASS
value|232
end_define

begin_define
define|#
directive|define
name|AUE_UTSSYS
value|233
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_STATVFS
value|234
end_define

begin_define
define|#
directive|define
name|AUE_XSTAT
value|235
end_define

begin_define
define|#
directive|define
name|AUE_LXSTAT
value|236
end_define

begin_define
define|#
directive|define
name|AUE_LCHOWN
value|237
end_define

begin_define
define|#
directive|define
name|AUE_MEMCNTL
value|238
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SYSINFO
value|239
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_XMKNOD
value|240
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_FORK1
value|241
end_define

begin_comment
comment|/* XXXRW: Solaris modctl()? */
end_comment

begin_define
define|#
directive|define
name|AUE_MODLOAD
value|243
end_define

begin_define
define|#
directive|define
name|AUE_MODUNLOAD
value|244
end_define

begin_define
define|#
directive|define
name|AUE_MODCONFIG
value|245
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_MODADDMAJ
value|246
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SOCKACCEPT
value|247
end_define

begin_define
define|#
directive|define
name|AUE_SOCKCONNECT
value|248
end_define

begin_define
define|#
directive|define
name|AUE_SOCKSEND
value|249
end_define

begin_define
define|#
directive|define
name|AUE_SOCKRECEIVE
value|250
end_define

begin_define
define|#
directive|define
name|AUE_ACLSET
value|251
end_define

begin_define
define|#
directive|define
name|AUE_FACLSET
value|252
end_define

begin_define
define|#
directive|define
name|AUE_DOORFS_DOOR_CALL
value|254
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DOORFS_DOOR_RETURN
value|255
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DOORFS_DOOR_CREATE
value|256
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DOORFS_DOOR_REVOKE
value|257
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DOORFS_DOOR_INFO
value|258
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DOORFS_DOOR_CRED
value|259
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DOORFS_DOOR_BIND
value|260
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DOORFS_DOOR_UNBIND
value|261
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_P_ONLINE
value|262
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_PROCESSOR_BIND
value|263
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_INST_SYNC
value|264
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SOCK_CONFIG
value|265
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SETAUDIT_ADDR
value|266
end_define

begin_define
define|#
directive|define
name|AUE_GETAUDIT_ADDR
value|267
end_define

begin_define
define|#
directive|define
name|AUE_CLOCK_SETTIME
value|287
end_define

begin_define
define|#
directive|define
name|AUE_NTP_ADJTIME
value|288
end_define

begin_comment
comment|/*  * Events added for Apple Darwin that potentially collide with future Solaris  * BSM events.  These are assigned AUE_DARWIN prefixes, and are deprecated in  * new trails.  Systems generating these events should switch to the new  * identifiers that avoid colliding with the Solaris identifier space.  */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_GETFSSTAT
value|301
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_PTRACE
value|302
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_CHFLAGS
value|303
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_FCHFLAGS
value|304
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_PROFILE
value|305
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_KTRACE
value|306
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SETLOGIN
value|307
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_REBOOT
value|308
end_define

begin_comment
comment|/* XXX: See AUE_REBOOT. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_REVOKE
value|309
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_UMASK
value|310
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_MPROTECT
value|311
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SETPRIORITY
value|312
end_define

begin_comment
comment|/* XXX: See AUE_SETPRIORITY. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_SETTIMEOFDAY
value|313
end_define

begin_comment
comment|/* XXX: See AUE_SETTIMEOFDAY. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_FLOCK
value|314
end_define

begin_comment
comment|/* XXX: See AUE_FLOCK. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_MKFIFO
value|315
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_POLL
value|316
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SOCKETPAIR
value|317
end_define

begin_comment
comment|/* XXXRW: See AUE_SOCKETPAIR. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_FUTIMES
value|318
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SETSID
value|319
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SETPRIVEXEC
value|320
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_NFSSVC
value|321
end_define

begin_comment
comment|/* XXX: See AUE_NFS_SVC. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_GETFH
value|322
end_define

begin_comment
comment|/* XXX: See AUE_NFS_GETFH. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_QUOTACTL
value|323
end_define

begin_comment
comment|/* XXX: See AUE_QUOTACTL. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_ADDPROFILE
value|324
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_KDEBUGTRACE
value|325
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_KDBUGTRACE
value|AUE_KDEBUGTRACE
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_FSTAT
value|326
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_FPATHCONF
value|327
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_GETDIRENTRIES
value|328
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_TRUNCATE
value|329
end_define

begin_comment
comment|/* XXX: See AUE_TRUNCATE. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_FTRUNCATE
value|330
end_define

begin_comment
comment|/* XXX: See AUE_FTRUNCATE. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_SYSCTL
value|331
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_MLOCK
value|332
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_MUNLOCK
value|333
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_UNDELETE
value|334
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_GETATTRLIST
value|335
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_SETATTRLIST
value|336
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_GETDIRENTRIESATTR
value|337
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_EXCHANGEDATA
value|338
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_SEARCHFS
value|339
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_MINHERIT
value|340
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SEMCONFIG
value|341
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SEMOPEN
value|342
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SEMCLOSE
value|343
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SEMUNLINK
value|344
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SHMOPEN
value|345
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SHMUNLINK
value|346
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_LOADSHFILE
value|347
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_RESETSHFILE
value|348
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_NEWSYSTEMSHREG
value|349
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_PTHREADKILL
value|350
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_PTHREADSIGMASK
value|351
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_AUDITCTL
value|352
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_RFORK
value|353
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_LCHMOD
value|354
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_SWAPOFF
value|355
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_INITPROCESS
value|356
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_MAPFD
value|357
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_TASKFORPID
value|358
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_PIDFORTASK
value|359
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_DARWIN_SYSCTL_NONADMIN
value|360
end_define

begin_define
define|#
directive|define
name|AUE_DARWIN_COPYFILE
value|361
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_comment
comment|/*  * Audit event identifiers added as part of OpenBSM, generally corresponding  * to events in FreeBSD, Darwin, and Linux that were not present in Solaris.  * These often duplicate events added to the Solaris set by Darwin, but use  * event identifiers in a higher range in order to avoid colliding with  * future Solaris additions.  */
end_comment

begin_define
define|#
directive|define
name|AUE_GETFSSTAT
value|43001
end_define

begin_define
define|#
directive|define
name|AUE_PTRACE
value|43002
end_define

begin_define
define|#
directive|define
name|AUE_CHFLAGS
value|43003
end_define

begin_define
define|#
directive|define
name|AUE_FCHFLAGS
value|43004
end_define

begin_define
define|#
directive|define
name|AUE_PROFILE
value|43005
end_define

begin_define
define|#
directive|define
name|AUE_KTRACE
value|43006
end_define

begin_define
define|#
directive|define
name|AUE_SETLOGIN
value|43007
end_define

begin_define
define|#
directive|define
name|AUE_REVOKE
value|43008
end_define

begin_define
define|#
directive|define
name|AUE_UMASK
value|43009
end_define

begin_define
define|#
directive|define
name|AUE_MPROTECT
value|43010
end_define

begin_define
define|#
directive|define
name|AUE_MKFIFO
value|43011
end_define

begin_define
define|#
directive|define
name|AUE_POLL
value|43012
end_define

begin_define
define|#
directive|define
name|AUE_FUTIMES
value|43013
end_define

begin_define
define|#
directive|define
name|AUE_SETSID
value|43014
end_define

begin_define
define|#
directive|define
name|AUE_SETPRIVEXEC
value|43015
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_ADDPROFILE
value|43016
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_KDEBUGTRACE
value|43017
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_KDBUGTRACE
value|AUE_KDEBUGTRACE
end_define

begin_define
define|#
directive|define
name|AUE_FSTAT
value|43018
end_define

begin_define
define|#
directive|define
name|AUE_FPATHCONF
value|43019
end_define

begin_define
define|#
directive|define
name|AUE_GETDIRENTRIES
value|43020
end_define

begin_define
define|#
directive|define
name|AUE_SYSCTL
value|43021
end_define

begin_define
define|#
directive|define
name|AUE_MLOCK
value|43022
end_define

begin_define
define|#
directive|define
name|AUE_MUNLOCK
value|43023
end_define

begin_define
define|#
directive|define
name|AUE_UNDELETE
value|43024
end_define

begin_define
define|#
directive|define
name|AUE_GETATTRLIST
value|43025
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SETATTRLIST
value|43026
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_GETDIRENTRIESATTR
value|43027
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXCHANGEDATA
value|43028
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SEARCHFS
value|43029
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_MINHERIT
value|43030
end_define

begin_define
define|#
directive|define
name|AUE_SEMCONFIG
value|43031
end_define

begin_define
define|#
directive|define
name|AUE_SEMOPEN
value|43032
end_define

begin_define
define|#
directive|define
name|AUE_SEMCLOSE
value|43033
end_define

begin_define
define|#
directive|define
name|AUE_SEMUNLINK
value|43034
end_define

begin_define
define|#
directive|define
name|AUE_SHMOPEN
value|43035
end_define

begin_define
define|#
directive|define
name|AUE_SHMUNLINK
value|43036
end_define

begin_define
define|#
directive|define
name|AUE_LOADSHFILE
value|43037
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_RESETSHFILE
value|43038
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_NEWSYSTEMSHREG
value|43039
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_PTHREADKILL
value|43040
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_PTHREADSIGMASK
value|43041
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_AUDITCTL
value|43042
end_define

begin_define
define|#
directive|define
name|AUE_RFORK
value|43043
end_define

begin_define
define|#
directive|define
name|AUE_LCHMOD
value|43044
end_define

begin_define
define|#
directive|define
name|AUE_SWAPOFF
value|43045
end_define

begin_define
define|#
directive|define
name|AUE_INITPROCESS
value|43046
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAPFD
value|43047
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_TASKFORPID
value|43048
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_PIDFORTASK
value|43049
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SYSCTL_NONADMIN
value|43050
end_define

begin_define
define|#
directive|define
name|AUE_COPYFILE
value|43051
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_comment
comment|/*  * Events added to OpenBSM for FreeBSD and Linux; may also be used by Darwin  * in the future.  */
end_comment

begin_define
define|#
directive|define
name|AUE_LUTIMES
value|43052
end_define

begin_define
define|#
directive|define
name|AUE_LCHFLAGS
value|43053
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SENDFILE
value|43054
end_define

begin_comment
comment|/* BSD/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_USELIB
value|43055
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_GETRESUID
value|43056
end_define

begin_define
define|#
directive|define
name|AUE_SETRESUID
value|43057
end_define

begin_define
define|#
directive|define
name|AUE_GETRESGID
value|43058
end_define

begin_define
define|#
directive|define
name|AUE_SETRESGID
value|43059
end_define

begin_define
define|#
directive|define
name|AUE_WAIT4
value|43060
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_LGETFH
value|43061
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_FHSTATFS
value|43062
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_FHOPEN
value|43063
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_FHSTAT
value|43064
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_JAIL
value|43065
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_EACCESS
value|43066
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_KQUEUE
value|43067
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_KEVENT
value|43068
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_FSYNC
value|43069
end_define

begin_define
define|#
directive|define
name|AUE_NMOUNT
value|43070
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_BDFLUSH
value|43071
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SETFSUID
value|43072
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SETFSGID
value|43073
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_PERSONALITY
value|43074
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SCHED_GETSCHEDULER
value|43075
end_define

begin_comment
comment|/* POSIX.1b. */
end_comment

begin_define
define|#
directive|define
name|AUE_SCHED_SETSCHEDULER
value|43076
end_define

begin_comment
comment|/* POSIX.1b. */
end_comment

begin_define
define|#
directive|define
name|AUE_PRCTL
value|43077
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_GETCWD
value|43078
end_define

begin_comment
comment|/* FreeBSD/Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_CAPGET
value|43079
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_CAPSET
value|43080
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_PIVOT_ROOT
value|43081
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_RTPRIO
value|43082
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|AUE_SCHED_GETPARAM
value|43083
end_define

begin_comment
comment|/* POSIX.1b. */
end_comment

begin_define
define|#
directive|define
name|AUE_SCHED_SETPARAM
value|43084
end_define

begin_comment
comment|/* POSIX.1b. */
end_comment

begin_define
define|#
directive|define
name|AUE_SCHED_GET_PRIORITY_MAX
value|43085
end_define

begin_comment
comment|/* POSIX.1b. */
end_comment

begin_define
define|#
directive|define
name|AUE_SCHED_GET_PRIORITY_MIN
value|43086
end_define

begin_comment
comment|/* POSIX.1b. */
end_comment

begin_define
define|#
directive|define
name|AUE_SCHED_RR_GET_INTERVAL
value|43087
end_define

begin_comment
comment|/* POSIX.1b. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_GET_FILE
value|43088
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_SET_FILE
value|43089
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_GET_FD
value|43090
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_SET_FD
value|43091
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_DELETE_FILE
value|43092
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_DELETE_FD
value|43093
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_CHECK_FILE
value|43094
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_CHECK_FD
value|43095
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_GET_LINK
value|43096
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_SET_LINK
value|43097
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_DELETE_LINK
value|43098
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_ACL_CHECK_LINK
value|43099
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_SYSARCH
value|43100
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTRCTL
value|43101
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_GET_FILE
value|43102
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_SET_FILE
value|43103
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_LIST_FILE
value|43104
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_DELETE_FILE
value|43105
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_GET_FD
value|43106
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_SET_FD
value|43107
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_LIST_FD
value|43108
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_DELETE_FD
value|43109
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_GET_LINK
value|43110
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_SET_LINK
value|43111
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_LIST_LINK
value|43112
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_EXTATTR_DELETE_LINK
value|43113
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_KENV
value|43114
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_JAIL_ATTACH
value|43115
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_SYSCTL_WRITE
value|43116
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_IOPERM
value|43117
end_define

begin_comment
comment|/* Linux. */
end_comment

begin_define
define|#
directive|define
name|AUE_READDIR
value|43118
end_define

begin_comment
comment|/* Linux. */
end_comment

begin_define
define|#
directive|define
name|AUE_IOPL
value|43119
end_define

begin_comment
comment|/* Linux. */
end_comment

begin_define
define|#
directive|define
name|AUE_VM86
value|43120
end_define

begin_comment
comment|/* Linux. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_GET_PROC
value|43121
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_SET_PROC
value|43122
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_GET_FD
value|43123
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_GET_FILE
value|43124
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_SET_FD
value|43125
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_SET_FILE
value|43126
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_SYSCALL
value|43127
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_GET_PID
value|43128
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_GET_LINK
value|43129
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_SET_LINK
value|43130
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MAC_EXECVE
value|43131
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_GETPATH_FROMFD
value|43132
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_GETPATH_FROMADDR
value|43133
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MQ_OPEN
value|43134
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MQ_SETATTR
value|43135
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MQ_TIMEDRECEIVE
value|43136
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MQ_TIMEDSEND
value|43137
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MQ_NOTIFY
value|43138
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MQ_UNLINK
value|43139
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_LISTEN
value|43140
end_define

begin_comment
comment|/* FreeBSD/Darwin/Linux. */
end_comment

begin_define
define|#
directive|define
name|AUE_MLOCKALL
value|43141
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_define
define|#
directive|define
name|AUE_MUNLOCKALL
value|43142
end_define

begin_comment
comment|/* FreeBSD. */
end_comment

begin_comment
comment|/*  * Darwin BSM uses a number of AUE_O_* definitions, which are aliased to the  * normal Solaris BSM identifiers.  _O_ refers to it being an old, or compat  * interface.  In most cases, Darwin has never implemented these system calls  * but picked up the fields in their system call table from their FreeBSD  * import.  Happily, these have different names than the AUE_O* definitions  * in Solaris BSM.  */
end_comment

begin_define
define|#
directive|define
name|AUE_O_CREAT
value|AUE_OPEN_RWTC
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_EXECVE
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SBREAK
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_LSEEK
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_MOUNT
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_UMOUNT
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_STAT
value|AUE_STAT
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_LSTAT
value|AUE_LSTAT
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_FSTAT
value|AUE_FSTAT
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETPAGESIZE
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_VREAD
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_VWRITE
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_MMAP
value|AUE_MMAP
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_VADVISE
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_VHANGUP
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_VLIMIT
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_WAIT
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETHOSTNAME
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SETHOSTNAME
value|AUE_SYSCTL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETDOPT
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SETDOPT
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_ACCEPT
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SEND
value|AUE_SENDMSG
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_RECV
value|AUE_RECVMSG
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_VTIMES
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SIGVEC
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SIGBLOCK
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SIGSETMASK
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SIGSTACK
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_RECVMSG
value|AUE_RECVMSG
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SENDMSG
value|AUE_SENDMSG
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_VTRACE
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_RESUBA
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_RECVFROM
value|AUE_RECVFROM
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SETREUID
value|AUE_SETREUID
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SETREGID
value|AUE_SETREGID
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETDIRENTRIES
value|AUE_GETDIRENTRIES
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_TRUNCATE
value|AUE_TRUNCATE
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_FTRUNCATE
value|AUE_FTRUNCATE
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETPEERNAME
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETHOSTID
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SETHOSTID
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETRLIMIT
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SETRLIMIT
value|AUE_SETRLIMIT
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_KILLPG
value|AUE_KILL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SETQUOTA
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_QUOTA
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETSOCKNAME
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETDIREENTRIES
value|AUE_GETDIREENTRIES
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_ASYNCDAEMON
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETDOMAINNAME
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_SETDOMAINNAME
value|AUE_SYSCTL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_PCFS_MOUNT
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_EXPORTFS
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_USTATE
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_WAIT3
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_RPAUSE
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_define
define|#
directive|define
name|AUE_O_GETDENTS
value|AUE_NULL
end_define

begin_comment
comment|/* Darwin */
end_comment

begin_comment
comment|/*  * Possible desired future values based on review of BSD/Darwin system calls.  */
end_comment

begin_define
define|#
directive|define
name|AUE_DUP
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_FSCTL
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_FSTATV
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GCCONTROL
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETDTABLESIZE
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETEGID
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETEUID
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETGID
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETGROUPS
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETITIMER
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETLOGIN
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETPEERNAME
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETPGID
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETPGRP
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETPID
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETPPID
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETPRIORITY
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETRLIMIT
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETRUSAGE
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETSID
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETSOCKNAME
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETTIMEOFDAY
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETUID
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GETSOCKOPT
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_GTSOCKOPT
value|AUE_GETSOCKOPT
end_define

begin_comment
comment|/* XXX: Typo in Darwin. */
end_comment

begin_define
define|#
directive|define
name|AUE_ISSETUGID
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_LSTATV
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_MADVISE
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_MINCORE
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_MKCOMPLEX
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_MODWATCH
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_MSGCL
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_MSYNC
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_PREAD
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_PWRITE
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_PREADV
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_PWRITEV
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SBRK
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SELECT
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SEMDESTROY
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SEMGETVALUE
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SEMINIT
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SEMPOST
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SEMTRYWAIT
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SEMWAIT
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SETITIMER
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SIGACTION
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SIGALTSTACK
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SIGPENDING
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SIGPROCMASK
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SIGRETURN
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SIGSUSPEND
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SIGWAIT
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SSTK
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_STATV
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SYNC
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_SYSCALL
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_TABLE
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_WAITEVENT
value|AUE_NULL
end_define

begin_define
define|#
directive|define
name|AUE_WATCHEVENT
value|AUE_NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BSM_AUDIT_KEVENTS_H_ */
end_comment

end_unit

