begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: %s must be preceded by --, otherwise it may be interpreted as a
end_comment

begin_comment
comment|// command-line option, e.g. on Mac where %s is commonly under /Users.
end_comment

begin_comment
comment|// Alias options:
end_comment

begin_comment
comment|// RUN: %clang_cl /c -### -- %s 2>&1 | FileCheck -check-prefix=c %s
end_comment

begin_comment
comment|// c: -c
end_comment

begin_comment
comment|// RUN: %clang_cl /C -### -- %s 2>&1 | FileCheck -check-prefix=C %s
end_comment

begin_comment
comment|// C: error: invalid argument '-C' only allowed with '/E, /P or /EP'
end_comment

begin_comment
comment|// RUN: %clang_cl /C /P -### -- %s 2>&1 | FileCheck -check-prefix=C_P %s
end_comment

begin_comment
comment|// C_P: "-E"
end_comment

begin_comment
comment|// C_P: "-C"
end_comment

begin_comment
comment|// RUN: %clang_cl /d1reportAllClassLayout -### -- %s 2>&1 | FileCheck -check-prefix=d1reportAllClassLayout %s
end_comment

begin_comment
comment|// d1reportAllClassLayout: -fdump-record-layouts
end_comment

begin_comment
comment|// RUN: %clang_cl /Dfoo=bar /D bar=baz /DMYDEF#value /DMYDEF2=foo#bar /DMYDEF3#a=b /DMYDEF4# \
end_comment

begin_comment
comment|// RUN:    -### -- %s 2>&1 | FileCheck -check-prefix=D %s
end_comment

begin_comment
comment|// D: "-D" "foo=bar"
end_comment

begin_comment
comment|// D: "-D" "bar=baz"
end_comment

begin_comment
comment|// D: "-D" "MYDEF=value"
end_comment

begin_comment
comment|// D: "-D" "MYDEF2=foo#bar"
end_comment

begin_comment
comment|// D: "-D" "MYDEF3=a=b"
end_comment

begin_comment
comment|// D: "-D" "MYDEF4="
end_comment

begin_comment
comment|// RUN: %clang_cl /E -### -- %s 2>&1 | FileCheck -check-prefix=E %s
end_comment

begin_comment
comment|// E: "-E"
end_comment

begin_comment
comment|// E: "-o" "-"
end_comment

begin_comment
comment|// RUN: %clang_cl /EP -### -- %s 2>&1 | FileCheck -check-prefix=EP %s
end_comment

begin_comment
comment|// EP: "-E"
end_comment

begin_comment
comment|// EP: "-P"
end_comment

begin_comment
comment|// EP: "-o" "-"
end_comment

begin_comment
comment|// RUN: %clang_cl /fp:fast /fp:except -### -- %s 2>&1 | FileCheck -check-prefix=fpexcept %s
end_comment

begin_comment
comment|// fpexcept-NOT: -menable-unsafe-fp-math
end_comment

begin_comment
comment|// RUN: %clang_cl /fp:fast /fp:except /fp:except- -### -- %s 2>&1 | FileCheck -check-prefix=fpexcept_ %s
end_comment

begin_comment
comment|// fpexcept_: -menable-unsafe-fp-math
end_comment

begin_comment
comment|// RUN: %clang_cl /fp:precise /fp:fast -### -- %s 2>&1 | FileCheck -check-prefix=fpfast %s
end_comment

begin_comment
comment|// fpfast: -menable-unsafe-fp-math
end_comment

begin_comment
comment|// fpfast: -ffast-math
end_comment

begin_comment
comment|// RUN: %clang_cl /fp:fast /fp:precise -### -- %s 2>&1 | FileCheck -check-prefix=fpprecise %s
end_comment

begin_comment
comment|// fpprecise-NOT: -menable-unsafe-fp-math
end_comment

begin_comment
comment|// fpprecise-NOT: -ffast-math
end_comment

begin_comment
comment|// RUN: %clang_cl /fp:fast /fp:strict -### -- %s 2>&1 | FileCheck -check-prefix=fpstrict %s
end_comment

begin_comment
comment|// fpstrict-NOT: -menable-unsafe-fp-math
end_comment

begin_comment
comment|// fpstrict-NOT: -ffast-math
end_comment

begin_comment
comment|// RUN: %clang_cl /Z7 -gcolumn-info -### -- %s 2>&1 | FileCheck -check-prefix=gcolumn %s
end_comment

begin_comment
comment|// gcolumn: -dwarf-column-info
end_comment

begin_comment
comment|// RUN: %clang_cl /Z7 -gno-column-info -### -- %s 2>&1 | FileCheck -check-prefix=gnocolumn %s
end_comment

begin_comment
comment|// gnocolumn-NOT: -dwarf-column-info
end_comment

begin_comment
comment|// RUN: %clang_cl /Z7 -### -- %s 2>&1 | FileCheck -check-prefix=gdefcolumn %s
end_comment

begin_comment
comment|// gdefcolumn-NOT: -dwarf-column-info
end_comment

begin_comment
comment|// RUN: %clang_cl -### /FA -fprofile-instr-generate -- %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-GENERATE %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /FA -fprofile-instr-generate=/tmp/somefile.profraw -- %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-GENERATE-FILE %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /FA -fprofile-instr-generate -fprofile-instr-use -- %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /FA -fprofile-instr-generate -fprofile-instr-use=file -- %s 2>&1 | FileCheck -check-prefix=CHECK-NO-MIX-GEN-USE %s
end_comment

begin_comment
comment|// CHECK-PROFILE-GENERATE: "-fprofile-instrument=clang"
end_comment

begin_comment
comment|// CHECK-PROFILE-GENERATE-FILE: "-fprofile-instrument-path=/tmp/somefile.profraw"
end_comment

begin_comment
comment|// CHECK-NO-MIX-GEN-USE: '{{[a-z=-]*}}' not allowed with '{{[a-z=-]*}}'
end_comment

