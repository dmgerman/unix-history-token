begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check target CPUs are correctly passed.
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// GENERIC: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s
end_comment

begin_comment
comment|// ARM64-GENERIC: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-darwin -arch arm64 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-DARWIN %s
end_comment

begin_comment
comment|// ARM64-DARWIN: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cyclone"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53 %s
end_comment

begin_comment
comment|// CA53: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA53 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA53 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA53 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA53 %s
end_comment

begin_comment
comment|// ARM64-CA53: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
end_comment

begin_comment
comment|// CA57: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a57"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA57 %s
end_comment

begin_comment
comment|// ARM64-CA57: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a57"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC-BE %s
end_comment

begin_comment
comment|// GENERIC-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE %s
end_comment

begin_comment
comment|// CA53-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE %s
end_comment

begin_comment
comment|// CA57-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a57"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a57 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a53 -mcpu=cortex-a57  -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE %s
end_comment

begin_comment
comment|// MCPU-MTUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a53"
end_comment

end_unit

