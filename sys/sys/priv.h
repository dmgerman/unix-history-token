begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 nCircle Network Security, Inc.  * All rights reserved.  *  * This software was developed by Robert N. M. Watson for the TrustedBSD  * Project under contract to nCircle Network Security, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR, NCIRCLE NETWORK SECURITY,  * INC., OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Privilege checking interface for BSD kernel.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PRIV_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PRIV_H_
end_define

begin_comment
comment|/*  * Privilege list.  In no particular order.  *  * Think carefully before adding or reusing one of these privileges -- are  * there existing instances referring to the same privilege?  Third party  * vendors may request the assignment of privileges to be used in loadable  * modules.  Particular numeric privilege assignments are part of the  * loadable kernel module ABI, and should not be changed across minor  * releases.  *  * When adding a new privilege, remember to determine if it's appropriate for  * use in jail, and update the privilege switch in kern_jail.c as necessary.  */
end_comment

begin_comment
comment|/*  * Track beginning of privilege list.  */
end_comment

begin_define
define|#
directive|define
name|_PRIV_LOWEST
value|0
end_define

begin_comment
comment|/*  * PRIV_ROOT is a catch-all for as yet unnamed privileges.  No new  * references to this privilege should be added.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_ROOT
value|1
end_define

begin_comment
comment|/* Catch-all during development. */
end_comment

begin_comment
comment|/*  * The remaining privileges typically correspond to one or a small  * number of specific privilege checks, and have (relatively) precise  * meanings.  They are loosely sorted into a set of base system  * privileges, such as the ability to reboot, and then loosely by  * subsystem, indicated by a subsystem name.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_ACCT
value|2
end_define

begin_comment
comment|/* Manage process accounting. */
end_comment

begin_define
define|#
directive|define
name|PRIV_MAXFILES
value|3
end_define

begin_comment
comment|/* Exceed system open files limit. */
end_comment

begin_define
define|#
directive|define
name|PRIV_MAXPROC
value|4
end_define

begin_comment
comment|/* Exceed system processes limit. */
end_comment

begin_define
define|#
directive|define
name|PRIV_KTRACE
value|5
end_define

begin_comment
comment|/* Set/clear KTRFAC_ROOT on ktrace. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SETDUMPER
value|6
end_define

begin_comment
comment|/* Configure dump device. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NFSD
value|7
end_define

begin_comment
comment|/* Can become NFS daemon. */
end_comment

begin_define
define|#
directive|define
name|PRIV_REBOOT
value|8
end_define

begin_comment
comment|/* Can reboot system. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SWAPON
value|9
end_define

begin_comment
comment|/* Can swapon(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_SWAPOFF
value|10
end_define

begin_comment
comment|/* Can swapoff(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_MSGBUF
value|11
end_define

begin_comment
comment|/* Can read kernel message buffer. */
end_comment

begin_define
define|#
directive|define
name|PRIV_WITNESS
value|12
end_define

begin_comment
comment|/* Can configure WITNESS. */
end_comment

begin_define
define|#
directive|define
name|PRIV_IO
value|13
end_define

begin_comment
comment|/* Can perform low-level I/O. */
end_comment

begin_define
define|#
directive|define
name|PRIV_KEYBOARD
value|14
end_define

begin_comment
comment|/* Reprogram keyboard. */
end_comment

begin_define
define|#
directive|define
name|PRIV_DRIVER
value|15
end_define

begin_comment
comment|/* Low-level driver privilege. */
end_comment

begin_define
define|#
directive|define
name|PRIV_ADJTIME
value|16
end_define

begin_comment
comment|/* Set time adjustment. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NTP_ADJTIME
value|17
end_define

begin_comment
comment|/* Set NTP time adjustment. */
end_comment

begin_define
define|#
directive|define
name|PRIV_CLOCK_SETTIME
value|18
end_define

begin_comment
comment|/* Can call clock_settime. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SETTIMEOFDAY
value|19
end_define

begin_comment
comment|/* Can call settimeofday. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SETHOSTID
value|20
end_define

begin_comment
comment|/* Can call sethostid. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SETDOMAINNAME
value|21
end_define

begin_comment
comment|/* Can call setdomainname. */
end_comment

begin_comment
comment|/*  * Audit subsystem privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_AUDIT_CONTROL
value|40
end_define

begin_comment
comment|/* Can configure audit. */
end_comment

begin_define
define|#
directive|define
name|PRIV_AUDIT_FAILSTOP
value|41
end_define

begin_comment
comment|/* Can run during audit fail stop. */
end_comment

