begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// ================== Check default CPU on each major architecture
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-GENERIC %s
end_comment

begin_comment
comment|// CHECK-GENERIC: "-cc1"{{.*}} "-triple" "armv4t-{{.*}} "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-GENERIC %s
end_comment

begin_comment
comment|// CHECK-BE-GENERIC: "-cc1"{{.*}} "-triple" "armebv4t-{{.*}} "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target arm -mthumb -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-GENERIC-THUMB %s
end_comment

begin_comment
comment|// CHECK-GENERIC-THUMB: "-cc1"{{.*}} "-triple" "thumbv4t-{{.*}} "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mthumb -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-GENERIC-THUMB %s
end_comment

begin_comment
comment|// CHECK-BE-GENERIC-THUMB: "-cc1"{{.*}} "-triple" "thumbebv4t-{{.*}} "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armv4t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V4T %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv4t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V4T %s
end_comment

begin_comment
comment|// CHECK-V4T: "-cc1"{{.*}} "-triple" "armv4t-{{.*}} "-target-cpu" "arm7tdmi"
end_comment

begin_comment
comment|// RUN: %clang -target armv4t -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V4T-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mthumb -march=armv4t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V4T-THUMB %s
end_comment

begin_comment
comment|// CHECK-V4T-THUMB: "-cc1"{{.*}} "-triple" "thumbv4t-{{.*}} "-target-cpu" "arm7tdmi"
end_comment

begin_comment
comment|// RUN: %clang -target armv5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv5t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv5t -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5 %s
end_comment

begin_comment
comment|// CHECK-V5: "-cc1"{{.*}} "-triple" "armv5-{{.*}} "-target-cpu" "arm10tdmi"
end_comment

begin_comment
comment|// RUN: %clang -target armv5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv5t -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5-THUMB %s
end_comment

begin_comment
comment|// CHECK-V5-THUMB: "-cc1"{{.*}} "-triple" "thumbv5-{{.*}} "-target-cpu" "arm10tdmi"
end_comment

begin_comment
comment|// RUN: %clang -target armv5e -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5E %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv5e -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5E %s
end_comment

begin_comment
comment|// CHECK-V5E: "-cc1"{{.*}} "-triple" "armv5e-{{.*}} "-target-cpu" "arm1022e"
end_comment

begin_comment
comment|// RUN: %clang -target armv5e -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5E-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv5e -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5E-THUMB %s
end_comment

begin_comment
comment|// CHECK-V5E-THUMB: "-cc1"{{.*}} "-triple" "thumbv5e-{{.*}} "-target-cpu" "arm1022e"
end_comment

begin_comment
comment|// FIXME %clang -target armv5tej -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5TEJ %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv5tej -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5TEJ %s
end_comment

begin_comment
comment|// CHECK-V5TEJ: "-cc1"{{.*}} "-triple" "armv5e-{{.*}} "-target-cpu" "arm926ej-s"
end_comment

begin_comment
comment|// FIXME %clang -target armv5tej -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5TEJ-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv5tej -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V5TEJ-THUMB %s
end_comment

begin_comment
comment|// CHECK-V5TEJ-THUMB: "-cc1"{{.*}} "-triple" "thumbv5e-{{.*}} "-target-cpu" "arm926ej-s"
end_comment

begin_comment
comment|// RUN: %clang -target armv6 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6 %s
end_comment

begin_comment
comment|// CHECK-V6: "-cc1"{{.*}} "-triple" "armv6-{{.*}} "-target-cpu" "arm1136jf-s"
end_comment

begin_comment
comment|// RUN: %clang -target armv6 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6-THUMB %s
end_comment

begin_comment
comment|// CHECK-V6-THUMB: "-cc1"{{.*}} "-triple" "thumbv6-{{.*}} "-target-cpu" "arm1136jf-s"
end_comment

begin_comment
comment|// FIXME %clang -target armv6j -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6J %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6j -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6J %s
end_comment

