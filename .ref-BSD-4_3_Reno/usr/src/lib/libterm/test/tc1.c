begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#) Copyright (c) 1980 The Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)tc1.c	5.2 (Berkeley) 1/3/89"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * tc1 [term]  * dummy program to test termlib.  * gets entry, counts it, and prints it.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|rc
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
name|p
operator|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
expr_stmt|;
else|else
name|p
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
name|rc
operator|=
name|tgetent
argument_list|(
name|buf
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"tgetent returns %d, len=%d, text=\n'%s'\n"
argument_list|,
name|rc
argument_list|,
name|strlen
argument_list|(
name|buf
argument_list|)
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