begin_define
define|#
directive|define
name|PRIV_AUDIT_GETAUDIT
value|42
end_define

begin_comment
comment|/* Can get proc audit properties. */
end_comment

begin_define
define|#
directive|define
name|PRIV_AUDIT_SETAUDIT
value|43
end_define

begin_comment
comment|/* Can set proc audit properties. */
end_comment

begin_define
define|#
directive|define
name|PRIV_AUDIT_SUBMIT
value|44
end_define

begin_comment
comment|/* Can submit an audit record. */
end_comment

begin_comment
comment|/*  * Credential management privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_CRED_SETUID
value|50
end_define

begin_comment
comment|/* setuid. */
end_comment

begin_define
define|#
directive|define
name|PRIV_CRED_SETEUID
value|51
end_define

begin_comment
comment|/* seteuid to !ruid and !svuid. */
end_comment

begin_define
define|#
directive|define
name|PRIV_CRED_SETGID
value|52
end_define

begin_comment
comment|/* setgid. */
end_comment

begin_define
define|#
directive|define
name|PRIV_CRED_SETEGID
value|53
end_define

begin_comment
comment|/* setgid to !rgid and !svgid. */
end_comment

begin_define
define|#
directive|define
name|PRIV_CRED_SETGROUPS
value|54
end_define

begin_comment
comment|/* Set process additional groups. */
end_comment

begin_define
define|#
directive|define
name|PRIV_CRED_SETREUID
value|55
end_define

begin_comment
comment|/* setreuid. */
end_comment

begin_define
define|#
directive|define
name|PRIV_CRED_SETREGID
value|56
end_define

begin_comment
comment|/* setregid. */
end_comment

begin_define
define|#
directive|define
name|PRIV_CRED_SETRESUID
value|57
end_define

begin_comment
comment|/* setresuid. */
end_comment

begin_define
define|#
directive|define
name|PRIV_CRED_SETRESGID
value|58
end_define

begin_comment
comment|/* setresgid. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SEEOTHERGIDS
value|59
end_define

begin_comment
comment|/* Exempt bsd.seeothergids. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SEEOTHERUIDS
value|60
end_define

begin_comment
comment|/* Exempt bsd.seeotheruids. */
end_comment

begin_comment
comment|/*  * Debugging privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_DEBUG_DIFFCRED
value|80
end_define

begin_comment
comment|/* Exempt debugging other users. */
end_comment

begin_define
define|#
directive|define
name|PRIV_DEBUG_SUGID
value|81
end_define

begin_comment
comment|/* Exempt debugging setuid proc. */
end_comment

begin_define
define|#
directive|define
name|PRIV_DEBUG_UNPRIV
value|82
end_define

begin_comment
comment|/* Exempt unprivileged debug limit. */
end_comment

begin_comment
comment|/*  * Dtrace privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_DTRACE_KERNEL
value|90
end_define

begin_comment
comment|/* Allow use of DTrace on the kernel. */
end_comment

begin_define
define|#
directive|define
name|PRIV_DTRACE_PROC
value|91
end_define

begin_comment
comment|/* Allow attaching DTrace to process. */
end_comment

begin_define
define|#
directive|define
name|PRIV_DTRACE_USER
value|92
end_define

begin_comment
comment|/* Process may submit DTrace events. */
end_comment

begin_comment
comment|/*  * Firmware privilegs.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_FIRMWARE_LOAD
value|100
end_define

begin_comment
comment|/* Can load firmware. */
end_comment

begin_comment
comment|/*  * Jail privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_JAIL_ATTACH
value|110
end_define

begin_comment
comment|/* Attach to a jail. */
end_comment

begin_comment
comment|/*  * Kernel environment priveleges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_KENV_SET
value|120
end_define

begin_comment
comment|/* Set kernel env. variables. */
end_comment

begin_define
define|#
directive|define
name|PRIV_KENV_UNSET
value|121
end_define

begin_comment
comment|/* Unset kernel env. variables. */
end_comment

begin_comment
comment|/*  * Loadable kernel module privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_KLD_LOAD
value|130
end_define

begin_comment
comment|/* Load a kernel module. */
end_comment

begin_define
define|#
directive|define
name|PRIV_KLD_UNLOAD
value|131
end_define

begin_comment
comment|/* Unload a kernel module. */
end_comment

begin_comment
comment|/*  * Privileges associated with the MAC Framework and specific MAC policy  * modules.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_MAC_PARTITION
value|140
end_define

begin_comment
comment|/* Privilege in mac_partition policy. */
end_comment

