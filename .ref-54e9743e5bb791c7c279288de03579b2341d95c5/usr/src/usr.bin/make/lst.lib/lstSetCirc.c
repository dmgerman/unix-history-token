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
literal|"@(#)lstSetCirc.c	5.2 (Berkeley) %G%"
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
comment|/*-  * listSetCirc.c --  *	Change the library's notion of the circularity of a list.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*  *------------------------------------------------------------  * Lst_SetCirc --  *	change the circularity of a list  *  * Results:  *	none  *  * Side Effects:  *	The circularity of the list is set appropriately. The head and  *	tail of the list will be linked or unlinked as necessary  *------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Lst_SetCirc
parameter_list|(
name|l
parameter_list|,
name|circ
parameter_list|)
name|Lst
name|l
decl_stmt|;
name|Boolean
name|circ
decl_stmt|;
block|{
specifier|register
name|List
name|list
init|=
operator|(
name|List
operator|)
name|l
decl_stmt|;
comment|/*      * if this isn't a change, do nothing.      */
if|if
condition|(
operator|(
name|list
operator|->
name|isCirc
operator|&&
name|circ
operator|)
operator|||
operator|(
operator|!
name|list
operator|->
name|isCirc
operator|&&
operator|!
name|circ
operator|)
condition|)
block|{
return|return;
block|}
name|list
operator|->
name|isCirc
operator|=
name|circ
expr_stmt|;
if|if
condition|(
name|LstIsEmpty
argument_list|(
name|l
argument_list|)
condition|)
block|{
return|return;
block|}
if|if
condition|(
name|circ
condition|)
block|{
name|list
operator|->
name|firstPtr
operator|->
name|prevPtr
operator|=
name|list
operator|->
name|lastPtr
expr_stmt|;
name|list
operator|->
name|lastPtr
operator|->
name|nextPtr
operator|=
name|list
operator|->
name|firstPtr
expr_stmt|;
block|}
else|else
block|{
name|list
operator|->
name|firstPtr
operator|->
name|prevPtr
operator|=
name|NilListNode
expr_stmt|;
name|list
operator|->
name|lastPtr
operator|->
name|nextPtr
operator|=
name|NilListNode
expr_stmt|;
block|}
block|}
end_function

end_unit

