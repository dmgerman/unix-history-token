begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// ================== Check default Architecture on krait CPU
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-gnueabi -mcpu=krait -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CPUV7A %s
end_comment

begin_comment
comment|// CHECK-CPUV7A: "-cc1"{{.*}} "-triple" "armv7-{{.*}}
end_comment

end_unit

