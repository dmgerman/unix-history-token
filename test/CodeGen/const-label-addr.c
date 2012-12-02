begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: asserts
end_comment

begin_comment
comment|// CHECK: @a.a = internal global i8* blockaddress(@a, %A)
end_comment

begin_function
name|int
name|a
parameter_list|()
block|{
name|A
label|:
empty_stmt|;
specifier|static
name|void
modifier|*
name|a
init|=
operator|&&
name|A
decl_stmt|;
block|}
end_function

begin_comment
comment|// PR14005
end_comment

begin_comment
comment|// CHECK: @b.ar = internal global {{.*}} sub (i{{..}} ptrtoint (i8* blockaddress(@b, %l2) to i{{..}}), i{{..}} ptrtoint (i8* blockaddress(@b, %l1) to i{{..}}))
end_comment

begin_function
name|int
name|b
parameter_list|()
block|{
specifier|static
name|int
name|ar
init|=
operator|&&
name|l2
operator|-
operator|&&
name|l1
decl_stmt|;
name|l1
label|:
return|return
literal|10
return|;
name|l2
label|:
return|return
literal|11
return|;
block|}
end_function

end_unit

