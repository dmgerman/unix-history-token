begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s --linker-option=/include:foo -triple i686-pc-win32 -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: !llvm.module.flags = !{{{.*}}}
end_comment

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32 6, !"Linker Options", ![[link_opts:[0-9]+]]}
end_comment

begin_comment
comment|// CHECK: ![[link_opts]] = !{![[msvcrt:[0-9]+]]}
end_comment

begin_comment
comment|// CHECK: ![[msvcrt]] = !{!"/include:foo"}
end_comment

begin_function_decl
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

end_unit

