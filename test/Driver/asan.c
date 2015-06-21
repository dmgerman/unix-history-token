begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang     -target i386-unknown-linux -fsanitize=address %s -S -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-ASAN
end_comment

begin_comment
comment|// RUN: %clang -O1 -target i386-unknown-linux -fsanitize=address %s -S -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-ASAN
end_comment

begin_comment
comment|// RUN: %clang -O2 -target i386-unknown-linux -fsanitize=address %s -S -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-ASAN
end_comment

begin_comment
comment|// RUN: %clang -O3 -target i386-unknown-linux -fsanitize=address %s -S -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-ASAN
end_comment

begin_comment
comment|// RUN: %clang     -target i386-unknown-linux -fsanitize=kernel-address %s -S -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-KASAN
end_comment

begin_comment
comment|// RUN: %clang -O1 -target i386-unknown-linux -fsanitize=kernel-address %s -S -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-KASAN
end_comment

begin_comment
comment|// RUN: %clang -O2 -target i386-unknown-linux -fsanitize=kernel-address %s -S -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-KASAN
end_comment

begin_comment
comment|// RUN: %clang -O3 -target i386-unknown-linux -fsanitize=kernel-address %s -S -emit-llvm -o - | FileCheck %s --check-prefix=CHECK-KASAN
end_comment

begin_comment
comment|// Verify that -fsanitize={address,kernel-address} invoke ASan and KASan instrumentation.
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
comment|// CHECK-ASAN: __asan_init
end_comment

begin_comment
comment|// CHECK-KASAN: __asan_load4_noabort
end_comment

end_unit

