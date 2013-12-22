begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fpack-struct -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|// RUN: %clang -fpack-struct=8 -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s --check-prefix=CHECK-EQ
end_comment

begin_comment
comment|// CHECK: "-cc1"
end_comment

begin_comment
comment|// CHECK: "-fpack-struct=1"
end_comment

begin_comment
comment|// CHECK-EQ: "-cc1"
end_comment

begin_comment
comment|// CHECK-EQ: "-fpack-struct=8"
end_comment

end_unit

