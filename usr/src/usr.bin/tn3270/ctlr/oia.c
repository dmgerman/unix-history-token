begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Routines to maintain the Operator Information Area.  */
end_comment

begin_include
include|#
directive|include
file|"../general/general.h"
end_include

begin_include
include|#
directive|include
file|"oia.h"
end_include

begin_include
include|#
directive|include
file|"../general/globals.h"
end_include

begin_macro
name|init_oia
argument_list|()
end_macro

begin_block
block|{
name|ClearElement
argument_list|(
name|OperatorInformationArea
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

