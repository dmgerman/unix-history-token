begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)wwredraw.c	3.13 (Berkeley) 6/6/90"
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
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|"tt.h"
end_include

begin_macro
name|wwredraw
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|i
operator|,
name|j
expr_stmt|;
specifier|register
name|union
name|ww_char
modifier|*
name|os
decl_stmt|;
name|xxclear
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|wwnrow
condition|;
name|i
operator|++
control|)
block|{
name|wwtouched
index|[
name|i
index|]
operator|=
name|WWU_TOUCHED
expr_stmt|;
name|os
operator|=
name|wwos
index|[
name|i
index|]
expr_stmt|;
for|for
control|(
name|j
operator|=
name|wwncol
init|;
operator|--
name|j
operator|>=
literal|0
condition|;
control|)
operator|(
name|os
operator|++
operator|)
operator|->
name|c_w
operator|=
literal|' '
expr_stmt|;
block|}
block|}
end_block

end_unit

