begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XDeleteAssoc.c,v 10.4 86/02/01 15:31:59 tony Rel $ */
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
comment|/*  * XDeleteAssoc - Delete an association in an XAssocTable keyed on  * an XId.  An association may be removed only once.  Redundant  * deletes are meaningless (but cause no problems).  */
end_comment

begin_expr_stmt
name|XDeleteAssoc
argument_list|(
name|table
argument_list|,
name|x_id
argument_list|)
specifier|register
name|XAssocTable
operator|*
name|table
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|XId
name|x_id
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|hash
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
comment|/* Hash the XId to get the bucket number. */
name|hash
operator|=
name|x_id
operator|&
operator|(
name|table
operator|->
name|size
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* Look up the bucket to get the entries in that bucket. */
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
name|hash
index|]
expr_stmt|;
comment|/* Get the first entry in the bucket. */
name|entry
operator|=
name|bucket
operator|->
name|next
expr_stmt|;
comment|/* Scan through the entries in the bucket for the right XId. */
for|for
control|(
name|entry
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
if|if
condition|(
name|entry
operator|->
name|x_id
operator|==
name|x_id
condition|)
block|{
comment|/* We have the right XId. */
if|if
condition|(
name|entry
operator|->
name|display
operator|==
name|_XlibCurrentDisplay
condition|)
block|{
comment|/* We have the right display. */
comment|/* We have the right entry! */
comment|/* Remove it from the queue and */
comment|/* free the entry. */
name|remque
argument_list|(
name|entry
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|entry
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* Oops, identical XId's on different displays! */
continue|continue;
block|}
if|if
condition|(
name|entry
operator|->
name|x_id
operator|>
name|x_id
condition|)
block|{
comment|/* We have gone past where it should be. */
comment|/* It is apparently not in the table. */
return|return;
block|}
block|}
comment|/* It is apparently not in the table. */
return|return;
block|}
end_block

end_unit