begin_comment
comment|// RUN: %clang_cl -### /FA -fprofile-instr-use -- %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-USE %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /FA -fprofile-instr-use=/tmp/somefile.prof -- %s 2>&1 | FileCheck -check-prefix=CHECK-PROFILE-USE-FILE %s
end_comment

begin_comment
comment|// CHECK-PROFILE-USE: "-fprofile-instrument-use-path=default.profdata"
end_comment

begin_comment
comment|// CHECK-PROFILE-USE-FILE: "-fprofile-instrument-use-path=/tmp/somefile.prof"
end_comment

begin_comment
comment|// RUN: %clang_cl /GA -### -- %s 2>&1 | FileCheck -check-prefix=GA %s
end_comment

begin_comment
comment|// GA: -ftls-model=local-exec
end_comment

begin_comment
comment|// RTTI is on by default; just check that we don't error.
end_comment

begin_comment
comment|// RUN: %clang_cl /Zs /GR -- %s 2>&1
end_comment

begin_comment
comment|// RUN: %clang_cl /GR- -### -- %s 2>&1 | FileCheck -check-prefix=GR_ %s
end_comment

begin_comment
comment|// GR_: -fno-rtti
end_comment

begin_comment
comment|// Security Buffer Check is on by default.
end_comment

begin_comment
comment|// RUN: %clang_cl -### -- %s 2>&1 | FileCheck -check-prefix=GS-default %s
end_comment

begin_comment
comment|// GS-default: "-stack-protector" "2"
end_comment

begin_comment
comment|// RUN: %clang_cl /GS -### -- %s 2>&1 | FileCheck -check-prefix=GS %s
end_comment

begin_comment
comment|// GS: "-stack-protector" "2"
end_comment

begin_comment
comment|// RUN: %clang_cl /GS- -### -- %s 2>&1 | FileCheck -check-prefix=GS_ %s
end_comment

begin_comment
comment|// GS_-NOT: -stack-protector
end_comment

begin_comment
comment|// RUN: %clang_cl /Gy -### -- %s 2>&1 | FileCheck -check-prefix=Gy %s
end_comment

begin_comment
comment|// Gy: -ffunction-sections
end_comment

begin_comment
comment|// RUN: %clang_cl /Gy /Gy- -### -- %s 2>&1 | FileCheck -check-prefix=Gy_ %s
end_comment

begin_comment
comment|// Gy_-NOT: -ffunction-sections
end_comment

begin_comment
comment|// RUN: %clang_cl /Gs -### -- %s 2>&1 | FileCheck -check-prefix=Gs %s
end_comment

begin_comment
comment|// Gs: "-mstack-probe-size=0"
end_comment

begin_comment
comment|// RUN: %clang_cl /Gs0 -### -- %s 2>&1 | FileCheck -check-prefix=Gs0 %s
end_comment

begin_comment
comment|// Gs0: "-mstack-probe-size=0"
end_comment

begin_comment
comment|// RUN: %clang_cl /Gs4096 -### -- %s 2>&1 | FileCheck -check-prefix=Gs4096 %s
end_comment

begin_comment
comment|// Gs4096: "-mstack-probe-size=4096"
end_comment

begin_comment
comment|// RUN: %clang_cl /Gw -### -- %s 2>&1 | FileCheck -check-prefix=Gw %s
end_comment

begin_comment
comment|// Gw: -fdata-sections
end_comment

begin_comment
comment|// RUN: %clang_cl /Gw /Gw- -### -- %s 2>&1 | FileCheck -check-prefix=Gw_ %s
end_comment

begin_comment
comment|// Gw_-NOT: -fdata-sections
end_comment

begin_comment
comment|// RUN: %clang_cl /Imyincludedir -### -- %s 2>&1 | FileCheck -check-prefix=SLASH_I %s
end_comment

begin_comment
comment|// RUN: %clang_cl /I myincludedir -### -- %s 2>&1 | FileCheck -check-prefix=SLASH_I %s
end_comment

begin_comment
comment|// SLASH_I: "-I" "myincludedir"
end_comment

begin_comment
comment|// RUN: %clang_cl /imsvcmyincludedir -### -- %s 2>&1 | FileCheck -check-prefix=SLASH_imsvc %s
end_comment

begin_comment
comment|// RUN: %clang_cl /imsvc myincludedir -### -- %s 2>&1 | FileCheck -check-prefix=SLASH_imsvc %s
end_comment

begin_comment
comment|// Clang's resource header directory should be first:
end_comment

begin_comment
comment|// SLASH_imsvc: "-internal-isystem" "{{[^"]*}}lib{{(64)?/|\\\\}}clang{{[^"]*}}include"
end_comment

begin_comment
comment|// SLASH_imsvc: "-internal-isystem" "myincludedir"
end_comment

begin_comment
comment|// RUN: %clang_cl /J -### -- %s 2>&1 | FileCheck -check-prefix=J %s
end_comment

begin_comment
comment|// J: -fno-signed-char
end_comment

begin_comment
comment|// RUN: %clang_cl /Ofoo -### -- %s 2>&1 | FileCheck -check-prefix=O %s
end_comment

begin_comment
comment|// O: /Ofoo
end_comment

begin_comment
comment|// RUN: %clang_cl /Ob0 -### -- %s 2>&1 | FileCheck -check-prefix=Ob0 %s
end_comment

begin_comment
comment|// Ob0: -fno-inline
end_comment

begin_comment
comment|// RUN: %clang_cl /Ob2 -### -- %s 2>&1 | FileCheck -check-prefix=Ob2 %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Odb2 -### -- %s 2>&1 | FileCheck -check-prefix=Ob2 %s
end_comment

begin_comment
comment|// RUN: %clang_cl /O2 /Ob2 -### -- %s 2>&1 | FileCheck -check-prefix=Ob2 %s
end_comment

