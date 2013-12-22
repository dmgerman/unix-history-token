begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -O1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f0()
end_comment

begin_comment
comment|// CHECK:   ret i32 0
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f1()
end_comment

begin_comment
comment|// CHECK:   ret i32 0
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f2()
end_comment

begin_comment
comment|// CHECK:   ret i32 0
end_comment

begin_comment
comment|//<rdar://problem/6113085>
end_comment

begin_struct
struct|struct
name|s0
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|f0
parameter_list|()
block|{
name|struct
name|s0
name|x
init|=
block|{
literal|0
block|}
decl_stmt|;
return|return
name|x
operator|.
name|y
return|;
block|}
end_function

begin_function
name|int
name|f1
parameter_list|()
block|{
name|struct
name|s0
name|x
index|[
literal|2
index|]
init|=
block|{
block|{
literal|0
block|}
block|}
decl_stmt|;
return|return
name|x
index|[
literal|1
index|]
operator|.
name|x
return|;
block|}
end_function

begin_function
name|int
name|f2
parameter_list|()
block|{
name|int
name|x
index|[
literal|2
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
return|return
name|x
index|[
literal|1
index|]
return|;
block|}
end_function

end_unit

