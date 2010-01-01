begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -ffreestanding %s
end_comment

begin_comment
comment|// Tests that -ffreestanding disables all special treatment of main().
end_comment

begin_function_decl
name|void
modifier|*
name|allocate
parameter_list|(
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
modifier|*
name|main
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|long
name|size
parameter_list|)
block|{
if|if
condition|(
name|context
condition|)
return|return
name|allocate
argument_list|(
name|size
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// expected-warning {{control may reach end of non-void function}}
end_comment

end_unit

