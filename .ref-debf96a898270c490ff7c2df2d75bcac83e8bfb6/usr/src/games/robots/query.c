begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)query.c	5.3 (Berkeley) %G%"
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
file|"robots.h"
end_include

begin_comment
comment|/*  * query:  *	Ask a question and get a yes or no answer.  Default is "no".  */
end_comment

begin_macro
name|query
argument_list|(
argument|prompt
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|prompt
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|c
decl_stmt|,
name|retval
decl_stmt|;
specifier|register
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
name|getyx
argument_list|(
name|stdscr
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|Y_PROMPT
argument_list|,
name|X_PROMPT
argument_list|)
expr_stmt|;
name|addstr
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
name|retval
operator|=
operator|(
operator|(
name|c
operator|=
name|getchar
argument_list|()
operator|)
operator|==
literal|'y'
operator|||
name|c
operator|==
literal|'Y'
operator|)
expr_stmt|;
name|move
argument_list|(
name|Y_PROMPT
argument_list|,
name|X_PROMPT
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_block

end_unit

