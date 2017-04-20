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
comment|// RUN: %clang -target arm-linux -mcpu=cortex-a8 -mfpu=neon -march=armebv7-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARMEB-ALL %s
end_comment

begin_comment
comment|// CHECK-ARMEB-ALL: as{{(.exe)?}}" "-mfloat-abi=soft" "-march=armebv7-a" "-mcpu=cortex-a8" "-mfpu=neon"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target thumb-linux -mcpu=cortex-a8 -mfpu=neon -march=thumbv7-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-THUMB-ALL %s
end_comment

begin_comment
comment|// CHECK-THUMB-ALL: as{{(.exe)?}}" "-mfloat-abi=soft" "-march=thumbv7-a" "-mcpu=cortex-a8" "-mfpu=neon"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target thumb-linux -mcpu=cortex-a8 -mfpu=neon -march=thumbebv7-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-THUMBEB-ALL %s
end_comment

begin_comment
comment|// CHECK-THUMBEB-ALL: as{{(.exe)?}}" "-mfloat-abi=soft" "-march=thumbebv7-a" "-mcpu=cortex-a8" "-mfpu=neon"
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
comment|// RUN: %clang -target armebv7-linux -mcpu=cortex-a8 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARMEB-TARGET %s
end_comment

begin_comment
comment|// CHECK-ARMEB-TARGET: as{{(.exe)?}}" "-mfpu=neon" "-mfloat-abi=soft" "-mcpu=cortex-a8"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target thumbv7-linux -mcpu=cortex-a8 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-THUMB-TARGET %s
end_comment

begin_comment
comment|// CHECK-THUMB-TARGET: as{{(.exe)?}}" "-mfpu=neon" "-mfloat-abi=soft" "-mcpu=cortex-a8"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target thumbebv7-linux -mcpu=cortex-a8 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-THUMBEB-TARGET %s
end_comment

begin_comment
comment|// CHECK-THUMBEB-TARGET: as{{(.exe)?}}" "-mfpu=neon" "-mfloat-abi=soft" "-mcpu=cortex-a8"
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
comment|// RUN: %clang -target armebv8-linux -mcpu=cortex-a53 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARMEB-TARGET-V8 %s
end_comment

begin_comment
comment|// CHECK-ARMEB-TARGET-V8: as{{(.exe)?}}" "-mfpu=crypto-neon-fp-armv8" "-mfloat-abi=soft" "-mcpu=cortex-a53"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target thumbv8-linux -mcpu=cortex-a53 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-THUMB-TARGET-V8 %s
end_comment

begin_comment
comment|// CHECK-THUMB-TARGET-V8: as{{(.exe)?}}" "-mfpu=crypto-neon-fp-armv8" "-mfloat-abi=soft" "-mcpu=cortex-a53"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target thumbebv8-linux -mcpu=cortex-a53 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-THUMBEB-TARGET-V8 %s
end_comment

begin_comment
comment|// CHECK-THUMBEB-TARGET-V8: as{{(.exe)?}}" "-mfpu=crypto-neon-fp-armv8" "-mfloat-abi=soft" "-mcpu=cortex-a53"
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
comment|// RUN: %clang -target aarch64-linux-gnu -mcpu=cortex-a53 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM64-MCPU %s
end_comment

begin_comment
comment|// CHECK-ARM64-MCPU: as{{(.exe)?}}" "-mcpu=cortex-a53"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-gnu -march=armv8-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM64-MARCH %s
end_comment

begin_comment
comment|// CHECK-ARM64-MARCH: as{{(.exe)?}}" "-march=armv8-a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-linux-gnu -mcpu=cortex-a53 -march=armv8-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM64-ALL %s
end_comment

begin_comment
comment|// CHECK-ARM64-ALL: as{{(.exe)?}}" "-march=armv8-a" "-mcpu=cortex-a53"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be-linux-gnu -mcpu=cortex-a53 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM64-MCPU %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be-linux-gnu -march=armv8-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM64-MARCH %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target aarch64_be-linux-gnu -mcpu=cortex-a53 -march=armv8-a -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ARM64-ALL %s
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
comment|// CHECK-SPARCV9: -Av9
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
comment|// CHECK-SPARCV9PIC: -Av9
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
comment|// CHECK-SPARCV8: -Av8
end_comment

begin_comment
comment|// CHECK-SPARCV8: -o
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target sparcel-linux -mcpu=invalid-cpu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-SPARCV8EL %s
end_comment

begin_comment
comment|// CHECK-SPARCV8EL: as
end_comment

begin_comment
comment|// CHECK-SPARCV8EL: -32
end_comment

begin_comment
comment|// CHECK-SPARCV8EL: -Av8
end_comment

begin_comment
comment|// CHECK-SPARCV8EL: -o
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

