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
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1983 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)talk.c	5.4 (Berkeley) 6/29/88"
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
file|"talk.h"
end_include

begin_comment
comment|/*  * talk:	A visual form of write. Using sockets, a two way   *		connection is set up between the two people talking.   *		With the aid of curses, the screen is split into two   *		windows, and each users text is added to the window,  *		one character at a time...  *  *		Written by Kipp Hickman  *		  *		Modified to run under 4.1a by Clem Cole and Peter Moore  *		Modified to run between hosts by Peter Moore, 8/19/82  *		Modified to run under 4.1c by Peter Moore 3/17/83  */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|get_names
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|init_display
argument_list|()
expr_stmt|;
name|open_ctl
argument_list|()
expr_stmt|;
name|open_sockt
argument_list|()
expr_stmt|;
name|start_msgs
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|check_local
argument_list|()
condition|)
name|invite_remote
argument_list|()
expr_stmt|;
name|end_msgs
argument_list|()
expr_stmt|;
name|set_edit_chars
argument_list|()
expr_stmt|;
name|talk
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

