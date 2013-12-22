begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR 1278
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | grep struct.s | not grep "4 x i8] zeroinitializer"
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | not grep "i32 0, i32 2"
end_comment

begin_struct
struct|struct
name|s
block|{
name|double
name|d1
decl_stmt|;
name|int
name|s1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|s
name|S
init|=
block|{
literal|1.1
block|,
literal|2
block|}
decl_stmt|;
return|return
name|S
return|;
block|}
end_function

end_unit

