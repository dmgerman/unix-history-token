begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)strdup.c	5.2 (Berkeley) %G%"
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
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|char
modifier|*
name|strdup
parameter_list|(
name|str
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
block|{
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|copy
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|str
argument_list|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|copy
operator|=
name|malloc
argument_list|(
operator|(
name|u_int
operator|)
name|len
argument_list|)
operator|)
condition|)
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|NULL
operator|)
return|;
name|bcopy
argument_list|(
name|str
argument_list|,
name|copy
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
name|copy
operator|)
return|;
block|}
end_function

end_unit