begin_comment
comment|// CHECK-V6J: "-cc1"{{.*}} "-triple" "armv6-{{.*}} "-target-cpu" "arm1136jf-s"
end_comment

begin_comment
comment|// FIXME %clang -target armv6j -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6J-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6j -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6J-THUMB %s
end_comment

begin_comment
comment|// CHECK-V6J-THUMB: "-cc1"{{.*}} "-triple" "thumbv6-{{.*}} "-target-cpu" "arm1136jf-s"
end_comment

begin_comment
comment|// FIXME %clang -target armv6z -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6Z %s
end_comment

begin_comment
comment|// FIXME %clang -target arm -march=armv6z -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6Z %s
end_comment

begin_comment
comment|// CHECK-V6Z: "-cc1"{{.*}} "-triple" "armv6-{{.*}} "-target-cpu" "arm1176jzf-s"
end_comment

begin_comment
comment|// FIXME %clang -target armv6z -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6Z-THUMB %s
end_comment

begin_comment
comment|// FIXME %clang -target arm -march=armv6z -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6Z-THUMB %s
end_comment

begin_comment
comment|// CHECK-V6Z-THUMB: "-cc1"{{.*}} "-triple" "thumbv6-{{.*}} "-target-cpu" "arm1176jzf-s"
end_comment

begin_comment
comment|// RUN: %clang -target armv6k -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6K %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6k -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6K %s
end_comment

begin_comment
comment|// CHECK-V6K: "-cc1"{{.*}} "-triple" "armv6k-{{.*}} "-target-cpu" "arm1176j-s"
end_comment

begin_comment
comment|// RUN: %clang -target armv6k -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6K-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6k -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6K-THUMB %s
end_comment

begin_comment
comment|// CHECK-V6K-THUMB: "-cc1"{{.*}} "-triple" "thumbv6k-{{.*}} "-target-cpu" "arm1176j-s"
end_comment

begin_comment
comment|// RUN: %clang -target armv6t2 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6T2 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6t2 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6T2 %s
end_comment

begin_comment
comment|// CHECK-V6T2: "-cc1"{{.*}} "-triple" "armv6t2-{{.*}} "-target-cpu" "arm1156t2-s"
end_comment

begin_comment
comment|// RUN: %clang -target armv6t2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6T2-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6t2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6T2-THUMB %s
end_comment

begin_comment
comment|// CHECK-V6T2-THUMB: "-cc1"{{.*}} "-triple" "thumbv6t2-{{.*}} "-target-cpu" "arm1156t2-s"
end_comment

begin_comment
comment|// RUN: %clang -target armv6m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M %s
end_comment

begin_comment
comment|// RUN: %clang -target armv6sm -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6sm -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M %s
end_comment

begin_comment
comment|// CHECK-V6M: "-cc1"{{.*}} "-triple" "thumbv6m-{{.*}} "-target-cpu" "cortex-m0"
end_comment

begin_comment
comment|// RUN: %clang -target armv6m -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M-BIG %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6m -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M-BIG %s
end_comment

begin_comment
comment|// CHECK-V6M-BIG: "-cc1"{{.*}} "-triple" "thumbebv6m-{{.*}} "-target-cpu" "cortex-m0"
end_comment

begin_comment
comment|// RUN: %clang -target armv7m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv7-m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7M %s
end_comment

begin_comment
comment|// CHECK-V7M: "-cc1"{{.*}} "-triple" "thumbv7m-{{.*}} "-target-cpu" "cortex-m3"
end_comment

begin_comment
comment|// RUN: %clang -target armv7em -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv7e-m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM %s
end_comment

begin_comment
comment|// CHECK-V7EM: "-cc1"{{.*}} "-triple" "thumbv7em-{{.*}} "-target-cpu" "cortex-m4"
end_comment

