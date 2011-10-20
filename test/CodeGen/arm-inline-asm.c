begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin9 -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|t1
parameter_list|(
name|void
modifier|*
name|f
parameter_list|,
name|int
name|g
parameter_list|)
block|{
comment|// CHECK: call void asm "str $1, $0", "=*Q,r"
asm|asm("str %1, %0" : "=Q"(f) : "r"(g));
block|}
end_function

end_unit

