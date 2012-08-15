begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check to make sure clang is somewhat picky about -g options.
end_comment

begin_comment
comment|// rdar://10383444
end_comment

begin_comment
comment|// RUN: %clang -### -c -g %s 2>&1 | FileCheck -check-prefix=G %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g2 %s 2>&1 | FileCheck -check-prefix=G %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g3 %s 2>&1 | FileCheck -check-prefix=G %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb %s 2>&1 | FileCheck -check-prefix=G %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb1 %s 2>&1 | FileCheck -check-prefix=G %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb3 %s 2>&1 | FileCheck -check-prefix=G %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gdwarf-2 %s 2>&1 | FileCheck -check-prefix=G %s
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
comment|// RUN: %clang -### -c -gline-tables-only %s 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=GLTO_ONLY %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gline-tables-only -g %s 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck -check-prefix=G_ONLY %s
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
comment|// RUN:           -gstrict-dwarf -gno-strict-dwarf %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | not grep "argument unused during compilation"
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
comment|// GLTO_NO: "-cc1"
end_comment

begin_comment
comment|// GLTO_NO-NOT: "-gline-tables-only"
end_comment

end_unit

