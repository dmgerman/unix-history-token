begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o - | grep "i32 @a(i32)"
end_comment

begin_function_decl
name|int
name|a
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|a
parameter_list|(
name|x
parameter_list|)
name|short
name|x
decl_stmt|;
block|{
return|return
name|x
return|;
block|}
end_function

end_unit

