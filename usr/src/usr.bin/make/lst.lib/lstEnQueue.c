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
literal|"@(#)lstEnQueue.c	5.2 (Berkeley) %G%"
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
comment|/*-  * LstEnQueue.c--  *	Treat the list as a queue and place a datum at its end  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_EnQueue --  *	Add the datum to the tail of the given list.  *  * Results:  *	SUCCESS or FAILURE as returned by Lst_Append.  *  * Side Effects:  *	the lastPtr field is altered all the time and the firstPtr field  *	will be altered if the list used to be empty.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ReturnStatus
name|Lst_EnQueue
parameter_list|(
name|l
parameter_list|,
name|d
parameter_list|)
name|Lst
name|l
decl_stmt|;
name|ClientData
name|d
decl_stmt|;
block|{
if|if
condition|(
name|LstValid
argument_list|(
name|l
argument_list|)
operator|==
name|FALSE
condition|)
block|{
return|return
operator|(
name|FAILURE
operator|)
return|;
block|}
return|return
operator|(
name|Lst_Append
argument_list|(
name|l
argument_list|,
name|Lst_Last
argument_list|(
name|l
argument_list|)
argument_list|,
name|d
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

