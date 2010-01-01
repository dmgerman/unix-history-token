begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple i386-unknown-unknown -### -S -O0 -Os %s -o %t.s -fverbose-asm -funwind-tables -fvisibility=hidden 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-triple" "i386-unknown-unknown"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-S"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-disable-free"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-mrelocation-model" "static"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-mdisable-fp-elim"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-munwind-tables"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-Os"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" .*clang-translation.*' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-masm-verbose"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-fvisibility" "hidden"' %t.log
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -### -S %s -o %t.s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-target-cpu" "yonah"' %t.log
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin9 -### -S %s -o %t.s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-target-cpu" "core2"' %t.log
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -### -S %s 2> %t.log \
end_comment

begin_comment
comment|// RUN:   -arch armv7
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=ARMV7_DEFAULT %s< %t.log
end_comment

begin_comment
comment|// ARMV7_DEFAULT: clang
end_comment

begin_comment
comment|// ARMV7_DEFAULT: "-cc1"
end_comment

begin_comment
comment|// ARMV7_DEFAULT-NOT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_DEFAULT: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// ARMV7_DEFAULT-NOT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_DEFAULT: "-x" "c"
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -### -S %s 2> %t.log \
end_comment

begin_comment
comment|// RUN:   -arch armv7 -msoft-float
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=ARMV7_SOFTFLOAT %s< %t.log
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: clang
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-cc1"
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-x" "c"
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -### -S %s 2> %t.log \
end_comment

begin_comment
comment|// RUN:   -arch armv7 -mhard-float
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=ARMV7_HARDFLOAT %s< %t.log
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT: clang
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT: "-cc1"
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT-NOT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT-NOT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT: "-x" "c"
end_comment

end_unit

