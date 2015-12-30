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
comment|// RUN:     %s -mllvm -debug-only=pchcontainer -emit-llvm -o %t.ll \
end_comment

begin_comment
comment|// RUN:     2>&1 | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: asserts
end_comment

begin_include
include|#
directive|include
file|"DebugSubmoduleA.h"
end_include

begin_comment
comment|// CHECK: !DICompositeType(tag: DW_TAG_structure_type, name: "A",
end_comment

begin_comment
comment|// CHECK-SAME:             scope: ![[SUBMODULEA:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: ![[SUBMODULEA]] = !DIModule(scope: ![[PARENT:[0-9]+]],
end_comment

begin_comment
comment|// CHECK-SAME:                        name: "DebugSubmoduleA",
end_comment

begin_comment
comment|// CHECK: ![[PARENT]] = !DIModule(scope: null, name: "DebugSubmodules"
end_comment

begin_comment
comment|// CHECK: !DICompositeType(tag: DW_TAG_structure_type, name: "B",
end_comment

begin_comment
comment|// CHECK-SAME:             scope: ![[SUBMODULEB:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: ![[SUBMODULEB]] = !DIModule(scope: ![[PARENT]],
end_comment

begin_comment
comment|// CHECK-SAME:                        name: "DebugSubmoduleB",
end_comment

end_unit

