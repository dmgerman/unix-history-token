begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)wwclreos.c	3.9 (Berkeley) %G%"
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

begin_expr_stmt
name|wwclreos
argument_list|(
name|w
argument_list|,
name|row
argument_list|,
name|col
argument_list|)
specifier|register
expr|struct
name|ww
operator|*
name|w
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|i
expr_stmt|;
name|wwclreol
argument_list|(
name|w
argument_list|,
name|row
argument_list|,
name|col
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|row
operator|+
literal|1
init|;
name|i
operator|<
name|w
operator|->
name|ww_b
operator|.
name|b
condition|;
name|i
operator|++
control|)
name|wwclreol
argument_list|(
name|w
argument_list|,
name|i
argument_list|,
name|w
operator|->
name|ww_b
operator|.
name|l
argument_list|)
expr_stmt|;
comment|/* XXX */
if|if
condition|(
operator|!
name|w
operator|->
name|ww_noupdate
condition|)
name|wwupdate1
argument_list|(
name|w
operator|->
name|ww_i
operator|.
name|t
argument_list|,
name|w
operator|->
name|ww_i
operator|.
name|b
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

