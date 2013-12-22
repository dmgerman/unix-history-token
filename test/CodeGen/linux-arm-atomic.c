begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=armv7-unknown-linux | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=armv6-unknown-linux | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=thumbv7-unknown-linux | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=armv6-unknown-freebsd | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=armv6-unknown-bitrig | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|int
name|_Atomic_word
typedef|;
end_typedef

begin_function
name|_Atomic_word
name|exchange_and_add
parameter_list|(
specifier|volatile
name|_Atomic_word
modifier|*
name|__mem
parameter_list|,
name|int
name|__val
parameter_list|)
block|{
return|return
name|__atomic_fetch_add
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|,
name|__ATOMIC_ACQ_REL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define {{.*}} @exchange_and_add
end_comment

begin_comment
comment|// CHECK: atomicrmw {{.*}} add
end_comment

end_unit

