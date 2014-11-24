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
comment|// RUN: %clang_cl /Dfoo=bar -### -- %s 2>&1 | FileCheck -check-prefix=D %s
end_comment

begin_comment
comment|// RUN: %clang_cl /D foo=bar -### -- %s 2>&1 | FileCheck -check-prefix=D %s
end_comment

begin_comment
comment|// D: "-D" "foo=bar"
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
comment|// RUN: %clang_cl /J -### -- %s 2>&1 | FileCheck -check-prefix=J %s
end_comment

begin_comment
comment|// J: -fno-signed-char
end_comment

begin_comment
comment|// RUN: %clang_cl /Ofoo -### -- %s 2>&1 | FileCheck -check-prefix=O %s
end_comment

begin_comment
comment|// O: -Ofoo
end_comment

begin_comment
comment|// RUN: %clang_cl /Ob0 -### -- %s 2>&1 | FileCheck -check-prefix=Ob0 %s
end_comment

begin_comment
comment|// Ob0: -fno-inline
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
comment|// RUN: %clang_cl /Os -### -- %s 2>&1 | FileCheck -check-prefix=Os %s
end_comment

begin_comment
comment|// Os: -Os
end_comment

begin_comment
comment|// RUN: %clang_cl /Ot -### -- %s 2>&1 | FileCheck -check-prefix=Ot %s
end_comment

begin_comment
comment|// Ot: -O2
end_comment

begin_comment
comment|// RUN: %clang_cl /Ox -### -- %s 2>&1 | FileCheck -check-prefix=Ox %s
end_comment

begin_comment
comment|// Ox: -O3
end_comment

begin_comment
comment|// RUN: %clang_cl /Zs /Oy -- %s 2>&1
end_comment

begin_comment
comment|// RUN: %clang_cl /Oy- -### -- %s 2>&1 | FileCheck -check-prefix=Oy_ %s
end_comment

begin_comment
comment|// Oy_: -mdisable-fp-elim
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
comment|// RUN: %clang_cl /Umymacro -### -- %s 2>&1 | FileCheck -check-prefix=U %s
end_comment

begin_comment
comment|// RUN: %clang_cl /U mymacro -### -- %s 2>&1 | FileCheck -check-prefix=U %s
end_comment

begin_comment
comment|// U: "-U" "mymacro"
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
comment|// RUN: %clang_cl /W4 -### -- %s 2>&1 | FileCheck -check-prefix=W1 %s
end_comment

begin_comment
comment|// RUN: %clang_cl /Wall -### -- %s 2>&1 | FileCheck -check-prefix=W1 %s
end_comment

begin_comment
comment|// W1: -Wall
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
comment|// For some warning ids, we can map from MSVC warning to Clang warning.
end_comment

begin_comment
comment|// RUN: %clang_cl -wd4005 -### -- %s 2>&1 | FileCheck -check-prefix=wd4005 %s
end_comment

begin_comment
comment|// wd4005: "-cc1"
end_comment

begin_comment
comment|// wd4005: "-Wno-macro-redefined"
end_comment

begin_comment
comment|// Ignored options. Check that we don't get "unused during compilation" errors.
end_comment

begin_comment
comment|// (/Zs is for syntax-only)
end_comment

begin_comment
comment|// RUN: %clang_cl /Zs \
end_comment

begin_comment
comment|// RUN:    /analyze- \
end_comment

begin_comment
comment|// RUN:    /errorReport:foo \
end_comment

begin_comment
comment|// RUN:    /FS \
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
comment|// RUN:    /Ob1 \
end_comment

begin_comment
comment|// RUN:    /Ob2 \
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
comment|// RUN:    /vmg \
end_comment

begin_comment
comment|// RUN:    /w12345 \
end_comment

begin_comment
comment|// RUN:    /wd1234 \
end_comment

begin_comment
comment|// RUN:    /Zc:forScope \
end_comment

begin_comment
comment|// RUN:    /Zc:wchar_t \
end_comment

begin_comment
comment|// RUN:    /Zc:inline \
end_comment

begin_comment
comment|// RUN:    /Zc:rvalueCast \
end_comment

begin_comment
comment|// RUN:    -### -- %s 2>&1 | FileCheck -check-prefix=IGNORED %s
end_comment

begin_comment
comment|// IGNORED-NOT: argument unused during compilation
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
comment|// RUN:     /d2Zi+ \
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
comment|// RUN:     /FC \
end_comment

begin_comment
comment|// RUN:     /Fdfoo \
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
comment|// RUN:     /fp:precise \
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
comment|// RUN:     /Gs1000 \
end_comment

begin_comment
comment|// RUN:     /GT \
end_comment

begin_comment
comment|// RUN:     /GX \
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
comment|// RUN:     /volatile \
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
comment|// RUN:     /Zc:auto \
end_comment

begin_comment
comment|// RUN:     /Zc:wchar_t- \
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
comment|// RUN:     /Zp \
end_comment

begin_comment
comment|// RUN:     /Zp1 \
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
comment|// Accept "core" clang options.
end_comment

begin_comment
comment|// (/Zs is for syntax-only)
end_comment

begin_comment
comment|// RUN: %clang_cl \
end_comment

begin_comment
comment|// RUN:     --driver-mode=cl \
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
comment|// RUN:     -mllvm -disable-llvm-optzns \
end_comment

begin_comment
comment|// RUN:     -Wunused-variables \
end_comment

begin_comment
comment|// RUN:     /Zs -- %s 2>&1
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{ }
end_function

end_unit

