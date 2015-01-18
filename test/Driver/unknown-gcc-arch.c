begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -no-integrated-as -c \
end_comment

begin_comment
comment|// RUN: -x assembler %s -### 2>&1 | FileCheck -check-prefix=X86_64 %s
end_comment

begin_comment
comment|// X86_64: {{.*as.*--64}}
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -x assembler %s -### -m32 \
end_comment

begin_comment
comment|// RUN: -no-integrated-as 2>&1 | FileCheck -check-prefix=X86_64-M32 %s
end_comment

begin_comment
comment|// X86_64-M32: {{.*as.*--32}}
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -c -x assembler %s -### \
end_comment

begin_comment
comment|// RUN: -no-integrated-as 2>&1| FileCheck -check-prefix=I386 %s
end_comment

begin_comment
comment|// I386: {{.*as.*--32}}
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -c -x assembler %s -### -m64 \
end_comment

begin_comment
comment|// RUN: -no-integrated-as 2>&1 | FileCheck -check-prefix=I386-M64 %s
end_comment

begin_comment
comment|// I386-M64: {{.*as.*--64}}
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-unknown -c -x assembler %s -### \
end_comment

begin_comment
comment|// RUN: -no-integrated-as 2>&1 | FileCheck -check-prefix=PPC64 %s
end_comment

begin_comment
comment|// PPC64: {{.*as.*-a64}}
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-unknown -c -x assembler %s -### -m64 \
end_comment

begin_comment
comment|// RUN: -no-integrated-as 2>&1  | FileCheck -check-prefix=PPC-M64 %s
end_comment

begin_comment
comment|// PPC-M64: {{.*as.*-a64}}
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-unknown -c -x assembler %s -### -m32 \
end_comment

begin_comment
comment|// RUN: -no-integrated-as 2>&1 | FileCheck -check-prefix=PPC64-M32 %s
end_comment

begin_comment
comment|// PPC64-M32: {{.*as.*-a32}}
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-unknown-unknown -c -x assembler %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: -no-integrated-as | FileCheck -check-prefix=PPC %s
end_comment

begin_comment
comment|// PPC: {{.*as.*-a32}}
end_comment

begin_comment
comment|// RUN: %clang -target sparc64-unknown-unknown -no-integrated-as -c -x assembler %s -### -m32 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=SPARCV8 %s
end_comment

begin_comment
comment|// SPARCV8: {{.*as.*-32}}
end_comment

begin_comment
comment|// RUN: %clang -target sparc-unknown-unknown -no-integrated-as -c -x assembler %s -### -m64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=SPARCV9 %s
end_comment

begin_comment
comment|// SPARCV9: {{.*as.*-64}}
end_comment

end_unit

