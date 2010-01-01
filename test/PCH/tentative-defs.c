begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -emit-pch -o %t.pch %S/tentative-defs.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -include-pch %t.pch -verify -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep "@variable = common global i32 0" %t | count 1
end_comment

begin_comment
comment|// RUN: grep "@incomplete_array = common global .*1 x i32" %t | count 1
end_comment

begin_comment
comment|// FIXME: tentative-defs.h expected-warning{{tentative}}
end_comment

end_unit

