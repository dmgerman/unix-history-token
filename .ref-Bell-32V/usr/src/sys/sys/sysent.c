begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This table is the switch used to transfer  * to the appropriate routine for processing a system call.  * Each row contains the number of arguments expected  * and a pointer to the routine.  */
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
name|alarm
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
name|chroot
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
name|creat
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
name|exec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exece
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
name|fstat
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
name|gtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gtty
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
name|kill
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
name|mknod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpxchan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nice
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ftime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nosys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nullsys
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
name|pause
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
name|ptrace
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
name|rexit
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
name|sbreak
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|seek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssig
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sumount
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
name|sysacct
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syslock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysphys
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|times
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
name|unlink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|utime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|sysent
name|sysent
index|[
literal|64
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 0 = indir */
literal|1
block|,
literal|0
block|,
name|rexit
block|,
comment|/*  1 = exit */
literal|0
block|,
literal|0
block|,
name|fork
block|,
comment|/*  2 = fork */
literal|3
block|,
literal|0
block|,
name|read
block|,
comment|/*  3 = read */
literal|3
block|,
literal|0
block|,
name|write
block|,
comment|/*  4 = write */
literal|2
block|,
literal|0
block|,
name|open
block|,
comment|/*  5 = open */
literal|1
block|,
literal|0
block|,
name|close
block|,
comment|/*  6 = close */
literal|0
block|,
literal|0
block|,
name|wait
block|,
comment|/*  7 = wait */
literal|2
block|,
literal|0
block|,
name|creat
block|,
comment|/*  8 = creat */
literal|2
block|,
literal|0
block|,
name|link
block|,
comment|/*  9 = link */
literal|1
block|,
literal|0
block|,
name|unlink
block|,
comment|/* 10 = unlink */
literal|2
block|,
literal|0
block|,
name|exec
block|,
comment|/* 11 = exec */
literal|1
block|,
literal|0
block|,
name|chdir
block|,
comment|/* 12 = chdir */
literal|0
block|,
literal|0
block|,
name|gtime
block|,
comment|/* 13 = time */
literal|3
block|,
literal|0
block|,
name|mknod
block|,
comment|/* 14 = mknod */
literal|2
block|,
literal|0
block|,
name|chmod
block|,
comment|/* 15 = chmod */
literal|3
block|,
literal|0
block|,
name|chown
block|,
comment|/* 16 = chown; now 3 args */
literal|1
block|,
literal|0
block|,
name|sbreak
block|,
comment|/* 17 = break */
literal|2
block|,
literal|0
block|,
name|stat
block|,
comment|/* 18 = stat */
literal|3
block|,
literal|0
block|,
name|seek
block|,
comment|/* 19 = seek */
literal|0
block|,
literal|0
block|,
name|getpid
block|,
comment|/* 20 = getpid */
literal|3
block|,
literal|0
block|,
name|smount
block|,
comment|/* 21 = mount */
literal|1
block|,
literal|0
block|,
name|sumount
block|,
comment|/* 22 = umount */
literal|1
block|,
literal|0
block|,
name|setuid
block|,
comment|/* 23 = setuid */
literal|0
block|,
literal|0
block|,
name|getuid
block|,
comment|/* 24 = getuid */
literal|1
block|,
literal|0
block|,
name|stime
block|,
comment|/* 25 = stime */
literal|4
block|,
literal|0
block|,
name|ptrace
block|,
comment|/* 26 = ptrace */
literal|1
block|,
literal|0
block|,
name|alarm
block|,
comment|/* 27 = alarm */
literal|2
block|,
literal|0
block|,
name|fstat
block|,
comment|/* 28 = fstat */
literal|0
block|,
literal|0
block|,
name|pause
block|,
comment|/* 29 = pause */
literal|2
block|,
literal|0
block|,
name|utime
block|,
comment|/* 30 = utime */
literal|2
block|,
literal|0
block|,
name|stty
block|,
comment|/* 31 = stty */
literal|2
block|,
literal|0
block|,
name|gtty
block|,
comment|/* 32 = gtty */
literal|2
block|,
literal|0
block|,
name|saccess
block|,
comment|/* 33 = access */
literal|1
block|,
literal|0
block|,
name|nice
block|,
comment|/* 34 = nice */
literal|1
block|,
literal|0
block|,
name|ftime
block|,
comment|/* 35 = ftime; formally sleep;  */
literal|0
block|,
literal|0
block|,
name|sync
block|,
comment|/* 36 = sync */
literal|2
block|,
literal|0
block|,
name|kill
block|,
comment|/* 37 = kill */
literal|0
block|,
literal|0
block|,
name|nullsys
block|,
comment|/* 38 = switch; inoperative */
literal|0
block|,
literal|0
block|,
name|nullsys
block|,
comment|/* 39 = setpgrp (not in yet) */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 40 = tell - obsolete */
literal|2
block|,
literal|0
block|,
name|dup
block|,
comment|/* 41 = dup */
literal|0
block|,
literal|0
block|,
name|pipe
block|,
comment|/* 42 = pipe */
literal|1
block|,
literal|0
block|,
name|times
block|,
comment|/* 43 = times */
literal|4
block|,
literal|0
block|,
name|profil
block|,
comment|/* 44 = prof */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 45 = tiu */
literal|1
block|,
literal|0
block|,
name|setgid
block|,
comment|/* 46 = setgid */
literal|0
block|,
literal|0
block|,
name|getgid
block|,
comment|/* 47 = getgid */
literal|2
block|,
literal|0
block|,
name|ssig
block|,
comment|/* 48 = sig */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 49 = reserved for USG */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 50 = reserved for USG */
literal|1
block|,
literal|0
block|,
name|sysacct
block|,
comment|/* 51 = turn acct off/on */
literal|3
block|,
literal|0
block|,
name|sysphys
block|,
comment|/* 52 = set user physical addresses */
literal|1
block|,
literal|0
block|,
name|syslock
block|,
comment|/* 53 = lock user in core */
literal|3
block|,
literal|0
block|,
name|ioctl
block|,
comment|/* 54 = ioctl */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 55 = reboot */
literal|4
block|,
literal|0
block|,
name|mpxchan
block|,
comment|/* 56 = creat mpx comm channel */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 57 = reserved for USG */
literal|0
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 58 = reserved for USG */
literal|3
block|,
literal|0
block|,
name|exece
block|,
comment|/* 59 = exece */
literal|1
block|,
literal|0
block|,
name|umask
block|,
comment|/* 60 = umask */
literal|1
block|,
literal|0
block|,
name|chroot
block|,
comment|/* 61 = chroot */
literal|1
block|,
literal|0
block|,
name|nosys
block|,
comment|/* 62 = unused */
literal|0
block|,
literal|0
block|,
name|nosys
comment|/* 63 = used internally */
block|}
decl_stmt|;
end_decl_stmt

end_unit

