begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check passing options to the assembler for ARM targets.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM %s
end_comment

begin_comment
comment|// CHECK-ARM: as{{(.exe)?}}" "-mfloat-abi=soft"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux -mcpu=cortex-a8 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM-MCPU %s
end_comment

begin_comment
comment|// CHECK-ARM-MCPU: as{{(.exe)?}}" "-mfloat-abi=soft" "-mcpu=cortex-a8"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux -mfpu=neon -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM-MFPU %s
end_comment

begin_comment
comment|// CHECK-ARM-MFPU: as{{(.exe)?}}" "-mfloat-abi=soft" "-mfpu=neon"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux -march=armv7-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM-MARCH %s
end_comment

begin_comment
comment|// CHECK-ARM-MARCH: as{{(.exe)?}}" "-mfloat-abi=soft" "-march=armv7-a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux -mcpu=cortex-a8 -mfpu=neon -march=armv7-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM-ALL %s
end_comment

begin_comment
comment|// CHECK-ARM-ALL: as{{(.exe)?}}" "-mfloat-abi=soft" "-march=armv7-a" "-mcpu=cortex-a8" "-mfpu=neon"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target armv7-linux -mcpu=cortex-a8 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM-TARGET %s
end_comment

begin_comment
comment|// CHECK-ARM-TARGET: as{{(.exe)?}}" "-mfpu=neon" "-mfloat-abi=soft" "-mcpu=cortex-a8"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux -mfloat-abi=hard -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM-MFLOAT-ABI %s
end_comment

begin_comment
comment|// CHECK-ARM-MFLOAT-ABI: as{{(.exe)?}}" "-mfloat-abi=hard"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-androideabi -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM-ANDROID %s
end_comment

begin_comment
comment|// CHECK-ARM-ANDROID: as{{(.exe)?}}" "-mfloat-abi=soft"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-androideabi -march=armv7-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM-ANDROID-SOFTFP %s
end_comment

begin_comment
comment|// CHECK-ARM-ANDROID-SOFTFP: as{{(.exe)?}}" "-mfloat-abi=softfp" "-march=armv7-a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux-eabi -mhard-float -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ARM-HARDFP %s
end_comment

begin_comment
comment|// CHECK-ARM-HARDFP: as{{(.exe)?}}" "-mfloat-abi=hard"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target ppc-linux -mcpu=invalid-cpu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=PPC-NO-MCPU %s
end_comment

begin_comment
comment|// CHECK-PPC-NO-MCPU-NOT: as{{.*}} "-mcpu=invalid-cpu"
end_comment

end_unit

