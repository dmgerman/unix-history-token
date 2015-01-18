begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check to make sure clang is somewhat picky about -g options.
end_comment

begin_comment
comment|// rdar://10383444
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s -target x86_64-linux-gnu 2>&1 \
end_comment

begin_expr_stmt
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G
operator|%
name|s
comment|// RUN: %clang -### -c -g2 %s -target x86_64-linux-gnu 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G
operator|%
name|s
comment|// RUN: %clang -### -c -g3 %s -target x86_64-linux-gnu 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G
operator|%
name|s
comment|// RUN: %clang -### -c -ggdb %s -target x86_64-linux-gnu 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G
operator|%
name|s
comment|// RUN: %clang -### -c -ggdb1 %s -target x86_64-linux-gnu 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G
operator|%
name|s
comment|// RUN: %clang -### -c -ggdb3 %s -target x86_64-linux-gnu 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G
operator|%
name|s
comment|// RUN: %clang -### -c -g %s -target x86_64-apple-darwin 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G_DARWIN
operator|%
name|s
comment|// RUN: %clang -### -c -g2 %s -target x86_64-apple-darwin 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G_DARWIN
operator|%
name|s
comment|// RUN: %clang -### -c -g3 %s -target x86_64-apple-darwin 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G_DARWIN
operator|%
name|s
comment|// RUN: %clang -### -c -ggdb %s -target x86_64-apple-darwin 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G_DARWIN
operator|%
name|s
comment|// RUN: %clang -### -c -ggdb1 %s -target x86_64-apple-darwin 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G_DARWIN
operator|%
name|s
comment|// RUN: %clang -### -c -ggdb3 %s -target x86_64-apple-darwin 2>&1 \
operator||
name|FileCheck
operator|-
name|check
operator|-
name|prefix
operator|=
name|G_DARWIN
operator|%
name|s
end_expr_stmt

begin_comment
comment|// RUN: %clang -### -c -gdwarf-2 %s 2>&1 | FileCheck -check-prefix=G_D2 %s
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
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY_DWARF2 %s
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
comment|// RUN: %clang -### -c -gline-tables-only -g %s -target x86_64-apple-darwin 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_ONLY_DWARF2 %s
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
comment|// RUN: %clang -### -c -grecord-gcc-switches -gno-record-gcc-switches \
end_comment

begin_comment
comment|// RUN:        -gstrict-dwarf -gno-strict-dwarf %s 2>&1 \
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
comment|// RUN: %clang -### -g %s 2>&1 | FileCheck -check-prefix=CI %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G: "-cc1"
end_comment

begin_comment
comment|// G: "-g"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_DARWIN: "-cc1"
end_comment

begin_comment
comment|// G_DARWIN: "-gdwarf-2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_D2: "-cc1"
end_comment

begin_comment
comment|// G_D2: "-gdwarf-2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_NO: "-cc1"
end_comment

begin_comment
comment|// G_NO-NOT: "-g"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GLTO_ONLY: "-cc1"
end_comment

begin_comment
comment|// GLTO_ONLY-NOT: "-g"
end_comment

begin_comment
comment|// GLTO_ONLY: "-gline-tables-only"
end_comment

begin_comment
comment|// GLTO_ONLY-NOT: "-g"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GLTO_ONLY_DWARF2: "-cc1"
end_comment

begin_comment
comment|// GLTO_ONLY_DWARF2-NOT: "-g"
end_comment

begin_comment
comment|// GLTO_ONLY_DWARF2: "-gline-tables-only"
end_comment

begin_comment
comment|// GLTO_ONLY_DWARF2: "-gdwarf-2"
end_comment

begin_comment
comment|// GLTO_ONLY_DWARF2-NOT: "-g"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_ONLY: "-cc1"
end_comment

begin_comment
comment|// G_ONLY-NOT: "-gline-tables-only"
end_comment

begin_comment
comment|// G_ONLY: "-g"
end_comment

begin_comment
comment|// G_ONLY-NOT: "-gline-tables-only"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G_ONLY_DWARF2: "-cc1"
end_comment

begin_comment
comment|// G_ONLY_DWARF2-NOT: "-gline-tables-only"
end_comment

begin_comment
comment|// G_ONLY_DWARF2: "-gdwarf-2"
end_comment

begin_comment
comment|// G_ONLY_DWARF2-NOT: "-gline-tables-only"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GLTO_NO: "-cc1"
end_comment

begin_comment
comment|// GLTO_NO-NOT: "-gline-tables-only"
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

end_unit

