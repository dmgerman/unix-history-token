begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)waitpid.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_macro
name|waitpid
argument_list|(
argument|pid
argument_list|,
argument|pstat
argument_list|,
argument|options
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|wait
modifier|*
name|pstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|options
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|wait4
argument_list|(
name|pid
argument_list|,
name|pstat
argument_list|,
name|options
argument_list|,
operator|(
expr|struct
name|rusage
operator|*
operator|)
literal|0
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

