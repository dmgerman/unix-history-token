begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check passing options to the assembler for various linux targets.
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM %s
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-MCPU %s
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-MFPU %s
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-MARCH %s
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-ALL %s
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-TARGET %s
end_comment

begin_comment
comment|// CHECK-ARM-TARGET: as{{(.exe)?}}" "-mfpu=neon" "-mfloat-abi=soft" "-mcpu=cortex-a8"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target armv8-linux -mcpu=cortex-a53 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-TARGET-V8 %s
end_comment

begin_comment
comment|// CHECK-ARM-TARGET-V8: as{{(.exe)?}}" "-mfpu=crypto-neon-fp-armv8" "-mfloat-abi=soft" "-mcpu=cortex-a53"
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-MFLOAT-ABI %s
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-ANDROID %s
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-ANDROID-SOFTFP %s
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM-HARDFP %s
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
comment|// RUN:   | FileCheck -check-prefix=CHECK-PPC-NO-MCPU %s
end_comment

begin_comment
comment|// CHECK-PPC-NO-MCPU-NOT: as{{.*}} "-mcpu=invalid-cpu"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target sparc64-linux -mcpu=invalid-cpu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-SPARCV9 %s
end_comment

begin_comment
comment|// CHECK-SPARCV9: as
end_comment

begin_comment
comment|// CHECK-SPARCV9: -64
end_comment

begin_comment
comment|// CHECK-SPARCV9: -Av9a
end_comment

begin_comment
comment|// CHECK-SPARCV9-NOT: -KPIC
end_comment

begin_comment
comment|// CHECK-SPARCV9: -o
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target sparc64-linux -mcpu=invalid-cpu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -fpic -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-SPARCV9PIC %s
end_comment

begin_comment
comment|// CHECK-SPARCV9PIC: as
end_comment

begin_comment
comment|// CHECK-SPARCV9PIC: -64
end_comment

begin_comment
comment|// CHECK-SPARCV9PIC: -Av9a
end_comment

begin_comment
comment|// CHECK-SPARCV9PIC: -KPIC
end_comment

begin_comment
comment|// CHECK-SPARCV9PIC: -o
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target sparc-linux -mcpu=invalid-cpu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-SPARCV8 %s
end_comment

begin_comment
comment|// CHECK-SPARCV8: as
end_comment

begin_comment
comment|// CHECK-SPARCV8: -32
end_comment

begin_comment
comment|// CHECK-SPARCV8: -Av8plusa
end_comment

begin_comment
comment|// CHECK-SPARCV8: -o
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target s390x-linux -### -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-Z-DEFAULT-ARCH %s
end_comment

begin_comment
comment|// CHECK-Z-DEFAULT-ARCH: as{{.*}} "-march=z10"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target s390x-linux -march=z196 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-Z-ARCH-Z196 %s
end_comment

begin_comment
comment|// CHECK-Z-ARCH-Z196: as{{.*}} "-march=z196"
end_comment

end_unit

