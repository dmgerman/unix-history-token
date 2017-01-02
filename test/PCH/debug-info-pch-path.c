begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: cd %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|// Relative PCH, same directory.
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-format=obj -emit-pch                \
end_comment

begin_comment
comment|// RUN:     -triple %itanium_abi_triple                         \
end_comment

begin_comment
comment|// RUN:     -o prefix.pch %S/debug-info-limited-struct.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=standalone                  \
end_comment

begin_comment
comment|// RUN:     -dwarf-ext-refs -fmodule-format=obj                 \
end_comment

begin_comment
comment|// RUN:     -triple %itanium_abi_triple                         \
end_comment

begin_comment
comment|// RUN:     -include-pch prefix.pch %s -emit-llvm -o %t.nodir.ll %s
end_comment

begin_comment
comment|// RUN: cat %t.nodir.ll | FileCheck %s --check-prefix=CHECK-REL-NODIR
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-REL-NODIR: !DICompileUnit
end_comment

begin_comment
comment|// CHECK-REL-NODIR-SAME:           file: ![[C:[0-9]+]]
end_comment

begin_comment
comment|// CHECK-REL-NODIR-NOT: dwoId
end_comment

begin_comment
comment|// CHECK-REL-NODIR: ![[C]] = !DIFile({{.*}}directory: "[[DIR:.*]]"
end_comment

begin_comment
comment|// CHECK-REL-NODIR: !DICompileUnit(
end_comment

begin_comment
comment|// CHECK-REL-NODIR-SAME:           file: ![[PCH:[0-9]+]]
end_comment

begin_comment
comment|// CHECK-REL-NODIR-SAME:           splitDebugFilename: "prefix.pch"
end_comment

begin_comment
comment|// CHECK-REL-NODIR: ![[PCH]] = !DIFile({{.*}}directory: "[[DIR]]"
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|// Relative PCH in a subdirectory.
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: mkdir pchdir
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-format=obj -emit-pch                \
end_comment

begin_comment
comment|// RUN:     -triple %itanium_abi_triple                         \
end_comment

begin_comment
comment|// RUN:     -o pchdir/prefix.pch %S/debug-info-limited-struct.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=standalone                  \
end_comment

begin_comment
comment|// RUN:     -dwarf-ext-refs -fmodule-format=obj                 \
end_comment

begin_comment
comment|// RUN:     -triple %itanium_abi_triple                         \
end_comment

begin_comment
comment|// RUN:     -include-pch pchdir/prefix.pch %s -emit-llvm -o %t.rel.ll %s
end_comment

begin_comment
comment|// RUN: cat %t.rel.ll | FileCheck %s --check-prefix=CHECK-REL
end_comment

begin_comment
comment|// CHECK-REL: !DICompileUnit
end_comment

begin_comment
comment|// CHECK-REL-SAME:           file: ![[C:[0-9]+]]
end_comment

begin_comment
comment|// CHECK-REL-NOT: dwoId
end_comment

begin_comment
comment|// CHECK-REL: ![[C]] = !DIFile({{.*}}directory: "[[DIR:.*]]"
end_comment

begin_comment
comment|// CHECK-REL: !DICompileUnit(
end_comment

begin_comment
comment|// CHECK-REL-SAME:           file: ![[PCH:[0-9]+]]
end_comment

begin_comment
comment|// CHECK-REL-SAME:           splitDebugFilename: "prefix.pch"
end_comment

begin_comment
comment|// CHECK-REL: ![[PCH]] = !DIFile({{.*}}directory: "[[DIR]]{{.*}}pchdir"
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|// Absolute PCH.
end_comment

begin_comment
comment|// ---------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-format=obj -emit-pch                \
end_comment

begin_comment
comment|// RUN:     -triple %itanium_abi_triple                         \
end_comment

begin_comment
comment|// RUN:     -o %t/prefix.pch %S/debug-info-limited-struct.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=standalone                  \
end_comment

begin_comment
comment|// RUN:     -dwarf-ext-refs -fmodule-format=obj                 \
end_comment

begin_comment
comment|// RUN:     -triple %itanium_abi_triple                         \
end_comment

begin_comment
comment|// RUN:     -include-pch %t/prefix.pch %s -emit-llvm -o %t.abs.ll %s
end_comment

begin_comment
comment|// RUN: cat %t.abs.ll | FileCheck %s --check-prefix=CHECK-ABS
end_comment

begin_comment
comment|// CHECK-ABS: !DICompileUnit
end_comment

begin_comment
comment|// CHECK-ABS-SAME:           file: ![[C:[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ABS-NOT: dwoId
end_comment

begin_comment
comment|// CHECK-ABS: ![[C]] = !DIFile({{.*}}directory: "[[DIR:.*]]"
end_comment

begin_comment
comment|// CHECK-ABS: !DICompileUnit(
end_comment

begin_comment
comment|// CHECK-ABS-SAME:           file: ![[PCH:[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ABS-SAME:           splitDebugFilename: "prefix.pch"
end_comment

begin_comment
comment|// CHECK-ABS: ![[PCH]] = !DIFile({{.*}}directory: "[[DIR]]"
end_comment

end_unit

