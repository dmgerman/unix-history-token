begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=armv7-none-eabi< %s -S -emit-llvm | FileCheck %s
end_comment

begin_struct
struct|struct
name|foo
block|{
name|long
name|long
name|a
decl_stmt|;
name|char
name|b
decl_stmt|;
name|int
name|c
range|:
literal|16
decl_stmt|;
name|int
name|d
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: %struct.foo* byval align 8 %z
end_comment

begin_function
name|long
name|long
name|bar
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|d
parameter_list|,
name|int
name|e
parameter_list|,
name|struct
name|foo
name|z
parameter_list|)
block|{
return|return
name|z
operator|.
name|a
return|;
block|}
end_function

end_unit

