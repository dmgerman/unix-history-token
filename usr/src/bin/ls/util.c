begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Michael Fischbein.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)util.c	5.4 (Berkeley) %G%"
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
file|<ctype.h>
end_include

begin_expr_stmt
name|prcopy
argument_list|(
name|src
argument_list|,
name|dest
argument_list|,
name|len
argument_list|)
specifier|register
name|char
operator|*
name|src
operator|,
operator|*
name|dest
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|ch
decl_stmt|;
while|while
condition|(
name|len
operator|--
condition|)
block|{
name|ch
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dest
operator|++
operator|=
name|isprint
argument_list|(
name|ch
argument_list|)
condition|?
name|ch
else|:
literal|'?'
expr_stmt|;
block|}
block|}
end_block

begin_function
name|char
modifier|*
name|emalloc
parameter_list|(
name|size
parameter_list|)
name|u_int
name|size
decl_stmt|;
block|{
name|char
modifier|*
name|retval
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|retval
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
operator|)
condition|)
name|nomem
argument_list|()
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_macro
name|nomem
argument_list|()
end_macro

begin_block
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ls: out of memory.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|usage
argument_list|()
end_macro

begin_block
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: ls [-1ACFLRacdgilqrstu] [file ...]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