begin_comment
comment|// RUN: %clang -target armv7em -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM-BIG %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv7e-m -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM-BIG %s
end_comment

begin_comment
comment|// CHECK-V7EM-BIG: "-cc1"{{.*}} "-triple" "thumbebv7em-{{.*}} "-target-cpu" "cortex-m4"
end_comment

begin_comment
comment|// RUN: %clang -target armv6m-apple-darwin -arch armv6m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V6M-DARWIN %s
end_comment

begin_comment
comment|// CHECK-V6M-DARWIN: "-cc1"{{.*}} "-triple" "thumbv6m-{{.*}} "-target-cpu" "cortex-m0"
end_comment

begin_comment
comment|// RUN: %clang -target armv7m-apple-darwin -arch armv7m -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7M-DARWIN %s
end_comment

begin_comment
comment|// CHECK-V7M-DARWIN: "-cc1"{{.*}} "-triple" "thumbv7m-{{.*}} "-target-cpu" "cortex-m3"
end_comment

begin_comment
comment|// RUN: %clang -target armv7em-apple-darwin -arch armv7em -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7EM-DARWIN %s
end_comment

begin_comment
comment|// CHECK-V7EM-DARWIN: "-cc1"{{.*}} "-triple" "thumbv7em-{{.*}} "-target-cpu" "cortex-m4"
end_comment

begin_comment
comment|// RUN: %clang -target armv7a-linux-gnueabi -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -march=armv7-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7A %s
end_comment

begin_comment
comment|// CHECK-V7A: "-cc1"{{.*}} "-triple" "armv7-{{.*}} "-target-cpu" "cortex-a8"
end_comment

begin_comment
comment|// RUN: %clang -target armv7a-linux-gnueabi -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -march=armv7-a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7A-THUMB %s
end_comment

begin_comment
comment|// CHECK-V7A-THUMB: "-cc1"{{.*}} "-triple" "thumbv7-{{.*}} "-target-cpu" "cortex-a8"
end_comment

begin_comment
comment|// RUN: %clang -target armv7r-linux-gnueabi -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -march=armv7-r -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7R %s
end_comment

begin_comment
comment|// CHECK-V7R: "-cc1"{{.*}} "-triple" "armv7r-{{.*}} "-target-cpu" "cortex-r4"
end_comment

begin_comment
comment|// RUN: %clang -target armv7r-linux-gnueabi -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -march=armv7-r -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V7R-THUMB %s
end_comment

begin_comment
comment|// CHECK-V7R-THUMB: "-cc1"{{.*}} "-triple" "thumbv7r-{{.*}} "-target-cpu" "cortex-r4"
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mlittle-endian -march=armv8-a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// CHECK-V8A: "-cc1"{{.*}} "-triple" "armv8-{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target armv8r-linux-gnueabi -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8r -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8-r -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8R %s
end_comment

begin_comment
comment|// CHECK-V8R: "-cc1"{{.*}} "-triple" "armv8r-{{.*}} "-target-cpu" "cortex-r52"
end_comment

begin_comment
comment|// RUN: %clang -target armv8r-linux-gnueabi -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8R-BIG %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8r -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8R-BIG %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8-r -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8R-BIG %s
end_comment

begin_comment
comment|// CHECK-V8R-BIG: "-cc1"{{.*}} "-triple" "armebv8r-{{.*}} "-target-cpu" "cortex-r52"
end_comment

begin_comment
comment|// RUN: %clang -target armv8r-linux-gnueabi -mthumb -### -c %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:     FileCheck -check-prefix=CHECK-V8R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8r -mthumb -### -c %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:     FileCheck -check-prefix=CHECK-V8R-THUMB %s
end_comment

begin_comment
comment|// CHECK-V8R-THUMB: "-cc1"{{.*}} "-triple" "thumbv8r-{{.*}} "-target-cpu" "cortex-r52"
end_comment

