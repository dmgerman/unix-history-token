begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * slrewind() resets the current key pointer to the first key in list  * slist.  */
end_comment

begin_include
include|#
directive|include
file|"slist.h"
end_include

begin_function
name|void
name|slrewind
parameter_list|(
name|slist
parameter_list|)
name|SLIST
modifier|*
name|slist
decl_stmt|;
comment|/* pointer to list head block */
block|{
name|slist
operator|->
name|curblk
operator|=
name|slist
operator|->
name|head
expr_stmt|;
block|}
end_function

end_unit

