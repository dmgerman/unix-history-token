begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: system-darwin
end_comment

begin_comment
comment|// -no_deduplicate is only present from ld64 version 262 and later.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=261 -O0 2>&1 | FileCheck -check-prefix=LINK_DEDUP %s
end_comment

begin_comment
comment|// Add -no_deduplicate when either -O0 or -O1 is explicitly specified
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=262 -O0 2>&1 | FileCheck -check-prefix=LINK_NODEDUP %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=262 -O1 2>&1 | FileCheck -check-prefix=LINK_NODEDUP %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=262 -O2 2>&1 | FileCheck -check-prefix=LINK_DEDUP %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=262 -O3 2>&1 | FileCheck -check-prefix=LINK_DEDUP %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=262 -Os 2>&1 | FileCheck -check-prefix=LINK_DEDUP %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=262 -O4 2>&1 | FileCheck -check-prefix=LINK_DEDUP %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=262 -Ofast 2>&1 | FileCheck -check-prefix=LINK_DEDUP %s
end_comment

begin_comment
comment|// Add -no_deduplicate when no -O option is specified *and* this is a compile+link
end_comment

begin_comment
comment|// (implicit -O0)
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### %s \
end_comment

begin_comment
comment|// RUN:   -mlinker-version=262 2>&1 | FileCheck -check-prefix=LINK_NODEDUP %s
end_comment

begin_comment
comment|// Do *not* add -no_deduplicate when no -O option is specified and this is just a link
end_comment

begin_comment
comment|// (since we can't imply -O0)
end_comment

begin_comment
comment|// RUN: rm -f %t.o %t.bin
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -c -o %t.o %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 %t.o -### -mlinker-version=262 \
end_comment

begin_comment
comment|// RUN:   -o %t.bin 2>&1 | FileCheck -check-prefix=LINK_DEDUP %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 %t.o -### -mlinker-version=262 \
end_comment

begin_comment
comment|// RUN:   -O0 -o %t.bin 2>&1 | FileCheck -check-prefix=LINK_NODEDUP %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 %t.o -### -mlinker-version=262 \
end_comment

begin_comment
comment|// RUN:   -O1 -o %t.bin 2>&1 | FileCheck -check-prefix=LINK_NODEDUP %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 %t.o -### -mlinker-version=262 \
end_comment

begin_comment
comment|// RUN:   -O2 -o %t.bin 2>&1 | FileCheck -check-prefix=LINK_DEDUP %s
end_comment

begin_comment
comment|// LINK_NODEDUP: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_NODEDUP: "-no_deduplicate"
end_comment

begin_comment
comment|// LINK_DEDUP: {{ld(.exe)?"}}
end_comment

begin_comment
comment|// LINK_DEDUP-NOT: "-no_deduplicate"
end_comment

end_unit

