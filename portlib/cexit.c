begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"iodec.h"
end_include

begin_comment
comment|/**  **	flush and close all files and exit  **/
end_comment

begin_macro
name|cexit
argument_list|(
argument|rcode
argument_list|)
end_macro

begin_block
block|{
name|flush
argument_list|()
expr_stmt|;
name|__exit
argument_list|(
name|rcode
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|exit
argument_list|(
argument|rcode
argument_list|)
end_macro

begin_block
block|{
name|cexit
argument_list|(
name|rcode
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

