begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv6m-apple-darwin -arch armv6m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M %s
end_comment

begin_comment
comment|// CHECK-V6M: "-cc1"{{.*}} "-triple" "thumbv6m-{{.*}} "-target-cpu" "cortex-m0"
end_comment

begin_comment
comment|// RUN: %clang -target armv7m-apple-darwin -arch armv7m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7M %s
end_comment

begin_comment
comment|// CHECK-V7M: "-cc1"{{.*}} "-triple" "thumbv7m-{{.*}} "-target-cpu" "cortex-m3"
end_comment

begin_comment
comment|// RUN: %clang -target armv7em-apple-darwin -arch armv7em -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM %s
end_comment

begin_comment
comment|// CHECK-V7EM: "-cc1"{{.*}} "-triple" "thumbv7em-{{.*}} "-target-cpu" "cortex-m4"
end_comment

end_unit

