begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check the -fmax-type-align=N flag
end_comment

begin_comment
comment|// rdar://16254558
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-apple-macosx10.7.0 %s -o - -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck -check-prefix=TEST0 %s
end_comment

begin_comment
comment|// TEST0: -fmax-type-align=16
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -fmax-type-align=32 -target x86_64-apple-macosx10.7.0 %s -o - -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck -check-prefix=TEST1 %s
end_comment

begin_comment
comment|// TEST1: -fmax-type-align=32
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -fmax-type-align=32 -fno-max-type-align -target x86_64-apple-macosx10.7.0 %s -o - -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck -check-prefix=TEST2 %s
end_comment

begin_comment
comment|// TEST2-NOT: -fmax-type-align
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -fno-max-type-align -target x86_64-apple-macosx10.7.0 %s -o - -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck -check-prefix=TEST3 %s
end_comment

begin_comment
comment|// TEST3-NOT: -fmax-type-align
end_comment

end_unit

