begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)RELSGE.c	1.3 (Berkeley) 4/9/90"
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
file|"h00vars.h"
end_include

begin_function
name|bool
name|RELSGE
parameter_list|(
name|siz
parameter_list|,
name|str1
parameter_list|,
name|str2
parameter_list|)
name|long
name|siz
decl_stmt|;
specifier|register
name|char
modifier|*
name|str1
decl_stmt|;
specifier|register
name|char
modifier|*
name|str2
decl_stmt|;
block|{
specifier|register
name|int
name|size
init|=
name|siz
decl_stmt|;
while|while
condition|(
operator|*
name|str1
operator|++
operator|==
operator|*
name|str2
operator|++
operator|&&
operator|--
name|size
condition|)
comment|/* void */
empty_stmt|;
if|if
condition|(
operator|(
name|size
operator|==
literal|0
operator|)
operator|||
operator|(
operator|*
operator|--
name|str1
operator|>=
operator|*
operator|--
name|str2
operator|)
condition|)
return|return
name|TRUE
return|;
return|return
name|FALSE
return|;
block|}
end_function

end_unit

