begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMakeAssoc.c,v 10.5 86/12/16 17:17:20 tony Exp $ */
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
comment|/*  * XMakeAssoc - Insert data into an XAssocTable keyed on an XId.  * Data is inserted into the table only once.  Redundant inserts are  * meaningless (but cause no problems).  The queue in each association  * bucket is sorted (lowest XId to highest XId).  */
end_comment

begin_expr_stmt
name|XMakeAssoc
argument_list|(
name|table
argument_list|,
name|x_id
argument_list|,
name|data
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

begin_decl_stmt
specifier|register
name|caddr_t
name|data
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
specifier|register
name|XAssoc
modifier|*
name|new_entry
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
name|table
operator|->
name|buckets
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
comment|/* If (entry != bucket), the bucket is empty so make */
comment|/* the new entry the first entry in the bucket. */
comment|/* if (entry == bucket), the we have to search the */
comment|/* bucket. */
if|if
condition|(
name|entry
operator|!=
name|bucket
condition|)
block|{
comment|/* The bucket isn't empty, begin searching. */
comment|/* If we leave the for loop then we have either passed */
comment|/* where the entry should be or hit the end of the bucket. */
comment|/* In either case we should then insert the new entry */
comment|/* before the current value of "entry". */
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
comment|/* Entry has the same XId... */
if|if
condition|(
name|entry
operator|->
name|display
operator|==
name|_XlibCurrentDisplay
condition|)
block|{
comment|/* Entry has the same Display... */
comment|/* Therefore there is already an */
comment|/* entry with this XId and Display, */
comment|/* reset its data value and return. */
name|entry
operator|->
name|data
operator|=
name|data
expr_stmt|;
return|return;
block|}
comment|/* We found an association with the right */
comment|/* id but the wrong display! */
continue|continue;
block|}
comment|/* If the current entry's XId is greater than the */
comment|/* XId of the entry to be inserted then we have */
comment|/* passed the location where the new XId should */
comment|/* be inserted. */
if|if
condition|(
name|entry
operator|->
name|x_id
operator|>
name|x_id
condition|)
break|break;
block|}
block|}
comment|/* If we are here then the new entry should be inserted just */
comment|/* before the current value of "entry". */
comment|/* Create a new XAssoc and load it with new provided data. */
name|new_entry
operator|=
operator|(
name|XAssoc
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|XAssoc
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|new_entry
operator|==
name|NULL
condition|)
block|{
comment|/* Malloc failed! */
name|errno
operator|=
name|ENOMEM
expr_stmt|;
name|_XIOError
argument_list|(
name|_XlibCurrentDisplay
argument_list|)
expr_stmt|;
block|}
name|new_entry
operator|->
name|display
operator|=
name|_XlibCurrentDisplay
expr_stmt|;
name|new_entry
operator|->
name|x_id
operator|=
name|x_id
expr_stmt|;
name|new_entry
operator|->
name|data
operator|=
name|data
expr_stmt|;
comment|/* Insert the new entry. */
name|insque
argument_list|(
name|new_entry
argument_list|,
name|entry
operator|->
name|prev
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

