begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * slsrewind() resets the current key pointer to the first key in list  * slslist.  */
end_comment

begin_include
include|#
directive|include
file|"slslist.h"
end_include

begin_function
name|void
name|slsrewind
parameter_list|(
name|slslist
parameter_list|)
name|SLSLIST
modifier|*
name|slslist
decl_stmt|;
comment|/* pointer to list head block */
block|{
name|slslist
operator|->
name|curblk
operator|=
name|slslist
operator|->
name|head
expr_stmt|;
block|}
end_function

end_unit

