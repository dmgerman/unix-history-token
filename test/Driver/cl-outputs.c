begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Don't attempt slash switches on msys bash.
end_comment

begin_comment
comment|// REQUIRES: shell-preserves-root
end_comment

begin_comment
comment|// Note: %s must be preceded by --, otherwise it may be interpreted as a
end_comment

begin_comment
comment|// command-line option, e.g. on Mac where %s is commonly under /Users.
end_comment

begin_comment
comment|// RUN: %clang_cl /c -### -- %s 2>&1 | FileCheck -check-prefix=DEFAULT %s
end_comment

begin_comment
comment|// DEFAULT: "-o" "cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /Foa -### -- %s 2>&1 | FileCheck -check-prefix=FoNAME %s
end_comment

begin_comment
comment|// FoNAME:  "-o" "a.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /Foa.ext /Fob.ext -### -- %s 2>&1 | FileCheck -check-prefix=FoNAMEEXT %s
end_comment

begin_comment
comment|// FoNAMEEXT:  "-o" "b.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fofoo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=FoDIR %s
end_comment

begin_comment
comment|// FoDIR:  "-o" "foo.dir{{[/\\]+}}cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fofoo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=FoDIRNAME %s
end_comment

begin_comment
comment|// FoDIRNAME:  "-o" "foo.dir{{[/\\]+}}a.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fofoo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=FoDIRNAMEEXT %s
end_comment

begin_comment
comment|// FoDIRNAMEEXT:  "-o" "foo.dir{{[/\\]+}}a.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fo.. -### -- %s 2>&1 | FileCheck -check-prefix=FoCRAZY %s
end_comment

begin_comment
comment|// FoCRAZY:  "-o" "..obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fo -### 2>&1 | FileCheck -check-prefix=FoMISSINGARG %s
end_comment

begin_comment
comment|// FoMISSINGARG: error: argument to '/Fo' is missing (expected 1 value)
end_comment

begin_comment
comment|// RUN: %clang_cl /Foa.obj -### -- %s %s 2>&1 | FileCheck -check-prefix=CHECK-MULTIPLESOURCEERROR %s
end_comment

begin_comment
comment|// CHECK-MULTIPLESOURCEERROR: error: cannot specify '/Foa.obj' when compiling multiple source files
end_comment

begin_comment
comment|// RUN: %clang_cl /Fomydir/ -### -- %s %s 2>&1 | FileCheck -check-prefix=CHECK-MULTIPLESOURCEOK %s
end_comment

begin_comment
comment|// CHECK-MULTIPLESOURCEOK: "-o" "mydir{{[/\\]+}}cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl -### -- %s 2>&1 | FileCheck -check-prefix=DEFAULTEXE %s
end_comment

begin_comment
comment|// DEFAULTEXE: cl-outputs.exe
end_comment

begin_comment
comment|// RUN: %clang_cl /LD -### -- %s 2>&1 | FileCheck -check-prefix=DEFAULTDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd -### -- %s 2>&1 | FileCheck -check-prefix=DEFAULTDLL %s
end_comment

begin_comment
comment|// DEFAULTDLL: "-out:cl-outputs.dll"
end_comment

begin_comment
comment|// DEFAULTDLL: "-implib:cl-outputs.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fefoo -### -- %s 2>&1 | FileCheck -check-prefix=FeNOEXT %s
end_comment

begin_comment
comment|// FeNOEXT: "-out:foo.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fefoo /LD -### -- %s 2>&1 | FileCheck -check-prefix=FeNOEXTDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Fefoo /LDd -### -- %s 2>&1 | FileCheck -check-prefix=FeNOEXTDLL %s
end_comment

begin_comment
comment|// FeNOEXTDLL: "-out:foo.dll"
end_comment

begin_comment
comment|// FeNOEXTDLL: "-implib:foo.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fefoo.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeEXT %s
end_comment

begin_comment
comment|// FeEXT: "-out:foo.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD /Fefoo.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeEXTDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd /Fefoo.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeEXTDLL %s
end_comment

begin_comment
comment|// FeEXTDLL: "-out:foo.ext"
end_comment

begin_comment
comment|// FeEXTDLL: "-implib:foo.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fefoo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=FeDIR %s
end_comment

begin_comment
comment|// FeDIR: "-out:foo.dir{{[/\\]+}}cl-outputs.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD /Fefoo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=FeDIRDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd /Fefoo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=FeDIRDLL %s
end_comment

