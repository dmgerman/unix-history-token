begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)sysexits.c	5.6 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_comment
comment|/*  *  SYSEXITS.C -- error messages corresponding to sysexits.h  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SysExMsg
index|[]
init|=
block|{
comment|/* 64 USAGE */
literal|"500 Bad usage"
block|,
comment|/* 65 DATAERR */
literal|"501 Data format error"
block|,
comment|/* 66 NOINPUT */
literal|"550 Cannot open input"
block|,
comment|/* 67 NOUSER */
literal|"550 User unknown"
block|,
comment|/* 68 NOHOST */
literal|"550 Host unknown"
block|,
comment|/* 69 UNAVAILABLE */
literal|"554 Service unavailable"
block|,
comment|/* 70 SOFTWARE */
literal|"554 Internal error"
block|,
comment|/* 71 OSERR */
literal|"451 Operating system error"
block|,
comment|/* 72 OSFILE */
literal|"554 System file missing"
block|,
comment|/* 73 CANTCREAT */
literal|"550 Can't create output"
block|,
comment|/* 74 IOERR */
literal|"451 I/O error"
block|,
comment|/* 75 TEMPFAIL */
literal|"250 Deferred"
block|,
comment|/* 76 PROTOCOL */
literal|"554 Remote protocol error"
block|,
comment|/* 77 NOPERM */
literal|"550 Insufficient permission"
block|,
comment|/* 78 CONFIG */
literal|"554 Local configuration error"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|N_SysEx
init|=
sizeof|sizeof
argument_list|(
name|SysExMsg
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|SysExMsg
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  STATSTRING -- return string corresponding to an error status  *  *	Parameters:  *		stat -- the status to decode.  *  *	Returns:  *		The string corresponding to that status  *  *	Side Effects:  *		none.  */
end_comment

begin_function
name|char
modifier|*
name|statstring
parameter_list|(
name|stat
parameter_list|)
name|int
name|stat
decl_stmt|;
block|{
specifier|static
name|char
name|ebuf
index|[
literal|50
index|]
decl_stmt|;
name|stat
operator|-=
name|EX__BASE
expr_stmt|;
if|if
condition|(
name|stat
operator|<
literal|0
operator|||
name|stat
operator|>=
name|N_SysEx
condition|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|ebuf
argument_list|,
literal|"554 Unknown status %d"
argument_list|,
name|stat
operator|+
name|EX__BASE
argument_list|)
expr_stmt|;
return|return
operator|(
name|ebuf
operator|)
return|;
block|}
return|return
operator|(
name|SysExMsg
index|[
name|stat
index|]
operator|)
return|;
block|}
end_function

end_unit