begin_define
define|#
directive|define
name|PRIV_MAC_PRIVS
value|141
end_define

begin_comment
comment|/* Privilege in the mac_privs policy. */
end_comment

begin_comment
comment|/*  * Process-related privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_PROC_LIMIT
value|160
end_define

begin_comment
comment|/* Exceed user process limit. */
end_comment

begin_define
define|#
directive|define
name|PRIV_PROC_SETLOGIN
value|161
end_define

begin_comment
comment|/* Can call setlogin. */
end_comment

begin_define
define|#
directive|define
name|PRIV_PROC_SETRLIMIT
value|162
end_define

begin_comment
comment|/* Can raise resources limits. */
end_comment

begin_comment
comment|/* System V IPC privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_IPC_READ
value|170
end_define

begin_comment
comment|/* Can override IPC read perm. */
end_comment

begin_define
define|#
directive|define
name|PRIV_IPC_WRITE
value|171
end_define

begin_comment
comment|/* Can override IPC write perm. */
end_comment

begin_define
define|#
directive|define
name|PRIV_IPC_ADMIN
value|172
end_define

begin_comment
comment|/* Can override IPC owner-only perm. */
end_comment

begin_define
define|#
directive|define
name|PRIV_IPC_MSGSIZE
value|173
end_define

begin_comment
comment|/* Exempt IPC message queue limit. */
end_comment

begin_comment
comment|/*  * POSIX message queue privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_MQ_ADMIN
value|180
end_define

begin_comment
comment|/* Can override msgq owner-only perm. */
end_comment

begin_comment
comment|/*  * Performance monitoring counter privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_PMC_MANAGE
value|190
end_define

begin_comment
comment|/* Can administer PMC. */
end_comment

begin_define
define|#
directive|define
name|PRIV_PMC_SYSTEM
value|191
end_define

begin_comment
comment|/* Can allocate a system-wide PMC. */
end_comment

begin_comment
comment|/*  * Scheduling privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_SCHED_DIFFCRED
value|200
end_define

begin_comment
comment|/* Exempt scheduling other users. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SCHED_SETPRIORITY
value|201
end_define

begin_comment
comment|/* Can set lower nice value for proc. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SCHED_RTPRIO
value|202
end_define

begin_comment
comment|/* Can set real time scheduling. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SCHED_SETPOLICY
value|203
end_define

begin_comment
comment|/* Can set scheduler policy. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SCHED_SET
value|204
end_define

begin_comment
comment|/* Can set thread scheduler. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SCHED_SETPARAM
value|205
end_define

begin_comment
comment|/* Can set thread scheduler params. */
end_comment

begin_comment
comment|/*  * POSIX semaphore privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_SEM_WRITE
value|220
end_define

begin_comment
comment|/* Can override sem write perm. */
end_comment

begin_comment
comment|/*  * Signal privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_SIGNAL_DIFFCRED
value|230
end_define

begin_comment
comment|/* Exempt signalling other users. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SIGNAL_SUGID
value|231
end_define

begin_comment
comment|/* Non-conserv signal setuid proc. */
end_comment

begin_comment
comment|/*  * Sysctl privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_SYSCTL_DEBUG
value|240
end_define

begin_comment
comment|/* Can invoke sysctl.debug. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SYSCTL_WRITE
value|241
end_define

begin_comment
comment|/* Can write sysctls. */
end_comment

begin_define
define|#
directive|define
name|PRIV_SYSCTL_WRITEJAIL
value|242
end_define

begin_comment
comment|/* Can write sysctls, jail permitted. */
end_comment

begin_comment
comment|/*  * TTY privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_TTY_CONSOLE
value|250
end_define

begin_comment
comment|/* Set console to tty. */
end_comment

begin_define
define|#
directive|define
name|PRIV_TTY_DRAINWAIT
value|251
end_define

begin_comment
comment|/* Set tty drain wait time. */
end_comment

begin_define
define|#
directive|define
name|PRIV_TTY_DTRWAIT
value|252
end_define

begin_comment
comment|/* Set DTR wait on tty. */
end_comment

begin_define
define|#
directive|define
name|PRIV_TTY_EXCLUSIVE
value|253
end_define

begin_comment
comment|/* Override tty exclusive flag. */
end_comment

begin_define
define|#
directive|define
name|PRIV_TTY_PRISON
value|254
end_define

begin_comment
comment|/* Can open pts across jails. */
end_comment

