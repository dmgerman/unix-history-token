begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// ================== Check default Cortex CPU on each major architecture
end_comment

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

begin_comment
comment|// RUN: %clang -target armv7a-linux-gnueabi -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7A %s
end_comment

begin_comment
comment|// CHECK-V7A: "-cc1"{{.*}} "-triple" "armv7-{{.*}} "-target-cpu" "cortex-a8"
end_comment

begin_comment
comment|// RUN: %clang -target armv7r-linux-gnueabi -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7R %s
end_comment

begin_comment
comment|// CHECK-V7R: "-cc1"{{.*}} "-triple" "armv7r-{{.*}} "-target-cpu" "cortex-r4"
end_comment

begin_comment
comment|// RUN: %clang -target armv8  -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// CHECK-V8A: "-cc1"{{.*}} "-triple" "armv8-{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// ================== Check default Architecture on each Cortex CPU
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// CHECK-CPUV7A: "-cc1"{{.*}} "-triple" "armv7-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m0 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6M %s
end_comment

begin_comment
comment|// CHECK-CPUV6M: "-cc1"{{.*}} "-triple" "thumbv6m-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m3 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7M %s
end_comment

begin_comment
comment|// CHECK-CPUV7M: "-cc1"{{.*}} "-triple" "armv7m-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7EM %s
end_comment

begin_comment
comment|// CHECK-CPUV7EM: "-cc1"{{.*}} "-triple" "armv7em-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// CHECK-CPUV7R: "-cc1"{{.*}} "-triple" "armv7r-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// CHECK-CPUV8A: "-cc1"{{.*}} "-triple" "armv8-{{.*}}
end_comment

end_unit

