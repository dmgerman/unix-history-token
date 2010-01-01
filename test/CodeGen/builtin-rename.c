begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | grep 'declare.*printf' | count 1
end_comment

begin_comment
comment|// PR3612
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|printf
argument_list|(
name|printf
argument_list|)
return|;
block|}
end_function

end_unit

