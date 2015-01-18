begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -pic-level 2 %s -o - | FileCheck %s -check-prefix=CHECK-BIGPIC
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -pic-level 1 %s -o - | FileCheck %s -check-prefix=CHECK-SMALLPIC
end_comment

begin_comment
comment|// CHECK-BIGPIC: !llvm.module.flags = !{{{.*}}}
end_comment

begin_comment
comment|// CHECK-BIGPIC: !{{[0-9]+}} = !{i32 1, !"PIC Level", i32 2}
end_comment

begin_comment
comment|// CHECK-SMALLPIC: !llvm.module.flags = !{{{.*}}}
end_comment

begin_comment
comment|// CHECK-SMALLPIC: !{{[0-9]+}} = !{i32 1, !"PIC Level", i32 1}
end_comment

end_unit

