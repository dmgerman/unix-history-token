begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#) Copyright (c) 1988 Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)tty.c	4.3 (Berkeley) %G%"
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
file|<stdio.h>
end_include

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
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|ch
decl_stmt|,
name|sflag
decl_stmt|;
name|char
modifier|*
name|t
decl_stmt|,
modifier|*
name|ttyname
argument_list|()
decl_stmt|;
name|sflag
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"s"
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
switch|switch
condition|(
operator|(
name|char
operator|)
name|ch
condition|)
block|{
case|case
literal|'s'
case|:
name|sflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
name|fputs
argument_list|(
literal|"usage: tty [-s]\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
name|t
operator|=
name|ttyname
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sflag
condition|)
name|puts
argument_list|(
name|t
condition|?
name|t
else|:
literal|"not a tty"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|t
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

