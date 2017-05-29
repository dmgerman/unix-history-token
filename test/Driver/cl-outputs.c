begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|// RUN: %clang_cl /c -flto -### -- %s 2>&1 | FileCheck -check-prefix=DEFAULT %s
end_comment

begin_comment
comment|// DEFAULT: "-o" "cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fo -### -- %s 2>&1 | FileCheck -check-prefix=FoEMPTY %s
end_comment

begin_comment
comment|// FoEMPTY:  "-o" "cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /Foa -### -- %s 2>&1 | FileCheck -check-prefix=FoNAME %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Foa -flto -### -- %s 2>&1 | FileCheck -check-prefix=FoNAME %s
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
comment|// RUN: %clang_cl /Fo -### -- %s %s 2>&1 | FileCheck -check-prefix=CHECK-MULTIPLESOURCEOK2 %s
end_comment

begin_comment
comment|// CHECK-MULTIPLESOURCEOK2: "-o" "cl-outputs.obj"
end_comment

begin_comment
comment|// CHECK-MULTIPLESOURCEOK2: "-o" "cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /oa -### -- %s 2>&1 | FileCheck -check-prefix=oNAME1 %s
end_comment

begin_comment
comment|// oNAME1:  "-o" "a.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /o a -### -- %s 2>&1 | FileCheck -check-prefix=oNAME2 %s
end_comment

begin_comment
comment|// oNAME2:  "-o" "a.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /oa.ext /ob.ext -### -- %s 2>&1 | FileCheck -check-prefix=oNAMEEXT1 %s
end_comment

begin_comment
comment|// oNAMEEXT1:  "-o" "b.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /o a.ext /ob.ext -### -- %s 2>&1 | FileCheck -check-prefix=oNAMEEXT2 %s
end_comment

begin_comment
comment|// oNAMEEXT2:  "-o" "b.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /ofoo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=oDIR1 %s
end_comment

begin_comment
comment|// oDIR1:  "-o" "foo.dir{{[/\\]+}}cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /o foo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=oDIR2 %s
end_comment

begin_comment
comment|// oDIR2:  "-o" "foo.dir{{[/\\]+}}cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /ofoo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=oDIRNAME1 %s
end_comment

begin_comment
comment|// oDIRNAME1:  "-o" "foo.dir{{[/\\]+}}a.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /o foo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=oDIRNAME2 %s
end_comment

begin_comment
comment|// oDIRNAME2:  "-o" "foo.dir{{[/\\]+}}a.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /ofoo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=oDIRNAMEEXT1 %s
end_comment

begin_comment
comment|// oDIRNAMEEXT1:  "-o" "foo.dir{{[/\\]+}}a.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /o foo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=oDIRNAMEEXT2 %s
end_comment

begin_comment
comment|// oDIRNAMEEXT2:  "-o" "foo.dir{{[/\\]+}}a.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /o.. -### -- %s 2>&1 | FileCheck -check-prefix=oCRAZY1 %s
end_comment

begin_comment
comment|// oCRAZY1:  "-o" "..obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /o .. -### -- %s 2>&1 | FileCheck -check-prefix=oCRAZY2 %s
end_comment

begin_comment
comment|// oCRAZY2:  "-o" "..obj"
end_comment

begin_comment
comment|// RUN: not %clang_cl /c %s -### /o 2>&1 | FileCheck -check-prefix=oMISSINGARG %s
end_comment

begin_comment
comment|// oMISSINGARG: error: argument to '/o' is missing (expected 1 value)
end_comment

begin_comment
comment|// RUN: %clang_cl /c /omydir/ -### -- %s %s 2>&1 | FileCheck -check-prefix=CHECK-oMULTIPLESOURCEOK1 %s
end_comment

begin_comment
comment|// CHECK-oMULTIPLESOURCEOK1: "-o" "mydir{{[/\\]+}}cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /o mydir/ -### -- %s %s 2>&1 | FileCheck -check-prefix=CHECK-oMULTIPLESOURCEOK2 %s
end_comment

