begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)hostnm_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * hostnm - return this machines hostname  *  * synopsis:  *	integer function hostnm (name)  *	character(*) name  *  * where:  *	name	will receive the host name  *	The returned value will be 0 if successful, an error number otherwise.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|hostnm_
parameter_list|(
name|name
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|long
name|len
decl_stmt|;
block|{
name|char
name|buf
index|[
literal|64
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
name|int
name|blen
init|=
sizeof|sizeof
name|buf
decl_stmt|;
if|if
condition|(
name|gethostname
argument_list|(
name|buf
argument_list|,
name|blen
argument_list|)
operator|==
literal|0
condition|)
block|{
name|b_char
argument_list|(
name|buf
argument_list|,
name|name
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0L
operator|)
return|;
block|}
else|else
return|return
operator|(
operator|(
name|long
operator|)
name|errno
operator|)
return|;
block|}
end_function

end_unit

