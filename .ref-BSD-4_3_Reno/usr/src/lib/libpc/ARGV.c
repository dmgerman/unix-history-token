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
literal|"@(#)ARGV.c	1.5 (Berkeley) 4/9/90"
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

begin_macro
name|ARGV
argument_list|(
argument|subscript
argument_list|,
argument|var
argument_list|,
argument|siz
argument_list|)
end_macro

begin_decl_stmt
name|long
name|subscript
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* subscript into argv */
end_comment

begin_decl_stmt
specifier|register
name|char
modifier|*
name|var
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to pascal char array */
end_comment

begin_decl_stmt
name|long
name|siz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizeof(var) */
end_comment

begin_block
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
specifier|register
name|int
name|size
init|=
name|siz
decl_stmt|;
if|if
condition|(
operator|(
name|unsigned
operator|)
name|subscript
operator|>=
name|_argc
condition|)
block|{
name|ERROR
argument_list|(
literal|"Argument to argv of %D is out of range\n"
argument_list|,
name|subscript
argument_list|)
expr_stmt|;
return|return;
block|}
name|cp
operator|=
name|_argv
index|[
name|subscript
index|]
expr_stmt|;
do|do
block|{
operator|*
name|var
operator|++
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|size
operator|&&
operator|*
name|cp
condition|)
do|;
while|while
condition|(
name|size
operator|--
condition|)
operator|*
name|var
operator|++
operator|=
literal|' '
expr_stmt|;
block|}
end_block

end_unit

