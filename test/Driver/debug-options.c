begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check to make sure clang is somewhat picky about -g options.
end_comment

begin_comment
comment|// rdar://10383444
end_comment

begin_comment
comment|// Linux.
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G -check-prefix=G_GDB %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g2 %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g3 %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G -check-prefix=G_GDB %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb1 %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY -check-prefix=G_GDB %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb3 %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -glldb %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G -check-prefix=G_LLDB %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gsce %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// Darwin.
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G -check-prefix=G_SCE %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target x86_64-apple-darwin 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF2 \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_LLDB %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target x86_64-apple-darwin16 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF4 \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_LLDB %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g2 %s -target x86_64-apple-darwin16 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF4 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g3 %s -target x86_64-apple-darwin16 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF4 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb %s -target x86_64-apple-darwin16 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF4 \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_GDB %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb1 %s -target x86_64-apple-darwin16 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb3 %s -target x86_64-apple-darwin16 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF4 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target x86_64-apple-macosx10.11 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF4 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target x86_64-apple-macosx10.10 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_ONLY_DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target armv7-apple-ios9.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF4 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target armv7-apple-ios8.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_ONLY_DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target armv7k-apple-watchos 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF4 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target arm64-apple-tvos9.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE \
end_comment

begin_comment
comment|// RUN:                         -check-prefix=G_DWARF4 %s
end_comment

begin_comment
comment|// FreeBSD.
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target x86_64-pc-freebsd10.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_GDB %s
end_comment

begin_comment
comment|// On the PS4, -g defaults to -gno-column-info, and we always generate the
end_comment

begin_comment
comment|// arange section.
end_comment

begin_comment
comment|// RUN: %clang -### -c %s -target x86_64-scei-ps4 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=NOG_PS4 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c %s -g -target x86_64-scei-ps4 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_PS4 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c %s -g -target x86_64-scei-ps4 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_SCE %s
end_comment

begin_comment
comment|// RUN: %clang -### -c %s -g -target x86_64-scei-ps4 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=NOCI %s
end_comment

begin_comment
comment|// RUN: %clang -### -c %s -g -gcolumn-info -target x86_64-scei-ps4 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=CI %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gdwarf-2 %s 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_ONLY_DWARF2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -c -gfoo %s 2>&1 | FileCheck -check-prefix=G_NO %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g -g0 %s 2>&1 | FileCheck -check-prefix=G_NO %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb0 %s 2>&1 | FileCheck -check-prefix=G_NO %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -glldb -g0 %s 2>&1 | FileCheck -check-prefix=G_NO %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -glldb -g1 %s 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY -check-prefix=G_LLDB %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PS4 defaults to sce; -ggdb0 changes tuning but turns off debug info,
end_comment

begin_comment
comment|// then -g turns it back on without affecting tuning.
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb0 -g -target x86_64-scei-ps4 %s 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G -check-prefix=G_GDB %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -c -g1 %s 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gmlt %s 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only %s -target x86_64-apple-darwin 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only %s -target i686-pc-openbsd 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY_DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only %s -target x86_64-pc-freebsd10.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY_DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only -g %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_ONLY %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only -g %s -target x86_64-apple-darwin16 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_STANDALONE -check-prefix=G_DWARF4 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only -g %s -target i686-pc-openbsd 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_ONLY_DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only -g %s -target x86_64-pc-freebsd10.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_ONLY_DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only -g %s -target i386-pc-solaris 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_ONLY_DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only -g0 %s 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_NO %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -c -grecord-gcc-switches %s 2>&1 \
end_comment

begin_comment
comment|//             | FileCheck -check-prefix=GRECORD %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gno-record-gcc-switches %s 2>&1 \
end_comment

begin_comment
comment|//             | FileCheck -check-prefix=GNO_RECORD %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -grecord-gcc-switches -gno-record-gcc-switches %s 2>&1 \
end_comment

begin_comment
comment|//             | FileCheck -check-prefix=GNO_RECORD %s/
end_comment

begin_comment
comment|// RUN: %clang -### -c -grecord-gcc-switches -o - %s 2>&1 \
end_comment

begin_comment
comment|//             | FileCheck -check-prefix=GRECORD_O %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -O3 -ffunction-sections -grecord-gcc-switches %s 2>&1 \
end_comment

begin_comment
comment|//             | FileCheck -check-prefix=GRECORD_OPT %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -c -gstrict-dwarf -gno-strict-dwarf %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=GIGNORE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggnu-pubnames %s 2>&1 | FileCheck -check-prefix=GOPT %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -c -gdwarf-aranges %s 2>&1 | FileCheck -check-prefix=GARANGE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fdebug-types-section %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=FDTS %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fdebug-types-section -fno-debug-types-section %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=NOFDTS %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -g -gno-column-info %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=NOCI %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -g -target x86_64-unknown-unknown %s 2>&1 \
end_comment

begin_comment
comment|//             | FileCheck -check-prefix=CI %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -gmodules %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=GEXTREFS %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -gmodules -g %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=GEXTREFS %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -gline-tables-only -gmodules %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=GEXTREFS %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -gmodules -gline-tables-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=GLTO_ONLY %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G: "-cc1"
end_comment

