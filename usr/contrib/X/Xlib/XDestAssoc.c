begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XDestAssoc.c,v 10.4 86/02/01 15:32:05 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_comment
comment|/*  * XDestroyAssocTable - Destroy (free the memory associated with)  * an XAssocTable.    */
end_comment

begin_expr_stmt
name|XDestroyAssocTable
argument_list|(
name|table
argument_list|)
specifier|register
name|XAssocTable
operator|*
name|table
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|XAssoc
modifier|*
name|bucket
decl_stmt|;
specifier|register
name|XAssoc
modifier|*
name|entry
decl_stmt|;
comment|/* Free the buckets. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|table
operator|->
name|size
condition|;
name|i
operator|++
control|)
block|{
name|bucket
operator|=
operator|&
operator|(
operator|*
name|table
operator|->
name|table
operator|)
index|[
name|i
index|]
expr_stmt|;
for|for
control|(
name|entry
operator|=
name|bucket
operator|->
name|next
init|;
name|entry
operator|!=
name|bucket
condition|;
name|entry
operator|=
name|entry
operator|->
name|next
control|)
block|{
name|free
argument_list|(
name|entry
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Free the bucket headers. */
name|free
argument_list|(
name|table
operator|->
name|table
argument_list|)
expr_stmt|;
comment|/* Free the table. */
name|free
argument_list|(
name|table
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

