begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i686-pc-linux-gnu -### -nodefaultlibs %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NOT: start-group
end_comment

begin_comment
comment|// CHECK-NOT: -lgcc
end_comment

begin_comment
comment|// CHECK-NOT: -lc
end_comment

begin_comment
comment|// CHECK: crtbegin
end_comment

begin_comment
comment|// CHECK: crtend
end_comment

end_unit

