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
literal|"@(#)lstIsEmpty.c	5.2 (Berkeley) %G%"
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
comment|/*-  * LstIsEmpty.c --  *	A single function to decide if a list is empty  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_IsEmpty --  *	Return TRUE if the given list is empty.  *  * Results:  *	TRUE if the list is empty, FALSE otherwise.  *  * Side Effects:  *	None.  *  *	A list is considered empty if its firstPtr == NilListNode (or if  *	the list itself is NILLIST).  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|Boolean
name|Lst_IsEmpty
parameter_list|(
name|l
parameter_list|)
name|Lst
name|l
decl_stmt|;
block|{
return|return
operator|(
operator|!
name|LstValid
argument_list|(
name|l
argument_list|)
operator|||
name|LstIsEmpty
argument_list|(
name|l
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

