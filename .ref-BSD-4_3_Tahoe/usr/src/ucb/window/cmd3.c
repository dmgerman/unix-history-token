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
literal|"@(#)cmd3.c	3.16 (Berkeley) 6/29/88"
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
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"string.h"
end_include

begin_expr_stmt
name|setescape
argument_list|(
name|esc
argument_list|)
specifier|register
name|char
operator|*
name|esc
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
operator|*
name|esc
operator|==
literal|'^'
condition|)
block|{
if|if
condition|(
name|esc
index|[
literal|1
index|]
operator|!=
literal|0
condition|)
name|escapec
operator|=
name|esc
index|[
literal|1
index|]
operator|&
literal|0x1f
expr_stmt|;
else|else
name|escapec
operator|=
literal|'^'
expr_stmt|;
block|}
else|else
name|escapec
operator|=
operator|*
name|esc
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|setlabel
argument_list|(
name|w
argument_list|,
name|label
argument_list|)
specifier|register
expr|struct
name|ww
operator|*
name|w
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|label
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|w
operator|->
name|ww_label
operator|!=
literal|0
condition|)
name|str_free
argument_list|(
name|w
operator|->
name|ww_label
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|w
operator|->
name|ww_label
operator|=
name|str_cpy
argument_list|(
name|label
argument_list|)
operator|)
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
return|return
literal|0
return|;
block|}
end_block

end_unit

