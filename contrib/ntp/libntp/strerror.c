begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)strerror.c	5.1 (Berkeley) 4/9/89"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|int
name|errnum
parameter_list|)
block|{
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
specifier|static
name|char
name|ebuf
index|[
literal|20
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|unsigned
name|int
operator|)
name|errnum
operator|<
name|sys_nerr
condition|)
return|return
operator|(
name|sys_errlist
index|[
name|errnum
index|]
operator|)
return|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|ebuf
argument_list|,
literal|"Unknown error: %d"
argument_list|,
name|errnum
argument_list|)
expr_stmt|;
return|return
operator|(
name|ebuf
operator|)
return|;
block|}
end_function

end_unit