begin_comment
comment|// RUN: %clang -target armv8r-linux-gnueabi -mthumb -mbig-endian -### -c %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:     FileCheck -check-prefix=CHECK-V8R-THUMB-BIG %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8r -mthumb -mbig-endian -### -c %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:     FileCheck -check-prefix=CHECK-V8R-THUMB-BIG %s
end_comment

begin_comment
comment|// CHECK-V8R-THUMB-BIG: "-cc1"{{.*}} "-triple" "thumbebv8r-{{.*}} "-target-cpu" "cortex-r52"
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target armv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -march=armv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -march=armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -march=armv8-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target armv8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -march=armv8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target armv8a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -march=armv8a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -mlittle-endian -march=armv8-a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-GENERIC %s
end_comment

begin_comment
comment|// CHECK-V8A-GENERIC: "-cc1"{{.*}} "-triple" "armv8-{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armebv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armebv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8-a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A %s
end_comment

begin_comment
comment|// CHECK-BE-V8A: "-cc1"{{.*}} "-triple" "armebv8-{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V8A-THUMB %s
end_comment

begin_comment
comment|// CHECK-V8A-THUMB: "-cc1"{{.*}} "-triple" "thumbv8-{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target armebv8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armebv8a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V8A-THUMB %s
end_comment

begin_comment
comment|// CHECK-BE-V8A-THUMB: "-cc1"{{.*}} "-triple" "thumbebv8-{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mlittle-endian -march=armv8.1-a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -march=armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -march=armv8.1a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=generic -target arm -mlittle-endian -march=armv8.1-a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// CHECK-V81A: "-cc1"{{.*}} "-triple" "armv8.1a-{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armebv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8.1a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8.1a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8.1-a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A %s
end_comment

begin_comment
comment|// CHECK-BE-V81A: "-cc1"{{.*}} "-triple" "armebv8.1a-{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armv8.1a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.1a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.1-a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8.1a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.1a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.1-a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V81A-THUMB %s
end_comment

begin_comment
comment|// CHECK-V81A-THUMB: "-cc1"{{.*}} "-triple" "thumbv8.1a-{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armebv8.1a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8.1a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8.1-a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8.1a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8.1a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8.1-a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V81A-THUMB %s
end_comment

begin_comment
comment|// CHECK-BE-V81A-THUMB: "-cc1"{{.*}} "-triple" "thumbebv8.1a-{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.2-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.2a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8.2a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.2a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mlittle-endian -march=armv8.2-a -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A %s
end_comment

begin_comment
comment|// CHECK-V82A: "-cc1"{{.*}} "-triple" "armv8.2{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armebv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8.2a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8.2-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8.2a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8.2-a -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A %s
end_comment

begin_comment
comment|// CHECK-BE-V82A: "-cc1"{{.*}} "-triple" "armebv8.2{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armv8.2a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.2a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.2-a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8.2a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.2a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8.2-a -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-V82A-THUMB %s
end_comment

begin_comment
comment|// CHECK-V82A-THUMB: "-cc1"{{.*}} "-triple" "thumbv8.2a-{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armebv8.2a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8.2a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -march=armebv8.2-a -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8.2a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8.2a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armebv8.2-a -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-V82A-THUMB %s
end_comment

begin_comment
comment|// CHECK-BE-V82A-THUMB: "-cc1"{{.*}} "-triple" "thumbebv8.2a-{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -march=armv8.2-a+fp16 -### -c %s 2>&1 | FileCheck --check-prefix CHECK-V82A-FP16 %s
end_comment

begin_comment
comment|// CHECK-V82A-FP16: "-cc1"{{.*}} "-triple" "armv8.2{{.*}}" "-target-cpu" "generic" {{.*}}"-target-feature" "+fullfp16"
end_comment

begin_comment
comment|// Once we have CPUs with optional v8.2-A FP16, we will need a way to turn it
end_comment

