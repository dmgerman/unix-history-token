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
literal|"@(#)strcat.c	5.4 (Berkeley) %G%"
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
file|<string.h>
end_include

begin_function
name|char
modifier|*
name|strcat
parameter_list|(
name|s
parameter_list|,
name|append
parameter_list|)
specifier|register
name|char
modifier|*
name|s
decl_stmt|,
decl|*
name|append
decl_stmt|;
end_function

begin_block
block|{
name|char
modifier|*
name|save
init|=
name|s
decl_stmt|;
for|for
control|(
init|;
operator|*
name|s
condition|;
operator|++
name|s
control|)
empty_stmt|;
while|while
condition|(
operator|*
name|s
operator|++
operator|=
operator|*
name|append
operator|++
condition|)
empty_stmt|;
return|return
operator|(
name|save
operator|)
return|;
block|}
end_block

end_unit

