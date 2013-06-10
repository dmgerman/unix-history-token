begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Verify that -include isn't included twice with -save-temps.
end_comment

begin_comment
comment|// RUN: %clang -S -o - %s -include %t.h -save-temps -### 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t.log
end_comment

begin_comment
comment|// CHECK: "-include
end_comment

begin_comment
comment|// CHECK-NOT: "-include
end_comment

end_unit