begin_comment
comment|// on and off. Cortex-A53 is a placeholder for now.
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mcpu=cortex-a53+fp16 -### -c %s 2>&1 | FileCheck --check-prefix CHECK-CORTEX-A53-FP16 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mcpu=cortex-a53+nofp16 -### -c %s 2>&1 | FileCheck --check-prefix CHECK-CORTEX-A53-NOFP16 %s
end_comment

begin_comment
comment|// CHECK-CORTEX-A53-FP16: "-cc1" {{.*}}"-target-cpu" "cortex-a53" {{.*}}"-target-feature" "+fullfp16"
end_comment

begin_comment
comment|// CHECK-CORTEX-A53-NOFP16: "-cc1" {{.*}}"-target-cpu" "cortex-a53" {{.*}}"-target-feature" "-fullfp16"
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.base %s -### -c 2>&1 | FileCheck %s --check-prefix=V8M_BASELINE
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8-m.base %s -### -c 2>&1 | FileCheck %s --check-prefix=V8M_BASELINE
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8m.base %s -### -c 2>&1 | FileCheck %s --check-prefix=V8M_BASELINE
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.base -mbig-endian %s -### -c 2>&1 | FileCheck %s --check-prefix=EBV8M_BASELINE
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8-m.base -mbig-endian %s -### -c 2>&1 | FileCheck %s --check-prefix=EBV8M_BASELINE
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8m.base -mbig-endian %s -### -c 2>&1 | FileCheck %s --check-prefix=EBV8M_BASELINE
end_comment

begin_comment
comment|// V8M_BASELINE: "-cc1"{{.*}} "-triple" "thumbv8m.base-{{.*}} "-target-cpu" "generic"
end_comment

begin_comment
comment|// EBV8M_BASELINE: "-cc1"{{.*}} "-triple" "thumbebv8m.base-{{.*}} "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.main %s -### -c 2>&1 | FileCheck %s --check-prefix=V8M_MAINLINE
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8-m.main %s -### -c 2>&1 | FileCheck %s --check-prefix=V8M_MAINLINE
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8m.main %s -### -c 2>&1 | FileCheck %s --check-prefix=V8M_MAINLINE
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.main -mbig-endian %s -### -c 2>&1 | FileCheck %s --check-prefix=EBV8M_MAINLINE
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8-m.main -mbig-endian %s -### -c 2>&1 | FileCheck %s --check-prefix=EBV8M_MAINLINE
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv8m.main -mbig-endian %s -### -c 2>&1 | FileCheck %s --check-prefix=EBV8M_MAINLINE
end_comment

begin_comment
comment|// V8M_MAINLINE: "-cc1"{{.*}} "-triple" "thumbv8m.main-{{.*}} "-target-cpu" "generic"
end_comment

begin_comment
comment|// EBV8M_MAINLINE: "-cc1"{{.*}} "-triple" "thumbebv8m.main-{{.*}} "-target-cpu" "generic"
end_comment

begin_comment
comment|// ================== Check that a bogus architecture gives an error
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armbogusv6 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS %s
end_comment

begin_comment
comment|// CHECK-BOGUS: error: {{.*}} does not support '-march=armbogusv6'
end_comment

begin_comment
comment|// RUN: %clang -target arm---eabihf -march=armbogusv7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS-HF %s
end_comment

begin_comment
comment|// CHECK-BOGUS-HF: error: {{.*}} does not support '-march=armbogusv7'
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=armv6bogus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS2 %s
end_comment

begin_comment
comment|// CHECK-BOGUS2: error: {{.*}} does not support '-march=armv6bogus'
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=bogus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS3 %s
end_comment

begin_comment
comment|// CHECK-BOGUS3: error: {{.*}} does not support '-march=bogus'
end_comment

begin_comment
comment|// ================== Check that a bogus CPU gives an error
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=bogus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS-CPU %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8-apple-darwin -arch arm64 -mcpu=bogus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS-CPU %s
end_comment