begin_comment
comment|// Ob2-NOT: warning: argument unused during compilation: '/O2'
end_comment

begin_comment
comment|// Ob2: -finline-functions
end_comment

begin_comment
comment|// RUN: %clang_cl /Ob1 -### -- %s 2>&1 | FileCheck -check-prefix=Ob1 %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Odb1 -### -- %s 2>&1 | FileCheck -check-prefix=Ob1 %s
end_comment

begin_comment
comment|// Ob1: -finline-hint-functions
end_comment

begin_comment
comment|// RUN: %clang_cl /Od -### -- %s 2>&1 | FileCheck -check-prefix=Od %s
end_comment

begin_comment
comment|// Od: -O0
end_comment

begin_comment
comment|// RUN: %clang_cl /Oi- /Oi -### -- %s 2>&1 | FileCheck -check-prefix=Oi %s
end_comment

begin_comment
comment|// Oi-NOT: -fno-builtin
end_comment

begin_comment
comment|// RUN: %clang_cl /Oi- -### -- %s 2>&1 | FileCheck -check-prefix=Oi_ %s
end_comment

begin_comment
comment|// Oi_: -fno-builtin
end_comment

begin_comment
comment|// RUN: %clang_cl /Os --target=i686-pc-windows-msvc -### -- %s 2>&1 | FileCheck -check-prefix=Os %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Os --target=x86_64-pc-windows-msvc -### -- %s 2>&1 | FileCheck -check-prefix=Os %s
end_comment

begin_comment
comment|// Os-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// Os: -momit-leaf-frame-pointer
end_comment

begin_comment
comment|// Os: -Os
end_comment

begin_comment
comment|// RUN: %clang_cl /Ot --target=i686-pc-windows-msvc -### -- %s 2>&1 | FileCheck -check-prefix=Ot %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Ot --target=x86_64-pc-windows-msvc -### -- %s 2>&1 | FileCheck -check-prefix=Ot %s
end_comment

begin_comment
comment|// Ot-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// Ot: -momit-leaf-frame-pointer
end_comment

begin_comment
comment|// Ot: -O2
end_comment

begin_comment
comment|// RUN: %clang_cl /Ox --target=i686-pc-windows-msvc -### -- %s 2>&1 | FileCheck -check-prefix=Ox %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Ox --target=x86_64-pc-windows-msvc -### -- %s 2>&1 | FileCheck -check-prefix=Ox %s
end_comment

begin_comment
comment|// Ox-NOT: -mdisable-fp-elim
end_comment

begin_comment
comment|// Ox: -momit-leaf-frame-pointer
end_comment

begin_comment
comment|// Ox: -O2
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-pc-win32 /O2sy- -### -- %s 2>&1 | FileCheck -check-prefix=PR24003 %s
end_comment

begin_comment
comment|// PR24003: -mdisable-fp-elim
end_comment

begin_comment
comment|// PR24003: -momit-leaf-frame-pointer
end_comment

begin_comment
comment|// PR24003: -Os
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-pc-win32 -Werror /Oy- /O2 -### -- %s 2>&1 | FileCheck -check-prefix=Oy_2 %s
end_comment

begin_comment
comment|// Oy_2: -momit-leaf-frame-pointer
end_comment

begin_comment
comment|// Oy_2: -O2
end_comment

begin_comment
comment|// RUN: %clang_cl /Zs -Werror /Oy -- %s 2>&1
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-pc-win32 -Werror /Oy- -### -- %s 2>&1 | FileCheck -check-prefix=Oy_ %s
end_comment

begin_comment
comment|// Oy_: -mdisable-fp-elim
end_comment

begin_comment
comment|// RUN: %clang_cl /Qvec -### -- %s 2>&1 | FileCheck -check-prefix=Qvec %s
end_comment

begin_comment
comment|// Qvec: -vectorize-loops
end_comment

begin_comment
comment|// RUN: %clang_cl /Qvec /Qvec- -### -- %s 2>&1 | FileCheck -check-prefix=Qvec_ %s
end_comment

begin_comment
comment|// Qvec_-NOT: -vectorize-loops
end_comment

begin_comment
comment|// RUN: %clang_cl /showIncludes -### -- %s 2>&1 | FileCheck -check-prefix=showIncludes %s
end_comment

begin_comment
comment|// showIncludes: --show-includes
end_comment

begin_comment
comment|// RUN: %clang_cl /E /showIncludes -### -- %s 2>&1 | FileCheck -check-prefix=showIncludes_E %s
end_comment

begin_comment
comment|// RUN: %clang_cl /EP /showIncludes -### -- %s 2>&1 | FileCheck -check-prefix=showIncludes_E %s
end_comment

begin_comment
comment|// showIncludes_E: warning: argument unused during compilation: '--show-includes'
end_comment

begin_comment
comment|// /source-charset: should warn on everything except UTF-8.
end_comment

begin_comment
comment|// RUN: %clang_cl /source-charset:utf-16 -### -- %s 2>&1 | FileCheck -check-prefix=source-charset-utf-16 %s
end_comment

begin_comment
comment|// source-charset-utf-16: invalid value 'utf-16'
end_comment

begin_comment
comment|// /execution-charset: should warn on everything except UTF-8.
end_comment

begin_comment
comment|// RUN: %clang_cl /execution-charset:utf-16 -### -- %s 2>&1 | FileCheck -check-prefix=execution-charset-utf-16 %s
end_comment

begin_comment
comment|// execution-charset-utf-16: invalid value 'utf-16'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cl /Umymacro -### -- %s 2>&1 | FileCheck -check-prefix=U %s
end_comment

begin_comment
comment|// RUN: %clang_cl /U mymacro -### -- %s 2>&1 | FileCheck -check-prefix=U %s
end_comment

begin_comment
comment|// U: "-U" "mymacro"
end_comment

begin_comment
comment|// RUN: %clang_cl /validate-charset -### -- %s 2>&1 | FileCheck -check-prefix=validate-charset %s
end_comment

