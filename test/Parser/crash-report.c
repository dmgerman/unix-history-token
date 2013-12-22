begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not --crash %clang_cc1 %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: crash-recovery
end_comment

begin_empty
empty|#prag\ ma clang __debug crash
end_empty

begin_comment
comment|// CHECK: prag\
end_comment

begin_comment
comment|// CHECK-NEXT: ma
end_comment

end_unit

