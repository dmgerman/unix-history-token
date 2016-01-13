begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm-freebsd -mcpu=xscale -### -c %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: error: the clang compiler does not support '-mcpu=xscale'
end_comment

begin_comment
comment|// CHECK: "-cc1"{{.*}} "-target-cpu" "xscale"{{.*}}
end_comment

end_unit