begin_comment
comment|// CHECK-oMULTIPLESOURCEOK2: "-o" "mydir{{[/\\]+}}cl-outputs.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /obar /Fofoo -### -- %s 2>&1 | FileCheck -check-prefix=FooRACE1 %s
end_comment

begin_comment
comment|// FooRACE1: "-o" "foo.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /Fofoo /obar -### -- %s 2>&1 | FileCheck -check-prefix=FooRACE2 %s
end_comment

begin_comment
comment|// FooRACE2: "-o" "bar.obj"
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
comment|// RUN: %clang_cl /Fe -### -- %s 2>&1 | FileCheck -check-prefix=FeEMPTY %s
end_comment

begin_comment
comment|// FeEMPTY-NOT: argument to '/Fe' is missing
end_comment

begin_comment
comment|// FeEMPTY: "-out:cl-outputs.exe"
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
comment|// RUN: %clang_cl /Fefoo /Febar -### -- %s 2>&1 | FileCheck -check-prefix=FeOVERRIDE %s
end_comment

begin_comment
comment|// FeOVERRIDE: "-out:bar.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /obar /Fefoo -### -- %s 2>&1 | FileCheck -check-prefix=FeoRACE1 %s
end_comment

begin_comment
comment|// FeoRACE1: "-out:foo.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /Fefoo /obar -### -- %s 2>&1 | FileCheck -check-prefix=FeoRACE2 %s
end_comment

begin_comment
comment|// FeoRACE2: "-out:bar.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /ofoo -### -- %s 2>&1 | FileCheck -check-prefix=FeoNOEXT1 %s
end_comment

begin_comment
comment|// FeoNOEXT1: "-out:foo.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /o foo -### -- %s 2>&1 | FileCheck -check-prefix=FeoNOEXT2 %s
end_comment

begin_comment
comment|// FeoNOEXT2: "-out:foo.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /o foo /LD -### -- %s 2>&1 | FileCheck -check-prefix=FeoNOEXTDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /ofoo /LDd -### -- %s 2>&1 | FileCheck -check-prefix=FeoNOEXTDLL %s
end_comment

begin_comment
comment|// FeoNOEXTDLL: "-out:foo.dll"
end_comment

begin_comment
comment|// FeoNOEXTDLL: "-implib:foo.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /ofoo.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeoEXT1 %s
end_comment

begin_comment
comment|// FeoEXT1: "-out:foo.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /o foo.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeoEXT2 %s
end_comment

begin_comment
comment|// FeoEXT2: "-out:foo.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD /o foo.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeoEXTDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd /ofoo.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeoEXTDLL %s
end_comment

begin_comment
comment|// FeoEXTDLL: "-out:foo.ext"
end_comment

begin_comment
comment|// FeoEXTDLL: "-implib:foo.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /ofoo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIR1 %s
end_comment

begin_comment
comment|// FeoDIR1: "-out:foo.dir{{[/\\]+}}cl-outputs.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /o foo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIR2 %s
end_comment

begin_comment
comment|// FeoDIR2: "-out:foo.dir{{[/\\]+}}cl-outputs.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD /o foo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd /ofoo.dir/ -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRDLL %s
end_comment

begin_comment
comment|// FeoDIRDLL: "-out:foo.dir{{[/\\]+}}cl-outputs.dll"
end_comment

begin_comment
comment|// FeoDIRDLL: "-implib:foo.dir{{[/\\]+}}cl-outputs.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /ofoo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRNAME1 %s
end_comment

begin_comment
comment|// FeoDIRNAME1: "-out:foo.dir{{[/\\]+}}a.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /o foo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRNAME2 %s
end_comment

begin_comment
comment|// FeoDIRNAME2: "-out:foo.dir{{[/\\]+}}a.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD /o foo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRNAMEDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd /ofoo.dir/a -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRNAMEDLL %s
end_comment

begin_comment
comment|// FeoDIRNAMEDLL: "-out:foo.dir{{[/\\]+}}a.dll"
end_comment

