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
comment|// RUN: %clang -### -c -g2 %s 2>&1 | FileCheck -check-prefix=G2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -g3 %s 2>&1 | FileCheck -check-prefix=G3 %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ganything %s 2>&1 | FileCheck -check-prefix=GANY %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -ggdb %s 2>&1 | FileCheck -check-prefix=GGDB %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -gfoo %s 2>&1 | FileCheck -check-prefix=GFOO %s
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
comment|// G2: "-cc1"
end_comment

begin_comment
comment|// G2: "-g"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// G3: "-cc1"
end_comment

begin_comment
comment|// G3: "-g"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GANY: "-cc1"
end_comment

begin_comment
comment|// GANY-NOT: "-g"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GGDB: "-cc1"
end_comment

begin_comment
comment|// GGDB: "-g"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GFOO: "-cc1"
end_comment

begin_comment
comment|// GFOO-NOT: "-g"
end_comment

end_unit

