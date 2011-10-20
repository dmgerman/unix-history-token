begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s  -o /dev/null
end_comment

begin_function
name|char
modifier|*
name|foo
parameter_list|()
block|{
return|return
literal|"\\begin{"
return|;
block|}
end_function

end_unit