begin_comment
comment|// G: "-debug-info-kind=limited"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOG_PS4: "-cc1"
end_comment

begin_comment
comment|// NOG_PS4-NOT "-dwarf-version=
end_comment

begin_comment
comment|// NOG_PS4: "-generate-arange-section"
end_comment

begin_comment
comment|// NOG_PS4-NOT: "-dwarf-version=
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_PS4: "-cc1"
end_comment

begin_comment
comment|// G_PS4: "-dwarf-version=
end_comment

begin_comment
comment|// G_PS4: "-generate-arange-section"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_NO: "-cc1"
end_comment

begin_comment
comment|// G_NO-NOT: -debug-info-kind=
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GLTO_ONLY: "-cc1"
end_comment

begin_comment
comment|// GLTO_ONLY-NOT: "-dwarf-ext-refs"
end_comment

begin_comment
comment|// GLTO_ONLY: "-debug-info-kind=line-tables-only"
end_comment

begin_comment
comment|// GLTO_ONLY-NOT: "-dwarf-ext-refs"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GLTO_ONLY_DWARF2: "-cc1"
end_comment

begin_comment
comment|// GLTO_ONLY_DWARF2: "-debug-info-kind=line-tables-only"
end_comment

begin_comment
comment|// GLTO_ONLY_DWARF2: "-dwarf-version=2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_ONLY: "-cc1"
end_comment

begin_comment
comment|// G_ONLY: "-debug-info-kind=limited"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These tests assert that "-gline-tables-only" "-g" uses the latter,
end_comment

begin_comment
comment|// but otherwise not caring about the DebugInfoKind.
end_comment

begin_comment
comment|// G_ONLY_DWARF2: "-cc1"
end_comment

begin_comment
comment|// G_ONLY_DWARF2: "-debug-info-kind={{standalone|limited}}"
end_comment

begin_comment
comment|// G_ONLY_DWARF2: "-dwarf-version=2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_STANDALONE: "-cc1"
end_comment

begin_comment
comment|// G_STANDALONE: "-debug-info-kind=standalone"
end_comment

begin_comment
comment|// G_DWARF4: "-dwarf-version=4"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_GDB:  "-debugger-tuning=gdb"
end_comment

begin_comment
comment|// G_LLDB: "-debugger-tuning=lldb"
end_comment

begin_comment
comment|// G_SCE:  "-debugger-tuning=sce"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This tests asserts that "-gline-tables-only" "-g0" disables debug info.
end_comment

begin_comment
comment|// GLTO_NO: "-cc1"
end_comment

begin_comment
comment|// GLTO_NO-NOT: -debug-info-kind=
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GRECORD: "-dwarf-debug-flags"
end_comment

begin_comment
comment|// GRECORD: -### -c -grecord-gcc-switches
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GNO_RECORD-NOT: "-dwarf-debug-flags"
end_comment

begin_comment
comment|// GNO_RECORD-NOT: -### -c -grecord-gcc-switches
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GRECORD_O: "-dwarf-debug-flags"
end_comment

begin_comment
comment|// GRECORD_O: -### -c -grecord-gcc-switches -o -
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GRECORD_OPT: -### -c -O3 -ffunction-sections -grecord-gcc-switches
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GIGNORE-NOT: "argument unused during compilation"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GOPT: -generate-gnu-dwarf-pub-sections
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GARANGE: -generate-arange-section
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FDTS: "-backend-option" "-generate-type-units"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOFDTS-NOT: "-backend-option" "-generate-type-units"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CI: "-dwarf-column-info"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOCI-NOT: "-dwarf-column-info"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GEXTREFS: "-dwarf-ext-refs" "-fmodule-format=obj" "-debug-info-kind={{standalone|limited}}"
end_comment

begin_comment
comment|// RUN: not %clang -cc1 -debug-info-kind=watkind 2>&1 | FileCheck -check-prefix=BADSTRING1 %s
end_comment

begin_comment
comment|// BADSTRING1: error: invalid value 'watkind' in '-debug-info-kind=watkind'
end_comment

begin_comment
comment|// RUN: not %clang -cc1 -debugger-tuning=gmodal 2>&1 | FileCheck -check-prefix=BADSTRING2 %s
end_comment

begin_comment
comment|// BADSTRING2: error: invalid value 'gmodal' in '-debugger-tuning=gmodal'
end_comment

begin_comment
comment|// RUN: %clang -### -fdebug-macro    %s 2>&1 | FileCheck -check-prefix=MACRO %s
end_comment

begin_comment
comment|// RUN: %clang -### -fno-debug-macro %s 2>&1 | FileCheck -check-prefix=NOMACRO %s
end_comment

begin_comment
comment|// RUN: %clang -###                  %s 2>&1 | FileCheck -check-prefix=NOMACRO %s
end_comment

begin_comment
comment|// MACRO: "-debug-info-macro"
end_comment

begin_comment
comment|// NOMACRO-NOT: "-debug-info-macro"
end_comment

end_unit

