begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386--netbsd -m32 %s -### 2>&1 | FileCheck -check-prefix=I386 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64--netbsd -m32 %s -### 2>&1 | FileCheck -check-prefix=I386 %s
end_comment

begin_comment
comment|// I386: "-cc1" "-triple" "i386--netbsd"
end_comment

begin_comment
comment|// RUN: %clang -target i386--netbsd -m64 %s -### 2>&1 | FileCheck -check-prefix=X86_64 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64--netbsd -m64 %s -### 2>&1 | FileCheck -check-prefix=X86_64 %s
end_comment

begin_comment
comment|// X86_64: "-cc1" "-triple" "x86_64--netbsd"
end_comment

begin_comment
comment|// r196538 set arm1176jzf-s as default CPU for ARMv6 on NetBSD
end_comment

begin_comment
comment|// RUN: %clang -target armv6--netbsd-eabihf -m32 %s -### 2>&1 | FileCheck -check-prefix=ARMV6 %s
end_comment

begin_comment
comment|// ARMV6: "-cc1" "-triple" "armv6kz--netbsd-eabihf"
end_comment

begin_comment
comment|// RUN: %clang -target sparcv9--netbsd -m32 %s -### 2>&1 | FileCheck -check-prefix=SPARC %s
end_comment

begin_comment
comment|// RUN: %clang -target sparc--netbsd -m32 %s -### 2>&1 | FileCheck -check-prefix=SPARC %s
end_comment

begin_comment
comment|// SPARC: "-cc1" "-triple" "sparc--netbsd"
end_comment

begin_comment
comment|// RUN: %clang -target sparcv9--netbsd -m64 %s -### 2>&1 | FileCheck -check-prefix=SPARCV9 %s
end_comment

begin_comment
comment|// RUN: %clang -target sparc--netbsd -m64 %s -### 2>&1 | FileCheck -check-prefix=SPARCV9 %s
end_comment

begin_comment
comment|// SPARCV9: "-cc1" "-triple" "sparcv9--netbsd"
end_comment

begin_comment
comment|// RUN: %clang -target sparc64--netbsd -m64 %s -### 2>&1 | FileCheck -check-prefix=SPARC64 %s
end_comment

begin_comment
comment|// SPARC64: "-cc1" "-triple" "sparc64--netbsd"
end_comment

begin_comment
comment|// RUN: %clang -target sparcel -o foo %s -### 2>&1 | FileCheck -check-prefix=SPARCEL %s
end_comment

begin_comment
comment|// SPARCEL: gcc{{(\.exe)?}}" "-EL" "-o" "foo"
end_comment

begin_comment
comment|// RUN: %clang -target mips64--netbsd -m32 %s -### 2>&1 | FileCheck -check-prefix=MIPS %s
end_comment

begin_comment
comment|// RUN: %clang -target mips--netbsd -m32 %s -### 2>&1 | FileCheck -check-prefix=MIPS %s
end_comment

begin_comment
comment|// MIPS: "-cc1" "-triple" "mips--netbsd"
end_comment

begin_comment
comment|// RUN: %clang -target mips64--netbsd -m64 %s -### 2>&1 | FileCheck -check-prefix=MIPS64 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips--netbsd -m64 %s -### 2>&1 | FileCheck -check-prefix=MIPS64 %s
end_comment

begin_comment
comment|// MIPS64: "-cc1" "-triple" "mips64--netbsd"
end_comment

end_unit

