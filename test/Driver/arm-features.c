begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic+crc -march=armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CRC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic -march=armv8a+crc -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CRC %s
end_comment

begin_comment
comment|// CHECK-CRC: "-cc1"{{.*}} "-triple" "armv8-{{.*}} "-target-cpu" "generic"{{.*}} "-target-feature" "+crc"
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic+crypto -march=armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CRYPTO %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic -march=armv8a+crypto -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-CRYPTO %s
end_comment

begin_comment
comment|// CHECK-CRYPTO: "-cc1"{{.*}} "-triple" "armv8-{{.*}} "-target-cpu" "generic"{{.*}} "-target-feature" "+crypto"
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic+dsp -march=armv8m.main -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-DSP %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic -march=armv8m.main+dsp -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-DSP %s
end_comment

begin_comment
comment|// CHECK-DSP: "-cc1"{{.*}} "-triple" "thumbv8m.main-{{.*}} "-target-cpu" "generic"{{.*}} "-target-feature" "+dsp"
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic+nocrc -march=armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-NOCRC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic -march=armv8a+nocrc -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-NOCRC %s
end_comment

begin_comment
comment|// CHECK-NOCRC: "-cc1"{{.*}} "-triple" "armv8-{{.*}} "-target-cpu" "generic"{{.*}} "-target-feature" "-crc"
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic+nocrypto -march=armv8a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-NOCRYPTO %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic -march=armv8a+nocrypto -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-NOCRYPTO %s
end_comment

begin_comment
comment|// CHECK-NOCRYPTO: "-cc1"{{.*}} "-triple" "armv8-{{.*}} "-target-cpu" "generic"{{.*}} "-target-feature" "-crypto"
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic+nodsp -march=armv8m.main -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-NODSP %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-none-eabi -mcpu=generic -march=armv8m.main+nodsp -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-NODSP %s
end_comment

begin_comment
comment|// CHECK-NODSP: "-cc1"{{.*}} "-triple" "thumbv8m.main-{{.*}} "-target-cpu" "generic"{{.*}} "-target-feature" "-dsp"
end_comment

end_unit

