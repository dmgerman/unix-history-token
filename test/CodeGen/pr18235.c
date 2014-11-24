begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -triple le32-unknown-nacl %s -S -o - 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: unable to create target: 'No available targets are compatible with this triple, see -version for the available targets.'
end_comment

end_unit