begin_comment
comment|// validate-charset: -Winvalid-source-encoding
end_comment

begin_comment
comment|// RUN: %clang_cl /validate-charset- -### -- %s 2>&1 | FileCheck -check-prefix=validate-charset_ %s
end_comment

begin_comment
comment|// validate-charset_: -Wno-invalid-source-encoding
end_comment

begin_comment
comment|// RUN: %clang_cl /vd2 -### -- %s 2>&1 | FileCheck -check-prefix=VD2 %s
end_comment

begin_comment
comment|// VD2: -vtordisp-mode=2
end_comment

begin_comment
comment|// RUN: %clang_cl /vmg -### -- %s 2>&1 | FileCheck -check-prefix=VMG %s
end_comment

begin_comment
comment|// VMG: "-fms-memptr-rep=virtual"
end_comment

begin_comment
comment|// RUN: %clang_cl /vmg /vms -### -- %s 2>&1 | FileCheck -check-prefix=VMS %s
end_comment

begin_comment
comment|// VMS: "-fms-memptr-rep=single"
end_comment

begin_comment
comment|// RUN: %clang_cl /vmg /vmm -### -- %s 2>&1 | FileCheck -check-prefix=VMM %s
end_comment

begin_comment
comment|// VMM: "-fms-memptr-rep=multiple"
end_comment

begin_comment
comment|// RUN: %clang_cl /vmg /vmv -### -- %s 2>&1 | FileCheck -check-prefix=VMV %s
end_comment

begin_comment
comment|// VMV: "-fms-memptr-rep=virtual"
end_comment

begin_comment
comment|// RUN: %clang_cl /vmg /vmb -### -- %s 2>&1 | FileCheck -check-prefix=VMB %s
end_comment

begin_comment
comment|// VMB: '/vmg' not allowed with '/vmb'
end_comment

begin_comment
comment|// RUN: %clang_cl /vmg /vmm /vms -### -- %s 2>&1 | FileCheck -check-prefix=VMX %s
end_comment

begin_comment
comment|// VMX: '/vms' not allowed with '/vmm'
end_comment

begin_comment
comment|// RUN: %clang_cl /volatile:iso -### -- %s 2>&1 | FileCheck -check-prefix=VOLATILE-ISO %s
end_comment

begin_comment
comment|// VOLATILE-ISO-NOT: "-fms-volatile"
end_comment

begin_comment
comment|// RUN: %clang_cl /volatile:ms -### -- %s 2>&1 | FileCheck -check-prefix=VOLATILE-MS %s
end_comment

begin_comment
comment|// VOLATILE-MS: "-fms-volatile"
end_comment

begin_comment
comment|// RUN: %clang_cl /W0 -### -- %s 2>&1 | FileCheck -check-prefix=W0 %s
end_comment

begin_comment
comment|// W0: -w
end_comment

begin_comment
comment|// RUN: %clang_cl /W1 -### -- %s 2>&1 | FileCheck -check-prefix=W1 %s
end_comment

begin_comment
comment|// RUN: %clang_cl /W2 -### -- %s 2>&1 | FileCheck -check-prefix=W1 %s
end_comment

begin_comment
comment|// RUN: %clang_cl /W3 -### -- %s 2>&1 | FileCheck -check-prefix=W1 %s
end_comment

begin_comment
comment|// RUN: %clang_cl /W4 -### -- %s 2>&1 | FileCheck -check-prefix=W4 %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Wall -### -- %s 2>&1 | FileCheck -check-prefix=W4 %s
end_comment

begin_comment
comment|// W1: -Wall
end_comment

begin_comment
comment|// W4: -WCL4
end_comment

begin_comment
comment|// RUN: %clang_cl /WX -### -- %s 2>&1 | FileCheck -check-prefix=WX %s
end_comment

begin_comment
comment|// WX: -Werror
end_comment

begin_comment
comment|// RUN: %clang_cl /WX- -### -- %s 2>&1 | FileCheck -check-prefix=WX_ %s
end_comment

begin_comment
comment|// WX_: -Wno-error
end_comment

begin_comment
comment|// RUN: %clang_cl /w -### -- %s 2>&1 | FileCheck -check-prefix=w %s
end_comment

begin_comment
comment|// w: -w
end_comment

begin_comment
comment|// RUN: %clang_cl /Zp -### -- %s 2>&1 | FileCheck -check-prefix=ZP %s
end_comment

begin_comment
comment|// ZP: -fpack-struct=1
end_comment

begin_comment
comment|// RUN: %clang_cl /Zp2 -### -- %s 2>&1 | FileCheck -check-prefix=ZP2 %s
end_comment

begin_comment
comment|// ZP2: -fpack-struct=2
end_comment

begin_comment
comment|// RUN: %clang_cl /Zs -### -- %s 2>&1 | FileCheck -check-prefix=Zs %s
end_comment

begin_comment
comment|// Zs: -fsyntax-only
end_comment

begin_comment
comment|// RUN: %clang_cl /FIasdf.h -### -- %s 2>&1 | FileCheck -check-prefix=FI %s
end_comment

begin_comment
comment|// FI: "-include" "asdf.h"
end_comment

begin_comment
comment|// RUN: %clang_cl /FI asdf.h -### -- %s 2>&1 | FileCheck -check-prefix=FI_ %s
end_comment

begin_comment
comment|// FI_: "-include" "asdf.h"
end_comment

begin_comment
comment|// RUN: %clang_cl /TP /c -### -- %s 2>&1 | FileCheck -check-prefix=NO-GX %s
end_comment

begin_comment
comment|// NO-GX-NOT: "-fcxx-exceptions" "-fexceptions"
end_comment

begin_comment
comment|// RUN: %clang_cl /TP /c /GX -### -- %s 2>&1 | FileCheck -check-prefix=GX %s
end_comment

