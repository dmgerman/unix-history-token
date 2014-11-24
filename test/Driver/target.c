begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -no-canonical-prefixes --target=unknown-unknown-unknown -c %s \
end_comment

begin_comment
comment|// RUN:   -o %t.o -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure we get a crazy triple here as we asked for one.
end_comment

begin_comment
comment|// CHECK: Target: unknown-unknown-unknown
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Also check that the legacy spelling works.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target unknown-unknown-unknown -c %s \
end_comment

begin_comment
comment|// RUN:   -o %t.o -### 2>&1 | FileCheck %s
end_comment

end_unit

