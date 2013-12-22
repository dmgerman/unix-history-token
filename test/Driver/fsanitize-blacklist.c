begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// General blacklist usage.
end_comment

begin_comment
comment|// PR12920
end_comment

begin_comment
comment|// REQUIRES: clang-driver, shell
end_comment

begin_comment
comment|// RUN: echo "fun:foo"> %t.good
end_comment

begin_comment
comment|// RUN: echo "badline"> %t.bad
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=address -fsanitize-blacklist=%t.good %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-BLACKLIST
end_comment

begin_comment
comment|// CHECK-BLACKLIST: -fsanitize-blacklist
end_comment

begin_comment
comment|// Ignore -fsanitize-blacklist flag if there is no -fsanitize flag.
end_comment

begin_comment
comment|// RUN: %clang -fsanitize-blacklist=%t.good %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-SANITIZE
end_comment

begin_comment
comment|// CHECK-NO-SANITIZE-NOT: -fsanitize-blacklist
end_comment

begin_comment
comment|// Flag -fno-sanitize-blacklist wins if it is specified later.
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=address -fsanitize-blacklist=%t.good -fno-sanitize-blacklist %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-BLACKLIST
end_comment

begin_comment
comment|// CHECK-NO-BLACKLIST-NOT: -fsanitize-blacklist
end_comment

begin_comment
comment|// Driver barks on unexisting blacklist files.
end_comment

begin_comment
comment|// RUN: %clang -fno-sanitize-blacklist -fsanitize-blacklist=unexisting.txt %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-SUCH-FILE
end_comment

begin_comment
comment|// CHECK-NO-SUCH-FILE: error: no such file or directory: 'unexisting.txt'
end_comment

begin_comment
comment|// Driver properly reports malformed blacklist files.
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=address -fsanitize-blacklist=%t.bad %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-BAD-BLACKLIST
end_comment

begin_comment
comment|// CHECK-BAD-BLACKLIST: error: malformed sanitizer blacklist
end_comment

end_unit

