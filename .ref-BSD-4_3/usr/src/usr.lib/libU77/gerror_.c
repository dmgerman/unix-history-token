begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)gerror_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * Return a standard error message in a character string.  *  * calling sequence:  *	call gerror (string)  * or  *	character*20 gerror, string  *	string = gerror()  * where:  *	'string' will receive the standard error message  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"../libI77/f_errno.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|f_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|f_nerr
decl_stmt|;
end_decl_stmt

begin_macro
name|gerror_
argument_list|(
argument|s
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|mesg
decl_stmt|;
if|if
condition|(
name|errno
operator|>=
literal|0
operator|&&
name|errno
operator|<
name|sys_nerr
condition|)
name|mesg
operator|=
name|sys_errlist
index|[
name|errno
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|errno
operator|>=
name|F_ER
operator|&&
name|errno
operator|<
operator|(
name|F_ER
operator|+
name|f_nerr
operator|)
condition|)
name|mesg
operator|=
name|f_errlist
index|[
name|errno
operator|-
name|F_ER
index|]
expr_stmt|;
else|else
name|mesg
operator|=
literal|"unknown error number"
expr_stmt|;
name|b_char
argument_list|(
name|mesg
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

