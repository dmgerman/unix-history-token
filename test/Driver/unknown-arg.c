begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 %s -cake-is-lie 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file=%t.log
end_comment

begin_comment
comment|// CHECK: unknown argument
end_comment

end_unit

