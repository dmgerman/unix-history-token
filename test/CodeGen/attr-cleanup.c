begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t
end_comment

begin_comment
comment|//<rdar://problem/6827047>
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|g
parameter_list|()
block|{
name|__attribute__
argument_list|(
argument|(cleanup(f))
argument_list|)
name|void
modifier|*
name|g
decl_stmt|;
block|}
end_function

end_unit