begin_define
define|#
directive|define
name|PRIV_TTY_STI
value|255
end_define

begin_comment
comment|/* Simulate input on another tty. */
end_comment

begin_define
define|#
directive|define
name|PRIV_TTY_SETA
value|256
end_define

begin_comment
comment|/* Set tty termios structure. */
end_comment

begin_comment
comment|/*  * UFS-specific privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_UFS_EXTATTRCTL
value|270
end_define

begin_comment
comment|/* Can configure EAs on UFS1. */
end_comment

begin_define
define|#
directive|define
name|PRIV_UFS_QUOTAOFF
value|271
end_define

begin_comment
comment|/* quotaoff(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_UFS_QUOTAON
value|272
end_define

begin_comment
comment|/* quotaon(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_UFS_SETUSE
value|273
end_define

begin_comment
comment|/* setuse(). */
end_comment

begin_comment
comment|/*  * VFS privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_READ
value|310
end_define

begin_comment
comment|/* Override vnode DAC read perm. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_WRITE
value|311
end_define

begin_comment
comment|/* Override vnode DAC write perm. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_ADMIN
value|312
end_define

begin_comment
comment|/* Override vnode DAC admin perm. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_EXEC
value|313
end_define

begin_comment
comment|/* Override vnode DAC exec perm. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_LOOKUP
value|314
end_define

begin_comment
comment|/* Override vnode DAC lookup perm. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_BLOCKRESERVE
value|315
end_define

begin_comment
comment|/* Can use free block reserve. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_CHFLAGS_DEV
value|316
end_define

begin_comment
comment|/* Can chflags() a device node. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_CHOWN
value|317
end_define

begin_comment
comment|/* Can set user; group to non-member. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_CHROOT
value|318
end_define

begin_comment
comment|/* chroot(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_CLEARSUGID
value|319
end_define

begin_comment
comment|/* Don't clear sugid on change. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_EXCEEDQUOTA
value|320
end_define

begin_comment
comment|/* Exempt from quota restrictions. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_EXTATTR_SYSTEM
value|321
end_define

begin_comment
comment|/* Operate on system EA namespace. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_FCHROOT
value|322
end_define

begin_comment
comment|/* fchroot(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_FHOPEN
value|323
end_define

begin_comment
comment|/* Can fhopen(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_FHSTAT
value|324
end_define

begin_comment
comment|/* Can fhstat(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_FHSTATFS
value|325
end_define

begin_comment
comment|/* Can fhstatfs(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_GENERATION
value|326
end_define

begin_comment
comment|/* stat() returns generation number. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_GETFH
value|327
end_define

begin_comment
comment|/* Can retrieve file handles. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_GETQUOTA
value|328
end_define

begin_comment
comment|/* getquota(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_LINK
value|329
end_define

begin_comment
comment|/* bsd.hardlink_check_uid */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_MKNOD_BAD
value|330
end_define

begin_comment
comment|/* Can mknod() to mark bad inodes. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_MKNOD_DEV
value|331
end_define

begin_comment
comment|/* Can mknod() to create dev nodes. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_MKNOD_WHT
value|332
end_define

begin_comment
comment|/* Can mknod() to create whiteout. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_MOUNT
value|333
end_define

begin_comment
comment|/* Can mount(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_MOUNT_OWNER
value|334
end_define

begin_comment
comment|/* Override owner on user mounts. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_MOUNT_EXPORTED
value|335
end_define

begin_comment
comment|/* Can set MNT_EXPORTED on mount. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_MOUNT_PERM
value|336
end_define

begin_comment
comment|/* Override dev node perms at mount. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_MOUNT_SUIDDIR
value|337
end_define

begin_comment
comment|/* Can set MNT_SUIDDIR on mount. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_MOUNT_NONUSER
value|338
end_define

begin_comment
comment|/* Can perform a non-user mount. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_SETGID
value|339
end_define

begin_comment
comment|/* Can setgid if not in group. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_SETQUOTA
value|340
end_define

begin_comment
comment|/* setquota(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_STICKYFILE
value|341
end_define

begin_comment
comment|/* Can set sticky bit on file. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_SYSFLAGS
value|342
end_define

begin_comment
comment|/* Can modify system flags. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VFS_UNMOUNT
value|343
end_define

begin_comment
comment|/* Can unmount(). */
end_comment

begin_comment
comment|/*  * Virtual memory privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_VM_MADV_PROTECT
value|360
end_define

begin_comment
comment|/* Can set MADV_PROTECT. */
end_comment