begin_comment
comment|// GX: "-fcxx-exceptions" "-fexceptions"
end_comment

begin_comment
comment|// RUN: %clang_cl /TP /c /GX /GX- -### -- %s 2>&1 | FileCheck -check-prefix=GX_ %s
end_comment

begin_comment
comment|// GX_-NOT: "-fcxx-exceptions" "-fexceptions"
end_comment

begin_comment
comment|// We forward any unrecognized -W diagnostic options to cc1.
end_comment

begin_comment
comment|// RUN: %clang_cl -Wunused-pragmas -### -- %s 2>&1 | FileCheck -check-prefix=WJoined %s
end_comment

begin_comment
comment|// WJoined: "-cc1"
end_comment

begin_comment
comment|// WJoined: "-Wunused-pragmas"
end_comment

begin_comment
comment|// We recognize -f[no-]strict-aliasing.
end_comment

begin_comment
comment|// RUN: %clang_cl -c -### -- %s 2>&1 | FileCheck -check-prefix=DEFAULTSTRICT %s
end_comment

begin_comment
comment|// DEFAULTSTRICT: "-relaxed-aliasing"
end_comment

begin_comment
comment|// RUN: %clang_cl -c -fstrict-aliasing -### -- %s 2>&1 | FileCheck -check-prefix=STRICT %s
end_comment

begin_comment
comment|// STRICT-NOT: "-relaxed-aliasing"
end_comment

begin_comment
comment|// RUN: %clang_cl -c -fno-strict-aliasing -### -- %s 2>&1 | FileCheck -check-prefix=NOSTRICT %s
end_comment

begin_comment
comment|// NOSTRICT: "-relaxed-aliasing"
end_comment

begin_comment
comment|// We recognize -f[no-]delayed-template-parsing.
end_comment

begin_comment
comment|// /Zc:twoPhase[-] has the opposite meaning.
end_comment

begin_comment
comment|// RUN: %clang_cl -c -### -- %s 2>&1 | FileCheck -check-prefix=DELAYEDDEFAULT %s
end_comment

begin_comment
comment|// DELAYEDDEFAULT: "-fdelayed-template-parsing"
end_comment

begin_comment
comment|// RUN: %clang_cl -c -fdelayed-template-parsing -### -- %s 2>&1 | FileCheck -check-prefix=DELAYEDON %s
end_comment

begin_comment
comment|// RUN: %clang_cl -c /Zc:twoPhase- -### -- %s 2>&1 | FileCheck -check-prefix=DELAYEDON %s
end_comment

begin_comment
comment|// DELAYEDON: "-fdelayed-template-parsing"
end_comment

begin_comment
comment|// RUN: %clang_cl -c -fno-delayed-template-parsing -### -- %s 2>&1 | FileCheck -check-prefix=DELAYEDOFF %s
end_comment

begin_comment
comment|// RUN: %clang_cl -c /Zc:twoPhase -### -- %s 2>&1 | FileCheck -check-prefix=DELAYEDOFF %s
end_comment

begin_comment
comment|// DELAYEDOFF-NOT: "-fdelayed-template-parsing"
end_comment

begin_comment
comment|// For some warning ids, we can map from MSVC warning to Clang warning.
end_comment

begin_comment
comment|// RUN: %clang_cl -wd4005 -wd4100 -wd4910 -wd4996 -### -- %s 2>&1 | FileCheck -check-prefix=Wno %s
end_comment

begin_comment
comment|// Wno: "-cc1"
end_comment

begin_comment
comment|// Wno: "-Wno-macro-redefined"
end_comment

begin_comment
comment|// Wno: "-Wno-unused-parameter"
end_comment

begin_comment
comment|// Wno: "-Wno-dllexport-explicit-instantiation-decl"
end_comment

begin_comment
comment|// Wno: "-Wno-deprecated-declarations"
end_comment

begin_comment
comment|// Ignored options. Check that we don't get "unused during compilation" errors.
end_comment

begin_comment
comment|// RUN: %clang_cl /c \
end_comment

begin_comment
comment|// RUN:    /analyze- \
end_comment

begin_comment
comment|// RUN:    /bigobj \
end_comment

begin_comment
comment|// RUN:    /cgthreads4 \
end_comment

begin_comment
comment|// RUN:    /cgthreads8 \
end_comment

begin_comment
comment|// RUN:    /d2FastFail \
end_comment

begin_comment
comment|// RUN:    /d2Zi+ \
end_comment

begin_comment
comment|// RUN:    /errorReport:foo \
end_comment

begin_comment
comment|// RUN:    /execution-charset:utf-8 \
end_comment

begin_comment
comment|// RUN:    /FC \
end_comment

begin_comment
comment|// RUN:    /Fdfoo \
end_comment

begin_comment
comment|// RUN:    /FS \
end_comment

begin_comment
comment|// RUN:    /Gd \
end_comment

begin_comment
comment|// RUN:    /GF \
end_comment

begin_comment
comment|// RUN:    /GS- \
end_comment

begin_comment
comment|// RUN:    /kernel- \
end_comment

begin_comment
comment|// RUN:    /nologo \
end_comment

begin_comment
comment|// RUN:    /openmp- \
end_comment

begin_comment
comment|// RUN:    /RTC1 \
end_comment

begin_comment
comment|// RUN:    /sdl \
end_comment

begin_comment
comment|// RUN:    /sdl- \
end_comment

begin_comment
comment|// RUN:    /source-charset:utf-8 \
end_comment

begin_comment
comment|// RUN:    /utf-8 \
end_comment

begin_comment
comment|// RUN:    /vmg \
end_comment

begin_comment
comment|// RUN:    /volatile:iso \
end_comment

begin_comment
comment|// RUN:    /w12345 \
end_comment

begin_comment
comment|// RUN:    /wd1234 \
end_comment

begin_comment
comment|// RUN:    /Zo \
end_comment

begin_comment
comment|// RUN:    /Zo- \
end_comment

