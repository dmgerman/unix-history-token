begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core %s
end_comment

begin_comment
comment|// PR12905
end_comment

begin_function_decl
name|void
name|C
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|t
parameter_list|(
name|void
parameter_list|)
block|{
name|C
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

