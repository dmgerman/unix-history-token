begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"hangman.h"
end_include

begin_comment
comment|/*  * prword:  *	Print out the current state of the word  */
end_comment

begin_macro
name|prword
argument_list|()
end_macro

begin_block
block|{
name|move
argument_list|(
name|KNOWNY
argument_list|,
name|KNOWNX
operator|+
sizeof|sizeof
expr|"Word: "
argument_list|)
expr_stmt|;
name|addstr
argument_list|(
name|Known
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

