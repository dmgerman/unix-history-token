begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|void
name|clang_analyzer_warnIfReached
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|class
name|PlistCheckMacro
block|{
name|public
label|:
name|PlistCheckMacro
argument_list|()
block|{ }
name|void
name|run
parameter_list|()
block|{
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

