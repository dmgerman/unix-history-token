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
literal|"@(#)INCT.c	1.3 (Berkeley) 4/9/90"
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
name|INCT
parameter_list|(
name|element
parameter_list|,
name|paircnt
parameter_list|,
name|singcnt
parameter_list|,
name|data
parameter_list|)
specifier|register
name|long
name|element
decl_stmt|;
comment|/* element to find */
name|long
name|paircnt
decl_stmt|;
comment|/* number of pairs to check */
name|long
name|singcnt
decl_stmt|;
comment|/* number of singles to check */
name|long
name|data
decl_stmt|;
comment|/* paircnt plus singcnt bounds */
block|{
specifier|register
name|long
modifier|*
name|dataptr
init|=
operator|&
name|data
decl_stmt|;
specifier|register
name|int
name|cnt
decl_stmt|;
for|for
control|(
name|cnt
operator|=
literal|0
init|;
name|cnt
operator|<
name|paircnt
condition|;
name|cnt
operator|++
control|)
block|{
if|if
condition|(
name|element
operator|>
operator|*
name|dataptr
operator|++
condition|)
block|{
name|dataptr
operator|++
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|element
operator|>=
operator|*
name|dataptr
operator|++
condition|)
block|{
return|return
name|TRUE
return|;
block|}
block|}
for|for
control|(
name|cnt
operator|=
literal|0
init|;
name|cnt
operator|<
name|singcnt
condition|;
name|cnt
operator|++
control|)
block|{
if|if
condition|(
name|element
operator|==
operator|*
name|dataptr
operator|++
condition|)
block|{
return|return
name|TRUE
return|;
block|}
block|}
return|return
name|FALSE
return|;
block|}
end_function

end_unit

