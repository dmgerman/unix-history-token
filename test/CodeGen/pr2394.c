begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-apple-darwin10 -emit-llvm -o - | FileCheck %s
end_comment

begin_struct
struct|struct
name|__attribute
argument_list|(
argument|(packed)
argument_list|)
name|x
block|{
name|int
name|a
range|:
literal|24
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|a
parameter_list|(
name|struct
name|x
modifier|*
name|g
parameter_list|)
block|{
comment|// CHECK: load i24
return|return
name|g
operator|->
name|a
return|;
block|}
end_function

end_unit

