begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_function
name|int
name|f
parameter_list|()
block|{
specifier|extern
name|int
name|a
decl_stmt|;
return|return
name|a
return|;
block|}
end_function

end_unit

