begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)sethostent.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_function
name|void
name|sethostent
parameter_list|(
name|stayopen
parameter_list|)
block|{
if|if
condition|(
name|stayopen
condition|)
name|_res
operator|.
name|options
operator||=
name|RES_STAYOPEN
operator||
name|RES_USEVC
expr_stmt|;
block|}
end_function

begin_function
name|void
name|endhostent
parameter_list|()
block|{
name|_res
operator|.
name|options
operator|&=
operator|~
operator|(
name|RES_STAYOPEN
operator||
name|RES_USEVC
operator|)
expr_stmt|;
name|_res_close
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