begin_define
define|#
directive|define
name|PRIV_VM_MLOCK
value|361
end_define

begin_comment
comment|/* Can mlock(), mlockall(). */
end_comment

begin_define
define|#
directive|define
name|PRIV_VM_MUNLOCK
value|362
end_define

begin_comment
comment|/* Can munlock(), munlockall(). */
end_comment

begin_comment
comment|/*  * Device file system privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_DEVFS_RULE
value|370
end_define

begin_comment
comment|/* Can manage devfs rules. */
end_comment

begin_define
define|#
directive|define
name|PRIV_DEVFS_SYMLINK
value|371
end_define

begin_comment
comment|/* Can create symlinks in devfs. */
end_comment

begin_comment
comment|/*  * Random number generator privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_RANDOM_RESEED
value|380
end_define

begin_comment
comment|/* Closing /dev/random reseeds. */
end_comment

begin_comment
comment|/*  * Network stack privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_BRIDGE
value|390
end_define

begin_comment
comment|/* Administer bridge. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_GRE
value|391
end_define

begin_comment
comment|/* Administer GRE. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_PPP
value|392
end_define

begin_comment
comment|/* Administer PPP. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_SLIP
value|393
end_define

begin_comment
comment|/* Administer SLIP. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_BPF
value|394
end_define

begin_comment
comment|/* Monitor BPF. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_RAW
value|395
end_define

begin_comment
comment|/* Open raw socket. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_ROUTE
value|396
end_define

begin_comment
comment|/* Administer routing. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_TAP
value|397
end_define

begin_comment
comment|/* Can open tap device. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_SETIFMTU
value|398
end_define

begin_comment
comment|/* Set interface MTU. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_SETIFFLAGS
value|399
end_define

begin_comment
comment|/* Set interface flags. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_SETIFCAP
value|400
end_define

begin_comment
comment|/* Set interface capabilities. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_SETIFNAME
value|401
end_define

begin_comment
comment|/* Set interface name. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_SETIFMETRIC
value|402
end_define

begin_comment
comment|/* Set interface metrics. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_SETIFPHYS
value|403
end_define

begin_comment
comment|/* Set interface physical layer prop. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_SETIFMAC
value|404
end_define

begin_comment
comment|/* Set interface MAC label. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_ADDMULTI
value|405
end_define

begin_comment
comment|/* Add multicast addr. to ifnet. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_DELMULTI
value|406
end_define

begin_comment
comment|/* Delete multicast addr. from ifnet. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_HWIOCTL
value|507
end_define

begin_comment
comment|/* Issue hardware ioctl on ifnet. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_SETLLADDR
value|508
end_define

begin_define
define|#
directive|define
name|PRIV_NET_ADDIFGROUP
value|509
end_define

begin_comment
comment|/* Add new interface group. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_DELIFGROUP
value|510
end_define

begin_comment
comment|/* Delete interface group. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_IFCREATE
value|511
end_define

begin_comment
comment|/* Create cloned interface. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_IFDESTROY
value|512
end_define

begin_comment
comment|/* Destroy cloned interface. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_ADDIFADDR
value|513
end_define

begin_comment
comment|/* Add protocol addr to interface. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET_DELIFADDR
value|514
end_define

begin_comment
comment|/* Delete protocol addr on interface. */
end_comment

begin_comment
comment|/*  * 802.11-related privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET80211_GETKEY
value|540
end_define

begin_comment
comment|/* Query 802.11 keys. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NET80211_MANAGE
value|541
end_define

begin_comment
comment|/* Administer 802.11. */
end_comment

begin_comment
comment|/*  * AppleTalk privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETATALK_RESERVEDPORT
value|550
end_define

begin_comment
comment|/* Bind low port number. */
end_comment

begin_comment
comment|/*  * ATM privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETATM_CFG
value|560
end_define

begin_define
define|#
directive|define
name|PRIV_NETATM_ADD
value|561
end_define

begin_define
define|#
directive|define
name|PRIV_NETATM_DEL
value|562
end_define

begin_define
define|#
directive|define
name|PRIV_NETATM_SET
value|563
end_define

begin_comment
comment|/*  * Bluetooth privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETBLUETOOTH_RAW
value|570
end_define

begin_comment
comment|/* Open raw bluetooth socket. */
end_comment

begin_comment
comment|/*  * Netgraph and netgraph module privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETGRAPH_CONTROL
value|580
end_define

begin_comment
comment|/* Open netgraph control socket. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETGRAPH_TTY
value|581
end_define

begin_comment
comment|/* Configure tty for netgraph. */
end_comment

