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
name|char
name|sccsid
index|[]
init|=
literal|"@(#)rindex.c	5.6 (Berkeley) %G%"
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
name|rindex
parameter_list|(
name|p
parameter_list|,
name|ch
parameter_list|)
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
name|ch
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|save
decl_stmt|;
for|for
control|(
name|save
operator|=
name|NULL
init|;
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
name|ch
condition|)
name|save
operator|=
name|p
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|p
condition|)
return|return
operator|(
name|save
operator|)
return|;
block|}
comment|/* NOTREACHED */
block|}
end_function

end_unit

