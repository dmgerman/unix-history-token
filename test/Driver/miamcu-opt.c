begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -miamcu -rtlib=platform -no-canonical-prefixes %s -### -o %t.o 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -miamcu -rtlib=platform -no-canonical-prefixes -m32 %s -### -o %t.o 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -miamcu -rtlib=platform -no-canonical-prefixes -target x86_64-unknown-linux-gnu %s -### -o %t.o 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -mno-iamcu -miamcu -rtlib=platform -no-canonical-prefixes %s -### -o %t.o 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -miamcu -rtlib=platform -no-canonical-prefixes -m64 %s -### -o %t.o 2>&1 | FileCheck %s -check-prefix=M64
end_comment

begin_comment
comment|// RUN: %clang -miamcu -rtlib=platform -no-canonical-prefixes -dynamic %s -### -o %t.o 2>&1 | FileCheck %s -check-prefix=DYNAMIC
end_comment

begin_comment
comment|// RUN: %clang -miamcu -rtlib=platform -no-canonical-prefixes  -target armv8-eabi %s -### -o %t.o 2>&1 | FileCheck %s -check-prefix=NOT-X86
end_comment

begin_comment
comment|// RUN: %clang -miamcu -mno-iamcu -no-canonical-prefixes -target x86_64-unknown-linux-gnu %s -### -o %t.o 2>&1 | FileCheck %s -check-prefix=MNOIAMCU
end_comment

begin_comment
comment|// M64: error: invalid argument '-miamcu' not allowed with '-m64'
end_comment

begin_comment
comment|// DYNAMIC: error: invalid argument '-dynamic' not allowed with '-static'
end_comment

begin_comment
comment|// NOT-X86: error: unsupported option '-miamcu' for target 'armv8---eabi'
end_comment

begin_comment
comment|// MNOIAMCU-NOT: "-triple" "i586-intel-elfiamcu"
end_comment

begin_comment
comment|// CHECK: "{{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK: "-triple" "i586-intel-elfiamcu"
end_comment

begin_comment
comment|// CHECK: "-static-define"
end_comment

begin_comment
comment|// CHECK: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// CHECK: "-mstack-alignment=4"
end_comment

begin_comment
comment|// CHECK: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK: "-m" "elf_iamcu"
end_comment

begin_comment
comment|// CHECK: "-static"
end_comment

begin_comment
comment|// CHECK-NOT: crt1
end_comment

begin_comment
comment|// CHECK-NOT: crti
end_comment

begin_comment
comment|// CHECK-NOT: ctrbegin
end_comment

begin_comment
comment|// CHECK: crt0
end_comment

begin_comment
comment|// CHECK: "--start-group" "-lgcc" "-lc" "-lgloss" "--end-group" "--as-needed" "-lsoftfp" "--no-as-needed"
end_comment

begin_comment
comment|// CHECK-NOT: crtend
end_comment

begin_comment
comment|// CHECK-NOT: ctrn
end_comment

end_unit