begin_comment
comment|// RUN:    -### -- %s 2>&1 | FileCheck -check-prefix=IGNORED %s
end_comment

begin_comment
comment|// IGNORED-NOT: argument unused during compilation
end_comment

begin_comment
comment|// IGNORED-NOT: no such file or directory
end_comment

begin_comment
comment|// Don't confuse /openmp- with the /o flag:
end_comment

begin_comment
comment|// IGNORED-NOT: "-o" "penmp-.obj"
end_comment

begin_comment
comment|// Ignored options and compile-only options are ignored for link jobs.
end_comment

begin_comment
comment|// RUN: touch %t.obj
end_comment

begin_comment
comment|// RUN: %clang_cl /nologo -### -- %t.obj 2>&1 | FileCheck -check-prefix=LINKUNUSED %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Dfoo -### -- %t.obj 2>&1 | FileCheck -check-prefix=LINKUNUSED %s
end_comment

begin_comment
comment|// RUN: %clang_cl /MD -### -- %t.obj 2>&1 | FileCheck -check-prefix=LINKUNUSED %s
end_comment

begin_comment
comment|// LINKUNUSED-NOT: argument unused during compilation
end_comment

begin_comment
comment|// Support ignoring warnings about unused arguments.
end_comment

begin_comment
comment|// RUN: %clang_cl /Abracadabra -Qunused-arguments -### -- %s 2>&1 | FileCheck -check-prefix=UNUSED %s
end_comment

begin_comment
comment|// UNUSED-NOT: argument unused during compilation
end_comment

begin_comment
comment|// Unsupported but parsed options. Check that we don't error on them.
end_comment

begin_comment
comment|// (/Zs is for syntax-only)
end_comment

begin_comment
comment|// RUN: %clang_cl /Zs \
end_comment

begin_comment
comment|// RUN:     /AIfoo \
end_comment

begin_comment
comment|// RUN:     /clr:pure \
end_comment

begin_comment
comment|// RUN:     /docname \
end_comment

begin_comment
comment|// RUN:     /EHsc \
end_comment

begin_comment
comment|// RUN:     /F \
end_comment

begin_comment
comment|// RUN:     /FA \
end_comment

begin_comment
comment|// RUN:     /FAc \
end_comment

begin_comment
comment|// RUN:     /Fafilename \
end_comment

begin_comment
comment|// RUN:     /FAs \
end_comment

begin_comment
comment|// RUN:     /FAu \
end_comment

begin_comment
comment|// RUN:     /favor:blend \
end_comment

begin_comment
comment|// RUN:     /Fifoo \
end_comment

begin_comment
comment|// RUN:     /Fmfoo \
end_comment

begin_comment
comment|// RUN:     /FpDebug\main.pch \
end_comment

begin_comment
comment|// RUN:     /Frfoo \
end_comment

begin_comment
comment|// RUN:     /FRfoo \
end_comment

begin_comment
comment|// RUN:     /FU foo \
end_comment

begin_comment
comment|// RUN:     /Fx \
end_comment

begin_comment
comment|// RUN:     /G1 \
end_comment

begin_comment
comment|// RUN:     /G2 \
end_comment

begin_comment
comment|// RUN:     /GA \
end_comment

begin_comment
comment|// RUN:     /Gd \
end_comment

begin_comment
comment|// RUN:     /Ge \
end_comment

begin_comment
comment|// RUN:     /Gh \
end_comment

begin_comment
comment|// RUN:     /GH \
end_comment

begin_comment
comment|// RUN:     /GL \
end_comment

begin_comment
comment|// RUN:     /GL- \
end_comment

begin_comment
comment|// RUN:     /Gm \
end_comment

begin_comment
comment|// RUN:     /Gm- \
end_comment

begin_comment
comment|// RUN:     /Gr \
end_comment

begin_comment
comment|// RUN:     /GS \
end_comment

begin_comment
comment|// RUN:     /GT \
end_comment

begin_comment
comment|// RUN:     /guard:cf \
end_comment

begin_comment
comment|// RUN:     /guard:cf- \
end_comment

begin_comment
comment|// RUN:     /GX \
end_comment

begin_comment
comment|// RUN:     /Gv \
end_comment

begin_comment
comment|// RUN:     /Gz \
end_comment

begin_comment
comment|// RUN:     /GZ \
end_comment

begin_comment
comment|// RUN:     /H \
end_comment

begin_comment
comment|// RUN:     /homeparams \
end_comment

begin_comment
comment|// RUN:     /hotpatch \
end_comment

begin_comment
comment|// RUN:     /kernel \
end_comment

begin_comment
comment|// RUN:     /LN \
end_comment

begin_comment
comment|// RUN:     /MP \
end_comment

begin_comment
comment|// RUN:     /o foo.obj \
end_comment

begin_comment
comment|// RUN:     /ofoo.obj \
end_comment

begin_comment
comment|// RUN:     /openmp \
end_comment

begin_comment
comment|// RUN:     /Qfast_transcendentals \
end_comment

begin_comment
comment|// RUN:     /QIfist \
end_comment

begin_comment
comment|// RUN:     /Qimprecise_fwaits \
end_comment

begin_comment
comment|// RUN:     /Qpar \
end_comment

begin_comment
comment|// RUN:     /Qvec-report:2 \
end_comment

begin_comment
comment|// RUN:     /u \
end_comment

begin_comment
comment|// RUN:     /V \
end_comment

begin_comment
comment|// RUN:     /volatile:ms \
end_comment

begin_comment
comment|// RUN:     /wfoo \
end_comment

begin_comment
comment|// RUN:     /WL \
end_comment

begin_comment
comment|// RUN:     /Wp64 \
end_comment

begin_comment
comment|// RUN:     /X \
end_comment

begin_comment
comment|// RUN:     /Y- \
end_comment

begin_comment
comment|// RUN:     /Yc \
end_comment

