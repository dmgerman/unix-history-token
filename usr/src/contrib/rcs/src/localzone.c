begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)localzone.c	5.1 (Berkeley) 8/15/89"
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
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|lclzon
decl_stmt|;
end_decl_stmt

begin_macro
name|localzone
argument_list|()
end_macro

begin_block
block|{
name|struct
name|timezone
name|tz
decl_stmt|;
if|if
condition|(
operator|!
name|lclzon
condition|)
block|{
operator|(
name|void
operator|)
name|gettimeofday
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|)
name|NULL
argument_list|,
operator|&
name|tz
argument_list|)
expr_stmt|;
name|lclzon
operator|=
name|tz
operator|.
name|tz_minuteswest
expr_stmt|;
block|}
return|return
operator|(
name|lclzon
operator|)
return|;
block|}
end_block

end_unit

