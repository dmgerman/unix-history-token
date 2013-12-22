begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -working-directory /no/such/dir/ input 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: shell-preserves-root
end_comment

begin_comment
comment|//CHECK: no such file or directory: '/no/such/dir/input'
end_comment

end_unit

