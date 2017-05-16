begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodule-format=obj -debug-info-kind=limited -dwarf-ext-refs \
end_comment

begin_comment
comment|// RUN:     -fimplicit-module-maps -x c -fmodules-cache-path=%t -I %S/Inputs \
end_comment

begin_comment
comment|// RUN:     %s -emit-llvm -debugger-tuning=lldb -o - | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodule-format=obj -debug-info-kind=limited -dwarf-ext-refs \
end_comment

begin_comment
comment|// RUN:     -fimplicit-module-maps -x c -fmodules-cache-path=%t -I %S/Inputs \
end_comment

begin_comment
comment|// RUN:     -fmodules-local-submodule-visibility \
end_comment

begin_comment
comment|// RUN:     %s -emit-llvm -debugger-tuning=lldb -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"DebugSubmoduleA.h"
end_include

begin_include
include|#
directive|include
file|"DebugSubmoduleB.h"
end_include

begin_comment
comment|// CHECK: !DICompileUnit
end_comment

begin_comment
comment|// CHECK-NOT: !DICompileUnit
end_comment

begin_comment
comment|// CHECK: !DIModule(scope: ![[PARENT:.*]], name: "DebugSubmoduleA"
end_comment

begin_comment
comment|// CHECK: [[PARENT]] = !DIModule(scope: null, name: "DebugSubmodules"
end_comment

begin_comment
comment|// CHECK: !DIModule(scope: ![[PARENT]], name: "DebugSubmoduleB"
end_comment

begin_comment
comment|// CHECK: !DICompileUnit({{.*}}splitDebugFilename: {{.*}}DebugSubmodules
end_comment

begin_comment
comment|// CHECK-SAME:                 dwoId:
end_comment

begin_comment
comment|// CHECK-NOT: !DICompileUnit
end_comment

end_unit

