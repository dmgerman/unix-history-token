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
literal|"@(#)damaged.c	5.3 (Berkeley) 6/18/88"
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
file|"trek.h"
end_include

begin_comment
comment|/*  DAMAGED -- check for device damaged ** **	This is a boolean function which returns non-zero if the **	specified device is broken.  It does this by checking the **	event list for a "device fix" action on that device. */
end_comment

begin_macro
name|damaged
argument_list|(
argument|dev
argument_list|)
end_macro

begin_decl_stmt
name|int
name|dev
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|d
decl_stmt|;
specifier|register
name|struct
name|event
modifier|*
name|e
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|d
operator|=
name|dev
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXEVENTS
condition|;
name|i
operator|++
control|)
block|{
name|e
operator|=
operator|&
name|Event
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|evcode
operator|!=
name|E_FIXDV
condition|)
continue|continue;
if|if
condition|(
name|e
operator|->
name|systemname
operator|==
name|d
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* device fix not in event list -- device must not be broken */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

