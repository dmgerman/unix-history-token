begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)misc.c	5.3 (Berkeley) 6/1/90"
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
file|"externs.h"
end_include

begin_expr_stmt
name|card
argument_list|(
name|array
argument_list|,
name|size
argument_list|)
comment|/* for beenthere, injuries */
specifier|register
name|char
operator|*
name|array
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|end
init|=
name|array
operator|+
name|size
decl_stmt|;
specifier|register
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|array
operator|<
name|end
condition|)
if|if
condition|(
operator|*
name|array
operator|++
condition|)
name|i
operator|++
expr_stmt|;
return|return
operator|(
name|i
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|ucard
argument_list|(
name|array
argument_list|)
specifier|register
name|unsigned
operator|*
name|array
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|j
init|=
literal|0
decl_stmt|,
name|n
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|NUMOFOBJECTS
condition|;
name|n
operator|++
control|)
if|if
condition|(
name|testbit
argument_list|(
name|array
argument_list|,
name|n
argument_list|)
condition|)
name|j
operator|++
expr_stmt|;
return|return
operator|(
name|j
operator|)
return|;
block|}
end_block

end_unit

