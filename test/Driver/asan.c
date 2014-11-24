begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang     -target i386-unknown-unknown -fsanitize=address %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -O1 -target i386-unknown-unknown -fsanitize=address %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -O2 -target i386-unknown-unknown -fsanitize=address %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -O3 -target i386-unknown-unknown -fsanitize=address %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Verify that -fsanitize=address invokes asan instrumentation.
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
return|return
operator|*
name|a
return|;
block|}
end_function

begin_comment
comment|// CHECK: __asan_init
end_comment

end_unit

