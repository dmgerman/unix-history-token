begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 	unix7sys.h	4.3	84/05/05  */
end_comment

begin_comment
comment|/* From Lou Salkind: compat/RCS/unix7sys.h,v 1.2 84/01/31 13:34:22 */
end_comment

begin_define
define|#
directive|define
name|NSYSTRAPS
value|64
end_define

begin_define
define|#
directive|define
name|NSIGS
value|13
end_define

begin_define
define|#
directive|define
name|ILLSYS
value|-1
end_define

begin_define
define|#
directive|define
name|NORMRET
value|0
end_define

begin_define
define|#
directive|define
name|LONGRET
value|1
end_define

begin_define
define|#
directive|define
name|TWORET
value|2
end_define

begin_define
define|#
directive|define
name|FORK
value|2
end_define

begin_define
define|#
directive|define
name|READ
value|3
end_define

begin_define
define|#
directive|define
name|WRITE
value|4
end_define

begin_define
define|#
directive|define
name|OPEN
value|5
end_define

begin_define
define|#
directive|define
name|CLOSE
value|6
end_define

begin_define
define|#
directive|define
name|WAIT
value|7
end_define

begin_define
define|#
directive|define
name|CREAT
value|8
end_define

begin_define
define|#
directive|define
name|LINK
value|9
end_define

begin_define
define|#
directive|define
name|UNLNK
value|10
end_define

begin_define
define|#
directive|define
name|EXEC
value|11
end_define

begin_define
define|#
directive|define
name|CHDIR
value|12
end_define

begin_define
define|#
directive|define
name|TIME
value|13
end_define

begin_define
define|#
directive|define
name|MKNOD
value|14
end_define

begin_define
define|#
directive|define
name|BRK
value|17
end_define

begin_define
define|#
directive|define
name|STAT
value|18
end_define

begin_define
define|#
directive|define
name|SEEK
value|19
end_define

begin_define
define|#
directive|define
name|SETUID
value|23
end_define

begin_define
define|#
directive|define
name|GETUID
value|24
end_define

begin_define
define|#
directive|define
name|STIME
value|25
end_define

begin_define
define|#
directive|define
name|ALARM
value|27
end_define

begin_define
define|#
directive|define
name|FSTAT
value|28
end_define

begin_define
define|#
directive|define
name|PAUSE
value|29
end_define

begin_define
define|#
directive|define
name|UTIME
value|30
end_define

begin_define
define|#
directive|define
name|NICE
value|34
end_define

begin_define
define|#
directive|define
name|FTIME
value|35
end_define

begin_define
define|#
directive|define
name|SETPGRP
value|39
end_define

begin_define
define|#
directive|define
name|PIPE
value|42
end_define

begin_define
define|#
directive|define
name|TIMES
value|43
end_define

begin_define
define|#
directive|define
name|SETGID
value|46
end_define

begin_define
define|#
directive|define
name|GETGID
value|47
end_define

begin_define
define|#
directive|define
name|SIG
value|48
end_define

begin_define
define|#
directive|define
name|IOCTL
value|54
end_define

begin_define
define|#
directive|define
name|EXECE
value|59
end_define

begin_comment
comment|/*  *	The numerical entries in the following table are  *	really composed of 3 parts.  *	The first entry in each row indicates the number  *	of register arguments for the system call, while  *	the 2nd position is the number of memory arguments  *	the 3rd position is LONGRET if the return is a long (r0 and r1)  *	or is TWORET if the return is 2 ints ala pipe  *	otherwise it is NORMRET.  */
end_comment

begin_decl_stmt
name|int
name|sysargs
index|[]
index|[
literal|3
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/*  0 = indir */
literal|1
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/*  1 = exit */
literal|0
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/*  2 = fork */
literal|1
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/*  3 = read */
literal|1
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/*  4 = write */
literal|0
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/*  5 = open */
literal|1
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/*  6 = close */
literal|0
block|,
literal|0
block|,
name|TWORET
block|,
comment|/*  7 = wait */
literal|0
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/*  8 = creat */
literal|0
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/*  9 = link */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 10 = unlink */
literal|0
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/* 11 = exec */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 12 = chdir */
literal|0
block|,
literal|0
block|,
name|LONGRET
block|,
comment|/* 13 = time */
literal|0
block|,
literal|3
block|,
name|NORMRET
block|,
comment|/* 14 = mknod */
literal|0
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/* 15 = chmod */
literal|0
block|,
literal|3
block|,
name|NORMRET
block|,
comment|/* 16 = chown; now 3 args */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 17 = break */
literal|0
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/* 18 = stat */
literal|1
block|,
literal|3
block|,
name|LONGRET
block|,
comment|/* 19 = seek; now 3 args */
literal|0
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 20 = getpid */
literal|0
block|,
literal|3
block|,
name|NORMRET
block|,
comment|/* 21 = mount */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 22 = umount */
literal|1
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 23 = setuid */
literal|0
block|,
literal|0
block|,
name|TWORET
block|,
comment|/* 24 = getuid */
literal|2
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 25 = stime */
literal|1
block|,
literal|3
block|,
name|NORMRET
block|,
comment|/* 26 = ptrace */
literal|1
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 27 = alarm */
literal|1
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 28 = fstat */
literal|0
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 29 = pause */
literal|0
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/* 30 = utime */
literal|1
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 31 = stty */
literal|1
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 32 = gtty */
literal|0
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/* 33 = access */
literal|1
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 34 = nice */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 35 = ftime; formerly sleep */
literal|0
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 36 = sync */
literal|1
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 37 = kill */
literal|0
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 38 = switch; inoperative */
literal|0
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 39 = setpgrp (not in yet) */
name|ILLSYS
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 40 = tell (obsolete) */
literal|2
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 41 = dup */
literal|0
block|,
literal|0
block|,
name|TWORET
block|,
comment|/* 42 = pipe */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 43 = times */
literal|0
block|,
literal|4
block|,
name|NORMRET
block|,
comment|/* 44 = prof */
name|ILLSYS
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 45 = unused */
literal|1
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 46 = setgid */
literal|0
block|,
literal|0
block|,
name|TWORET
block|,
comment|/* 47 = getgid */
literal|0
block|,
literal|2
block|,
name|NORMRET
block|,
comment|/* 48 = sig */
name|ILLSYS
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 49 = reserved for USG */
name|ILLSYS
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 50 = reserved for USG */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 51 = turn acct off/on */
literal|0
block|,
literal|3
block|,
name|NORMRET
block|,
comment|/* 52 = set user physical addresses */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 53 = lock user in core */
literal|0
block|,
literal|3
block|,
name|NORMRET
block|,
comment|/* 54 = ioctl */
name|ILLSYS
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 55 = readwrite (in abeyance) */
literal|0
block|,
literal|4
block|,
name|NORMRET
block|,
comment|/* 56 = creat mpx comm channel */
name|ILLSYS
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 57 = reserved for USG */
name|ILLSYS
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 58 = reserved for USG */
literal|0
block|,
literal|3
block|,
name|NORMRET
block|,
comment|/* 59 = exece */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 60 = umask */
literal|0
block|,
literal|1
block|,
name|NORMRET
block|,
comment|/* 61 = chroot */
name|ILLSYS
block|,
literal|0
block|,
name|NORMRET
block|,
comment|/* 62 = x */
name|ILLSYS
block|,
literal|0
block|,
name|NORMRET
comment|/* 63 = used internally */
block|}
decl_stmt|;
end_decl_stmt

end_unit

