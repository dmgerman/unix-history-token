begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|Point
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
name|float
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test
parameter_list|(
name|struct
name|Point
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
comment|// RUN: %clang_cc1 -fsyntax-only -code-completion-at=%s:8:6 %s -o - | FileCheck -check-prefix=CHECK-CC1 %s
comment|// CHECK-CC1: x
comment|// CHECK-CC1: y
comment|// CHECK-CC1: z
end_function

end_unit

