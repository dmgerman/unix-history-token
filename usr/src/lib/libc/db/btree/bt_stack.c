begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mike Olson.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)bt_stack.c	8.3 (Berkeley) %G%"
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|"btree.h"
end_include

begin_comment
comment|/*  * When a page splits, a new record has to be inserted into its parent page.  * This page may have to split as well, all the way up to the root.  Since  * parent pointers in each page would be expensive, we maintain a stack of  * parent pages as we descend the tree.  *  * XXX  * This is a concurrency problem -- if user a builds a stack, then user b  * splits the tree, then user a tries to split the tree, there's a new level  * in the tree that user a doesn't know about.  */
end_comment

begin_comment
comment|/*  * __BT_PUSH -- Push parent page info onto the stack (LIFO).  *  * Parameters:  *	t:	tree  *	pgno:	page  *	index:	page index  *  * Returns:  * 	RET_ERROR, RET_SUCCESS  */
end_comment

begin_function
name|int
name|__bt_push
parameter_list|(
name|t
parameter_list|,
name|pgno
parameter_list|,
name|index
parameter_list|)
name|BTREE
modifier|*
name|t
decl_stmt|;
name|pgno_t
name|pgno
decl_stmt|;
name|indx_t
name|index
decl_stmt|;
block|{
if|if
condition|(
name|t
operator|->
name|bt_sp
operator|==
name|t
operator|->
name|bt_maxstack
condition|)
block|{
name|t
operator|->
name|bt_maxstack
operator|+=
literal|50
expr_stmt|;
if|if
condition|(
operator|(
name|t
operator|->
name|bt_stack
operator|=
operator|(
name|EPGNO
operator|*
operator|)
name|realloc
argument_list|(
name|t
operator|->
name|bt_stack
argument_list|,
name|t
operator|->
name|bt_maxstack
operator|*
sizeof|sizeof
argument_list|(
name|EPGNO
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|t
operator|->
name|bt_maxstack
operator|-=
literal|50
expr_stmt|;
return|return
operator|(
name|RET_ERROR
operator|)
return|;
block|}
block|}
name|t
operator|->
name|bt_stack
index|[
name|t
operator|->
name|bt_sp
index|]
operator|.
name|pgno
operator|=
name|pgno
expr_stmt|;
name|t
operator|->
name|bt_stack
index|[
name|t
operator|->
name|bt_sp
index|]
operator|.
name|index
operator|=
name|index
expr_stmt|;
operator|++
name|t
operator|->
name|bt_sp
expr_stmt|;
return|return
operator|(
name|RET_SUCCESS
operator|)
return|;
block|}
end_function

end_unit

