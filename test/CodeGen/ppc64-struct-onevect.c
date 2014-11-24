begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|float
name|v4sf
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_struct
struct|struct
name|s
block|{
name|v4sf
name|v
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|v4sf
name|foo
parameter_list|(
name|struct
name|s
name|a
parameter_list|)
block|{
return|return
name|a
operator|.
name|v
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @foo(<4 x float> inreg %a.coerce)
end_comment

begin_comment
comment|// CHECK: ret<4 x float> %a.coerce
end_comment

end_unit

