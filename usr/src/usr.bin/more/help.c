begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Mark Nudleman and the University of California, Berkeley.  The  * name of Mark Nudleman or the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)help.c	5.6 (Berkeley) %G%"
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<less.h>
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_macro
name|help
argument_list|()
end_macro

begin_block
block|{
name|char
name|cmd
index|[
name|MAXPATHLEN
operator|+
literal|20
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|cmd
argument_list|,
literal|"-more %s"
argument_list|,
name|_PATH_HELPFILE
argument_list|)
expr_stmt|;
name|lsystem
argument_list|(
name|cmd
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

