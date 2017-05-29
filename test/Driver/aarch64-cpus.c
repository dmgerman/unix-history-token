begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check target CPUs are correctly passed.
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
end_comment

begin_comment
comment|// GENERIC: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s
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
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35 %s
end_comment

begin_comment
comment|// CA35: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a35"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA35 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA35 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA35 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA35 %s
end_comment

begin_comment
comment|// ARM64-CA35: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a35"
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
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72 %s
end_comment

begin_comment
comment|// CA72: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a72"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA72 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA72 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA72 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA72 %s
end_comment

begin_comment
comment|// ARM64-CA72: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a72"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73 %s
end_comment

begin_comment
comment|// CORTEX-A73: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a73"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A73 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A73 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A73 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A73 %s
end_comment

begin_comment
comment|// ARM64-CORTEX-A73: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a73"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1 %s
end_comment

begin_comment
comment|// M1: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "exynos-m1"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2 %s
end_comment

begin_comment
comment|// M2: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "exynos-m2"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3 %s
end_comment

begin_comment
comment|// M3: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "exynos-m3"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M1 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M1 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M1 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M1 %s
end_comment

begin_comment
comment|// ARM64-M1: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "exynos-m1"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M2 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M2 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M2 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M2 %s
end_comment

begin_comment
comment|// ARM64-M2: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "exynos-m2"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M3 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M3 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M3 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M3 %s
end_comment

begin_comment
comment|// ARM64-M3: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "exynos-m3"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=falkor -### -c %s 2>&1 | FileCheck -check-prefix=FALKOR %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=falkor -### -c %s 2>&1 | FileCheck -check-prefix=FALKOR %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=falkor -### -c %s 2>&1 | FileCheck -check-prefix=FALKOR %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mtune=falkor -### -c %s 2>&1 | FileCheck -check-prefix=FALKOR %s
end_comment

begin_comment
comment|// FALKOR: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "falkor"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=falkor -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-FALKOR %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=falkor -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-FALKOR %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=falkor -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-FALKOR %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=falkor -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-FALKOR %s
end_comment

begin_comment
comment|// ARM64-FALKOR: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "falkor"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=kryo -### -c %s 2>&1 | FileCheck -check-prefix=KRYO %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=kryo -### -c %s 2>&1 | FileCheck -check-prefix=KRYO %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=kryo -### -c %s 2>&1 | FileCheck -check-prefix=KRYO %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mtune=kryo -### -c %s 2>&1 | FileCheck -check-prefix=KRYO %s
end_comment

begin_comment
comment|// KRYO: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "kryo"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=kryo -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-KRYO %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=kryo -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-KRYO %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=kryo -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-KRYO %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=kryo -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-KRYO %s
end_comment

begin_comment
comment|// ARM64-KRYO: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "kryo"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-TUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-TUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-TUNE %s
end_comment

begin_comment
comment|// THUNDERX2T99: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "thunderx2t99" "-target-feature" "+v8.1a"
end_comment

begin_comment
comment|// THUNDERX2T99-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "thunderx2t99"
end_comment

begin_comment
comment|// THUNDERX2T99-TUNE-NOT: +v8.1a
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-THUNDERX2T99 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-THUNDERX2T99 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-THUNDERX2T99-TUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-THUNDERX2T99-TUNE %s
end_comment

begin_comment
comment|// ARM64-THUNDERX2T99: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "thunderx2t99" "-target-feature" "+v8.1a"
end_comment

begin_comment
comment|// ARM64-THUNDERX2T99-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "thunderx2t99"
end_comment

begin_comment
comment|// ARM64-THUNDERX2T99-TUNE-NOT: +v8.1a
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
comment|// RUN: %clang -target aarch64_be -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE %s
end_comment

begin_comment
comment|// CA35-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a35"
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
comment|// RUN: %clang -target aarch64_be -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE %s
end_comment

begin_comment
comment|// CA72-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a72"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE %s
end_comment

begin_comment
comment|// CORTEX-A73-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a73"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE %s
end_comment

begin_comment
comment|// M1-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "exynos-m1"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE %s
end_comment

begin_comment
comment|// M2-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "exynos-m2"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE %s
end_comment

begin_comment
comment|// M3-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "exynos-m3"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE %s
end_comment

begin_comment
comment|// THUNDERX2T99-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "thunderx2t99"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a57 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a53 -mcpu=cortex-a57  -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a72 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a53 -mcpu=cortex-a72  -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a53 -mcpu=cortex-a73     -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=thunderx2t99 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cortex-a53 -mcpu=thunderx2t99  -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE %s
end_comment

begin_comment
comment|// MCPU-MTUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
end_comment

begin_comment
comment|// GENERICV81A: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.1a"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERICV81A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERICV81A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERICV81A %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mlittle-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERICV81A %s
end_comment

begin_comment
comment|// ARM64-GENERICV81A: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.1a"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8.2-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -march=armv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mlittle-endian -march=armv8.2-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -march=armv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mlittle-endian -march=armv8.2-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
end_comment

begin_comment
comment|// GENERICV82A: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.2a"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8.2-a+fp16 -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A-FP16 %s
end_comment

begin_comment
comment|// GENERICV82A-FP16: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.2a" "-target-feature" "+fullfp16"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8.2-a+profile -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A-SPE %s
end_comment

begin_comment
comment|// GENERICV82A-SPE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.2a" "-target-feature" "+spe"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8.2-a+fp16+profile -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A-FP16-SPE %s
end_comment

begin_comment
comment|// GENERICV82A-FP16-SPE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.2a" "-target-feature" "+fullfp16" "-target-feature" "+spe"
end_comment

begin_comment
comment|// ================== Check whether -march accepts mixed-case values.
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -march=ARMV8.1A -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -march=ARMV8.1-A -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -march=Armv8.1A -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mbig-endian -march=Armv8.1-A -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -march=ARMv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be -mbig-endian -march=ARMV8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
end_comment

begin_comment
comment|// GENERICV81A-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.1a"
end_comment

begin_comment
comment|// ================== Check whether -mcpu and -mtune accept mixed-case values.
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=Cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-CA53 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=Cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-CA53 %s
end_comment

begin_comment
comment|// CASE-INSENSITIVE-CA53: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=cortex-A53 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-ARM64-CA53 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=cortex-A53 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-ARM64-CA53 %s
end_comment

begin_comment
comment|// CASE-INSENSITIVE-ARM64-CA53: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a53"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=CORTEX-A57 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=CORTEX-A57 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-CA57 %s
end_comment

begin_comment
comment|// CASE-INSENSITIVE-CA57: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a57"
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mcpu=Cortex-A57 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-ARM64-CA57 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64 -mtune=Cortex-A57 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-ARM64-CA57 %s
end_comment

begin_comment
comment|// CASE-INSENSITIVE-ARM64-CA57: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a57"
end_comment

end_unit

