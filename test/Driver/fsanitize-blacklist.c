begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// General blacklist usage.
end_comment

begin_comment
comment|// PR12920
end_comment

begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// Make sure we don't match the -NOT lines with the linker invocation.
end_comment

begin_comment
comment|// Delimiters match the start of the cc1 and the start of the linker lines
end_comment

begin_comment
comment|// for fragile tests.
end_comment

begin_comment
comment|// DELIMITERS: {{^ *"}}
end_comment

begin_comment
comment|// RUN: echo "fun:foo"> %t.good
end_comment

begin_comment
comment|// RUN: echo "fun:bar"> %t.second
end_comment

begin_comment
comment|// RUN: echo "badline"> %t.bad
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-blacklist=%t.good -fsanitize-blacklist=%t.second %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-BLACKLIST
end_comment

begin_comment
comment|// CHECK-BLACKLIST: -fsanitize-blacklist={{.*}}.good" "-fsanitize-blacklist={{.*}}.second
end_comment

begin_comment
comment|// Now, check for -fdepfile-entry flags.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-blacklist=%t.good -fsanitize-blacklist=%t.second %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-BLACKLIST2
end_comment

begin_comment
comment|// CHECK-BLACKLIST2: -fdepfile-entry={{.*}}.good" "-fdepfile-entry={{.*}}.second
end_comment

begin_comment
comment|// Check that the default blacklist is not added as an extra dependency.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -resource-dir=%S/Inputs/resource_dir %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-DEFAULT-BLACKLIST --implicit-check-not=fdepfile-entry
end_comment

begin_comment
comment|// CHECK-DEFAULT-BLACKLIST: -fsanitize-blacklist={{.*}}asan_blacklist.txt
end_comment

begin_comment
comment|// Ignore -fsanitize-blacklist flag if there is no -fsanitize flag.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-blacklist=%t.good %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-SANITIZE --check-prefix=DELIMITERS
end_comment

begin_comment
comment|// CHECK-NO-SANITIZE-NOT: -fsanitize-blacklist
end_comment

begin_comment
comment|// Ignore -fsanitize-blacklist flag if there is no -fsanitize flag.
end_comment

begin_comment
comment|// Now, check for the absense of -fdepfile-entry flags.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize-blacklist=%t.good %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-SANITIZE2 --check-prefix=DELIMITERS
end_comment

begin_comment
comment|// CHECK-NO-SANITIZE2-NOT: -fdepfile-entry
end_comment

begin_comment
comment|// Flag -fno-sanitize-blacklist wins if it is specified later.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-blacklist=%t.good -fno-sanitize-blacklist %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-BLACKLIST --check-prefix=DELIMITERS
end_comment

begin_comment
comment|// CHECK-NO-BLACKLIST-NOT: -fsanitize-blacklist
end_comment

begin_comment
comment|// Driver barks on unexisting blacklist files.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fno-sanitize-blacklist -fsanitize-blacklist=unexisting.txt %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-SUCH-FILE
end_comment

begin_comment
comment|// CHECK-NO-SUCH-FILE: error: no such file or directory: 'unexisting.txt'
end_comment

begin_comment
comment|// Driver properly reports malformed blacklist files.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-blacklist=%t.second -fsanitize-blacklist=%t.bad -fsanitize-blacklist=%t.good %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-BAD-BLACKLIST
end_comment

begin_comment
comment|// CHECK-BAD-BLACKLIST: error: malformed sanitizer blacklist: 'error parsing file '{{.*}}.bad': malformed line 1: 'badline''
end_comment

begin_comment
comment|// -fno-sanitize-blacklist disables all blacklists specified earlier.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address -fsanitize-blacklist=%t.good -fno-sanitize-blacklist -fsanitize-blacklist=%t.second %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-ONLY-FIRST-DISABLED
end_comment

begin_comment
comment|// CHECK-ONLY_FIRST-DISABLED-NOT: good
end_comment

begin_comment
comment|// CHECK-ONLY-FIRST-DISABLED: -fsanitize-blacklist={{.*}}.second
end_comment

begin_comment
comment|// CHECK-ONLY_FIRST-DISABLED-NOT: good
end_comment

begin_comment
comment|// DELIMITERS: {{^ *"}}
end_comment

end_unit

