begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)bt_page.c	8.2 (Berkeley) %G%"
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
file|<stdio.h>
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
comment|/*  * __BT_FREE -- Put a page on the freelist.  *  * Parameters:  *	t:	tree  *	h:	page to free  *  * Returns:  *	RET_ERROR, RET_SUCCESS  */
end_comment

begin_function
name|int
name|__bt_free
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|)
name|BTREE
modifier|*
name|t
decl_stmt|;
name|PAGE
modifier|*
name|h
decl_stmt|;
block|{
comment|/* Insert the page at the start of the free list. */
name|h
operator|->
name|prevpg
operator|=
name|P_INVALID
expr_stmt|;
name|h
operator|->
name|nextpg
operator|=
name|t
operator|->
name|bt_free
expr_stmt|;
name|t
operator|->
name|bt_free
operator|=
name|h
operator|->
name|pgno
expr_stmt|;
comment|/* Make sure the page gets written back. */
return|return
operator|(
name|mpool_put
argument_list|(
name|t
operator|->
name|bt_mp
argument_list|,
name|h
argument_list|,
name|MPOOL_DIRTY
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * __BT_NEW -- Get a new page, preferably from the freelist.  *  * Parameters:  *	t:	tree  *	npg:	storage for page number.  *  * Returns:  *	Pointer to a page, NULL on error.  */
end_comment

begin_function
name|PAGE
modifier|*
name|__bt_new
parameter_list|(
name|t
parameter_list|,
name|npg
parameter_list|)
name|BTREE
modifier|*
name|t
decl_stmt|;
name|pgno_t
modifier|*
name|npg
decl_stmt|;
block|{
name|PAGE
modifier|*
name|h
decl_stmt|;
if|if
condition|(
name|t
operator|->
name|bt_free
operator|!=
name|P_INVALID
operator|&&
operator|(
name|h
operator|=
name|mpool_get
argument_list|(
name|t
operator|->
name|bt_mp
argument_list|,
name|t
operator|->
name|bt_free
argument_list|,
literal|0
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
operator|*
name|npg
operator|=
name|t
operator|->
name|bt_free
expr_stmt|;
name|t
operator|->
name|bt_free
operator|=
name|h
operator|->
name|nextpg
expr_stmt|;
return|return
operator|(
name|h
operator|)
return|;
block|}
return|return
operator|(
name|mpool_new
argument_list|(
name|t
operator|->
name|bt_mp
argument_list|,
name|npg
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