begin_comment
comment|// RUN:     /Ycstdafx.h \
end_comment

begin_comment
comment|// RUN:     /Yd \
end_comment

begin_comment
comment|// RUN:     /Yl- \
end_comment

begin_comment
comment|// RUN:     /Ylfoo \
end_comment

begin_comment
comment|// RUN:     /Yustdafx.h \
end_comment

begin_comment
comment|// RUN:     /Z7 \
end_comment

begin_comment
comment|// RUN:     /Za \
end_comment

begin_comment
comment|// RUN:     /Ze \
end_comment

begin_comment
comment|// RUN:     /Zg \
end_comment

begin_comment
comment|// RUN:     /Zi \
end_comment

begin_comment
comment|// RUN:     /ZI \
end_comment

begin_comment
comment|// RUN:     /Zl \
end_comment

begin_comment
comment|// RUN:     /ZW:nostdlib \
end_comment

begin_comment
comment|// RUN:     -- %s 2>&1
end_comment

begin_comment
comment|// We support -Xclang for forwarding options to cc1.
end_comment

begin_comment
comment|// RUN: %clang_cl -Xclang hellocc1 -### -- %s 2>&1 | FileCheck -check-prefix=Xclang %s
end_comment

begin_comment
comment|// Xclang: "-cc1"
end_comment

begin_comment
comment|// Xclang: "hellocc1"
end_comment

begin_comment
comment|// Files under /Users are often confused with the /U flag. (This could happen
end_comment

begin_comment
comment|// for other flags too, but this is the one people run into.)
end_comment

begin_comment
comment|// RUN: %clang_cl /c /Users/me/myfile.c -### 2>&1 | FileCheck -check-prefix=SlashU %s
end_comment

begin_comment
comment|// SlashU: warning: '/Users/me/myfile.c' treated as the '/U' option
end_comment

begin_comment
comment|// SlashU: note: Use '--' to treat subsequent arguments as filenames
end_comment

begin_comment
comment|// RTTI is on by default. /GR- controls -fno-rtti-data.
end_comment

begin_comment
comment|// RUN: %clang_cl /c /GR- -### -- %s 2>&1 | FileCheck -check-prefix=NoRTTI %s
end_comment

begin_comment
comment|// NoRTTI: "-fno-rtti-data"
end_comment

begin_comment
comment|// NoRTTI-NOT: "-fno-rtti"
end_comment

begin_comment
comment|// RUN: %clang_cl /c /GR -### -- %s 2>&1 | FileCheck -check-prefix=RTTI %s
end_comment

begin_comment
comment|// RTTI-NOT: "-fno-rtti-data"
end_comment

begin_comment
comment|// RTTI-NOT: "-fno-rtti"
end_comment

begin_comment
comment|// thread safe statics are off for versions< 19.
end_comment

begin_comment
comment|// RUN: %clang_cl /c -### -fms-compatibility-version=18 -- %s 2>&1 | FileCheck -check-prefix=NoThreadSafeStatics %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Zc:threadSafeInit /Zc:threadSafeInit- /c -### -- %s 2>&1 | FileCheck -check-prefix=NoThreadSafeStatics %s
end_comment

begin_comment
comment|// NoThreadSafeStatics: "-fno-threadsafe-statics"
end_comment

begin_comment
comment|// RUN: %clang_cl /Zc:threadSafeInit /c -### -- %s 2>&1 | FileCheck -check-prefix=ThreadSafeStatics %s
end_comment

begin_comment
comment|// ThreadSafeStatics-NOT: "-fno-threadsafe-statics"
end_comment

begin_comment
comment|// RUN: %clang_cl /Zi /c -### -- %s 2>&1 | FileCheck -check-prefix=Zi %s
end_comment

begin_comment
comment|// Zi: "-gcodeview"
end_comment

begin_comment
comment|// Zi: "-debug-info-kind=limited"
end_comment

begin_comment
comment|// RUN: %clang_cl /Z7 /c -### -- %s 2>&1 | FileCheck -check-prefix=Z7 %s
end_comment

begin_comment
comment|// Z7: "-gcodeview"
end_comment

begin_comment
comment|// Z7: "-debug-info-kind=limited"
end_comment

begin_comment
comment|// RUN: %clang_cl /Zd /c -### -- %s 2>&1 | FileCheck -check-prefix=Z7GMLT %s
end_comment

begin_comment
comment|// Z7GMLT: "-gcodeview"
end_comment

begin_comment
comment|// Z7GMLT: "-debug-info-kind=line-tables-only"
end_comment

begin_comment
comment|// RUN: %clang_cl -gline-tables-only /c -### -- %s 2>&1 | FileCheck -check-prefix=ZGMLT %s
end_comment

begin_comment
comment|// ZGMLT: "-gcodeview"
end_comment

begin_comment
comment|// ZGMLT: "-debug-info-kind=line-tables-only"
end_comment

begin_comment
comment|// RUN: %clang_cl /c -### -- %s 2>&1 | FileCheck -check-prefix=BreproDefault %s
end_comment

begin_comment
comment|// BreproDefault: "-mincremental-linker-compatible"
end_comment

begin_comment
comment|// RUN: %clang_cl /Brepro- /Brepro /c '-###' -- %s 2>&1 | FileCheck -check-prefix=Brepro %s
end_comment

begin_comment
comment|// Brepro-NOT: "-mincremental-linker-compatible"
end_comment

begin_comment
comment|// RUN: %clang_cl /Brepro /Brepro- /c '-###' -- %s 2>&1 | FileCheck -check-prefix=Brepro_ %s
end_comment

begin_comment
comment|// Brepro_: "-mincremental-linker-compatible"
end_comment

begin_comment
comment|// This test was super sneaky: "/Z7" means "line-tables", but "-gdwarf" occurs
end_comment

begin_comment
comment|// later on the command line, so it should win. Interestingly the cc1 arguments
end_comment

