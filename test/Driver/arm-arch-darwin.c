begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// On Darwin, arch should override CPU for triple purposes
end_comment

begin_comment
comment|// RUN: %clang -target armv7m-apple-darwin -arch armv7m -mcpu=cortex-m4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7M-DARWIN %s
end_comment

begin_comment
comment|// CHECK-V7M-DARWIN: "-cc1"{{.*}} "-triple" "thumbv7m-{{.*}} "-target-cpu" "cortex-m4"
end_comment

begin_comment
comment|// RUN: %clang -target armv7m -arch armv7m -mcpu=cortex-m4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7M-OVERRIDDEN %s
end_comment

begin_comment
comment|// CHECK-V7M-OVERRIDDEN: "-cc1"{{.*}} "-triple" "thumbv7em-{{.*}} "-target-cpu" "cortex-m4"
end_comment

end_unit

