begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm-none-eabi               -### -c %s 2>&1 | FileCheck --check-prefix=STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -fropi        -### -c %s 2>&1 | FileCheck --check-prefix=ROPI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi        -frwpi -### -c %s 2>&1 | FileCheck --check-prefix=RWPI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -fropi -frwpi -### -c %s 2>&1 | FileCheck --check-prefix=ROPI-RWPI %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb-none-eabi   -fropi        -### -c %s 2>&1 | FileCheck --check-prefix=ROPI %s
end_comment

begin_comment
comment|// RUN: %clang -target thumb-none-eabi   -fropi        -### -c %s 2>&1 | FileCheck --check-prefix=ROPI %s
end_comment

begin_comment
comment|// RUN: %clang -target thumbeb-none-eabi -fropi        -### -c %s 2>&1 | FileCheck --check-prefix=ROPI %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fropi        -### -c %s 2>&1 | FileCheck --check-prefix=ROPI-NON-ARM %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu        -frwpi -### -c %s 2>&1 | FileCheck --check-prefix=RWPI-NON-ARM %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fropi -frwpi -### -c %s 2>&1 | FileCheck --check-prefix=ROPI-NON-ARM --check-prefix=RWPI-NON-ARM %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -fpic    -fropi        -### -c %s 2>&1 | FileCheck --check-prefix=PIC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -fpie           -frwpi -### -c %s 2>&1 | FileCheck --check-prefix=PIC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -fPIC    -fropi -frwpi -### -c %s 2>&1 | FileCheck --check-prefix=PIC %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -fno-pic -fropi        -### -c %s 2>&1 | FileCheck --check-prefix=ROPI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -x c++ -fropi        -### -c %s 2>&1 | FileCheck --check-prefix=CXX %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -x c++        -frwpi -### -c %s 2>&1 | FileCheck --check-prefix=RWPI %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -x c++ -fropi -frwpi -### -c %s 2>&1 | FileCheck --check-prefix=CXX %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-eabi -x c++ -fallow-unsupported -fropi        -### -c %s 2>&1 | FileCheck --check-prefix=ROPI %s
end_comment

begin_comment
comment|// STATIC: "-mrelocation-model" "static"
end_comment

begin_comment
comment|// ROPI: "-mrelocation-model" "ropi"
end_comment

begin_comment
comment|// RWPI: "-mrelocation-model" "rwpi"
end_comment

begin_comment
comment|// ROPI-RWPI: "-mrelocation-model" "ropi-rwpi"
end_comment

begin_comment
comment|// ROPI-NON-ARM: error: unsupported option '-fropi' for target 'x86_64--linux-gnu'
end_comment

begin_comment
comment|// RWPI-NON-ARM: error: unsupported option '-frwpi' for target 'x86_64--linux-gnu'
end_comment

begin_comment
comment|// PIC: error: embedded and GOT-based position independence are incompatible
end_comment

begin_comment
comment|// CXX: error: ROPI is not compatible with c++
end_comment

end_unit

