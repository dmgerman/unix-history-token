begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: netwrite.c,v 4.1 88/11/15 16:48:58 jtkohl Exp $";  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char rcsid[] = "$FreeBSD$";
endif|#
directive|endif
endif|lint
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/*  * krb_net_write() writes "len" bytes from "buf" to the file  * descriptor "fd".  It returns the number of bytes written or  * a write() error.  (The calling interface is identical to  * write(2).)  *  * XXX must not use non-blocking I/O  */
end_comment

begin_function
name|int
name|krb_net_write
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
name|int
name|fd
decl_stmt|;
specifier|register
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|int
name|cc
decl_stmt|;
specifier|register
name|int
name|wrlen
init|=
name|len
decl_stmt|;
do|do
block|{
name|cc
operator|=
name|write
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|wrlen
argument_list|)
expr_stmt|;
if|if
condition|(
name|cc
operator|<
literal|0
condition|)
return|return
operator|(
name|cc
operator|)
return|;
else|else
block|{
name|buf
operator|+=
name|cc
expr_stmt|;
name|wrlen
operator|-=
name|cc
expr_stmt|;
block|}
block|}
do|while
condition|(
name|wrlen
operator|>
literal|0
condition|)
do|;
return|return
operator|(
name|len
operator|)
return|;
block|}
end_function

end_unit

