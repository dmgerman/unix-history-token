begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XLookUpAssoc.c,v 10.4 86/02/01 15:36:21 tony Rel $ */
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
comment|/*   * XLookUpAssoc - Retrieve the data stored in an XAssocTable by its XId.  * If an appropriately matching XId can be found in the table the routine will  * return apointer to the data associated with it. If the XId can not be found  * in the table the routine will return a NULL pointer.  All XId's are relative  * to the currently active Display.  */
end_comment

begin_function
name|caddr_t
name|XLookUpAssoc
parameter_list|(
name|table
parameter_list|,
name|x_id
parameter_list|)
specifier|register
name|XAssocTable
modifier|*
name|table
decl_stmt|;
comment|/* XAssocTable to search in. */
specifier|register
name|XId
name|x_id
decl_stmt|;
comment|/* XId to search for. */
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
return|return
operator|(
name|entry
operator|->
name|data
operator|)
return|;
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
return|return
operator|(
name|NULL
operator|)
return|;
block|}
block|}
comment|/* It is apparently not in the table. */
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

