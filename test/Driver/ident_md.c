begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -emit-llvm -S -o - | FileCheck %s
end_comment

begin_comment
comment|// Verify that clang version appears in the llvm.ident metadata.
end_comment

begin_comment
comment|// CHECK: !llvm.ident = !{{{.*}}}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = metadata !{metadata !{{.*}}
end_comment

end_unit