begin_comment
comment|// CHECK-BOGUS-CPU: error: {{.*}} does not support '-mcpu=bogus'
end_comment

begin_comment
comment|// RUN: %clang -target armv8-apple-darwin -arch arm64 -mtune=bogus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BOGUS-TUNE %s
end_comment

begin_comment
comment|// CHECK-BOGUS-TUNE: error: {{.*}} does not support '-mtune=bogus'
end_comment

begin_comment
comment|// ================== Check default Architecture on each ARM11 CPU
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1136j-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1136jf-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6 %s
end_comment

begin_comment
comment|// CHECK-CPUV6: "-cc1"{{.*}} "-triple" "armv6-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=mpcore -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6K %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=mpcorenovfp -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6K %s
end_comment

begin_comment
comment|// CHECK-CPUV6K: "-cc1"{{.*}} "-triple" "armv6k-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1176jz-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6KZ %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1176jzf-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6KZ %s
end_comment

begin_comment
comment|// CHECK-CPUV6KZ: "-cc1"{{.*}} "-triple" "armv6kz-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1156t2-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6T2 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=arm1156t2f-s -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6T2 %s
end_comment

begin_comment
comment|// CHECK-CPUV6T2: "-cc1"{{.*}} "-triple" "armv6t2-{{.*}}
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
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// CHECK-CPUV7A: "-cc1"{{.*}} "-triple" "armv7-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a9 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a12 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a15 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a17 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A %s
end_comment

begin_comment
comment|// CHECK-BE-CPUV7A: "-cc1"{{.*}} "-triple" "armebv7-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// CHECK-CPUV7A-THUMB: "-cc1"{{.*}} "-triple" "thumbv7-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a7 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a9 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a12 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a15 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-a17 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a5 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a7 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a8 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a9 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a12 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a15 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-a17 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7A-THUMB %s
end_comment

begin_comment
comment|// CHECK-BE-CPUV7A-THUMB: "-cc1"{{.*}} "-triple" "thumbebv7-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m0 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m0plus -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m1 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=sc000 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV6M %s
end_comment

begin_comment
comment|// CHECK-CPUV6M: "-cc1"{{.*}} "-triple" "thumbv6m-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m3 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m3 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=sc300 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=sc300 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7M %s
end_comment

begin_comment
comment|// CHECK-CPUV7M: "-cc1"{{.*}} "-triple" "thumbv7m-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-m3 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7M %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m3 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7M %s
end_comment

begin_comment
comment|// CHECK-BE-CPUV7M: "-cc1"{{.*}} "-triple" "thumbebv7m-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7EM %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7EM %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m4 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7EM %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m7 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7EM %s
end_comment

begin_comment
comment|// CHECK-CPUV7EM: "-cc1"{{.*}} "-triple" "thumbv7em-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-m4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7EM %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-m7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7EM %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m4 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7EM %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-m7 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7EM %s
end_comment

begin_comment
comment|// CHECK-BE-CPUV7EM: "-cc1"{{.*}} "-triple" "thumbebv7em-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r8 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R %s
end_comment

begin_comment
comment|// CHECK-CPUV7R: "-cc1"{{.*}} "-triple" "armv7r-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r4 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r4f -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r8 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R %s
end_comment

begin_comment
comment|// CHECK-BE-CPUV7R: "-cc1"{{.*}} "-triple" "armebv7r-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r8 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// CHECK-CPUV7R-THUMB: "-cc1"{{.*}} "-triple" "thumbv7r-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r4 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r4f -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r5 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r7 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-linux-gnueabi -mcpu=cortex-r8 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r4f -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r5 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r7 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r8 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV7R-THUMB %s
end_comment

begin_comment
comment|// CHECK-BE-CPUV7R-THUMB: "-cc1"{{.*}} "-triple" "thumbebv7r-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a32 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a32 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a35 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a53 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a57 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a72 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a73 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m1 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m2 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m3 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A %s
end_comment

