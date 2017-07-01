begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=full -O0 %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-FULL-O0
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=thin -O0 %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-THIN-O0
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=full -O1 %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-FULL-OPTIMIZED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=thin -O1 %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-THIN-OPTIMIZED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=full -O2 %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-FULL-OPTIMIZED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=thin -O2 %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-THIN-OPTIMIZED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=full -O3 %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-FULL-OPTIMIZED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=thin -O3 %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-THIN-OPTIMIZED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=full -Os %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-FULL-OPTIMIZED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=thin -Os %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-THIN-OPTIMIZED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=full -Oz %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-FULL-OPTIMIZED
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm-bc -o /dev/null -fexperimental-new-pass-manager -fdebug-pass-manager -flto=thin -Oz %s 2>&1 | FileCheck %s \
end_comment

begin_comment
comment|// RUN:   -check-prefix=CHECK-THIN-OPTIMIZED
end_comment

begin_comment
comment|// CHECK-FULL-O0: Starting llvm::Module pass manager run.
end_comment

begin_comment
comment|// CHECK-FULL-O0: Running pass: AlwaysInlinerPass
end_comment

begin_comment
comment|// CHECK-FULL-O0-NEXT: Running pass: BitcodeWriterPass
end_comment

begin_comment
comment|// CHECK-FULL-O0: Finished llvm::Module pass manager run.
end_comment

begin_comment
comment|// CHECK-THIN-O0: Starting llvm::Module pass manager run.
end_comment

begin_comment
comment|// CHECK-THIN-O0: Running pass: AlwaysInlinerPass
end_comment

begin_comment
comment|// CHECK-THIN-O0-NEXT: Running pass: NameAnonGlobalPass
end_comment

begin_comment
comment|// CHECK-THIN-O0-NEXT: Running pass: ThinLTOBitcodeWriterPass
end_comment

begin_comment
comment|// CHECK-THIN-O0: Finished llvm::Module pass manager run.
end_comment

begin_comment
comment|// TODO: The LTO pre-link pipeline currently invokes
end_comment

begin_comment
comment|//       buildPerModuleDefaultPipeline(), which contains LoopVectorizePass.
end_comment

begin_comment
comment|//       This may change as the pipeline gets implemented.
end_comment

begin_comment
comment|// CHECK-FULL-OPTIMIZED: Starting llvm::Function pass manager run.
end_comment

begin_comment
comment|// CHECK-FULL-OPTIMIZED: Running pass: LoopVectorizePass
end_comment

begin_comment
comment|// CHECK-FULL-OPTIMIZED: Running pass: BitcodeWriterPass
end_comment

begin_comment
comment|// The ThinLTO pre-link pipeline shouldn't contain passes like
end_comment

begin_comment
comment|// LoopVectorizePass.
end_comment

begin_comment
comment|// CHECK-THIN-OPTIMIZED: Starting llvm::Function pass manager run.
end_comment

begin_comment
comment|// CHECK-THIN-OPTIMIZED-NOT: Running pass: LoopVectorizePass
end_comment

begin_comment
comment|// CHECK-THIN-OPTIMIZED: Running pass: NameAnonGlobalPass
end_comment

begin_comment
comment|// CHECK-THIN-OPTIMIZED: Running pass: ThinLTOBitcodeWriterPass
end_comment

begin_function
name|void
name|Foo
parameter_list|()
block|{}
end_function

end_unit

