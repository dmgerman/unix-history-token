begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=line-tables-only -debug-info-macro %s -o - "-DC1(x)=( x  + 5 )" -DA -include %S/Inputs/debug-info-macro.h -UC1 | FileCheck -check-prefixes=CHECK,NO_PCH %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=limited          -debug-info-macro %s -o - "-DC1(x)=( x  + 5 )" -DA -include %S/Inputs/debug-info-macro.h -UC1 | FileCheck -check-prefixes=CHECK,NO_PCH %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=standalone       -debug-info-macro %s -o - "-DC1(x)=( x  + 5 )" -DA -include %S/Inputs/debug-info-macro.h -UC1 | FileCheck -check-prefixes=CHECK,NO_PCH %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm                                   -debug-info-macro %s -o - "-DC1(x)=( x  + 5 )" -DA -include %S/Inputs/debug-info-macro.h -UC1 | FileCheck -check-prefixes=NO_MACRO %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=limited -debug-info-macro %S/Inputs/debug-info-macro.h -emit-pch -o %t.pch -DC3
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=limited -debug-info-macro %s -o - -include-pch %t.pch "-DC1(x)=( x  + 5 )" -DA -include %S/Inputs/debug-info-macro.h -UC1 | FileCheck -check-prefixes=CHECK,PCH %s
end_comment

begin_comment
comment|// This test checks that macro Debug info is correctly generated.
end_comment

begin_comment
comment|// TODO: Check for an following entry once support macros defined in pch files.
end_comment

begin_comment
comment|// -PCH: !DIMacro(type: DW_MACINFO_define, name: "C3", value: "1")>
end_comment

begin_line
line|#
directive|line
number|15
end_line

begin_comment
comment|/*Line 15*/
end_comment

begin_define
define|#
directive|define
name|D1
value|1
end_define

begin_comment
comment|/*Line 16*/
end_comment

begin_include
include|#
directive|include
file|"Inputs/debug-info-macro.h"
end_include

begin_comment
comment|/*Line 17*/
end_comment

begin_undef
undef|#
directive|undef
name|D1
end_undef

begin_comment
comment|/*Line 18*/
end_comment

begin_define
define|#
directive|define
name|D2
value|2
end_define

begin_comment
comment|/*Line 19*/
end_comment

begin_include
include|#
directive|include
file|"Inputs/debug-info-macro.h"
end_include

begin_comment
comment|/*Line 20*/
end_comment

begin_undef
undef|#
directive|undef
name|D2
end_undef

begin_comment
comment|// NO_MACRO-NOT: macros
end_comment

begin_comment
comment|// NO_MACRO-NOT: DIMacro
end_comment

begin_comment
comment|// NO_MACRO-NOT: DIMacroFile
end_comment

begin_comment
comment|// CHECK:  !DICompileUnit({{.*}} macros: [[Macros:![0-9]+]])
end_comment

begin_comment
comment|// CHECK:  [[EmptyMD:![0-9]+]] = !{}
end_comment

begin_comment
comment|// NO_PCH: [[Macros]] = !{[[MainMacroFile:![0-9]+]], [[BuiltinMacro:![0-9]+]], {{.*}}, [[DefineC1:![0-9]+]], [[DefineA:![0-9]+]], [[UndefC1:![0-9]+]]}
end_comment

begin_comment
comment|// PCH:    [[Macros]] = !{[[MainMacroFile:![0-9]+]], [[DefineC1:![0-9]+]], [[DefineA:![0-9]+]], [[UndefC1:![0-9]+]]}
end_comment

begin_comment
comment|// CHECK:  [[MainMacroFile]] = !DIMacroFile(file: [[MainFile:![0-9]+]], nodes: [[N1:![0-9]+]])
end_comment

begin_comment
comment|// CHECK:  [[MainFile]] = !DIFile(filename: "{{.*}}debug-info-macro.c"
end_comment

begin_comment
comment|// CHECK:  [[N1]] = !{[[CommandLineInclude:![0-9]+]], [[DefineD1:![0-9]+]], [[FileInclude1:![0-9]+]], [[UndefD1:![0-9]+]], [[DefineD2:![0-9]+]], [[FileInclude2:![0-9]+]], [[UndefD2:![0-9]+]]}
end_comment

begin_comment
comment|// CHECK:  [[CommandLineInclude]] = !DIMacroFile(file: [[HeaderFile:![0-9]+]], nodes: [[N2:![0-9]+]])
end_comment

begin_comment
comment|// CHECK:  [[HeaderFile]] = !DIFile(filename: "{{.*}}debug-info-macro.h"
end_comment

begin_comment
comment|// CHECK:  [[N2]] = !{[[UndefA:![0-9]+]]}
end_comment

begin_comment
comment|// CHECK:  [[UndefA]] = !DIMacro(type: DW_MACINFO_undef, line: 11, name: "A")
end_comment

begin_comment
comment|// CHECK:  [[DefineD1]] = !DIMacro(type: DW_MACINFO_define, line: 15, name: "D1", value: "1")
end_comment

begin_comment
comment|// CHECK:  [[FileInclude1]] = !DIMacroFile(line: 16, file: [[HeaderFile]], nodes: [[N3:![0-9]+]])
end_comment

begin_comment
comment|// CHECK:  [[N3]] = !{[[DefineAx:![0-9]+]], [[UndefA]]}
end_comment

begin_comment
comment|// CHECK:  [[DefineAx]] = !DIMacro(type: DW_MACINFO_define, line: 3, name: "A(x,y,z)", value: "(x)")
end_comment

begin_comment
comment|// CHECK:  [[UndefD1]] = !DIMacro(type: DW_MACINFO_undef, line: 17, name: "D1")
end_comment

begin_comment
comment|// CHECK:  [[DefineD2]] = !DIMacro(type: DW_MACINFO_define, line: 18, name: "D2", value: "2")
end_comment

begin_comment
comment|// CHECK:  [[FileInclude2]] = !DIMacroFile(line: 19, file: [[HeaderFile]], nodes: [[N4:![0-9]+]])
end_comment

begin_comment
comment|// CHECK:  [[N4]] = !{[[DefineAy:![0-9]+]], [[UndefA]]}
end_comment

begin_comment
comment|// CHECK:  [[DefineAy]] = !DIMacro(type: DW_MACINFO_define, line: 7, name: "A(x,y,z)", value: "(y)")
end_comment

begin_comment
comment|// CHECK:  [[UndefD2]] = !DIMacro(type: DW_MACINFO_undef, line: 20, name: "D2")
end_comment

begin_comment
comment|// NO_PCH: [[BuiltinMacro]] = !DIMacro(type: DW_MACINFO_define, name: "__llvm__", value: "1")
end_comment

begin_comment
comment|// CHECK:  [[DefineC1]] = !DIMacro(type: DW_MACINFO_define, name: "C1(x)", value: "( x + 5 )")
end_comment

begin_comment
comment|// CHECK:  [[DefineA]] = !DIMacro(type: DW_MACINFO_define, name: "A", value: "1")
end_comment

begin_comment
comment|// CHECK:  [[UndefC1]] = !DIMacro(type: DW_MACINFO_undef, name: "C1")
end_comment

end_unit

