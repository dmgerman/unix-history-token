begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)idlok.c	5.3 (Berkeley) 6/30/88"
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
file|"curses.ext"
end_include

begin_comment
comment|/*  * idlok:  *	Turn on and off using insert/deleteln sequences for the given  *	window.  *  */
end_comment

begin_expr_stmt
name|idlok
argument_list|(
name|win
argument_list|,
name|bf
argument_list|)
specifier|register
name|WINDOW
operator|*
name|win
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|bf
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|bf
condition|)
name|win
operator|->
name|_flags
operator||=
name|_IDLINE
expr_stmt|;
else|else
name|win
operator|->
name|_flags
operator|&=
operator|~
name|_IDLINE
expr_stmt|;
block|}
end_block

end_unit

