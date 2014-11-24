begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | grep sret | count 2
end_comment

begin_struct
struct|struct
name|abc
block|{
name|long
name|a
decl_stmt|;
name|long
name|b
decl_stmt|;
name|long
name|c
decl_stmt|;
name|long
name|d
decl_stmt|;
name|long
name|e
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|abc
name|foo2
parameter_list|()
block|{}
end_function

end_unit