begin_comment
comment|// CHECK-CPUV8A: "-cc1"{{.*}} "-triple" "armv8-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a32 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a32 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a35 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a53 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a57 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a72 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a73 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m1 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m2 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m3 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A %s
end_comment

begin_comment
comment|// CHECK-BE-CPUV8A: "-cc1"{{.*}} "-triple" "armebv8-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-r52 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8R %s
end_comment

begin_comment
comment|// CHECK-CPUV8R: "-cc1"{{.*}} "-triple" "armv8r-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a32 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a35 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a53 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a57 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a72 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a73 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m1 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m3 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a32 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a35 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a53 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a57 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a72 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a73 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m1 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m2 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m3 -mlittle-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// CHECK-CPUV8A-THUMB: "-cc1"{{.*}} "-triple" "thumbv8-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a32 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a35 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a53 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a57 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a72 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=cortex-a73 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=exynos-m1 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=exynos-m2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb -mcpu=exynos-m3 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a32 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a35 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a53 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a57 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a72 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a73 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m1 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m2 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=exynos-m3 -mbig-endian -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-BE-CPUV8A-THUMB %s
end_comment

begin_comment
comment|// CHECK-BE-CPUV8A-THUMB: "-cc1"{{.*}} "-triple" "thumbebv8-{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-arm-none-eabi -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CORTEX-A73 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-arm-none-eabi -mcpu=cortex-a73 -mfpu=crypto-neon-fp-armv8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CORTEX-A73-MFPU %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-arm-none-eabi -mcpu=cortex-a73 -mfloat-abi=soft -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CORTEX-A73-SOFT %s
end_comment

begin_comment
comment|// CHECK-CORTEX-A73: "-cc1"{{.*}} "-triple" "armv8-{{.*}} "-target-cpu" "cortex-a73"
end_comment

begin_comment
comment|// CHECK-CORTEX-A73-MFPU: "-cc1"{{.*}} "-target-feature" "+fp-armv8"
end_comment

begin_comment
comment|// CHECK-CORTEX-A73-MFPU: "-target-feature" "+crypto"
end_comment

begin_comment
comment|// CHECK-CORTEX-A73-SOFT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-CORTEX-A73-SOFT: "-target-feature" "+soft-float-abi"
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-m23 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8MBASE %s
end_comment

begin_comment
comment|// CHECK-CPUV8MBASE:  "-cc1"{{.*}} "-triple" "thumbv8m.base-
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-m33 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV8MMAIN %s
end_comment

begin_comment
comment|// CHECK-CPUV8MMAIN:  "-cc1"{{.*}} "-triple" "thumbv8m.main-
end_comment

begin_comment
comment|// ================== Check whether -mcpu accepts mixed-case values.
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=Cortex-a5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=cortex-A7 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=CORTEX-a8 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=Cortex-A9 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=corteX-A12 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=CorteX-a15 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=CorteX-A17 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-CPUV7A %s
end_comment

begin_comment
comment|// CHECK-CASE-INSENSITIVE-CPUV7A: "-cc1"{{.*}} "-triple" "armv7-{{.*}}
end_comment

begin_comment
comment|// ================== Check whether -march accepts mixed-case values.
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=Armv5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-V5 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=ARMV5 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-V5 %s
end_comment

begin_comment
comment|// CHECK-CASE-INSENSITIVE-V5: "-cc1"{{.*}} "-triple" "armv5-{{.*}} "-target-cpu" "arm10tdmi"
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=Armv6t2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-V6T2-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -march=ARMV6T2 -mthumb -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CASE-INSENSITIVE-V6T2-THUMB %s
end_comment

begin_comment
comment|// CHECK-CASE-INSENSITIVE-V6T2-THUMB: "-cc1"{{.*}} "-triple" "thumbv6t2-{{.*}} "-target-cpu" "arm1156t2-s"
end_comment

end_unit

