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
literal|"@(#)blkcpy.c	1.4 (Berkeley) 4/9/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_expr_stmt
name|blkcpy
argument_list|(
name|from
argument_list|,
name|to
argument_list|,
name|siz
argument_list|)
specifier|register
name|char
operator|*
name|from
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|siz
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|size
init|=
name|siz
decl_stmt|;
if|if
condition|(
name|to
operator|<
name|from
condition|)
while|while
condition|(
name|size
operator|--
operator|>
literal|0
condition|)
operator|*
name|to
operator|++
operator|=
operator|*
name|from
operator|++
expr_stmt|;
else|else
block|{
name|to
operator|+=
name|size
expr_stmt|;
name|from
operator|+=
name|size
expr_stmt|;
while|while
condition|(
name|size
operator|--
operator|>
literal|0
condition|)
operator|*
operator|--
name|to
operator|=
operator|*
operator|--
name|from
expr_stmt|;
block|}
block|}
end_block

end_unit

