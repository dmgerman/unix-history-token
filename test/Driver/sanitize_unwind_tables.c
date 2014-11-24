begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Sanitizers need to unwind stack at any code location.
end_comment

begin_comment
comment|// Test that unwind tables are enabled in supported configurations.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=address %s -### 2>&1 |  FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target i686-linux-gnu -fsanitize=address %s -### 2>&1 |  FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-androideabi -fsanitize=address %s -### 2>&1 |  FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=memory %s -### 2>&1 |  FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=thread %s -### 2>&1 |  FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fsanitize=dataflow %s -### 2>&1 |  FileCheck %s
end_comment

begin_comment
comment|// CHECK: -munwind-tables
end_comment

end_unit

