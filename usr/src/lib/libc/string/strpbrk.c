begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)strpbrk.c	5.6 (Berkeley) %G%"
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

begin_include
include|#
directive|include
file|<sys/stdc.h>
end_include

begin_comment
comment|/*  * Find the first occurrence in s1 of a character in s2 (excluding NUL).  */
end_comment

begin_function
name|char
modifier|*
name|strpbrk
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
specifier|register
specifier|const
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_block
block|{
specifier|register
specifier|const
name|char
modifier|*
name|scanp
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|,
name|sc
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|s1
operator|++
operator|)
operator|!=
literal|0
condition|)
block|{
for|for
control|(
name|scanp
operator|=
name|s2
init|;
operator|(
name|sc
operator|=
operator|*
name|scanp
operator|++
operator|)
operator|!=
literal|0
condition|;
control|)
if|if
condition|(
name|sc
operator|==
name|c
condition|)
return|return
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
name|s1
operator|-
literal|1
operator|)
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_block

end_unit

