begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o - | grep {private constant }
end_comment

begin_comment
comment|// The synthetic global made by the CFE for big initializer should be marked
end_comment

begin_comment
comment|// constant.
end_comment

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|char
name|Blah
index|[]
init|=
literal|"asdlfkajsdlfkajsd;lfkajds;lfkjasd;flkajsd;lkfja;sdlkfjasd"
decl_stmt|;
name|bar
argument_list|(
name|Blah
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

