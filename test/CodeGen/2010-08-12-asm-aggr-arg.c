begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Radar 8288710: A small aggregate can be passed as an integer.  Make sure
end_comment

begin_comment
comment|// we don't get an error with "input constraint with a matching output
end_comment

begin_comment
comment|// constraint of incompatible type!"
end_comment

begin_struct
struct|struct
name|wrapper
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: xyz
end_comment

begin_function
name|int
name|test
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|struct
name|wrapper
name|w
decl_stmt|;
name|w
operator|.
name|i
operator|=
name|i
expr_stmt|;
asm|__asm__("xyz" : "=r" (w) : "0" (w));
return|return
name|w
operator|.
name|i
return|;
block|}
end_function

end_unit