begin_comment
comment|// FeoDIRNAMEDLL: "-implib:foo.dir{{[/\\]+}}a.lib"
end_comment

begin_comment
comment|// RUN: %clang_cl /ofoo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRNAMEEXT1 %s
end_comment

begin_comment
comment|// FeoDIRNAMEEXT1: "-out:foo.dir{{[/\\]+}}a.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /o foo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRNAMEEXT2 %s
end_comment

begin_comment
comment|// FeoDIRNAMEEXT2: "-out:foo.dir{{[/\\]+}}a.ext"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD /o foo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRNAMEEXTDLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd /ofoo.dir/a.ext -### -- %s 2>&1 | FileCheck -check-prefix=FeoDIRNAMEEXTDLL %s
end_comment

begin_comment
comment|// FeoDIRNAMEEXTDLL: "-out:foo.dir{{[/\\]+}}a.ext"
end_comment

begin_comment
comment|// FeoDIRNAMEEXTDLL: "-implib:foo.dir{{[/\\]+}}a.lib"
end_comment

begin_comment
comment|// RUN: not %clang_cl -### /o 2>&1 | FileCheck -check-prefix=FeoMISSINGARG %s
end_comment

begin_comment
comment|// FeoMISSINGARG: error: argument to '/o' is missing (expected 1 value)
end_comment

begin_comment
comment|// RUN: %clang_cl /ofoo /o bar -### -- %s 2>&1 | FileCheck -check-prefix=FeoOVERRIDE %s
end_comment

begin_comment
comment|// FeoOVERRIDE: "-out:bar.exe"
end_comment

begin_comment
comment|// RUN: %clang_cl /FA -### -- %s 2>&1 | FileCheck -check-prefix=FA %s
end_comment

begin_comment
comment|// FA: "-o" "cl-outputs.asm"
end_comment

begin_comment
comment|// RUN: %clang_cl /FA /Fa -### -- %s 2>&1 | FileCheck -check-prefix=FaEMPTY %s
end_comment

begin_comment
comment|// FaEMPTY: "-o" "cl-outputs.asm"
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
comment|// RUN: %clang_cl /Fa -### -- %s %s 2>&1 | FileCheck -check-prefix=FaMULTIPLESOURCEOK %s
end_comment

begin_comment
comment|// FaMULTIPLESOURCEOK: "-o" "cl-outputs.asm"
end_comment

begin_comment
comment|// FaMULTIPLESOURCEOK: "-o" "cl-outputs.asm"
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

begin_comment
comment|// To match MSVC behavior /o should be ignored for /P output.
end_comment

begin_comment
comment|// RUN: %clang_cl /P /ofoo -### -- %s 2>&1 | FileCheck -check-prefix=Fio1 %s
end_comment

begin_comment
comment|// Fio1: "-E"
end_comment

begin_comment
comment|// Fio1: "-o" "cl-outputs.i"
end_comment

begin_comment
comment|// RUN: %clang_cl /P /o foo.x -### -- %s 2>&1 | FileCheck -check-prefix=Fio2 %s
end_comment

begin_comment
comment|// Fio2: "-E"
end_comment

begin_comment
comment|// Fio2: "-o" "cl-outputs.i"
end_comment

begin_comment
comment|// RUN: %clang_cl /P /obar.x /Fifoo.x -### -- %s 2>&1 | FileCheck -check-prefix=FioRACE1 %s
end_comment

begin_comment
comment|// FioRACE1: "-E"
end_comment

begin_comment
comment|// FioRACE1: "-o" "foo.x"
end_comment

begin_comment
comment|// RUN: %clang_cl /P /Fifoo.x /obar.x -### -- %s 2>&1 | FileCheck -check-prefix=FioRACE2 %s
end_comment

begin_comment
comment|// FioRACE2: "-E"
end_comment

begin_comment
comment|// FioRACE2: "-o" "foo.x"
end_comment

end_unit

