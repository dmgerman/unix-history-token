begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* Dummy routines to handle calls used in Stifplot */
end_comment

begin_macro
name|StifCall
argument_list|()
end_macro

begin_block
block|{
name|Error
argument_list|(
literal|"StifCall called in CIFPLOT"
argument_list|,
name|INTERNAL
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|FreeStif
argument_list|()
end_macro

begin_block
block|{
name|Error
argument_list|(
literal|"FreeStif called in CIFPLOT"
argument_list|,
name|INTERNAL
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