begin_comment
comment|/*  * IPv4 and IPv6 privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_RESERVEDPORT
value|590
end_define

begin_comment
comment|/* Bind low port number. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_IPFW
value|591
end_define

begin_comment
comment|/* Administer IPFW firewall. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_DIVERT
value|592
end_define

begin_comment
comment|/* Open IP divert socket. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_PF
value|593
end_define

begin_comment
comment|/* Administer pf firewall. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_DUMMYNET
value|594
end_define

begin_comment
comment|/* Administer DUMMYNET. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_CARP
value|595
end_define

begin_comment
comment|/* Administer CARP. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_MROUTE
value|596
end_define

begin_comment
comment|/* Administer multicast routing. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_RAW
value|597
end_define

begin_comment
comment|/* Open netinet raw socket. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_GETCRED
value|598
end_define

begin_comment
comment|/* Query netinet pcb credentials. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_ADDRCTRL6
value|599
end_define

begin_comment
comment|/* Administer IPv6 address scopes. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_ND6
value|600
end_define

begin_comment
comment|/* Administer IPv6 neighbor disc. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_SCOPE6
value|601
end_define

begin_comment
comment|/* Administer IPv6 address scopes. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_ALIFETIME6
value|602
end_define

begin_comment
comment|/* Administer IPv6 address lifetimes. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETINET_IPSEC
value|603
end_define

begin_comment
comment|/* Administer IPSEC. */
end_comment

begin_comment
comment|/*  * IPX/SPX privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETIPX_RESERVEDPORT
value|620
end_define

begin_comment
comment|/* Bind low port number. */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETIPX_RAW
value|621
end_define

begin_comment
comment|/* Open netipx raw socket. */
end_comment

begin_comment
comment|/*  * NCP privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETNCP
value|630
end_define

begin_comment
comment|/* Use another user's connection. */
end_comment

begin_comment
comment|/*  * SMB privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_NETSMB
value|640
end_define

begin_comment
comment|/* Use another user's connection. */
end_comment

begin_comment
comment|/*  * VM86 privileges.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_VM86_INTCALL
value|650
end_define

begin_comment
comment|/* Allow invoking vm86 int handlers. */
end_comment

begin_comment
comment|/*  * Set of reserved privilege values, which will be allocated to code as  * needed, in order to avoid renumbering later privileges due to insertion.  */
end_comment

begin_define
define|#
directive|define
name|_PRIV_RESERVED0
value|660
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED1
value|661
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED2
value|662
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED3
value|663
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED4
value|664
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED5
value|665
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED6
value|666
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED7
value|667
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED8
value|668
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED9
value|669
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED10
value|670
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED11
value|671
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED12
value|672
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED13
value|673
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED14
value|674
end_define

begin_define
define|#
directive|define
name|_PRIV_RESERVED15
value|675
end_define

begin_comment
comment|/*  * Define a set of valid privilege numbers that can be used by loadable  * modules that don't yet have privilege reservations.  Ideally, these should  * not be used, since their meaning is opaque to any policies that are aware  * of specific privileges, such as jail, and as such may be arbitrarily  * denied.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_MODULE0
value|700
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE1
value|701
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE2
value|702
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE3
value|703
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE4
value|704
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE5
value|705
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE6
value|706
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE7
value|707
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE8
value|708
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE9
value|709
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE10
value|710
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE11
value|711
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE12
value|712
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE13
value|713
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE14
value|714
end_define

begin_define
define|#
directive|define
name|PRIV_MODULE15
value|715
end_define

begin_comment
comment|/*  * Track end of privilege list.  */
end_comment

begin_define
define|#
directive|define
name|_PRIV_HIGHEST
value|716
end_define

begin_comment
comment|/*  * Validate that a named privilege is known by the privilege system.  Invalid  * privileges presented to the privilege system by a priv_check interface  * will result in a panic.  This is only approximate due to sparse allocation  * of the privilege space.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)> _PRIV_LOWEST&& (x)< _PRIV_HIGHEST)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Privilege check interfaces, modeled after historic suser() interfacs, but  * with the addition of a specific privilege name.  The existing SUSER_* flag  * name space is used here.  The jail flag will likely be something that can  * be removed at some point as jail itself will be able to decide if the priv  * is appropriate, rather than the caller.  */
end_comment

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|priv_check
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|priv_check_cred
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|priv
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_PRIV_H_ */
end_comment

end_unit

