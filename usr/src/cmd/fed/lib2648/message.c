begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * message: print str on the screen in the message area.  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|message
argument_list|(
argument|str
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|dispmsg
argument_list|(
name|str
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
literal|100
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