begin_comment
comment|// FeDIRDLL: "-out:foo.dir{{[/\\]+}}cl-outputs.dll"
end_comment

begin_comment
comment|// FeDIRDLL: "-implib:foo.dir{{[/\\]+}}cl-outputs.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fefoo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=FeDIRNAME %s
end_comment

begin_comment
comment|// FeDIRNAME: "-out:foo.dir{{[/\\]+}}a.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD /Fefoo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=FeDIRNAMEDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd /Fefoo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=FeDIRNAMEDLL %s
end_comment

begin_comment
comment|// FeDIRNAMEDLL: "-out:foo.dir{{[/\\]+}}a.dll"
end_comment

begin_comment
comment|// FeDIRNAMEDLL: "-implib:foo.dir{{[/\\]+}}a.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fefoo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeDIRNAMEEXT %s
end_comment

begin_comment
comment|// FeDIRNAMEEXT: "-out:foo.dir{{[/\\]+}}a.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD /Fefoo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeDIRNAMEEXTDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd /Fefoo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeDIRNAMEEXTDLL %s
end_comment

begin_comment
comment|// FeDIRNAMEEXTDLL: "-out:foo.dir{{[/\\]+}}a.ext"
end_comment

begin_comment
comment|// FeDIRNAMEEXTDLL: "-implib:foo.dir{{[/\\]+}}a.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fe -### 2>&1 | FileCheck -check-prefix=FeMISSINGARG %s
end_comment

begin_comment
comment|// FeMISSINGARG: error: argument to '/Fe' is missing (expected 1 value)
end_comment

begin_comment
comment|// RUN: %clang_cl /Fefoo /Febar -### -- %s 2>&1 | FileCheck -check-prefix=FeOVERRIDE %s
end_comment

begin_comment
comment|// FeOVERRIDE: "-out:bar.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /FA -### -- %s 2>&1 | FileCheck -check-prefix=FA %s
end_comment

begin_comment
comment|// FA: "-o" "cl-outputs.asm"
end_comment

begin_comment
comment|// RUN: %clang_cl /FA /Fafoo -### -- %s 2>&1 | FileCheck -check-prefix=FaNAME %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Fafoo -### -- %s 2>&1 | FileCheck -check-prefix=FaNAME %s
end_comment

begin_comment
comment|// FaNAME:  "-o" "foo.asm"
end_comment

begin_comment
comment|// RUN: %clang_cl /FA /Faa.ext /Fab.ext -### -- %s 2>&1 | FileCheck -check-prefix=FaNAMEEXT %s
end_comment

begin_comment
comment|// FaNAMEEXT:  "-o" "b.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /FA /Fafoo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=FaDIR %s
end_comment

begin_comment
comment|// FaDIR:  "-o" "foo.dir{{[/\\]+}}cl-outputs.asm"
end_comment

begin_comment
comment|// RUN: %clang_cl /FA /Fafoo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=FaDIRNAME %s
end_comment

begin_comment
comment|// FaDIRNAME:  "-o" "foo.dir{{[/\\]+}}a.asm"
end_comment

begin_comment
comment|// RUN: %clang_cl /FA /Fafoo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=FaDIRNAMEEXT %s
end_comment

begin_comment
comment|// FaDIRNAMEEXT:  "-o" "foo.dir{{[/\\]+}}a.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /Faa.asm -### -- %s %s 2>&1 | FileCheck -check-prefix=FaMULTIPLESOURCE %s
end_comment

begin_comment
comment|// FaMULTIPLESOURCE: error: cannot specify '/Faa.asm' when compiling multiple source files
end_comment

begin_comment
comment|// RUN: %clang_cl /P -### -- %s 2>&1 | FileCheck -check-prefix=P %s
end_comment

begin_comment
comment|// P: "-E"
end_comment

begin_comment
comment|// P: "-o" "cl-outputs.i"
end_comment

begin_comment
comment|// RUN: %clang_cl /P /Fifoo -### -- %s 2>&1 | FileCheck -check-prefix=Fi1 %s
end_comment

begin_comment
comment|// Fi1: "-E"
end_comment

begin_comment
comment|// Fi1: "-o" "foo.i"
end_comment

begin_comment
comment|// RUN: %clang_cl /P /Fifoo.x -### -- %s 2>&1 | FileCheck -check-prefix=Fi2 %s
end_comment

begin_comment
comment|// Fi2: "-E"
end_comment

begin_comment
comment|// Fi2: "-o" "foo.x"
end_comment

end_unit

