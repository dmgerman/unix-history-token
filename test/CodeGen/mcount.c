begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pg -triple i386-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple i386-unknown-unknown -emit-llvm -O2 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc-unknown-gnu-linux -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc64-unknown-gnu-linux -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc64le-unknown-gnu-linux -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple i386-netbsd -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple x86_64-netbsd -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple arm-netbsd-eabi -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple aarch64-netbsd -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple mips-netbsd -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc-netbsd -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc64-netbsd -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc64le-netbsd -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple sparc-netbsd -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple sparc64-netbsd -emit-llvm -o - %s | FileCheck -check-prefixes=CHECK-PREFIXED,NO-MCOUNT1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s -check-prefix=NO-MCOUNT
end_comment

begin_function
name|int
name|bar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|bar
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|no_instrument_function
operator|)
argument_list|)
name|no_instrument
argument_list|(
name|void
argument_list|)
block|{
return|return
name|foo
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|no_instrument
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// CHECK: attributes #0 = { {{.*}}"counting-function"="mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes #1 = { {{.*}} }
end_comment

begin_comment
comment|// CHECK-PREFIXED: attributes #0 = { {{.*}}"counting-function"="_mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-PREFIXED: attributes #1 = { {{.*}} }
end_comment

begin_comment
comment|// NO-MCOUNT-NOT: attributes #{{[0-9]}} = { {{.*}}"counting-function"={{.*}} }
end_comment

begin_comment
comment|// NO-MCOUNT1-NOT: attributes #1 = { {{.*}}"counting-function"={{.*}} }
end_comment

end_unit

