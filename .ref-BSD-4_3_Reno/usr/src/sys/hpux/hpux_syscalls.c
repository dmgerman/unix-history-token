begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * from: Utah $Hdr: hpux_syscalls.c 1.8 89/08/23$  *  *	@(#)hpux_syscalls.c	7.1 (Berkeley) 5/8/90  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUXCOMPAT
end_ifdef

begin_comment
comment|/*  * HPUX System call names.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hpuxsyscallnames
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
literal|"wait"
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
literal|"old stty"
block|,
comment|/*  31 = old stty */
literal|"old gtty"
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
literal|"ki_syscall"
block|,
comment|/*  45 = ki_syscall */
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
literal|"uname"
block|,
comment|/*  57 = uname */
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
literal|"fcntl"
block|,
comment|/*  62 = fcntl */
literal|"ulimit"
block|,
comment|/*  63 = ulimit */
literal|"#64"
block|,
comment|/*  64 = nosys */
literal|"#65"
block|,
comment|/*  65 = nosys */
literal|"vfork"
block|,
comment|/*  66 = vfork */
literal|"old vread - read"
block|,
comment|/*  67 = old vread */
literal|"old vwrite - write"
block|,
comment|/*  68 = old vwrite */
literal|"#69"
block|,
comment|/*  69 = nosys */
literal|"#70"
block|,
comment|/*  70 = nosys */
literal|"#71"
block|,
comment|/*  71 = nosys */
literal|"#72"
block|,
comment|/*  72 = nosys */
literal|"#73"
block|,
comment|/*  73 = nosys */
literal|"mprotect"
block|,
comment|/*  74 = mprotect */
literal|"#75"
block|,
comment|/*  75 = nosys */
literal|"#76"
block|,
comment|/*  76 = nosys */
literal|"#77"
block|,
comment|/*  77 = nosys */
literal|"#78"
block|,
comment|/*  78 = nosys */
literal|"getgroups"
block|,
comment|/*  79 = getgroups */
literal|"setgroups"
block|,
comment|/*  80 = setgroups */
literal|"getpgrp2"
block|,
comment|/*  81 = getpgrp2 */
literal|"setpgrp2"
block|,
comment|/*  82 = setpgrp2 */
literal|"setitimer"
block|,
comment|/*  83 = setitimer */
literal|"wait3"
block|,
comment|/*  84 = wait3 */
literal|"swapon"
block|,
comment|/*  85 = swapon */
literal|"getitimer"
block|,
comment|/*  86 = getitimer */
literal|"#87"
block|,
comment|/*  87 = nosys */
literal|"#88"
block|,
comment|/*  88 = nosys */
literal|"#89"
block|,
comment|/*  89 = nosys */
literal|"dup2"
block|,
comment|/*  90 = dup2 */
literal|"#91"
block|,
comment|/*  91 = nosys */
literal|"fstat"
block|,
comment|/*  92 = fstat */
literal|"select"
block|,
comment|/*  93 = select */
literal|"#94"
block|,
comment|/*  94 = nosys */
literal|"fsync"
block|,
comment|/*  95 = fsync */
literal|"#96"
block|,
comment|/*  96 = nosys */
literal|"#97"
block|,
comment|/*  97 = nosys */
literal|"#98"
block|,
comment|/*  98 = nosys */
literal|"#99"
block|,
comment|/*  99 = nosys */
literal|"#100"
block|,
comment|/* 100 = nosys */
literal|"#101"
block|,
comment|/* 101 = nosys */
literal|"#102"
block|,
comment|/* 102 = nosys */
literal|"sigreturn"
block|,
comment|/* 103 = BSD sigreturn */
literal|"#104"
block|,
comment|/* 104 = nosys */
literal|"#105"
block|,
comment|/* 105 = nosys */
literal|"#106"
block|,
comment|/* 106 = nosys */
literal|"#107"
block|,
comment|/* 107 = nosys */
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
literal|"#113"
block|,
comment|/* 113 = nosys */
literal|"#114"
block|,
comment|/* 114 = nosys */
literal|"#115"
block|,
comment|/* 115 = nosys */
literal|"gettimeofday"
block|,
comment|/* 116 = gettimeofday */
literal|"#117"
block|,
comment|/* 117 = nosys */
literal|"#118"
block|,
comment|/* 118 = nosys */
literal|"hpib_io_stub"
block|,
comment|/* 119 = hpib_io_stub */
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
literal|"#125"
block|,
comment|/* 125 = nosys */
literal|"setresuid"
block|,
comment|/* 126 = setresuid */
literal|"setresgid"
block|,
comment|/* 127 = setresgid */
literal|"rename"
block|,
comment|/* 128 = rename */
literal|"truncate"
block|,
comment|/* 129 = truncate */
literal|"ftruncate"
block|,
comment|/* 130 = ftruncate */
literal|"#131"
block|,
comment|/* 131 = nosys */
literal|"sysconf"
block|,
comment|/* 132 = sysconf */
literal|"#133"
block|,
comment|/* 133 = nosys */
literal|"#134"
block|,
comment|/* 134 = nosys */
literal|"#135"
block|,
comment|/* 135 = nosys */
literal|"mkdir"
block|,
comment|/* 136 = mkdir */
literal|"rmdir"
block|,
comment|/* 137 = rmdir */
literal|"utimes"
block|,
comment|/* 138 = utimes */
literal|"#139"
block|,
comment|/* 139 = nosys */
literal|"#140"
block|,
comment|/* 140 = nosys */
literal|"#141"
block|,
comment|/* 141 = nosys */
literal|"#142"
block|,
comment|/* 142 = nosys */
literal|"#143"
block|,
comment|/* 143 = nosys */
literal|"#144"
block|,
comment|/* 144 = nosys */
literal|"#145"
block|,
comment|/* 145 = nosys */
literal|"#146"
block|,
comment|/* 146 = nosys */
literal|"#147"
block|,
comment|/* 147 = nosys */
literal|"#148"
block|,
comment|/* 148 = nosys */
literal|"#149"
block|,
comment|/* 149 = nosys */
literal|"#150"
block|,
comment|/* 150 = nosys */
comment|/* 	 * HPUX specific syscalls 	 */
literal|"privgrp"
block|,
comment|/* 151 = privgrp */
literal|"rtprio"
block|,
comment|/* 152 = rtprio */
literal|"plock"
block|,
comment|/* 153 = plock */
literal|"netioctl"
block|,
comment|/* 154 = netioctl */
literal|"lockf"
block|,
comment|/* 155 = lockf */
literal|"semget"
block|,
comment|/* 156 = semget */
literal|"semctl"
block|,
comment|/* 157 = semctl */
literal|"semop"
block|,
comment|/* 158 = semop */
literal|"msgget"
block|,
comment|/* 159 = msgget */
literal|"msgctl"
block|,
comment|/* 160 = msgctl */
literal|"msgsnd"
block|,
comment|/* 161 = msgsnd */
literal|"msgrcv"
block|,
comment|/* 162 = msgrcv */
literal|"shmget"
block|,
comment|/* 163 = shmget */
literal|"shmctl"
block|,
comment|/* 164 = shmctl */
literal|"shmat"
block|,
comment|/* 165 = shmat */
literal|"shmdt"
block|,
comment|/* 166 = shmdt */
literal|"m68020_advise"
block|,
comment|/* 167 = m68020_advise */
literal|"#168"
block|,
comment|/* 168 = nosys */
literal|"cluster"
block|,
comment|/* 169 = cluster */
literal|"mkrnod"
block|,
comment|/* 170 = mkrnod */
literal|"#171"
block|,
comment|/* 171 = nosys */
literal|"#172"
block|,
comment|/* 172 = nosys */
literal|"#173"
block|,
comment|/* 173 = nosys */
literal|"getcontext"
block|,
comment|/* 174 = getcontext */
literal|"#175"
block|,
comment|/* 175 = nosys */
literal|"#176"
block|,
comment|/* 176 = nosys */
literal|"#177"
block|,
comment|/* 177 = nosys */
literal|"lsync"
block|,
comment|/* 178 = lsync */
literal|"#179"
block|,
comment|/* 179 = nosys */
literal|"mysite"
block|,
comment|/* 180 = mysite */
literal|"returnzero"
block|,
comment|/* 181 = returnzero */
literal|"#182"
block|,
comment|/* 182 = nosys */
literal|"#183"
block|,
comment|/* 183 = nosys */
literal|"#184"
block|,
comment|/* 184 = nosys */
literal|"#185"
block|,
comment|/* 185 = nosys */
literal|"setacl"
block|,
comment|/* 186 = setacl */
literal|"fsetacl"
block|,
comment|/* 187 = fsetacl */
literal|"getacl"
block|,
comment|/* 188 = getacl */
literal|"fgetacl"
block|,
comment|/* 189 = fgetacl */
literal|"getaccess"
block|,
comment|/* 190 = getaccess */
literal|"getaudid"
block|,
comment|/* 191 = getaudid */
literal|"setaudid"
block|,
comment|/* 192 = setaudid */
literal|"getaudproc"
block|,
comment|/* 193 = getaudproc */
literal|"setaudproc"
block|,
comment|/* 194 = setaudproc */
literal|"getevent"
block|,
comment|/* 195 = getevent */
literal|"setevent"
block|,
comment|/* 196 = setevent */
literal|"audwrite"
block|,
comment|/* 197 = audwrite */
literal|"audswitch"
block|,
comment|/* 198 = audswitch */
literal|"audctl"
block|,
comment|/* 199 = audctl */
literal|"waitpid"
block|,
comment|/* 200 = waitpid */
literal|"#201"
block|,
comment|/* 201 = nosys */
literal|"netioctl"
block|,
comment|/* 202 = netioctl */
literal|"#203"
block|,
comment|/* 203 = nosys */
literal|"#204"
block|,
comment|/* 204 = nosys */
literal|"#205"
block|,
comment|/* 205 = nosys */
literal|"#206"
block|,
comment|/* 206 = nosys */
literal|"#207"
block|,
comment|/* 207 = nosys */
literal|"#208"
block|,
comment|/* 208 = nosys */
literal|"#209"
block|,
comment|/* 209 = nosys */
literal|"#210"
block|,
comment|/* 210 = nosys */
literal|"#211"
block|,
comment|/* 211 = nosys */
literal|"#212"
block|,
comment|/* 212 = nosys */
literal|"#213"
block|,
comment|/* 213 = nosys */
literal|"#214"
block|,
comment|/* 214 = nosys */
literal|"#215"
block|,
comment|/* 215 = nosys */
literal|"#216"
block|,
comment|/* 216 = nosys */
literal|"#217"
block|,
comment|/* 217 = nosys */
literal|"#218"
block|,
comment|/* 218 = nosys */
literal|"#219"
block|,
comment|/* 219 = nosys */
literal|"#220"
block|,
comment|/* 220 = nosys */
literal|"#221"
block|,
comment|/* 221 = nosys */
literal|"#222"
block|,
comment|/* 222 = nosys */
literal|"#223"
block|,
comment|/* 223 = nosys */
literal|"#224"
block|,
comment|/* 224 = nosys */
literal|"pathconf"
block|,
comment|/* 225 = pathconf */
literal|"fpathconf"
block|,
comment|/* 226 = fpathconf */
literal|"#227"
block|,
comment|/* 227 = nosys */
literal|"#228"
block|,
comment|/* 228 = nosys */
literal|"async_daemon"
block|,
comment|/* 229 = aync_daemon */
literal|"nfs_fcntl"
block|,
comment|/* 230 = nfs_fcntl */
literal|"getdirentries"
block|,
comment|/* 231 = getdirentries */
literal|"getdomainname"
block|,
comment|/* 232 = getdomainname */
literal|"nfs_getfh"
block|,
comment|/* 233 = nfs_getfh */
literal|"vfsmount"
block|,
comment|/* 234 = vfsmount */
literal|"nfs_svc"
block|,
comment|/* 235 = nfs_svc */
literal|"fstatfs"
block|,
comment|/* 236 = setdomainname */
literal|"statfs"
block|,
comment|/* 237 = statfs */
literal|"fstatfs"
block|,
comment|/* 238 = fstatfs */
literal|"sigaction"
block|,
comment|/* 239 = sigaction */
literal|"sigprocmask"
block|,
comment|/* 240 = sigprocmask */
literal|"sigpending"
block|,
comment|/* 241 = sigpending */
literal|"sigsuspend"
block|,
comment|/* 242 = sigsuspend */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hpuxbsdipcnames
index|[]
init|=
block|{
literal|"socket"
block|,
literal|"listen"
block|,
literal|"bind"
block|,
literal|"accept"
block|,
literal|"connect"
block|,
literal|"recv"
block|,
literal|"send"
block|,
literal|"shutdown"
block|,
literal|"getsockname"
block|,
literal|"setsockopt"
block|,
literal|"sendto"
block|,
literal|"recvfrom"
block|,
literal|"getpeername"
block|,
literal|"0x3FB"
block|,
literal|"0x3FC"
block|,
literal|"0x3FD"
block|,
literal|"0x3FE"
block|,
literal|"0x3FF"
block|,
literal|"0x400"
block|,
literal|"0x401"
block|,
literal|"0x402"
block|,
literal|"0x403"
block|,
literal|"0x404"
block|,
literal|"0x405"
block|,
literal|"0x406"
block|,
literal|"0x407"
block|,
literal|"0x408"
block|,
literal|"0x409"
block|,
literal|"0x40A"
block|,
literal|"getsockopt"
block|,
literal|"0x40C"
block|,
literal|"0x40D"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