begin_comment
comment|// came out right, but had wrong semantics, because an invariant assumed by
end_comment

begin_comment
comment|// CompilerInvocation was violated: it expects that at most one of {gdwarfN,
end_comment

begin_comment
comment|// line-tables-only} appear. If you assume that, then you can safely use
end_comment

begin_comment
comment|// Args.hasArg to test whether a boolean flag is present without caring
end_comment

begin_comment
comment|// where it appeared. And for this test, it appeared to the left of -gdwarf
end_comment

begin_comment
comment|// which made it "win". This test could not detect that bug.
end_comment

begin_comment
comment|// RUN: %clang_cl /Z7 -gdwarf /c -### -- %s 2>&1 | FileCheck -check-prefix=Z7_gdwarf %s
end_comment

begin_comment
comment|// Z7_gdwarf: "-gcodeview"
end_comment

begin_comment
comment|// Z7_gdwarf: "-debug-info-kind=limited"
end_comment

begin_comment
comment|// Z7_gdwarf: "-dwarf-version=4"
end_comment

begin_comment
comment|// RUN: %clang_cl -fmsc-version=1800 -TP -### -- %s 2>&1 | FileCheck -check-prefix=CXX11 %s
end_comment

begin_comment
comment|// CXX11: -std=c++11
end_comment

begin_comment
comment|// RUN: %clang_cl -fmsc-version=1900 -TP -### -- %s 2>&1 | FileCheck -check-prefix=CXX14 %s
end_comment

begin_comment
comment|// CXX14: -std=c++14
end_comment

begin_comment
comment|// RUN: %clang_cl -fmsc-version=1900 -TP -std:c++14 -### -- %s 2>&1 | FileCheck -check-prefix=STDCXX14 %s
end_comment

begin_comment
comment|// STDCXX14: -std=c++14
end_comment

begin_comment
comment|// RUN: %clang_cl -fmsc-version=1900 -TP -std:c++latest -### -- %s 2>&1 | FileCheck -check-prefix=STDCXXLATEST %s
end_comment

begin_comment
comment|// STDCXXLATEST: -std=c++1z
end_comment

begin_comment
comment|// RUN: env CL="/Gy" %clang_cl -### -- %s 2>&1 | FileCheck -check-prefix=ENV-CL %s
end_comment

begin_comment
comment|// ENV-CL: "-ffunction-sections"
end_comment

begin_comment
comment|// RUN: env CL="/Gy" _CL_="/Gy- -- %s" %clang_cl -### 2>&1 | FileCheck -check-prefix=ENV-_CL_ %s
end_comment

begin_comment
comment|// ENV-_CL_-NOT: "-ffunction-sections"
end_comment

begin_comment
comment|// RUN: env CL="%s" _CL_="%s" not %clang --rsp-quoting=windows -c
end_comment

begin_comment
comment|// RUN: %clang_cl -### /c -flto -- %s 2>&1 | FileCheck -check-prefix=LTO %s
end_comment

begin_comment
comment|// LTO: -flto
end_comment

begin_comment
comment|// RUN: %clang_cl -### /c -flto=thin -- %s 2>&1 | FileCheck -check-prefix=LTO-THIN %s
end_comment

begin_comment
comment|// LTO-THIN: -flto=thin
end_comment

begin_comment
comment|// RUN: %clang_cl -### -Fe%t.exe -entry:main -flto -- %s 2>&1 | FileCheck -check-prefix=LTO-WITHOUT-LLD %s
end_comment

begin_comment
comment|// LTO-WITHOUT-LLD: LTO requires -fuse-ld=lld
end_comment

begin_comment
comment|// Accept "core" clang options.
end_comment

begin_comment
comment|// (/Zs is for syntax-only, -Werror makes it fail hard on unknown options)
end_comment

begin_comment
comment|// RUN: %clang_cl \
end_comment

begin_comment
comment|// RUN:     --driver-mode=cl \
end_comment

begin_comment
comment|// RUN:     -fcolor-diagnostics \
end_comment

begin_comment
comment|// RUN:     -fno-color-diagnostics \
end_comment

begin_comment
comment|// RUN:     -fdiagnostics-color \
end_comment

begin_comment
comment|// RUN:     -fno-diagnostics-color \
end_comment

begin_comment
comment|// RUN:     -fdiagnostics-parseable-fixits \
end_comment

begin_comment
comment|// RUN:     -fdiagnostics-absolute-paths \
end_comment

begin_comment
comment|// RUN:     -ferror-limit=10 \
end_comment

begin_comment
comment|// RUN:     -fmsc-version=1800 \
end_comment

begin_comment
comment|// RUN:     -fno-strict-aliasing \
end_comment

begin_comment
comment|// RUN:     -fstrict-aliasing \
end_comment

begin_comment
comment|// RUN:     -fsyntax-only \
end_comment

begin_comment
comment|// RUN:     -fms-compatibility \
end_comment

begin_comment
comment|// RUN:     -fno-ms-compatibility \
end_comment

begin_comment
comment|// RUN:     -fms-extensions \
end_comment

begin_comment
comment|// RUN:     -fno-ms-extensions \
end_comment

begin_comment
comment|// RUN:     -Xclang -disable-llvm-passes \
end_comment

begin_comment
comment|// RUN:     -resource-dir asdf \
end_comment

begin_comment
comment|// RUN:     -resource-dir=asdf \
end_comment

begin_comment
comment|// RUN:     -Wunused-variable \
end_comment

begin_comment
comment|// RUN:     -fmacro-backtrace-limit=0 \
end_comment

begin_comment
comment|// RUN:     -fstandalone-debug \
end_comment

begin_comment
comment|// RUN:     -flimit-debug-info \
end_comment

begin_comment
comment|// RUN:     -flto \
end_comment

begin_comment
comment|// RUN:     -Werror /Zs -- %s 2>&1
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{ }
end_function

end_unit

