begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|sysent
index|[]
block|{
literal|0
operator|,
operator|&
name|nullsys
operator|,
comment|/*  0 = indir */
literal|0
operator|,
operator|&
name|rexit
operator|,
comment|/*  1 = exit */
literal|0
operator|,
operator|&
name|fork
operator|,
comment|/*  2 = fork */
literal|2
operator|,
operator|&
name|read
operator|,
comment|/*  3 = read */
literal|2
operator|,
operator|&
name|write
operator|,
comment|/*  4 = write */
literal|2
operator|,
operator|&
name|open
operator|,
comment|/*  5 = open */
literal|0
operator|,
operator|&
name|close
operator|,
comment|/*  6 = close */
literal|0
operator|,
operator|&
name|wait
operator|,
comment|/*  7 = wait */
literal|2
operator|,
operator|&
name|creat
operator|,
comment|/*  8 = creat */
literal|2
operator|,
operator|&
name|link
operator|,
comment|/*  9 = link */
literal|1
operator|,
operator|&
name|unlink
operator|,
comment|/* 10 = unlink */
literal|2
operator|,
operator|&
name|exec
operator|,
comment|/* 11 = exec */
literal|1
operator|,
operator|&
name|chdir
operator|,
comment|/* 12 = chdir */
literal|0
operator|,
operator|&
name|gtime
operator|,
comment|/* 13 = time */
literal|3
operator|,
operator|&
name|mknod
operator|,
comment|/* 14 = mknod */
literal|2
operator|,
operator|&
name|chmod
operator|,
comment|/* 15 = chmod */
literal|2
operator|,
operator|&
name|chown
operator|,
comment|/* 16 = chown */
literal|1
operator|,
operator|&
name|sbreak
operator|,
comment|/* 17 = break */
literal|2
operator|,
operator|&
name|stat
operator|,
comment|/* 18 = stat */
literal|2
operator|,
operator|&
name|seek
operator|,
comment|/* 19 = seek */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 20 = x */
literal|2
operator|,
operator|&
name|smount
operator|,
comment|/* 21 = mount */
literal|1
operator|,
operator|&
name|sumount
operator|,
comment|/* 22 = umount */
literal|0
operator|,
operator|&
name|setuid
operator|,
comment|/* 23 = setuid */
literal|0
operator|,
operator|&
name|getuid
operator|,
comment|/* 24 = getuid */
literal|0
operator|,
operator|&
name|stime
operator|,
comment|/* 25 = stime */
literal|1
operator|,
operator|&
name|quit
operator|,
comment|/* 26 = quit */
literal|1
operator|,
operator|&
name|intr
operator|,
comment|/* 27 = intr */
literal|1
operator|,
operator|&
name|fstat
operator|,
comment|/* 28 = fstat */
literal|1
operator|,
operator|&
name|cemt
operator|,
comment|/* 29 = cemt */
literal|1
operator|,
operator|&
name|nullsys
operator|,
comment|/* 30 = smdate */
literal|1
operator|,
operator|&
name|stty
operator|,
comment|/* 31 = stty */
literal|1
operator|,
operator|&
name|gtty
operator|,
comment|/* 32 = gtty */
literal|1
operator|,
operator|&
name|ilgins
operator|,
comment|/* 33 = ilgins */
literal|0
operator|,
operator|&
name|nullsys
operator|,
comment|/* 34 = nice */
literal|0
operator|,
operator|&
name|sslep
operator|,
comment|/* 35 = sleep */
literal|0
operator|,
operator|&
name|sync
operator|,
comment|/* 36 = sync */
literal|0
operator|,
operator|&
name|kill
operator|,
comment|/* 37 = kill */
literal|0
operator|,
operator|&
name|getswit
operator|,
comment|/* 38 = switch */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 39 = panic */
literal|1
operator|,
operator|&
name|fpe
operator|,
comment|/* 40 = fpe */
literal|0
operator|,
operator|&
name|dup
operator|,
comment|/* 41 = dup */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 42 = pipe */
literal|1
operator|,
operator|&
name|times
operator|,
comment|/* 43 = times */
literal|4
operator|,
operator|&
name|nullsys
operator|,
comment|/* 44 = prof */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 45 = tiu */
literal|0
operator|,
operator|&
name|setgid
operator|,
comment|/* 46 = setgid */
literal|0
operator|,
operator|&
name|getgid
operator|,
comment|/* 47 = getgid */
literal|2
operator|,
operator|&
name|ssig
operator|,
comment|/* 48 = sig */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 49 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 50 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 51 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 52 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 53 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 54 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 55 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 56 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 57 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 58 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 59 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 60 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 61 = x */
literal|0
operator|,
operator|&
name|nosys
operator|,
comment|/* 62 = x */
literal|0
operator|,
operator|&
name|prproc
comment|/* 63 = special */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

