begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)lstLength.c	5.2 (Berkeley) %G%"
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
comment|/*-  * lstLength.c --  *	Find the length of a lst  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_function
name|int
name|Lst_Length
parameter_list|(
name|l
parameter_list|)
name|Lst
name|l
decl_stmt|;
comment|/* List whose length is desired */
block|{
specifier|register
name|ListNode
name|node
decl_stmt|;
specifier|register
name|List
name|list
init|=
operator|(
name|List
operator|)
name|l
decl_stmt|;
specifier|register
name|int
name|len
decl_stmt|;
if|if
condition|(
operator|!
name|LstValid
argument_list|(
name|l
argument_list|)
condition|)
block|{
return|return
operator|-
literal|1
return|;
block|}
for|for
control|(
name|len
operator|=
literal|0
operator|,
name|node
operator|=
name|list
operator|->
name|firstPtr
init|;
name|node
operator|!=
name|NilListNode
condition|;
name|len
operator|++
operator|,
name|node
operator|=
name|node
operator|->
name|nextPtr
control|)
block|{
if|if
condition|(
name|node
operator|==
name|list
operator|->
name|firstPtr
operator|&&
name|len
operator|!=
literal|0
condition|)
block|{
break|break;
block|}
block|}
return|return
name|len
return|;
block|}
end_function

end_unit

